/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:49:12 by yoav              #+#    #+#             */
/*   Updated: 2022/09/20 14:44:45 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <stdlib.h>

void	test(void)
{
	char	*leak;

	leak = malloc(100);
	leak = 0;
	(void)leak;
	CU_ASSERT(CU_TRUE);
}
