#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *insertion(struct Node *head, int value, int targetValue)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    if (head == NULL)
    {
        printf("list is empty");
        return head;
    }
    if (head->data == targetValue)
    {
        printf("insertion at Beggining\n");
        ptr->next = head;
        ptr->prev = NULL;
        head->prev = ptr;
        head = ptr;
        return head;
    }

    struct Node *temp = head;
    while (temp->data != targetValue)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("insertion at End\n");
        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = NULL;
        return head;
    }
    printf("%d\n", temp->data);
    printf("insertion at middle\n");
    ptr->prev = temp->prev;   // Link ptr’s prev to temp’s prev
    ptr->next = temp;         // Link ptr’s next to temp
    (temp->prev)->next = ptr; // Fix the old previous node’s next to ptr
    temp->prev = ptr;

    return head;
}

void traverse(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("Element: %d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *two = (struct Node *)malloc(sizeof(struct Node));
    struct Node *three = (struct Node *)malloc(sizeof(struct Node));
    struct Node *four = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 1;
    head->next = two;
    two->prev = head;
    two->data = 2;
    two->next = three;
    three->prev = two;
    three->data = 3;
    three->next = four;
    four->prev = three;
    four->data = 4;
    four->next = NULL;
    traverse(head);
    traverse(insertion(head, 5, 3));
    return 0;
}