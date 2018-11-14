/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:09:10 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/10/18 17:53:47 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *lst, size_t n)
{
	free(lst);
	(void)n;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*list;

	if (!lst || !f)
		return (NULL);
	if (!(list = f(lst)))
	{
		ft_lstdel(&new, &del);
		return (NULL);
	}
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = f(lst)))
		{
			ft_lstdel(&new, del);
			return (NULL);
		}
		list = list->next;
	}
	return (new);
}
