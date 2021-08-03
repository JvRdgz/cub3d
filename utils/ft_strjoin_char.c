/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:11:24 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/03 21:12:22 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strjoin_char(char *str, char c)
{
	char			*finally;
	int				i;

	i = 0;
	finally = (char *)malloc((sizeof(char *)) * ft_strlen(str)) + 2;
	if (!finally)
	{
		printf("ERROR: malloc my_strjoin ha fallado");
		exit(-1);
	}
	while (str[i] != '\0')
	{
		finally[i] = str[i];
		i++;
	}
	finally[i] = c;
	finally[i + 1] = '\0';
	return (finally);
}
