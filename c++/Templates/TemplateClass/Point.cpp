#include "Point.h"

template <typename T>
T Point<T>::getX()
{
  return X;
}

template <typename T>
Point<T>::Point()
{
  
}

template class Point<double>;
template class Point<unsigned int>;