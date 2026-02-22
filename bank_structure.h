#ifndef BANK_STRUCTURE_H
#define BANK_STRUCTURE_H

//header
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// COLOR

#define RESET   "\033[0m"

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"

//structure
struct accountdetails
{
    long long int  account_no;
    char account_holder_name[20];
    char account_type[20];
    float balance;
    char address[50];
    char contact_number[11];
    struct accountdetails *next;
};


//global head pointer
extern struct accountdetails *head;


/* File Handling Functions */
void savetofile();
void loadfromfile();

//function declaration

void create_new_account();

void update_account_details_menu();
void update_using_accountnumber();

void delete_using_accountnumber();
void delete_account_menu();

void search_using_accountnumber();
void search_account_menu();

//Transaction function
void deposit_money();
void withdraw_money();

void view_account_details();
void save_and_exit();



#endif
