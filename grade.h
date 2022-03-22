
#pragma once
#include "student.h"

/**
 * @brief Definition of type struct grade. Represents a grade from a student.
 *
 */
typedef struct grade
{
    Student student;
    float result;
} Grade;

/**
 * @brief Creates a new Grade
 * 
 * @param number    The student's number.
 * @param name      The student's name.
 * @param result    The grade value.
 * 
 * @return The new created grade.
 */
Grade gradeCreate(int number, char *name, float result);

/*Function's prototypes*/

/**
 * @brief Print information about a specific grade.
 * 
 * The format is "Number: [number] | Name: [name] | grade: [result] | Status: [approved/reproved]".
 * 
 * @param g The grade to be printed.
 */
void gradePrint(Grade g);

/**
 * @brief Print all grades in grade's array.
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 */
void gradeArrayPrint(Grade *gradeArr, int size);

/**
 * @brief Get the number of approvals.
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 * @return int      Total of approvals.
 */
int gradeArrayApproved(Grade *gradeArr, int size);

/**
 * @brief Get the highest Grade in the grade's array.
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 * @return int      the index of highest result found, -1 case gradeArr is empty..
 */
int gradeArrayIndexOfHighest(Grade *gradeArr, int size);

/**
 * @brief Get the lowest Grade in the grade's array
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 * @return int      the index of lowest result found, -1 case gradeArr is empty..
 */
int gradeArrayIndexOfLowest(Grade *gradeArr, int size);

/**
 * @brief Verifies if the value exists in grade's array.
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 * @param value     The value to search.
 * 
 * @return true if the result exists, false otherwise.
 */
bool resultExists(Grade *gradeArr, int size, float value);

/**
 * @brief Show statistics about grade's array.
 * Show all grades, number of approved and the highest and lowest grade and respective Student.
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 */
void gradeArrayStats(Grade *gradeArr, int size);

/**
 * @brief   Sorts students in increasing numerical order by result of the array of grades.
 * Algorithm: Selection Sort.
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 */
void gradeArraySortByResult(Grade *gradeArr, int size);

/**
 * @brief   Sorts students in increasing numerical order by number of the array of grades.
 * Algorithm: Bubble Sort.
 * 
 * @param gradeArr  The grade's array.
 * @param size      The size of the array.
 */
void studentSortByNumber(Grade *gradeArr, int size);
