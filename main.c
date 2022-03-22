/**
 * @file main.c
 * @author João Capinha
 */
#include <stdio.h>
#include <stdlib.h>
#include "grade.h"
#include <stdbool.h>


#define ELEMENTS 10

int main()
{
    // Level 1 - modulos
    // Criação do modulo Student e Grade.

    // Level 2
    printf("\n--> Level 2");
    Grade gradeArr[ELEMENTS] = {gradeCreate(145678478, "Hugo Vieira", 10.4),
                                gradeCreate(193498649, "Maria Carvalho", 16.35),
                                gradeCreate(190530864, "Joaquim Dinis", 9.5),
                                gradeCreate(156978458, "Henrique Ferreira", 17.4),
                                gradeCreate(146978478, "Margarida Mourato", 6.45),
                                gradeCreate(185678478, "Diogo Carreira", 12.8),
                                gradeCreate(175678458, "Ana Marques", 14.6),
                                gradeCreate(135674468, "Manuel Quintino", 7.2),
                                gradeCreate(145678479, "Joana Firmino", 16.4),
                                gradeCreate(165678478, "Lara Pires", 19.3)};

    gradeArrayPrint(gradeArr, ELEMENTS);

    // Level 3
    printf("\n--> Level 3");
    printf("\nTotal of approved: %d in %d\n", gradeArrayApproved(gradeArr, ELEMENTS), ELEMENTS);

    float valueSearch = 9.5;
    bool resultSearch = resultExists(gradeArr, ELEMENTS, valueSearch);
    printf("\nSomeone got %05.2f values? %s\n", valueSearch, (resultSearch == true) ? "Yes" : "No");

    // Level 4 - seleção
    printf("\n--> Level 4");
    gradeArrayStats(gradeArr, ELEMENTS);

    // Level 5 - Ordenação
    printf("\n--> Level 5");
    // Selection Sort
    gradeArraySortByResult(gradeArr, ELEMENTS);
    printf("\nSort all grades by results:");
    gradeArrayPrint(gradeArr, ELEMENTS);

    // Bubble Sort
    studentSortByNumber(gradeArr, ELEMENTS);
    printf("\nSort all grades by student number:");
    gradeArrayPrint(gradeArr, ELEMENTS);

    return EXIT_SUCCESS;
}