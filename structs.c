#include<stdio.h>


typedef struct bank_account
{
    int no;
    char name[100];
    int money;
} acc;// acc is the alias 



int main(){
    int n;
    acc accounts[10];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&accounts[i].no);
        gets(accounts[i].name);// ptr->name or (*ptr).name
        scanf("%d",&accounts[i].money);
    }
    for(int i=0;i<n;i++){
        printf("No. %d",accounts[i].no);
        printf("\n");
        puts(accounts[i].name);// ptr->name or (*ptr).name
        printf("\n");
        printf("Money %d",accounts[i].money);
        printf("\n");
    }
    return 0;
}