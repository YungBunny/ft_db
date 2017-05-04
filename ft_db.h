/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfu <cfu@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 01:00:21 by cfu               #+#    #+#             */
/*   Updated: 2017/05/03 23:43:06 by cfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void		null_term(char *str);
int			line_count(char *table);
int			open_check(char *table);
int			line_check(char *table, char *lines);
int			element_count(char *entry);
int			entries_total(char *table);
char		*choose_row_insert(char *table, char *str, size_t len);
char		*choose_row_update(char *table, char *str, size_t len);
int			retry(void);
int			create_table(void);
int			update_helper(char *table, char *str, size_t len);
int			insert_helper(char *table, char *str, size_t len);
int			update_entry(char *table, char *data, int line);
int			append_entry(char *table);
int			insert_entry(char *table, char *data, int line);
int			delete_entry(char *table, int line);
void		modify_choices(char *table, char *command);
int			modify_table(void);
int			delete_table(void);
int			choices(void);

#endif
