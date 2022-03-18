//
// Created by Polina Yakimkina on 17.03.2022.
//

#include "delete_matrix_rows_and_cols_with_zero.h"


int		count_zeros(char const *arr, size_t size)
{
	int	num = 0;

	for (size_t i = 0; i < size; i++)
		if (arr[i] == 0)
			num += 1;

	return num;
}

void	fill_one_col(float const *src, float *dst, char const *rows, size_t size)
{
	size_t dst_i = 0;

	for (size_t i = 0; i < size; i++)
		if (rows[i] == 0)
			dst[dst_i++] = src[i];
}

char	fill_matrix(const t_matrix *src, t_matrix *dst, char *rows, char *cols)
{
	size_t dst_i = 0;

	dst->num_rows = count_zeros(rows, src->num_rows);
	dst->num_cols = count_zeros(cols, src->num_cols);

	dst->matrix_ptr = (float**)malloc(dst->num_cols * sizeof(float));
	if (check_null_pointer(dst->matrix_ptr, "[ERROR] Error during allocating memory: (fill_matrix) dst->matrix_ptr."))
		return 0;

	for (size_t i = 0; i < src->num_cols; i++)
	{
		if (cols[i] == 0)
		{
			(dst->matrix_ptr)[dst_i] = (float*)malloc(dst->num_rows * sizeof(float));
			if (check_null_pointer(dst->matrix_ptr, "[ERROR] Error during allocating memory: (fill_matrix) dst->matrix_ptr[i]."))
			{
				free_recursive((void**)dst->matrix_ptr, dst_i);
				return 0;
			}

			fill_one_col((src->matrix_ptr)[i], (dst->matrix_ptr)[dst_i], rows, src->num_rows);
			++dst_i;
		}
	}

	return 1;
}

void	find_zeros(t_matrix *src, char *cols, char *rows)
{
	for (size_t i = 0; i < src->num_cols; i++)
		for (size_t j = 0; j < src->num_rows; j++)
		{
			if (src->matrix_ptr[i][j] == 0)
			{
				rows[j] = 1;
				cols[i] = 1;
				break;
			}

			rows[j] |= 0;
		}
}

void	delete_matrix_rows_and_cols_with_null_elements(t_matrix *matrix_src, t_matrix *matrix_dst)
{
	// check valid input data
	if (check_null_pointer(matrix_src, "[ERROR] No source matrix was passed.")
		|| check_null_pointer(matrix_src->matrix_ptr, "[ERROR] Passed matrix is empty.")
		|| check_null_pointer(matrix_dst, "[ERROR] No destination matrix was passed."))
	{
		make_null_matrix(matrix_dst);
		return;
	}

	// check valid input matrix size
	if (matrix_src->num_rows == 0 || matrix_src->num_cols == 0)
	{
		print_error("[ERROR] Size passed equals zero.");
		return;
	}

	// creating array, which would store flags 0 and 1: 1 if row in matrix_src have at least one zero, 0 otherwise
	char *rows_is_zero = (char*)calloc(matrix_src->num_rows, sizeof(char));
	if (check_null_pointer(rows_is_zero, "[ERROR] Error during allocating memory: rows_is_zero."))
		return;

	// creating array, which would store flags 0 and 1: 1 if column in matrix_src have at least one zero, 0 otherwise
	char *cols_is_zero = (char*)calloc(matrix_src->num_cols, sizeof(char));
	if (check_null_pointer(rows_is_zero, "[ERROR] Error during allocating memory: cols_is_zero."))
	{
		free(rows_is_zero);
		return;
	}

	// find all rows and cols with zeros, fill arrays cols_is_zero and rows_is_zero
	find_zeros(matrix_src, cols_is_zero, rows_is_zero);

	// fill destination matrix with non-zero rows and cols
	if (!fill_matrix(matrix_src, matrix_dst, rows_is_zero, cols_is_zero))
	{
		free(rows_is_zero);
		free(cols_is_zero);
		return;
	}

	free(rows_is_zero);
	free(cols_is_zero);
}
