#include <iostream>
using namespace std;
int main()
{
    float espressoPrice = 250.0;
    float lattePrice = 250.0;
    float cappuccinoPrice = 250.0;

    int espressoQty = 0, latteQty = 0, cappuccinoQty = 0;

    float* pEspressoPrice = &espressoPrice;
    float* pLattePrice = &lattePrice;
    float* pCappuccinoPrice = &cappuccinoPrice;

    int* pEspressoQty = &espressoQty;
    int* pLatteQty = &latteQty;
    int* pCappuccinoQty = &cappuccinoQty;

    cout << "Enter Espresso Quantity: ";
    cin >> *pEspressoQty;

    cout << "Enter Latte Quantity: ";
    cin >> *pLatteQty;

    cout << "Enter Cappuccino Quantity: ";
    cin >> *pCappuccinoQty;

    float espressoCost = (*pEspressoQty) * (*pEspressoPrice);
    float latteCost = (*pLatteQty) * (*pLattePrice);
    float cappuccinoCost = (*pCappuccinoQty) * (*pCappuccinoPrice);

    float totalBill = 0.0;
    float* pTotalBill = &totalBill;

    *pTotalBill = espressoCost + latteCost + cappuccinoCost;

    cout << "------ Cafe Bill ------" << endl;
    cout << "Espresso (" << *pEspressoQty << " x " << *pEspressoPrice << ") = " << espressoCost << endl;
    cout << "Latte    (" << *pLatteQty << " x " << *pLattePrice << ") = " << latteCost << endl;
    cout << "Cappuccino (" << *pCappuccinoQty << " x " << *pCappuccinoPrice << ") = " << cappuccinoCost << endl;
    cout << "-----------------------" << endl;
    cout << "TOTAL BILL: " << *pTotalBill << endl;
}
