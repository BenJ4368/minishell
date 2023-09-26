/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:29:00 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/26 12:52:40 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "TheLibft/base/libft.h"
# include "TheLibft/ft_printf/ft_printf.h"
# include "TheLibft/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# define CYAN "\001\x1b[36m\002"
# define MAGENTA "\001\x1b[35m\002"
# define BOLD "\001\x1b[1m\002"
# define STOP "\001\x1b[0m\002"


typedef struct data_s
{
	char		**ms_env;
	char		*prompt;
	char		*input;
}				t_data;

// main.c
void		copy_env(t_data *data, char **env);
int			main(int argc, char **argv, char **env);

// parse_input.c
int			check_input(char *input);
int			check_unclosed_quotes(char *input, int i);
int			in_quotes(char *str, int x);

// prompt.c
void		prompt_builder(char **prompt, char *usr, char *cwd, int length);
void		prompt(t_data *data);

// utils_error.c
void		ms_error(char *msg);

// utils_free.c
void		free_minishell(t_data *data);

// utils_signal.c
void		sigint_handler(int signal);
void		sigquit_handler(int signal);


#endif