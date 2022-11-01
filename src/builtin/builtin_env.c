/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r3dc4t <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:40:07 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/11/02 00:40:21 by r3dc4t           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_error_code	builtin_env(t_shell_op *sp, t_cmd *c)
{
	(void)sp;
	(void)c;
	c->builtin_ret_val = 0;
	return (SUCCESS);
}
