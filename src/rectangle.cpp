#include "rectangle.hh"
#include <iomanip>
#include <iostream>

/******************************************************************************
 |  Konstruktor klasy Rectangle                                               |
 |  Argumenty:                                                                |
 |      tmp1 - obiekt klasy wektor                                            |
 |      tmp2 - obiekt klasy wektor                                            |
 |      tmp3 - obiekt klasy wektor                                            |
 |      tmp4 - obiekt klasy wektor                                            |
 |  Zwraca:                                                                   |
 |      Obiekt klasy Rectangle wypelniony wartosciami podanymi w argumencie   |
 |                                                                            |
 */
Rectangle::Rectangle(Vector tmp1, Vector tmp2, Vector tmp3, Vector tmp4)
{
    P[0] = tmp1;
    P[1] = tmp2;
    P[2] = tmp3;
    P[3] = tmp4;
}
/******************************************************************************
 |  Konstruktor klasy Rectangle                                               |
 |  Argumenty:                                                                |
 |      brak                                                                  |
 |  Zwraca:                                                                   |
 |      Obiekt klasy Rectangle wypelniony wektorami [0][0]                    |
 |                                                                            |
 */
Rectangle::Rectangle()
{   
    int i; Vector tmp;
    for(i = 0; i < 4; ++i)
    {
        P[i] = tmp;
    }
}
/******************************************************************************
 |  Konstruktor klasy Rectangle                                               |
 |  Argumenty:                                                                |
 |      tmp1 - obiekt klasy wektor                                            |
 |      tmp2 - obiekt klasy wektor                                            |
 |      tmp3 - obiekt klasy wektor                                            |
 |      tmp4 - obiekt klasy wektor                                            |
 |  Zwraca:                                                                   |
 |      Obiekt klasy Rectangle wypelniony wartosciami podanymi w argumencie   |
 |                                                                            |
 */
Rectangle Rectangle::rotation(Rectangle S, double degr, int re)
{  
    
    Matrix M(degr);
    for(int p = 1; p <= re; ++p)
    {
        for(int i = 0; i < 4; ++i)
        {
            S.P[i] = M*S.P[i];
        }
    }
    
    return S;
}
/******************************************************************************
 |  Operacja translacji                                                       |
 |  Argumenty:                                                                |
 |      S - prostokat na ktorym zostanie dokonana translacja                  |
 |      tmp - obiekt klasy wektor                                             |
 |  Zwraca:                                                                   |
 |      Prostokat przesuniety o wektor                                        |
 |                                                                            |
 */
Rectangle Rectangle::translation(Rectangle S, Vector tmp)
{   
    
    S.P[0] = S.P[0] + tmp;
    S.P[1] = S.P[1] + tmp;
    S.P[2] = S.P[2] + tmp;
    S.P[3] = S.P[3] + tmp;
    return S;

}
/******************************************************************************
 |  Operacja                                                                  |
 |  Argumenty:                                                                |
 |      index - index wierzcholka prostokata                                  |
 |  Zwraca:                                                                   |
 |      wektor wierzcholka jako stala                                         |
 |                                                                            |
 */
const Vector &Rectangle::operator[] (int index) const
{
    if (index < 0 || index >= SIZE4) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;}
    return P[index];
}



/******************************************************************************
 |  Operacja wyswietlania                                                     |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy                                              |
 |      S - prostokat                                                         |
 |  Zwraca:                                                                   |
 |      Wyswietla wspolrzedne prostokatu                                      |
 |                                                                            |
 */
std::ostream &operator << (std::ostream &out, Rectangle const &S)
{
    for (int i = 0; i < SIZE4; ++i)
    {   
        Vector v = S[i];
        for(int j = 0; j < SIZE; ++j)
        {
        out << std::setw(16) << std::fixed << std::setprecision(10) << v[j];
        if(j == 1)
        {out << std::endl;}
        }
    }
    return out;
}

/******************************************************************************
 |  Operacja porownania i wyswietlania dlugosci bokow                         |
 |  Argumenty:                                                                |
 |      S - prostokat                                                         |
 |  Zwraca:                                                                   |
 |      Komunikat czy boki sa rowne czy nie, oraz wyswietla wartosci dlugosci |
 |      tych bokow                                                            |
 |                                                                            |
 */
Rectangle Rectangle::sides(Rectangle const &S)
{   
    Vector a, b, c, d;
    Vector s1, s2;
    s1 = S[0]; s2 = S[1];
    a = s2 - s1;
    s1 = S[1]; s2 = S[2];
    b = s2 - s1;
    s1 = S[2]; s2 = S[3];
    c = s2 - s1;
    s1 = S[3]; s2 = S[0];
    d = s2 - s1;
    
    double l1 = a.length(a);
    double l2 = b.length(b);
    double l3 = c.length(c);
    double l4 = d.length(d);
    if(l2 < l1)
    {
        if(l1 - l3 < epsilon)
        {
            std::cout << "Dluzsze przeciwlegle boki sa sobie rowne" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << l1
            << std::setw(16) << std::fixed << std::setprecision(10) << l3 << std::endl;
        }
        else
        {
            std::cout << "Dluzsze przeciwlegle boki nie sa sa sobie rowne!!!" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << l1
            << std::setw(16) << std::fixed << std::setprecision(10) << l3 << std::endl;
        }
        if(l2 - l4 < epsilon)
        {
            std::cout << "Krotsze przeciwlegle boki sa sobie rowne" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << l2
            << std::setw(16) << std::fixed << std::setprecision(10) << l4 << std::endl;
        }
        else
        {
            std::cout << "Krotsze przeciwlegle boki nie sa sa sobie rowne!!!" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << l2
            << std::setw(16) << std::fixed << std::setprecision(10) << l4 << std::endl;
        }
        }
    else
    {
        if(l2 - l4 < epsilon)
        {
            std::cout << "Dluzsze przeciwlegle boki sa sobie rowne" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << l2
            << std::setw(16) << std::fixed << std::setprecision(10) << l4 << std::endl;
        }
        else
        {
            std::cout << "Dluzsze przeciwlegle boki nie sa sa sobie rowne!!!" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << l2
            << std::setw(16) << std::fixed << std::setprecision(10) << l4 << std::endl;
        }
        if(l1 - l3 < epsilon)
        {
            std::cout << "Krotsze przeciwlegle boki sa sobie rowne" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << l1
            << std::setw(16) << std::fixed << std::setprecision(10) << l3 << std::endl;
        }
        else
        {
            std::cout << "Krotsze przeciwlegle boki nie sa sa sobie rowne!!!" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << l1
            << std::setw(16) << std::fixed << std::setprecision(10) << l3 << std::endl;
        }
    }
    return S;
    
}
bool operator ==(const Rectangle &p1, const Rectangle &p2)
{   
    for(int i = 0; i <SIZE4; i++)
    {
        if(p1[i] == p2[i]){}
        else{return false;}
    }
    return true;
}