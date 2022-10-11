/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/13 10:45:27 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "reader.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printer_print("~Minishell~");
	reader_get_tab(&argv);
	return (0);
}
