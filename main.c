#include <stdio.h>
#include <stdlib.h>
int printItem(char itemArray[20][20],int numberOfItem[20]);
int printSettings();
int printSettings2(char settingsArray2[3][10]);
void addMoreItems(char itemArray[20][20],int numberOfOneItem[20],float priceOfOneItem[20]);
void itemNameSet(char itemArray[20][20],int i);
int arraySize=5;
int main(){
    char itemArray[20][20]={"Water Bottles","Coca cola","Soda","Sprite","Pepsi"};//item array
    char settingsArray2[3][10]={"Change","Back","Exit"};
    int numberOfOneItem[20]={5,10,0,10,2};//number of one item array
    float priceOfOneItem[20]={100,70,150,80,90};//price of one item array
    int chooseItem=printItem(itemArray,numberOfOneItem);//call print item function

    int chooseSettings=0;
    int chooseSettings2=0;
    //Item Choose
    settings:
    if(chooseItem==-1){
        system("CLS");
        chooseSettings=printSettings();
    }else{
        ///////////////////////
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
            chooseItem=printItem(itemArray,numberOfOneItem);
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
            break;
            //
        }
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    default:
        break;
    }
    return 0;
}
//Item print and get input.if input is -1 go settings
int printItem(char itemArray[20][20],int numberOfItem[20]){
    int chooseItem=0;
    for(int i=0;i<arraySize;i++){
        if(numberOfItem[i]!=0){
            printf("%d. %s\n",i+1,itemArray[i]);
        }
    }
    printf("<>Select the Item You Want? :");
    scanf("%d",&chooseItem);
    return chooseItem;
}
//--->if Input -1(Settings)
int printSettings(){
    int chooseSettings=0;
    char settingsArray[6][50]={"Add More Items","Change The Price","The Number Of Items Available","Looking At The Profit","Increasing The Number Of Items","Exit"};
    for(int i=0;i<6;i++){
        printf("%d. %s\n",i+1,settingsArray[i]);
    }
    printf("<>Choose :");
    scanf("%d",&chooseSettings);
    return chooseSettings;
}
//Settings 2
int printSettings2(char settingsArray2[3][10]){
    int chooseSettings2=0;
    for(int i=0;i<3;i++){
        printf("%d. %s\n",i+1,settingsArray2[i]);
    }
    printf("<>Choose :");
    scanf("%d",&chooseSettings2);
    return chooseSettings2;
}
//Settings--->Settings 2--->if input 1
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


