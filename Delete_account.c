
#include "bank_structure.h"

void delete_account_menu()
{
    printf(BLUE);
    printf("--------------------------  delete account section menu  ----------------------------------\n");
    printf(RESET);
    char op,choice;

    do
    {
        printf(GREEN);
        printf("************* Deletion method ************************\n");
        printf("*           A.By Account Number                      *\n");
        printf("*           C.Back to Main Menu                      *\n");
        printf("******************************************************\n");

        printf(RESET);
        printf("Enter your choice:");
        scanf(" %c",&choice);
        switch(choice)
        {
        case 'A':
            printf(CYAN);
            printf("Choice A so delete using Account Number\n");
            printf(RESET);
            delete_using_accountnumber();
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

void delete_using_accountnumber()
{

    printf(BLUE);
    printf("-------------------------------  Delete Using Account Number  -----------------------------------------------\n");
    printf(RESET);

    long long int accountnumber;
    struct accountdetails *temp=head,*prev=0;

    printf(YELLOW);
    printf("enter the account number:");
    printf(RESET);
    scanf("%lld",&accountnumber);

    while(temp !=0)
    {
        if (accountnumber == temp->account_no)
        {
            printf(GREEN);
            printf("account details \n");

            printf("account no          :%lld\n",temp->account_no);
            printf("account holder name :%s\n",temp->account_holder_name);
            printf("account type        :%s\n",temp->account_type);
            printf("Balance             :%f\n",temp->balance);
            printf("address             :%s\n",temp->address);
            printf("contact number      :%s\n",temp->contact_number);
            printf(RESET);
            if(prev ==0)
                head=temp->next;
            else
                prev->next=temp->next;

            free(temp);
            savetofile();
            printf(GREEN);
            printf("------------------------------  Account deleted successfully  --------------------------------------\n");
            printf(RESET);
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    printf(RED);
    printf("Account not found !\n");
    printf(RESET);
}
