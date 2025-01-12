#include <cassert>
#include <string>
#include <type_traits>

template <typename T>
class Payload
{
    private:    
        T data;

    public:

        Payload(T a)
        : data{a}
        {}

        operator T() const
        {
            return data;
        }

        template <typename Callable>
        auto operator|(Callable callable)
        {
            using type = typename std::invoke_result<Callable, T>::type;
            type a = callable(data);
            return Payload<type>{a};
        }

        template<typename Q>
        bool operator==(Q comp) const
        {
            return data == comp;
        }
};

template <typename T>
Payload<T> payload(T&& a)
{
    return std::forward<T>(Payload<T>{a});
}

/** TESTCASES **/

int fun1(std::string const& str)
{
    return std::stoi(str);
}

char fun2(int x)
{
    return static_cast<char>(x);
}

struct NextCharacter
{
    char operator()(char c) const { return c + 1; }
};

int main()
{

    assert((payload(1) | [](int    x) -> double { return 1.5f + x; }
                       | [](double y) -> int    { return 2*y; }) == 5);

    assert((payload("67") | fun1 | fun2) == 'C');

    char c { 'a' };
    assert((payload(c) | NextCharacter{}) == 'b');
}