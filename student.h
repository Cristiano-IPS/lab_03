/**
 * @file student.h
 * @author Joao Capinha
 */

#pragma once
#include <stdbool.h>

/**
 * @brief Definition of type struct student. Represents a student with name and number.
 *
 */
typedef struct student {
    int number;
    char name[51];
} Student;

/*Function's prototypes*/

/**
 * @brief Creates a new student.
 * 
 * @param number The student's number.
 * @param name   The student's name.
 * 
 * @return The new created student.
 */
Student studentCreate(int number, char* name);