
#include "bank_structure.h"

#include "new_account.c"
#include "update_acc_details.c"
#include "Delete_account.c"
#include "View_account_details.c"
#include "deposit_money.c"
#include "withdraw_money.c"
#include "support_fun.c"
#include "search_account.c"
#include "ext.c"



struct accountdetails *head=0;

int  main()
{
    //Title
    printf(BLUE);
    printf("*******************************************************************************************************************\n");
    printf("***************************** TITLE: BANK MANAGEMENT SYSTEM (BMS)  ************************************************\n");
    printf("*******************************************************************************************************************\n");
    printf(RESET);
    char op;
    int choice;

    loadfromfile();

    do
    {
        printf(GREEN);
        printf("\n*****************************  BANK MANAGEMENT SYSTEM (BMS) Menu  ********************************************\n");
        printf("*                                   1.Create New Account                                                       *\n");
        printf("*                                   2.Update Account Details                                                   *\n");
        printf("*                                   3.Delete Account                                                           *\n");
        printf("*                                   4.Search Account                                                           *\n");
        printf("*                                   5.Deposit Money                                                            *\n");
        printf("*                                   6.Withdraw Money                                                           *\n");
        printf("*                                   7.View Account Details                                                     *\n");
        printf("*                                   8.Save and Exit                                                            *\n");
        printf("****************************************************************************************************************\n");
        printf(RESET);

        printf(YELLOW);
        printf("enter your choice:");
        printf(RESET);

        scanf("%d",&choice);
        switch(choice)
        {

        case 1:
            create_new_account();
            break;

        case 2:
            update_account_details_menu();
            break;

        case 3:
            delete_account_menu();
            break;

        case 4:
            search_account_menu();
            break;

        case 5:
            deposit_money();
            break;

        case 6:
            withdraw_money();
            break;

        case 7:
            view_account_details();
            break;

        case 8:
            save_and_exit();
            break;

        default:
            printf(RED);
            printf("invalid operation , above modules only service provided in this bank.\n ");
            printf(RESET);
            break;

        }
        printf(YELLOW);
        printf("do you want preform one more function(y/n):");
        printf(RESET);
        scanf(" %c",&op);
    }
    while(op=='Y' || op=='y');
    printf(GREEN);
    printf("------------------------------ Service Ended -- Thank you!---------------------------------------------------\n");
    printf(RESET);
    return 0;
}
