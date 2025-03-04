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
    Node* recucrsiveFunction(Node* p) {
        Node* q = p->next;
        if (q->next) {
            Node* newNode = q->next;
            q->next = p;
            return recucrsiveFunction(q);
        }else {
            return nullptr;
        }
    }

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
        Node* a = head;
        Node* b = a->next;
        a->next = nullptr;
        while (b->next) {
            Node* temp = b->next;
            b->next = a;
            a = b;
            b = temp;
        }
        b->next = a;
        head = b;
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
