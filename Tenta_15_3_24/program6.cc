#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <typeindex>

struct Name
{
    std::string name;
};

struct Health
{
    int hp;
};

struct Damage
{
    int damage;
};

class ComponentBase
{
    public:
        ComponentBase(std::type_index t)
        :type{t} 
        {} 

        virtual~ComponentBase() = default; 

    private:
    std::type_index type;
};

template <typename T>
class Component : public ComponentBase
{
    std::type_index t = typeid(T);
    public:
        Component(std::type_index t)
        : ComponentBase(typeid(t))
        {

        } 

        T& get()
        {
            return value;
        } 

    private:
        T value;
}; 


class Entity
{
    public:
        template <typename T>
        void add(T obj)
        {
            collection.push_back(new Component<T>());
        } 

        template <typename T>
        bool has(T)
        {

        } 

        template <typename T>
        T& get()
        {

        } 

    private:
        std::vector<ComponentBase*> collection{}; 
};


int main()
{
    int entity_count { 10 };    
    std::vector<Entity> entities(entity_count);

    // a pseudo random number generator
    std::mt19937 gen { std::random_device{}() };

    // generates a number in [0, 100)
    std::uniform_int_distribution<int> dist { 0, 99 };
    
    for (int i { 0 }; i < entity_count; ++i)
    {
        if (dist(gen) <= 50) // 50% chance to get a name
        {
            entities[i].add(Name { "Entity #" + std::to_string(i) });
        }

        if (dist(gen) <= 80) // 80% chance to get health
        {
            entities[i].add(Health{dist(gen)});
        }

        if (dist(gen) <= 75) // 75% chance to get damage
        {
            entities[i].add(Damage{dist(gen)});
        }
    }

    // A system for processing all entities with the Name component
    std::cout << "Named entities: " << std::endl;
    for (Entity& entity : entities)
    {
        if (entity.has<Name>())
        {
            std::cout << " - " << entity.get<Name>().name << std::endl;
        }
    }

    // A system for processing all entities with both Health and Damage
    std::cout << "Battle ready entities: " << std::endl;
    for (std::size_t i { 0 }; i < entities.size(); ++i)
    {
        Entity& entity { entities[i] };
        if (entity.has<Health>() && entity.has<Damage>())
        {
            std::cout << " - " << i << ": has " << entity.get<Health>().hp
                      << " hp and deals " << entity.get<Damage>().damage << " damage"
                      << std::endl;
        }
    }
    
}
