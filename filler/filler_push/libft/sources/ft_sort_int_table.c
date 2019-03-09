/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:55:30 by lsimanau          #+#    #+#             */
/*   Updated: 2018/11/17 19:59:14 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_table(int *tab, int size)
{
	int i;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}
