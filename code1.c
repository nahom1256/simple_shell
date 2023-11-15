#include "nashell.h"

void *_narealloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _nagetline(char **nalineptr, size_t *f, FILE *nahomstream);

/**
 * _narealloc - Reallocates.
 * @ptr: pointer
 * @old_size: The size in bytes
 * @new_size: The size in bytes
 *
 * Return: If new_size == old_size - ptr.
 *         If new_size == 0 and ptr is not NULL - NULL.
 *         Otherwise - a pointer
 */
void *_narealloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *namem;
	char *naptr_copy, *nafiller;
	unsigned int naindex;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		namem = malloc(new_size);
		if (namem == NULL)
			return (NULL);

		return (namem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	naptr_copy = ptr;
	namem = malloc(sizeof(*naptr_copy) * new_size);
	if (namem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	nafiller = mem;

	for (naindex = 0; naindex < old_size && naindex < new_size; naindex++)
		nafiller[naindex] = *naptr_copy++;

	free(ptr);
	return (namem);
}

/**
 * assign_lineptr - Reassigns
 * @lineptr: A buffer
 * @n: size
 * @buffer: string
 * @b: size.
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _nagetline - input
 * @nalineptr: buffer
 * @f: size
 * @nahomstream: stream
 *
 * Return: The number of bytes read.
 */
ssize_t _nagetline(char **nalineptr, size_t *f, FILE *nahomstream)
{
	static ssize_t nainput;
	ssize_t retna;
	char v = 'z', *buffer;
	int e;

	if (nainput == 0)
		fflush(stream);
	else
		return (-1);
	nainput = 0;

	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (v != '\n')
	{
		e = read(STDIN_FILENO, &v, 1);
		if (e == -1 || (e == 0 && nainput == 0))
		{
			free(buffer);
			return (-1);
		}
		if (e == 0 && nainput != 0)
		{
			nainput++;
			break;
		}

		if (nainput >= 120)
			buffer = _realloc(buffer, nainput, nainput + 1);

		buffer[nainput] = c;
		nainput++;
	}
	buffer[nainput] = '\0';

	assign_lineptr(lineptr, n, buffer, input);

	retna = nainput;
	if (e != 0)
		nainput = 0;
	return (retna);
}
