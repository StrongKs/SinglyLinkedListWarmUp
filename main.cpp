#include <iostream>

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    void reverseLinkedList() {
        // TODO: Students will implement this function

        std::cout << "Implement reverseLinkedList()" << std::endl;

        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr) {
            next = curr->next;  // Store next node
            curr->next = prev;  // Reverse current node’s pointer
            prev = curr;        // Move prev to current
            curr = next;        // Move current to next
        }

        head = prev;  // Update head to new front
    }
};

int main() {
    SinglyLinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.printList();


    // Student should implement reverseLinkedList()
    list.reverseLinkedList();
    list.printList();

    return 0;
}
