//
// Created by Polina Yakimkina on 17.03.2022.
//

#ifndef DELETE_MATRIX_ROWS_AND_COLS_WITH_ZERO_H
#define DELETE_MATRIX_ROWS_AND_COLS_WITH_ZERO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_matrix
{
	float**	matrix_ptr;
	size_t	num_rows;
	size_t	num_cols;
}				t_matrix;

void	delete_matrix_rows_and_cols_with_zero(t_matrix *matrix_src, t_matrix *matrix_dst);

char	check_null_pointer(const void *obj, char *string_output);
void	free_recursive(void **obj, size_t size);
void	make_null_matrix(t_matrix *dst);
void	print_error(char *str);


#endif
