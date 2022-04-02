//
// Created by Polina Yakimkina on 01.04.2022.
//

#include "search_max_sequence_multi_thread.h"
#define BUF_CUR_SIZE 10

pthread_mutex_t mutex;

void	*read_file_to_buffer_multi(void *args)
{
	char *buf_cur;
	size_t num_read_chars;
	size_t buffer_size = sizeof(char) ; // for '\0' in the end

	args_read_file *ar = (args_read_file *)args;
	
	while (!feof(ar->file))
	{
		buf_cur = realloc(*(ar->buffer), (buffer_size + BUF_CUR_SIZE) * sizeof(char));
		if (buf_cur == NULL)
		{
			print_free_and_null("[ERR0R] Can't reallocate memory during reading from file. Stopped.", (void **)(ar->buffer));
			return NULL;
		}

		*(ar->buffer) = buf_cur;

		pthread_mutex_lock(&mutex);
		num_read_chars = fread(*(ar->buffer), sizeof(char), BUF_CUR_SIZE ,ar->file);
		pthread_mutex_unlock(&mutex);
		if (num_read_chars != BUF_CUR_SIZE && !feof(ar->file))
		{
			print_free_and_null("[ERR0R] Can't read from file. Stopped.", (void **)(ar->buffer));
			return NULL;
		}

//		printf("%s\n", buf_cur);

		buffer_size += num_read_chars;
	}

	(*(ar->buffer))[buffer_size] = '\0';

	// close file
	if (fclose(ar->file))
	{
		print_error("[ERR0R] Can't close the stream.");
		free(*(ar->buffer));
		return NULL;
	}

	return NULL;
}


char	*read_from_file_multithread(const char *filename)
{
	// open file
	FILE	*file_src =  fopen(filename, "r");
	if (file_src == NULL)
	{
		print_error("[ERR0R] No input stream was passed.");
		return NULL;
	}

	char	*buf = NULL;

	pthread_t read_thread;
	args_read_file args = {.file = file_src, .buffer = &buf};
	pthread_attr_t tattr;
	pthread_attr_setdetachstate(&tattr, PTHREAD_CREATE_DETACHED);
	int errflag = pthread_create(&read_thread, &tattr, read_file_to_buffer_multi, (void*)&args);
	if (errflag != 0)
	{
		print_error("[ERR0R] Can't create thread during reading file.");
		return NULL;
	}

	return buf;
}
