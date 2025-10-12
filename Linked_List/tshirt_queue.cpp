#include <iostream>
using namespace std;

struct Node {
    string name;
    int id;
    Node* next;
};

class Queue {
private:
    Node* head;
    Node* tail;
    int count;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~Queue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addStudent(string name, int id) {
        Node* newNode = new Node();
        newNode->name = name;
        newNode->id = id;
        newNode->next = nullptr;
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
        cout << "Student " << name << " (ID: " << id << ") added to the queue." << endl;
    }

    void serveStudent() {
        if (!head) {
            cout << "Queue is empty. No student to serve." << endl;
            return;
        }
        Node* temp = head;
        cout << "Serving student: " << head->name << " (ID: " << head->id << ")" << endl;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete temp;
        count--;
    }

    void removeStudentById(int id) {
        if (!head) {
            cout << "Queue is empty. No student to remove." << endl;
            return;
        }
        if (head->id == id) {
            serveStudent();
            return;
        }
        Node* current = head;
        while (current->next && current->next->id != id) {
            current = current->next;
        }
        if (!current->next) {
            cout << "Student with ID " << id << " not found in the queue." << endl;
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        if (temp == tail) {
            tail = current;
        }
        cout << "Removed student: " << temp->name << " (ID: " << temp->id << ")" << endl;
        delete temp;
        count--;
    }

    void displayQueue() {
        if (!head) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current queue (front to back):" << endl;
        Node* current = head;
        while (current) {
            cout << "- " << current->name << " (ID: " << current->id << ")" << endl;
            current = current->next;
        }
    }

    int getCount() {
        return count;
    }
};

int main() {
    Queue queue;
    int choice;
    do {
        cout << "\nT-Shirt Queue Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Serve Student" << endl;
        cout << "3. Student Leaves (Remove by ID)" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Count Students" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name;
            int id;
            cout << "Enter student name: ";
            getline(cin, name);
            cout << "Enter student ID: ";
            cin >> id;
            queue.addStudent(name, id);
        } else if (choice == 2) {
            queue.serveStudent();
        } else if (choice == 3) {
            int id;
            cout << "Enter student ID to remove: ";
            cin >> id;
            queue.removeStudentById(id);
        } else if (choice == 4) {
            queue.displayQueue();
        } else if (choice == 5) {
            cout << "Total students in queue: " << queue.getCount() << endl;
        } else if (choice == 6) {
            cout << "Exiting the system." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    
}
