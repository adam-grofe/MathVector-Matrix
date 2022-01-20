
#pragma once

#include <blas.hh>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>


/*
 *
 *   Brief: This is template class to handle basic vector operations
 *          using the blas++ library.
 *
 */
template<typename T>
class MathVector {
private:
  std::vector<T> vec;      ///< Use to store and allocate memory dynamically
  size_t N    = 0;         ///< Dimension of vector
  std::string name;        ///< Name of the vector for output

public:
  MathVector() = delete;
  MathVector(size_t n): N(n), vec(n, T(0.)) {};
  MathVector(size_t n, std::string label): N(n), vec(n, T(0.)), name(label) {};

  MathVector(MathVector<T>& w) = default;
  MathVector(MathVector<T>&& w) = default;

  // Getter Functions
  inline T* pointer() { return &vec[0]; };
  inline size_t dimension() { return N; };

  //==========================================================================================
  // Data Functions
  //==========================================================================================

  // Make all of the elements of a vector zero
  void clear() { std::fill_n(pointer(),N,T(0.)); };

  // Access element of vector
  inline T& operator[](size_t i) {
    if( i > N ) throw "Index is out of bounds for MathVector";
    return vec[i];
  };

  // Checks the vectors are the same size
  inline bool sameSize(MathVector<T> u) { return dimension() == u.dimension(); };

  // Set the name of the vector for output
  inline void setName( std::string n ){ name = n; };

  //==========================================================================================
  // Math functions 
  //==========================================================================================

  // Vector dot product
  T operator*(MathVector<T>& w);

  // Const scaling of a vector
  MathVector<T> operator*(T& c);

  // In place scaling of a vector
  void operator*=(T& c);

  // Vector Tensor product r_i = u_i * v_i
  MathVector<T> tensorProd( MathVector<T> u);

  // Vector Addition
  MathVector<T> operator+(MathVector<T>& w);

  // Vector Add in place
  void operator+=(MathVector<T>& w);

  // Normalize Vector
  void normalize();

  //==========================================================================================
  // Output functions
  //==========================================================================================

  // Vector printing
  friend std::ostream& operator<<( std::ostream& out, MathVector& w) {
    out << "Vector(" << w.name << "):" << std::endl;
    for( size_t i = 0; i < w.N; ++i )
        out << "  " << std::fixed << std::setprecision(5) << w[i] << std::endl;
    out << std::endl;
    return out;
  };
};
