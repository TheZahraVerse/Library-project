//Library management project---> *PEANUTZEE LIBRARY*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
#define ARCSTAFF "Staffarchive.txt"
#define ARCMEMBER "Membersarchive.txt"
//..........................................Functions
//Linked list functions
struct employee* CallFileLinkEmp();
struct member* CallFileLinkMem();
//General Functions
void manage(int here);
int menu();//done
int Login();//solved
void hidepass(char pass[PASSWORD]);//done
int validusername(char user[10]);
int validphone(char phone[10]);
int validname(char name[20]);
int validID(char ID[10]);
int validemail(char email[20]);
int validdate(char date[20]);
int isinfile(char input[100] , char file[100]);
void todaydate(char *current);
void repeat();//done
int exitpro();//done
//Admin Functions
int adminMenu();//done
void newEmp();//..............................................
void staffList();//.............................................
void rmEmp();//..................................................
void report_ad();//.............................................
//staff Functions
int staffMenu();//done
void newMem();//done
void revival();//.............................................
void generalList();//done
void rmMem();//....................................................
void bookRegister();//done
void report_emp();//............................................
int setting_emp(struct employee *head);//.........................................
void savechanges_emp(struct employee *head);
//Member Functions
int memberMenu();//done
void memNewBook();//...........................................
void memReturn();//.............................................
void memAllBooks();//............................................
void availBooks();//done
int memberSetting(struct member *head);
void memberSavechanges(struct member *head);
//Staff structure
struct employee
{
    char username_emp[10];
    char pass_emp[16];
    char name[20];
    char family[20];
    char join_date_e[15];
    char phone[20];
    char id_emp[20];
    char email[40];
    char status[2]; // to know what her position is
    struct employee *link ;
};
struct employee E ;

//Members structure
struct member
{
    char username_mem[10];
    char pass_mem[16];
    char name[20];
    char family[20];
    char join_date_m[15];
    char validate[10];
    char phone[20];
    char id_mem[20];
    char email[40];
    char status[3]; //condition for each member to know the position
    struct member *link ;
};
struct member M ;
//Books structure
struct book
{
    char name[50];
    char publication[20];
    char writer[50];
    char year[5];
    char reg_date[11];//automatic
    char id_book[10];
    char reg_user[10];
    struct book *link ;
};
struct book B ;


//*******************************************...Main
void main()
{
    int here ;
    int back ;
    int who =  0;
    int result ;
    char dis ;
    int adminselect , staffselect , memberselect;
    here = menu();
    while(1){
        //call the head of files linked list
        struct employee *head_emp = CallFileLinkEmp();
        struct member *head_mem = CallFileLinkMem();
       //......................choose between menus
        switch(here)
        {
        case 0 :
            here = menu();
            continue;//to repeat main menu
            break;
        case 1 :
            if(who == 0){//log in again
                who = Login(here);
                break;
            }
            else
                who = 1;//continue with this user
            break;
        case 2 :
            if(who ==0){
                who = Login(here);
                break;
            }
            else
                who = 2;
            break;
        case 3 :
            if(who == 0){
                who = Login(here);
                break;
            }
            else
                who = 3;
            break;
        //exiting the program
        case 4 :
           back = exitpro();
           if(back == 1){
            here = menu();
            continue;
           }
           else
            break;
        }
        //......................choose between characters
        switch(who)
        {
        case 0 ://back main menu
            printf("\n~Returning to main menu...");
            Sleep(3000);
            system("cls");
            here = menu();
            continue;
            break;
    //...........................choose in admin menu
        case 1 :
            switch(adminMenu())
            {
            case 0 :
                puts("\n______________________");
                printf("|1.Admin menu\n|2.Main menu\n\n~Select your choice:");
                dis = getch();
                printf("\n");
                if(dis == '1'){
                    here = 1;
                    who = 1;
                    printf("\n~Returning to admin menu...");
                    Sleep(4000);
                    system("cls");
                    continue;
                }
                else{
                    who = 0;
                    printf("\n~Returning to main menu...");
                    Sleep(3000);
                    system("cls");
                    here = menu();
                    continue;
                }
                   break;
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
                break;
            case 5 :
                who = 0;
                printf("\n~Returning to main menu...");
                Sleep(3000);
                system("cls");
                here = menu();
                continue;
            }
            break;
    //..............................choose in staff menu
        case 2 :
           switch(staffMenu())
           {
           case 0 :
                puts("\n______________________");
                printf("|1.Staff menu\n|2.Main menu\n\n~Select your choice:");
                dis = getch();
                printf("\n");
                if(dis == '1'){
                    here = 2;
                    who = 2;
                    printf("\n~Returning to staff menu...");
                    Sleep(4000);
                    system("cls");
                    continue;
                }
                else{
                    who = 0;
                    printf("\n~Returning to main menu...");
                    Sleep(3000);
                    system("cls");
                    here = menu();
                    continue;
                }
                break;
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
                result = setting_emp(head_emp);
                if(result == 0){//unsuccessful in changing info
                    free(head_emp);
                    puts("\n______________________");
                    printf("|1.Staff menu\n|2.Account setting\n\n~Select your choice:");
                    dis = getch();
                    printf("\n");
                    if(dis == '1'){
                        here = 2;
                        who = 2;
                        printf("\n~Returning to staff menu...");
                        Sleep(4000);
                        system("cls");
                        continue;
                    }
                    else{
                        who = 2;
                        printf("\n~Returning to setting...");
                        Sleep(3000);
                        system("cls");
                        here = 2;
                        who = 2 ;
                        continue;
                    }
                }
                else if(result == 1){//successful in changing info
                    puts("\n______________________");
                    printf("|1.Staff menu\n|2.Main menu\n\n~Select your choice:");
                    dis = getch();
                    printf("\n");
                    if(dis == '1'){
                        here = 2;
                        who = 2;
                        printf("\n~Returning to staff menu...");
                        Sleep(4000);
                        system("cls");
                        continue;
                    }
                    else{
                        who = 0;
                        printf("\n~Returning to main menu...");
                        Sleep(3000);
                        system("cls");
                        here = menu();
                        continue;
                    }
                }
                break;
           case 8 :
                who = 0;
                printf("\n~Returning to main menu...");
                Sleep(3000);
                system("cls");
                here = menu();
                continue;
           }
            break;
    //....................................choose in member menu
        case 3 :
            switch(memberMenu())
            {
            case 0 :
                puts("\n______________________");
                printf("|1.Member menu\n|2.Main menu\n\n~Select your choice:");
                dis = getch();
                printf("\n");
                if(dis == '1'){
                    here = 3;
                    who = 3;
                    printf("\n~Returning to member menu...");
                    Sleep(4000);
                    system("cls");
                    continue;
                }
                else{
                    who = 0;
                    printf("\n~Returning to main menu...");
                    Sleep(3000);
                    system("cls");
                    here = menu();
                    continue;
                }
                break;
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
               result = memberSetting(head_mem);
               if(result == 0){//was not successful
                    free(head_mem);
                    puts("\n______________________");
                    printf("|1.Member menu\n|2.Main menu\n\n~Select your choice:");
                    dis = getch();
                    printf("\n");
                    if(dis == '1'){
                        here = 3;
                        who = 3;
                        printf("\n~Returning to Member menu...");
                        Sleep(4000);
                        system("cls");
                        continue;
                    }
                    else{
                        who = 0;
                        printf("\n~Returning to Main menu...");
                        Sleep(3000);
                        system("cls");
                        here = menu();
                        continue;
                    }
               }
               else if(result == 1){//changing successful
                    free(head_emp);
                    puts("\n______________________");
                    printf("|1.Member menu\n|2.Account setting\n\n~Select your choice:");
                    dis = getch();
                    printf("\n");
                    if(dis == '1'){
                        here = 3;
                        who = 3;
                        printf("\n~Returning to Member menu...");
                        Sleep(4000);
                        system("cls");
                        continue;
                    }
                    else{
                        who = 3;
                        printf("\n~Returning to setting...");
                        Sleep(3000);
                        system("cls");
                        here = 3;
                        who = 3;
                        continue;
                    }
               }
                break;
            case 6 :
                who = 0;
                printf("\n~Returning to main menu...");
                Sleep(3000);
                system("cls");
                here = menu();
                continue;
            }
            break;
        case 4 ://repeat log in
            who = 0;
            continue;
            break;

        }

    }
}

