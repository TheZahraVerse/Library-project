//Library management project
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//Functions
void menu(){}
//.............Main............
void main()
{
    menu();



}
//Main menu managemanet
void menu()
{
    do{
    puts("*******/Welcome to ZedBook Library/*******");
    puts("~You are in : main menu\n____________________");
    puts("|1. Admin Login");
    puts("|2. Staff Login");
    puts("|3. Member Login");
    puts("|4. Exit\n");
    printf("~Please Enter Your Choice :");
    int choice , isvalid;
    scanf("%d" , &choice );
    }while(isvalid == 1);
    if( (!isdigit(choice)) || (choice > 4 || choice < 1) ){
        if( !isdigit(choice) ){
            printf("Use numbers for your choice(between 1 - 4)");
            isvalid == 0;
        }
    }
    else{
        printf("yes");
        isvalid == 1;
    }
}
