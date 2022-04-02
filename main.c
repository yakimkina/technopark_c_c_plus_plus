//
// Created by Polina Yakimkina on 26.03.2022.
//

#include <stdio.h>
#include <time.h>
#include <limits.h>
#include "search_max_sequence_single_thread/search_max_sequence_single_thread.h"
#include "search_max_sequence_multiple_threads/search_max_sequence_multi_thread.h"

#define CLK_TCK         __DARWIN_CLK_TCK

int main()
{
	clock_t start, stop;

	start = clock();
	char *max1 = search_max_sequence_single_thread("../tests/tests_sample/testBasic2.txt", 17);
	stop = clock();
	float time1 = (stop - start) / CLK_TCK;

	start = clock();
	char *max2 = search_max_sequence_multithread("../tests/tests_sample/testBasic1.txt", 7);
	stop = clock();
	float time2 = (stop - start) / CLK_TCK;

	printf("single thread: %f\n"
		   "multiple thread: %f\n"
		   "delta: %f\n",
		   time1, time2, time2 - time1);

	printf("%s\n", max1);
	free(max1);
	free(max2);
	return 0;
}
