//
// Created by Polina Yakimkina on 30.03.2022.
//

#include <gtest/gtest.h>

extern "C" {
#include "../search_max_sequence_single_thread/search_max_sequence_single_thread.h"
#include "../search_max_sequence_multiple_threads/search_max_sequence_multi_thread.h"
}

TEST(TestBasic, 1)
{
	char *max = search_max_sequence_single_thread("../tests/tests_sample/testBasic1.txt", 7);
	free(max);

	EXPECT_EQ(strcmp(max, "123"), 0);
}

TEST(TestBasic, 2)
{
	char *max = search_max_sequence_single_thread("../tests/tests_sample/testBasic1.txt", 7);
	free(max);

	EXPECT_EQ(strcmp(max, "111111111"), 0);
}