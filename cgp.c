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

   struct Student_info *student1;
   struct Course_info *courses;
   int number_of_courses = 0;

   student1 = (struct Student_info *) malloc (1*sizeof(struct Student_info));             //Allocating memory for student info
   if (student1 == NULL)
   {
       printf ("Memory allocation failed\n");
       return (-1);
   }

   get_student_info (student1);                                                         //Calling function to accept student info from keyboard
  
   printf ("Enter number of course(s) offered: ");
   scanf ("%d", &number_of_courses);
   getchar ();

   courses = (struct Course_info *) malloc (number_of_courses * sizeof(struct Course_info));

   if (courses == NULL)
   {
       perror ("Memory not allocated\n");
       return (-2);
   }

   //Getting all result values calculated and stored into memory. Memory size depending on number of courses offered
   
   for (int i = 0; i<number_of_courses; ++i)
   {
       printf ("course %d\n", i+1);              //expression to number the course(e.g course 1, course 2 etc.)
       
       accept_score (courses + i);
       score_grade_level (courses + i);
       score_point (courses + i);
   }


    //Print student info to screen

    printf ("\nSurname: %s First Name: %s Middle name: %s", student1->lname, student1->fname, student1->mname);
    printf ("Matriculation Number: %d\n", student1->matric_no);
    printf ("Session: %s", student1->session);
    printf ("Semester: %s\n", student1->semester);


    for (int i=0; i<number_of_courses; ++i)
       {
        printf ("course %d\n", i+1);                       //expression to number the course(e.g course 1, course 2 etc.)
        printf ("code: %s", (courses +i)->course_code);
        printf ("Tittle: %s", (courses + i)->course_tittle);
        printf ("Unit: %d\n", (courses + i)->course_unit);
        printf ("Score: %d\n", (courses + i)->score);
        printf ("Grade: %c\n\n", (courses + i)->grade);
       
        //Eqns to calculate total semester units and points

        total_uints += (courses + i)->course_unit;
        total_points += (courses + i)->point;

       }

       printf ("Semester Total Units = %d\n", total_uints);
       printf ("Semester Total Points = %d\n", total_points);

       float cgp = 0.00;
       cgp = (float)total_points/total_uints;
       printf ("Semester G.P.A. = %.2f\n", cgp);


       free (student1);
       free (courses);

    return 0;
}