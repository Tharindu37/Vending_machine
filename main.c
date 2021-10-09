#include <stdio.h>
#include <stdlib.h>
int printItem(char itemArray[20][20],int numberOfItem[20]);
int printSettings();
int printSettings2(settingsArray2[3][10]);
int arraySize=5;
int main(){
    char itemArray[20][20]={"Water Bottles","Coca cola","Soda","Sprite","Pepsi"};//item array
    char settingsArray2[3][10]={"Change","Back","Exit"};
    int numberOfOneItem[20]={5,10,0,10,2};//number of one item array
    float priceOfOneItem[20]={100,70,150,80,90};//price of one item array
    int chooseItem=printItem(itemArray,numberOfOneItem);//call print item function
    int chooseSettings=0;
    if(chooseItem==-1){
        system("CLS");
        chooseSettings=printSettings();
    }else{
        ///////////////////////
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
//--->if Input -1
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
//Settings2
int printSettings2(settingsArray2[3][10]){
    int chooseSettings2=0;
    for(int i=0;i<3;i++){
        printf("%d. %s\n",i+1,settingsArray2[i]);
    }
    printf("<>Choose :");
    scanf("%d",&chooseSettings2);
}

