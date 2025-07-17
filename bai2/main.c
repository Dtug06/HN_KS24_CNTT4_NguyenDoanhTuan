#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node {
    char text[1000];
    struct Node* next;
} node;
typedef struct Stack {
    node* top;
} stack;
stack *createStack() {
  stack *s = malloc(sizeof(stack));
    s->top = NULL;
    return s;
}
node *createNode(char *text) {
    node* newNode= malloc(sizeof(node));
    strcpy(newNode->text,text);
    newNode->next=NULL;
    return newNode;
}
void push(stack *s,char *text) {
    node* newNode = createNode(text);
    newNode->next=s->top;
    s->top=newNode;
}
void peek(stack *s) {
    if (s->top==NULL) {
        printf("Stack is empty\n");
    }
    else {
        printf("%s\n",s->top->text);
    }
}
void printClipBoard(stack *s) {
    if (s->top==NULL) {
        printf("Stack is empty\n");
    }
        while (s->top!=NULL) {
            printf("%s\n",s->top->text);
            s->top=s->top->next;
        }
}
int undo(stack *s) {
    if (s->top->text==NULL) {
        printf("Stack is empty\n");
        return 0;

    }
    stack *current=s->top;
    s->top=s->top->next;
    free(current);
    return 1;
}
int main(void) {
    stack *s = createStack();
    int choice;
    do {
        printf("1.	Copy\n");
        printf("2.	PASTE\n");
        printf("3.	UNDO\n");
        printf("4.	Redo\n");
        printf("5.	Show \n");
        printf("6.	Exit\n");

        printf("Nhap lua chon\t");
        scanf("%d",&choice);
        switch (choice) {
            case 1://copy
                char text[1000];
                printf("Nhap chuoi ");
                getchar();
                fgets(text,1000,stdin);
                text[strlen(text)-1]='\0';
                push(s,text);
                break;
            case 2://paste
                peek(s);
                break;
            case 3://undo
                undo(s);
                break;
            case 4://redo
                printf("Sorry!! program building yet !");
                break;
            case 5://in toan bo
                printClipBoard(s);
                break;
            case 6://thoat
                printf("Thoat chuong trinh");
                break;
            default:
                printf("Choice ivalid !");
        }
    }while (choice!=6);
    return 0;
}