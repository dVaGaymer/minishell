/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:31:58 by yoav              #+#    #+#             */
/*   Updated: 2022/11/17 15:05:53 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_OP_H
# define SHELL_OP_H

# include "error_code.h"
# include "libft.h"
# include "tab.h"
# include "env.h"
# include "token_list.h"
# include "pipe_list.h"
# include "cmd_list.h"

typedef struct s_shell_op
{
	char			**input;
	char			**envp;
	t_token_list	*token_list;
	t_cmd_list		*cmd_list;
	t_bool			run;
	t_bool			open_pipe;
	int				last_cmd_stt;
	t_pipe_list		*pipe_list;
}	t_shell_op;

t_error_code	shell_op_create(t_shell_op **ret, char **envp);
void			shell_op_destroy(t_shell_op **sp);
void			shell_op_set_token_list(t_shell_op *sp, t_token_list *tok_lst);
void			shell_op_set_input(t_shell_op *sp, char **input);
t_cmd_list		*shell_op_get_cmd_list(t_shell_op *sp);

#endif
