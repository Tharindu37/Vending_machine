//===========================
/*
Title :Vending machine
Author :Tharindu Lakshan - AS2020913
Date :2021/10/20
Version :1.0.0
Description :Here it represents the basic function of a vending machine.
*/
//===========================

//--------Header Files-------
#include <stdio.h>
#include <stdlib.h>
//---------------------------

//-------------Function Declaration--------------------------------------------------------------
int printItem(char itemArray[20][20],int numberOfItem[20]);
int printSettings();
int printSettings2(char settingsArray2[3][10]);
void addMoreItems(char itemArray[20][20],int numberOfOneItem[20],float priceOfOneItem[20]);
void itemNameSet(char itemArray[20][20],int i);
void changePrice(char itemArray[20][20],float priceOfOneItem[20]);
void printProfit(char itemArray[20][20],float buyItemTotalPrice[20]);
void addItemCount(char itemArray[20][20],int numberOfOneItem[20]);
int defaultOutPut(char itemArray[20][20],int numberOfOneItem[20]);
void printItemTable(char itemArray[20][20],int numberOfOneItem[20],float priceOfOneItem[20]);
void buyItem(float priceOfOneItem[20],float buyItemTotalPrice[20],
             int chooseItem,int numberOfOneItem[20],char itemArray[20][20]);
float calculateDiscount(float priceOfOneItem[20],int chooseItemIndex);
void printBill(float priceOfOneItem[20],int chooseItemIndex,float discont,char itemArray[20][20],
               char paymentMehtod[2][20],int intPaymentMethod,float sellPrice,float enterMoney);
void createBuyitemFile();
void writeTheFile(char itemAraay[20][20],float priceOfOneItem[20],int chooseItemIndex,
                  float discont,float sellPrice);
void fixFget(char s[]);
//------------------------------------------------------------------------------------------------

//-Global variable-
int arraySize=5;
//-----------------

//-------------------------Main Function Declaration-----------------------------------------------
int main(){
    createBuyitemFile();
    char itemArray[20][20]={"Water Bottles","Coca cola","Soda","Sprite","Pepsi"};//item array
    char settingsArray2[3][10]={"Change","Back","Exit"};
    int numberOfOneItem[20]={5,10,10,10,2};//number of one item array
    float priceOfOneItem[20]={100,70,150,80,90};//price of one item array
    float buyItemTotalPrice[20]={0,0,0,0,0};
    int chooseItem=printItem(itemArray,numberOfOneItem);//call print item function

    int chooseSettings=0;
    int chooseSettings2=0;
    //Item Choose
    settings:
    if(chooseItem==-1){
        system("CLS");
        chooseSettings=printSettings();
    }else{
        system("cls");
        if(arraySize>=chooseItem && chooseItem>0){
            buyItem(priceOfOneItem,buyItemTotalPrice,chooseItem,numberOfOneItem,itemArray);
            printf("\t\t<<Please Press Any Key>>");
        }else{
            chooseItem=defaultOutPut(itemArray,numberOfOneItem);
            goto settings;
        }
        getch();
        system("cls");
        chooseItem=printItem(itemArray,numberOfOneItem);
        goto settings;
    }
    //Settings Choose
    switch(chooseSettings){
    case 1:
        system("CLS");
        chooseSettings2=printSettings2(settingsArray2);
        system("cls");
        switch(chooseSettings2){
        case 1:
            addMoreItems(itemArray,numberOfOneItem,priceOfOneItem);
            system("CLS");
            printItemTable(itemArray,numberOfOneItem,priceOfOneItem);
            chooseSettings=printSettings();
            goto settings;
        case 2:
            system("CLS");
            chooseSettings=printSettings();
            goto settings;
        case 3:
            system("CLS");
            chooseItem=printItem(itemArray,numberOfOneItem);
            goto settings;
        default:
            chooseItem=defaultOutPut(itemArray,numberOfOneItem);
            goto settings;
        }
        break;
    case 2:
        system("CLS");
        chooseSettings2=printSettings2(settingsArray2);
        system("cls");
        switch(chooseSettings2){
        case 1:
            changePrice(itemArray,priceOfOneItem);
            system("CLS");
            printItemTable(itemArray,numberOfOneItem,priceOfOneItem);
            chooseSettings=printSettings();
            goto settings;
        case 2:
            system("CLS");
            chooseSettings=printSettings();
            goto settings;
        case 3:
            system("CLS");
            chooseItem=printItem(itemArray,numberOfOneItem);
            goto settings;
        default:
            chooseItem=defaultOutPut(itemArray,numberOfOneItem);
            goto settings;
        }
        break;
    case 3:
        printItemTable(itemArray,numberOfOneItem,priceOfOneItem);
        chooseSettings=printSettings();
        goto settings;
    case 4:
        printProfit(itemArray,buyItemTotalPrice);
        chooseSettings=printSettings();
        goto settings;
    case 5:
        system("CLS");
        chooseSettings2=printSettings2(settingsArray2);
        system("cls");
        switch(chooseSettings2){
        case 1:
            addItemCount(itemArray,numberOfOneItem);
            system("CLS");
            printItemTable(itemArray,numberOfOneItem,priceOfOneItem);
            chooseSettings=printSettings();
            goto settings;
        case 2:
            system("CLS");
            chooseSettings=printSettings();
            goto settings;
        case 3:
            system("CLS");
            chooseItem=printItem(itemArray,numberOfOneItem);
            goto settings;
        default:
            chooseItem=defaultOutPut(itemArray,numberOfOneItem);
            goto settings;
        }
        break;
    case 6:
        //Settings--->if input 6--->Settings 2--->if input 1
        //goto Item List
        system("CLS");
        chooseItem=printItem(itemArray,numberOfOneItem);
        goto settings;
    default:
        chooseItem=defaultOutPut(itemArray,numberOfOneItem);
        goto settings;
    }
    return 0;
}
//-----------------------------------------------------------------------------------------------

