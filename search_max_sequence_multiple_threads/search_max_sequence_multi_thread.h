//
// Created by Polina Yakimkina on 29.03.2022.
//

#ifndef SEARCH_MAX_SEQUENCE_MULTI_THREAD_H
#define SEARCH_MAX_SEQUENCE_MULTI_THREAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "search_max_sequence_implementation/search_max_sequence_implementation.h"

typedef struct {
	FILE *file;
	char **buffer;
}	args_read_file;

typedef struct {
	const int *arr_sum;
	const size_t i;
	const size_t len;
	const int N;
	t_max_elem	max_elem;
}	args_search;

char	*search_max_sequence_multithread(const char *filename, const int N);
char	*read_from_file_multithread(const char *filename);

void	print_error(const char *str);
char	check_null_pointer(const void *obj, const char *string_output);
void	print_free_and_null(const char *string_output, void **obj);


#endif
