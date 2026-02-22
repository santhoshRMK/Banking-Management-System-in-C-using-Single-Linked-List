#include "bank_structure.h"

void save_and_exit()
{

    struct accountdetails *temp;

    char ch;
    printf(YELLOW);
    printf("Do you really want to exit(y/n):");
    printf(RESET);

    scanf(" %c",&ch);

    if (ch == 'y' || ch == 'Y')
    {
        savetofile();
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        printf(GREEN);
        printf("-------------------------------  Thank you for using Bank Management System.  ------------------------------\n");
        printf("Exiting program...\n");
        printf(RESET);
        exit(0);
    }
    else
    {
        printf(RED);
        printf("Exit cancelled. Returning to main menu.\n");
        printf(RESET);
    }

}

