/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfu <cfu@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 00:47:56 by cfu               #+#    #+#             */
/*   Updated: 2017/04/28 12:44:00 by cfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		choices(void)
{
	char	str[5];
	int		going;

	going = 0;
	printf("Didja wanna \x1b[33m(1)create\x1b[0m, ");
	printf("\x1b[36m(2)modify\x1b[0m, " "\x1b[31m(3)delete\x1b[0m, ");
	printf("or \x1b[32m(4)search data?\x1b[0m ");
	printf("Gimme a number.\n");
	fgets(str, 5, stdin);
	null_term(str);
	if (strcmp(str, "1") == 0)
		going = create_table();
	else if (strcmp(str, "2") == 0)
		going = modify_table();
	else if (strcmp(str, "3") == 0)
		going = delete_table();
	else if (strcmp(str, "4") == 0)
		printf("u ask too much kbai.\n");
	else
		printf("What is this, go away. No DB for you.\n");
	return (going);
}
