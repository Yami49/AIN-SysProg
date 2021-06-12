/*
 * aufgabe1.c
 *
 * 15 Grundtypen und Zeigerdefinition
 * Von jedem Typ wird Wert, Adresse, Platzbedarf und Name ausgegeben
 * und das Datenmodell
 *
 * author: Georgios Gerontidis
 * version: 28.4.2021
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    // Integer
    int z0 = 123;
    printf("%p | %zu  | int                    | z0  | %d\n", (void*) &z0, sizeof z0, z0);
    short int z1 = 12;
    printf("%p | %zu  | short int              | z1  | %hd\n", (void*) &z1, sizeof z1, z1);
    long int z2 = 123L;
    printf("%p | %zu  | long int               | z2  | %ld\n", (void*) &z2, sizeof z2, z2);
    long long int z3 = 123LL;
    printf("%p | %zu  | long long int          | z3  | %lld\n", (void*) &z3, sizeof z3, z3);
    unsigned int z4 = 0xffffffffU;
    printf("%p | %zu  | unsigned int           | z4  | %u\n", (void*) &z4, sizeof z4, z4);
    unsigned short int z5 = 0xffffU;
    printf("%p | %zu  | unsigned short int     | z5  | %hu\n", (void*) &z5, sizeof z5, z5);
    unsigned long int z6 = 0xffffffUL;
    printf("%p | %zu  | unsigned long int      | z6  | %lu\n", (void*) &z6, sizeof z6, z6);
    unsigned long long int z7 = 0xffffffffULL;
    printf("%p | %zu  | unsigned long long int | z7  | %llu\n", (void*) &z7, sizeof z7, z7);

    // Float und Double
    float z8 = 3.14F;
    printf("%p | %zu  | float                  | z8  | %f\n", (void*) &z8, sizeof z8, z8);
    double z9 = 3.14;
    printf("%p | %zu  | double                 | z9  | %e\n", (void*) &z9, sizeof z9, z9);
    long double z10 = 3.14L;
    printf("%p | %zu | long double            | z10 | %Le\n", (void*) &z10, sizeof z10, z10);

    // char
    char z11 = 'g';
    printf("%p | %zu  | char                   | z11 | %c\n", (void*) &z11, sizeof z11, z11);
    signed char z12 = -49;
    printf("%p | %zu  | signed char            | z12 | %hhd\n", (void*) &z12, sizeof z12, z12);
    unsigned char z13 = 0x31;
    printf("%p | %zu  | unsigned char          | z13 | %hhu\n", (void*) &z13, sizeof z13, z13);
    const char* z14 = "Hallo";
    printf("%p | %zu  | char*                  | z14 | %s\n", (void*) &z14, sizeof z14, z14);

    // bool
    bool z15 = true;
    printf("%p | %zu  | boolean                | z15 | %i\n\n", (void*) &z15, sizeof z15, z15);

    // Datenmodell
    printf("sizeof(int) = %zu Byte\n", sizeof(int));
    printf("sizeof(long int) = %zu Byte\n", sizeof(long int));
    printf("sizeof(char*) = %zu Byte\n", sizeof(char*));
    printf("sizeof(long long int) = %zu Byte\n\n", sizeof(long long int));

    if ((sizeof(int) == 4) && (sizeof(long int) == 4) && (sizeof(char*) == 4))
    {
        printf("ILP32-Datenmodell\n");
    }
    else if ((sizeof(int) == 4) && (sizeof(long int) == 8) && (sizeof(char*) == 8))
    {
        printf("LP64-Datenmodell\n");
    }
    else if ((sizeof(int) == 4) && (sizeof(long int) == 4) && (sizeof(long long int) == 8) && (sizeof(char*) == 8))
    {
        printf("LLP64-Datenmodell\n");
    }
    else
    {
        printf("Keins der Modelle\n");
    }

    return 0;
}
