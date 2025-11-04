#include<stdio.h>
#include<string.h>

int owner();
int waiter();
int chef();
int table_manager();
int login();
void menu();
int order();

//global array so that all functions can acces them.
char items[5][20] = {"Pizza","Burger","Pasta","Coffee","Salad"};
int price[5] = {250,150,200,50,120};
int qty[5] = {5,4,3,8,6};


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
        "           WELCOME to FAST EAT  \n"
        "========================================\n"
        "|  1. Login as OWNER          |\n"
        "|  2. Login as CHEF           |\n"
        "|  3. Login as WAITER         |\n"
        "|  4. Login as TABLE MANAGER  |\n"
        "========================================\n");
    retry1:
        printf("Select an option (1-4): ");
        scanf("%d",&who);
    
    //if the user input 5 or 0.
    if(who!=1 && who!=2 && who!=3 && who!=4){
        printf("Invalid Input!! Error!!\n");
        goto retry1;
    }
    retry2:
    printf(
        "\n------------ LOGIN PORTAL ------------\n");

    printf("USERNAME / ID:-- ");
    scanf("%s",&usr);

    printf("PASSWORD:-- ");
    scanf("%s",&pass);

    printf("--------------------------------------\n");

    
    if(strcmp(usr, "owner") == 0 && strcmp(pass, "owner_123") == 0){
        printf("Succesfully LOGGED IN as %s!!\n", usr);
    }
    else if(strcmp(usr, "chef") == 0 && strcmp(pass, "chef_123") == 0){
        printf("Succesfully LOGGED IN as %s!!\n", usr);
    }
    else if(strcmp(usr, "waiter") == 0 && strcmp(pass, "waiter_123") == 0){
        printf("Succesfully LOGGED IN as %s!!\n", usr);
    }
    else if(strcmp(usr, "table_man") == 0 && strcmp(pass, "table_man_123") == 0){
        printf("Succesfully LOGGED IN as %s!!\n", usr);
    }
    else{
        printf("LOGIN CREDENTIALS are INCORRECT!!\n");
        goto retry2;
    }
    printf("\n");
    return who; //returns who has the person logged as.
}

int owner(){

}
int waiter(){
    menu();
}
int chef(){

}
int table_manager(){

}

void menu(){
    printf("--------------------\n"
           "        MENU        \n"
           "--------------------\n");
    for(int i = 0; i<5; i++){
        printf("%d. %s -------- %d\n", i+1, items[i], price[i]);
    }
    printf("====================\n");
}

int order(){

}