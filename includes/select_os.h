/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_os.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:08:54 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/18 14:58:16 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DETECT_SO_H
# define _DETECT_SO_H

# ifdef __APPLE__
#  include "key_macos.h"
#  include "../mlx/minilibx-macos/mlx.h"
# else
#  include "key_linux.h"
#  include "../mlx/minilibx-linux/mlx.h"
# endif
#endif
