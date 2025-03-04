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
    Node* getHead() {
        return head;
    }
    void modifyHead(Node* newhead) {
        head = newhead;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    Node* reverseLinkedList(Node* starter) {
        // TODO: Students will implement this function
        std::cout << "Implement reverseLinkedList()" << std::endl;
        if (starter->next != nullptr) {
            Node* child = reverseLinkedList(starter->next);
            if (child == nullptr) {
                return starter;
            }
            starter->next->next = starter;
            starter->next = NULL;
            return child;
        }
        return starter;
    }
};

int main() {
    SinglyLinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.printList();

    // Student should implement reverseLinkedList()
    list.modifyHead(list.reverseLinkedList(list.getHead()));
    list.printList();

    return 0;
}
