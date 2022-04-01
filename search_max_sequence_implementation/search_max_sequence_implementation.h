//
// Created by Polina Yakimkina on 26.03.2022.
//

#ifndef SEARCH_MAX_SEQUENCE_H
#define SEARCH_MAX_SEQUENCE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_max_elem {
	size_t	begin_index;
	size_t 	end_index;
	size_t	length;
}				t_max_elem;

t_max_elem	search_sequence_from_i(const int *arr_sum, const size_t i, const size_t len, const int N);
int	*create_array_contains_all_sum(const int *buf, const size_t len);
void	update_max_value(t_max_elem *old, t_max_elem *new);

#endif
