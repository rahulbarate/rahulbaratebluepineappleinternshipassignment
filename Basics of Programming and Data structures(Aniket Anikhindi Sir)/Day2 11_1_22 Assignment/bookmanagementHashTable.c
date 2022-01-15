#include <stdio.h>
#include <stdlib.h>
struct book
{
    int id;
    char name[50];
    struct book *next;
}*head;
int lastPos=1;
struct book* Hashtable[5000];
int getHashKey(int key)
{
    return (key*2)%5000;
}
void insert()
{
    int pos,i,hindex;
    struct book *temp,*trav1,*trav2;
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(pos<1 || pos>lastPos)
    {
        printf("Invalid Position");
        return;
    }
    temp=(struct book *)malloc(sizeof(struct book));
    printf("\nEnter book id : ");
    scanf("%d",&(temp->id));
    hindex = getHashKey(temp->id);
    if(Hashtable[hindex]!=NULL)
    {
        printf("\n please enter Unique id");
        return;
    }


    printf("\nEnter the book name : ");
    scanf("%s",&(temp->name));
    temp->next = NULL;

    //stroring in hash
    Hashtable[hindex] = temp;

    lastPos+=1;
    if(pos==1)
    {
        temp->next =head;
        head=temp;
    }
    else
    {
        trav1 = head;
        for(i=2;i<pos;i++)
        {
            trav1 = trav1->next;
        }
        temp->next = trav1->next;
        trav1->next = temp;
    }
    printf("Inserted");
}
void delete()
{
    int pos,i,hindex;
    struct book *trav1,*trav2;
    printf("\nEnter Position to delete : ");
    scanf("%d",&pos);
    if(pos<1 || pos>lastPos-1)
    {
        printf("Invalid Position");
        return;
    }
    lastPos-=1;
    if(pos==1)
    {
        trav1 = head->next;
        head = trav1;
    }
    else
    {
        trav1 = head;
        for(i=2;i<pos;i++)
        {
            trav1 = trav1->next;
        }
        trav2 = trav1->next;
        trav1->next = trav2->next;
        
        //stroring in hash
        hindex = getHashKey(trav2->id);
        Hashtable[hindex] = NULL;

        free(trav2);
    }
    printf("\ndeleted");

}
void add()
{
    struct book *temp,*trav;
    int cnt=0,hindex;

    temp = (struct book *)malloc(sizeof(struct book));
    printf("\nEnter book id : ");
    scanf("%d",&(temp->id));
    hindex = getHashKey(temp->id);
    if(Hashtable[hindex]!=NULL)
    {
        printf("\n please enter Unique id");
        return;
    }
    printf("\nEnter the book name : ");
    scanf("%s",&(temp->name));
    temp->next = NULL;

    //stroring in hash
    Hashtable[hindex] = temp;

    if(head==NULL)
    {
        head = temp;
        lastPos+=1;
    }
    else
    {
        lastPos+=1;
        trav = head;
        while(trav->next!=NULL)
        {
            trav = trav->next;
        }
        trav->next = temp;
    }
    printf("added");
}
void print()
{
    struct book *trav;
    trav = (struct book *)malloc(sizeof(struct book));

    trav = head;
    while(trav!=NULL)
    {
        printf("|id = %d,Name = %s|-",trav->id,trav->name);
        trav = trav->next;
    }
}
void hashSearch()
{
    int id,hindex;
    struct book *temp;
    printf("\nEnter id to search : ");
    scanf("%d",&id);

    hindex = getHashKey(id);
    temp = Hashtable[hindex];
    if(temp != NULL)
    {
        printf("\n-----------");
        printf("\nBook Found");
        printf("\nbook id : %d\nbook name : %s",temp->id,temp->name);
        printf("\n-----------");
    }
    else
    {
        printf("\nBook Not Found");
    }


}
void search()
{
    int id,cnt=1;
    struct book *trav;
    printf("\nEnter id to search : ");
    scanf("%d",&id);

    trav= head;
    while(trav!=NULL)
    {
        cnt+=1;
        if(trav->id==id)
        {
            printf("\n-----------");
            printf("\nBook Found");
            printf("\nbook Position : %d\nbook id : %d\nbook name : %s",cnt,trav->id,trav->name);
            printf("\n-----------");
            return;
        }
        trav = trav->next;
    }
    printf("\nBook not found");
}
void main()
{
    head = NULL;
    int ch;
    while(1)
    {
        printf("\n1)add \n2)print \n3)insert \n4)delete \n5)search \n6)Quit \nEnter Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:add();
            break;
            case 2:print();
            break;
            case 3:insert();
            break;
            case 4:delete();
            break;
            case 5:hashSearch();
            break;
            case 6:exit(0);

            default:printf("!!!!!!!Invalid Choice!!!!!!!");
        }

    }
}
