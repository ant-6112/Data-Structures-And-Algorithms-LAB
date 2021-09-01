#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct NODE{
    double data;
    struct NODE* next;
    struct NODE* prev;
};

struct LIST{
    struct NODE* head;
    struct NODE* tail;
};

struct NODE* createNode(double item){
    struct NODE* newnode = (struct NODE*)malloc(sizeof(struct NODE));
    newnode->data = item;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void addLast(struct LIST* lst, double item){
    struct NODE* nn = createNode(item);
    if(lst->head == NULL){ // SLL is empty
        lst->head = nn;
        lst->tail = nn;
        return;
    }
    lst->tail->next = nn; // forward  link
    nn->prev = lst->tail; // Backward link
    lst->tail = nn;
}

void addFirst(struct LIST* lst, double item){
    struct NODE* nn=createNode(item);
    if(lst->head == NULL){
        lst->head=nn;
        lst->tail=nn;
        return;
    }
    lst->head->prev = nn;
    nn->next = lst->head; // Linking the new node with the current list
    nn->prev = NULL;
    lst->head = nn;
}

double delLast(struct LIST* lst){
    double todel = INFINITY;
    if(lst->head==NULL){
        return todel;
    }else if(lst->head == lst->tail){
        todel = lst->head->data;
        free(lst->head);
        lst->head = NULL;
        lst->tail = NULL;
        return todel;
    }
    //struct NODE* delNode = lst->tail;
    //todel  = delNode->data;
    todel = lst->tail->data;
    //lst->tail = delNode->prev;
    lst->tail = lst->tail->prev;
    //lst->tail->next = NULL;
    free(lst->tail->next);
    lst->tail->next = NULL;
    //free(delNode);
    return todel;
}

int size(struct LIST* lst){
    int count = 0;
    for(struct NODE* temp = lst->head; temp ; temp=temp->next){
        count++;
    }
    return count;
}

void display(struct LIST* lst){
    printf("\n{");
    struct NODE* temp = NULL;
    for( temp = lst->head; temp!=NULL ; temp=temp->next ){
        printf(" %lf ", temp->data);
    }
    printf("}\n");
}

double delFirst(struct LIST* lst){
    double todel = INFINITY;
    if(lst->head == NULL){
        return todel;
    }else if(lst->head == lst->tail){
        todel = lst->head->data;
        free(lst->head);
        lst->head= NULL;
        lst->tail = NULL;
        return todel;
    }
    todel = lst->head->data;
    struct NODE* delNode = lst->head;
    lst->head = lst->head->next;
    lst->head->prev = NULL;
    free(delNode);
    return todel;
}


double delNode(struct LIST* lst, int pos){
    double todel  = INFINITY;
    struct NODE* temp;
    int count=0;
    if(lst->head==NULL){
        return todel;
    }
    if(pos == 1){
        todel = delFirst(lst);
        return todel;
    }

    for(temp = lst->head; temp!=NULL; temp=temp->next ){
        count++;
        if(count==pos){
            break;
        }
    }
    if(count!=pos){
        return todel;
    }
    if(temp==lst->tail){
        todel  = delLast(lst);
        return todel;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    todel = temp->data;
    free(temp);
    return todel;
}

double Recall(struct LIST* lst, int pos)
{

}

int main(){
    struct LIST lst;
    lst.head = NULL;
    lst.tail = NULL;

    addLast( &lst, 1.4 );
    display( &lst );

    addFirst( &lst, 100 );
    display(&lst);
    
    printf("Deleted element = %lf\n", delLast(&lst));
    display(&lst);

    printf("Deleted element = %lf\n", delFirst(&lst));
    display(&lst);

    printf("\nSize of the List: %d ", size(&lst));
    return 0;
}