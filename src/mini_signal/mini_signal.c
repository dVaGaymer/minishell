/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:25:36 by yoav              #+#    #+#             */
/*   Updated: 2022/12/13 11:04:06 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_signal.h"

static void	handler_int(int sig_code)
{
	t_shell_op	*sp;

	(void)sig_code;
	sp = shell_op_get_sp(NULL);
	ft_putstr_fd(NEW_LINE_STR, sp->t->term_fd);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	sp->last_cmd_stt = CMD_EXIT_SIG_INT;
}

t_error_code	mini_signal_interactive_mode(void)
{
	if (SIG_ERR == signal(SIGINT, handler_int))
		return (SIGNAL_ERROR);
	return (SUCCESS);
}

t_error_code	mini_signal_disable(void)
{
	if (SIG_ERR == signal(SIGINT, SIG_IGN))
		return (SIGNAL_ERROR);
	if (SIG_ERR == signal(SIGQUIT, SIG_IGN))
		return (SIGNAL_ERROR);
	return (SUCCESS);
}

t_error_code	mini_signal_set_child(void)
{
	if (SIG_ERR == signal(SIGINT, SIG_DFL))
		return (SIGNAL_ERROR);
	if (SIG_ERR == signal(SIGQUIT, SIG_DFL))
		return (SIGNAL_ERROR);
	return (SUCCESS);
}
