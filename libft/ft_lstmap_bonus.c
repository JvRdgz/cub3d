/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:13:59 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/04 22:28:33 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list	*newlst;
	t_list	*rlst;

	if (!l || !f)
		return (NULL);
	newlst = ft_lstnew((*f)(l->content));
	if (!newlst)
		return (NULL);
	rlst = newlst;
	l = l->next;
	while (l)
	{
		newlst->next = ft_lstnew((*f)(l->content));
		if (!newlst->next)
		{
			ft_lstclear(&rlst, d);
			return (NULL);
		}
		newlst = newlst->next;
		l = l->next;
	}
	newlst->next = NULL;
	return (rlst);
}
