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
    int course_id[5];
} std;

void add_student(std arr[]){
    printf("First Name of Student: ");
    scanf(" %[^\n]s",arr[n].fname);// %[^\n]%*c
    printf("Last Name of Student: ");
    // fgets(arr[n].lname,100,stdin);
    scanf(" %[^\n]s",arr[n].lname);
    printf("Roll Number of Student: ");
    scanf("%lld",&arr[n].roll_no);
    printf("CGPA of Student: ");
    scanf("%f",&arr[n].cgpa);
    // int c;
    // scanf("Number of Courses taken by student",&c);
    printf("Courses: ");
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
            arr[j]=arr[j+1];
        }
        n--;
    }
}


void delete_student_fname(std arr[]){
    if(n==0) printf("There is no student in system");
    else{
        char key[100];
        printf("Which First Name to delete?\n");
        scanf(" %[^\n]s",key);
        int i;
        for(i=0;i<n;i++){
            if(!strcmp(key, arr[i].fname)) break;
        }
        for(int j=i;j<n;j++){
            arr[j]=arr[j+1];
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
            printf("Roll Number: %lld\n", arr[i].roll_no);
            printf("First Name: %s\n", arr[i].fname);
            printf("Last Name: %s\n", arr[i].lname);
            printf("CGPA: %f\n", arr[i].cgpa);
            printf("\n");
            for(int j=0;j<5;j++){
                printf("CID: %d\n", arr[i].course_id[j]);
            }
            break;
        }
    }
}

void find_by_fname(std arr[]){
    char fname;
    printf("What is the First Name: ");
    scanf("%s",&fname);

    for(int i=0;i<n;i++){
        if(!strcmp(arr[i].fname,&fname)){
            printf("Roll Number: %lld\n", arr[i].roll_no);
            printf("First Name: %s\n", arr[i].fname);
            printf("Last Name: %s\n", arr[i].lname);
            printf("CGPA: %f\n", arr[i].cgpa);
            printf("\n");
            for(int j=0;j<5;j++){
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
            scanf("%lld",&arr[x].roll_no);
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
            printf("Roll Number: %lld\n", arr[i].roll_no);
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
            printf("Roll Number: %lld\n", arr[i].roll_no);
            printf("First Name: %s\n", arr[i].fname);
            printf("Last Name: %s\n", arr[i].lname);
            printf("CGPA: %f\n", arr[i].cgpa);
            printf("\n");
            for(int j=0;j<5;j++){
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
    FILE *fp;
    fp= fopen("student_database.txt","w");
    // can also take from user
    for(int i=0;i<n;i++){
        fprintf(fp,"Roll Number: %lld\n", arr[i].roll_no);
        fprintf(fp,"First Name: %s\n", arr[i].fname);
        fprintf(fp,"Last Name: %s\n", arr[i].lname);
        fprintf(fp,"CGPA: %f\n", arr[i].cgpa); 
        fprintf(fp,"Attendance: %f\n",arr[i].attendance);
        for(int j=0;j<5;j++){
                fprintf(fp,"CID: %d\n", arr[i].course_id[j]);
        }
        fprintf(fp,"\n\n");
    }
    fclose(fp);
}

// void read_existing(std arr[]){

// }

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
    int ch;
    b:
    printf("Main Menu: Choose the number\n");
    printf("1. Add Student\n2. Total Students\n3. Delete Student(First Name)\n4. Delete Student(Roll Number)\n5. Find Student(by First Name)\n6. Find Student(by Roll Number)\n7. Update Student\n8. Short Attendance Student\n9. Total Students Failed in the Examination\n10. Average CGPA\n11. Topper List\n12. Dump Database in File\n13. Exit\nChoice: ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        add_student(arr);
        goto b;
        break;
    case 2:
        total_number_of_students(arr);
        goto b;
        break;
    case 3:
        delete_student_fname(arr);
        goto b;
        break;
    case 4:
        delete_student_roll(arr);
        goto b;
        break;
    case 5:
        find_by_fname(arr);
        goto b;
        break;
    case 6:
        find_by_rollnumber(arr);
        goto b;
        break;
    case 7:
        update_student(arr);
        goto b;
        break;
    case 8:
        short_attendance(arr);
        goto b;
        break;
    case 9:
        total_pass_fail(arr);
        goto b;
        break;
    case 10:
        avg_cgpa(arr);
        goto b;
        break;
    case 11:
        toppers_list(arr);
        goto b;
        break;
    case 12:
        finalize_file(arr);
        goto b;
        break;
    case 13:
        exit(0);
        goto b;
        break;
    default:
        goto b;
        break;
    }
    return 0;
}