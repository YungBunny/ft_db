/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfu <cfu@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 00:54:07 by cfu               #+#    #+#             */
/*   Updated: 2017/04/30 23:02:59 by cfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

/*int		update_entry(char *table, int line, char *replace)
{
	FILE	*fp;
	FILE	*fp2;
	char	*buff;
	int count = 0;
	size_t	buffsize = 100;
	buff = (char*)malloc(buffsize*sizeof(char));
	fp = fopen(table, "r");
	fp2 = fopen(".tmp.tab", "w+");
	while(getline(&buff, &buffsize, fp) > 0)
	{
		count++;
		fprintf(fp2, "%s", buff);
		if(count == line)
			fprintf(fp2, "%s", insert);
	}
	fclose(fp);
	fclose(fp2);
	remove(table);
	rename(".tmp.tab", table);
	return (1);
}

int		update_entry()
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

int		insert_entry(char *table)
{
	FILE		*fp;
	FILE		*fp2;
	char		entry[5];
	char		data[100];
	int			max;
	int			lines;
	char		*str;
	size_t		len;
	int			count;

	max = line_count(table);
	str = NULL;
	len = 0;
	count = 0;
	printf("Here the categories of this table. There are x number of entries.\n");
	printf("After which entry would ya like to make an insert?");
	printf("Enter line #\n");
	fgets(entry, 5, stdin);
	null_term(entry);
	lines = atoi(entry) + 1;
	if (lines > max)
	{
		printf("that line doesn't exist... try again loser.\n");
		return (0);
	}
	fp = fopen(table, "r");
	printf("Gimme your data in following format, ");
	printf("separated by commas sans brackets:\n");
	if (getline(&str, &len, fp) != -1)
		printf("%s", str);
	fgets(data, 100, stdin);
	null_term(data);
	fclose(fp);
	fp = fopen(table, "r");
	fp2 = fopen(".tmp.tab", "w+");
	while (getline(&str, &len, fp) > 0)
	{
		count++;
		fprintf(fp2, "%s", str);
		if (count == lines)
			fprintf(fp2, "[%s]\n", data);
	}
	fclose(fp);
	fclose(fp2);
	remove(table);
	rename(".tmp.tab", table);
	return (0);
}

/*int		delete_entry(char *table, int line)
{
	FILE	*fp;
	FILE	*fp2;
	char	*buff;
	int count = 0;
	size_t	buffsize = 100;
	buff = (char*)malloc(buffsize*sizeof(char));
	fp = fopen(table, "r");
	fp2 = fopen(".tmp.tab", "w+");
	while(getline(&buff, &buffsize, fp) > 0)
	{
		count++;
		if(count != line)
			fprintf(fp2, "%s", buff);
	}
	fclose(fp);
	fclose(fp2);
	remove(table);
	rename(".tmp.tab", table);
	return (1);
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