//--------------------User written Functions-----------------------------------------------------

//Item print and get input.if input is -1 go settings
//Printing the item list and receiving the input provided by the customer or seller.
int printItem(char itemArray[20][20],int numberOfItem[20]){
    int chooseItem=0;
    printf("\t\t============================\n");
    printf("\t\t|           ITEM           |\n");
    printf("\t\t============================\n");
    printf("\t\t============================\n");
    printf("\t\t|                          |\n");
    for(int i=0;i<arraySize;i++){
        if(numberOfItem[i]!=0){
            printf("\t\t|%3d. %-21s|\n",i+1,itemArray[i]);
        }
    }
    printf("\t\t|                          |\n");
    printf("\t\t============================\n");
    printf("\t\t============================\n");
    printf("\t-------------------------------------------\n");
    printf("\t<<<<<Edit System Settings For Enter -1>>>>>\n");
    printf("\t-------------------------------------------\n\n");
    printf("\t<>Select the Item You Want? :");
    scanf("%d",&chooseItem);
    return chooseItem;
}

//Settings--->if Input -1
//Printing the Settings list and receiving the input provided by the seller
int printSettings(){
    int chooseSettings=0;
    char settingsArray[6][50]={"Add More Items","Change The Price","Item Table","The Profit",
    "Increasing The Number Of Items","Exit"};
    printf("\t\t=================================\n");
    printf("\t\t|             SETTINGS          |\n");
    printf("\t\t=================================\n");
    printf("\t\t=================================\n\n");
    for(int i=0;i<6;i++){
        printf("\t\t%d. %s\n",i+1,settingsArray[i]);
    }
    printf("\n\t\t=================================\n");
    printf("\t\t=================================\n\n");
    printf("\t\t<>Choose :");
    scanf("%d",&chooseSettings);
    return chooseSettings;
}

//Settings 2
//Printing the Settings 2 list and receiving the input provided by the seller
int printSettings2(char settingsArray2[3][10]){
    int chooseSettings2=0;
    printf("\t\t============================\n");
    printf("\t\t|      MORE SETTINGS       |\n");
    printf("\t\t============================\n");
    printf("\t\t============================\n\n");
    for(int i=0;i<3;i++){
        printf("\t\t%d. %s\n",i+1,settingsArray2[i]);
    }
    printf("\n\t\t============================\n");
    printf("\t\t============================\n");
    printf("\t\t<>Choose :");
    scanf("%d",&chooseSettings2);
    return chooseSettings2;
}

