#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	null_term(char *str)
{
	int		i;

	i = strlen(str) - 1;
	if (str[i] == '\n')
		str[i] = '\0';
}

int		insert_entry(char *table)
{
	FILE		*fp;
	/*	char		entry[5];
	 *	char		data[100];*/
	int			lines;
	char		*str;
	size_t		len;

	str = NULL;
	len = 0;
	lines = 3;
	printf("Here the categories of this table. There are x number of entries.\n");
	printf("After which entry would ya like to make an insert?");
	printf("Enter line #\n");
	/*fgets(entry, 5, stdin);
	null_term(entry);
	lines = atoi(entry);*/
	fp = fopen(table, "r");
	while (lines >= 0)
	{
		if ((getline(&str, &len, fp)) != -1)
			lines--;
		else
		{
			printf("that line doesn't exist... try again loser.\n");
			fclose(fp);
			return (0);
		}
	}
	printf("Gimme your data in following format, ");
	printf("separated by commas sans brackets:\n");
/*	if (getline(&str, &len, fp) != -1)
		printf("%s", str);
	fgets(data, 100, stdin);
	null_term(data);
	fclose(fp);
	fp = fopen(table, "w+");
	fprintf(fp, "\n[%s]", data);
	fclose(fp);
	*/
	fp = fopen(table, "w+");
	fprintf(fp, "[Ivan, 22, CA]\n");
	fclose(fp);
	return (0);
}

int		main(void)
{
	insert_entry("42");
	return (0);
}
