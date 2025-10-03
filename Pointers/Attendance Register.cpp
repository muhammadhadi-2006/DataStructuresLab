#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter number of participants: ";
    cin >> num;

    int* attendance = new int[num];

    for (int i = 0; i < num; i++) {
    attendance[i] = 0;
    }

    int present;
    cout << "How many participants are present? ";
    cin >> present;

    for (int i = 0; i < present; i++) {
        int id;
        cout << "Enter participant number (1 to " << num << "): ";
        cin >> id;
        if (id >= 1 && id <= num){
             attendance[id - 1] = 1;
        }
    }
    
    cout << "Attendance List:" << endl;
    for (int i = 0; i < num; i++) {
        if (attendance[i]) {
    cout << "Participant " << i + 1 << ": Present" << endl;
} else {
    cout << "Participant " << i + 1 << ": Absent" << endl;
}
    }
    delete[] attendance;
}
