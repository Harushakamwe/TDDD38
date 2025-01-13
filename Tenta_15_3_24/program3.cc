#include <cassert>
#include <string>
#include <vector>
#include <unordered_map>

template <typename Key, typename Value>
class Sparse_Map
{
    // Assumption 1: Key and Value are always passed in this order

public:

    // TODO: Create an bidirectional iterator
    class iterator
    {
        public:
            using value_type = std::pair<Key, Value>;
            using reference  = std::pair<Key const&, Value&>;
            using pointer    = std::pair<Key const*, Value*>;
            using difference_type = int;
            using iterator_category = std::bidirectional_iterator_tag;

            reference operator*()
            {
                auto&& pair = *current;
                return{pair.first, pair.second}; 
            } 

            iterator& operator++()
            {
                ++current;
                return *this;
            } 

            iterator operator++(int)
            {
                iterator tmp{*this};
                ++(*this);
                return tmp; 
            }  

            iterator& operator--()
            {
                --current;
                return *this;
            } 

            iterator operator--(int)
            {
                iterator tmp{*this};
                --(*this);
                return tmp; 
            }

            bool operator==(iterator const & other) const
            {
                return current == other.current;
            } 

            bool operator!=(iterator const & other) const
            {
                return !(*this == other); 
            }


        private:
            friend class Sparse_Map<Key, Value>;
            iterator(typename std::vector<std::pair<Key, Value>>::iterator current)
            : current{current}
            {}  
            typename std::vector<std::pair<Key, Value>>::iterator current;
    }; 

    // TODO: create begin() and end() functions
    iterator begin()
    {
        return { data.begin() } ;
    } 

    iterator end()
    {
        return { data.end() } ;
    } 
    
    void insert(Key const& key, Value const& value)
    {
        // TODO: associate data.size() (i.e. the index of the next
        //       element that gets pushed) with the specified key in
        //       the lookup table

        if (lookup.count(key))
        {
            return;
        } 

        std::size_t index {data.size()};
        lookup[key] = index;

        data.push_back({ key, value });
    }

    void erase(Key const& key)
    {
        // TODO: replace this lookup with a lookup in the table instead
        /*
        std::size_t index { 0 };
        for (; index < data.size(); ++index)
        {
            if (lookup[index].first == key)
                break;
        }*/

        auto it = lookup.find(key);
        if (it == lookup.end())
        {
            return;
        }  

        std::size_t index = (it->second);


        // remove the element by swapping it with the last element
        // and then popping the vector (constaint-time operation)
        // TODO: remember to update the swapped key in the lookup
        //       table. i.e. since we are moving one element within
        //       data, corresponding key needs to be updated in the
        //       lookup table.
        
        // TODO: remove the 'key' entry in the lookup table
        std::swap(data[index], data.back());
        lookup[data[index].first] = index; 
        data.pop_back();
        lookup.erase(it);

        
    }

    Value& at(Key const& key)
    {
        // TODO: replace with a lookup in the table
        /*std::size_t index { 0 };
        for (; index < data.size(); ++index)
        {
            if (data[index].first == key)
                break;
        }*/
        
        std::size_t index = (lookup.at(key));
        
        return data[index].second;
    }

    std::size_t size() const
    {
        return data.size();
    }
    
private:

    /* TODO: create an appropriate lookup table */
    std::vector<std::pair<Key, Value>> data { };
    std::unordered_map<Key, std::size_t> lookup { };
    
};

int main()
{
    Sparse_Map<std::string, int> map { };
    
    map.insert("def", 2);
    map.insert("abc", 1);
    map.insert("ghi", 3);

    assert( map.at("abc") == 1 );
    assert( map.at("def") == 2 );
    assert( map.at("ghi") == 3 );

    map.erase("def");
    assert( map.size() == 2 );

    map.insert("jkl", 4);

    assert( map.at("abc") == 1 );
    assert( map.at("ghi") == 3 );
    assert( map.at("jkl") == 4 );

    assert( map.size() == 3 );
    
// Uncomment this once you've implemented the iterators
    
    // looping should work once the iterators have been created
    // note that it should be possible to modify value, but not key
    for (auto&& [key, value] : map)
        ++value;

    // make sure that modifying value in the previous loop worked
    assert( map.at("abc") == 2 );
    assert( map.at("ghi") == 4 );
    assert( map.at("jkl") == 5 );
    
    auto it = map.begin();

    // test that all increments and decrements exist and work
    
    assert( it++ == map.begin() );
    assert( --it == map.begin() );

    it = map.end();
    assert( it-- == map.end() );
    assert( ++it == map.end() );

    --(--(--it));
    assert( it == map.begin() );

    ++(++(++it));
    assert( it == map.end() );


}
