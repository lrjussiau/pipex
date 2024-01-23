/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:14:47 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/22 10:23:50 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*new_str;
	unsigned int	i;
	unsigned int	j;

	new_str = (char *)malloc(len + 1);
	if (!s || !(new_str))
		return (0);
	i = start;
	j = 0;
	while (i < (unsigned int)ft_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}
/*
int main()
{
    const char *input = "bullshit";
    unsigned int start = 400;
    unsigned int len = 20;

    char *result = ft_substr(input, start, len);
	printf("ft_substr : %s\n", result);

    free(result);

    return 0;
}
*/