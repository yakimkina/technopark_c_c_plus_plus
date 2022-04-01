//
// Created by Polina Yakimkina on 26.03.2022.
//

#include "search_max_sequence_single_thread/search_max_sequence.h"

int main()
{
	char *max = search_max_sequence("../tests/tests_sample/testBasic1.txt", 7);
	printf("max: %s\n", max);
	return 0;
}
