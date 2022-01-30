#include<stdio.h>
#include<string.h>
#include "struct_cgp.h"

//Function to get student information
void get_student_info (struct info *student)
{
     printf("Enter student matric number: ");
     scanf("%d", &(student->matric_no));
     getchar();
    
    printf("Enter student first name: ");
    fgets(student->fname, 15, stdin);

    printf("Enter student middle name: ");
    fgets(student->mname, 15, stdin);

    printf("Enter student last name: ");
    fgets(student->lname, 15, stdin);

    printf("Enter session (e.g 2013/2014): ");
    fgets(student->session, 44, stdin);

    printf("Enter semester (Rain or Harmattan): ");
    fgets(student->semester, 10, stdin);
}

//Function to accept scores in course(s)
void accept_score(struct info *student)
{
    printf("Enter course code: ");
    fgets(student->course_code, 20, stdin);

    printf("Enter course tittle: ");
    fgets(student->course_tittle, 50, stdin);

    printf("Enter course unit: ");
    scanf("%d", &(student->course_unit));
    getchar();

    printf("Enter score: ");
    scanf("%d", &(student->score));
    getchar();

}

//Function to put scores into grades
char score_grade_level (struct info *student)
{
    if ((student->score)>69)
    student->grade = 'A';
    else if ((student->score)>59)
    student->grade  = 'B';
    else if ((student->score)>49)
    student->grade  = 'C';
    else if ((student->score)>44)
    student->grade  = 'D';
    else if ((student->score)>39)
    student->grade  = 'E';
    else
    student->grade  = 'F';

}

//Function to obtain grade points
int score_point (struct info *student)
{
    if ((student->score)>100)
    student->point = 0*(student->course_unit);
    if ((student->score)>69)
    student->point = 5*(student->course_unit);
    else if ((student->score)>59)
    student->point = 4*(student->course_unit);
    else if ((student->score)>49)
    student->point = 3*(student->course_unit);
    else if ((student->score)>44)
    student->point = 2*(student->course_unit);
    else if ((student->score)>39)
    student->point = 1*(student->course_unit);
    else
    student->point = 0*(student->course_unit);
}