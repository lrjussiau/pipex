/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:48:35 by ljussiau          #+#    #+#             */
/*   Updated: 2023/10/27 14:24:44 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

unsigned	int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	n;
	unsigned int	i;

	i = 0;
	n = ft_strlen(dest);
	if (size < n)
		return (ft_strlen(src) + size);
	while ((n + 1) < size && src[i] != '\0')
		dest[n++] = src[i++];
	dest[n] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}
/*
int main()
{
    char first[] = "hello ";
    char last[] = "salut";
    int r;
	int t;
    int size = 8;
    char buffer[40];

    strcpy(buffer,first);
    r = strlcat(buffer,last,size);

    puts(buffer);
    printf("Value returned: %d\n",r);
    return(0);
}
*/
