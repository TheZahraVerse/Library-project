//Library management project---> *PEANUTZEE LIBRARY*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
//define sizes
#define USERNAME 16
#define PASSWORD 20
//..........................................Functions
//General Functions
int menu();
int Login();
void repeat();
void exitpro();
//Admin Functions
int adminMenu();
void newEmp();
void staffList();
void rmEmp();
void report_ad();
//staff Functions
int staffMenu();
void newMem();
void revival();
void generalList();
void rmMem();
void bookRegister();
void report_emp();
void setting_emp();
//Member Functions
int memberMenu();
void memNewBook();
void memReturn();
void memAllBooks();
void availBooks();
void setting_mem();

//*******************************************...Main
void main()
{
    //Start the menu as first wall
    int select_user = menu();
    int who = Login();
    int confirmed;
    //selection of each characters
    int admin_se ;
    int staff_se;
    int member_se;
    //call the functions by checking the selection
    switch(select_user)
    {
    case 1 :
        if(who == 1){
            confirmed = 1;
         }
        break;
    case 2 :
        if(who == 2){
            confirmed = 2;
            break;
        }
    case 3 :
        if(who == 3){
            confirmed = 3;
            break;
        }
    }
    /*for those who are confirmed and their menu is open
    get their selection*/
    switch(confirmed)
    {
    case 1 :
        admin_se = adminMenu();
         break;
    case 2 :
        staff_se = staffMenu();
        break;
    case 3 :
         member_se = memberMenu();
    }
    //admin made her choice
    switch(admin_se)
    {
    case 1 :
        newEmp();
        break;
    case 2 :
        staffList();
        break;
    case 3 :
        rmEmp();
        break;
    case 4 :
        report_ad();
    }
    //staff made their choices
    switch(staff_se)
    {
    case 1 :
        newMem();
        break;
    case 2 :
        revival();
        break;
    case 3 :
        generalList();
        break;
    case 4 :
        rmMem();
        break;
    case 5 :
        bookRegister();
        break;
    case 6 :
        report_emp();
        break;
    case 7 :
        setting_emp();
        break;
    }
    //Member made her choice
    switch(member_se)
    {
    case 1 :
        memNewBook();
        break;
    case 2 :
        memReturn();
        break;
    case 3 :
        memAllBooks();
        break;
    case 4 :
        availBooks();
        break;
    case 5 :
        setting_mem();
        break;
    }




}

//                         *ADMIN SECTION*
//..................................................Admin menu
int adminMenu()
{
    char choice ;
    int isvalid=0 ;
    puts("******/Welcome Admin/*******");
    puts("~You are in Admin menu\n______________________________________");
    puts("|1. New employee  registration");
    puts("|2. View the list of staff");
    puts("|3. Remove the employee from the system");
    puts("|4. Reports");
    puts("|5. Logout and return to main menu\n");
    printf("Please enter your choice:");
    scanf(" %c" , &choice);
    do{
        switch(choice)
        {
        case '1':
            isvalid = 1;
            break;
        case '2':
            isvalid = 2;
            break;
        case '3':
            isvalid = 3;
            break;
        case '4':
            isvalid = 4;
            break;
        case '5':
            exitpro();
            break;
        }
    }while(isvalid == 0);
    return isvalid;
}
//...................................................new employee
void newEmp()
{

}
//...................................................view staff list
void staffList()
{

}
//...................................................remove employee
void rmEmp()
{

}
//...................................................reports
void report_ad()
{

}
//                               *STAFF SECTION*
//......................................................Staff menu
int staffMenu()
{
    char choice ;
    int isvalid =0 ;
    puts("******/Welcome Employee/*******");
    puts("~You are in Staff menu\n_______________________________");
    puts("|1. Sign in for new members");
    puts("|2. Revival membership");
    puts("|3. General list of members ");
    puts("|4. Remove members");
    puts("|5. Register new books");
    puts("|6. Reports ");
    puts("|7. Account Setting");
    puts("|8. Logout and return to main menu\n");
    printf("Please enter your choice:");
    scanf(" %c" , &choice);
    do{
        switch(choice)
        {
            case '1':
                isvalid = 1;
                 break;
            case '2':
                isvalid = 2;
                break;
            case '3':
                isvalid = 3;
                break;
            case '4':
                isvalid = 4;
                break;
            case '5':
                isvalid = 5;
                break;
            case '6':
                isvalid = 6;
                break;
            case '7':
                isvalid = 7;
            case '8':
                exitpro();
                break;
        }

    }while( isvalid == 0);
    return isvalid ;
}
//.....................................................new member
void newMem()
{

}
//.....................................................revival membership
void revival()
{

}
//......................................................general list of every member
void generalList()
{

}
//......................................................remove members
void rmMem()
{

}
//......................................................books registering
void bookRegister()
{

}
//.......................................................report for employees
void report_emp()
{

}
//.........................................................staff account settings
void setting_emp()
{

}
//                              *MEMBER SECTION*
//.....................................................Member menu
int memberMenu()
{
    char choice ;
    int isvalid = 0;
    puts("*******welcome member*******");
    puts("~You are in Member menu\n_____________________________");
    puts("|1. Borrow new books");
    puts("|2. Write-in returns");
    puts("|3. My books");
    puts("|4. Available books in library");
    puts("|5. Account setting");
    puts("|6. Logout and return to main menu");
    scanf(" %c" , &choice);
    do{
        switch(choice)
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
            break;
        case '5' :
            isvalid = 5;
            break;
        case '6' :
            exitpro();
            break;
        }
    }while(isvalid == 0);
    return isvalid ;
}
//........................................................borrow new books
void memNewBook()
{

}
//........................................................return books
void memReturn()
{

}
//.........................................................all of the member's book
void memAllBooks()
{

}
//..........................................................available books to borrow
void availBooks()
{

}
//...........................................................setting for member's account
void setting_mem()
{

}
//                               *GENERAL SECTION*
//...................................................Main menu managemanet
int menu()
{
    char choice;
    int isvalid =0;
    do{
        puts("*******/Welcome to PeanutZee Library/*******");
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
//......................................................Repeat
void repeat()
{   char x ;
    printf("~Your input is not valid\n");
    printf("Enter any key to start again:");
    getche(x);
    system("cls");
    menu();
}
//.....................................................exit
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
//......................................................log in
int Login()
{
    printf("Log in process... \n");
    char user[USERNAME];
    char pass[PASSWORD];
    char ch ;
    int i , chance = 3;//the numbers to try your password chance
    printf("Username:");
    scanf(" %s" , user);
    //check the username character
    if(strcmp(user , "admin") == 0){
        printf("Password:");//add stars to avoid showing password
      while(chance > 0){
            i = 0 ;//for every new chances
          while(1){
              ch = getch();
              if(ch == '\r'){
                  break;
              }
              if( i < sizeof(pass) - 1){
                  pass[i++] = ch ;
                  printf("*");
              }
            }
            pass[i] = '\0' ;
            if(strcmp(pass , "1234") == 0){
              printf("\n");
              return 1 ;
            }
            else{
                chance-- ;
            //add limits for trying here
            if(chance > 0){
                printf("\nWrong password!\nYou have %d more chances,try again!" , chance);
                printf("\nPassword:");
            }
            else{
                printf("\nToo many wrong passwords!\nThe program will be closed soon...");
                Sleep(3000);
                system("cls");
                exit(1);
            }
        }
      }
    }
    else{
        //check in the files for username
        //check in the files for passwords
    return 2 ;
    return 3 ;
    }

}
