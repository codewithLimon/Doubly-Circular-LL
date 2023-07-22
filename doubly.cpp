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
    Node* next; // next pointer
    Node* prev; // previous pointer 
};

Node* LL_insert_to_beginning(Node* head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    newNode->prev = nullptr; // Set the 'prev' pointer to nullptr for the first node
    if (head != nullptr) {
        head->prev = newNode; // Update the 'prev' pointer of the second node (if exists)
    }
    return newNode;
}

void LL_insert_to_beginning(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    newNode->prev = nullptr; // Set 'prev' pointer to nullptr for the first node
    if (*head != nullptr) {
        (*head)->prev = newNode; // Update the 'prev' pointer of the second node (if exists)
    }
    *head = newNode;
}

void LL_insert_after(Node* head, int newData, int target) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "The target element not found \n";
        return;
    }
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = newNode; // Update the 'prev' pointer of the next node (if exists)
    }
    temp->next = newNode;
}

void LL_insert_at_end(Node* head, int newData) {
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = temp; // Set 'prev' pointer to the current last node
    temp->next = newNode;
}

void LL_delete_node(Node** head, int hasValue) {
    Node* temp = *head;
    while (temp != nullptr && temp->data != hasValue) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "The item doesn't exist \n";
        return;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next; // Update the 'next' pointer of the previous node
    } else {
        *head = temp->next; // If the deleted node is the head, update the head pointer
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev; // Update the 'prev' pointer of the next node (if exists)
    }
    free(temp);
}

Node* LL_linear_search(Node* head, int target) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == target) {
            return temp; // Return the node with the target value if found
        }
        temp = temp->next;
    }
    return nullptr; // Return nullptr if the target value is not found
}

void display(Node* head){
    Node* temp=head;

    cout<<"NULL"<<"->";

    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main() {
    Node* head = nullptr;

    head = new Node(); // first node (head)
    head->data = 1; // head data
    head->next = nullptr;
    head->prev = nullptr;

    head = LL_insert_to_beginning(head, 3);  // inserting before 1, so it will be NULL->3->1->NULL now
    LL_insert_to_beginning(&head, 4);  // inserting before 3, so it will be NULL->4->3->1->NULL now

    LL_insert_after(head, 2, 3); // inserting 2 after 3, so it will be NULL->4->3->2->1->NULL now

    LL_insert_at_end(head, 0); // inserting 0 at the end, so it will be NULL->4->3->2->1->0->NULL now

    Node* targetNode = LL_linear_search(head, 3); // search if the element 3 is present, if present, delete the node!
    if (targetNode != nullptr) {
        LL_delete_node(&head, targetNode->data);
    }

    // Node* Cursor = head;
    // while (Cursor) {
    //     cout << Cursor->data << endl;
    //     Cursor = Cursor->next;
    // }

    display(head); // displays the LL

    return 0;
}
