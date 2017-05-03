/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfu <cfu@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 01:05:52 by cfu               #+#    #+#             */
/*   Updated: 2017/05/01 16:15:50 by cfu              ###   ########.fr       */
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

	count = 0;
	fp = fopen(table, "r");
	while (getline(&buff, &buffsize, fp) > 0)
		count++;
	fclose(fp);
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

int		line_check(char *table, char *entry)
{
	int		lines;
	int		max;

	lines = atoi(entry) + 1;
	max = line_count(table);
	if (lines > max)
	{
		printf("that line don't exist... try again loser.\n");
		return (0);
	}
	return (lines);
}
