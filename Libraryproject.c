//Library management project
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
//Functions
void menu();
//.............Main............
void main()
{
    menu();



}
//Main menu managemanet
void menu()
{
    char choice;
    int isvalid =0;
    while(isvalid == 0){
    puts("*******/Welcome to ZedBook Library/*******");
    puts("~You are in : main menu\n____________________");
    puts("|1. Admin Login");
    puts("|2. Staff Login");
    puts("|3. Member Login");
    puts("|4. Exit\n");
    if(isvalid == 0){
        printf("~Please Enter Your Choice :");
        scanf("%c" , &choice );
    }
    if(isalpha(choice)){
        printf("Your input is an alphabetical character , use numbers for your choice\n");
        printf("Please wait a second to start again.\n");
        Sleep(5000);
        system("cls");
        isvalid == 1;
    }
    else if(choice-'0' > 4 || choice-'0' < 1){
            printf("Your number is out of range or you entered an invalid character");
            continue;
    }
     else {
        printf("valid");
        isvalid = 1;
        break;
     }


    }
}
