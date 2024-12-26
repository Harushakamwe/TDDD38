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

std::ostream& operator<<(std::ostream& out, Vector &v)
{
    int x = static_cast<int> (v.x);
    int y = static_cast<int> (v.y);
    if (v.x - x == 0.0 && v.y - y == 0.0)
    {
        return out << "(" << x << ", " << y << ")";
    }
    else
    {
        return out << "(" << v.x << ", " << v.y << ")";
    }
        
}

std::istream& operator>>(std::istream& in, Vector &v)
{
    Vector tmp;
    in >> std::ws;
    if (in.peek() == ('('))
    {
        if(in.ignore(1) >> std::ws >> tmp.x >> std::ws)
        {
            if (in.peek() == ',')
            {
                if(in.ignore(1) >> std::ws >> tmp.y >> std::ws)
                {
                    if (in.peek() == ')')
                    {
                        in.ignore(1);
                        v = tmp;
                        return in;
                    }
                    
                }
            }
        }
    }

    in.setstate(std::ios::failbit);
    return in;

}
