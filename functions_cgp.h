#ifndef FUNCTIONS_CGP
#define FUNCTIONS_CGP
#include<stdio.h>
#include<string.h>
#include "struct_cgp.h"

void get_student_info (struct Student_info *student);


//Function to accept scores in course(s)
void accept_score(struct Course_info *student);

//Function to put scores into grades
char score_grade_level (struct Course_info *student);


//Function to obtain grade points
int score_point (struct Course_info *student);

#endif