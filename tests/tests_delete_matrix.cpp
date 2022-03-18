//
// Created by Polina Yakimkina on 18.03.2022.
//

#include <gtest/gtest.h>

extern "C" {
	#include "delete_matrix_rows_and_cols_with_zero.h"
}

char	function_works(t_matrix *src, t_matrix *dst)
{
	delete_matrix_rows_and_cols_with_zero(src, src);
	return 1;
}

TEST(DeathTest, EmptyInput)
{
	EXPECT_EXIT(delete_matrix_rows_and_cols_with_zero(NULL, NULL), testing::ExitedWithCode(0), "Success");
}