//                         *ADMIN SECTION*
//..................................................Admin menu
int adminMenu()
{
    char choice[100] , ch ;
    char current[10];
    todaydate(current);
    puts("******/     Welcome Admin    /*******\n");
    printf("~You are in Admin menu             Date: %s\n______________________________________\n" , current);
    puts("|1. New employee registration");
    puts("|2. View the list of staff");
    puts("|3. Remove the employee from the system");
    puts("|4. Reports");
    puts("|5. Logout and return to main menu\n");
    printf("Please enter your choice:");
    scanf(" %s" , choice);
    if(strcmp(choice, ":)")==0)
        return 0;
    if( isdigit(choice[0]) && choice[1]=='\0' && (choice[0]>'0' && choice[0]<'6')){
            ch = choice[0];
    }
    else{
        ch = '\0' ;
    }
        switch(ch)
        {
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '\0' :
            puts("\n~You used invalid characters to choose , Try again!");
            return 0;
            break;
        }
}
//...................................................to add one employee
int addemp()
{
    char temp[50];
    struct employee emp;
    FILE *e ;
    e = fopen(EMPFILE , "a");
    if( e == NULL ){
        puts("\n~Error opening staff file!");
        return 0 ;
    }
    else{
        puts("\n<<<<<< Use dash (-) instead of space( ) >>>>>>\n");
        while(1){
            printf("First name:");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
            if(validname(temp)){
                    strcpy(emp.name , temp);
                    break;
            }
            else{
                puts("\n~Invalid name , Try again");
            }
        }
        //last name
        while(1){
            printf("Last name:");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
            if(validname(temp)){
                strcpy(emp.family , temp);
                break;
            }
            else{
                puts("\n~Invalid name , Try again");
            }
        }
        //ID
        while(1){
            printf("ID number:");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
            if(validID(temp)){
                strcpy(emp.id_emp , temp);
                break;
            }
            else{
                puts("\n~Invalid ID  number , Try again");
            }
        }
        //phone
        while(1){
            printf("Phone number:");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
                //add valid phone
                strncpy(emp.phone , temp , sizeof(emp.phone)-1 );
                break;
        }
        //Email
        while(1){
            printf("E-mail:");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
            if(validemail(temp)){
                strcpy(emp.email , temp);
                break;
            }
            else{
                puts("\n~Invalid Email , Try again");
            }
        }
        //username
        while(1){
            printf("Username:");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
            if(isinfile(temp , EMPFILE)==1){
                puts("\n~This username is already saved , Try again!");
                continue;
            }
            if(validusername(temp)){
                strcpy(emp.username_emp , temp);
                break;
            }
            else{
                puts("\n~Invalid username , Try again");
            }
        }
        //password
        while(1){
            char pass1[20] , pass2[20];
            printf("Password(first time):");
            scanf(" %s" , pass1);
            if(strcmp(pass1 , ":)")==0)
                return 0;
            if(isinfile(pass1 , EMPFILE)==1){
                puts("\n~This password is already saved , Try again!");
                continue;
            }
           else if(validpass(pass1)){
                printf("Password(second time):");
                scanf(" %s" , pass2);
                if(strcmp(pass2 , ":)")==0)
                    return 0;
                if(strcmp(pass1 , pass2) == 0){
                    strcpy(emp.pass_emp , pass1);
                    break;
                }
                else{
                    puts("\n~Password do not match, Try again!");
                    continue;
                }
            }
            else{
                puts("\n~Invalid password , Try again!");
            }
        }
        //join date
        todaydate(emp.join_date_e);
        //write them on file
        fprintf(e  , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" ,emp.username_emp
                 , emp.pass_emp , emp.id_emp , emp.join_date_e , emp.name , emp.family , emp.phone , emp.email );
        puts("\n~Employee added successfully!");
        fclose(e);
        return 1 ;
    }
}
//...................................................new employee
void newEmp()
{
    int num , added , done;
    printf("\n~How many staff you want to add? : ");
    scanf(" %d" , &num);
    for(int i = 0 ; i < num ; i++){
            printf("\n___________________________________");
        printf("\n~Add information(Employee %d of %d):\n" , i+1 , num);
        added = addemp();
        if(!added){
            puts("\n~Failed to add employee!");
            continue;
        }
        else
            done = 1;
    }
    if(done==1){
        puts("\n~All staff added successfully and the join date is today.");
    }
    printf("\n~Press any key to return to admin menu:");
    getche();
    printf("\n\n~Returning to admin menu...");
    Sleep(3000);
    system("cls");
}

