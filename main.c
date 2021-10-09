#include <stdio.h>
#include <stdlib.h>
void printItem(char itemArray[20][20],int numberOfItem[20]);
int arraySize=5;
int main(){
    char itemArray[20][20]={"Water Botties","Coca cola","Soda","Sprite","Pepsi"};//item array
    int numberOfOneItem[20]={5,10,0,10,2};//number of one item array
    float priceOfOneItem[20]={100,70,150,80,90};//price of one item array
    printItem(itemArray,numberOfOneItem);//call print item function
    return 0;
}
//Item print and get input.if input is -1 go settings
void printItem(char itemArray[20][20],int numberOfItem[20]){
    int chooseItem=0;
    for(int i=0;i<arraySize;i++){
        if(numberOfItem[i]!=0){
            printf("%d. %s\n",i+1,itemArray[i]);
        }
    }
    printf("<>Select the Item You Want? :");
    scanf("%d",&chooseItem);
}
