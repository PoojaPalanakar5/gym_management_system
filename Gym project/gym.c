/*mini project in C Member Record System for Gym  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char name[20];
    int contact;
    int month;
    char Entering_Month[10];
    char Exit_Month[10];
    char mail[25];
    int age;
    struct node *next;

} node;
node *head;

void Add_Member()
{
    node *NewMember = (node *)malloc(sizeof(node));
    NewMember->next = NULL;
    printf("Enter the detail of Visitor : \n");
    printf("Name \t contact \t membership period \t from month :\t to month \t MAIL \t AGE \n");
    scanf("%s%d%d%s%s%s%d", NewMember->name, &NewMember->contact, &NewMember->month, NewMember->Entering_Month, NewMember->Exit_Month, NewMember->mail, &NewMember->age);

    if (head == NULL)
    {
        head = NewMember;
    }

    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NewMember;
    }
    printf("%s is added into list \n", NewMember->name);
    printf("\n");

    float cal;
    cal = 2000 * NewMember->month;
    printf("PAYMENT AMOUNT TO BE PAID = %f ", cal);
    printf("\n");
}

void Display_Member()
{
  
    

    if (head == NULL)
    {
        printf("EMPTY LIST ! \n");
        return;
    }

    node *temp = head;
    printf("Detail of member's are : \n");
    while (temp != NULL)
    {
        printf("name : %s\t contact : %d\t month  : %d\t from month : %s\t to month : %s\t mail : %s\t age : %d \n ", temp->name, temp->contact, temp->month, temp->Entering_Month, temp->Exit_Month, temp->mail, temp->age);
        temp = temp->next;
    }
    printf("\n");

}
void Cancle_membership()
{
    char name[20];
    printf("Enter the membership to be Cancle : \n");
    scanf("%s", name);
    if (head == NULL)
    {
        printf("Empty List !\n");
        return;
    }

    node *temp = head;
    node *prev = head;

    while (temp != NULL && strcmp(temp->name, name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Not Found !");
    }
    else
    {
        prev->next = temp->next;
        printf("%s is Cancled from List \n ", temp->name);
        free(temp);
    }
}

void Search_Member()
{

    int flag=0;
    if (head == NULL)
    {
        printf("Empty List !\n");
    }
    else
    {

        char name[20];
        printf("Enter the name of the member to be Search : \n");
        scanf("%s", name);

        node *temp = head;

        while (temp != NULL )
        {
            if(strcmp(temp->name,name)==0)
            {
               if(flag==0)
               {
                   printf("name : \t contact : \t month  : \t from month : \t to month : \t mail : \t age :\n  ");
                   flag=1;
               }
        printf(" %s\t  %d\t  %d\t %s\t  %s\t %s\t  %d \n ", temp->name, temp->contact, temp->month, temp->Entering_Month, temp->Exit_Month, temp->mail, temp->age);
        }
        temp=temp->next;
     }
        if(flag=0)
        {
             printf("Not Found !");
        }
        }
}



void Search_Ending()
{
  int flag=0;
    if (head == NULL)
    {
        printf("Empty List !\n");
    }
    else
    {

        char month[20];
        printf("Enter the ending month of the membership to be Search : \n");
        scanf("%s", month);

        node *temp = head;

        while (temp != NULL )
        {
            if(strcmp(temp->Exit_Month,month)==0)
            {
               if(flag==0)
               {
                   printf("name : \t contact : \t month  : \t from month : \t to month : \t mail : \t age :\n  ");
                   flag=1;
               }
        printf(" %s\t  %d\t  %d\t %s\t  %s\t %s\t  %d \n ", temp->name, temp->contact, temp->month, temp->Entering_Month, temp->Exit_Month, temp->mail, temp->age);
        }
        temp=temp->next;
     }
        if(flag=0)
        {
             printf("Not Found !");
        }
        }
}
            
           
    
void Search_Period()
{
  int flag=0;
    if (head == NULL)
    {
        printf("Empty List !\n");
    }
    else
    {

        int period;
        printf("Enter the period  of the membership to be Search : \n");
        scanf("%d",&period);

        node *temp = head;

        while (temp != NULL )
        {
            if(temp->month==period)
            {
               if(flag==0)
               {
                   printf("name : \t contact : \t month  : \t from month : \t to month : \t mail : \t age :\n  ");
                   flag=1;
               }
        printf(" %s\t  %d\t  %d\t %s\t  %s\t %s\t  %d \n ", temp->name, temp->contact, temp->month, temp->Entering_Month, temp->Exit_Month, temp->mail, temp->age);
        }
        temp=temp->next;
     }
        if(flag=0)
        {
             printf("Not Found !");
        }
        }
}
            

int main()
{
    head = NULL;
    int choice;

    while (1)
    {
        printf("\n1:Add_Member \n2:Search_Member \n3:Cancle_membership \n4: Display_Member \n5: Search_Member by ending membership \n6: search by period \n7: EXIT \n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            Add_Member();
        }
        else if (choice == 2)
        {
            Search_Member();
        }

        else if (choice == 3)
        {
            Cancle_membership();
        }

        else if (choice == 4)
        {
            Display_Member();
        }
        else if (choice == 5)
        {
            Search_Ending();
        }
        else if (choice == 6)
        {
            Search_Period();
        }
        else
        {
            exit(0);
        }
    }

    return 0;
}