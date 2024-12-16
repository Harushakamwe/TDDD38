#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string filename{"randomText.txt"};
    ifstream stream(filename, ios::binary);

    string s{};
    string shortest{};
    string longest{};
    int counter{0};
    float sum{0};
    while (stream >> s)
    {   
        counter++;
        sum += s.length();
        if (shortest.empty() || shortest.length() > s.length())
        {
            shortest = s;
        }
        if (longest.empty() || longest.length() < s.length())
        {
            longest = s;
        }
    }

    cout << "There are " << counter << " words in the file." << endl;
    cout << "The shortest word was " << '"' << shortest << '"' << " with " << shortest.length() << " characters(s)" << endl;
    cout << "The longest word was " << '"' << longest << '"' << " with " << longest.length() << " characters(s)" << endl;
    cout << "The average length was " << setprecision(3) << sum/counter << " characters(s)" << endl;
}