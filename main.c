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
STUDENT database[512];

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
    int count = 0;
    char name[MAXLENGTH];
    int grade;
    bool isRunning = true;

    printf("* Start adding students to the database\n* Type in \"EXIT\" if you are finished\n");
    do
    {
        printf("* ---- Student %d ----\n", count+1);
        printf("./ADD/%d/NAME/", count+1);
        fflush(stdin);
        //gets(name);
        scanf("%s", name);

        if(strcmp(name, "EXIT") == 0)
        {
            printf("* [BREAK]\n");
            isRunning = false;
        }
        else
        {
            printf("./ADD/%d/GRADE/", count+1);
            fflush(stdin);
            scanf("%d", &grade);

            database[count].id_number = count + 1;
            strncpy(database[count].name, name, MAXLENGTH);
            database[count].grade = grade;

            printf("[OK] Added student %s\n", name);
        }
        ++count;
    }
    while (isRunning);

    fwrite(database, sizeof (STUDENT), count - 1, file);
    fclose(file);
}

void info()
{
    file = fopen("../config/config.nscf", "rb+");
    int input = 0;
    char cache;
    STUDENT student[1];

    printf("* Please type in the catalog number of the student you are searching for\n");
    printf("./INFO/");
    scanf("%d", &input);

    fseek(file, input, 0);
    fread(student, sizeof (STUDENT), 1, file);

    printf("* Found student: \n");
    printf("* - Catalog Number: %d\n", student[0].id_number);
    printf("* - Name: %s\n", student[0].name);
    printf("* - Grade: %d\n", student[0].grade);
    printf("* Type in any key to continue...\n");
    scanf("%c", &cache);

    fclose(file);
}

void avg()
{

}