//...................................................view staff list
void staffList()
{
    struct employee emp;
    int empcount = 1 ;
    //system cls
    puts("\n****_________  List of staff  __________****");
    puts("______________________________________");
    FILE *f ;
    f = fopen(EMPFILE , "r");
    if(f == NULL){
        printf("The staff file has not found !\nYou will return to admin menu...");
        Sleep(5000);
        system("cls");
        return;
    }
    else{
        while( fscanf(f , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , emp.username_emp , emp.pass_emp
                    ,emp.id_emp , emp.join_date_e , emp.name , emp.family , emp.phone , emp.email)!=EOF ){
            if(validusername(emp.username_emp)){
                //show the list
                printf("|~~Employee No.%d~~\n" , empcount);
                printf("|First name   :  %s\n" , emp.name);
                printf("|Last name    :  %s\n" , emp.family);
                printf("|ID number    :  %s\n" , emp.id_emp);
                printf("|Phone number :  %s\n" , emp.phone);
                printf("|E-mail       :  %s\n" , emp.email);
                printf("|Join date    :  %s\n" , emp.join_date_e);
                printf("|Username     :  %s\n" , emp.username_emp);
                printf("|Password     :  %s\n" , emp.pass_emp);
                puts("______________________________________");
                empcount++ ;
            }
        }
        fclose(f);
        if(empcount == 1)
            printf("No staff data found!");

    }
    printf("Press any key to return to admin menu:");
    getche();
    printf("\n\nReturning to admin menu...");
    Sleep(3000);
    system("cls");
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
    char current[10];
    todaydate(current);
    printf("******/  Welcome  %s  /*******\n\n" , E.username_emp);
    printf("~You are in Staff menu              Date: %s\n_______________________________\n" , current);
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
    if(strcmp(choice , ":)")==0)
        return 0;
    if( isdigit(choice[0]) && choice[1]=='\0' && (choice[0]>'0' && choice[0]<'9')){
        ch = choice[0];
    }
    else{
        ch = '\0' ;
    }
            switch(ch)
            {
            case '1':
                return 1;
                 break;
            case '2':
                return 2;
                break;
            case '3':
                return 3;
                break;
            case '4':
                return 4;
                break;
            case '5':
                return 5;
                break;
            case '6':
                return 6;
                break;
            case '7':
                return 7;
            case '8':
                return 8;
                break;
            case '\0':
                puts("\n~You used invalid characters to choose , Try again!");
                return 0;
                break;
            }
}
//.....................................................new member
int addmem()
{
    char temp[50];
    struct member mem;
    FILE *e ;
    e = fopen(MEMFILE , "a");
    if( e == NULL ){
        puts("\n~Error opening staff file!");
        return 0 ;
    }
    else{
        puts("\n<<<<<< Use dash (-) instead of space( ) >>>>>>\n");
        while(1){
            printf("First name:");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
            if(validname(temp)){
                    strcpy(mem.name , temp);
                    break;
            }
            else{
                puts("\n~Invalid name , Try again");
            }
        }
        //last name
        while(1){
            printf("Last name:");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
            if(validname(temp)){
                strcpy(mem.family , temp);
                break;
            }
            else{
                puts("\n~Invalid name , Try again");
            }
        }
        //ID
        while(1){
            printf("ID number:");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
            if(validID(temp)){
                strcpy(mem.id_mem , temp);
                break;
            }
            else{
                puts("\n~Invalid ID  number , Try again");
            }
        }
        //phone
        while(1){
            printf("Phone number:09");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
            if(validphone(temp)){
                strcpy(mem.phone, temp);
                break;
            }
            else{
                puts("\n~Invalid Phone number , Try again");
            }
        }
        //Email
        while(1){
            printf("E-mail:");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
            if(validemail(temp)){
                strcpy(mem.email , temp);
                break;
            }
            else{
                puts("\n~Invalid Email , Try again");
            }
        }
        //username
        while(1){
            printf("Username:");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
            if(isinfile(temp , MEMFILE)==1){
                puts("\n~This username is already saved , Try again!");
                continue;
            }
            if(validusername(temp)){
                strcpy(mem.username_mem , temp);
                break;
            }
            else{
                puts("\n~Invalid username , Try again");
            }
        }
        //password
        while(1){
            char pass1[20] , pass2[20];
            printf("Password(first time):");
            scanf(" %s" , pass1);
            if(strcmp(pass1 , ":)")==0)
                return 0;
            if(isinfile(pass1 , MEMFILE)==1){
                puts("\n~This password is already saved , Try again!");
                continue;
            }
           else if(validpass(pass1)){
                printf("Password(second time):");
                scanf(" %s" , pass2);
                if(strcmp(pass2 , ":)")==0)
                return 0;
                if(strcmp(pass1 , pass2) == 0){
                    strcpy(mem.pass_mem , pass1);
                    break;
                }
                else{
                    puts("\n~Password do not match, Try again!");
                    continue;
                }
            }
            else{
                puts("\n~Invalid password , Try again!");
            }
        }
        //join date
        todaydate(mem.join_date_m);
        //write them on file
        fprintf(e  , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" ,mem.username_mem
                 , mem.pass_mem , mem.id_mem, mem.join_date_m , mem.name , mem.family , mem.phone, mem.email );
        fclose(e);
        puts("\n~Member added successfully!");
        return 1 ;
    }
}
//...................................................new employee
void newMem()
{
    int num , added , done;
    printf("\n~How many members you want to add? : ");
    scanf(" %d" , &num);
    for(int i = 0 ; i < num ; i++){
        printf("\n___________________________________");
        printf("\n~Add information(Member %d of %d):\n" , i+1 , num);
        added = addmem();
        if(!added){
            puts("\n~Failed to add member!");
            continue;
        }
        else
            done = 1 ;
    }
    if(done==1){
        puts("\n~All members added successfully by the join date of today.");
    }
    printf("\n~Returning to staff menu...");
    Sleep(5000);
    system("cls");
}
//.....................................................revival membership
void revival()
{


}
//......................................................general list of every member
void generalList()
{
    struct member mem ;
    int memcount = 1 ;
    printf("\n****___________  List of Members  _________****\n");
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
        while(fscanf( f , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , mem.username_mem , mem.pass_mem
                     , mem.id_mem , mem.join_date_m , mem.name , mem.family , mem.phone , mem.email) != EOF){
            if(validusername(mem.username_mem)){
            //show the list
                printf("|~~Member No.%d~~\n" , memcount);
                printf("|First name   :  %s\n" , mem.name);
                printf("|Last name    :  %s\n" , mem.family);
                printf("|ID number    :  %s\n" , mem.id_mem);
                printf("|Phone number :  %s\n" , mem.phone);
                printf("|E-mail       :  %s\n" , mem.email);
                printf("|Join date    :  %s\n" , mem.join_date_m);
                printf("|Username     :  %s\n" , mem.username_mem);
                printf("|Password     :  %s\n" , mem.pass_mem);
                puts("______________________________________");\
                memcount++ ;
            }
        }
        if(memcount == 1)
                printf("No staff data found!");
        }
        fclose(f);
        printf("Press any key to return to staff menu:");
        getche();
        printf("\n\nReturning to staff menu...");
        Sleep(5000);
        system("cls");
}


