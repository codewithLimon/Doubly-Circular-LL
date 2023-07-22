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

// Function to insert a node at the beginning of the linked list
Node* LL_insert_to_beginning(Node* head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the beginning of the linked list (with pointer to head)
void LL_insert_to_beginning(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node after a target node in the linked list
void LL_insert_after(Node* head, int newData, int target) {
    Node* temp = head;
    while (temp->next != NULL && temp->data != target) {
        temp = temp->next;
    }
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert a node at the end of the linked list (converting to circular linked list)
void LL_insert_at_end(Node* head, int newData) {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head; // Point the new node back to the head to make it circular
    temp->next = newNode;
}

// Function to perform a linear search in the circular linked list
Node* LL_linear_search(Node* head, int target) {
    Node* temp = head;
    do {
        if (temp->data == target) {
            return temp; // Return the node if the target is found
        }
        temp = temp->next;
    } while (temp != head); // Continue until we reach back to the head

    return nullptr; // Return nullptr if the target is not found
}

// Function to delete a node from the linked list
void LL_delete_node(Node** head, int targetValue) {
    // Perform linear search to find the target node
    Node* targetNode = LL_linear_search(*head, targetValue);
    
    if (targetNode) {
        // If the target node is found, delete it from the circular linked list
        Node* temp = *head;
        
        if (temp == targetNode) {
            // If the target node is the head node
            *head = temp->next;
            // Update the last node's next pointer to maintain the circularity
            Node* lastNode = *head;
            while (lastNode->next != temp)
                lastNode = lastNode->next;
            lastNode->next = *head;
            delete temp; // Deallocate the memory
        } else {
            // If the target node is not the head node
            Node* prevNode = nullptr;
            while (temp != targetNode) {
                prevNode = temp;
                temp = temp->next;
            }
            prevNode->next = temp->next;
            delete temp; // Deallocate the memory
        }
        
        cout << "Node with value " << targetValue << " deleted from the circular linked list." << endl;
    } else {
        // If the target node is not found, print a message
        cout << "Node with value " << targetValue << " does not exist in the circular linked list." << endl;
    }
}

void LL_display(Node* head) {
    Node* cursor = head;
    do {
        cout << cursor->data << " ";
        cursor = cursor->next;
    } while (cursor != head);
    cout << endl;
}



int main() {
    Node* head;

    head = new Node();
    head->data = 1;

    head = LL_insert_to_beginning(head, 3);
    LL_insert_to_beginning(&head, 4);

    LL_insert_after(head, 2, 3);

    LL_insert_at_end(head, 0);

    LL_display(head);

    LL_delete_node(&head, 10);

    LL_display(head);
    

    // Linear search in the circular linked list
    Node* searchResult = LL_linear_search(head, 2);
    if (searchResult) {
        cout << "Found node with value 2 in the circular linked list." << endl;
    } else {
        cout << "Node with value 2 not found in the circular linked list." << endl;
    }

    return 0;
}
