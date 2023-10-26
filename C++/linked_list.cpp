#include <iostream>
using namespace std;


class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int data) : data(data), next(nullptr) {}
    };
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    void append(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
    }
    void insert(int data, int position) {
        Node* new_node = new Node(data);
        if (position == 0) {
            new_node->next = head;
            head = new_node;
        } else {
            Node* current = head;
            int count = 0;
            while (current && count < position - 1) {
                current = current->next;
                count++;
            }
            if (!current) {
                cout << "Error: position out of range." << endl;
                delete new_node;
                return;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }
    void remove(int position) {
        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            int count = 0;
            while (current && count < position - 1) {
                current = current->next;
                count++;
            }
            if (!current || !current->next) {
                cout << "Error: position out of range." << endl;
                return;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.display();
    list.insert(4, 0);
    list.display();
    list.insert(5, 2);
    list.display();
    list.remove(1);
    list.display();
    return 0;
}