/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:15:06 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/15 22:19:55 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "shell_op.h"

char			*get_key_value_pair(char *key, char *value);
t_error_code	new_var(char ***env, char *key, char *value);
t_bool			key_compare(char *env, char *key);
char			*get_value(char *env_var);
int				env_size(char **envp);

#endif
