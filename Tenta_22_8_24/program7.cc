#include <type_traits>

template <typename... Ts>
struct Pack
{
    static constexpr std::size_t size = sizeof...(Ts);
};

int main()
{
    static_assert( Count_Unique<>::value == 0 );
    static_assert( Count_Unique<int, int, int>::value == 1 );
    static_assert( Count_Unique<int, float, int, bool>::value == 3 );
    static_assert( Count_Unique<int, int, int, float>::value == 2 );
    static_assert( Count_Unique<float, int, int, int>::value == 2 );
}