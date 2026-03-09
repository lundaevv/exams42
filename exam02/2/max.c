/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:09:13 by vlundaev          #+#    #+#             */
/*   Updated: 2025/09/04 13:17:34 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int* tab, unsigned int len)
{
	int	count = 0;
	int	result = 0;
	int	i = 0;
	if (len > 0)
	{
		while (count < len)
		{
			if (tab[i] > result)
				result = tab[i];
			i++;
			count++;
		}
		return (result);
	}
	return (0);
}

#include <stdio.h>

int	main(void)
{
	int	int_tab[] = {256, 1, 3, 2, 10, 9};
	printf("%d", max(int_tab, 6));
}
