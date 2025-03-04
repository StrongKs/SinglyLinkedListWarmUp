#include <iostream>
using namespace std;

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
        Node* temp = head;
        int node_count = 0;
        while (temp != nullptr) {
            node_count++;
            temp = temp->next;
        }
        temp = head;
        int *datatot = new int[node_count];
        for (int i = 0; i < node_count; i++) {
            datatot[i] = temp->data;
            Node* old_node = temp;
            temp = temp->next;
            delete[] old_node;
        }
        head = nullptr;
        for (int i = node_count - 1; i >= 0; i--) {
            append(datatot[i]);
        }
        delete[] datatot;
        std::cout << "Implement reverseLinkedList()" << std::endl;
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
