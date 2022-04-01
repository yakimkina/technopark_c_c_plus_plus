//
// Created by Polina Yakimkina on 01.04.2022.
//

#include "search_max_sequence.h"
#define BUF_CUR_SIZE 10


void	read_file_to_buffer(FILE *file, char **buffer)
{
	char *buf_cur;
	size_t num_read_chars;
	size_t buffer_size = sizeof(char) ; // for '\0' in the end

	while (!feof(file))
	{
		buf_cur = realloc(*buffer, (buffer_size + BUF_CUR_SIZE) * sizeof(char));
		if (buf_cur == NULL)
		{
			//error
			//free
			*buffer = NULL;
			return;
		}

		*buffer = buf_cur;

		num_read_chars = fread(*buffer, sizeof(char), BUF_CUR_SIZE ,file);
		if (num_read_chars != BUF_CUR_SIZE && !feof(file))
		{
		 	 //error
			 //free
			 *buffer = NULL;
			 return;
		}

//		printf("%s\n", buf_cur);

		buffer_size += num_read_chars;
	}

	(*buffer)[buffer_size] = '\0';
}
