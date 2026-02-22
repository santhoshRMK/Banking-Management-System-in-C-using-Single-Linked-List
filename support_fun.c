
#include "bank_structure.h"

void savetofile()
{
    printf(BLUE);
    printf("-------------------------  details save to file(bank.data)  --------------------------------------------\n");
    printf(RESET);
    FILE *fp = fopen("bank.data", "wb");
    struct accountdetails *temp = head;

    while (temp != NULL)
    {
        fwrite(temp, sizeof(struct accountdetails), 1, fp);
        temp = temp->next;
    }
    fclose(fp);
    printf(GREEN);
    printf("-------------------------------------  Data Saved Successfully  ------------------------------------------\n");
    printf(RESET);
}

void loadfromfile()
{
    FILE *fp = fopen("bank.data", "rb");
    struct accountdetails *newnode, *temp;

    if (fp == NULL) return;

    while (1)
    {
        newnode = (struct accountdetails *)malloc(sizeof(struct accountdetails));
        if (fread(newnode, sizeof(struct accountdetails), 1, fp) != 1)
        {
            free(newnode);
            break;
        }
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    fclose(fp);
}
