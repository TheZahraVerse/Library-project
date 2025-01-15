//Library management project---> *PEANUTZEE LIBRARY*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
//define sizes
#define USERNAME 16
#define PASSWORD 20
#define ADMIN_USERNAME "a"
#define ADMIN_PASS "123"
#define EMPFILE "Staffprofile.txt"
#define MEMFILE "Membersprofile.txt"
//..........................................Functions
//General Functions
int menu();//done
int Login();//50 - 50//there is a problem in process
void hidepass(char pass[PASSWORD]);//done
void repeat();//done
void exitpro();//done
//Admin Functions
int adminMenu();//done
void newEmp();//done
void staffList();//done
void rmEmp();
void report_ad();
//staff Functions
int staffMenu();//done
void newMem();
void revival();
void generalList();
void rmMem();
void bookRegister();
void report_emp();
void setting_emp();
//Member Functions
int memberMenu();//done
void memNewBook();
void memReturn();
void memAllBooks();
void availBooks();
void setting_mem();
//Staff structure
struct employee
{
    char username_emp[16];
    char pass_emp[16];
    char name[20];
    char family[20];
    char join_date[10];
    char phone[10];
    char id_emp[20];
    char email[40];
    struct employee *link ;
};
struct employee *start_e , *e;
//Members structure
struct member
{
    char username_mem[16];
    char pass_mem[16];
    char name[20];
    char family[20];
    char join_date[10];
    char validate[10];
    char phone[10];
    char id_mem[20];
    char email[40];
    struct member *link ;
};
struct member *start_m  , *m;

