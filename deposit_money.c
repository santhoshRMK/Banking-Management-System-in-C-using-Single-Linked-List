#include "bank_structure.h"

void deposit_money()
{
    printf(BLUE);
    printf("-------------------------------------- welcome to deposit -----------------------------------------------\n");
    printf(RESET);
    long long int acc_no;
    float amount;
    struct accountdetails *temp = head;

    printf(YELLOW);
    printf("Enter Account Number: ");
    printf(RESET);
    scanf("%lld", &acc_no);
    while (temp != NULL)
    {
        if (temp->account_no == acc_no)
        {
            printf(YELLOW);
            printf("Enter Amount: ");
            printf(RESET);

            scanf("%f", &amount);
            temp->balance += amount;
            printf(GREEN);
            printf("-----------------------------------  Amount Deposited  ---------------------------------------\n");
            printf("Updated Account Details:\n");
            printf("Account No      : %lld\n",temp->account_no);
            printf("Name            : %s\n",temp->account_holder_name);
            printf("Type            : %s\n",temp->account_type);
            printf("Balance         : %f\n",temp->balance);
            printf("Address         : %s\n",temp->address);
            printf("contact number  : %s\n",temp->contact_number);
            printf(RESET);
            savetofile();
            return;
        }
        temp = temp->next;
    }
    printf(RED);
    printf("Account Not Found\n");
    printf(RESET);
}
