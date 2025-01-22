//Library management project---> *PEANUTZEE LIBRARY*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
//define sizes
#define USERNAME 16
#define PASSWORD 20
#define ADMIN_USERNAME "admin"
#define ADMIN_PASS "123"
#define EMPFILE "Staffprofile.txt"
#define MEMFILE "Membersprofile.txt"
#define GBOOKFILE "Generalbooks.txt"
//..........................................Functions
//General Functions
int menu();//done
int Login();//solved
void hidepass(char pass[PASSWORD]);//done
int validusername(char user[10]);
int validphone(char phone[10]);
int validname(char name[20]);
int validID(char ID[10]);
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
void newMem();//done
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
    char username_emp[10];
    char pass_emp[16];
    char name[20];
    char family[20];
    char join_date_e[10];
    char phone[10];
    char id_emp[20];
    char email[40];
    struct employee *link ;
};
struct employee *start_e , *e;
//Members structure
struct member
{
    char username_mem[10];
    char pass_mem[16];
    char name[20];
    char family[20];
    char join_date_m[10];
    char validate[10];
    char phone[10];
    char id_mem[20];
    char email[40];
    struct member *link ;
};
struct member *start_m  , *m;
//Books structure
struct book
{
    char name[50];
    char publication[20];
    char writer[50];
    char year[4];
    char reg_date[10];//automatic
    char id_book[10];
    char id_register[10];
};
struct book *start_b , *b ;