//*******************************************...Main
void main()
{
    start_e = malloc(sizeof(struct employee));
    e = start_e ;
    start_m = malloc(sizeof(struct member));
    m = start_m ;
    //Start the menu as first wall
    int select_user = menu();
    int who = Login();
    //not entered
    if(who == 0)
        select_user = 0 ;
    int confirmed;
    //selection of each characters
    int admin_se ;
    int staff_se;
    int member_se;
    //call the functions by checking the selection
    switch(select_user)
    {
    case 0 ://Issue in repeating the menu again
        repeat();
        menu();
        break;
    case 1 :
        if(who == 1){
            confirmed = 1;
         }
        break;
    case 2 :
        if(who == 2){
            confirmed = 2;
        }
        break ;
    case 3 :
        if(who == 3){
            confirmed = 3;
        }
        break;
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
        newEmp(e);
        e = e->link ;
        break;
    case 2 :
        staffList(e);
        e = e->link ;
        break;
    case 3 :
        rmEmp();
        break;
    case 4 :
        report_ad();
        break;
    case 5 :
        repeat();
        adminMenu();
        break;
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
    char choice[100] , ch ;
    int isvalid=0 ;
    do{
    puts("******/Welcome Admin/*******");
    puts("~You are in Admin menu\n______________________________________");
    puts("|1. New employee  registration");
    puts("|2. View the list of staff");
    puts("|3. Remove the employee from the system");
    puts("|4. Reports");
    puts("|5. Logout and return to main menu\n");
    printf("Please enter your choice:");
    scanf(" %s" , &choice);
    if( isdigit(choice[0]) && choice[1]=='\0'){
        ch = choice[0];
    }
    else{
        ch = '6' ;
    }
        switch(ch)
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
        case '6' :
            repeat();
            break;
        }
    }while(isvalid == 0);
    return isvalid;
}
//...................................................new employee
void newEmp(struct employee *x)
{
    FILE *f ;
    f = fopen(EMPFILE , "a");
    if(f == NULL){
        printf("The staff file has not found !\nYou will return to admin menu...");
        Sleep(5000);
        system("cls");
        adminMenu();
    }
    else{//get info and add them to file
        puts("~New employee informations:");
        printf("First name:");
        scanf(" %s" , x->name);

        printf("Last name:");
        scanf(" %s" , x->family);

        printf("ID number:");
        scanf(" %s" , x->id_emp);//issue in saving id

        printf("Join date(dd/mm/yyyy):");
        scanf(" %s" , x->join_date);

        printf("Phone number:");
        scanf(" %s" , x->phone);

        printf("E-mail:");
        scanf(" %s" , x->email);

        printf("Username:");//add condition
        scanf(" %s" , x->username_emp);

        printf("Password:");//add double check
        scanf(" %s" , x->pass_emp);

        //add info to the file by this sort
        fprintf(f , "\n");
        fprintf(f , "%s\n" , x->username_emp);
        fprintf(f , "%s\n" , x->pass_emp);
        fprintf(f , "%s\n" , x->id_emp);
        fprintf(f , "%s\n" , x->join_date);
        fprintf(f , "%s\n" , x->name);
        fprintf(f , "%s\n" , x->family);
        fprintf(f , "%s\n" , x->phone);
        fprintf(f , "%s\n" , x->email);

        //if the conditions worked out , you can write a better massage
        printf("New employee added successfully.\nPress any key to return to admin menu:");
        fclose(f);
        getche();
        printf("\n\nReturning to admin menu...");
        Sleep(3000);
        system("cls");
        adminMenu();//issue to choose again
    }
}
//...................................................view staff list
void staffList(struct employee *x)
{
    //system cls
    puts("\n~You are watching the list of staff~");
    puts("______________________________________");
    FILE *f ;
    f = fopen(EMPFILE , "r");
    if(f == NULL){
        printf("The staff file has not found !\nYou will return to admin menu...");
        Sleep(5000);
        system("cls");
        adminMenu();
    }
    else{
       int empcount = 1 ;
       while(feof(f)== 0){
        fscanf(f , "%s\n" , x->username_emp);
        fscanf(f , "%s\n" , x->pass_emp);
        fscanf(f , "%s\n" , x->id_emp);
        fscanf(f , "%s\n" , x->join_date);
        fscanf(f , "%s\n" , x->name);
        fscanf(f , "%s\n" , x->family);
        fscanf(f , "%s\n" , x->phone);
        fscanf(f , "%s\n" , x->email);
        if(x->username_emp == EOF)
            break;
        //show the list
        printf("|~~Employee No.%d~~\n" , empcount++);
        printf("|First name   :  %s\n" , x->name);
        printf("|Last name    :  %s\n" , x->family);
        printf("|ID number    :  %s\n" , x->id_emp);
        printf("|Phone number :  %s\n" , x->phone);
        printf("|E-mail       :  %s\n" , x->email);
        printf("|Join date    :  %s\n" , x->join_date);
        printf("|Username     :  %s\n" , x->username_emp);
        printf("|Password     :  %s\n" , x->pass_emp);
        puts("______________________________________");
        }
        if(empcount == 1)
            printf("No staff data found!");
    }
    fclose(f);
    printf("Press any key to return to admin menu:");
    getche();
    printf("\n\nReturning to admin menu...");
    Sleep(3000);
    system("cls");
    adminMenu();//issue to choose again
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
    char choice[100] , ch ;
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
    scanf(" %s" , &choice);
    if( isdigit(choice[0]) && choice[1]=='\0'){
        ch = choice[0];
    }
    do{
        switch(ch)
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
    FILE *m ;
    m = fopen(MEMFILE , "a");
    if(m == NULL){
        printf("\n~The member file has not found!\nReturning to staff menu...");
        Sleep(4000);
        system("cls");
        staffMenu();
    }
    else{

    }

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
    char choice[100] , ch ;
    int isvalid = 0;
    puts("*******welcome member*******");
    puts("~You are in Member menu\n_____________________________");
    puts("|1. Borrow new books");
    puts("|2. Write-in returns");
    puts("|3. My books");
    puts("|4. Available books in library");
    puts("|5. Account setting");
    puts("|6. Logout and return to main menu");
    printf("Please enter your choice:");
    scanf(" %s" , &choice);
    if( isdigit(choice[0]) && choice[1]=='\0'){
        ch = choice[0];
    }
    do{
        switch(ch)
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
    char choice[100];
    char ch;
    int isvalid =0;
    do{
        puts("*******/Welcome to PeanutZee Library/*******");
        puts("~You are in : main menu\n____________________");
        puts("|1. Admin Login");
        puts("|2. Staff Login");
        puts("|3. Member Login");
        puts("|4. Exit\n");
        printf("Please enter your choice:");
        scanf(" %s" , &choice);
        if( isdigit(choice[0]) && choice[1]=='\0'){
            ch = choice[0];
        }
           switch (ch)
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
    x = getche();
    system("cls");
}
//.....................................................exit
void exitpro()
{
    int x ;
    printf("~Are you sure you want to exit?   | 1.Yes  / 2.No | : ");
    scanf(" %d" , &x);
    while( x == 1){
        printf("Exiting the program....");
        Sleep(3000);
        system("cls");
        exit(1);
    }
    while(x == 2){
        printf("Returning to main menu....");
        Sleep(3000);
        system("cls");
        menu();
    }
}
//......................................................log in
int Login()//input for user selection
{
    printf("Log in process... \n");
    char user_input[USERNAME];
    char pass_input[PASSWORD];
    char ch ;
    int i , chance = 3;//the numbers to try your password chance
    //excited usernames and passwords reads from files
    char user_file[USERNAME];
    char pass_file[PASSWORD];
    printf("Username:");
    scanf(" %s" , user_input);
    //check the input username character

        if(strcmp(user_input , ADMIN_USERNAME) == 0){
            printf("Password:");//add stars to avoid showing password
            while(chance > 0){
                hidepass(pass_input);//hide on screen
                if(strcmp(pass_input , ADMIN_PASS) == 0){
                    printf("\n~Login successfully as admin~\n");
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

        FILE *s , *m ;

        s = fopen(EMPFILE , "r");
        if(s == NULL){
            printf("The staff file has not found!\nReturning to main menu...");
            Sleep(4000);
            exitpro();
        }
        else{
        //check for staff log in
            while(feof(s)==0){
                fgets(user_file ,USERNAME , s);
                user_file[strcspn(user_file, "\n")] = '\0';

                if(strcmp(user_file , user_input) == 0){
                    chance = 3 ;//limit for password chances
                    while(chance > 0){
                        printf("Password:");
                        hidepass(pass_input);
                        fgets(pass_file , PASSWORD , s);
                        pass_file[strcspn(pass_file, "\n")] = '\0';

                        if(strcmp(pass_file , pass_input) == 0){
                            printf("\n~Login successfully as staff~\n");
                            fclose(s);
                            return 2 ;
                        }else{
                            chance-- ;
                            if(chance > 0){
                                printf("\nWrong password!\nYou have %d more chances,try again!" , chance);
                                hidepass(pass_input);
                            }else{
                                printf("\nToo many wrong passwords!\nThe program will be closed soon...");
                                fclose(s);
                                Sleep(3000);
                                system("cls");
                                exit(1);
                            }
                        }
                    }
                }
            }
        }
        //check for member log in
        m = fopen(MEMFILE , "r");
        if(m == NULL){
            printf("The members file has not found!\nReturning to main menu...");
            Sleep(4000);
            exitpro();
        }else{
            while(feof(m)==0){
                fgets(user_file , USERNAME , m);
                user_file[strcspn(user_file, "\n")] = '\0';

            if(strcmp(user_file , user_input)==0){
                chance = 3 ;
                while(chance > 0){
                printf("Password:");
                hidepass(pass_input);
                fgets(pass_file , PASSWORD , m);
                pass_file[strcspn(pass_file, "\n")] = '\0';

                    if(strcmp(pass_file , pass_input)==0){
                        printf("\n~Login successfully as member~\n");
                        fclose(m);
                        return 3;
                    }else{
                        chance-- ;
                        if(chance > 0){
                            printf("\nWrong password!\nYou have %d more chances,try again!" , chance);
                            hidepass(pass_input);
                        }else{
                            printf("\nToo many wrong passwords!\nThe program will be closed soon...");
                            fclose(s);
                            Sleep(3000);
                            system("cls");
                            exit(1);
                        }
                    }
                }
            }
        }
    }
}

void hidepass(char pass[PASSWORD])
{
    char ch;
    int i = 0;
    while(1){
        ch = getch();
        if(ch == '\r') { // Enter
            break;
        }else if(ch == '\b'){
                if (i > 0){
                    i--;
                    printf("\b \b");
                }
        }else if(i < PASSWORD - 1){
                pass[i++] = ch;
                printf("*");
        }
    }
    pass[i] = '\0';
}


