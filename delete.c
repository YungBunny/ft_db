/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfu <cfu@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 00:57:13 by cfu               #+#    #+#             */
/*   Updated: 2017/04/28 01:05:17 by cfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		delete_table(void)
{
	char	table[20];
	char	moar[5];

	/*printf("Here are the existing tables.\n");*/
	printf("Which table would you like to delete?\n");
	fgets(table, 20, stdin);
	null_term(table);
	if ((remove(table)) == 0)
	{
		printf("anything else you'd like to do?\n");
		fgets(moar, 5, stdin);
		null_term(moar);
		if (strcmp(moar, "yes") == 0)
			return (1);
		return (0);
	}
	return (-1);
}