//Settings--->if input 1--->Settings 2--->if input 1
//Adding new items
void addMoreItems(char itemArray[20][20],int numberOfOneItem[20],float priceOfOneItem[20]){
    int noOfItems=0;
    printf("\t\t==========================\n");
    printf("\t\t     NUMBER OF ITEMS      \n");
    printf("\t\t==========================\n");
    printf("\t\t==========================\n\n");
    printf("\t\tEnter Number Of Items :");
    scanf("%d",&noOfItems);
    printf("\t\t==========================\n");
    printf("\t\tOK..!,<--Please Click Any Key-->\n");
    getch();
    system("cls");
    printf("\t\t====================================\n");
    printf("\t\t              ADD ITEM              \n");
    printf("\t\t====================================\n");
    printf("\t\t====================================\n\n");
    for(int i=0;i<noOfItems;i++){
        printf("\t\tItem %d>>>\n",i+1);
        printf("\t\t\tEnter Item %d Name :",i+1);
        fflush(stdin);
        fgets(itemArray[arraySize],sizeof(itemArray[arraySize]),stdin);
        fixFget(itemArray[arraySize]);
        printf("\t\t\tEnter Item %d Price :",i+1);
        scanf("%f",&priceOfOneItem[arraySize]);
        printf("\t\t\tEnter Item %d Count :",i+1);
        scanf("%d",&numberOfOneItem[arraySize]);
        arraySize++;
    }
    printf("\t\t====================================\n");
    printf("\t\tOK..!,<--Please Click Any Key-->\n");
    getch();
}

//Fix fget new line error
void fixFget(char s[]){
    char *pos=strchr(s,'\n');
    if(pos != NULL){
        *pos='\0';
    }
}

//Settings--->if input 2--->Settings 2--->if input 1
//Change the price of available items.
void changePrice(char itemArray[20][20],float priceOfOneItem[20]){
    printf("\t<<If Not Change,Enter -1>>\n");
    for(int i=0;i<arraySize;i++){
        float temp=0;
        printf("\t\tEnter New Price For %s :",itemArray[i]);
        scanf("%f",&temp);
        if(temp>=0){
            priceOfOneItem[i]=temp;
        }
    }
}

//Settings--->if input 3--->Settings 2--->if input 1
//Check the number of items available
void printItemTable(char itemArray[20][20],int numberOfOneItem[20],float priceOfOneItem[20]){
    system("CLS");
    printf("\t\t==========================================================\n");
    printf("\t\t|               The Number Of Item Available             |\n");
    printf("\t\t==========================================================\n");
    printf("\t\t|Item\t\tNumber Of Item\t\tPrice Of One Item|\n");
    for(int i=0;i<arraySize;i++){
        printf("\t\t|%-20s%-20dRs. %-12.2f|\n",itemArray[i],numberOfOneItem[i],priceOfOneItem[i]);
    }
    printf("\t\t==========================================================\n");
    printf("\t\tFor Go Settings <--Please Click Any Key-->");
    getch();
    system("CLS");
}

//Settings--->if input 4--->Settings 2--->if input 1
//Take care of the total amount collected by selling one item.
void printProfit(char itemArray[20][20],float buyItemTotalPrice[20]){
    system("cls");
    printf("\t\t======================================\n");
    printf("\t\t|              Profit                |\n");
    printf("\t\t======================================\n");
    printf("\t\t|Item Name\tTotal amount of sales|\n");
    for(int i=0;i<arraySize;i++){
        printf("\t|%-10s\tRs. %-17.2f|\n",itemArray[i],buyItemTotalPrice[i]);
    }
    printf("\t\t======================================\n");
    printf("\t\tFor Go Settings <--Please Click Any Key-->");
    getch();
    system("CLS");
}

//Settings--->if input 5--->Settings 2--->if input 1
//Increase the number of available items.
void addItemCount(char itemArray[20][20],int numberOfOneItem[20]){
    printf("\t\t=====================================\n");
    printf("\t\t|           INCREASE ITEM           |\n");
    printf("\t\t=====================================\n");
    printf("\t\t=====================================\n\n");
    for(int i=0;i<arraySize;i++){
        float temp=-1;
        printf("\t\tEnter Add Item Count For %s :",itemArray[i]);
        scanf("%f",&temp);
        numberOfOneItem[i]+=temp;
    }
    printf("\t\t=====================================\n");
    printf("\t\tOK..!,<--Please Click Any Key-->\n");
    getch();
}

//default output
int defaultOutPut(char itemArray[20][20],int numberOfOneItem[20]){
    system("CLS");
    printf("\t\t---------------------------------------------\n");
    printf("\t\t|Invalid Input..! <--Please Click Any Key-->|\n");
    printf("\t\t---------------------------------------------\n");
    getch();
    system("CLS");
    int chooseItem=printItem(itemArray,numberOfOneItem);
    return chooseItem;
}

