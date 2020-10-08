#include<stdio.h>
#include"conio.h"
#include"stdlib.h"

typedef struct Node
{
  int info;
  struct Node *next;
}node;
void traverse_list();
node* insert_end(void);
node* creat_node(void);
void insert_after(int);
void insert_at(int);
node* insert_begin(void);
node* delete_end(void);
node* delete_begin(void);
void delete_after(int);
//void delete_at(int);
int countnodes(void);
node *head;

////////////////----main----////////////////////////

void main(){
  node *ptr;
  int key, c;
  printf("first node that is head node is created first to perform operation\n\n");
  head=creat_node();
  do
    {
  printf("press 1--- to insert node at beginning\n");
  printf("press 2--- to insert node at end\n");
  printf("press 3--- to insert node after a given node\n");
  printf("press 4--- to insert node at a given position\n");
  printf("press 5--- to delete node at beginning\n");
  printf("press 6--- to delete node at end\n");
  printf("press 7--- to delete node after a given node\n");
  //printf("press 8--- to delete node at a given position");
  printf("press 9--- to get the total no of nodes\n");
  printf("press 10--- to exit\n");
  printf("____________________________________________________________________\n");
  printf("enter your choice-\n");
  scanf("%d",&c);

  switch(c)
    {
        case 1:
                        insert_begin();
                        traverse_list();
        break;
        case 2:
                        insert_end();
                        traverse_list();
        break;
        case 3:
                        printf("enter the key\n");
                        scanf("%d",&key);
                        insert_after(key);
                        traverse_list();
        break;
        case 4:
                        printf("enter the position\n");
                        scanf("%d",&key);
                        insert_at(key);
                        traverse_list();
        break;
        case 5:
                        delete_begin();
                        traverse_list();

        break;
       case 6:
                        delete_end();
                        traverse_list();
        break;
        case 7:
                        printf("enter the key\n");
                        scanf("%d",&key);
                        delete_after(key);
                        traverse_list();
        break;
        case 8:
                        printf("enter the position\n");
                        scanf("%d",&key);
    //                    delete_at(key);
                        traverse_list();
        break;
        case 9:
                       printf("this linked list has %d nodes.\n", countnodes());
        break;
         default: break;
  }
}while(c!=10);
    printf("\nThank you for using the program\npress enter to exit");

getch();

}
/////////////////////////----create node function----//////////////////////////////////////////////

  node* creat_node(void){
  node *new_node;
  new_node=(node*)malloc(sizeof(node));
  printf("enter info for new node: ");
  scanf("%d",&new_node->info);
  new_node->next=NULL;
  return new_node;
}

//////////////////////----traverse_list----/////////////////////////////////////////////////////////////////
void traverse_list()
{  node *ptr;
    ptr=head;
    printf("the linked list is-\n");
    while(ptr!=NULL)
        {
            printf("%d ",ptr->info);
            ptr=ptr->next;
        }
        printf("\n\n");
}
///////////////////// ----Insert Node at end----//////////////////////////////////////////////////////

node* insert_end(void){
    node *h,*tp;
    tp=head;
    h=creat_node();

    if(tp->next==NULL)
        {
           tp->next=h;
        }
    else
    {
        while(tp->next!=NULL)
            {
                tp=tp->next;
            }
        tp->next=h;
    }
    h->next=NULL;
    return head;
}

////////////////----insert_begin----//////////////
node* insert_begin()
{
    node *n;
    n=creat_node();
    n->next=head;
    head=n;
    return head;
}

////////////////----insert_after----////////////////

void insert_after(int key)
{
    node *n, *tp, *temp;
    int flag=0;
    n=creat_node();
    tp=head;

    if(head!=NULL)
    {
        while(tp->next!=NULL&&tp->info!=key)
            tp=tp->next;
        if(tp->info==key)
        {
            if(tp->next!=NULL)
            {
                flag=1;
                temp=tp->next;
            }
            tp->next=n;
            if(flag==1)
            {
                n->next=temp;
            }
        }
        else printf("key not found");
    }
    else printf("link list is empty");

}

///////////////////////////----insert_at----//////////////////////

void insert_at(int k)
{
    int n=1;
    node *tp;
    tp=head;
    if(k==1)//  at Head position
    {
        insert_begin();
    }
    else
    {
        while(n<(k-1)&&tp->next!=NULL)
        {
            ++n;
            tp=tp->next;
        }
        node *new_node =creat_node();
        new_node->next=tp->next;
        tp->next=new_node;
    }
}

///////////////////////////----delete_begin----///////////////////////

node* delete_begin()
{
    node *tp;
    tp=head;
    head=tp->next;
    free(tp);
    return head;
}

///////////////////////////----delete_end----///////////////////////
node* delete_end()
{
    node *tp,*temp;
    tp=head;
    if(head!=NULL)
    {
        if(head->next==NULL)
        {
            free(head);
            head=NULL;
        }
        else
            {
                while(tp->next!=NULL)
                       {
                            temp=tp;
                            tp=tp->next;
                       }
                 free(tp);
                temp->next=NULL;

            }
    }
    else printf("linked list is empty");

}
////////////////////-----void delete_after----////////////////////////////////

void delete_after(int key)
{
    node  *temp, *tp;


    tp=head;

    if(head!=NULL)
    {
        while(tp->next!=NULL&&tp->info!=key)
            tp=tp->next;
        if(tp->info==key)
        {
            if(tp->next!=NULL)
            {
                temp=tp->next;
                tp->next=temp->next;
            }
            else
            {
               delete_end();
            }

                free(temp);

        }
        else printf("key not found, so cannot delete.");
    }
    else printf("link list is empty");
}

/////////----countnodes()--------///////////////////////

int countnodes(void)
{
    int n=1;
    node *tp;
    tp=head;
    if(head==NULL)
    {
        return (0);
    }
    else
    {
        while(tp->next!=NULL)
        {
            ++n;
            tp=tp->next;
        }
        return n;
    }
}

