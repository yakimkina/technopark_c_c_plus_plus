//
// Created by Polina Yakimkina on 01.04.2022.
//

#include "search_max_sequence_multi_thread.h"

void	print_error(const char *str)
{
	printf("%s\n", str);
}

char	check_null_pointer(const void *obj, const char *string_output)
{
	if (!obj)
	{
		print_error(string_output);
		return 1;
	}
	return 0;
}

void	print_free_and_null(const char *string_output, void **obj)
{
	print_error(string_output); // print error
	free(*obj); // free allocated memory
	*obj = NULL; // make null
}
