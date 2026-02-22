
#include "bank_structure.h"

void create_new_account()
{

    struct accountdetails *temp,*newnode;
    char op;

    do
    {
        printf(BLUE);
        printf("-----------------------------------  Account Creation ------------------------------------------\n");
        printf(RESET);
        newnode=(struct accountdetails*)malloc(sizeof(struct accountdetails));
        if(newnode==0)
        {
            printf(RED);
            printf("memory allocation failed\n");
            printf(RESET);
            return;
        }

        printf(WHITE);
        printf("  enter the account details  \n");

        printf("account no:");
        scanf("%lld",&newnode->account_no);

        printf("account holder name:");
        scanf(" %s",newnode->account_holder_name);

        printf("account type:");
        scanf(" %s",newnode->account_type);

        printf("Balance:");
        scanf("%f",&newnode->balance);

        printf("address:");
        scanf(" %[^\n]",newnode->address);

        printf("contact number:");
        scanf(" %10s",newnode->contact_number);
        printf(RESET);

        newnode->next=0;

        if(head == 0)
        {
            head=newnode;
            temp=newnode;

        }
        else
        {
            temp=head;
            while(temp->next !=0)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            temp=newnode;

        }

        savetofile(); // auto save

        printf(GREEN);
        printf("-----------------------------  account created successfully -----------------------------------\n");
        printf(RESET);

        printf(YELLOW);
        printf("do you want create one more bank account(y/n) but the account number should be unique:");
        printf(RESET);
        scanf(" %c",&op);
    }
    while(op =='y' ||op =='Y');

}
