/**
 * stringsort.h
 *
 * Aufgabe3 Stringsort.java in C portieren
 *
 * Georgios Gerontidis
 * 25.5.2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stddef.h>
#include "bubblesort.h"

int main (int argc, char *argv[])
{
    //---------- Arraygröße einlesen
    if (argc != 2 || !atoi(argv[1])) {
	fprintf(stderr, "Aufruf: ./stringsort Anzahl\n");
	return 1;
    }

    const int n = atoi(argv[1]);
    const int m = 2;

    if (n < 1) {
	fprintf(stderr, "Anzahl muss mindestens eins sein!\n");
	return 1;
    }


    //-------- Array von String-Zeigern mit malloc
    char **array = (char**) malloc(n * sizeof (char*));
    if (array == NULL)
    {
	fprintf(stderr, "Speicheralokierungsfehler\n");
	return 1;
    }

    srand((unsigned int) time(NULL));

    for (int i = 0; i < n; i++)
    {
	array[i] = (char*) malloc(m  * sizeof(char));
	if (array[i] == NULL)
	{
	    fprintf(stderr, "Speicheralokierungsfehler\n");
	    for (int j = 0; j < i; j++)
	    {
		free(array[i]);
	    }
	    free(array);
	    return 1;
	}
	sprintf(array[i], "%d", rand() % 10);
    }

    printf("Unsortiertes Array:\n");
    for (int i = 0; i < n; i++)
    {
	printf("%s ", array[i]);
    }
    printf("\n");

    char *sortedArray = (char*) malloc(m * sizeof (char));
    if (sortedArray == NULL)
    {
	fprintf(stderr, "Speciheralokierungsfehler\n");
	return 1;
    }

    bubblesort(array, n, strcmp);

    for (int i = 0, len = 0; i < n; ++i)
    {
	if (i > 0 && strcmp(array[i - 1], array[i]) == 0)
	{
	    len += sprintf(sortedArray + len, "*");
	} else {
	    if (i > 0)
	    {
		len += sprintf(sortedArray + len, ", ");
	    }

	    len += sprintf(sortedArray + len, "%s", array[i]);
	}
    }

    printf("\n");
    printf("Soritertes Array: \n%s\n", sortedArray);

    //-------- Speicher freigeben
    free(sortedArray);
    for (int i = 0; i < n; i++)
    {
	free(array[i]);
    }
    free(array);

    return 0;
}

