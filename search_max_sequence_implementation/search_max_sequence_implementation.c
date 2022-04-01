//
// Created by Polina Yakimkina on 26.03.2022.
//

#include "search_max_sequence_single_thread.h"

// change max sequence on new
void	update_max_value(const int *src, int **dst, size_t *len_dst, const size_t from, const size_t len)
{
	// update length of sequence
	*len_dst = len;

	int *dst_new = realloc(*dst, len);
	//checks if ok

	memcpy((void *)dst_new, (const void *)(src + from), len);
	// checks if ok
}


// searches sequence starting from index i which sum less than N; returns length of found sequence
size_t	search_sequence_from_i(const int *srci, int **dst_seq, const size_t len, const int N)
{
	long long int	cur_sum = 0;
	size_t			len_cur_sum = 0;

	for (size_t j = 0; j < len; j++)
	{
		cur_sum += *(srci + j);

		if (cur_sum > N)
			break;

		len_cur_sum += 1;
	}

	return len_cur_sum;
}


int	*search_max_sequence_single_thread(const int *src, const size_t len, const int N)
{
	int	*max_seq = NULL;
	size_t	len_max_seq = 0;

	for (size_t i = 0; i < len; i++)
	{
		len_i = search_sequence_from_i(&src[i], &max_seq, len, N);

		// if found sequence longer, should save it and delete previous
		if (len_i > max_seq_len)
			update_max_value(src, &max_seq, &len_max_seq, i, len_i);

		// if length of max found sequence is already more than length have left in source input,
		// there is no point to continue, so break out of cycle
		if (len_max_seq > (len - i))
			break;
	}

	//dont forget about \0 -- or not ?
	return max_seq;
}