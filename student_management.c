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

void clearBuffer() {
    while (getchar()!='\n')
    {
        
    }
    
}

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
            printf("Student Id: %d\n",ptr->id);
            printf("Student Name: %s\n",ptr->name);
            printf("Student Age: %d\n",ptr->age);
            printf("Student Grade: %c\n",ptr->grade);
            printf("\n********************\n");
            ptr = ptr -> next;
        }
        
        
    }
    
    printf("\nPress Enter to continue\n");
    clearBuffer();
    getchar();
    clearConsole();
    
}


void searchid(){
    struct student *ptr;
    ptr = head;
    if (ptr==NULL)
    {
        printf("\nEmpty Database\n");
    } else {
        int target;
        printf("Enter the ID of the target student: ");
        scanf("%d",&target);
        while (ptr!=NULL)
        {
            if (ptr->id==target)
            {
                printf("\n********************\n");
                printf("Student Id: %d",ptr->id);
                printf("Student Name: %s",ptr->name);
                printf("Student Age: %d",ptr->age);
                printf("Student Grade: %c",ptr->grade);
                printf("\n********************\n");
                break;
            }
            ptr = ptr -> next;
            
        }
        
        
    }
    
    printf("\nPress Enter to continue\n");
    clearBuffer();
    getchar();
    clearConsole();
    
}

void deleteid(){
    struct student *ptr;
    struct student *prev_ptr;
    ptr = head;
    prev_ptr = ptr;
    if (ptr==NULL)
    {
        printf("\nEmpty Database\n");
    } else {
        printf("\nEnter the id of student to be Deleted: ");
        int target;
        scanf("%d",&target);
        while (ptr!=NULL)
        {
            printf("\nEnter the id of student to be Deleted: ");
            int target;
            scanf("%d",&target);
            if (ptr -> id == target)
            {
                prev_ptr -> next = ptr -> next;
                free(ptr);
                break;
            } else {
                
                prev_ptr = ptr;
                ptr = ptr -> next;
            }
            
        }
        
        
    }
    printf("\nPress Enter to continue\n");
    clearBuffer();
    getchar();
    clearConsole();
    
}


void addnew(){
    struct student *ptr;
    struct student *iterator;
    iterator = head;
    ptr = (struct student *) malloc(sizeof(struct student));

    
    
    if (head==NULL)
    {
        //head -> next = ptr; // This causes segmentation fault, because we are trying to access NULL 
        head = ptr;
        printf("\nEnter ID: ");
        scanf("%d",&ptr->id);
        clearBuffer();
        printf("\nEnter Name: ");
        fgets(ptr->name,1000,stdin); //We will use this to get the whole line as input
        //clearBuffer();
        printf("\nEnter Age: ");
        
        scanf("%d",&ptr->age);
        clearBuffer();
        printf("\nEnter Grade: ");
        scanf("%c",&ptr->grade);
        ptr->next = NULL;
    }else{
        while (1)
        {
            if (iterator->next==NULL)
            {
                iterator -> next = ptr;
                
                printf("\nEnter ID: ");
                scanf("%d",&ptr->id);
                clearBuffer();
                printf("\nEnter Name: ");
                fgets(ptr->name,1000,stdin); //We will use this to get the whole line as input
                //clearBuffer();
                printf("\nEnter Age: ");
        
                scanf("%d",&ptr->age);
                clearBuffer();
                printf("\nEnter Grade: ");
                scanf("%c",&ptr->grade);
                
                ptr->next = NULL;
                break;

            } else {
                iterator = iterator -> next;
            }
            
            
        }
        
    }
    printf("\nPress Enter to continue\n");
    clearBuffer();
    getchar();
    clearConsole();
    
}



void deleteall(){
    struct student *ptr;
    struct student *delete;
    ptr = head;
    if (ptr==NULL)
    {
        printf("\nDatabase Clear\n");
    } else {
        while (ptr->next!=NULL)
        {
            delete = ptr;
            ptr = ptr->next;
            free(delete);
            
        }
        free(ptr);
        head = NULL;
        printf("\nDatabase Cleared\n");
        

    }
    printf("\nPress Enter to continue\n");
    clearBuffer();
    getchar();
    clearConsole();
    
}