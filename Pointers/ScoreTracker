#include <iostream>
using namespace std;

int generateCode(int n) {
    if (n == 0)
     return 1;

    int result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {

    int (*codePtr)(int) = generateCode;
    
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Your secret code is: " << codePtr(n) << endl;
}
