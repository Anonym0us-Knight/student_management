#include<stdio.h>
#include<stdlib.h>
//In order to allow any numbers of records to be added, I will try to use a linked list
struct student{
    int id;
    int name;
    int age;
    int grade;
    struct student *next;
};

struct student *head = NULL;

