#include <stdio.h>

////////////////////////////////////////////////////
/////////////  Rouvem Pishchik   ///////////////////
///////////// LINKED LIST SOL'N ////////////////////
////////////////////////////////////////////////////

typedef struct record{ // Node
    int data;
    struct record *next;
}Node;

// All of these below are functions

void add(Node *p, int num) // adds a Node to the linked list
{
    while(p->next!= NULL){
        p = p->next;
    }
    Node *newp = (Node*)malloc(sizeof(Node));
    if(newp == NULL){
        fprintf(stderr, "Unable to allocate memory for new node\n");
        exit(-1);
    }
    p->next = newp;
    newp->data = num;
    newp->next = NULL;
}

void peek(Node *p){ // prints out the data in the list
    Node *start = p;
    while(start != NULL){
        printf("%d\n", start->data);
        start = start->next;
    }
}

void rem(Node *p, int num) // first remove function, removes a specific node with int num
{   //doesn't return anything, just void
    Node *temp;
    if(p->data == num){
        temp = p->next;
        free(p);
        p = temp;
        return;
    }
    while(p->next->data != num){
        p = p->next;
        if(p->next == NULL){
            return;
        }
    }
    temp = p->next->next;
    free(p->next);
    p->next = temp;
}

Node* rem2(Node *p, int num){ // second remove function (acts the same as the first)
    if(p == NULL){          // uses recursion instead then returns the Node
        printf("Data not found\n");
        return NULL;
    }
    if(p->data == num){
        Node *temp = p->next;
        free(p);
        p = temp;
        return temp;
    }
    p-> next= rem2(p->next, num);
    return p; //must always return the calling pointer and reassign it in main...
}

int main()
{
    int i;

    Node *p = (Node *)malloc(sizeof(Node)), *head = p; // allocate memory for first node and declare second node head (you don't really need it)

    p->next = NULL; //first node has data 0, next is NULL;
    p->data = 0;

    add(head, 10); //2nd node
    add(head, 20); //3rd node
    add(head, 80); //4th node;
    peek(head);
    printf("\n");

    rem(head, 20); //remove node with the data = 20
    peek(head);
    printf("\n");

    head = rem2(head, 0); // remove the node with the data = 0 (first node)
    peek(head);
    printf("\n");

    rem(head, 12); // doesn't do anything
    peek(head);
    free(head);
    free(p);
    
    return 0;
}
