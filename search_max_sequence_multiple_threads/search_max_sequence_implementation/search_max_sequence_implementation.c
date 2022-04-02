//
// Created by Polina Yakimkina on 26.03.2022.
//

#include "search_max_sequence_implementation.h"

int	*create_array_contains_all_sum(const int *buf, const size_t len)
{
	int *arr = malloc(len * sizeof(int));
	if (arr == NULL)
	{
		print_free_and_null("[ERR0R] Can't allocate memory to create sum array.", (void**)(&buf));
		return NULL;
	}

	arr[0] = buf[0];
	for (size_t i = 1; i < len; i++)
		arr[i] = arr[i - 1] + buf[i];

	return arr;
}

// change max sequence on new
void	update_max_value(t_max_elem *old_elem, t_max_elem *new_elem)
{
	old_elem->begin_index = new_elem->begin_index;
	old_elem->end_index = new_elem->end_index;
	old_elem->length = new_elem->length;
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
void	*search_sequence_from_i(void *args)
{
	args_search *ar = (args_search *)args;
	t_max_elem	max_elem;
	int	new_N = ar->N + (ar->arr_sum)[(ar->i) - 1];

	max_elem.begin_index = ar->i;
	max_elem.end_index = binary_search(ar->arr_sum, ar->i, ar->len, new_N);
	max_elem.length = max_elem.end_index - max_elem.begin_index;

	ar->max_elem = max_elem;
	return NULL;
}
