#include "bubblesort.h"

void bubblesort(char **array, int n, int (*cmp_func)(const char *, const char *))
{
    char **start = array;
    char **end = array + n - 1;
    char **current, **last_swapped;

    while(start < end)
    {
	last_swapped = start;

	for(current = start; current < end; ++current)
	{
	    char **next = current + 1;

	    if(cmp_func(*current, *next) > 0)
	    {
		char *tmp = *current;
		*current = *next;
		*next = tmp;

		last_swapped = next;
	    }
	}

	end = last_swapped;
    }
}
