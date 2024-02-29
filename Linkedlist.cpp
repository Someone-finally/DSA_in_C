//Using a Cpp compiler to program Linked List in C 

//A linked list is a fundamental data structure in computer science. 
//It consists of nodes where each node contains data and a reference (link) to the next node in the sequence. 
//This allows for dynamic memory allocation and efficient insertion and deletion operations compared to arrays.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//array of values for initializing Linked list
int A[] = {1,2,3,3,4,7,8,9,10,100};
int B[]= {7,10,11,200};

 struct Node{
  int data;
  struct Node *next;
};


struct Node *last,*temp,*first, *temp1;


struct Node* initialise_linked(int A[], int len)
{
    int i =0;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next =NULL;
    last=first;

    for(i=1;i<len;++i)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    return first;

}
void display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;

    }

}

void link_insert(struct Node *p)
{
    int x = 4;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));


    while(p)
    {
        if(((p->next)->data) > x && p->data < x)
        {
            temp->data = x;
            temp->next = (p->next);
            p->next = temp;
        }

        p = p->next;
    }
}

void delete_Node(struct Node* p, int x)
{
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node*));
    while(p)
    {
        //first check is if (p->next)->value ==x

        if((p->next)->data == x)
        {
           // printf("%d \n",(p->next)->data);
            temp = p->next;
            p->next = ((p->next)->next);
            free(temp);
            break;
        }
        p = p->next;
    }

}

void removemult_Nodes(struct Node* p)
{
    struct Node* temp;

    while(p)
    {
        if(p->data == (p->next)->data)
        {
            temp = (struct Node*)malloc(sizeof(struct Node*));
            temp = p->next;
            p->next = (p->next)->next;
            free(temp);
        }
        p = p->next;
    }

}

struct Node* mergeTwoLists(struct Node* list1, struct Node* list2) {

    struct Node *last,*first;

     if(list1->data <= list2->data)
     {
         first = last = list1;
         list1 = list1->next;
         last->next = NULL;

     }

        else if(list1->data > list2->data)
     {
         first = last = list2;
         list2 = list2->next;
         last->next = NULL;
     }

    while(list1 && list2)
    {

        if(list1->data <= list2->data)
        {
            last->next = list1;
            last = list1;
            list1 = list1->next;
            last->next = NULL;
        }
        else if( list2->data < list1->data)
        {
            last->next = list2;
            last = list2;
            list2 = list2->next;
            last->next = NULL;
        }
    }

    if(list1)
    {
        last->next = list1;
    }
    else if(list2)
        last->next =list2;

     return first;

}


int main()
{
 struct Node* A_data ,*B_data;
 
//1 - Initializing Linked list 
    A_data = initialise_linked(A,10);
    B_data = initialise_linked(B,4);

//2 - Inserting into a sorted Linked list 
    link_insert(first);

   
//3 - Delete a specific Node from Linked list 
    delete_Node(first,7);
	
//4 - Remove multiple similar Nodes from sorted Linked list
    removemult_Nodes(first);
	
//5 - Display the Linked list 
    display(A_data);
   //display(B_data);
   
//6 - Merge two Linked list together 
    temp1 = mergeTwoLists(A_data, B_data);
    display(temp1);

    return 0;
}
