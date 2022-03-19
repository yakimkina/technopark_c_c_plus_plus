//
// Created by Polina Yakimkina on 17.03.2022.
//

#include "delete_matrix_rows_and_cols_with_zero.h"

void	print_matrix(t_matrix *mat)
{
	for (size_t j = 0; j < mat->num_rows; j++)
	{
		for (size_t i = 0; i < mat->num_cols; i++)
			mat->matrix_ptr[i][j] == 0 ? printf("\033[0;31m%.2f\t", mat->matrix_ptr[i][j]) : printf("\033[0m%.2f\t", mat->matrix_ptr[i][j]);
		printf("\033[0m\n");
	}
}

int 	main()
{
	t_matrix	mat;
	mat.num_rows = 6;
	mat.num_cols = 10;
	mat.matrix_ptr = (float**)malloc(sizeof(float*) * mat.num_cols);

	for (size_t i = 0; i < mat.num_cols; i++)
	{
		mat.matrix_ptr[i] = (float*)malloc(sizeof(float) * mat.num_rows);
		for (size_t j = 0; j < mat.num_rows; j++)
		{
			if (rand() % 10 == 0)
				mat.matrix_ptr[i][j] = 0;
			else
				mat.matrix_ptr[i][j] = (float)(rand() % 100);
		}
	}

	printf("\n=======INPUT=======\n");
	print_matrix(&mat);

	t_matrix new_matrix;
	delete_matrix_rows_and_cols_with_zero(&mat, &new_matrix);

	printf("\n=======OUTPUT=======\n");
	print_matrix(&new_matrix);
}
