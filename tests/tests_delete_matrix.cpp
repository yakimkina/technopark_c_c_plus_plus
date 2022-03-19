//
// Created by Polina Yakimkina on 18.03.2022.
//

#include <gtest/gtest.h>

extern "C" {
	#include "delete_matrix_rows_and_cols_with_zero.h"
}

void	print_matrix(t_matrix *mat)
{
	for (size_t j = 0; j < mat->num_rows; j++)
	{
		for (size_t i = 0; i < mat->num_cols; i++)
			mat->matrix_ptr[i][j] == 0 ? printf("\033[0;31m%.2f\t", mat->matrix_ptr[i][j]) : printf("\033[0m%.2f\t", mat->matrix_ptr[i][j]);
		printf("\033[0m\n");
	}
}

int		matrix_equals(t_matrix *src, t_matrix *right, size_t r, size_t c)
{
	t_matrix dst;
	delete_matrix_rows_and_cols_with_zero(src, &dst);

	for (size_t i = 0; i < c; i++)
	{
		for (size_t j = 0; j < r; j++)
		{
			if (dst.matrix_ptr[i][j] != right->matrix_ptr[i][j])
				return 0;
		}
	}
	return 1;
}


TEST(ErrorTest, ErrorInput)
{
	t_matrix	m;
	t_matrix	d;
	m.matrix_ptr = NULL;

	delete_matrix_rows_and_cols_with_zero(&m, &d);
	EXPECT_EQ(0, 0);
}

TEST(ErrorTest, ErrorInputSize)
{
	t_matrix	m;
	t_matrix	d;
	m.matrix_ptr = (float**)malloc(sizeof(float*) * 1);
	m.num_cols - 0;
	m.num_rows = 0;

	delete_matrix_rows_and_cols_with_zero(&m, &d);
	EXPECT_EQ(0, 0);
}

TEST(BaseTest, MatrixWithoutZeros)
{
	t_matrix	m;
	size_t		r = 2;
	size_t		c = 3;

	m.matrix_ptr = (float**)malloc(sizeof(float*) * c);
	for (size_t i = 0; i < c; i++)
	{
		m.matrix_ptr[i] = (float*)malloc(sizeof(float) * r);
		m.matrix_ptr[i][0] = 1;
		m.matrix_ptr[i][1] = 2;
	}
	m.num_rows = r;
	m.num_cols = c;

	EXPECT_EQ(matrix_equals(&m, &m, m.num_rows, m.num_cols), 1);
}

TEST(BaseTest, BaseMatrix)
{
	t_matrix	m;
	size_t		r = 3;
	size_t		c = 4;

	m.matrix_ptr = (float**)malloc(sizeof(float*) * c);
	for (size_t i = 0; i < c; i++)
	{
		m.matrix_ptr[i] = (float*)malloc(sizeof(float) * r);
		m.matrix_ptr[i][0] = 1;
		m.matrix_ptr[i][1] = 2;
		m.matrix_ptr[i][2] = 3;
	}
	m.matrix_ptr[1][2] = 0;
	m.matrix_ptr[3][2] = 0;
	m.num_rows = r;
	m.num_cols = c;

	t_matrix	right;
	right.num_rows = 2;
	right.num_cols = 2;
	right.matrix_ptr = (float**)malloc(sizeof(float*) * right.num_cols);
	for (size_t i = 0; i < right.num_cols; i++)
	{
		right.matrix_ptr[i] = (float*)malloc(sizeof(float) * right.num_rows);
		right.matrix_ptr[i][0] = 1;
		right.matrix_ptr[i][1] = 2;
	}

	EXPECT_EQ(matrix_equals(&m, &right, right.num_rows, right.num_cols), 1);
}

