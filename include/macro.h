/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:35:42 by yoav              #+#    #+#             */
/*   Updated: 2022/10/24 11:45:55 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# define PIPE_CHAR			'|'
# define RR_CHAR			'>'
# define RL_CHAR			'<'
# define SEMICOLON_CHAR		';'
# define NEW_LINE_CHAR		'\n'
# define NEW_LINE_STR		"\n"
# define SINGLE_QUOTE_CHAR	'\''
# define DOUBLE_QUOTE_CHAR	'\"'
# define SPACE_CHAR			' '
# define EQUAL_CHAR			'='
# define MINUS_CHAR			'-'
# define EQUAL_STR			"="
# define COLON_CHAR			':'
# define SLASH_CHAR			'/'
# define SLASH_STR			"/"
# define QUOTE_STR			"'"
# define MAIN_PROMPT		"\e[0;32m➜ \e[0mmsh$ "
# define ERROR_MAIN_PROMPT		"\e[0;31m➜ \e[0mmsh$ "
# define DQUOTE_PROMPT		"dquote> "
# define SQUOTE_PROMPT		"quote> "
# define EMPTY_STRING		""
# define NEW_PROC			0
# define EXPANDER_CHAR		'$'
# define R_BRACKET			')'
# define L_BRACKET			'('
# define MINISHELL_STR		"minishell"

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

#endif
