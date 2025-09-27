#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter number of players: ";
    cin >> num;

    float* scores = new float[num];

    for (int i = 0; i < num; i++) {
        cout << "Enter score for player " << i + 1 << ": ";
        cin >> scores[i];
    }
    cout << "Scores:" << endl;
    for (int i = 0; i < num; i++) {
        cout << "Player " << i + 1 << ": " << scores[i] << endl;
    }
    
    delete[] scores;
}
