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

//define constants
#define MAXLENGTH 50

//define struct
typedef struct
{
    int id_number;
    char name[32];
    int grade;
}
STUDENT;

//declare variables
FILE *file;
STUDENT *database;

//declare functions
void create();
void info();
void avg();

int main()
{
    //declare variables
    char *input = malloc(MAXLENGTH);
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

    file = fopen("../config/config.nscf", "wb+");
    int count = 1;
    char* name = malloc(MAXLENGTH);
    char *lastName = malloc(MAXLENGTH);
    int grade;
    bool isRunning = true;

    printf("* Start adding students to the database\n* Type in \"END\" if you are finished\n");
    do
    {
        fflush(stdin);
        printf("* ---- Student %d ----\n", count);
        printf("./ADD/%d/LAST-NAME/", count);
        gets(lastName);

        if(strcmp(lastName, "END") == 0)
        {
            printf("* [BREAK]\n");
            isRunning = false;
        }

        printf("./ADD/%d/FIRST-NAME/", count);
        gets(name);

        printf("./ADD/%d/GRADE/", count);
        scanf("%d", &grade);

        strcat(lastName, " ");
        strcat(lastName, name);

        /*
        database[count - 1].id_number = count;
        strncpy(database[count - 1].name, lastName, 2*MAXLENGTH);
        database[count - 1].grade = grade;
         */
        printf("[OK] Added student %s\n", lastName);
        ++count;
    }
    while (isRunning);

    //fwrite(database, sizeof (STUDENT), count - 1, file);
    fclose(file);
}

void info()
{

}

void avg()
{

}
