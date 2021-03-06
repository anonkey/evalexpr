/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 02:55:56 by tseguier          #+#    #+#             */
/*   Updated: 2014/03/27 18:40:35 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	if (*s == '\0')
		return ((c == 0) ? (char *)s : NULL);
	last = ft_strrchr(s + 1, c);
	if (!last && *s == (char)c)
		return ((char *)s);
	else
		return (last);
}
