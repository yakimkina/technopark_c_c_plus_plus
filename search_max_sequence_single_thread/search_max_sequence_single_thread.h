//
// Created by Polina Yakimkina on 29.03.2022.
//

#ifndef SEARCH_MAX_SEQUENCE_SINGLE_THREAD_H
#define SEARCH_MAX_SEQUENCE_SINGLE_THREAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search_max_sequence_implementation/search_max_sequence_implementation.h"


char	*search_max_sequence_single_thread(const char *filename, const int N);
void	read_file_to_buffer(FILE *file, char **buffer);

void	print_error(const char *str);
char	check_null_pointer(const void *obj, const char *string_output);
void	print_free_and_null(const char *string_output, void **obj);


#endif
