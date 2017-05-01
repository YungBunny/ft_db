/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfu <cfu@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 01:00:21 by cfu               #+#    #+#             */
/*   Updated: 2017/04/30 22:50:22 by cfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void		null_term(char *str);
int			line_count(char* table);
int			create_table(void);
int			update_entry(char *table, int line, char *replace);
int			append_entry(char *table);
int			insert_entry(char *table);
int			delete_entry(char *table, int line);
void		modify_choices(char *table, char *command);
int			modify_table(void);
int			delete_table(void);
int			choices(void);

#endif
