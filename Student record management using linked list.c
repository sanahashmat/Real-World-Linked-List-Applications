#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
    int roll_no;
    char name[100];
    float marks;
    struct student *next;
}node;
node *create_list();
void display(node *);
void count(node *);
void search(node *,int);
node *addatbeg(node *);
node *addatend(node *);
node *addafter(node *,int);
node *addbefore(node *,int);
node *addatpos(node *,int);
node *del(node *,int);
node *reverse(node *);

void main(){
    int choice,data,item,pos;
    node *start;
    start=NULL;
    do
    {
        printf("ENTER YOUR CHOICE\n");
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Count\n");
        printf("4.Search\n");
        printf("5.Add to empty list / Add at beginning\n");
        printf("6.Add at end\n");
        printf("7.Add after node\n");
        printf("8.Add before node\n");
        printf("9.Add at position\n");
        printf("10.Delete\n");
        printf("11.Reverse\n");
        printf("12.Quit\n\n");
        
        printf("Enter your choice : ");
        scanf("%d",&choice);
        
        switch(choice)
        {
         case 1:
            start=create_list();
            break;
         case 2:
            display(start);
            break;
         case 3:
            count(start);
            break;
         case 4:
            printf("Enter the element to be searched : ");
            scanf("%d",&data);
            search(start,data);
            break;
        case 5:
            start=addatbeg(start);
            break;
         case 6:
            start=addatend(start);
            break;
         case 7:
            printf("Enter the roll no after which to insert : ");
            scanf("%d",&item);
            start=addafter(start,item);
            break;
         case 8:
            
            printf("Enter the roll no before which to insert : ");
            scanf("%d",&item);
            start=addbefore(start,item);
            break;
         case 9:
            printf("Enter the position at which to insert : ");
            scanf("%d",&pos);
            start=addatpos(start,pos);
            break;
         case 10:
            printf("Enter the roll no to be deleted : ");
            scanf("%d",&data);
            start=del(start, data);    
            break;
         case 11:
            start=reverse(start);
            break;
         case 12:
             exit(0);
         default:
             printf("Wrong choice\n");
        }/*End of switch */
    }while(choice!=12);/*End of while */
}/*End of main()*/
node *create_list()
{
    int roll,flag = 1;
    float marks;
    char Name[100];
    char ans='y';
    node *tem,*new,*start;
    node *getnode();
    tem=NULL;
    do
    {
        printf("Enter the roll number : ");
        scanf("%d",&roll);
        printf("Enter name of student : ");
        _flushall();
        gets(Name);
        printf("Enter the marks : ");
        scanf("%d",&marks);
        new=getnode();
        if(new==NULL)
        printf("\nMemory is not allocated : ");
        new->roll_no=roll;
        strcpy(new->name,Name);
        new->marks=marks;
        if(flag==1)
        {
            start=new;
            tem=start;
            flag=0;
        }
        else
        {
            tem->next=new;
            tem=new;
        }
    printf("\nDo you want to enter more elements(y/n) : ");
    ans=getche();
    } while (ans=='y');
    printf("\nThe single linked list is created\n");
    return start;
}/*End of create_list()*/
node *getnode()
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->next=NULL;
    return temp;
}
void display(node *start)
{
    node *p;
    p=start;
    if(p==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List is :\n");
    while(p!=NULL)
    {
        _flushall();
        printf("%d|%s|%0.2f| \n",p->roll_no,p->name,p->marks);
        p=p->next;
    }
    printf("\n\n");
}/*End of display() */
void count(node *start)
{
    node *p;
    int cnt=0;
    p=start;
    while(p!=NULL)
    {
        p=p->next;
        cnt++;
    }
    printf("Number of elements are %d\n",cnt);
}/*End of count() */
void search(node *start,int data)
{
    node *p;
    p=start;
    int pos=1;
    while(p!=NULL)
    {
        if(p->roll_no==data)
        {
            printf("Item %d found at position %d\n",data,pos);
            return;
        }
        p=p->next;
        pos++;
    }
    printf("Item %d not found in list\n",data);
}/*End of search()*/
node *addatbeg(node *start)
{
    node *tmp,*new;
    new=getnode();
    printf("Enter the roll no : ");
    scanf("%d",&new->roll_no);
    printf("Enter the name : ");
    _flushall();
    gets(new->name);
    printf("Enter the marks : ");
    scanf("%f",&new->marks);
    if(start==NULL)
    start=new;
    else
    {
        tmp=start;
        new->next=tmp;
        start=new;
    }
    return start;
}/*End of addatbeg()*/
node *addatend(node *start)
{
    node *p,*tmp;
    p=getnode();
    printf("Enter the roll no : ");
    scanf("%d",&p->roll_no);
    printf("Enter the name : ");
    _flushall();
    gets(p->name);
    printf("Enter the marks : ");
    scanf("%f",&p->marks);
    if(start==NULL){
    start=p;
    return start;}
    else{
    tmp=start;
    while(tmp->next!=NULL)
        tmp=tmp->next;
    tmp->next=p;
    p->next=NULL;
    return start;}
}/*End of addatend()*/
node *addafter(node *start,int item)
{
    node *tmp,*p;
    p=getnode();
            printf("Enter the roll no : ");
            scanf("%d",&p->roll_no);
            printf("Enter the name : ");
            _flushall();
            gets(p->name);
            printf("Enter the marks : ");
            scanf("%f",&p->marks);
            if(start==NULL)
            start=p;
            else
            {
                tmp=start;
                do
                {
                    if(tmp->roll_no==item)
                    {
                    p->next=tmp->next;
                    tmp->next=p;
                    return start;
                    }
                    else
                    tmp=tmp->next;
                }while(tmp!=NULL);
            }
}/*End of addafter()*/
node *addbefore(node *start,int item)
{
    node *tmp,*p;
    if(start==NULL )
    {
        printf("List is empty\n");
        return start;
    }    
    /*If data to be inserted before first node*/
    if(start->roll_no==item)
    {
        tmp=getnode();
        printf("Enter the roll no : ");
        scanf("%d",&tmp->roll_no);
        printf("Enter the name : ");
        gets(tmp->name);
        printf("Enter the marks : ");
        scanf("%f",&tmp->marks);
        tmp->next=start;
        start=tmp;
        return start;
    }    
    p=start;
    while(p->next!=NULL) 
    {
        if(p->next->roll_no==item)
        {
            tmp=getnode();
            printf("Enter the roll no : ");
            scanf("%d",&tmp->roll_no);
            printf("Enter the name : ");
            gets(tmp->name);
            printf("Enter the marks : ");
            scanf("%f",&tmp->marks);        
            tmp->next=p->next;
            p->next=tmp;
            return start;
        }
        p=p->next;
    }
    printf("%d not present in the list\n",item);
    return start;
}/*End of addbefore()*/    
node *addatpos(node *start,int pos)
{
    node *tmp,*p;
    int i;
    tmp=getnode();
    printf("Enter the roll no : ");
    scanf("%d",&tmp->roll_no);
    printf("Enter the name : ");
    gets(tmp->name);
    printf("Enter the marks : ");
    scanf("%f",&tmp->marks);
    if(pos==1)
    {
        tmp->next=start; 
        start=tmp;
        return start;
    }
    p=start;
    for(i=1; i<pos-1 && p!=NULL; i++)
        p=p->next;
    if(p==NULL)
        printf("There are less than %d elements\n",pos);
    else
    {
        tmp->next=p->next;
        p->next=tmp;
    }    
    return start;
}/*End of addatpos()*/
node *del(node *start,int data)
{
    node *tmp,*p;
    if(start==NULL)
    {
        printf("List is empty\n");
        return start;
    }
    /*Deletion of first node*/
    if(start->roll_no==data)
    {
        tmp=start;
        start=start->next;  
        free(tmp);
        return start;
    }
    /*Deletion in between or at the end*/
    p=start;
    while(p->next!=NULL)
    {
        if(p->next->roll_no==data)   
        {
            tmp=p->next;
            p->next=tmp->next;
            free(tmp);
            return start;
        }
        p=p->next;
    }
    printf("Element %d not found\n",data);
    return start;
}/*End of del()*/
node *reverse(node *start)
{
    node *prev, *ptr, *n;
    prev=NULL;
       ptr=start;
    while(ptr!=NULL)
    {
        n=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=n;
    }
    start=prev;
    return start;
}/*End of reverse()*/