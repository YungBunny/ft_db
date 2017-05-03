/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfu <cfu@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 00:51:44 by cfu               #+#    #+#             */
/*   Updated: 2017/05/01 20:32:27 by cfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		update_helper(char *table, char *str, size_t len)
{
	FILE	*fp;
	char	entry[5];
	char	data[100];
	int		line;

	str = NULL;
	len = 100;
	printf("Here are the categories of this table. There are x entries.\n");
	printf("Which entry would you like to edit?");
	printf("Enter row #\n");
	fgets(entry, 5, stdin);
	null_term(entry);
	if ((line = line_check(table, entry)) == 0)
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
	update_entry(table, data, line);
	return (0);
}

int		insert_helper(char *table, char *str, size_t len)
{
	FILE	*fp;
	char	entry[5];
	char	data[100];
	int		line;

	str = NULL;
	len = 0;
	printf("Here are the categories of this table. There are x entries.\n");
	printf("After which entry would ya like to make an insert? ");
	printf("Enter row #\n");
	fgets(entry, 5, stdin);
	null_term(entry);
	if ((line = line_check(table, entry)) == 0)
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
	char	entry[5];
	int		line;

	printf("Here are the categories of this table. There are x entries.\n");
	printf("After which entry would ya like to delete? ");
	printf("Enter row #\n");
	fgets(entry, 5, stdin);
	null_term(entry);
	if ((line = line_check(table, entry)) == 0)
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
