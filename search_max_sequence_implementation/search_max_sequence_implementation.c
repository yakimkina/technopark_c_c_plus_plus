//
// Created by Polina Yakimkina on 26.03.2022.
//

#include "search_max_sequence_implementation.h"

int	*create_array_contains_all_sum(const int *buf, const size_t len)
{
	int *arr = malloc(len * sizeof(int));
	if (arr == NULL)
	{
		// free
		return NULL;
	}

	arr[0] = buf[0];
	for (size_t i = 1; i < len; i++)
		arr[i] = arr[i - 1] + buf[i];

	return arr;
}

// change max sequence on new
void	update_max_value(t_max_elem *old, t_max_elem *new)
{
	old->begin_index = new->begin_index;
	old->end_index = new->end_index;
	old->length = new->length;
}

size_t	binary_search(const int *arr_sum, const size_t i, const size_t len, const int N)
{
	size_t	first = i;
	size_t	last = len;
	size_t	mid;

	while (first < last)
	{
		mid = (first + last) / 2;
		if (arr_sum[mid] < N)
			first = mid + 1;
		else
			last = mid;
	}
//	printf("%zu", first);
	return first;
}

// searches sequence starting from index i which sum less than N; returns length of found sequence
t_max_elem	search_sequence_from_i(const int *arr_sum, const size_t i, const size_t len, const int N)
{
	t_max_elem	max_elem;
	int	new_N = N + arr_sum[i - 1];

	max_elem.begin_index = i;
	max_elem.end_index = binary_search(arr_sum, i, len, new_N);
//	printf("|%zu\n", max_elem.end_index);
	max_elem.length = max_elem.end_index - max_elem.begin_index;

	return max_elem;
}
