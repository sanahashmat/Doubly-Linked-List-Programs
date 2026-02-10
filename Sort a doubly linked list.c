// C program to sort a doubly linked list
// using bubble sort
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to sort the doubly linked list using 
// bubble sort
struct Node* bubbleSort(struct Node* head) {
    if (head == NULL) return head;

    int swapped;
    struct Node* curr;
    struct Node* last = NULL;
  
    // Keep going until no swaps occur in a pass
    do {
        swapped = 0;
        curr = head;
       
        // Traverse through the list and swap adjacent
        // nodes if they are in the wrong order
        while (curr->next != last) {
            if (curr->data > curr->next->data) {
              
                // Swap the data of the current node 
                // and next node
                int swap_data = curr->data;
                curr->data = curr->next->data;
                curr->next->data = swap_data;
                swapped = 1;
            }
            curr = curr->next;
        }
        last = curr;
    } while (swapped);

    return head;
}

void printList(struct Node* node) {
    struct Node* curr = node;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}


struct Node* createNode(int new_data) {
    struct Node* new_node =
      (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

int main() {
  
    // Create a hard-coded doubly linked list:
    // 5 <-> 3 <-> 4 <-> 1 <-> 2
    struct Node* head = createNode(5);
    head->next = createNode(3);
    head->next->prev = head;
    head->next->next = createNode(4);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(1);
    head->next->next->next->prev
                        = head->next->next;
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->prev 
                        = head->next->next->next;

    head = bubbleSort(head);

    printList(head);

    return 0;
}