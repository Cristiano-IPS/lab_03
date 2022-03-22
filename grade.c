/**
 * @file grade.c
 * @author Joao Capinha
 */
#include <stdio.h>
#include <string.h>

#include "grade.h"

/**
 * @brief Creates a new Grade
 * 
 * @param number    The student's number.
 * @param name      The student's name.
 * @param result    The grade value.
 * 
 * @return The new created grade.
 */
Grade gradeCreate(int number, char *name, float result)
{
    Grade grade;
    grade.student = studentCreate(number, name);
    grade.result = result;
    return grade;
}

/*Function's prototypes*/

/**
 * @brief Print information about a specific grade.
 * 
 * The format is "Number: [number] | Name: [name] | grade: [result] | Status: [approved/reproved]".
 * 
 * @param g The grade to be printed.
 */
void gradePrint(Grade g)
{
    printf("Number: %9d | Name: %-20s | grade: %05.2f | Status: %s\n", g.student.number, g.student.name, g.result, (g.result >= 9.5) ? "approved" : "reproved");
}

/**
 * @brief Print all grades in grade's array.
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 */
void gradeArrayPrint(Grade *gradeArr, int size)
{
    printf("\nAll class notes:\n");
    for (int i = 0; i < size; i++)
    {
        printf("\t");
        gradePrint(gradeArr[i]);
    }
}

/**
 * @brief Get the number of approvals.
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 * @return int      Total of approvals.
 */
int gradeArrayApproved(Grade *gradeArr, int size)
{
    int totalApproved = 0;
    for (int i = 0; i < size; i++)
    {
        if (gradeArr[i].result >= 9.5)
        {
            totalApproved++;
        }
    }
    return totalApproved;
}

/**
 * @brief Verifies if the value exists in grade's array.
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 * @param value     The value to search.
 * 
 * @return true if the result exists, false otherwise.
 */
bool resultExists(Grade *gradeArr, int size, float value)
{
    for (int i = 0; i < size; i++)
    {
        if (gradeArr[i].result == value)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Get the highest Grade in the grade's array.
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 * @return int      the index of highest result found, -1 case gradeArr is empty..
 */
int gradeArrayIndexOfHighest(Grade *gradeArr, int size)
{
    if (size == 0)
        return -1;
    int indexMax = 0; // assumes that the maximum value is at index 0

    for (int i = 0; i < size; i++)
    {
        if (gradeArr[i].result > gradeArr[indexMax].result)
            indexMax = i;
    }
    return indexMax;
}

/**
 * @brief Get the lowest Grade in the grade's array
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 * @return int      the index of lowest result found, -1 case gradeArr is empty..
 */
int gradeArrayIndexOfLowest(Grade *gradeArr, int size)
{
    if (size == 0)
        return -1;
    int indexMin = 0; // assumes that the minimum value is at index 0

    for (int i = 0; i < size; i++)
    {
        if (gradeArr[i].result < gradeArr[indexMin].result)
            indexMin = i;
    }
    return indexMin;
}

/**
 * @brief Show statistics about grade's array.
 * Show all grades, number of approved and the highest and lowest grade and respective Student.
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 */
void gradeArrayStats(Grade *gradeArr, int size)
{
    gradeArrayPrint(gradeArr, size);

    printf("\nTotal of approved: %d in %d\n", gradeArrayApproved(gradeArr, size), size);

    Grade bestGrade = gradeArr[gradeArrayIndexOfHighest(gradeArr, size)];
    printf("\nThe best great is %.2f values from %s\n", bestGrade.result, bestGrade.student.name);

    Grade worstGrade = gradeArr[gradeArrayIndexOfLowest(gradeArr, size)];
    printf("\nThe worst great is %.2f values from %s\n", worstGrade.result, worstGrade.student.name);
}

/**
 * @brief   Sorts students in increasing numerical order by result of the array of grades.
 * Algorithm: Selection Sort.
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 */
void gradeArraySortByResult(Grade *gradeArr, int size)
{
    int indexMin;
    for (int i = 0; i < size; i++)
    {
        indexMin = i;
        for (int j = i + 1; j < size - 1; j++)
        {
            if (gradeArr[indexMin].result > gradeArr[j].result)
            {
                indexMin = j;
            }
        }
        Grade aux = gradeArr[i];
        gradeArr[i] = gradeArr[indexMin];
        gradeArr[indexMin] = aux;
    }
}

/**
 * @brief   Sorts students in increasing numerical order by number of the array of grades.
 * Algorithm: Bubble Sort.
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 */
void studentSortByNumber(Grade *gradeArr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (gradeArr[j].student.number > gradeArr[j + 1].student.number)
            {
                Grade aux = gradeArr[j];
                gradeArr[j] = gradeArr[j + 1];
                gradeArr[j + 1] = aux;
            }
        }
    }
}