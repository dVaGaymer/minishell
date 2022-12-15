/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_wrapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:57:09 by yoav              #+#    #+#             */
/*   Updated: 2022/12/09 15:54:55 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dup_wrapper.h"

t_error_code	dup_wrapper(int src, int dest)
{
	if (ERROR == dup2(src, dest))
		return (ERROR);
	return (SUCCESS);
}
