#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void display(struct node *head);
struct node *addback(struct node *header, int data);
struct node *find(struct node *head, int data);
struct node *delnode(struct node *head, struct node *pelement);
struct node* freelist(struct node *head);
struct node *elements(void);

int main() {
    struct node *head = NULL;
    int val;

    do {
        puts("\nEnter  0:element call , 1:display , 2:addback , 3:find ,4:delnode , 5:freelist ");
        scanf("%d", &val);

        switch (val) {
            case 0:
                head = elements();
                break;
            case 1:
                display(head);
                break;
            case 2:
                addback(head, 4);
                puts("\nelements after addback call:");
                display(head);
                break;
            case 3: {
                struct node *result = find(head, 45);
                if (result != NULL) {
                    printf("\nThe Data is at address :%p\n", result);
                } else {
                    puts("\nThe data is not in the list\n");
                }
            } break;
            case 4: {
                struct node *result = find(head, 45);
                if (result != NULL) {
                    head = delnode(head, result);
                    puts("elements after calling delnode:");
                    display(head);
                } else {
                    puts("\nThe data is not in the list\n");
                }
            } break;
            case 5:
              head =  freelist(head);
                if(head == NULL){
                  puts("\n All nodes deleted");
                }
                break;
            default:
                break;
        }
    } while (val < 6);

    return 0;
}

void display(struct node *head) {
    struct node *temp = head;
    if(temp==NULL)
    {
      puts("List is empty.");
    }
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}

struct node *addback(struct node *header, int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        puts("Error adding element. Memory not allocated.");
    } else {
        newnode->data = data;
        newnode->next = NULL;
        if (header == NULL) {
            header = newnode;  // update head if the list is empty
        } else {
            struct node *temp;
            for (temp = header; temp->next != NULL; temp = temp->next) {
            }
            temp->next = newnode;
        }
    }
    return header;
}

struct node *find(struct node *head, int data) {
    struct node *temp = head;
    while (temp != NULL) {
        if (data == temp->data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

struct node *delnode(struct node *head, struct node *pelement) {
    struct node *temp = head, *previous = NULL;

    if (head == pelement) {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL) {
        if (pelement == temp) {
            previous->next = temp->next;
            free(temp);
            break;
        }
        previous = temp;
        temp = temp->next;
    }

    return head;
}

struct node *freelist(struct node *head) {
    struct node *current, *nextnode;
    current = head;
    while (current != NULL) {
        nextnode = current->next;
        free(current);
        current = nextnode;
    }
    return NULL;
}

struct node *elements(void) {
    int data;
    struct node *head = NULL, *temp = NULL;

    puts("Enter 3 elements:");
    for (int i = 0; i < 3; i++) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));

        scanf("%d", &data);

        if (newnode == NULL) {
            puts("Error allocating Memory !");
        } else {
            newnode->data = data;
            newnode->next = NULL;
            if (head == NULL) {
                head = temp = newnode;
            } else {
                temp->next = newnode;
                temp = newnode;
            }
        }
    }

    return head;
}
