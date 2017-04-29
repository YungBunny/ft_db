/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfu <cfu@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 00:54:07 by cfu               #+#    #+#             */
/*   Updated: 2017/04/28 21:20:53 by cfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

/*int		update_entry()
{
	char	entry[5];
	int		lines;

	printf("Here are all the existing entries. ");
	printf("Which entry would you like to update? Enter a line #\n");
	fgets(entry, 5, stdin);
	return (0);
}
*/

int		append_entry(char *table)
{
	FILE			*fp;
	size_t			len;
	char			*str;
	char			entry[100];

	/*	printf("Here are all the existing entries. ");*/
	str = NULL;
	len = 100;
	fp = fopen(table, "r");
	if (fp == NULL)
	{
		printf("shit don't exist\n");
		fclose(fp);
		return (0);
	}
	printf("Gimme your data in following format, ");
	printf("separated by commas sans brackets:\n");
	if (getline(&str, &len, fp) != -1)
		printf("%s\n", str);
	fgets(entry, 100, stdin);
	null_term(entry);
	fclose(fp);
	fp = fopen(table, "a");
	fprintf(fp, "\n[%s]", entry);
	fclose(fp);
	return (0);
}
/*
int		insert_entry(char *table)
{
	FILE	*fp;
	char	entry[5];
	int		lines;

	printf("Here are all the existing entries. ");
	printf("After which entry would ya like to make an insert? ");
	printf("Enter line #\n");
	fgets(entry, 5, stdin);
	way to count the lines, maybe new lines. then fprintf
	return (0);
}

int		delete_entry()
{
	char	entry[5];
	int		lines;

	*printf("Here are all the existing entries. ");
	printf("Which entry would you like to delete? Enter a line #\n");
	fgets(entry, 5, stdin);
	return (0);
}
*/
