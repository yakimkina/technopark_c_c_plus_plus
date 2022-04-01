//
// Created by Polina Yakimkina on 29.03.2022.
//

#ifndef SEARCH_MAX_SEQUENCE_ONE_THREAD_H
#define SEARCH_MAX_SEQUENCE_ONE_THREAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../search_max_sequence_implementation/search_max_sequence_implementation.h"

char	*search_max_sequence(const char *filename, const int N);

void	print_error(char *str);
void	read_file_to_buffer(FILE *file, char **buffer);


#endif
