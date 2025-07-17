#include <stdio.h>
#include <stdlib.h>
#include<string.h>

 typedef struct Project {
    int id;
    char title[100];
    char owner[100];
    int priority;
    struct Project *next;
}project;
int idCounter = 1;
project *createProject( const char *title, const char *owner, int priority) {
    project *newProject=(project*)malloc(sizeof(project));
    newProject->id=idCounter++;
    strcpy(newProject->title,title);
    strcpy(newProject->owner,owner);
    newProject->priority=priority;
    newProject->next=NULL;
    return newProject;
};
project *push(project *head,project *newProject) {
    if (head==NULL) {
        head=newProject;
        return head;
    }
    project *temp=head;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newProject;
    return head;
}
void display(project *head) {
    project *temp=head;
    while (temp!=NULL) {
        printf("%s %s %d\n",temp->title,temp->owner,temp->priority);
        temp=temp->next;
    }
    printf("\n");
}
project *deleteProjectByid(project *head,int id) {
    project *temp=head;
    if (head==NULL) {
        return NULL;
    }
    while (temp->next!=NULL&&temp->next->id!=id) {
        temp=temp->next;
    }
    if (temp->next==NULL) {
        return NULL;
    }
    project *toDelete=temp->next;
    temp->next=toDelete->next;
    free(toDelete);
    return head;
}
void *search(project *head,char *name) {
    project *temp=head;
    if (head==NULL) {
        printf("Khong timm thay phan tu hop le ");
        return NULL;
    }
    while (temp->title!=NULL&&strcmp(temp->title,name)!=0) {
        temp=temp->next;
    }
    if (temp==NULL) {
        printf("Khong timm thay phan tu hop le ");
        return NULL;
    }
    printf("%s %s %d\n",temp->title,temp->owner,temp->priority);
}
int main(void) {
    project *head=NULL;
    int choice;
    int idToDelete;
    do {
        printf("1:Them du an \n");
        printf("2:Hien thi danh sach\n");
        printf("3:Xoa du an \n");
        printf("4:Cap nhat thong tin du an\n");
        printf("5:Danh dau da hoan thanh\n");
        printf("6:Sap xep du an  theo do uu tien \n");
        printf("7:Tim kiem du an theo ten \n");
        printf("8:Thoat chuong tirnh\n");
        printf("Nhap lua chon\t");
        scanf("%d",&choice);
        switch (choice) {
            case 1://Thêm mới dự án
            {
                int id;
                char title[100];
                char owner[100];
                int priority;
                printf("Nhap title: ");
                getchar();
                fgets(title,100,stdin);
                title[strcspn(title,"\n")]=0;
                printf("Nhap priority: ");
                scanf("%d",&priority);
                getchar();
                printf("Nhap owner: ");
                fgets(owner,100,stdin);
                owner[strcspn(owner,"\n")]=0;
                head=push(head,createProject(title,owner,priority));
            }
                break;
            case 2://hien thi danh sach
                display(head);
                break;
            case 3:
                printf("Nhap id muon xoa: ");
                scanf("%d",&idToDelete);
                getchar();
                head=deleteProjectByid(head,idToDelete);
                display(head);
                break;
            case 4:
                printf("Sorry!! program building yet !");
                break;
            case 5:
                printf("Sorry!! program building yet !");
                break;
            case 6:
                printf("Sorry!! program building yet !");
                break;
            case 7://tim kiem theo ten
                char title[100];
                printf("Nhap title: ");
                getchar();
                fgets(title,100,stdin);
                title[strcspn(title,"\n")]=0;
                search(head,title);
                break;
            case 8://thoat
                printf("Thoat chuong trinh");
                break;
            default:
                printf("Choice ivalid !");
        }
    }while (choice!=8);
    return 0;
}