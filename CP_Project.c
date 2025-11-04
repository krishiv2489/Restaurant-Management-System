#include<stdio.h>
#include<string.h>
int owner();
int waiter();
int chef();
int table_manager();
int login();
int main() {
    int who = login();

    switch (who) {
    case 1:
        owner();
        break;
    case 2:
        chef();
        break;
    case 3:
        waiter();
        break;
    case 4:
        table_manager();
        break;
    default:
        printf("Invalid choice message\n");
}

    return 0;
}
int login(){
    //this part is about the login or the start page. here who is who is going to happen
    char usr[100],pass[100];
    int who;

    printf(
        "========================================\n"
        "               WELCOME  \n"
        "========================================\n"
        "|  1. Login as OWNER          |\n"
        "|  2. Login as CHEF           |\n"
        "|  3. Login as WAITER         |\n"
        "|  4. Login as TABLE MANAGER  |\n"
        "========================================\n");
    retry:
        printf("Select an option (1-4): ");
        scanf("%d",&who);
    
    //if the user input 5 or 0.
    if(who!=1 && who!=2 && who!=3 && who!=4){
        printf("Invalid Input!! Error!!\n");
        goto retry;
    }
    
     printf(
        "\n------------ LOGIN PORTAL ------------\n");

    printf("USERNAME / ID:-- ");
    scanf("%s",&usr);

    printf("PASSWORD:-- ");
    scanf("%s",&pass);

    printf("--------------------------------------\n");


    if(strcmp(usr, "owner") == 0 && strcmp(pass, "owner_123") == 0){
        printf("Succesfully LOGGED IN!!\n");
    }
    else if(strcmp(usr, "chef") == 0 && strcmp(pass, "chef_123") == 0){
        printf("Succesfully LOGGED IN!!\n");
    }
    else if(strcmp(usr, "waiter") == 0 && strcmp(pass, "waiter_123") == 0){
        printf("Succesfully LOGGED IN!!\n");
    }
    else if(strcmp(usr, "table_man") == 0 && strcmp(pass, "table_man_123") == 0){
        printf("Succesfully LOGGED IN!!\n");
    }
    else{
        printf("LOGIN CREDENTIALS are INCORRECT!!\n");
    }

    return who; //returns who has the person logged as.
}

int owner(){
    
}
int waiter(){

}
int chef(){

}
int table_manager(){

}