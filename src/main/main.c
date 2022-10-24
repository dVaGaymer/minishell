/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2022/10/23 00:14:18 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// TODO SYNTAX_ERROR create error_code handler -- NO printf
static	t_error_code	handle_input(t_shell_op *sp, t_read_input read_func)
{
	char			*bad_str;
	t_error_code	err;

	err = read_func(&(sp->input));
	if (NULL == sp->input)
		return (EOF_SUCCESS);
	if (SUCCESS != err)
		return (err);
	err = laxer_create_token_list(sp);
	if (SUCCESS != err)
		return (err);
	err = parser_check_tokens(sp, &bad_str);
	if (SYNTAX_ERROR == err)
	{
		printf("minishell: parse error near `%s'", bad_str);
		return (err);
	}
	return (err);
}

static	t_error_code	handle_valid_input(t_shell_op *sp)
{
	t_error_code	err;

	if (0 == **(sp->input))
		return (SUCCESS);
	err = commander_create_cmds(sp);
	if (SUCCESS != err)
		return (err);
	err = executer_run_all_cmds(sp);
	if (SUCCESS != err)
		return (err);
	cleaner_round_clean(sp);
	return (SUCCESS);
}

// TODO reader should handle open pipe then FALSE it
static t_error_code	internal_flow(char **envp, t_read_input read_func)
{
	t_error_code	err;
	t_shell_op		*sp;

	err = shell_op_create(&sp, envp);
	if (SUCCESS != err)
		return (err);
	sp->run = TRUE;
	while (sp->run && SUCCESS == err)
	{
		err = handle_input(sp, read_func);
		if (EOF_SUCCESS == err)
		{
			shell_op_destroy(&sp);
			return (SUCCESS);
		}
		if (SYNTAX_PIPE_STILL_OPEN == err)
		{
			sp->open_pipe = TRUE;
			continue ;
		}
		err = handle_valid_input(sp);
	}
	shell_op_destroy(&sp);
	return (err);
}

int	main(int argc, char **argv, char **envp)
{
	t_error_code	err;
	int				fd;

	if (1 < argc)
	{
		fd = open(*(argv + 1), O_RDONLY);
		dup2(fd, STDIN_FILENO);
		err = internal_flow(envp, reader_get_tab_from_file);
		close(fd);
		return (err);
	}
	return (internal_flow(envp, reader_get_tab));
}
