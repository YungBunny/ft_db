/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfu <cfu@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 01:05:52 by cfu               #+#    #+#             */
/*   Updated: 2017/05/04 00:35:45 by cfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	null_term(char *str)
{
	int		i;

	i = strlen(str) - 1;
	if (str[i] == '\n')
		str[i] = '\0';
}

int    line_count(char *table)
{
	FILE	*fp;
	int		count;
	char	*buff;
	size_t	buffsize = 100;

	buff = malloc(sizeof(char)* 101);
	bzero(buff, sizeof(char)* 101);
	count = 0;
	fp = fopen(table, "r");
	while (getline(&buff, &buffsize, fp) > 0)
		count++;
	fclose(fp);
	free(buff);
	return (count);
}

int		open_check(char *table)
{
	FILE	*fp;

	fp = fopen(table, "r");
	if (fp == NULL)
	{
		printf("shit don't exist\n");
		fclose(fp);
		return (0);
	}
	return (1);
}

int		line_check(char *table, char *lines)
{
	int		max;
	int		row;

	row = atoi(lines) + 1;
	max = line_count(table);
	if (row > max)
	{
		printf("that line don't exist... try again loser.\n");
		return (0);
	}
	return (row);
}

int		element_count(char *entry)
{
	int		count;
	int		i;
	char	c;

	count = 1;
	i = 0;
	c = ',';
	if (entry)
	{
		while (entry[i])
		{
			if (strcmp(&entry[i], &c) == 0)
				count++;
			i++;
		}
		return (count);
	}
	return (0);
}

int		entries_total(char *table)
{
	FILE	*fp;
	char	*str;
	size_t	len;
	int		total;

	total = -1;
	fp = fopen(table, "r");
	str = malloc(sizeof(char)* 101);
	bzero(str, sizeof(char)*101);
	while (getline(&str, &len, fp) > 0)
		total++;
	fclose(fp);
	free(str);
	return (total);
}

char	*choose_row_insert(char *table, char *str, size_t len)
{
	char	row[5];
	char	*num;
	char	*categories;
	int		entries;
	FILE	*fp;

	fp = fopen(table, "r");
	if (getline(&str, &len, fp) < 0)
		return ("-1");
	categories = str;
	entries = entries_total(table);
	printf("%s\n%s%s%i%s\n", "Here are the categories of this table:", categories, "There are ", entries, " entries.");
	printf("After which entry would ya like to make an insert? ");
	printf("Enter row #\n");
	fgets(row, 5, stdin);
	null_term(row);
	num = strdup(row);
	return (num);
}

char	*choose_row_update(char *table, char *str, size_t len)
{
	char	row[5];
	char	*num;
	char	*categories;
	int		entries;
	FILE	*fp;

	fp = fopen(table, "r");
	if (getline(&str, &len, fp) < 0)
		return ("-1");
	categories = str;
	entries = entries_total(table);
	printf("%s\n%s%s%i%s\n", "Here are the categories of this table:", categories, "There are ", entries, " entries.");
	printf("Which entry would ya like to update? ");
	printf("Enter row #\n");
	fgets(row, 5, stdin);
	null_term(row);
	num = strdup(row);
	return (num);
}


int		retry(void)
{
	char	retry[5];

	printf("wrong number of entries, wanna try again?");
	fgets(retry, 5, stdin);
	null_term(retry);
	if (strcmp(retry, "yes") == 0)
		return (1);
	else if (strcmp(retry, "no") == 0)
		return (0);
	else
	{
		printf("horribre engrish. bai.\n");
		return (-1);
	}
}
