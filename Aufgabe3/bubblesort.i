# 1 "bubblesort.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "bubblesort.c"
# 1 "bubblesort.h" 1



void bubblesort(char **, int ,int (*)(const char *, const char *));
# 2 "bubblesort.c" 2

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
