#include <iostream>
#include <vector>

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
        Node* current = head;
        std::vector<int> temp;
        while (current) {
          temp.push_back(current->data);
          current = current->next;
        }
        current = head;
        for (int i = temp.size() - 1; i >= 0; i--) {
          current->data = temp[i];
          current = current->next;
        }
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
