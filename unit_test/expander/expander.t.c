/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:13 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/22 20:57:25 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "expander.h"

void	test_expander(void)
{
	t_shell_op	sp;
	char		*str;

	env_initenv(&sp.envp, 0);
	env_setvar(&sp.envp, "USER", "al7arolopez");
	env_setvar(&sp.envp, "NAME", "ALVARO LOPEZ");
	env_setvar(&sp.envp, "PWD", "~/");
	env_setvar(&sp.envp, "OLD_PWD", "~/Documents/");
	env_setvar(&sp.envp, "K", "ALVARO LOPEZ");
	str = expander_expand_var(sp.envp, "Name is $USER :D\n");
	CU_ASSERT_STRING_EQUAL(str, "Name is al7arolopez :D\n");
	free(str);
	str = expander_expand_var(sp.envp, "Name is $NAME");
	CU_ASSERT_STRING_EQUAL(str, "Name is \"ALVARO\" \"LOPEZ\"");
	free(str);
	str = expander_expand_var(sp.envp, "Your is $PATH :D $PWD $K o$Lo");
	CU_ASSERT_STRING_EQUAL(str, "Your is  :D ~/ \"ALVARO\" \"LOPEZ\" o");
	free(str);
	str = expander_expand_var(sp.envp, "$PWD");
	CU_ASSERT_STRING_EQUAL(str, "~/");
	free(str);
	str = expander_expand_var(sp.envp, "TTTaqqq $ $ $");
	CU_ASSERT_STRING_EQUAL(str, "TTTaqqq $ $ $");
	free(str);
	str = expander_expand_var(sp.envp, "TTT hola que tal");
	printf("%s", str);
	free(str);
	env_destroy(&(sp.envp));
}
