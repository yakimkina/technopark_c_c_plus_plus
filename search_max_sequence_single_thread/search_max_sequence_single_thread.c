//
// Created by Polina Yakimkina on 29.03.2022.
//

#include "search_max_sequence_single_thread.h"


static void	print_arr(const int *arr, size_t len)
{
	for (size_t i = 0; i < len; i++)
		printf("%i, ", arr[i]);
	printf("\n");
}

static char	*get_sequence_of_chars_from_element(const int *buf, t_max_elem elem)
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

//	printf("%zu|%zu|%zu\n", elem.begin_index, elem.end_index, elem.length);

	return max_seq;
}

char	*search_max_sequence_one_thread(const int *buf, const size_t len, const int N)
{
	t_max_elem max_elem = {.length = 0};

	int *arr_sum = create_array_contains_all_sum(buf, len);
	if (arr_sum == NULL)
		return NULL;

//	print_arr(arr_sum, len);

	t_max_elem	max_elem_cur;
	for (size_t i = 0; i < len; i++)
	{
		max_elem_cur = search_sequence_from_i(arr_sum, i, len, N);

		// if found sequence longer, should save it
		if (max_elem_cur.length > max_elem.length)
			update_max_value(&max_elem, &max_elem_cur);

		// if length of max found sequence is already more than length have left in source input,
		// there is no point to continue, so break out of cycle
		if (max_elem.length > (len - i))
			break;
	}

	free(arr_sum);
	return get_sequence_of_chars_from_element(buf, max_elem);
}


static void	convert_buf_to_int(const char *char_buf, int *int_buf, const size_t len)
{
	for (size_t i = 0; i < len; i++)
		int_buf[i] = char_buf[i] - '0';
}


char	*search_max_sequence_single_thread(const char *filename, const int N)
{
	// open file
	FILE	*file_src =  fopen(filename, "r");
	if (file_src == NULL)
	{
		print_error("[ERR0R] No input stream was passed.");
		return NULL;
	}

	char	*buf = NULL;
	read_file_to_buffer(file_src, &buf);
	//	printf("BUFFER: %s\n", buf);

	// close file
	if (fclose(file_src))
	{
		print_error("[ERR0R] Can't close the stream.");
		return NULL;
	}


	size_t buf_len = strlen(buf);
	int *int_buf = malloc(buf_len * sizeof(int));
	if (int_buf == NULL)
	{
		print_free_and_null("[ERR0R] Can't allocacte memory to create int array.", (void**)&buf);
		return NULL;
	}

	convert_buf_to_int(buf, int_buf, buf_len);

//	print_arr(int_buf, buf_len);

	char *max_seq = search_max_sequence_one_thread(int_buf, buf_len, N);

	free(buf);

	return max_seq;
}
