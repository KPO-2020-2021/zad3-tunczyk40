#include "matrix.hh"
#include <cmath>
class Rectangle
{
    private:
    Vector P[SIZE4]; // tablica wektorow oznaczajacych wierzcholki prostokata
    

    public: 
    Rectangle();
    Rectangle(Vector tmp, Vector tmp2, Vector tmp3, Vector tmp4);
    Rectangle rotation(Rectangle P, double degr, int re);
    Rectangle translation(Rectangle S, Vector v);
    const Vector &operator[] (int index) const;
    Rectangle sides(Rectangle const &tmp);

};
std::ostream &operator << (std::ostream &out, Rectangle const &tmp);

bool operator ==(const Rectangle &p1, const Rectangle &p2);
