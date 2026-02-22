#include "bank_structure.h"

void search_account_menu()
{
    printf(BLUE);
    printf("----------------------------------  search account section menu  ----------------------------------------\n");
    printf(RESET);
    char op,choice;

    do
    {
        printf("**********  SEARCHING METHODS   **************\n");
        printf("*           A.By Account Number              *\n");
        printf("*           C.Back to Main Menu              *\n");
        printf("**********************************************\n");

        printf(YELLOW);
        printf("Enter your choice:");
        printf(RESET);
        scanf(" %c",&choice);
        switch(choice)
        {
        case 'A':
            printf(CYAN);
            printf("choice A so search based on account number\n");
            printf(RESET);
            search_using_accountnumber();
            break;
        case 'C':
            return;
        default:
            printf(RED);
            printf("invalid choice \n please enter the above character \n ");
            printf(RESET);
            break;
        }
        printf(YELLOW);
        printf("do you want to search one more time(y/n):");
        printf(RESET);
        scanf(" %c",&op);
    }
    while(op=='y' || op == 'Y');

}

void search_using_accountnumber()
{
    printf(BLUE);
    printf("--------------------------------  account number based search  --------------------------------------------\n");
    printf(RESET);
    long long int acc;
    struct accountdetails *temp = head;

    printf(YELLOW);
    printf("Enter Account Number: ");
    printf(RESET);
    scanf("%lld",&acc);

    while (temp != NULL)
    {
        if (temp->account_no == acc)
        {
            printf(GREEN);
            printf("\nAccount Found\n");
            printf("Account Number:%lld\n",temp->account_no);
            printf("account holder name: %s\n",temp->account_holder_name);
            printf("account type:%s",temp->account_type);
            printf("Balance: %.2f\n",temp->balance);
            printf("address:%s\n",temp->address);
            printf("contact number: %s\n",temp->contact_number);
            printf("---------------------------------------------------------------------------------------------------\n");
            printf(RESET);
            return;
        }
        temp = temp->next;
    }
    printf(RED);
    printf("Account Not Found\n");
    printf(RESET);
}
