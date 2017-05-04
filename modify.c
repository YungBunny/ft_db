/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfu <cfu@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 00:51:44 by cfu               #+#    #+#             */
/*   Updated: 2017/05/04 00:34:51 by cfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		update_helper(char *table, char *str, size_t len)
{
	FILE	*fp;
	char	*row;
	char	data[100];
	int		line;

	str = NULL;
	len = 100;
	row = choose_row_update(table, str, len);
	if ((line = line_check(table, row)) == 0)
		return (0);
	fp = fopen(table, "r");
	printf("Gimme your data in following format, ");
	printf("separated by commas sans brackets:\n");
	if (getline(&str, &len, fp) == -1)
		return (0);
	printf("%s", str);
	fgets(data, 100, stdin);
	null_term(data);
	fclose(fp);
	if (element_count(str) != element_count(data))
	{
		if (retry() == 1)
			update_helper(table, str, len);
		else if (retry() == -1 || retry() == 0)
			return (0);
	}
	update_entry(table, data, line);
	return (0);
}

int		insert_helper(char *table, char *str, size_t len)
{
	FILE	*fp;
	char	*row;
	char	data[100];
	int		line;

	str = NULL;
	len = 0;
	row = choose_row_insert(table, str, len);
	if ((line = line_check(table, row)) == 0)
		return (0);
	fp = fopen(table, "r");
	printf("Gimme your data in following format, ");
	printf("separated by commas sans brackets:\n");
	if (getline(&str, &len, fp) == -1)
		return (0);
	printf("%s", str);
	fgets(data, 100, stdin);
	null_term(data);
	fclose(fp);
	insert_entry(table, data, line);
	return (0);
}

int		delete_helper(char *table)
{
	char	entry[10];
	char	*row;
	int		line;
	int		entries;

	entries = entries_total(table);
	printf("%s%i%s\n", "There are ", entries, " entries.");
	printf("Which entry would ya like to delete? ");
	printf("Enter row #\n");
	fgets(entry, 10, stdin);
	null_term(entry);
	row = strdup(entry);
	if ((line = line_check(table, row)) == 0)
		return (0);
	delete_entry(table, line);
	return (0);
}

void	modify_choices(char *table, char *command)
{
	char	*str;
	size_t	len;

	str = NULL;
	len = 0;
	if (strcmp(command, "1") == 0)
		update_helper(table, str, len);
	else if (strcmp(command, "2") == 0)
		append_entry(table);
	else if (strcmp(command, "3") == 0)
		insert_helper(table, str, len);
	else if (strcmp(command, "4") == 0)
		delete_helper(table);
	else
		printf("Wot. Try again, buddy.\n");
}

int		modify_table(void)
{
	FILE	*fp;
	char	table[20];
	char	command[5];

	/*	printf("Here are the existing tables.\n");*/
	printf("Which table would you like to modify?\n");
	fgets(table, 20, stdin);
	null_term(table);
	fp = fopen(table, "r");
	if (open_check(table) == 0)
		return (0);
	printf("What would you like to do? ");
	printf("(1)update, (2)append, (3)insert, or (4)delete an entry? # plz.\n");
	fgets(command, 5, stdin);
	null_term(command);
	modify_choices(table, command);
	printf("anything else you'd like to do?\n");
	fgets(command, 5, stdin);
	null_term(command);
	if (strcmp(command, "yes") == 0)
		return (1);
	return (0);
}
