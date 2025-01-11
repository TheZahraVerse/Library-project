//Library management project
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
//define sizes
#define USERNAME 16
#define PASSWORD 20
//Functions
int menu();
void repeat();
void adminLogin();
void staffLogin();
void memberLogin();
void exitpro();
//.............Main............
void main()
{
    //Start the menu as first wall
    int select = menu();
    int entry = Login();
    //call the functions by checking the selection
    switch(select)
    {
    case 1 :
        if(entry==1){
            printf("welcome admin");
        }
        break;
    case 2 :
        staffLogin();
        break;
    case 3 :
        memberLogin();
        break;
    }




}
//Main menu managemanet
int menu()
{
    char choice;
    int isvalid =0;
    do{
        puts("*******/Welcome to ZedBook Library/*******");
        puts("~You are in : main menu\n____________________");
        puts("|1. Admin Login");
        puts("|2. Staff Login");
        puts("|3. Member Login");
        puts("|4. Exit\n");
        printf("Please enter your choice:");
        scanf(" %c" , &choice);
        switch (choice)
        {
          case '1' :
                  isvalid = 1;
                  break;
          case '2' :
                  isvalid = 2;

                  break;
          case '3' :
                  isvalid = 3;
                  break;
          case '4' :
                  isvalid = 4;
                  exitpro();
                  break;
          default :
              if(isvalid == 0){
                  repeat();
              }

            }

        }while( isvalid == 0);
    return isvalid ;

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
{   char x ;
    printf("~Your input is not valid\n");
    printf("Enter any key to start again:");
    getche(x);
    system("cls");
    menu();
}
void exitpro()
{
    int x ;
    printf("~Are you sure you want to exit?   | 1.Yes  / 2.No | : ");
    scanf(" %d" , &x);
    if( x == 1){
        printf("Exiting the program....");
        Sleep(3000);
        system("cls");
        exit(1);
    }
    else if(x == 2){
        printf("Returning to main menu....");
        Sleep(3000);
        system("cls");
        menu();
    }
}
//log in function
int Login()
{
    printf("Log in process... \n");
    char user[USERNAME];
    char pass[PASSWORD];
    printf("Username:");
    scanf(" %s" , user);
    //check the username character
    if(strcmp(user , "admin") == 0){
        printf("Password:");
        scanf(" %s" , pass);
        if(strcmp(pass , "adminishere4you") == 0){
            return 1 ;
        }
        else{
            printf("wrong password,try again!");
            //add limits for trying here
            return 0 ;
        }
    }
    else{
        //check in the files for username
        //check in the files for passwords
    return 2 ;
    return 3 ;
    }

}
