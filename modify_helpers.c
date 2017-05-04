/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfu <cfu@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 00:54:07 by cfu               #+#    #+#             */
/*   Updated: 2017/05/04 00:33:10 by cfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		update_entry(char *table, char *data, int line)
{
	FILE	*fp;
	FILE	*fp2;
	char	*str;
	int		count;
	size_t	len;

	count = 1;
	str = NULL;
	len = 100;
	fp = fopen(table, "r");
	fp2 = fopen(".tmp.tab", "w+");
	while(getline(&str, &len, fp) > 0)
	{
		if(count == line)
		{
			getline(&str, &len, fp);
			fprintf(fp2, "[%s]\n", data);
		}
		count++;
		fprintf(fp2, "%s", str);
	}
	fclose(fp);
	fclose(fp2);
	remove(table);
	rename(".tmp.tab", table);
	return (0);
}

int		append_entry(char *table)
{
	FILE			*fp;
	size_t			len;
	char			*str;
	char			entry[100];

	str = NULL;
	len = 100;
	printf("Gimme your data in following format, ");
	printf("separated by commas sans brackets:\n");
	fp = fopen(table, "r");
	if (getline(&str, &len, fp) != -1)
		printf("%s", str);
	fgets(entry, 100, stdin);
	null_term(entry);
	fclose(fp);
	fp = fopen(table, "a");
	fprintf(fp, "[%s]\n", entry);
	fclose(fp);
	return (0);
}

int		insert_entry(char *table, char *data, int line)
{
	FILE		*fp;
	FILE		*fp2;
	char		*str;
	size_t		len;
	int			count;

	str = NULL;
	len = 100;
	count = 0;
	fp = fopen(table, "r");
	fp2 = fopen(".tmp.tab", "w+");
	while (getline(&str, &len, fp) > 0)
	{
		count++;
		fprintf(fp2, "%s", str);
		if (count == line)
			fprintf(fp2, "[%s]\n", data);
	}
	fclose(fp);
	fclose(fp2);
	remove(table);
	rename(".tmp.tab", table);
	return (0);
}

int		delete_entry(char *table, int line)
{
	FILE	*fp;
	FILE	*fp2;
	char	*str;
	int		count;
	size_t	len;

	str = NULL;
	count = 0;
	len = 100;
	fp = fopen(table, "r");
	fp2 = fopen(".tmp.tab", "w+");
	while(getline(&str, &len, fp) > 0)
	{
		count++;
		if(count != line)
			fprintf(fp2, "%s", str);
	}
	fclose(fp);
	fclose(fp2);
	remove(table);
	rename(".tmp.tab", table);
	return (0);
}
