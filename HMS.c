#include <stdio.h>
#include <stdlib.h>

struct node
{
    int id;
    int age;
    int priority;
    char name[50];
    struct node *next;
};

struct node *head = NULL;



char* pname(int p)
{
    if(p == 1)
    {
        return "Emergency";
    }
    else if(p == 2)
    {
        return "Critical";
    }
    else if(p == 3)
    {
        return "Normal";
    }
    else
    {
        return "General";
    }
}



void insert()
{
    int id;
    int age;
    int priority;
    char name[50];

    printf("Enter ID: ");
    scanf("%d", &id);

    printf("Enter Name: ");
    scanf("%s", name);

    printf("Enter Age: ");
    scanf("%d", &age);

    printf("Enter Priority (1-4): ");
    scanf("%d", &priority);

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->id = id;
    newnode->age = age;
    newnode->priority = priority;

    int i = 0;
    while(name[i] != '\0')
    {
        newnode->name[i] = name[i];
        i++;
    }
    newnode->name[i] = '\0';

    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        if(priority < head->priority)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            struct node *temp;
            temp = head;

            while(temp->next != NULL)
            {
                if(temp->next->priority > priority)
                {
                    break;
                }
                else
                {
                    temp = temp->next;
                }
            }

            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}



void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("Queue Empty\n");
    }
    else
    {
        temp = head;

        printf("\nID   Name   Age   Priority\n");

        while(temp != NULL)
        {
            printf("%d   %s   %d   %s\n",
                   temp->id,
                   temp->name,
                   temp->age,
                   pname(temp->priority));

            temp = temp->next;
        }
    }
}



void treat()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("No patient available\n");
    }
    else
    {
        temp = head;

        printf("Treated: %s\n", temp->name);

        head = head->next;

        free(temp);
    }
}



void delete_id()
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    struct node *temp;
    struct node *prev;

    temp = head;
    prev = NULL;

    if(head == NULL)
    {
        printf("Queue Empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->id == id)
            {
                break;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }

        if(temp == NULL)
        {
            printf("Patient not found\n");
        }
        else
        {
            if(prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);

            printf("Deleted successfully\n");
        }
    }
}



void search()
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    struct node *temp;
    temp = head;

    if(head == NULL)
    {
        printf("Queue Empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->id == id)
            {
                printf("Found: %s %d %s\n",
                       temp->name,
                       temp->age,
                       pname(temp->priority));
                return;
            }
            else
            {
                temp = temp->next;
            }
        }

        printf("Patient not found\n");
    }
}



int main()
{
    int choice;

    while(1)
    {
        printf("\n1 Insert\n");
        printf("2 Display\n");
        printf("3 Treat Patient\n");
        printf("4 Delete by ID\n");
        printf("5 Search\n");
        printf("6 Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            insert();
        }
        else if(choice == 2)
        {
            display();
        }
        else if(choice == 3)
        {
            treat();
        }
        else if(choice == 4)
        {
            delete_id();
        }
        else if(choice == 5)
        {
            search();
        }  
        else if(choice == 6)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}