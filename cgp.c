//Program to semester cpgp on grade point of 5
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "struct_cgp.h"
#include "functions_cgp.h"

int main()
{
   int total_points = 0;
   int total_uints = 0;
   struct info *student1;
   struct info *courses = NULL;
   int number_of_courses = 0;
   student1 = (struct info *)malloc(1*sizeof(struct info));//Allocating memory for student info
   get_student_info (student1); //Calling function to get student info
   printf("Enter number of course(s) offered: ");
   scanf("%d", &number_of_courses);
   getchar();

   courses = (struct info *)malloc(number_of_courses * sizeof(struct info));
   if (courses == NULL)
   {
       perror("Memory not allocated\n");
       return(-1);
   }
   //Getting all result values calculated and stored into memory. Memory size depending on no of courses offered
   for (int i = 0; i<number_of_courses; ++i)
   {
       printf("course %d\n", i+1); //expression to number the course(e.g course 1, course 2 etc.)
       accept_score (courses + i);
       score_grade_level (courses + i);
       score_point (courses + i);
   }


    //Print student info to screen
    printf("\nSurname: %s First Name: %s Middle name: %s", student1->lname, student1->fname, student1->mname);
    printf("Matriculation Number: %d\n", student1->matric_no);
    printf("Session: %s", student1->session);
    printf("Semester: %s\n", student1->semester);

    for (int i=0; i<number_of_courses; ++i)
       {
        printf("course %d\n", i+1); //expression to number the course(e.g course 1, course 2 etc.)
        printf("code: %s", (courses +i)->course_code);
        printf("Tittle: %s", (courses + i)->course_tittle);
        printf("Unit: %d\n", (courses + i)->course_unit);
        printf("Score: %d\n", (courses + i)->score);
        printf("Grade: %c\n\n", (courses + i)->grade);
       
        //Eqns to calculate total semester units and points
        total_uints += (courses + i)->course_unit;
        total_points += (courses + i)->point;
       }
       printf("Semester Total Units = %d\n", total_uints);
       printf("Semester Total Points = %d\n", total_points);
       float cgp = 0.00;
       cgp = (float)total_points/total_uints;
       printf("Semester G.P.A. = %.2f\n", cgp);

    return 0;
}