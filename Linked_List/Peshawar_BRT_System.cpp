#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void insertAtPosition(int value, int pos) {
        if (pos <= 0) {
            cout << "Invalid position! Position must be positive."<<endl;
            return;
        }
        if (pos == 1) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* current = head;
        for (int i = 1; i < pos - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Position " << pos << " is beyond the current queue length. Adding at end."<<endl;
            insertAtEnd(value);
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    bool deleteFromBeginning(int* removedValue) {
        if (head == nullptr) {
            return false;
        }
        Node* temp = head;
        head = head->next;
        if (removedValue != nullptr) {
            *removedValue = temp->data;
        }
        delete temp;
        return true;
    }
    void display() const {
        if (head == nullptr) {
            cout << "Queue is empty!"<<endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(101);
    list.insertAtEnd(102);
    list.insertAtEnd(103);
    cout << "Initial Queue after adding passengers:"<<endl;
    list.display();

    list.insertAtBeginning(999);
    cout << "After adding an emergency passenger at beginning:"<<endl;
    list.display();

    list.insertAtPosition(555, 2);
    cout << "After inserting special booking passenger at position 2:"<<endl;
    list.display();

    int removed;
    list.deleteFromBeginning(&removed);
    cout << "After first passenger boards (deletion):"<<endl;
    list.display();

    return 0;
}
