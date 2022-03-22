/**
 * @file student.c
 * @author Joao Capinha
 */
#include <stdio.h>
#include <string.h>

#include "student.h"

/**
 * @brief Creates a new student.
 * 
 * @param number The student's number.
 * @param name   The student's name.
 * 
 * @return The new created student.
 */
Student studentCreate(int number, char* name){
    Student s;
    s.number = number;
    strcpy(s.name, name);
    return s;
}