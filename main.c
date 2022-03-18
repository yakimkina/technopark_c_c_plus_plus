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
			mat.matrix_ptr[i][j] = (float)(rand() % 100);//-10 + 20*(float)rand();
	}
	mat.matrix_ptr[1][1] = 0;
	mat.matrix_ptr[4][3] = 0;
	mat.matrix_ptr[7][2] = 0;
	mat.matrix_ptr[9][5] = 0;

	printf("\n=======INPUT=======\n");
	print_matrix(&mat);

	t_matrix new_matrix;
	delete_matrix_rows_and_cols_with_null_elements(&mat, &new_matrix);

	printf("\n=======OUTPUT=======\n");
	print_matrix(&new_matrix);
}
