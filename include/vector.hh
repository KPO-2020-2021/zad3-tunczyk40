#pragma once

#include "size.hh"
#include <iostream>
#include <iomanip>


class Vector {

private:

    double size[SIZE];     //Tablica wektora
    friend class Square;
    

public:

    Vector();

    Vector(double [SIZE]);

    Vector(double x, double y);

    Vector operator + (const Vector &v);

    Vector operator - (const Vector &v);

    Vector operator * (const double &tmp);

    Vector operator / (const double &tmp);

    const double &operator [] (int index) const;

    double &operator [] (int index);

    double length(const Vector &v1);

    

};

std::ostream &operator << (std::ostream &out, Vector const &tmp);

std::istream &operator >> (std::istream &in, Vector &tmp);

bool operator ==(const Vector &v1, const Vector &v2);


