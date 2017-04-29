/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfu <cfu@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 00:49:58 by cfu               #+#    #+#             */
/*   Updated: 2017/04/28 01:05:04 by cfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		create_table(void)
{
	FILE	*fp;
	char	str[100];
	char	filename[20];
	char	moar[5];

	printf("Gimme the name of this data table\n");
	fgets(filename, 20, stdin);
	null_term(filename);
	fp = fopen(filename, "w");
	printf("Gimme dem classes/categories separated by commas\n");
	fgets(str, 100, stdin);
	null_term(str);
	fprintf(fp, "[%s]", str);
	fclose(fp);
	printf("anything else you'd like to do?\n");
	fgets(moar, 5, stdin);
	null_term(moar);
	if (strcmp(moar, "yes") == 0)
		return (1);
	return (0);
}
