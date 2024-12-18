#include <iostream>
#include <string> 

using namespace std;

// Exercises 6 & 7
/*
int main() 
{
    // Exercise 6, size will be 13, however length of string is 12.
    char msg[] {"Hello world!"};
    cout << sizeof(msg) << endl;

    // Exercise 7
    // 1, list init
    int i1{};
    cout << i1 << endl;

    // 2, direct init
    int i2(2);
    cout << i2 << endl;

    // 3, copy init
    int i3 = 1;
    cout << i3 << endl;

    // 4, copy with implicit conversion
    int i4 = {};
    cout << i4 << endl;

    // 5, invalid assignement, misinterpreted as function since direct init calls appropriate constructors first
    /*
    int i5();
    cout << i5 << endl;
    */
/*
   // 8
   string str4{'a', 'a'};
   cout << str4 << endl;

   // 10, implicit conversions
   float f1(5.37e100);
   cout << f1 << endl;

   // 11, copy init, implicit conversion
   float f2 = 5.37e100;
   cout << f2 << endl;

   // 12, list init aggregates and doesn't allow for narrowing conversions or precision loss
   float f3{1738335806};
   cout << f3 << endl;

}*/


/*
int sum ( double const * numbers ,
unsigned long long size )
{
    double result {};
    for ( unsigned i {}; i < size ; ++ i ) // i is promoted to unsigned long long for comparison
    {
        result += static_cast < int >( numbers [ i ]); 
        // Static cast from double to int, narrowing conversion. 
        // An implicit conversion back to double through the expression
    }
    return result ; 
    // Implicit conversion for the function to return the right type
}

int main ()
{
    std :: string message {};
    message = "Enter a number : " ;

    double numbers [3];
    for ( int i {0}; i < 3; ++ i )
    {
        std :: cout << message ;
        if (!( std :: cin >> numbers [ i ])) // Implicit conversion to double
        {
            return true ;
            // Boolean true is casted to an int for correct return type.
        }
    }


    std :: cout << sum ( numbers , 3) + 1.0 << std :: endl ; 
    // Sum takes a double const* so numbers is converted to double* and then the compiler performs a qualification conversion
    // Int 3 is promoted to long long to fit the format of the function
    // 1.0 is converted to int for the sum since sum returns an int
}
*/


int foo ()
{
    return 0;
}

using function_t = int (*)();

int main ()
{
    function_t f { main }; // Function main is promoted to a function pointer

    char c { 'A' };
    std :: cout << c + 1 << std :: endl ; // Character c is promoted to int for the addition so that no overflow happens
    std :: cout << c + 'A' << std :: endl ; // Result is converted to an int

    std :: cout << 0 - 1u << std :: endl ; // int 0 is converted to unsigned int

    f = foo ; // Function foo is promoted to a function pointer
    std :: cout << f () << std :: endl ; 
    std :: cout << f << std :: endl ; // Function pointer f is converted to a boolean and then an integer for the output, since operator<< has no overload for function-pointers.
    std :: cout << reinterpret_cast < void * >( f ) << std :: endl ; // Function pointer is converted to a void pointer to allow for printout of the adress
}