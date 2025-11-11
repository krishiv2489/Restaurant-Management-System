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
int menu_change();
int tableBook;
int guests;
int table_booking();
void ingredients();
int note();
int cook_count();

//global arrays so that all functions can acces them.
int item = 5;//no. of items in the menu.
char items[10][20] = {"Pizza","Burger","Pasta","Coffee","Salad"};
int price[10] = {250,150,200,50,120};
int qty[5] = {5,4,3,8,6};
int order[2][10];
int total;
int tableBook;
char table[5][20] = {"Table 1", "Table 2", "Table 3", "Table 4", "Table 5"};
int tableNum[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int tableCapacity[10] = {2,2,2,4,4,4,4,6,6,8};
int tableAvailable[10] = {1,1,1,1,1,1,1,1,1,1};
char ing[15][20] = {"Tomato", "Onion", "Lettuce", "Buns/Bread", "Cheese", "Milk", "Olive Oil", "Salt", "Ketchup"};
char quantity[15][20] = {"20 units", "10 units", "25 units", "5 packets", "1 kg", "3 Litres", "500 mL", "500 grams", "75 sachets"};

int main() {

<<<<<<< HEAD
<<<<<<< HEAD

=======
    
>>>>>>> be0d1be (Updated project)
=======

>>>>>>> d4f9ac7 (Updated project)
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
    

>>>>>>> be0d1be (Updated project)
=======
>>>>>>> d4f9ac7 (Updated project)
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

int bill() {
    int i = 0;
    total = 0;

    printf("The Final Order:\n"
           "Index   Name       Quantity         Total\n");

    while (order[0][i] != 0) {
        int a = order[0][i]; // item index
        int b = order[1][i]; // quantity
        printf("%-5d %-10s %-10d %-10d\n", a, items[a - 1], b, price[a - 1] * b);
        total += price[a - 1] * b;
        i++;
    }

    // Added GST calculation
    float gst = total * 0.05;  // 5% GST
    float final_total = total + gst;

    printf("---------------------------------------------\n");
    printf("Subtotal:           Rs.%d\n", total);
    printf("GST (5%%):           Rs.%.2f\n", gst);//.2f (.2) means rounding off to 2 decimals
    printf("---------------------------------------------\n");
    printf("Grand Total:        Rs.%.2f\n", final_total);
    printf("---------------------------------------------\n\n");

    return 0;
}


int menu_change(){
    int opt;//variable to store the preference of the owner.
    int opt2;//for secondary menu at the last.

    retry3:
    printf("===============================\n"
           "|You have entered MENU CHANGER|\n"
           "===============================\n"
           "1. Add a DISH to menu.!!\n"
           "2. Remove a DISH from the menu.!!\n"
           "3. Change the price of a DISH.!!\n"
           "================================\n\n");
    retry4:
    printf("Please Select one of the above options(1-3):- ");
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
    printf("3. EXIT menu changer!!\n");
    printf("-------------------------------------\n");
    printf("Select (1-3) from above options:- \n");
    scanf("%d", &opt2);
    if(opt2 == 1){goto add_again;}
    else if(opt2 == 2){goto retry3;}
    else if(opt2 == 3){}
    else{printf("Invalid input.");}

    }

int chef()
{
    int chef1;
    printf("=================================\n"
           "|You have entered CHEF's ARSENAL|\n"
           "=================================\n"
           "1. Cooking Counter!\n"
           "2. Check the INGREDIENTS!\n"
           "3. Write a NOTE to owner!\n"
           "=================================\n\n");
           printf("Please Select one of the above options(1-3):- ");
           scanf("%d", &chef1);
           if(chef1 == 1)
           {
               cook_count();
           }
           if(chef1 == 2)
           {
               ingredients();
           }
           if(chef1 == 3)
           {
               note();
           }
           return 0;
}
int cook_count(){printf("Hello");}
int note(){}
void ingredients()
{
    int ingredients1, ingredients2;
    printf("------------------------------\n"
           "|You have entered INGREDIENTS|\n"
           "------------------------------\n"
           "1. Check the quantity of INGREDIENTS!\n"
           "2. Add NEW Ingredients!\n"
           "3. Add a Special Item to the Menu!\n"
           "4. Return to ARSENAL!\n"
           "----------------------------------\n\n");
           printf("Please Select one of the above options(1-3):- ");
           scanf("%d", &ingredients1);
           int j=9;

           if(ingredients1 == 1)
           {
               printf("Ingredients: \n\n");
               for(int i=0;i<15;i++)
               {
                   if(ing[i][1] == '\0' || quantity[i][1] == '\0'){break;}
                   printf("%s - %s\n", ing[i], quantity[i]);
               }
           }
           else if(ingredients1 == 2)
           {
               add_ingredients:
               printf("Enter the name of ingredient to add: ");
               scanf("%s", &ing[j+1]);
               printf("Enter the quantity of ingredient: ");
               scanf("%s", &quantity[j+1]);
               j++;
               printf("Would you like to add another ingredient?\n");
               printf("1. Yes\n");
               printf("2. No. Return to Ingredients\n");
               printf("Please Select one of the options:- ");
               scanf(" %d", &ingredients2);
               if(ingredients2 == 1)
                {goto add_ingredients;}
               else if(ingredients2 == 2)
               {
                   ingredients();
               }
           }
           else if(ingredients1 == 3)
           {

           }
           else if(ingredients1 == 4)
           {
               chef();
           }
<<<<<<< HEAD
}
=======
}
>>>>>>> d4f9ac7 (Updated project)
