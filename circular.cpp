/*
Doubly LinkedList 
Author: Borshon Dopho
ID: 011221337
*/

#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

// Function to insert a new node at the beginning of the circular linked list
void CLL_insert_to_beginning(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;

    if (head == NULL) {
        // If the list is empty, make the new node point to itself
        newNode->next = newNode;
        head = newNode;
    } else {
        // If the list is not empty, find the last node and update pointers to create circular linked list
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// Function to perform linear search in circular linked list
Node* CLL_linear_search(Node* head, int target) {
    if (head == NULL) {
        cout << "Circular linked list is empty.\n";
        return NULL;
    }

    Node* temp = head;
    do {
        if (temp->data == target) {
            return temp; // Return the node if target is found
        }
        temp = temp->next;
    } while (temp != head);

    // Target not found in the circular linked list
    return NULL;
}

int main() {
    Node* head = NULL; // Initialize the head to NULL for an empty circular linked list

    // Inserting nodes into the circular linked list
    CLL_insert_to_beginning(head, 3);
    CLL_insert_to_beginning(head, 4);
    CLL_insert_to_beginning(head, 1);
    CLL_insert_to_beginning(head, 0);
    CLL_insert_to_beginning(head, 2);

    // Perform linear search on the circular linked list
    int target = 4;
    Node* result = CLL_linear_search(head, target);
    if (result != NULL) {
        cout<< target << " found in the circular linked list.\n";
    } else {
        cout<< target << " not found in the circular linked list.\n";
    }

    // Printing the circular linked list
    if (head != NULL) {
        Node* cursor = head;
        do {
            cout << cursor->data << " ";
            cursor = cursor->next;
        } while (cursor != head);
    } else {
        cout << "Circular linked list is empty.";
    }

    return 0;
}
