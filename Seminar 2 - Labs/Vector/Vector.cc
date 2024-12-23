#include "Vector.h"

// implement all the functions declared in Vector.h here

// Konstruktorer

Vector::Vector() {
    this->x = 0.0;
    this->y = 0.0;
}

Vector::Vector(double a, double b) : x(a), y(b)
{
}

void Vector::setX(double x)
{
    this->x = x;
}

void Vector::setY(double y)
{
    this->y = y;
}

double Vector::getX()
{
    return this->x;
}

double Vector::getY()
{
    return this->y;
}

double Vector::length()
{
    return std::sqrt(this->x * this->x + this->y * this->y);
}

// Funktioner
// double dotProduct(Vector v, Vector w)
// {
//     return (v.getX()*w.getX() + v.getY()*w.getY());
// }

Vector operator+(Vector v, Vector w)
{
    Vector res(v.getX()+w.getX() , v.getY()+w.getY());
    return res;
}

Vector operator-(Vector v, Vector w)
{
    Vector res(v.getX()-w.getX() , v.getY()-w.getY());
    return res;
}

Vector operator-(Vector v)
{
    v.setX(-v.getX());
    v.setY(-v.getY());

    return v;
}

Vector operator*(Vector v, double n){

    Vector res(v.getX()*n, v.getY()*n);
    return res;
}

Vector operator/(Vector v, double n)
{
    Vector res(v.getX()/n, v.getY()/n);
    return res;
}

Vector operator*(double n, Vector v){
    Vector res(v.getX()*n, v.getY()*n);
    return res;
}


bool operator==(Vector v, Vector w){
    return (v.getX() == w.getX()) && (v.getY() == v.getX());
}

bool operator!=(Vector v, Vector w){
    return !(v==w);
}

// bool operator<(Vector v, Vector w){}

// bool operator>(Vector v, Vector w){}

std::ostream& operator<<(std::ostream& out, Vector const v){}

std::istream& operator>>(std::istream& in, std::string const string){}
