/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r3dc4t <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:34:33 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/11/13 19:10:31 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env.h"

static t_error_code	get_dir(t_shell_op *sp, char *new_dir)
{
	t_error_code	err;
	char			*tmp;

	err = chdir(new_dir);
	if (SUCCESS != err)
		return (err);
	tmp = getcwd(NULL, 0);
	if (!ft_strcmp(tmp, env_getvar(sp->envp, "PWD")))
	{
		free(tmp);
		return (SUCCESS);
	}
	env_setvar(&sp->envp, "OLDPWD", env_getvar(sp->envp, "PWD"));
	env_setvar(&sp->envp, "PWD", tmp);
	free(tmp);
	return (SUCCESS);
}

t_error_code	builtin_cd(t_shell_op *sp, t_cmd *c)
{
	c->builtin_ret_val = 0;
	if (2 != tab_count(c->argv))
	{
		if (SUCCESS != get_dir(sp, env_getvar(sp->envp, "HOME")))
			c->builtin_ret_val = -1;
		return (SUCCESS);
	}
	if (SUCCESS != get_dir(sp, *(c->argv + 1)))
		c->builtin_ret_val = -1;
	return (SUCCESS);
}