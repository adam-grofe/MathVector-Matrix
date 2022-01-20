
#include "mathvector.hpp"
#include <iostream>
#include <iomanip>
#include <blas.hh>
#include <lapack.hh>

  template class MathVector<float>;
  template class MathVector<std::complex<float>>;
  template class MathVector<double>;
  template class MathVector<std::complex<double>>;


  //================================================
  // Math functions
  //================================================
  template<typename T>
  T MathVector<T>::operator*(MathVector<T>& w) { 
      if( not sameSize(w) ) throw "Dimension mismatch";
      return blas::dot(N, pointer(), 1, w.pointer(), 1); 
  };

  template<typename T>
  MathVector<T> MathVector<T>::operator*(T& c) {
    MathVector<T> retVec(N);
    std::copy_n(pointer(), N, retVec.pointer());
    blas::scal(N, c, retVec.pointer(), 1);
    return retVec;
  };

  template<typename T>
  void MathVector<T>::operator*=(T& c) { blas::scal(N, c, pointer(), 1); }

  template<typename T>
  MathVector<T> MathVector<T>::tensorProd(MathVector<T> u){
    if( not sameSize(u) ) throw "Dimension mismatch";
    MathVector<T> retVec(N);
    for( size_t i=0; i<N; ++i)
      retVec[i] = vec[i]*u[i];
    return retVec;
  }

  template<typename T>
  MathVector<T> MathVector<T>::operator+(MathVector<T>& w) {
    if( not sameSize(w) ) throw "Dimension mismatch";
    MathVector<T> retVec(w.dimension());
    retVec.clear();
    std::copy_n(pointer(),N,retVec.pointer());
    blas::axpy(N, T(1.), w.pointer(), 1, retVec.pointer(), 1);
    return retVec;
  };

  template<typename T>
  void MathVector<T>::operator+=(MathVector<T>& w) {
    if( not sameSize(w) ) throw "Dimension mismatch";
    blas::axpy(N, T(1.), w.pointer(), 1, pointer(), 1);
  };

  template<typename T>
  void MathVector<T>::normalize(){
    T scale = T(1.) / blas::nrm2(N,pointer(),1);
    blas::scal(N,scale,pointer(),1);
  }

  //================================================
  // Output functions
  //================================================
  /*
  template<typename T>
  std::ostream& operator<<( std::ostream& out, MathVector<T>& w) {
    out << "Vector(" << w.name << "):" << std::endl;
    for( size_t i = 0; i < w.N; ++i )
        out << "  " << std::fixed << std::setprecision(5) << w[i] << std::endl;
    out << std::endl;
    return out;
  };
  */