#include <iostream>
#include <list>
#include <map>
#include <string>
#include <utility>
#include <vector>

namespace details
{
    template <typename T, typename U, typename Callable>
    auto apply(std::pair<T, U> element, Callable callable, int, int, int) -> decltype(callable(element.first), std::declval<void> ())
    {
        callable(element.first);
    }

    template <typename T, typename U, typename Callable>
    auto apply(std::pair<T, U> element, Callable callable, int, int, float) -> decltype(callable(element.second), std::declval<void> ())
    {
        callable(element.second);
    }

    template <typename T, typename U, typename Callable>
    auto apply(std::pair<T, U> element, Callable callable, int, float, float) -> decltype(callable(element.first, element.second), std::declval<void> ())
    {
        callable(element.first, element.second);
    }

    template <typename T, typename Callable>
    auto apply(T element, Callable callable, float, float, float)
    {
        callable(element);
    }
}




template <typename T, typename V, typename Callable>
void iterate(T begin, V end, Callable func)
{
    T it = begin;
    while (*it != *end)
    {
        details::apply(*it, func, 0, 0, 0);
        ++it;
    }
}

/** TESTCASES **/

/* Expected output:

1 2 3 
1 2 
one two 
(1, one) (2, two) 
one three two 

 */

void print(int key, std::string const& value)
{
    std::cout << "(" << key << ", " << value << ") ";
}

struct IntPrinter
{
    void operator()(int key) const
    {
        std::cout << key << " ";
    };
};

int main()
{
    std::vector<int> v { 1, 2, 3 };
    iterate(v.begin(), v.end(), [](int v) { std::cout << v << " "; });
    std::cout << std::endl;

    std::list<std::pair<int, std::string>> l { { 1, "one" }, { 2, "two" } };
    iterate(l.begin(), l.end(), IntPrinter{});
    std::cout << std::endl;

    iterate(l.begin(), l.end(), [](std::string const& v) { std::cout << v << " "; });
    std::cout << std::endl;

    iterate(l.begin(), l.end(), print);
    std::cout << std::endl;

    std::map<std::string, std::string> m { { "one", "1" }, { "two", "2" }, { "three", "3" } };
    iterate(m.begin(), m.end(), [](std::string const& k) { std::cout << k << " "; });
    std::cout << std::endl;
}