//*******************************************...Main
void main()
{
    int select_user , who , confirmed = 0;
    //selection of each characters
    int admin_se ;
    int staff_se;
    int member_se;
   //Start the menu as first wall
   do{//to repeat the menu//done
        select_user = menu();
        if(select_user == 4){
            continue;
        }
        who = Login(select_user);//add
        //not entered
        if(who == 0){
            select_user = 0 ;
            printf("\n");
            repeat();
            system("cls");
        }
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
            }
            break ;
        case 3 :
            if(who == 3){
                confirmed = 3;
            }
        }
        if(confirmed != 0)
            break;
   }while(1);
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
    case 0 :
        menu();
        break;
    case 1 :
        newEmp(e);
        break;
    case 2 :
        staffList(e);
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
            newMem(m);
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
        case 8 :
            exitpro();
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
    puts("|1. New employee registration");
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
        ch = '\0' ;
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
            return 0 ;
            break;
        default :
            repeat();
            break;
        }
    }while(isvalid == 0);
    return isvalid;
}
//...................................................new employee
void newEmp(struct employee *x)
{
    char temp[50];
    int num ;
    printf("~How many staff you want to add ? : ");
    scanf(" %d" , &num);
    FILE *e ;
    e = fopen(EMPFILE , "a");
    if(e == NULL){
        printf("The staff file has not found !\nYou will return to admin menu...");
        Sleep(5000);
        system("cls");
        adminMenu();
    }
    else{//get info and add them to file
        int count = 0;
        for(int i = 0 ; i < num ; i++){
            puts("______________________________________");
            printf("~Add information(Employee %d of %d):\n" , i+1 , num);
        while(1){
            printf("First name:");
            //get input
            scanf(" %s" , temp);
            if( validname(temp) == 0){
                puts("\nTry again!");
                repeat();
                continue;
            }
            else{
                //copy in pointer address to put file later
                strcpy(x->name , temp);//issue
                break;
            }
        }

        while(1){
            printf("Last name:");
            scanf(" %s" , temp);
            if( validname(temp) == 0){
                puts("\nTry again!");
                repeat();
                continue;
            }
            else{
                strcpy(x->family , temp);
                break;
            }
        }

        while(1){
            printf("ID number:");
            scanf(" %s" , temp);
            if( validID(temp) == 0){
                puts("\nTry again!");
                repeat();
                continue;
            }
            else{
                strcpy(x->id_emp , temp);
                break;
            }
        }
            printf("Join date:");
            scanf(" %s" , temp);
            strcpy(x->join_date_e , temp);

       while(1){
            printf("Phone number:");
            scanf(" %s" , temp);
            if(validphone(temp) == 0){
                puts("\nTry again!");
                repeat();
                continue;
            }else{
                strcpy(x->phone , temp);
                break;
            }
       }
            printf("E-mail:");
            scanf(" %s" , temp);
            strcpy(x->email , temp);

        while(1){
            printf("Username:");//must check it first
            scanf(" %s" , temp);
            if(validusername(temp)==0){
                puts("\nTry again!");
                repeat();
                continue;
            }else{
                strcpy(x->username_emp , temp);
                break;
            }
        }

            printf("Password:");//must check it first
            scanf(" %s" , temp);
            strcpy(x->pass_emp , temp);

        //add info to the file by this sort
            fputs(x->username_emp , e);
            fputs("\n" , e);
            fputs(x->pass_emp , e);
            fputs("\n" , e);
            fputs(x->id_emp, e);
            fputs("\n" , e);
            fputs(x->join_date_e , e);
            fputs("\n" , e);
            fputs(x->name , e);
            fputs("\n" , e);
            fputs(x->family , e);
            fputs("\n" , e);
            fputs(x->phone , e);
            fputs("\n" , e);
            fputs(x->email , e);
            fputs("\n" , e);

        //if the conditions worked out , you can write a better massage
            puts("New Employee added successfully");
            count++ ;
        }
        fclose(e);
        printf("\nAll staff added successfully.\n");
        printf("Press any key to return to admin menu.");//issue
        getche();
        return ;
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
        fscanf(f , "%s\n" , x->join_date_e);
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
        printf("|Join date    :  %s\n" , x->join_date_e);
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
    while(1){
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
    scanf(" %s" , choice);
    if( isdigit(choice[0]) && choice[1]=='\0'){
        ch = choice[0];
    }
    else{
        ch = '\0' ;
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
            default :
                   printf("\n~Your input is not valid!\n");
                   repeat();
                   system("cls");
                   break;
        }

    }while( isvalid == 0);
    return isvalid ;
    }
}
//.....................................................new member
void newMem(struct member *x)
{
    int num , count=0;
    printf("How many members you want to add? : ");
    scanf(" %d" , &num);
    char temp[50];//an array to copy each time
    FILE *m ;
    m = fopen(MEMFILE , "a");
    if(m == NULL){
        printf("\n~The member file has not found!\nReturning to staff menu...");
        Sleep(4000);
        system("cls");
        staffMenu();
    }
    else{
        for(int i = 0 ; i < num ; i++){
            puts("__________________________________________");
            printf("\n~Add information(member %d of %d):\n" , i+1 , num);
            printf("First name:");
            //get input
            scanf(" %s" , temp);
        while(1){
            printf("First name:");
            //get input
            scanf(" %s" , temp);
            if( validname(temp) == 0){
                puts("\nTry again!");
                repeat();
                continue;
            }
            else{
                //copy in pointer address to put file later
                strcpy(x->name , temp);
                break;
            }
            //copy in pointer address to put file later
            strcpy(x->name , temp);
        }

        while(1){
            printf("Last name:");
            scanf(" %s" , temp);
            if( validname(temp) == 0){
                puts("\nTry again!");
                repeat();
                continue;
            }
            else{
                strcpy(x->family , temp);
                break;
            }
        }
        while(1){
            printf("ID number:");
            scanf(" %s" , temp);
            if( validID(temp) == 0){
                puts("\nTry again!");
                repeat();
                continue;
            }
            else{
                strcpy(x->id_mem , temp);
                break;
            }
        }
            printf("Join date:");
            scanf(" %s" , temp);
            strcpy(x->join_date_m , temp);

        while(1){
            printf("Phone number:");
            scanf(" %s" , temp);
            if(validphone(temp) == 0){
                puts("\nTry again!");
                repeat();
                continue;
            }else{
                strcpy(x->phone , temp);
                break;
            }
        }
            printf("E-mail:");
            scanf(" %s" , temp);
            strcpy(x->email , temp);

        while(1){
            printf("Username:");//must check it first
            scanf(" %s" , temp);
            if(validusername(temp)==0){
                puts("\nTry again!");
                repeat();
                continue;
            }else{
                strcpy(x->username_mem , temp);
                break;
            }
        }


            printf("Password:");//must check it first
            scanf(" %s" , temp);
            strcpy(x->pass_mem , temp);

            printf("Validate:");
            scanf(" %s" , temp);
            strcpy(x->validate , temp);

        //add info to the file by this sort

            fputs(x->username_mem , m);//issue print diff char
            fputs("\n" , m);
            fputs(x->pass_mem , m);
            fputs("\n" , m);
            fputs(x->validate , m);
            fputs("\n" , m);
            fputs(x->id_mem , m);
            fputs("\n" , m);
            fputs(x->join_date_m , m);
            fputs("\n" , m);
            fputs(x->name , m);
            fputs("\n" , m);
            fputs(x->family , m);
            fputs("\n" , m);
            fputs(x->phone , m);
            fputs("\n" , m);
            fputs(x->email , m);
            fputs("\n" , m);

        //if the conditions worked out , you can write a better massage
            puts("New member added successfully");
            count++ ;
        }
        fclose(m);
        printf("\nAll members added successfully.\n");
        printf("Press any key to return to staff menu.");
        getche();
    }

}
//.....................................................revival membership
void revival()
{

}
//......................................................general list of every member
void generalList(struct member *x)
{
    printf("\n~You are watching the list of Members~\n");
    puts("______________________________________");
    FILE *f ;
    f = fopen(MEMFILE , "r");
    if(f == NULL){
        printf("The member's file has not found!\n");
        Sleep(4000);
        system("cls");
        staffMenu();
    }
    else{
        int empcount = 1 ;
        while(feof(f)== 0){
            fscanf(f , "%s\n" , x->username_mem);//issue in showing the username and pass
            fscanf(f , "%s\n" , x->pass_mem);
            fscanf(f , "%s\n" , x->validate);
            fscanf(f , "%s\n" , x->id_mem);
            fscanf(f , "%s\n" , x->join_date_m);
            fscanf(f , "%s\n" , x->name);
            fscanf(f , "%s\n" , x->family);
            fscanf(f , "%s\n" , x->phone);
            fscanf(f , "%s\n" , x->email);
            if(x->username_mem == EOF)
                break;
            //show the list
            printf("|~~Member No.%d~~\n" , empcount++);
            printf("|First name   :  %s\n" , x->name);
            printf("|Last name    :  %s\n" , x->family);
            printf("|ID number    :  %s\n" , x->id_mem);
            printf("|Phone number :  %s\n" , x->phone);
            printf("|E-mail       :  %s\n" , x->email);
            printf("|Join date    :  %s\n" , x->join_date_m);
            printf("|Validate     :  %s\n" , x->validate);
            printf("|Username     :  %s\n" , x->username_mem);
            printf("|Password     :  %s\n" , x->pass_mem);
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
        adminMenu();//issue to choose again*/
}


//......................................................remove members
void rmMem()
{

}
//......................................................books registering
void bookRegister(struct book *x)
{
    char temp[50] , user[10];
    int num , id;
    printf("~Enter your username :");//consider it valid
    scanf(" %s" , user);
    printf("\n~How many books you want to add ? :");
    scanf(" %d" , &num);
    FILE *f ;
    f = fopen(GBOOKFILE , "a");
    if(f == NULL){
        printf("\nCould not found the file of books!\n");
        repeat();
        return;
    }
    else{
        for(int i = 0 ; i < num ; i++){
            puts("\n_______________________________________");
            printf("~Add information (book %d of %d):\n" , i+1 , num);
            printf("Name of the book :");
            //get input
            scanf(" %s" , temp);//use '_' to separate words
            //copy temp to save it to file later
            strcpy(x->name , temp);

            printf("The publication :");
            scanf(" %s" , temp);
            strcpy(x->publication , temp);

            printf("Name of the writer :");
            scanf(" %s" , temp);
            strcpy(x->writer , temp);

            printf("Year of publication :");
            scanf(" %s" , temp);
            strcpy(x->year , temp);

            printf("Date of registration :");//automatic later
            scanf(" %s" , temp);
            strcpy(x->reg_date , temp);

            //get a random number for id
            id = rand();
            //convert to string
            itoa(id , temp , 10);
            strcpy(x->id_book , temp);

            //specify the register employee
            strcpy(x->id_register , user);

            //add information in file
            fputs(x->name , f);
            fputs("\n" , f);
            fputs(x->writer , f);
            fputs("\n" , f);
            fputs(x->publication , f);
            fputs("\n" , f);
            fputs(x->id_book , f);
            fputs("\n" , f);
            fputs(x->year , f);
            fputs("\n" , f);
            fputs(x->reg_date , f);//same issue in file
            fputs("\n" , f);
            fputs(x->id_register , f);
            fputs("\n" , f);

            printf("\n~New book added successfully.\n");
        }
        fclose(f);
        printf("\n~All books successfully saved by '%s'\n" , user);
        printf("Press any key to return to staff menu:");//issue
        getche();
    }

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
    puts("\n*******Welcome member*******");
    puts("~You are in Member menu\n_____________________________");
    puts("|1. Borrow new books");
    puts("|2. Write-in returns");
    puts("|3. My books");
    puts("|4. Available books in library");
    puts("|5. Account setting");
    puts("|6. Logout and return to main menu");
    printf("\nPlease enter your choice:");
    scanf(" %3s" , &choice);
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
        default :
            repeat();
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
//...................................................Main menu management
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
        }else{
            ch = '\0' ;
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
                   printf("\n~Your input is not valid!\n");
                   repeat();
                   system("cls");
                   break;
            }

    }while( isvalid == 0);

    return isvalid ;

}
//......................................................Repeat
void repeat()
{
    printf("Enter any key to start again:");
    getche();
    printf("\n");
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
    }
}
//......................................................log in
int Login(int selection)//input for user selection
{
    printf("Log in process... \n");
    char user_input[USERNAME];
    char pass_input[PASSWORD];
    char ch ;
    int i , chance = 3;//the numbers to try your password chance
    int found ;//check for a founded user
    int usercheck;
    //excited usernames and passwords reads from files
    char user_file[USERNAME];
    char pass_file[PASSWORD];
    printf("Username:");
    scanf(" %s" , user_input);
    usercheck = validusername(user_input);
    if(usercheck == 0)
        return 0 ;
    else{
    //check the input username character
    while(selection == 1){
        if(strcmp(user_input , ADMIN_USERNAME) == 0){
            printf("Password:");//add stars to avoid showing password
            while(chance > 0){
                hidepass(pass_input);//hide on screen
                if(strcmp(pass_input , ADMIN_PASS) == 0){
                    printf("\n~Login successfully as admin~\n");
                    printf("\n");
                    found = 1 ;
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
        }else{//if it was not admin
            puts("Wrong username for admin!");
            return 0 ;
        }
    }
        if(found == 0){
            printf("Wrong username for admin!\n");
            return 0 ;
        }
    while(selection == 2){
        FILE *s , *m ;
        s = fopen(EMPFILE , "r");
        if(s == NULL){
            printf("The staff file has not found!\nReturning to main menu...");
            Sleep(4000);
            exitpro();
        }
        else{
        //check for staff log in
        found = 0 ;
            while(feof(s)==0){
                fgets(user_file ,USERNAME , s);
                user_file[strcspn(user_file, "\n")] = '\0';

                if(strcmp(user_file , user_input) == 0){
                    chance = 3 ;//limit for password chances
                    printf("Password:");
                    while(chance > 0){   //.......................Issue in repeating password
                        hidepass(pass_input);
                        fgets(pass_file , PASSWORD , s);
                        pass_file[strcspn(pass_file, "\n")] = '\0';

                        if(strcmp(pass_file , pass_input) == 0){
                            printf("\n~Login successfully as staff~\n");
                            found = 1 ;
                            fclose(s);
                            return 2 ;
                        }else{
                            chance-- ;
                            if(chance > 0){
                                printf("\nWrong password!\nYou have %d more chances,try again!" , chance);
                                printf("\nPassword:");
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
            if(found == 0){
                printf("Employee not found!\n");
                return 0 ;
            }
        }
    }
    while(selection == 3){
        //check for member log in
        m = fopen(MEMFILE , "r");
        if(m == NULL){
            printf("The members file has not found!\nReturning to main menu...");
            Sleep(4000);
            exitpro();
        }else{
            found = 0;
            while(feof(m)==0){
                fgets(user_file , USERNAME , m);
                user_file[strcspn(user_file, "\n")] = '\0';

            if(strcmp(user_file , user_input)==0){
                chance = 3 ;
                printf("Password:");
                while(chance > 0){
                hidepass(pass_input);
                fgets(pass_file , PASSWORD , m);
                pass_file[strcspn(pass_file, "\n")] = '\0';

                    if(strcmp(pass_file , pass_input)==0){
                        printf("\n~Login successfully as member~\n");
                        found = 1;
                        fclose(m);
                        return 3;
                    }else{
                        chance-- ;
                        if(chance > 0){
                            printf("\nWrong password!\nYou have %d more chances,try again!" , chance);
                            printf("\nPassword:");
                            hidepass(pass_input);
                        }else{
                            printf("\nToo many wrong passwords!\nThe program will be closed soon...");
                            fclose(m);
                            Sleep(3000);
                            system("cls");
                            exit(1);
                        }
                    }
                }

            }else
               found = 0;
        }
        if(found == 0){
            printf("Member not found!\n");
                return 0 ;
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
        if(ch == '\r') {
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
int validusername(char user[10])
{
    int len = strlen(user);
    if(user[len-1] == '\n'){
        user[len-1] == '\0';
        len-- ;
    }
    //check the length of username
    if( len < 4 || len > 10 ){
        puts("\n~Username must be between 4 and 10 characters");
        return 0 ;
    }
    else{
        if(!isalpha(user[0])){
            puts("\n~Username must start with at least one alphabetical character");
            return 0 ;
        }
        for(int i = 0 ; i < len ; i++){
            if(!isalnum(user[i]) && user[i]!= '.' && user[i]!= '_'){
                puts("\n~There is invalid characters in username");
                //add more conditions later
                return 0 ;
            }
        }//valid username
        return 1 ;
    }
}
int validphone(char phone[10])
{
    int len = strlen(phone);//size of phone number without 09
    int count = 0 ;
    if( len != 9 ){
        printf("\n~Phone number must have exactly 11 digits!\n");
        return 0 ;//not valid
    }
    else{
        for(int i = 0 ; i < len ; i++){
            if(!isdigit(phone[i]) ){//only digits
                printf("\n~Phone number is not valid,Use digits only!\n");
                return 0 ;//not valid
                break;
            }
            else{
                count++ ;
            }
        }
        if(count == 9)//all of the characters are valid
            return 1 ;
    }

}
int validname(char name[20])
{
    int len = strlen(name);
    int count = 0 ;
    if(len < 4 || len > 20 ){
        printf("\n~Name must be between 4 and 20 characters!\n");
        return 0 ;
    }
    else{
        for(int i = 0 ; i < len ; i++){
            if( !isalpha(name[i]) ){
                printf("\n~Invalid name , Use only alphabetical characters!\n");
                return 0 ;
            }
            else
                count++ ;
        }
        if(count == len){
            return 1 ;
        }
    }
}
int validID(char ID[10])
{
    int count = 0;
    int len = strlen(ID);
    if( len != 10 ){
        printf("\n~ID must have 10 digits!\n");
        return 0 ;
    }
    else{
        for(int i = 0 ; i < len ; i++){
            if( !isdigit(ID[i]) ){
                printf("\n~Invalid ID(unknown characters for ID) , Use digits only!\n");
                return 0 ;
            }
            else{
                count++ ;
            }
        }
        if(count == len){
            return 1 ;
        }
    }
}

