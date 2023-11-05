#include<stdio.h>

int largest_element(int arr[],int n){
    int max=arr[0];
    for (int i = 0; i < n; i++) if(arr[i]>max) max=arr[i];
    return max;
}

int *min_max_array(int arr[],int n){
    static int min_max_arr[2];
    int min=arr[0],max=arr[0],i;
    for(i=0;i<n;i++) if(arr[i]>max) max= arr[i];
    for(i=0;i<n;i++) if(arr[i]<min) min= arr[i];
    min_max_arr[0]=min;
    min_max_arr[1]=max;
    return min_max_arr;
}

int main(){
    int i,n;
    int *p;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    p=min_max_array(arr,n);
    for(i=0;i<2;i++){ 
        printf("%d\n",*p);
        p++;
    }
    return 0;
}