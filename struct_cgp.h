#ifndef STRUCT_CGP
#define STRUCT_CGP
#include<string.h>
#include<stdio.h>
struct Student_info
{
    char fname[15];
    char mname [15];
    char lname [15];
     int matric_no;
    char session [44];
    char semester [10];
};


struct Course_info
{
    char course_code [20];
    char course_tittle [50];
    int course_unit;
    int score;
    char grade;
    int point;
};


#endif