#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int i{};
    char c{};
    double d{};
    string s{};

    // Output 1
    /*
    cout << "Enter one integer: ";
    cin >> i;
    cout << "You entered the number: " << i << endl;

    // Output 2
    cout << "Enter four integers: ";
    cin >> i;
    cout << "You entered the numbers: " << i;
    cin >> i;
    cout << " " << i;
    cin >> i;
    cout << " " << i;
    cin >> i;
    cout << " " << i << endl;

    // Output 3
    cout << "Enter one integer and one real number: ";
    cin >> i;
    cin >> d;
    cout << "The real is: " << setw(12) << setprecision(4) << d << endl;
    cout << "The integer is: " << setw(9) << i << endl;

    // Output 4
    cout << "Enter one real and one integer number: ";
    cin >> d;
    cin >> i;
    cout << "The real is: " << setw(12) << setprecision(4) << setfill('.') << d << endl;
    cout << "The integer is: " << setw(9) << i << endl;
    

    // Output 6
    cout << "Enter a word: ";
    cin >> s;
    cout << "The word '" << s << "' has " << s.length() << " character(s)." << endl;
    */

    // Output 10
    cout << "Enter a text-line: ";
    getline(cin, s);
    cout << "You entered: " << '"' << s << '"' << endl;
    


    
    return 0;

}