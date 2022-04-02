//
// Created by Polina Yakimkina on 29.03.2022.
//

#include "search_max_sequence_multi_thread.h"
#define NUM_PROC sysconf(_SC_NPROCESSORS_ONLN)/2

pthread_mutex_t mutex;

void	print_arr(const int *arr, size_t len)
{
	for (size_t i = 0; i < len; i++)
		printf("%i, ", arr[i]);
	printf("\n");
}

char	*get_sequence_of_chars_from_element(const int *buf, t_max_elem elem)
{
	char *max_seq = malloc((elem.length + 1) * sizeof(char));
	if (max_seq == NULL)
	{
		print_free_and_null("[ERR0R] Can't allocacte memory to create char array.", (void**)&buf);
		return NULL;
	}

	for (size_t i = 0; i < elem.length; i++)
		max_seq[i] = buf[elem.begin_index + i] + '0';
	max_seq[elem.length] = '\0';

	return max_seq;
}

char	*search_max_sequence_single_thread(const int *buf, const size_t len, const int N)
{
	t_max_elem max_elem = {.length = 0};

	int *arr_sum = create_array_contains_all_sum(buf, len);
	if (arr_sum == NULL)
		return NULL;

	print_arr(arr_sum, len);
//	long number_of_processors = sysconf(_SC_NPROCESSORS_ONLN);

	printf("proc: %li\n", NUM_PROC);

	t_max_elem	max_elem_cur = {.length = 0};
	pthread_t **arr_threads = malloc(NUM_PROC * sizeof(pthread_t *));
	if (arr_threads == NULL)
	{
		print_free_and_null("[ERR0R] Can't create thread array during reading file.\n", (void**)&buf);
		free(arr_sum);
		return NULL;
	}

	for (size_t i = 0; i < len; i += NUM_PROC)
	{
		for (int j = 0; j < NUM_PROC; j++)
		{
			pthread_t search_thread;
			args_search args = {.arr_sum = arr_sum, .i = i, .len = len, .N = N};
			printf("hear\n");
			int errflag = pthread_create(&search_thread, NULL, search_sequence_from_i, (void*)&args);
			printf("hear1\n");
			if (errflag != 0)
			{
				print_free_and_null("[ERR0R] Can't create thread during reading file.\n", (void**)&buf);
				free(arr_sum);
				return NULL;
			}
			printf("hear2\n");
			// if found sequence longer, should save it
			if (args.max_elem.length > max_elem.length)
			{
				pthread_mutex_lock(&mutex);
				update_max_value(&max_elem, &max_elem_cur);
				pthread_mutex_unlock(&mutex);
			}
			printf("hear3\n");
			arr_threads[j] = &search_thread;
			printf("arr0: %p\n", (void*)&search_thread);

		}

		for (int j = 0; j < NUM_PROC; j++)
		{
			printf("arr: %p\n", (void*)&arr_threads[j]);
			int err;
			if ((err = pthread_join((*arr_threads)[j], NULL)) != 0)
			{

				printf("err: %d\n", err);
			}
		}
		printf("hear4\n");
		// if length of max found sequence is already more than length have left in source input,
		// there is no point to continue, so break out of cycle
		if (max_elem.length > (len - i))
			break;
	}

	free(arr_threads);
	free(arr_sum);
	return get_sequence_of_chars_from_element(buf, max_elem);
}


void	convert_buf_to_int(const char *char_buf, int *int_buf, const size_t len)
{
	for (size_t i = 0; i < len; i++)
		int_buf[i] = char_buf[i] - '0';
}


char	*search_max_sequence_multithread(const char *filename, const int N)
{
	char	*buf = read_from_file_multithread(filename);
	if (buf == NULL)
		return NULL;

	size_t buf_len = strlen(buf);
	int *int_buf = malloc(buf_len * sizeof(int));
	if (int_buf == NULL)
	{
		print_free_and_null("[ERR0R] Can't allocacte memory to create int array.", (void**)&buf);
		return NULL;
	}

	convert_buf_to_int(buf, int_buf, buf_len);

	print_arr(int_buf, buf_len);

	char *max_seq = search_max_sequence_single_thread(int_buf, buf_len, N);

	free(buf);

	return max_seq;
}
