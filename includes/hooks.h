/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:36:21 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/04 19:36:26 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# ifdef APPLE
#  include "../mlx/minilibx_macos/mlx.h"
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_S 1
#  define KEY_W 13
#  define KEY_Q 12
#  define KEY_ESC 53
#  define KEY_AR_L 123
#  define KEY_AR_R 124
#  define LINUX 0
# elif __linux
#  include "../mlx/minilibx-linux/mlx.h"
#  include "../mlx/minilibx-linux/mlx_int.h"
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_S 115
#  define KEY_W 119
#  define KEY_Q 113
#  define KEY_ESC 65307
#  define KEY_AR_L 65361
#  define KEY_AR_R 65363
#  define LINUX 1
# endif

#endif
