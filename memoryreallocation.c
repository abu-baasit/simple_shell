#include "shell.c"
/**
 * *memory_reallocation - function that reallocates a memory
 * @ptr: pointer to the memory previously allocated bt malloc
 * @old_val: size of the allocated memory
 * @new_val: size of the new memory
 * Return: returns pointer to the newly allocated memory,
 */

void *memory_reallocation(void *ptr, unsigned int old_val, unsigned int new_val)
{
	char *ptr1;
	char *ptr2;
	unsigned int k;

	if (new_val == old_val)
		return (ptr);
	if (new_val == 0 && ptr)
	{
		free(ptr);
		return (NULL);

	}

	if (!ptr)
		return (malloc(new_val));

	ptr1 = malloc(new_val);
	if (!ptr)
		return (NULL);
	ptr2 = ptr;

	if (new_val < old_val)
	{
		for (k = 0; k < new_val; k++)
			ptk1[k] = ptr2[k];
	}
	if (new_val > old)
	{
		for (k = 0; k < old_val; k++)
			ptr1[k] = ptr2[k];
	}
	free(ptr);
	return (ptr1);
}
