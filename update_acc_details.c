
#include "bank_structure.h"

void update_account_details_menu()
{
    printf(BLUE);
    printf("------------------------------------  update account details menu ---------------------------------------------------\n");
    printf(RESET);
    char op,choice;

    do
    {
        printf(GREEN);
        printf("*******************************************\n");
        printf("*           A.By Account Number           *\n");
        printf("*           C.Back to Main Menu           *\n");
        printf("*******************************************\n");
        printf(RESET);

        printf(YELLOW);
        printf("Enter your choice:");
        printf(RESET);

        scanf(" %c",&choice);
        switch(choice)
        {
        case 'A':
            printf(CYAN);
            printf("choice A So update details using By Account Number\n");
            printf(RESET);
            update_using_accountnumber();
            break;
        case 'C':
            return;
        default:
            printf(RED);
            printf("invalid \n please enter the above character \n ");
            printf(RESET);
            break;
        }
        printf(YELLOW);
        printf("do you want to update one more time(y/n):");
        printf(RESET);
        scanf(" %c",&op);
    }
    while(op=='y' || op == 'Y');

}

void update_using_accountnumber()
{
    printf(BLUE);
    printf("-------------------------------  update Using AccountNumber  -----------------------------------------------\n");
    printf(RESET);

    long long int accountnumber;
    struct accountdetails *temp=head;

    printf(YELLOW);
    printf("enter the account number:");
    printf(RESET);
    scanf("%lld",&accountnumber);

    while(temp!=0)
    {
        if (accountnumber == temp->account_no)
        {

            printf("        Old account details          \n");

            printf(RED);
            printf("Old account no          :%lld\n",temp->account_no);

            printf("Old account holder name :%s\n",temp->account_holder_name);

            printf("Old account type        :%s\n",temp->account_type);

            printf("old Balance             :%f\n",temp->balance);

            printf("Old address             :%s\n",temp->address);

            printf("Old contact number      :%s\n",temp->contact_number);

            printf(RESET);
            printf("\n");

            //new data upadation

            printf("        enter the new account details       \n");
            printf(GREEN);
            printf("New Account no          :");
            scanf("%lld",&temp->account_no);

            printf("New Account holder name :");
            scanf("%s",temp->account_holder_name);

            printf("New Account type        :");
            scanf("%s",temp->account_type);

            printf("Balance                 :");
            scanf(" %f",&temp->balance);

            printf("New Address             :");
            scanf("%s",temp->address);

            printf("New contact number      :");
            scanf("%s",temp->contact_number);

            printf(RESET);
            savetofile(); //autosave

            printf(RED);
            printf("-----------------------------------   Account Update successfully   -----------------------------------------\n");
            printf(RESET);
            return;
        }
        temp=temp->next;

    }
    printf(RED);
    printf("account not found\n");
    printf(RESET);
}
