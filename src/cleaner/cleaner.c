/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:04:03 by yoav              #+#    #+#             */
/*   Updated: 2022/11/30 10:28:11 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleaner.h"

void	cleaner_round_clean(t_shell_op *sp)
{
	if (sp->input)
	{
		tab_deep_destroy(&(sp->input));
		token_list_destroy(&(sp->token_list));
		cmd_list_destroy(&(sp->cmd_list));
		pipe_list_clean(sp->pipe_list);
	}
	if (sp->input_full_expansion)
		tab_deep_destroy(&(sp->input_full_expansion));
}

void	cleaner_on_pipe_error(t_shell_op *sp)
{
	if (sp->input)
	{
		tab_deep_destroy(&(sp->input));
		token_list_destroy(&(sp->token_list));
	}
	if (sp->input_full_expansion)
		tab_deep_destroy(&(sp->input_full_expansion));
}
