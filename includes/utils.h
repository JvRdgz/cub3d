/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:01:22 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/18 14:31:49 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

char			*ft_strjoin_char(char *str, char c);
char			*ft_strdup2(char *str, char now, int max, int *count_sprites);
void			change_tabs(char *finally, char c, int n);
void			double_kill(char **str);
int				what_is_higher(int a, int b);
int				char_to_num(char *str);
char			*give_me_digit_without_spaces(char *str);
void			kill(char *str);
void			double_kill(char **str);
void			ace(char *str, ...);
void			print_err(char *str);
void			ft_putstr(char *str);
int				white_spaces(char c);

#endif
