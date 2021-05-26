/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_os.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 20:25:10 by jarodrig          #+#    #+#             */
/*   Updated: 2021/05/26 20:31:45 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SELECT_SO
# define _SELECT_SO

# ifdef __APPLE__
#  include "key_macos.h"
#  include "../mlx/minilibx-macos/mlx.h"
# else
#  include "key_linux.h"
#  include "../mlx/minilibx-linux/mlx.h"
# endif
#endif
