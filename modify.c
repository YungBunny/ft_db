/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfu <cfu@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 00:51:44 by cfu               #+#    #+#             */
/*   Updated: 2017/04/28 01:04:32 by cfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	modify_choices(char *table, char *command)
{
	if (strcmp(command, "1") == 0)
		printf("u ask too much kbai.\n");
	else if (strcmp(command, "2") == 0)
		append_entry(table);
	else if (strcmp(command, "3") == 0)
		printf("u ask too much kbai.\n");
	else if (strcmp(command, "4") == 0)
		printf("u ask too much kbai.\n");
	else
		printf("Wot. Try again, buddy.\n");
}

int		modify_table(void)
{
	char	table[20];
	char	command[5];

	/*	printf("Here are the existing tables.\n");*/
	printf("Which table would you like to modify?\n");
	fgets(table, 20, stdin);
	null_term(table);
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
