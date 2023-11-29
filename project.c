#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int n =0;// number of students in the system
int num;
typedef struct student{
    char fname[20];
    char lname[20];
    long long int roll_no;
    float cgpa;
    int course_id[25];
} std;

void add_student(std arr[]){
    printf("First Name of Student: ");
    fgets(arr[n].fname,100,stdin);
    printf("Last Name of Student: ");
    fgets(arr[n].lname,100,stdin);
    printf("Roll Number of Student: ");
    scanf("%ld",&arr[n].roll_no);
    printf("CGPA of Student: ");
    scanf("%f",&arr[n].cgpa);
    // int c;
    // scanf("Number of Courses taken by student",&c);
    for(int i=0;i<5;i++){// 5 Courses is the max taken by a student
        scanf("%d",&arr[n].course_id[i]);
    }
    n++;
}

void total_number_of_students(std arr[]){
    printf("Total number of students is %d.\n",n);
    printf("Total number of students allowed is: %d\n",num);
    printf("Total number of students which can still be added: %d\n", num-n);
}

void delete_student_roll(std arr[]){
    if(n==0) printf("There is no student in system");
    else{
        long int key;
        printf("Which roll number to delete?\n");
        scanf("%ld",&key);
        int i;
        for(i=0;i<n;i++){
            if(key==arr[i].roll_no) break;
        }
        for(int j=i;j<n;j++){
            arr[i]=arr[i+1];
        }
        n--;
    }
}


void delete_student_fname(std arr[]){
    if(n==0) printf("There is no student in system");
    else{
        char key[100];
        printf("Which First Name to delete?\n");
        fgets(key,100,stdin);
        int i;
        for(i=0;i<n;i++){
            if(!strcmp(key, arr[i].fname)) break;
        }
        for(int j=i;j<n;j++){
            arr[i]=arr[i+1];
        }
        n--;
    }
}

void find_by_rollnumber(std arr[]){
    int roll;
    printf("What is the roll number: ");
    scanf("%d",&roll);

    for(int i=0;i<n;i++){
        if(arr[i].roll_no==roll){
            printf("Roll Number: %ld\n", arr[i].roll_no);
            printf("First Name: %s\n", arr[i].fname);
            printf("Last Name: %s\n", arr[i].lname);
            printf("CGPA: %f\n", arr[i].cgpa);
            printf("\n");
            for(int j=0;j<5;i++){
                printf("CID: %d\n", arr[i].course_id[j]);
            }
            break;
        }
    }
}

void find_by_rollnumber(std arr[]){
    char fname;
    printf("What is the First Name: ");
    scanf("%d",&fname);

    for(int i=0;i<n;i++){
        if(!strcmp(arr[i].fname,fname)){
            printf("Roll Number: %ld\n", arr[i].roll_no);
            printf("First Name: %s\n", arr[i].fname);
            printf("Last Name: %s\n", arr[i].lname);
            printf("CGPA: %f\n", arr[i].cgpa);
            printf("\n");
            for(int j=0;j<5;i++){
                printf("CID: %d\n", arr[i].course_id[j]);
            }
            break;
        }
    }
}


void finalize_file(std arr[]){

}

int main(){

    printf("What do you want the MAX length of array to be?\n");
    scanf("%d",&num);
    std arr[num];

}