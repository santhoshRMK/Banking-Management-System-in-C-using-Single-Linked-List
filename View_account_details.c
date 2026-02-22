
#include "bank_structure.h"

void view_account_details()
{
    printf(BLUE);
    printf("------------------------------------  view account details  --------------------------------------------\n");
    printf(RESET);

    struct accountdetails *temp = head;

    if (head == NULL)
    {
        printf(RED);
        printf("No Records Found\n");
        printf(RESET);
        return;
    }

    while (temp != NULL)
    {
        printf(GREEN);
        printf("Account Number      : %lld\n",temp->account_no);
        printf("account holder name : %s\n",temp->account_holder_name);
        printf("account type        : %s\n",temp->account_type);
        printf("Balance             : %.2f\n",temp->balance);
        printf("address             : %s\n",temp->address);
        printf("contact number      : %s\n",temp->contact_number);
        printf("\n");

        temp = temp->next;
    }

    printf("----------------------------------------------------------------------------------------------------------\n");
    printf(RESET);
}
