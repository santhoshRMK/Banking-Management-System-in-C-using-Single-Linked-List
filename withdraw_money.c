
#include "bank_structure.h"

void withdraw_money()
{
    printf(BLUE);
    printf("------------------------------------- withdraw money --------------------------------------------------\n");
    printf(RESET);
    long long int acc;
    float amount;
    struct accountdetails *temp = head;

    printf(YELLOW);
    printf("Enter Account No: ");
    printf(RESET);
    scanf("%lld",&acc);

    while (temp != NULL)
    {
        if (temp->account_no == acc)
        {
            printf(YELLOW);
            printf("Enter Amount: ");
            printf(RESET);
            scanf("%f", &amount);
            if (temp->balance >= amount)
            {
                printf(GREEN);
                temp->balance -= amount;
                printf("-------------------------------------  Amount Withdrawn  ------------------------------------\n");
                printf("Updated Account Details:\n");
                printf("Account No      : %lld\n",temp->account_no);
                printf("Name            : %s\n",temp->account_holder_name);
                printf("Type            : %s\n",temp->account_type);
                printf("Balance         : %f\n",temp->balance);
                printf("Address         : %s\n",temp->address);
                printf("contact number  : %s\n",temp->contact_number);
                printf(RESET);
                savetofile();
            }
            else
            {
                printf(RED);
                printf("Insufficient Balance!\n");
                printf(RESET);
            }
            return;
        }
        temp = temp->next;
    }
    printf(RED);
    printf("Account Not Found\n");
    printf(RESET);
}

