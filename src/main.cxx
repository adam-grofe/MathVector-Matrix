#include "mathvector.hpp"
#include <iostream>
#include <string>

int main( int argc, char *argv[] ){

    size_t n = 3;
    MathVector<double> v(n, "v");
    MathVector<double> w(n, "w");

    v[0] = 1.;
    v[1] = 1.;
    v[2] = 1.;

    w[0] = 1.;
    w[1] = 0.;
    w[2] = 1.;

    std::cout << v;
    std::cout << w;

    std::cout << "z = v + w\n";
    MathVector<double> z = v + w;
    z.setName("z");
    std::cout << z;

    std::cout << "dot = v * w";
    double dot = v*w;
    std::cout << " = " << dot << "\n";

    std::cout << "Normalize z:\n";
    z.normalize();
    std::cout << z;

};
