#include "Vector.h"

// implement all the functions declared in Vector.h here

// Konstruktorer

Vector::Vector() : x{0.0}, y{0.0}
{
}

Vector::Vector(double a, double b) : x(a), y(b)
{
}

Vector& Vector::operator+=(Vector const &rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Vector& Vector::operator-=(Vector const &rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}

Vector& Vector::operator*=(double factor)
{
    this->x *= factor;
    this->y *= factor;
    return *this;
}

Vector& Vector::operator/=(double factor)
{
    this->x /= factor;
    this->y /= factor;
    return *this;
}

double Vector::length() const
{
    return std::sqrt(this->x * this->x + this->y * this->y);
}

// Funktioner
// double dotProduct(Vector v, Vector w)
// {
//     return (v.getX()*w.getX() + v.getY()*w.getY());
// }

Vector operator+(Vector v, Vector const & w)
{
    return Vector{v+=w};
}

Vector operator-(Vector v, Vector const & w)
{
    return Vector{v-=w};
}

Vector operator-(Vector v)
{
    return (v*=-1);
}

Vector operator*(Vector v, double n){

    return (v*=n);
}

Vector operator/(Vector v, double n)
{
    return {v/=n};
}

Vector operator*(double n, Vector v){
     return (v*=n);
}


bool Vector::operator==(Vector const & w) const 
{
    return (this->x == w.x) && (this->y == w.y);
}

bool operator!=(Vector const & v, Vector const & w){
    return !(v==w);
}

std::ostream& Vector::operator<<(std::ostream& out) const
{
    int x = static_cast<int> (this->x);
    int y = static_cast<int> (this->y);
    if (this->x - x == 0.0 && this->y - y == 0.0)
    {
        return out << "(" << x << ", " << y << ")";
    }
    else
    {
        return out << "(" << this->x << ", " << this->y << ")";
    }
        
}

std::ostream& operator<<(std::ostream& out, Vector const &v)
{
    return v.operator<<(out);
        
}
//Vector& Vector::operator>>(std::istream& in)

bool operator>>(std::istream& in, Vector& v)
{
    std::cout << "In operator>>" << std::endl;
    std::string str{};
    std::getline(in >> std::ws, str);
    std::cout << str << std::endl;
    if (in.fail())
    {
        std::cout << "Wrong format for input to Vector." << std::endl;
        return false; 
    }

    std::getline(in, str, ',');
    std::cout << str << std::endl;
    if (in.fail())
    {
        std::cout << "Wrong format for input to Vector." << std::endl;
        return false; 
    }

    std::getline(in, str, ')');
    std::cout << str << std::endl;
    if (in.fail())
    {
        std::cout << "Wrong format for input to Vector." << std::endl;
        return false; 
    }

    return true;
    
    //std::cout << str << std::endl;
    //return in;
}