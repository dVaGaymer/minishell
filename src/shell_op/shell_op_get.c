/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_op_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:40:13 by yoav              #+#    #+#             */
/*   Updated: 2022/10/12 11:52:41 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_op.h"

t_cmd_list	*shell_op_get_cmd_list(t_shell_op *sp)
{
	return (sp->cmd_list);
}
