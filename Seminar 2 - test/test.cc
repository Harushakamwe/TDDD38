#include <iostream>

class X
{
public:
void print(int&) { std::cout << "1"; }
void print(int const&) { std::cout << "2"; }
void print(int const&) const { std::cout << "3"; }

};

int main()
 {
 X x1 { };
 X const x2 { };
 int y1 { };
 int const y2 { };

 x1.print(y1);
 x2.print(y1);
 x1.print(y2);
 x2.print(y2);
 }