#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

//********************************************************************
//
// Program        : Übung 25 - Schuelerverwaltung
//
// Author         : Niklas Schachl
//
// Date           : 27.5.2021
//
// Description    : Program to manage students
//
//********************************************************************

//define struct
typedef struct
{
    int id_number;
    char name[32];
    int grade;
}
student;

//declare variables
FILE *file;

//declare functions
void create();
void info();
void avg();

int main()
{
    //declare variables
    char *input = malloc(255);
    bool isError = false;

    do
    {
        printf("\n***************************************\n");
        printf("*  Welcome to NSC Student Management  *\n");
        printf("***************************************\n");
        printf("* Please choose one of the options below with the command in brackets\n");
        printf("* Create new student database [CREATE]\n");
        printf("* Get Information about a student [INFO]\n");
        printf("* Calculate the average grade of all students [AVG]\n");
        printf("./MENU/");
        gets(input);

        if (strcmp(input, "CREATE") == 0)
            create();
        else if (strcmp(input, "INFO") == 0)
            info();
        else if (strcmp(input, "AVG") == 0) //strcasecmp für case-insensitive comparison nur in UNIX-Systemen verfügbar
            avg();
        else
        {
            printf("* [ERROR] Wrong input\n");
            isError = true;
        }
    }
    while (isError);


    return 0;
}

void create()
{
    file = fopen("../config/config.nscf", "w");
}

void info()
{

}

void avg()
{

}
