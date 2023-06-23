#include <stdio.h>
#include <malloc.h>

struct node
{
    int info;
    struct node *next;
};

typedef struct node Node;

Node *head = NULL;

void insert_at_beg(int n);
void insert_givenpos(int);
void insert_at_end(int);
void delete_first();
void delete_last();
void delete_nth_node();
void count_nodes();
void display();

int main()
{
    int choice;
    int item;

    do
    {
        printf("\n manu for program:\n");
        printf("1. insert first \n2.insert at given position \n3 insert at last \n4:Delete first \n5:delete last node \n6:delete nth node \n7:count nodes \n8Display items \n9:exit \n");
        printf("enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item to be inserted: ");
            scanf("%d", &item);
            insert_at_beg(item);
            break;
        case 2:
            printf("Enter item to be inserted: ");
            scanf("%d", &item);
            insert_givenpos(item);
            break;
        case 3:
            printf("Enter item to be inserted: ");
            scanf("%d", &item);
            insert_at_end(item);
            break;
        case 4:
            delete_first();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            delete_nth_node();
            break;
        case 7:
            count_nodes();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(1);
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    } while (choice < 10);

    return 0;
}

void insert_at_beg(int item)
{
    Node *p;
    p = malloc(sizeof(Node));
    p->info = item;
    p->next = head;
    head = p;
}

void insert_at_end(int item)
{
    Node *p = malloc(sizeof(Node));
    Node *temp = head;

    p->info = item;

    // for the condition if there are no elements in linked list
    if (head == NULL)
    {
        head = p;
        p->next = NULL;
    }

    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
        p->next = NULL;
    }
}

void insert_givenpos(int item)
{

    Node *p = malloc(sizeof(Node));
    Node *temp = head;
    p->info = item;

    if (head == NULL)
    {
        p->next = NULL;
        head = p;
    }

    else
    {
        int pos, i;
        printf("Enter the position to enter the element: ");
        scanf("%d", &pos);

        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        p->next = temp->next;
        temp->next = p;
    }
}

void delete_first()
{
    Node *p;

    if (head == NULL)
    {
        printf("NO items to delete");
        return;
    }
    else
    {
        p = head;
        head = head->next;
        free(p);
    }
}

void delete_last()
{
    Node *temp, *hold;
    temp = head;
    if (head == NULL)
    {
        printf("NO items to delete");
        return;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        hold = temp->next;
        temp->next = NULL;
        free(hold);
    }
}

void delete_nth_node()
{
    Node *temp, *hold;

    temp = head;
    if (head == NULL)
    {
        printf("No items in the list to delete");
        return;
    }

    else
    {
        int pos, i;
        printf("Enter the position to delete the node: ");
        scanf("%d", &pos);

        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        hold = temp->next;
        temp->next = hold->next;
        free(hold);
    }
}

void display()
{
    Node *temp;
    temp = head;

    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
}

void count_nodes()
{
    int count = 0;
    Node *temp;
    temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("The total number of nodes = %d", count);
}
