#ifndef VECTOR_H
#define VECTOR_H

#pragma once
#include <iostream>

// Declare your class here
class Vector {


    double x;
    double y;

    public:
        // Constructor
        Vector();
        Vector(double a, double b);
        
        double length();
        void setX(double x);
        void setY(double y);
        double getX();
        double getY();
};

//double dotProduct(Vector v, Vector w);

Vector operator+(Vector v, Vector w);

Vector operator-(Vector v, Vector w);

Vector operator-(Vector v);

Vector operator*(Vector v, double n);

Vector operator/(Vector v, double n);

Vector operator*(double n, Vector v);

bool operator==(Vector v, Vector w);

bool operator!=(Vector v, Vector w);

std::ostream& operator<<(std::ostream& out, Vector& v);

std::istream& operator>>(std::istream& in, std::string string);

#endif
