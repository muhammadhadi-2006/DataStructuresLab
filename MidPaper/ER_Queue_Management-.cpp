#include<iostream>
using namespace std;

struct Node {
    int PatientId;
    Node* prev;
    Node* next;
  Node(int id) {
    PatientId = id;
    prev = nullptr;
    next = nullptr;
}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

    void InsertAtBeginning(int PatientId) {
        Node* temp = new Node(PatientId);
        if (head == nullptr) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void InsertAtEnd(int PatientId) {
        Node* temp = new Node(PatientId);
        if (tail == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void InsertAtPosition(int PatientId, int position) {
        if (position < 1) {
            cout << "Invalid position. Position must be >= 1." << endl;
            return;
        }
        if (position == 1) {
            InsertAtBeginning(PatientId);
            return;
        }
        if (position > size + 1) {
            
            InsertAtEnd(PatientId);
            return;
        }
        Node* temp = new Node(PatientId);
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        temp->next = current->next;
        temp->prev = current;
        if (current->next != nullptr) {
            current->next->prev = temp;
        } else {
            tail = temp;
        }
        current->next = temp;
        size++;
    }

    void DeleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    void PrintForward() {
        Node* current = head;
        cout << "Forward: ";
        while (current != nullptr) {
            cout << current->PatientId << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    void PrintBackward() {
        Node* current = tail;
        cout << "Backward: ";
        while (current != nullptr) {
            cout << current->PatientId << " ";
            current = current->next;
        }
        cout << endl;
    }

int GetHeadID() {
    if (head != nullptr)
        return head->PatientId;
    else
        return -1;
}

int GetTailID() {
    if (tail != nullptr)
        return tail->PatientId;
    else
        return -1;
}
  
    void PrintGraphical() {
        Node* current = head;
        cout << "Graphical: ";
        while (current != nullptr) {
            cout << "[" << current->PatientId << "] <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList ErQueue;

    cout << "Initial empty list:" << endl;
    ErQueue.PrintGraphical();

    cout << "After insertAtEnd(101):" << endl;
    ErQueue.InsertAtEnd(101);
    ErQueue.PrintGraphical();

    cout << "After insertAtEnd(102):" << endl;
    ErQueue.InsertAtEnd(102);
    ErQueue.PrintGraphical();

    cout << "After insertAtBeginning(200):" << endl;
    ErQueue.InsertAtBeginning(200);
    ErQueue.PrintGraphical();

    cout << "After insertAtPosition(150, 2):" << endl;
    ErQueue.InsertAtPosition(150, 2);
    ErQueue.PrintGraphical();
   
    cout << "After deleteFromBeginning():" << endl;
    ErQueue.DeleteFromBeginning();
    ErQueue.PrintGraphical();

    cout << "After insertAtEnd(300):" << endl;
    ErQueue.InsertAtEnd(300);
    ErQueue.PrintGraphical();
  
    cout << "After all operations:" << endl;
    cout << "(a) PatientID at head: " << ErQueue.GetHeadID() << endl;
    cout << "(b) PatientID at tail: " << ErQueue.GetTailID() << endl;
    cout << "(c) ";
    ErQueue.PrintForward();
    cout << "(d) ";
    ErQueue.PrintBackward();

    return 0;
}
