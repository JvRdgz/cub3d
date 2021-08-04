/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_os.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:36:58 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/04 20:15:51 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_OS_H
# define SELECT_OS_H

# ifdef __APPLE__
#  include "key_macos.h"
#  include "../mlx/minilibx-macos/mlx.h"
# else
#  include "key_linux.h"
#  include "../mlx/minilibx-linux/mlx.h"
# endif
#endif
