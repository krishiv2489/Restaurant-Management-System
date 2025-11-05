#include<stdio.h>
#include<string.h>

int owner();
int waiter();
int chef();
int table_manager();
int login();
void menu();
int cost_order();
int bill();
int table_booking();
int menu_change();

//global arrays so that all functions can acces them.
int item = 5;//no. of items in the menu.
char items[10][20] = {"Pizza","Burger","Pasta","Coffee","Salad"};
int price[10] = {250,150,200,50,120};
int qty[5] = {5,4,3,8,6};
int order[2][10];
int total;
int tableBook;



int main() {

    /*
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
        printf("Invalid choice message\n");}
    */
    //waiter();
    owner();
    //table_manager();
    //chef();

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
    menu_change();
}

int waiter(){
    menu();
    cost_order();
    bill();
}

int chef(){}
/*
int table_manager()
{
    printf("Enter the number of guests: ");
    scanf("%d", &guests);

    printf("Tables Available: \n");
    for(int i=0;i<10;i++)
    {
        if(tableCapacity[i] >= guests && tableAvailable[i] == 1)
        {
            printf("Table %d\n", i+1);
        }
    }
    int t = table_booking();
    int s=1;
    for(int i=0;i<10;i++)
    {
        if(tableAvailable[i] == 0)
        {
            s++;
        }
    }
    tableAvailable[t-1] = 0;
    printf("Total Tables booked today = %d\n", s);
    table_manager();
}

int table_booking()
{
    printf("Select the number of table to book: ");
    scanf("%d", &tableBook);
    if(tableBook > 10 || tableBook <= 0)
    {
        printf("No table of that number.\n");
    }
    else
    {
        printf("Table %d has been booked.\n", tableBook);
    }
    printf("========================================\n");
    return tableBook;
}
*/
void menu(){
    printf("--------------------\n"
           "        MENU        \n"
           "--------------------\n");
    for(int i = 0; i<item; i++){
        printf("%d. %s -------- %d\n", i+1, items[i], price[i]);
    }
    printf("====================\n\n");
}

int cost_order(){

    printf("ORDER Initialized!!");
    printf("--------------------------------\n");
    printf("Just enter the index of the item!!(To exit press 0)\n");
    int j = 0;
    do{
        scanf("%d",&order[0][j]);
        if(order[0][j] == 0){
            break; // this is if he wants to exit the order
        }
        printf("Quantity:- ");
        scanf("%d", &order[1][j]);
        j++;
    }while(1);
}

int bill(){
    int i = 0;
    total = 0;

    printf("The Final Order:\n"
           "Index   Name       Quantity         Total\n");

    while(order[0][i] != 0){
        int a = order[0][i];//item
        int b = order[1][i];//quantity
        printf("%d.      %s     %d                      %d\n", a, items[a-1], b, price[a-1]*b);
        
        total += (price[a-1]*(b));
        i++;
    }
    printf("The total BILL is:- %d", total);
    printf("\n");
}

int menu_change(){
    int opt;//variable to store the preference of the owner.
    int opt2;//for secondary menu at the last.

    retry3:
    printf("...............................\n"
           "|You have entered MENU CHANGER|\n"
           "...............................\n"
           "1. Add a DISH to menu.!!\n"
           "2. Remove a DISH from the menu.!!\n"
           "3. Change the price of a DISH.!!\n"
           "...............................\n\n");
    retry4:
    printf("Please Select one of the above options(1-3):-");
    scanf("%d", &opt);
    if(opt==1){

        add_again:
        item++;
        printf("Enter the NAME of the NEW dish:- ");
        scanf(" %s", items[item-1]);
        printf("Enter the PRICE of the NEW dish:- ");
        scanf(" %d", &price[item-1]);
        printf("So the new MENU is:- \n");
        menu();
        
    }
    else if(opt == 2){
    int removeIndex;

    printf("\n-------- CURRENT MENU --------\n");
    menu();

    printf("Enter the number of the dish to remove: ");
    scanf("%d", &removeIndex);

    if (removeIndex < 1 || removeIndex > item) {
        printf("Invalid dish number!\n");
        return 0;
    }

    printf("'%s' removed from menu.\n", items[removeIndex - 1]);

    for (int i = removeIndex - 1; i < item - 1; i++) {
        strcpy(items[i], items[i + 1]);
        price[i] = price[i + 1];
        qty[i] = qty[i + 1];
    }

    item--;
    printf("\nUpdated Menu:\n");
    menu();

    return 0;
}
    else if(opt == 3){
        int changePriceIndex;
        int changePrice;
        printf("Enter the index of the dish that you what to change the price of:- ");
        scanf("%d", &changePriceIndex);
        printf("Enter the changed price:- ");
        scanf("%d", &changePrice);
        price[changePriceIndex-1] = changePrice;

        printf("\nUpdated Menu:\n");
        menu();

    }
    else{
        printf("Invalid Input!! ERROR!!\n");
        goto retry4;
    }
    printf("-------------------------------------\n");
    printf("1. Do you want to add another dish??\n");
    printf("2. Go back to MENU CHANGER??\n");
    printf("3. EXIT menu changer!!");
    printf("-------------------------------------\n");
    printf("Select (1-3) from above options:- \n");
    scanf("%d", &opt2);
    if(opt2 == 1){goto add_again;}
    else if(opt2 == 2){goto retry3;}
    else if(opt2 == 3){}
    else{printf("Invalid input.");}

    }
    
        


