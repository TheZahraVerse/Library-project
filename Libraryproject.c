//Library management project
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
//Functions
void menu();
void repeat();
void adminLogin();
void staffLogin();
void memberLogin();
void exitpro();
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

    puts("*******/Welcome to ZedBook Library/*******");
    puts("~You are in : main menu\n____________________");
    puts("|1. Admin Login");
    puts("|2. Staff Login");
    puts("|3. Member Login");
    puts("|4. Exit\n");
    printf("Please enter your choice:");
    scanf("%c" , &choice);

      switch (choice)
      {
        case '1' :
                isvalid = 1;
                adminLogin();
                break;
        case '2' :
                isvalid = 1;
                staffLogin();
                break;
        case '3' :
                isvalid = 1;
                memberLogin();
                break;
        case '4' :
                isvalid = 1;
                exitpro();
                break;
        default :
            if(isvalid == 0){
                repeat();
                break;
            }
      }
}
//AdminLogin
void adminLogin()
{
    printf("~You are in Admin Login");
}
//StaffLogin
void staffLogin()
{
    printf("~You are in Staff Login");
}
//MemberLogin
void memberLogin()
{
    printf("~You are in Member Login");
}
//Repeat the menu
void repeat()
{
    printf("~Your input is not valid");

}
void exitpro()
{
    printf("~Are you sure?\nPress enter to close the program:");
    exit(1);
//add two choice here
}
