// Copyright [2022] <Polina Yakimkina>
// Created by Polina Yakimkina on 18.03.2022.
//

#include "delete_matrix_rows_and_cols_with_zero.h"

void	free_recursive(void **obj, size_t size)
{
	for (size_t i = 0; i < size; i++)
		free(obj[i]);
	free(obj);
}

void	make_null_matrix(t_matrix *dst)
{
	dst->matrix_ptr = NULL;
	dst->num_rows = 0;
	dst->num_cols = 0;
}

void	print_error(char *str)
{
	printf("%s\n", str);
}

char	check_null_pointer(const void *obj, char *string_output)
{
	if (!obj)
	{
		print_error(string_output);
		return 1;
	}
	return 0;
}
