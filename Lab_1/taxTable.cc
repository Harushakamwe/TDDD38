#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    float firstPrice{};
    float lastPrice{};
    float stride{};
    float taxPercent{};

    // INPUT PART
    cout << "INPUT PART" << endl;
    cout << setfill('=') << setw(10) << '\n';

    cout << left << setw(17) << setfill(' ') << "Enter first price" << right << ": ";
    cin >> firstPrice;
    while (firstPrice < 0)
    {
        cerr << "First price must be at least 0 (zero) SEK." << endl;
        cout << left << setw(17) << setfill(' ') << "Enter first price" << right << ": ";
        cin >> firstPrice;
    }

    cout << left << setw(17) << "Enter last price:" << right << ": ";
    cin >> lastPrice;
    while (lastPrice < firstPrice)
    {
        cerr << "Last price must be at least " << firstPrice << " SEK." << endl;
        cout << left << setw(17) << setfill(' ') << "Enter last price" << right << ": ";
        cin >> lastPrice;
    }

    cout << left << setw(17) << "Enter stride" << right << ": ";
    cin >> stride;
    while (stride < 0 || stride > (lastPrice - firstPrice))
    {
        cerr << "Stride must be between 0 and " << (lastPrice - firstPrice) << "." << endl;
        cout << left << setw(17) << "Enter stride" << right << ": ";
        cin >> stride;
    }

    cout << left << setw(17) << "Enter tax percent" << right << ": ";
    cin >> taxPercent;
    while (taxPercent < 0 )
    {
        cerr << "Tax percent must be at least 0 (zero)." << endl;
        cout << left << setw(17) << "Enter tax percent" << right << ": ";
        cin >> taxPercent;
    }
    cout << endl;

    // OUTPUT PART
    cout << "TAX TABLE" << endl;
    cout << setfill('=') << setw(10) << '\n';

    cout << right << setw(10) << setfill(' ') << "Price" << setw(15) << "Tax" << setw(20) << "Price with tax" << endl;
    cout << setfill('-') << setw(46) << '\n';

    float currentPrice{0};
    float currentTax{};
    int idx{1};

    while (currentPrice <= lastPrice)
    {
        currentTax = currentPrice * taxPercent * 0.01;
        cout << right << setw(10) << setfill(' ') << currentPrice << setw(15) << currentTax << setw(20) << currentPrice + currentTax << endl;
        currentPrice = firstPrice + idx*stride;
        idx++;
    }    

    cout << '\n';



    return 0;
}