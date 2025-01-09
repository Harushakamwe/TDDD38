#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>


constexpr double tensPower(std::size_t precision)
{
    if (precision == 0)
    {
        return 1.0;
    }
    return 10.0 * tensPower(precision - 1);
}

template <std::size_t precision>
class Interval_Iterator
{
public:

    using value_type = double; 
    using difference_type = std::ptrdiff_t;
    using pointer_type = value_type const*;
    using reference_tyoe = value_type const &;
    using iterator_category = std::random_access_iterator_tag;

    Interval_Iterator(double val = 0.0)
    : value{static_cast<long long> (val*factor)}
    {}

    value_type operator*()
    {
        return value/factor;
    }

    Interval_Iterator& operator+=(long long step)
    {
        value += step;
        return *this;
    }

    Interval_Iterator operator+(long long step) const
    {
        Interval_Iterator tmp {*this};
        tmp += step;
        return tmp;
    }

    Interval_Iterator& operator++()
    {
        return *this += 1;
    }

    Interval_Iterator operator++(int)
    {
        Interval_Iterator tmp {*this};
        ++(*this);
        return tmp;
    }

    Interval_Iterator& operator-=(long long step)
    {
        value -= step;
        return *this;
    }

    Interval_Iterator operator-(long long step) const
    {
        Interval_Iterator tmp {*this};
        tmp -= step;
        return tmp;
    }

    Interval_Iterator& operator--()
    {
        return *this -= 1;
    }

    Interval_Iterator operator--(int)
    {
        Interval_Iterator tmp {*this};
        --(*this);
        return tmp;
    }

    difference_type operator-(Interval_Iterator const & other) const
    {
        return value - other.value;
    }

    bool operator<(Interval_Iterator const & other) const
    {
        return value < other.value;
    }

    bool operator>(Interval_Iterator const & other) const
    {
        return value > other.value;
    }

    bool operator<=(Interval_Iterator const & other) const
    {
        return !(value > other.value);
    }

    bool operator>=(Interval_Iterator const & other) const
    {
        return !(value < other.value);
    }

    bool operator==(Interval_Iterator const & other) const
    {
        return value == other.value;
    }

    bool operator!=(Interval_Iterator const & other) const
    {
        return !(*this == other);
    }

private:
    long long value;
    static constexpr double factor = tensPower(precision); 
};

int main()
{
    std::cout << "Starting Program" << "\n";
    // test the basic behaviour
    {
        int counter { 0 };
        Interval_Iterator<0> start(0.0);
        Interval_Iterator<0> end(10.0);
        while (start != end)
        {
            assert(*start++ == counter++);
        }
    }

    // test that subtraction and std::distance works
    {
        Interval_Iterator<2> start(0.0);
        Interval_Iterator<2> end(1.0);
        assert(end - start == 100);
        assert(std::distance(start, end) == 100);
    }

    // test addition and subtraction
    {
        Interval_Iterator<2> start(0.0);
        assert( *(start + 10) == 0.1 );
        assert( *(start - 10) == -0.1 );
    }

    {
        // Note: precision is 1, meaning second decimal digit doesn't matter
        Interval_Iterator<1> a { 1.12 };
        Interval_Iterator<1> b { 1.13 };
        Interval_Iterator<1> c { 2.14 };

        assert( a == b );
        assert( a <= b );
        assert( a >= b );

        assert( !(a < b) );
        assert( !(a > b) );
        assert( !(a != b) );

        assert( a <= c );
        assert( a < c );
        assert( a != c );

        assert( !(a >= c) );
        assert( !(a > c) );
        assert( !(a == c) );
    }

    // Test that it works with an STL algorithm
    {
        // calculate arcsin(0.5) by binary searching over the value range of std::sin
        // this works for any monotone function (i.e. a function which is increasing or
        // decreasing on the specified interval)
        double x { 0.5 };
	double result { *std::lower_bound(Interval_Iterator<3>(0.0),
					  Interval_Iterator<3>(3.1415), x,
					  [](double check, double pivot)
					  { return std::sin(check) < pivot; }) };
	assert( std::abs(x - std::sin(result)) < 1e-3 );
    }

    std::cout << "Finished Program" << "\n";

}
