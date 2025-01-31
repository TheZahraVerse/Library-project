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
#define BORROWED "borrowedbooks.txt"
#define ARCSTAFF "Staffarchive.txt"
#define ARCMEMBER "Membersarchive.txt"
//..........................................Functions
//Linked list functions
struct employee* CallFileLinkEmp();
struct member* CallFileLinkMem();
struct book* CallFileLinkBook();
//General Functions
void manage(int here);
int menu();//done
int Login();//solved
void hidepass(char pass[PASSWORD]);//done
int validusername(char user[10]);//done
int validphone(char phone[10]);//done
int validname(char name[20]);//done
int validID(char ID[10]);//done
int validemail(char email[20]);//done
int validdate(char date[20]);//done
int isinfile(char input[100] , char file[100]);//done
void todaydate(char *current);//done
void oneyear(char *date);//done
int exitpro();//done
//Admin Functions
int adminMenu();//done
void newEmp();//done
void staffList();//done
void rmEmp(struct employee *head);//..................................................
void report_ad();//.............................................
//staff Functions
int staffMenu();//done
void newMem();//done
int revival(struct member *head);//.............................................
void generalList();//done
void rmMem(struct member *head);//....................................................
void bookRegister();//done
void report_emp();//............................................
int setting_emp(struct employee *head);//.........................................
void savechangesEmp(struct employee *head);
//Member Functions
int memberMenu();//done
void memNewBook(struct book *head);//done
void memReturn();//..................................
void memAllBooks(struct book *general);//done
void availBooks();//done
int memberSetting(struct member *head);//................
void savechangeMem(struct member *head);
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
    char email[60];
    char status[30]; // to know what her position is
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
    char validate[15];
    char phone[20];
    char id_mem[20];
    char email[60];
    char status[30]; //condition for each member to know the position
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
    char status[30];//condition of a book
    struct book *link ;
};
struct book B ;
//.....................................free the memory allocations
void freelistEmp(struct employee *head)
{
    struct employee *temp ;
    while(head != NULL){
        temp = head ;
        head = head->link ;
        free(temp);
    }
}
void freelistMem(struct member *head)
{
    struct member *temp ;
    while(head != NULL){
        temp = head;
        head = head->link;
        free(temp);
    }
}
void freelistBook(struct book *head)
{
    struct book *temp ;
    while(head != NULL){
        temp = head;
        head = head->link;
        free(temp);
    }
}
//**********************************...Main...*****************************************
void main()
{
    int here ;
    int back ;
    int who =  0;
    int result ;
    char dis ;
    int run = 1 ;
    struct employee *head_emp = NULL ;
    struct member *head_mem = NULL ;
    struct book *head_b = NULL;
    //first try
    here = menu();
    do{
        //free the memory allocation
        freelistEmp(head_emp);
        freelistMem(head_mem);
        freelistBook(head_b);
        //create the linked list of files
        head_emp = CallFileLinkEmp();
        head_mem = CallFileLinkMem();
        head_b = CallFileLinkBook();

        //the choices of main menu
        switch(here)
        {
        case 0 :
            here = menu();
            continue;
        case 1 :
            if(who == 0)
                who = Login(here);
            else
                who = 1;
            break;
        case 2 :
            if(who == 0)
                who = Login(here);
            else
                who = 2;
            break;
        case 3 :
            if(who == 0)
                who = Login(here);
            else
                who = 3;
            break;
        case 4 :
            back = exitpro();
            if(back != 1)
                run = 0;
            break;
        }
        //the choices between characters
        switch(who)
        {
        case 0 :
            here = menu();
            continue;
        //selection of admin
        case 1 :
            switch(adminMenu())
            {
            //main menu
            case 0 :
                who = 0;
                here = menu();
                break;
            //other options
            case 1 :
                newEmp();
                break;
            case 2 :
                staffList();
                break;
            case 3 :
                rmEmp(head_emp);
                break;
            case 4 :
                report_ad();
                break;
            //main menu
            case 5 :
                who = 0;
                break;
            }
            break;
        //selection of staff
        case 2 :
            switch(staffMenu())
            {
            //main menu
                case 0 :
                    who = 0;
                    break;
            //other choices
                case 1 :
                    newMem();
                    break;
                case 2 :
                    result = revival(head_mem);
                    if(result == 0)
                        who = 2;
                    else
                        who = 0;
                    break;
                case 3 :
                    generalList();
                    break;
                case 4 :
                    rmMem(head_mem);
                    break;
                case 5 :
                    bookRegister();
                    break;
                case 6 :
                    report_emp();
                    break;
                case 7 :
                    result = setting_emp(head_emp);
                    if(result == 0)
                        who = 2;
                    else
                        who = 0;
                    break;
                //main menu
                case 8 :
                    who = 0;
                    break;
            }
            break;
        //selection of members
        case 3 :
            switch(memberMenu())
            {
                //main menu
            case 0:
                who = 0;
                break;
            case 1 :
                memNewBook(head_b);
                break;
            case 2 :
                memReturn();
                break;
            case 3 :
                memAllBooks(head_b);
                break;
            case 4 :
                availBooks();
                break;
            case 5 :
                result = memberSetting(head_mem);
                if(result == 0)
                    who = 3;
                else
                    who = 0;
                break;
            case 6 :
                who = 0;
                break;
            }
            break;
        //return to main menu
        case 4 :
            who = 0;
            break;
        }
    }while(run==1);
    //free the memory allocation
    freelistEmp(head_emp);
    freelistMem(head_mem);
}
//                         *ADMIN SECTION*
//..................................................Admin menu
int adminMenu()
{
    char choice[100] , ch ;
    char current[10];
    todaydate(current);
    puts("\n\033[34m******/     Welcome Admin    /*******\033[0m\n");
    printf("\033[32m~You are in Admin menu             Date: %s\033[0m\n______________________________________\n" , current);
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
        //define the condition
        strcpy(emp.status , "Active");
        //write them on file
        fprintf(e  , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" ,emp.username_emp
                 , emp.pass_emp , emp.id_emp , emp.join_date_e , emp.name , emp.family , emp.phone , emp.email , emp.status);
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
    int check ;
    //system cls
    puts("\n\033[34m****_________  List of staff  __________****");
    puts("______________________________________\033[0m");
    FILE *f ;
    f = fopen(EMPFILE , "r");
    if(f == NULL){
        printf("The staff file has not found !\nYou will return to admin menu...");
        Sleep(5000);
        system("cls");
        return;
    }
    else{
        while( fscanf(f , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , emp.username_emp , emp.pass_emp
                    ,emp.id_emp , emp.join_date_e , emp.name , emp.family , emp.phone , emp.email , emp.status)!=EOF ){
            if(validusername(emp.username_emp)){
                //check the activation , 1 for yes , 0 for no
                check = isinfile(emp.username_emp , ARCSTAFF);
                if(check == 1){
                    strcpy(emp.status , "Inactive");
                }
                else{
                    strcpy(emp.status , "Active");
                }
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
                printf("|Employee status : %s\n" , emp.status);
                puts("\033[34m______________________________________\033[0m");
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
void rmEmp(struct employee *head)
{
    struct employee *temp = head ;
    struct employee*back = NULL;
    struct employee copy ;
    char input[20];
    int done = 0 ;
    printf("\n~Removing process...");
    Sleep(2000);
    printf("\n~Please enter the username of employee you want to remove : ");
    scanf(" %s" , input);
    if(strcmp(input , ":)")==0)
        return ;
    if(validusername(input)){
            //open file to add info to archived file
            FILE *f ;
            f = fopen(ARCSTAFF , "a");
            if(f == NULL){
                puts("\nCould not open the file!");
                return ;
            }
            else{
                //remove if the subject is the first node
                if(temp != NULL && strcmp(temp->username_emp , input)==0){
                    //to copy the whole structure in copy employee type
                    memcpy(&copy , temp , sizeof(struct employee));
                    //save the head after removing
                    head->link = temp->link;
                    //add info to another archived file
                    fprintf(f  , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" ,copy.username_emp
                        ,copy.pass_emp , copy.id_emp , copy.join_date_e , copy.name , copy.family , copy.phone , copy.email , copy.status);
                    //delete the node
                    free(temp);
                    fclose(f);
                    savechangesEmp(head);//write the file again
                    puts("\n~Employee has been removed successfully!\n(You can find the info in archive file of staff)");
                    Sleep(4000);
                    return ;
                }
            //remove if the subject is in the middle of linked list or at the end
            while(temp != NULL){
                back = temp ;
                temp = temp->link;
                if(temp != NULL && strcmp(temp->username_emp , input)==0){
                        //disconnect the node
                        back->link = temp->link;
                        //to copy the whole structure in copy employee type
                        memcpy(&copy , temp , sizeof(struct employee));
                        //add info to another archived file
                        fprintf(f  , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" ,copy.username_emp
                            ,copy.pass_emp , copy.id_emp , copy.join_date_e , copy.name , copy.family , copy.phone , copy.email, copy.status);
                        //delete the node
                        free(temp);
                        fclose(f);
                        savechangesEmp(head);//write the file again
                        puts("\n~Employee has been removed successfully!\n(You can find the info in archive file of staff)");
                        Sleep(4000);
                        return ;
                }

            }
        }
    fclose(f);
    }
    else{
        puts("\n~Invalid input!");
        return;
    }
    puts("\n~Employee not found!");
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
    printf("\n\033[34m******/  Welcome  %s  /*******\033[0m\n\n" , E.username_emp);
    printf("\033[32m~You are in Staff menu              Date: %s\033[0m\n_______________________________\n" , current);
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
                puts("\n\033[31m~You used invalid characters to choose , Try again!\033[0m");
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
            printf("Phone number:");
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
        //add revival
        char newdate[15];
        strcpy(newdate , mem.join_date_m);
        oneyear(newdate);
        strcpy(mem.validate , newdate );
        //add condition
        strcpy(mem.status , "Active");
        //write them on file
        fprintf(e  , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" ,mem.username_mem
                 , mem.pass_mem , mem.id_mem, mem.join_date_m , mem.validate , mem.name , mem.family , mem.phone, mem.email, mem.status);
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
//.................................Update the date for 1 more year
void oneyear(char *date)
{
    int year , month , day;
    //get amounts of a date array
    sscanf(date , "%d/%d/%d" , &day , &month , &year);
    //one more year
    year = year + 1;
    sprintf(date , "%02d/%02d/%d" , day , month , year);
}
int revival(struct member *head)
{
    struct member *temp = head ;
    char input[20];
    char origindate[15];
    printf("\n~Revival member process...");
    Sleep(3000);
    printf("\n\n~Enter the username of your desired member : ");
    scanf(" %s" , input);
    if(strcmp(input , ":)")==0)
        return 0 ;
    if(validusername(input)){
        printf("\nWait for the process...");
        Sleep(2000);
        while(temp != NULL){
            if(strcmp(temp->username_mem , input)==0){
                oneyear(temp->validate);
                Sleep(4000);
                savechangeMem(head);
                puts("\n~Member revival has been successfully done.");
                Sleep(3000);
                return 1;
            }
            temp = temp->link ;
        }
    }
    else{
        puts("\n~Invalid input!");
        return 0;
    }
    puts("\n~Member not found!");
    return 0;
}
//......................................................general list of every member
void generalList()
{
    struct member mem ;
    int memcount = 1 ;
    int check = 0 ;
    char newdate[15];
    printf("\n\033[34m****___________  List of Members  _________****\033[0m\n");
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
        while(fscanf( f , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , mem.username_mem , mem.pass_mem
                     , mem.id_mem , mem.join_date_m , mem.validate, mem.name , mem.family , mem.phone , mem.email , mem.status) != EOF){
            if(validusername(mem.username_mem)){
            //check for being an active member
            strcpy(newdate , mem.join_date_m);
            oneyear(newdate);
            check = strcmp(mem.validate , newdate);
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
                //check for being an active member
                if(check >= 0 && !isinfile(mem.username_mem , ARCMEMBER)){//still active
                    printf("|Membership status : Active until %s\n" , mem.validate);
                }
                else if(check < 0){
                        if(isinfile(mem.username_mem , MEMFILE))
                           printf("|Membership   : Inactive\n");
                        else if(isinfile(mem.username_mem , ARCMEMBER))
                            printf("|Membership status : Removed\n");
                }
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
        Sleep(4000);
        system("cls");
}


//......................................................remove members
void rmMem(struct member *head)
{
    struct member *temp = head;
    struct member *back = NULL;
    struct member copy;
    char input[20];
    int done = 0;
    printf("\n~Removing process...");
    Sleep(2000);
    printf("\n~Please enter the username of the member you want to remove : ");
    scanf(" %s" , input);
    if(strcmp(input , ":)")==0)
        return ;
    if(validusername(input)){
        //open the archive file to save the info
        FILE *f ;
        f = fopen(ARCMEMBER , "a");
        if(f == NULL){
            printf("\n~Could not read the file!\n");
            return;
        }
        else{
            //remove if the subject is the first node
            if(temp != NULL && strcmp(temp->username_mem , input)==0){
                //to copy the whole structure in copy member type
                memcpy(&copy , temp , sizeof(struct member));
                //save the head after removing
                head->link = temp->link;
                //add info to another archived file
                fprintf(f  , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" ,copy.username_mem
                    ,copy.pass_mem, copy.id_mem , copy.join_date_m, copy.validate , copy.name , copy.family , copy.phone , copy.email , copy.status);
                //delete the node
                free(temp);
                fclose(f);
                savechangeMem(head);//write the file again
                puts("\n~Member has been removed successfully!\n(You can find the info in archive file of members)");
                Sleep(4000);
                return ;
            }
            //remove if the subject is in the middle of linked list or at the end
            while(temp != NULL){
                back = temp ;
                temp = temp->link;
                if(temp != NULL && strcmp(temp->username_mem , input)==0){
                        //disconnect the node
                        back->link = temp->link;
                        //to copy the whole structure in copy employee type
                        memcpy(&copy , temp , sizeof(struct member));
                        //add info to another archived file
                        fprintf(f  , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" ,copy.username_mem
                            ,copy.pass_mem , copy.id_mem , copy.join_date_m , copy.name , copy.family , copy.phone , copy.email , copy.status);
                        //delete the node
                        free(temp);
                        fclose(f);
                        savechangeMem(head);//write the file again
                        puts("\n~Member has been removed successfully!\n(You can find the info in archive file of members)");
                        Sleep(4000);
                        return ;
                }

            }
        }
        fclose(f);
    }
    else{
        puts("\n\033[31m~Invalid username!\033[0m");
        return;
    }
    puts("\n\033[31m~Member not found!\033[0m");

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

        //define condition
        strcpy(b.status , "Active");
        //to save info in file
        fprintf(f, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", b.id_book, b.name, b.writer,
                  b.publication, b.year, b.reg_date, E.username_emp , b.status);
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
                                savechangesEmp(head);
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
                        savechangesEmp(head);
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
                        savechangesEmp(head);
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
    printf("\n\033[34m*******/   Welcome    %s   /*******\033[0m\n\n" , M.username_mem);
    printf("\033[32m~You are in Member menu             Date: %s\033[0m\n_____________________________\n" , current);
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
            puts("\n\033[31m~You used invalid characters to choose , Try again:\033[0m");
            return 0;
            break;
        }
}
//........................................................borrow new books
void onemonth(char *date)
{
    int year , month , day;
    //get amounts of a date array
    sscanf(date , "%d/%d/%d" , &day , &month , &year);
    //one more year
    month++ ;
    if(month > 12){
        month = 1;
        year++ ;
    }
    sprintf(date , "%02d/%02d/%d" , day , month , year);
}
void borrowsave(char id[15] )//for saving in file
{
    //get the date
    char current[15];
    todaydate(current);
    //open the borrowed file
    FILE *f ;
    f = fopen(BORROWED , "a");
    if(f == NULL){
        puts("\n~Could not read the file!");
        return;
    }
    else{
        fprintf(f , "%s\n%s\n%s\n" , id , current , M.username_mem);
    }
    fclose(f);
}
void memNewBook(struct book *head)//for process
{
    struct book *temp = head;
    struct book copy;
    char input[20];
    printf("\n~Borrow books process...");
    Sleep(2000);
    //show the list to choose
    puts("\n\n** Here is the list of all books with their status **\n\n~pick up your desired book and Enter the book ID at the end of the list~");
    Sleep(3000);
    availBooks();
    printf("\n** Enter the book ID :");
    scanf(" %s" , input);
    if(strcmp(input , ":)")==0)
        return;
    if(isinfile(input , GBOOKFILE)==0){
        puts("\n~There is no book with this ID!");
        return ;
    }
    //id founded in general file
    while(temp != NULL){
        if(strcmp(temp->id_book , input)==0){//looking for the book
            if(strcmp(temp->status , "Active")==0){//s in active or not
                puts("\n~Loading...");
                Sleep(2000);
                borrowsave(input);
                printf("\n~You borrowed this book(for one month)successfully:\n");
                printf("Name :%s\nAuthor :%s\nPublication :%s\n" , temp->name , temp->writer , temp->publication);
                //get the date to save validate for books
                char current[15];
                todaydate(current);
                onemonth(current);
                printf("\n~You can return this book until : %s" , current);
                return;
            }
        }
        temp = temp->link;
    }
}

//........................................................return books
void memReturn()
{

}
//.........................................................all of the member's book
struct borrow//define the structure
{
        char olddate[15];
        char id[20];
        char member[20];
        struct borrow *link;
};
//to get a linked list for borrowed books
struct borrow* CallFileLinkBorrow()
{
    struct borrow *start = NULL;
    struct borrow *temp = NULL ;
    struct borrow *fresh = NULL ;
     //open file
    FILE *f;
    f = fopen(BORROWED , "r");
    if(f == NULL){
        puts("\n~File not found!");
        return NULL;
    }
    else{
        start = malloc(sizeof(struct borrow));
        if(start == NULL){
            puts("\n~memory error!");
            fclose(f);
            return NULL;
        }
        temp = start ;
        temp->link = NULL ;
        //read the info from file and fill the first node
        while(fscanf(f , "%s\n%s\n%s\n" , temp->id , temp->olddate , temp->member ) != EOF ){
                //add a new node
                fresh = malloc(sizeof(struct borrow));
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
void memAllBooks(struct book *general)
{
    char guess[15];//array for time to check the activation
    char current[15];
    todaydate(current);//for now and compare the dates
    puts("\n~You are watching the list of your books\n(including borrowed or write-in ones)\n");
    //call the general book linked list
    struct book *info = general;
    //call the linked list to search for member
    struct borrow *head = CallFileLinkBorrow();
    struct borrow *temp = head;
    while(temp != NULL){//search for member
        if(strcmp(temp->member , M.username_mem)==0){
            while(info != NULL){//search for information in general file
                if(strcmp(temp->id , info->id_book)==0){
                    //show the result
                    puts("\n_________________________________");
                    printf("|Name        : %s\n" , info->name);
                    printf("|Author      : %s\n" , info->writer);
                    printf("|Publication : %s\n" , info->publication);
                    //check the date
                    strcpy(guess , temp->olddate);
                    onemonth(guess);
                    if(strcmp( current , guess) <= 0){//still have time to return
                       strcpy(info->status , "In-Your-Hand");
                       printf("|Status     :\033[32m %s  until  %s\033[0m\n" , info->status ,guess);
                    }
                    else if(strcmp(current , guess) > 0 ){//do not have time warning for return
                        strcpy(info->status , "Time-Over");
                        printf("|Status     : \033[31m%s ,Please Return your book!\033[0m\n" , info->status);
                    }
                }
                info = info->link;
            }
        }
        temp = temp->link;
    }
    //free borrow linked list
    while(head != NULL){
        temp = head ;
        head = head->link ;
        free(temp);
    }
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
        puts("\n\033[34m****____________List of available books___________****\033[0m");
        while(fscanf(f , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" ,b.id_book , b.name , b.writer ,
                    b.publication , b.year , b.reg_date , b.reg_user , b.status ) != EOF){
            if(validname(b.name)){
                //check for activation
                if(isinfile(b.id_book , BORROWED)==1)
                    strcpy(b.status , "Borrowed");
                else if(isinfile(b.id_book , GBOOKFILE)==1 || strcmp(b.status , "Active")==0)
                    strcpy(b.status , "Active");
                else if(!(isinfile(b.id_book , GBOOKFILE)))
                    strcpy(b.status , "Inactive");
                printf("\n\033[34m____________________________________\033[0m");
                printf("\n\n~Book number %d ~" , bookcount);
                printf("____________________");
                printf("\n|Book ID              : %s" , b.id_book);
                printf("\n|Book name            : %s" , b.name);
                printf("\n|The author           : %s" , b.writer);
                printf("\n|The publication      : %s" , b.publication);
                printf("\n|Year of publication  : %s" , b.year);
                printf("\n|Date of registration : %s" , b.reg_date);
                printf("\n|Saved by (Username)  : %s" , b.reg_user);
                printf("\n|Book status          : %s" , b.status);//check
                bookcount++ ;
            }
        }
        if(bookcount==1){
            puts("\n~Could not found any books!");
        }
        printf("\n____________________________________");
        fclose(f);
        printf("\n\n~Press any key to continue:");
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
                                savechangeMem(head);
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
                       savechangeMem(head);
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
                        savechangeMem(head);
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
        printf("\033[34m*******/   Welcome to PeanutZee Library   /*******\033[0m\n\n");
        printf("\033[32m~You are in : main menu             Date: %s\033[0m\n____________________\n"  , current);
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
                    printf("\n\033[31m~You used invalid characters to choose ,Press any key to Try again:\033[0m");
                    getch();
                    system("cls");
                    return 0;
                    break;
            }
    }

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
    puts("\n\033[34m____________________");
    printf("Log in process... \033[0m\n");
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
        puts("\n\033[31m~Invalid username!\033[0m\n");
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
                    printf("\n\n\033[32m~Login successfully as %s~\033[0m\n" , ADMIN_USERNAME);
                    printf("\n");
                    found = 1 ;
                    return 1 ;
                }
                else{
                    chance-- ;
                //add limits for trying here
                    if(chance > 0){
                        printf("\n\033[31mWrong password!\nYou have %d more chances,try again!\033[0m" , chance);
                        printf("\nPassword:");
                    }
                    else{
                        printf("\n\033[31mToo many wrong passwords!\n_____YOU ARE NOT ALLOWED____\n");
                        printf("\n~After 5 minutes , you can try log in again...\033[0m");
                        Sleep(300000);
                        return 4;
                    }
                }
            }
        }else{//if it was not admin
            puts("\033[31m\nWrong username for admin!\033[0m");
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
            printf("\n\033[31mThe staff file has not found!\033[0m");
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
                    //read password from file
                    fgets(pass_file , PASSWORD , s);
                    pass_file[strcspn(pass_file, "\n")] = '\0';
                    //get input
                    printf("Password:");
                    while(chance > 0){
                        hidepass(pass_input);
                        if(strcmp(pass_file , pass_input) == 0){
                            printf("\n\n\033[32m~Login successfully as (%s)\033[0m\n" , E.username_emp);
                            found = 1 ;
                            fclose(s);
                            return 2 ;
                        }else{
                            chance-- ;
                            if(chance > 0){
                                printf("\n\033[31mWrong password!\nYou have %d more chances,try again!\033[0m" , chance);
                                printf("\nPassword:");
                            }else{
                                printf("\n\033[31mToo many wrong passwords!\n___YOU ARE NOT ALLOWED___\n");
                                printf("\n~After 5 minutes , you can try log in again...\033[0m");
                                fclose(s);
                                Sleep(300000);
                                return 4;
                            }
                        }
                    }

                }
            }
            if(found == 0){
                printf("\n\033[31mEmployee not found!\033[0m\n");
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
            printf("\n\033[31mThe members file has not found!\033[0m\nReturning to main menu...");
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
                //read from file
                fgets(pass_file , PASSWORD , m);
                pass_file[strcspn(pass_file, "\n")] = '\0';
                //get input
                printf("Password:");
                while(chance > 0){
                hidepass(pass_input);
                    if(strcmp(pass_file , pass_input)==0){
                        printf("\n\n\033[32m~Login successfully as (%s)\033[0m\n" , M.username_mem);
                        found = 1;
                        fclose(m);
                        return 3;
                    }else{
                        chance-- ;
                        if(chance > 0){
                            printf("\n\033[31mWrong password!\nYou have %d more chances,try again!\033[0m" , chance);
                            printf("\nPassword:");
                        }else{
                            printf("\n\033[31mToo many wrong passwords!\n_____YOU ARE NOT ALLOWED____\n");
                            printf("\n~After 5 minutes , you can try log in again...\033[0m");
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
            printf("\n\033[31mMember not found!\033[0m\n");
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
int validemail(char email[60])
{
    int at = 0 , dot = 0;
    if(strlen(email) > 60 || strlen(email)< 10){
        puts("\n~Too mush or too few characters for email!\n");
        return 0;
    }
    //check each character
    int i = 0;
    while(email[i] != '\0'){
        //invalid characters
        if(!(isalpha(email[i])) || email[i] != '-' || email[i] != '_' || email[i] != '.' || email[i] != '@'){
            puts("\n~Unknown characters!\n");
            return 0;
        }
        //count at and dot
        if(email[i]=='@')
            at++ ;
        //is there any dot after count and it is not the last character
        if(email[i]=='.' && email[i+1]!='\0'){
            if(at > 0)
                dot++ ;
        }
        //move to next character
        i++;
    }
    //to be valid
    if(at == 1 && dot > 0 && email[0]!='@'){
        return 1 ;
    }
    //not valid at all
    return 0;
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
        while(fscanf(f , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , temp->username_emp , temp->pass_emp
                    ,temp->id_emp , temp->join_date_e , temp->name , temp->family , temp->phone , temp->email , temp->status) != EOF ){
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
        while(fscanf(f , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , temp->username_mem , temp->pass_mem
                    ,temp->id_mem , temp->join_date_m ,temp->validate, temp->name , temp->family , temp->phone , temp->email , temp->status) != EOF ){
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
//................................also for books just general file
struct book* CallFileLinkBook()
{
    struct book *start = NULL;
    struct book *temp = NULL ;
    struct book *fresh = NULL ;
     //open file
    FILE *f;
    f = fopen(GBOOKFILE , "r");
    if(f == NULL){
        puts("\n~File not found!");
        return NULL;
    }
    else{
        start = malloc(sizeof(struct book));
        if(start == NULL){
            puts("\n~memory error!");
            fclose(f);
            return NULL;
        }
        temp = start ;
        temp->link = NULL ;
        //read the info from file and fill the first node
        while(fscanf(f , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , temp->id_book , temp->name
                    ,temp->writer , temp->publication ,temp->year, temp->reg_date , temp->reg_user , temp->status) != EOF ){
                //add a new node
                fresh = malloc(sizeof(struct book));
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
void savechangesEmp(struct employee *head)
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
            fprintf(f , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , temp->username_emp , temp->pass_emp
                    ,temp->id_emp , temp->join_date_e , temp->name , temp->family , temp->phone , temp->email , temp->status);
            //next employee
            temp = temp->link ;
        }
        fclose(f);
    }
    //free the whole memory
    while(head != NULL){
        temp = head;
        head = head->link;
        free(temp);
    }
}
void savechangeMem(struct member *head)
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
            fprintf(f , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , temp->username_mem, temp->pass_mem
                    ,temp->id_mem , temp->join_date_m , temp->validate, temp->name , temp->family , temp->phone , temp->email , temp->status);
            //next employee
            temp = temp->link ;
        }
        fclose(f);
    }
   //free the whole memory
    while(head != NULL){
        temp = head;
        head = head->link;
        free(temp);
    }
}
