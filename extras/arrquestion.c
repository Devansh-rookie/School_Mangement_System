#include<stdio.h>

int duplicate(int a, int b){
    if(a==b) return 1;
    else return 0;
}

void print_runtime(int arr[]){// int n is not required because we have fixed sized static arr
    int flag;
    for(int i=0;i<20;i++){
        flag=0;
        for(int j=0;j<i;j++){
            if(duplicate(arr[i],arr[j])) flag=1;
        }
        if(!flag) printf("%d\n",arr[i]);
    }
}

int main(){
    int array[20];
    for(int i=0;i<20;i++) scanf("%d", &array[i]);
    print_runtime(array);
    return 0;
}

// using recursion fibonacci series fib n-1 and fib n-2 
// Sum of n natural numbers using recursion
// Digit Sum using recursion
// x,y swap function using pointers.
// arr input then sort function then return the array
