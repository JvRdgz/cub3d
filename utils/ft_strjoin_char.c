/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:37:10 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/18 14:22:37 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char				*ft_strjoin_char(char *str, char c)
{
	char			*finally;
	int				i;

	i = 0;
	if (!(finally = (char *)malloc((sizeof(char *)) * ft_strlen(str)) + 2))
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
