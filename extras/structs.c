// #include<stdio.h>


// typedef struct bank_account
// {
//     int no;
//     char name[100];
//     int money;
// } acc;// acc is the alias 



// int main(){
//     int n;
//     acc accounts[10];
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&accounts[i].no);
//         gets(accounts[i].name);// ptr->name or (*ptr).name
//         scanf("%d",&accounts[i].money);
//     }
//     for(int i=0;i<n;i++){
//         printf("No. %d",accounts[i].no);
//         printf("\n");
//         puts(accounts[i].name);// ptr->name or (*ptr).name
//         printf("\n");
//         printf("Money %d",accounts[i].money);
//         printf("\n");
//     }
//     return 0;
// }

#include <stdio.h>
#include <string.h>

struct cricket {
  char player_name[20];
  char team_name[20];
  float batting_avg;
}
player[50], t;

void compare(struct cricket s1, struct cricket s2){
    if(s1.batting_avg>s2.batting_avg) 
    printf("Player one has a better batting average than Player two by %d runs", s1.batting_avg-s2.batting_avg);
    else
    printf("Player two has a better batting average than Player one by %d runs", -s1.batting_avg+s2.batting_avg);
}

int main(void) {
  int i = 0, j = 0, n = 10;

  for (i = 0; i < n; i++) {
    printf("\n Enter Player Name : ");
    scanf("%s", player[i].player_name);
    printf("\n Enter Team Name : ");
    scanf("%s", player[i].team_name);
    printf("\n Enter Batting Average : ");
    scanf("%f", & player[i].batting_avg);
  }
    int a,b;
    printf("Which two players to compare? (for e.g. 1st and 5th put 1 5)");
    scanf("%d %d", &a ,&b);
    compare(player[a-1],player[b-1]);
  return 0;
}