//......................................................remove members
void rmMem()
{

}
//......................................................books registering
int addBook()
{
    char temp[50];
    struct book b ;
    FILE *f;
    f = fopen(GBOOKFILE , "a");
    if(f == NULL){
        puts("\nError opening the file of general books");
        return 0;
    }
    else{
        puts("\n<<<<<< Use dash (-) instead of space( ) >>>>>>\n");
        puts("(if there is any number in names , use it alphabetical like 'one')\n");
        //name of the book
        while(1){
            printf("Name of the book :");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
            if(validname(temp)==1){
                strcpy( b.name , temp);
                break;
            }
            else{
                puts("\n~Invalid name for the book , Try again!");
            }
        }
        //writer
        while(1){
            printf("Name of the author :");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
            if(validname(temp)==1){
                strcpy( b.writer , temp);
                break;
            }
            else{
                puts("\n~Invalid name for the author , Try again!");
            }
        }
        //publication
        while(1){
            printf("The publication :");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
            if(validname(temp)==1){
                strcpy( b.publication , temp);
                break;
            }
            else{
                puts("\n~Invalid name for the publication , Try again!");
            }
        }
        //year of publication
        while(1){
            int alldigit = 1 ;
            printf("Year of publication (yyyy):");
            scanf(" %s" , temp);
            if(strcmp(temp , ":)")==0)
                return 0;
            if(strlen(temp) != 4){
                puts("\n~It must be only 4 digits for the year!");
                continue;
            }

            for(int i = 0 ; i < 4 ; i++){
                if(!isdigit(temp[i])){
                    alldigit = 0;
                    break;
                }
            }
            if(!alldigit){
                puts("\n~Use only digits , Try again!");
                continue;
            }
            else if(strlen(temp)==4 && alldigit==1){
                strcpy( b.year , temp);
                break;
            }
        }

        //random id number for book
        srand(time(NULL));
        int id = rand();
        sprintf(b.id_book , "%d" , id);

        //registration date
        todaydate(b.reg_date);

        //to save info in file
        fprintf(f, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n", b.id_book, b.name, b.writer,
                  b.publication, b.year, b.reg_date, E.username_emp);
        fclose(f);
        puts("\n~All books added successfully!\n");
        printf("~Returning to staff menu...");
        Sleep(4000);
        system("cls");
        return 1 ;

    }
}
void bookRegister()
{
    int num ;
    int added ;
    printf("\n~How many books you want to add ? :");
    scanf(" %d" , &num);
    for(int i = 0 ; i < num ; i++){
        puts("\n_______________________________________");
        printf("~Add information (book %d of %d):\n" , i+1 , num);
        added = addBook();
        if(!added){
            puts("\n~Failed to add the book!");
            continue;
        }
    }
}
//.......................................................report for employees
void report_emp()
{

}
//.........................................................staff account settings
int setting_emp(struct employee *head)
{
    struct employee *temp;
    temp = head ;
    char ch ;
    char input[50] , pass1[50] , pass2[50];
    puts("\n*****__________  Account setting  _________*****");
    puts("_______________________________");
    printf("|1. Password\n");
    printf("|2. Phone number\n");
    printf("|3. Email\n");
    printf("|4. Exit");
    printf("\n\n~Please enter your choice :");
    ch = getche();
    switch(ch)
    {
    case '1':
        printf("\n\n~Changing password...");
        Sleep(2000);
        puts("\n_____________________________________");
        while(1){
            //password checks and a way to exit
            printf("Enter your new password(first time) : ");
            scanf(" %s" , pass1);
            if(strcmp(pass1 , ":)")==0)
                return 0;

            if(validpass(pass1)){
                printf("\nEnter your new password again(second time) : ");
                scanf(" %s" , pass2);
                if(strcmp(pass2 , ":)")==0)
                    return 0;

                if(validpass(pass2)){
                    if(strcmp(pass1 , pass2 )==0){
                        //looking for username to change the pass word
                        temp = head ;
                        while(temp != NULL){
                            if(strcmp(temp->username_emp , E.username_emp)==0){
                                strcpy(temp->pass_emp , pass1);
                                //save the changes and write it in a new file
                                savechanges_emp(head);
                                puts("\n~Your password has been changed successfully.");
                                Sleep(2000);
                                return 1;
                            }
                            temp = temp->link ;
                        }
                    }
                    else{
                        puts("\n~Passwords do not match , try again!");
                        continue;
                    }
                }
                else
                    puts("\n~Invalid password!");
            }
            else
                puts("\n~Invalid password!");
        }
        break;
    case '2':
        printf("\n\n~Changing phone number...");
        Sleep(2000);
        puts("_______________________________________");
        while(1){
            printf("\nEnter your new phone number : ");
            scanf(" %s" , input);
            if(strcmp(input , ":)")==0)
                return 0;

            if(validphone(input)){
                temp = head ;//for repeating the cycle
                while(temp != NULL){
                    if(strcmp(temp->username_emp , E.username_emp)==0){
                        strcpy(temp->phone , input);
                        //save the changes and write it in a new file
                        savechanges_emp(head);
                        puts("\n~Your phone number has been changed successfully.");
                        Sleep(2000);
                        return 1;
                    }
                    temp = temp->link ;
                }
            }
            else
                puts("\n~Invalid phone number!");
        }
        break;
    case '3':
        printf("\n\nChanging Email address...");
        Sleep(2000);
        puts("____________________________________");
        while(1){
            printf("\nEnter your new E-mail address : ");
            scanf(" %s" , input);
            if(strcmp(input , ":)")==0)
                return 0;

            if(validemail(input)){
                temp = head ;//for repeating the cycle
                while(temp != NULL){
                    if(strcmp(temp->username_emp , E.username_emp)==0){
                        strcpy(temp->email , input);
                        //save the changes and write it in a new file
                        savechanges_emp(head);
                        puts("\n~Your Email address has been successfully changed!");
                        Sleep(2000);
                        return 1;
                    }
                    temp = temp->link ;
                }
            }
            else
                puts("\n~Invalid email!");
        }
        break;
    case '4':
        return 0;
    }
    return 0;

}
//                              *MEMBER SECTION*
//.....................................................Member menu
int memberMenu()
{
    char choice[100] , ch ;
    char current[10];
    todaydate(current);
    printf("\n*******/   Welcome    %s   /*******\n\n" , M.username_mem);
    printf("~You are in Member menu             Date: %s\n_____________________________\n" , current);
    puts("|1. Borrow new books");
    puts("|2. Write-in returns");
    puts("|3. My books");
    puts("|4. Available books in library");
    puts("|5. Account setting");
    puts("|6. Logout and return to main menu");
    printf("\nPlease enter your choice:");
    scanf(" %s" , &choice);
    if( isdigit(choice[0]) && choice[1]=='\0' && (choice[0]>'0' && choice[0]<'7')){
        ch = choice[0];
    }
    else{
        ch = '\0';
    }
        switch(ch)
        {
        case '1' :
            return 1;
            break;
        case '2' :
            return 2;
            break;
        case '3' :
            return 3;
            break;
        case '4' :
            return 4;
            break;
        case '5' :
            return 5;
            break;
        case '6' :
            return 6;
            break;
        case '\0':
            puts("\n~You used invalid characters to choose , Try again!");
            return 0;
            break;
        }
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
    struct book b ;
    int bookcount = 1 ;
    int line = 0 ;//how many books you have
    FILE *f ;
    f = fopen(GBOOKFILE , "r");
    if(f == NULL){
        printf("Could not read the file");
    }
    else{
        puts("\n****____________List of available books___________****");
        while(fscanf(f , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n" ,b.id_book , b.name , b.writer ,
                    b.publication , b.year , b.reg_date , b.reg_user ) != EOF){
            if(validname(b.name)){
                printf("\n____________________________________");
                printf("\n\n~Book number %d ~" , bookcount);
                printf("____________________");
                printf("\n|Book ID              : %s" , b.id_book);
                printf("\n|Book name            : %s" , b.name);
                printf("\n|The author           : %s" , b.writer);
                printf("\n|The publication      : %s" , b.publication);
                printf("\n|Year of publication  : %s" , b.year);
                printf("\n|Date of registration : %s" , b.reg_date);
                printf("\n|Saved by (Username)  : %s" , b.reg_user);
                bookcount++ ;
            }
        }
        if(bookcount==1){
            puts("\n~Could not found any books!");
        }
        printf("\n____________________________________");
        fclose(f);
        printf("\n\n~Press any key to return to Member menu:");
        getche();
        printf("\n\n~Returning to Member menu...");
        Sleep(4000);
    }
}
//...........................................................setting for member's account
int memberSetting(struct member *head)
{
    struct member *temp;
    temp = head ;
    char ch ;
    char input[50] , pass1[50] , pass2[50];
    puts("\n*****__________  Account setting  _________*****");
    puts("_______________________________");
    printf("|1. Password\n");
    printf("|2. Phone number\n");
    printf("|3. Email\n");
    printf("|4. Exit");
    printf("\n\n~Please enter your choice :");
    ch = getche();
    switch(ch)
    {
    case '1':
        printf("\n\n~Changing password...");
        Sleep(2000);
        puts("\n_____________________________________");
        while(1){
            //password checks and a way to exit
            printf("Enter your new password(first time) : ");
            scanf(" %s" , pass1);
            if(strcmp(pass1 , ":)")==0)
                return 0;

            if(validpass(pass1)){
                printf("\nEnter your new password again(second time) : ");
                scanf(" %s" , pass2);
                if(strcmp(pass2 , ":)")==0)
                    return 0;

                if(validpass(pass2)){
                    if(strcmp(pass1 , pass2 )==0){
                        //looking for username to change the pass word
                        temp = head ;
                        while(temp != NULL){
                            if(strcmp(temp->username_mem , M.username_mem)==0){
                                strcpy(temp->pass_mem, pass1);
                                //save the changes and write it in a new file
                                memberSavechanges(head);
                                puts("\n~Your password has been changed successfully.");
                                Sleep(2000);
                                return 1;
                            }
                            temp = temp->link ;
                        }
                    }
                    else{
                        puts("\n~Passwords do not match , try again!");
                        continue;
                    }
                }
                else
                    puts("\n~Invalid password!");
            }
            else
                puts("\n~Invalid password!");
        }
        break;
    case '2':
        printf("\n\n~Changing phone number...");
        Sleep(2000);
        puts("_______________________________________");
        while(1){
            printf("\nEnter your new phone number : ");
            scanf(" %s" , input);
            if(strcmp(input , ":)")==0)
                return 0;

            if(validphone(input)){
                temp = head ;//for repeating the cycle
                while(temp != NULL){
                    if(strcmp(temp->username_mem, M.username_mem)==0){
                        strcpy(temp->phone , input);
                        //save the changes and write it in a new file
                        memberSavechanges(head);
                        puts("\n~Your phone number has been changed successfully.");
                        Sleep(2000);
                        return 1;
                    }
                    temp = temp->link ;
                }
            }
            else
                puts("\n~Invalid phone number!");
        }
        break;
    case '3':
        printf("\n\nChanging Email address...");
        Sleep(2000);
        puts("____________________________________");
        while(1){
            printf("\nEnter your new E-mail address : ");
            scanf(" %s" , input);
            if(strcmp(input , ":)")==0)
                return 0;

            if(validemail(input)){
                temp = head ;//for repeating the cycle
                while(temp != NULL){
                    if(strcmp(temp->username_mem , M.username_mem)==0){
                        strcpy(temp->email , input);
                        //save the changes and write it in a new file
                        memberSavechanges(head);
                        puts("\n~Your Email address has been successfully changed!");
                        Sleep(2000);
                        return 1;
                    }
                    temp = temp->link ;
                }
            }
            else
                puts("\n~Invalid email!");
        }
        break;
    case '4':
        return 0;
    }
    return 0;

}
//                               *GENERAL SECTION*
//...................................................Main menu management
int menu()
{
    char choice[100];
    char ch ;
    char current[10];
    todaydate(current);
    while(1){
        puts("*******/   Welcome to PeanutZee Library   /*******\n");
        printf("~You are in : main menu             Date: %s\n____________________\n"  , current);
        puts("|1. Admin Login");
        puts("|2. Staff Login");
        puts("|3. Member Login");
        puts("|4. Exit\n");
        printf("Please enter your choice:");
        scanf(" %s" , &choice);
        if( isdigit(choice[0]) && choice[1]=='\0' && (choice[0]>'0' && choice[0]<'5')){
            ch = choice[0];
        }
        else{
            ch = '\0' ;
        }
           switch (ch)
           {
           case '1' :
                    return 1;
                    break;
           case '2' :
                    return 2;
                    break;
           case '3' :
                    return 3;
                    break;
           case '4' :
                    return 4;
                    break;
           case '\0' :
                    printf("\n~You used invalid characters to choose ,Press any key to Try again!");
                    getch();
                    system("cls");
                    return 0;
                    break;
            }
    }

}
//......................................................Repeat
void repeat()
{
    printf("\nEnter any key:");
    getche();
    printf("\n");
}
//.....................................................exit
int exitpro()
{
    char x ;
    printf("~Are you sure you want to exit?   | 1.Yes  / 2.No | : ");
    x = getche();
    printf("\n");
    if( x == '1'){
        printf("Exiting the program....");
        Sleep(3000);
        system("cls");
        exit(1);
    }
    else if(x == '2'){
        printf("Returning to recent menu....");
        Sleep(3000);
        system("cls");
        return 1;
    }
}
//......................................................log in
int Login(int selection)//input for user selection
{
    puts("\n____________________");
    printf("Log in process... \n");
    char user_input[USERNAME];
    char pass_input[PASSWORD];
    char ch ;
    char dis;
    int i , chance = 3;//the numbers to try your password chance
    int found ;//check for a founded user
    int usercheck;
    //excited usernames and passwords reads from files
    char user_file[USERNAME];
    char pass_file[PASSWORD];
    printf("Username:");
    scanf(" %s" , user_input);
    if(strcmp(user_input , ":)")==0)
        return 0;
    usercheck = validusername(user_input);
    if(usercheck == 0){
        puts("\n______________________");
        printf("|1.Start Login again\n|2.Return to main menu\n\n~Select your choice:");
        dis = getche();
        printf("\n");
        if(dis == '1')
            return 4 ;
        else
            return 0 ;
    }

    else{
    //check the input username character
    while(selection == 1){
        if(strcmp(user_input , ADMIN_USERNAME) == 0){
            printf("Password:");//add stars to avoid showing password
            while(chance > 0){
                hidepass(pass_input);//hide on screen
                if(strcmp(pass_input , ADMIN_PASS) == 0){
                    printf("\n\n~Login successfully as %s~\n" , ADMIN_USERNAME);
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
                        printf("\nToo many wrong passwords!\n_____YOU ARE NOT ALLOWED____\n");
                        printf("\n~After 5 minutes , you can try log in again...");
                        Sleep(300000);
                        return 4;
                    }
                }
            }
        }else{//if it was not admin
            puts("Wrong username for admin!");
            puts("\n______________________");
            printf("|1.Start Login again\n|2.Return to main menu\n\n~Select your choice:");
            dis = getche();
            printf("\n");
            if(dis == '1')
                return 4 ;
           else
                return 0 ;
        }
    }

    while(selection == 2){
        FILE *s , *m ;
        s = fopen(EMPFILE , "r");
        if(s == NULL){
            printf("The staff file has not found!");
            puts("\n______________________");
            printf("|1.Start Login again\n|2.Return to main menu\n\n~Select your choice:");
            dis = getche();
            printf("\n");
            if(dis == '1')
                return 4 ;
           else
                return 0 ;
        }
        else{
        //check for staff log in
        found = 0 ;
            while(feof(s)==0){
                fgets(user_file ,USERNAME , s);
                user_file[strcspn(user_file, "\n")] = '\0';

                if(strcmp(user_file , user_input) == 0){
                    chance = 3 ;//limit for password chances
                    strcpy(E.username_emp , user_file);
                    printf("Password:");
                    while(chance > 0){   //.......................Issue in repeating password
                        hidepass(pass_input);
                        fgets(pass_file , PASSWORD , s);
                        pass_file[strcspn(pass_file, "\n")] = '\0';

                        if(strcmp(pass_file , pass_input) == 0){
                            printf("\n\n~Login successfully as (%s)\n" , E.username_emp);
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
                                printf("\nToo many wrong passwords!\n___YOU ARE NOT ALLOWED___\n");
                                printf("\n~After 5 minutes , you can try log in again...");
                                fclose(s);
                                Sleep(300000);
                                return 4;
                            }
                        }
                    }

                }
            }
            if(found == 0){
                printf("Employee not found!\n");
                puts("\n______________________");
                printf("|1.Start Login again\n|2.Return to main menu\n\n~Select your choice:");
                dis = getch();
                if(dis == '1')
                    return 4 ;
                else
                    return 0 ;
            }
        }
    }
    while(selection == 3){
        //check for member log in
        FILE *m ;
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
                strcpy(M.username_mem , user_file);
                printf("Password:");
                while(chance > 0){
                hidepass(pass_input);
                fgets(pass_file , PASSWORD , m);
                pass_file[strcspn(pass_file, "\n")] = '\0';

                    if(strcmp(pass_file , pass_input)==0){
                        printf("\n\n~Login successfully as (%s)\n" , M.username_mem);
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
                            printf("\nToo many wrong passwords!\n_____YOU ARE NOT ALLOWED____\n");
                            printf("\n~After 5 minutes , you can try log in again...");
                            fclose(m);
                            Sleep(300000);
                            return 4;
                        }
                    }
                }

            }else
               found = 0;
        }
        if(found == 0){
            printf("Member not found!\n");
            puts("\n______________________");
            printf("|1.Start Login again\n|2.Return to main menu\n\n~Select your choice:");
            dis = getch();
            if(dis == '1')
                return 4 ;
           else
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
//............................................check validity
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
int validpass(char pass[20])
{
    printf("pass");//1 for yes and 0 for no
}
int validphone(char phone[11])
{
    int len = strlen(phone);//size of phone number without 09
    int count = 0 ;
    if( len != 11 ){
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
        if(count == 11)//all of the characters are valid
            return 1 ;
    }

}
int validname(char name[20])
{
    int len = strlen(name);
    int count = 0 ;
    if(len < 4 || len > 20 ){
        printf("\n~Your input must be between 4 and 20 characters!\n");
        return 0 ;
    }
    else{
        for(int i = 0 ; i < len ; i++){
            if( !(isalpha(name[i]) || name[i]=='-')){
                printf("\n~Use only alphabetical characters!\n");
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
int validdate(char date[10])
{
    if(strlen(date) != 10 || date[2] != '/' || date[5] != '/'){
        puts("\n~Use the suggested form of date");
        return 0;
    }
    else{
        for(int i = 0 ; i < 10 ; i++){
            if(i==2 || i==5)
                continue;
            if( !isdigit(date[i]) ){
                puts("\n~Use digits and '/' only");
                return 0;
            }
        }
    }
    //valid
    return 1;
}
int validemail(char email[20])
{
    printf("email");
}

//.........................existing
int isinfile(char input[100] , char file[100])
{
    char subject[100];
    int found=0 ;
    FILE *f;
    f = fopen( file , "r");
    if(f == NULL){
        puts("\n~Could not found the file");
        return 0;
    }
    else{
        while(fgets(subject , sizeof(subject) , f)!= NULL){
          if(strstr(subject , input) != NULL){
            found = 1;
            break;
          }
        }
        if(found == 1)
            return 1;
        else
            return 0;
    }
}
void todaydate(char *current)
{
    time_t now = time(NULL);//get the time by secounds
    struct tm *local = localtime(&now);//convert into local time
    //add 1900 to get real number of year
    sprintf(current , "%02d/%02d/%d" , local->tm_mday , local->tm_mon + 1 , local->tm_year+1900);//(dd/mm/yyyy)
}
//......................................................Functions to use linked list
//...................to create a linked list with the info of a file and return the pointer
struct employee* CallFileLinkEmp()
{
    //create the first node
    struct employee *start = NULL;
    struct employee *temp = NULL;
    struct employee *fresh = NULL ;
    //open file
    FILE *f;
    f = fopen(EMPFILE , "r");
    if(f == NULL){
        puts("\n~File not found!");
        return NULL;
    }
    else{
        start = malloc(sizeof(struct employee));
        if(start == NULL){
            puts("\n~memory error!");
            fclose(f);
            return NULL;
        }
        temp = start ;
        temp->link = NULL ;
        //read the info from file and fill the first node
        while(fscanf(f , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , temp->username_emp , temp->pass_emp
                    ,temp->id_emp , temp->join_date_e , temp->name , temp->family , temp->phone , temp->email) != EOF ){
                //add a new node
                fresh = malloc(sizeof(struct employee));
                if(fresh == NULL){
                    puts("\n~memory error!");
                    fclose(f);
                    return NULL;
                }
                temp->link = fresh ;
                fresh->link = NULL;
                temp = fresh ;
        }
        if(temp == fresh){//delete the last node
            free(temp);
            temp = NULL;
        }
        fclose(f);
        return start;
    }
}
struct member* CallFileLinkMem()
{
    //create the first node
    struct member *start = NULL;
    struct member *temp = NULL;
    struct member *fresh = NULL ;
    //open file
    FILE *f;
    f = fopen(MEMFILE , "r");
    if(f == NULL){
        puts("\n~File not found!");
        return NULL;
    }
    else{
        start = malloc(sizeof(struct member));
        if(start == NULL){
            puts("\n~memory error!");
            fclose(f);
            return NULL;
        }
        temp = start ;
        temp->link = NULL ;
        //read the info from file and fill the first node
        while(fscanf(f , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , temp->username_mem , temp->pass_mem
                    ,temp->id_mem , temp->join_date_m , temp->name , temp->family , temp->phone , temp->email) != EOF ){
                //add a new node
                fresh = malloc(sizeof(struct member));
                if(fresh == NULL){
                    puts("\n~memory error!");
                    fclose(f);
                    return NULL;
                }
                temp->link = fresh ;
                fresh->link = NULL;
                temp = fresh ;
        }
        if(temp == fresh){//delete the last node
            free(temp);
            temp = NULL;
        }
        fclose(f);
        return start;
    }
}
//.......................................to save changes in staff file
void savechanges_emp(struct employee *head)
{
    struct employee *temp = head ;
    FILE *f ;
    f = fopen(EMPFILE , "w");
    if(f == NULL){
        printf("\n~File not found!");
        return;
    }
    else{
        while(temp != NULL){
            fprintf(f , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , temp->username_emp , temp->pass_emp
                    ,temp->id_emp , temp->join_date_e , temp->name , temp->family , temp->phone , temp->email);
            //next employee
            temp = temp->link ;
        }
    }

    fclose(f);
    free(head);
}
void memberSavechanges(struct member *head)
{
    struct member *temp = head ;
    FILE *f ;
    f = fopen(MEMFILE , "w");
    if(f == NULL){
        printf("\n~File not found!");
        return;
    }
    else{
        while(temp != NULL){
            fprintf(f , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , temp->username_mem , temp->pass_mem
                    ,temp->id_mem , temp->join_date_m , temp->name , temp->family , temp->phone , temp->email);
            //next member
            temp = temp->link ;
        }
    }

    fclose(f);
    free(head);
}
