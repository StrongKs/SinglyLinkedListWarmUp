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

    SinglyLinkedList reverseLinkedList() {
        std::vector<int> info;
        Node* temp = head;
        while (temp) {
            info.push_back(temp->data);
            temp = temp->next;
        }
        SinglyLinkedList newlist;
        for (int i = info.size() - 1; i >= 0 ; i--) {
            newlist.append(info[i]);
        }
        return newlist;
    }
};

int main() {
    SinglyLinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.printList();

    // Student should implement reverseLinkedList()
    SinglyLinkedList newlist = list.reverseLinkedList();
    newlist.printList();

    return 0;
}
