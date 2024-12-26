#ifndef VECTOR_H
#define VECTOR_H

#pragma once
#include <iostream>

// Declare your class here
// Class Vector takes in two doubles to create a 2-dim mathematical vector
class Vector {


    double x;
    double y;

    public:
        // Constructor
        Vector();
        Vector(double a, double b);
        
        double length() const;
        Vector& operator+=(Vector const & rhs);
        Vector& operator-=(Vector const & rhs);
        Vector& operator*=(double factor);
        Vector& operator/=(double factor);
        bool operator==(Vector const & rhs) const;
        std::ostream& operator<<(std::ostream& out) const;
        //Vector& operator>>(std::istream& in);
};

//double dotProduct(Vector v, Vector w);

Vector operator+(Vector v, Vector const & w);

Vector operator-(Vector v, Vector const & w);

Vector operator-(Vector v);

Vector operator*(Vector v, double n);

Vector operator/(Vector v, double n);

Vector operator*(double n, Vector v);

bool operator!=(Vector const & v, Vector const & w);

std::ostream& operator<<(std::ostream& out, Vector const &v);

bool operator>>(std::istream& in, Vector& v);

#endif
