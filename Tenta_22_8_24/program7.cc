#include <type_traits>

template <typename... Ts>
struct Pack
{
    static constexpr std::size_t size = sizeof...(Ts);
};

template <typename T, typename... Ts>
struct Contains;

template <typename T>
struct Contains<T>
{
    static constexpr bool value = false;
};

template <typename T, typename... Rest>
struct Contains<T, T, Rest...>
{
    static constexpr bool value = true;
};

template <typename T, typename First, typename... Rest>
struct Contains<T, First, Rest...>
{
    static constexpr bool value = Contains<T, Rest...>::value;
};

template <typename Result, typename... Ts>
struct Make_Unique;

template <typename... Results, typename T, typename... Ts>
struct Make_Unique<Pack<Results...>, T, Ts...>
{
    private:
        using result = std::conditional< Contains<T, Results...>::value,
                                         Pack<Results...>,
                                         Pack<Results..., T> >::type;

    public:
        using type = typename Make_Unique<result, Ts...>::type;
};

template <typename... Ts>
struct Make_Unique<Pack<Ts...>> 
{
    using type = Pack<Ts...>;
};

template <typename... Ts>
struct Count_Unique
{
    private:
        using result = typename Make_Unique<Pack<>, Ts...>::type;

    public:
        static constexpr std::size_t value = result::size;
};

int main()
{
    static_assert( Count_Unique<>::value == 0 );
    static_assert( Count_Unique<int, int, int>::value == 1 );
    static_assert( Count_Unique<int, float, int, bool>::value == 3 );
    static_assert( Count_Unique<int, int, int, float>::value == 2 );
    static_assert( Count_Unique<float, int, int, int>::value == 2 );
}