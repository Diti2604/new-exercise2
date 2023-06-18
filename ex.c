#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[100];
    int grade1;
    int grade2;
    float average;
    struct Node* next;
};
typedef struct Node node;
typedef struct Node *next;
node* createNode(char name[], int grade1, int grade2) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL)
     exit(1);
    else{
       strcpy(newNode->name, name);
    newNode->grade1 = grade1;
    newNode->grade2 = grade2;
    newNode->average = (grade1 + grade2) / 2.0;
    newNode->next = NULL;
    }



    return newNode;
}

void insertNode(node** head, node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void displayStudents(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->name);
        printf("%.2f\n", temp->average);
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        char name[100];
        int grade1, grade2;
        scanf("%s", name);
        scanf("%d", &grade1);
        scanf("%d", &grade2);
        node* newNode = createNode(name, grade1, grade2);
        insertNode(&head, newNode);
    }
    displayStudents(head);
    node* temp = head;
    while (temp != NULL) {
        node* prev = temp;
        temp = temp->next;
        free(prev);
    }

    return 0;
}