//buy items
//Choosing how the customer will pay when purchasing an item and making a payment
void buyItem(float priceOfOneItem[20],float buyItemTotalPrice[20],int chooseItem,int numberOfOneItem[20],
             char itemArray[20][20]){
    int intPaymentMethod;
    int discont;
    int chooseItemIndex=chooseItem-1;
    int sellPrice;
    float enterMoney;
    char paymentMehtod[2][20]={"Card Payment","cash Payment"};
    printf("\t\t===================\n");
    printf("\t\t| PAYMENT METHOD  |\n");
    printf("\t\t===================\n");
    printf("\t\t===================\n\n");
    for(int i=0;i<2;i++){
        printf("\t\t%d. %s\n",i+1,paymentMehtod[i]);
    }
    printf("\n\t\t===================\n\n");
    printf("\t\tChoose Payment Method :");
    scanf("%d",&intPaymentMethod);

    if(intPaymentMethod==1){
        discont=calculateDiscount(priceOfOneItem,chooseItemIndex);
    }else{
        discont=0;
    }

    system("cls");
    printf("\t\t==========================\n");
    printf("\t\t|         PAY MONEY      |\n");
    printf("\t\t==========================\n");
    printf("\t\t==========================\n\n");
    printf("\t\tEnter Card Or Money :");
    scanf("%f",&enterMoney);
    printf("\n\t\t==========================\n");
    printf("\t\tOK..!,<--Please Click Any Key-->\n");
    getch();

    if(enterMoney>=priceOfOneItem[chooseItemIndex]){
        sellPrice=priceOfOneItem[chooseItemIndex]-discont;
        numberOfOneItem[chooseItemIndex]-=1;
        buyItemTotalPrice[chooseItemIndex]+=sellPrice;

        printBill(priceOfOneItem,chooseItemIndex,discont,itemArray,paymentMehtod,intPaymentMethod,
                  sellPrice,enterMoney);
    }else{
        system("cls");
        printf("Try agaen!\n");
    }
}

//Calculate Discount
//Giving a discount if card payment is made.
float calculateDiscount(float priceOfOneItem[20],int chooseItemIndex){
    return priceOfOneItem[chooseItemIndex]*(0.1);
}

//print Main bill
void printBill(float priceOfOneItem[20],int chooseItemIndex,float discont,char itemArray[20][20],
               char paymentMehtod[2][20],int intPaymentMethod,float sellPrice,float enterMoney){
    system("cls");
    writeTheFile(itemArray,priceOfOneItem,chooseItemIndex,discont,sellPrice);
    printf("\t\t===================================\n");
    printf("\t\t|            YOUR BILL            |\n");
    printf("\t\t===================================\n");
    printf("\t\t|    Discount For Card Payment!   |\n");
    printf("\t\t-----------------------------------\n");
    printf("\t\t|Item Name      : %-16s|\n",itemArray[chooseItemIndex]);
    printf("\t\t|Item Price     : Rs. %-12.2f|\n",priceOfOneItem[chooseItemIndex]);
    printf("\t\t|Payment Method : %-16s|\n",paymentMehtod[intPaymentMethod-1]);
    printf("\t\t|Discount       : Rs. %-12.2f|\n",discont);
    printf("\t\t|You Pay Price  : Rs. %-12.2f|\n",enterMoney);
    printf("\t\t|Total Price    : Rs. %-12.2f|\n",sellPrice);
    printf("\t\t|Balance        : Rs. %-12.2f|\n",enterMoney-sellPrice);
    printf("\t\t===================================\n");
    printf("\t\t|            Come Agean!          |\n");
    printf("\t\t===================================\n");
}

//Create a text file to store what items you are buying.
void createBuyitemFile(){
    FILE *filePointer;
    filePointer=fopen("Buy_Item_List.txt","w");
    //write
    fprintf(filePointer,"Item Name\tQTY\tItem Price\tDiscount\tSell_Price");
    fclose(filePointer);
}

//Store the item that the customer retrieves in the created text file.
void writeTheFile(char itemAraay[20][20],float priceOfOneItem[20],int chooseItemIndex,float discont,
                  float sellPrice){
    FILE *filePointer;
    filePointer=fopen("Buy_Item_List.txt","a");
    fprintf(filePointer,"\n%-15s\t1\t%0.2f\t\t%0.2f\t\t%0.2f",itemAraay[chooseItemIndex],
            priceOfOneItem[chooseItemIndex],discont,sellPrice);
    fclose(filePointer);
}
//-----------------------------------------------------------------------------------------------

