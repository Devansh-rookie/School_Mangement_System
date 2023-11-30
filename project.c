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
    float attendance;
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
    printf("Attendance: ");
    scanf("%f",&arr[n].attendance);

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

void find_by_fname(std arr[]){
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

void update_student(std arr[]){
    int roll;
    printf("What is the roll number: ");
    scanf("%d",&roll);
    int i;
    for(i=0;i<n;i++){
        if(arr[i].roll_no==roll) break;
    }
    int x=i;
    a:
    printf("Choose the number:\n1. First Name\n2. Last Name\n3. Roll No.\n4. CGPA\n5. Courses\n6. Exit\n");
    int ch;
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("Updated First Name: ");
            fgets(arr[x].fname,100,stdin);
            break;
        case 2:
            printf("Updated Last Name: ");
            fgets(arr[x].lname,100,stdin);
            break;
        case 3:
            printf("Updated Roll Number: ");
            scanf("%ld",&arr[x].roll_no);
            break;
        case 4:
            printf("Updated CGPA: ");
            scanf("%f",&arr[x].cgpa);
            break;
        case 5:
            printf("Enter New courses: ");
            for(int i=0;i<5;i++){// 5 Courses is the max taken by a student
                scanf("%d",&arr[n].course_id[i]);
            }
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Enter a valid value.");
            goto a;
    }
}


void short_attendance(std arr[]){
    int flag =1,count=0;
    for(int i=0;i<n;i++){
        if(arr[i].attendance<75){// attendance in percent
            printf("Roll Number: %ld\n", arr[i].roll_no);
            printf("First Name: %s\n", arr[i].fname);
            printf("Last Name: %s\n", arr[i].lname);
            printf("CGPA: %f\n", arr[i].cgpa);
            printf("\n");
            for(int j=0;j<5;i++){
                printf("CID: %d\n", arr[i].course_id[j]);
            }
            flag =0;
            count++;
        }
    }
    printf("Total number of students with short attendance: %d", count);
    if(flag){
            printf("Everybody is eligible for exams.\n");
    }
}

void total_pass_fail(std arr[]){
    int flag =1,count=0;
    for(int i=0;i<n;i++){
        if(arr[i].cgpa<4.0){// attendance in percent
            printf("Roll Number: %ld\n", arr[i].roll_no);
            printf("First Name: %s\n", arr[i].fname);
            printf("Last Name: %s\n", arr[i].lname);
            printf("CGPA: %f\n", arr[i].cgpa);
            printf("\n");
            for(int j=0;j<5;i++){
                printf("CID: %d\n", arr[i].course_id[j]);
            }
            flag =0;
            count++;
        }
    }
    printf("Total number of students failed: %d", count);
    if(flag){
            printf("Everybody has passed.\n");
    }
}

void avg_cgpa(std arr[]){
    float avg_cg=0.0, sum=0.0;
    for(int i=0;i<n;i++){
        sum+= arr[i].cgpa; 
    }
    avg_cg = (float)sum/n;
    printf("The average CGPA of the class is %f", avg_cg);
}

void finalize_file(std arr[]){

}

void toppers_list(std arr[]){
    std arr2[num];
    for(int i=0;i<n;i++){
        arr2[i]=arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr2[j].cgpa<arr2[j+1].cgpa){
                float temp = arr2[j].cgpa;
                arr2[j].cgpa=arr2[j+1].cgpa;
                arr2[j+1].cgpa=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("Rank: %d is %s %s with CGPA %f\n",i+1,arr2[i].fname,arr2[i].lname,arr2[i].cgpa);
    }
}

int main(){

    printf("What do you want the MAX length of array to be?\n");
    scanf("%d",&num);
    std arr[num];

}