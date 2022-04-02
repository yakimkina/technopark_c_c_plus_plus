//
// Created by Polina Yakimkina on 26.03.2022.
//

#ifndef SEARCH_MAX_SEQUENCE_H
#define SEARCH_MAX_SEQUENCE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../search_max_sequence.h"

void	print_free_and_null(const char *string_output, void **obj);

typedef struct	s_max_elem {
	size_t	begin_index;
	size_t 	end_index;
	size_t	length;
}				t_max_elem;


void	*search_sequence_from_i(void *args);
int	*create_array_contains_all_sum(const int *buf, const size_t len);
void	update_max_value(t_max_elem *old_elem, t_max_elem *new_elem);

#endif
