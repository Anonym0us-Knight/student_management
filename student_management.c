#include<stdio.h>
#include<stdlib.h>

//In order to allow any numbers of records to be added, I will try to use a linked list
struct student{
    int id;
    char name[1000];
    int age;
    char grade;
    struct student *next;
};

struct student *head = NULL;

void showall();
void searchid();
void deleteid();
void addnew();
void deleteall();

void clearConsole() {
    #ifdef _WIN32
        system("cls"); // Windows command to clear console
    #else
        system("clear"); // Linux/macOS command to clear console
    #endif
}

int main(){
    int t = 1;
    printf("\n **Welcome** \n Student Management System Version 1.0\n");
    while(t!=0){
        
        int option = 0;
        printf("\nEnter your desired operation\n");
        printf("\n[1] Show all Students\n");
        printf("\n[2] Search for specific student\n");
        printf("\n[3] Delete a specific student\n");
        printf("\n[4] Add a student\n");
        printf("\n[5] Clear the Database \n");
        printf("\n[6] Exit");
        printf("\nEnter:");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            showall();
            break;
        case 2:
            searchid();
            break;
        case 3:
            deleteid();
            break;
        case 4:
            addnew();
            break;
        case 5:
            deleteall();
            break;
        case 6:
            t = 0;
            break;
        
        default:
            break;
        }

    }
}

void showall(){
    struct student *ptr;
    ptr = head;
    if (ptr==NULL)
    {
        printf("\nEmpty Database\n");
    }else{
        while (ptr!=NULL)
        {
            printf("\n********************\n");
            printf("Student Id: %d",ptr->id);
            printf("Student Name: %s",ptr->name);
            printf("Student Age: %d",ptr->age);
            printf("Student Grade: %c",ptr->grade);
            printf("\n********************\n");
        }
        char key;
        printf("\nPress any key to continue\n");
        scanf("%c",&key);
        clearConsole();
        
    }
    
}


