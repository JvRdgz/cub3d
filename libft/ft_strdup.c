/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:25:10 by jarodrig          #+#    #+#             */
/*   Updated: 2021/07/18 14:03:42 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*s;
	size_t	len;

	len = ft_strlen(s1) + 1;
	s = (char *)s1;
	ptr = malloc(len);
	if (ptr)
		ft_memcpy(ptr, s, len);
	return (ptr);
}
