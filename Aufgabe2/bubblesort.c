/**
 * bubblesort.c
 *
 * Aufgabe2 bubblesort.java in C portieren
 *
 * Georgios Gerontidis
 * 18.4.21
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand((unsigned int) time(NULL));

    //---- Arraygroesse einlesen
    if (argc != 2 || !atoi(argv[1]))
    {
        fprintf(stderr, "Aufruf: ./bubblesort Anzahl\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int *a = (int*) malloc(sizeof (int) * n);
    if (a == NULL)
    {
        fprintf(stderr, "Speicherreservierung fehlgeschlagen!\n");
        return 1;
    }

    printf("%d ganze Zahlen eingeben:\n\n", n);

    //---- Zahlen einlesen
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            a[i] = rand();
            printf("%d\n", a[i]);
        }
    }
    printf("\n");

    //---- Zahlen sortieren
    for (int i = n; i > 1; i--)
    {
        for (int j = 0; j < i - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }

    //---- Zahlen ausgeben
    printf("Sortierte Zahlenfolge: \n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    free(a);
    return 0;
}
