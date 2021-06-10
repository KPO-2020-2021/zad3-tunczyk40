#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "../include/vector.hh"
#include "../include/matrix.hh"
#include "../include/rectangle.hh"




// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.
TEST_CASE("construction of vector without parameters")
{   
    Vector v;
    Vector v2(0, 0);
    CHECK(v == v2);
}
TEST_CASE("Construction of vector with parameters")
{
    double tmp[SIZE] = {4, 2};
    Vector v(tmp);
    Vector v2(4, 2);
    CHECK(v == v2);
}
TEST_CASE("Vector Sum")
{
    Vector v(8, -6);
    Vector v1(4, 2);
    Vector v2(4, -8);
    Vector v3;
    v3 = v1 + v2;
    CHECK(v == v3);
}
TEST_CASE("Vector Subtraction")
{
    Vector v(0, 10);
    Vector v1(4, 2);
    Vector v2(4, -8);
    Vector v3;
    v3 = v1 - v2;
    CHECK(v == v3);
}
TEST_CASE("Vector Operator <<")
{
    Vector v(4,2);
    Vector v2(4.0, 2.0);
    std::stringstream v1, v3;
    v1 << v; v3 << v2;
    CHECK(v1.str() == v3.str());

}
TEST_CASE("Vector Operator ==")
{
    Vector v1(4, 2);
    Vector v2(4.00000000001, 2.00000000001);
    CHECK(v1 == v2);
}
TEST_CASE("Vector Operator >>")
{
    std::stringstream in1, in2;
    Vector v(4, 2), v2(4.0, 2.0);


}
TEST_CASE("Matrix constructor without parameters")
{   
    double tmp[SIZE][SIZE] = {0, 0, 0, 0};
    Matrix m1; Matrix m2(tmp);
    CHECK(m1 == m2);
}
TEST_CASE("Matrix constructor with parameters")
{
    double tmp1[SIZE][SIZE] = {2, 4, 3, 6}, tmp2[SIZE][SIZE] = {2, 4, 3, 6};
    Matrix m1(tmp1), m2(tmp2);
    CHECK(m1 == m2);
}
TEST_CASE("Matrix operator ()")
{
    double tmp1[SIZE][SIZE] = {2, 4, 3, 6};
    Matrix m(tmp1);
    bool odp1, odp2;
    if(m(0,0)==2 && m(0,1) == 4){odp1 = true;}else{odp1 = false;}
    if(m(1, 0) == 3 && m(1, 1) == 6){odp2 = true;}else{odp2 = false;}
    CHECK(odp1 == odp2);
}
TEST_CASE("Matrix of rotation")
{
    double degr = 45;
    Matrix m1(degr);
    double tmp [SIZE][SIZE] ={sqrt(2)/2, -sqrt(2)/2, sqrt(2)/2, sqrt(2)/2};
    Matrix m2(tmp);
    CHECK(m1 == m2);

}
TEST_CASE("Rectangle constructor without parameters")
{
    Rectangle p;
    Vector v1(0, 0), v2(0,0), v3(0, 0), v4(0, 0);
    Rectangle p2(v1, v2, v3,v4);
    CHECK(p == p2);
}
TEST_CASE("REctangle translation")
{   
    Vector v1(0, 100), v2(0, 160), v3(120, 160), v4(120, 100), v5(50, 60);
    Vector n1(50, 160), n2(50, 220), n3(170, 220), n4(170, 160);
    Rectangle p(v1, v2, v3, v4);
    Rectangle p2(n1, n2, n3, n4);
    p = p.translation(p, v5);
    CHECK(p == p2);

}
