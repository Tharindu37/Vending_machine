#include <stdio.h>
#include <stdlib.h>
int printItem(char itemArray[20][20],int numberOfItem[20]);
int printSettings();
int printSettings2(char settingsArray2[3][10]);
void addMoreItems(char itemArray[20][20],int numberOfOneItem[20],float priceOfOneItem[20]);
void itemNameSet(char itemArray[20][20],int i);
void changePrice(char itemArray[20][20],float priceOfOneItem[20]);
void printProfit();
void addItemCount(char itemArray[20][20],int numberOfOneItem[20]);
int defaultOutPut(char itemArray[20][20],int numberOfOneItem[20]);
void printItemTable(char itemArray[20][20],int numberOfOneItem[20],float priceOfOneItem[20]);
void buyItem(float priceOfOneItem[20],float buyItemTotalPrice[20],int chooseItem,int numberOfOneItem[20],char itemArray[20][20]);
float calculateDiscount(float priceOfOneItem[20],int chooseItemIndex);
void printBill(float priceOfOneItem[20],int chooseItemIndex,float discont,char itemArray[20][20],char paymentMehtod[2][20],int intPaymentMethod,float sellPrice);
int arraySize=5;
int main(){
    char itemArray[20][20]={"Water_Bottles","Coca_cola","Soda","Sprite","Pepsi"};//item array
    char settingsArray2[3][10]={"Change","Back","Exit"};
    int numberOfOneItem[20]={5,10,0,10,2};//number of one item array
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
        buyItem(priceOfOneItem,buyItemTotalPrice,chooseItem,numberOfOneItem,itemArray);
        printf("Wall Come! Come Agean!<<Please Press Any Key>>");
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
        //
        chooseSettings=printSettings();
        goto settings;
    case 5:
        system("CLS");
        chooseSettings2=printSettings2(settingsArray2);
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
        system("CLS");
        chooseItem=printItem(itemArray,numberOfOneItem);
        goto settings;
    default:
        chooseItem=defaultOutPut(itemArray,numberOfOneItem);
        goto settings;
    }
    return 0;
}
//Item print and get input.if input is -1 go settings
int printItem(char itemArray[20][20],int numberOfItem[20]){
    int chooseItem=0;
    for(int i=0;i<arraySize;i++){
        if(numberOfItem[i]!=0){
            printf("\t%d. %s\n",i+1,itemArray[i]);
        }
    }
    printf("<<Edit System Settings For Enter -1>>\n");
    printf("<>Select the Item You Want? :");
    scanf("%d",&chooseItem);
    return chooseItem;
}
//Settings--->if Input -1
int printSettings(){
    int chooseSettings=0;
    char settingsArray[6][50]={"Add More Items","Change The Price","Item Table","The Profit","Increasing The Number Of Items","Exit"};
    for(int i=0;i<6;i++){
        printf("\t%d. %s\n",i+1,settingsArray[i]);
    }
    //printf("%s",settingsArray[0])
    printf("<>Choose :");
    scanf("%d",&chooseSettings);
    return chooseSettings;
}
//Settings 2
int printSettings2(char settingsArray2[3][10]){
    int chooseSettings2=0;
    for(int i=0;i<3;i++){
        printf("\t%d. %s\n",i+1,settingsArray2[i]);
    }
    printf("<>Choose :");
    scanf("%d",&chooseSettings2);
    return chooseSettings2;
}
//Settings--->if input 1--->Settings 2--->if input 1
void addMoreItems(char itemArray[20][20],int numberOfOneItem[20],float priceOfOneItem[20]){
    int noOfItems=0;
    printf("Enter Number Of Items :");
    scanf("%d",&noOfItems);
    for(int i=0;i<noOfItems;i++){
        printf("Enter Item %d Name :",i+1);
        scanf("%s",&itemArray[arraySize]);
        printf("Enter Item %d Price And Count(Ex:70.00,5) :",i+1);
        scanf("%f,%d",&priceOfOneItem[arraySize],&numberOfOneItem[arraySize]);
        arraySize++;
    }
}
//Settings--->if input 2--->Settings 2--->if input 1
void changePrice(char itemArray[20][20],float priceOfOneItem[20]){
    printf("<<If Not Change,Enter -1>>\n");
    for(int i=0;i<arraySize;i++){
        float temp=0;
        printf("Enter New Price For %s :",itemArray[i]);
        scanf("%f",&temp);
        if(temp>=0){
            priceOfOneItem[i]=temp;
        }
    }
}
//Settings--->if input 3--->Settings 2--->if input 1
void printItemTable(char itemArray[20][20],int numberOfOneItem[20],float priceOfOneItem[20]){
    system("CLS");
    printf("\tItem\t\tNumber Of Item\t\tPrice Of One Item\n");
    for(int i=0;i<arraySize;i++){
        printf("\t%-20s%d\t%25.2f\n",itemArray[i],numberOfOneItem[i],priceOfOneItem[i]);
    }
    printf("For Go Settings <--Please Click Any Key-->");
    getch();
    system("CLS");
}
//Settings--->if input 4--->Settings 2--->if input 1
void printProfit(){

}
//Settings--->if input 5--->Settings 2--->if input 1
void addItemCount(char itemArray[20][20],int numberOfOneItem[20]){
    for(int i=0;i<arraySize;i++){
        float temp=-1;
        printf("Enter New Price For %s :",itemArray[i]);
        scanf("%f",&temp);
        numberOfOneItem[i]+=temp;
    }
}
//default output
int defaultOutPut(char itemArray[20][20],int numberOfOneItem[20]){
    system("CLS");
    printf("Invalid Input..! <--Please Click Any Key-->");
    getch();
    system("CLS");
    int chooseItem=printItem(itemArray,numberOfOneItem);
    return chooseItem;
}
//buy items
void buyItem(float priceOfOneItem[20],float buyItemTotalPrice[20],int chooseItem,int numberOfOneItem[20],char itemArray[20][20]){
    int intPaymentMethod;
    int discont;
    int chooseItemIndex=chooseItem-1;
    int sellPrice;
    char paymentMehtod[2][20]={"Card Payment","cash Payment"};

    for(int i=0;i<2;i++){
        printf("%d. %s\n",i+1,paymentMehtod[i]);
    }
    printf("Choose Payment Method :");
    scanf("%d",&intPaymentMethod);

    if(intPaymentMethod==1){
        discont=calculateDiscount(priceOfOneItem,chooseItemIndex);
    }else{
        discont=0;
    }

    sellPrice=priceOfOneItem[chooseItemIndex]-discont;
    numberOfOneItem[chooseItemIndex]-=1;
    buyItemTotalPrice[chooseItemIndex]+=sellPrice;
    printBill(priceOfOneItem,chooseItemIndex,discont,itemArray,paymentMehtod,intPaymentMethod,sellPrice);
}
//calculate discont
float calculateDiscount(float priceOfOneItem[20],int chooseItemIndex){
    return priceOfOneItem[chooseItemIndex]*(0.1);
}
//print Main bill
void printBill(float priceOfOneItem[20],int chooseItemIndex,float discont,char itemArray[20][20],char paymentMehtod[2][20],int intPaymentMethod,float sellPrice){
    float enterMoney;
    system("cls");
    printf("Enter Card Or Money :");
    scanf("%f",&enterMoney);
    printf("Item Name :%s\n",itemArray[chooseItemIndex]);
    printf("Payment Method :%s\n",paymentMehtod[intPaymentMethod-1]);
    printf("Item Price : %0.2f\n",priceOfOneItem[chooseItemIndex]);
    printf("For card payment :Discount : 10%\nFor Cash payment : Discount : 0%\n");
    printf("Discount : %0.2f\n",discont);
    printf("Total Price : %0.2f\n",sellPrice);
    printf("Balance : %0.2f\n",enterMoney-sellPrice);
}

