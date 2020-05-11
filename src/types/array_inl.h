#pragma once

#include "exceptions.h"

template<typename T>
inline Array<T>::Array(size_t size) : array_(size) {

}

template<>
inline int Array<int>::toInt() const {
  throw TypeMismatchException("Expected type: int, but int array were provided");
}

template<>
inline int Array<bool>::toInt() const {
  throw TypeMismatchException("Expected type: int, but boolean array were provided");
}

template<>
inline bool Array<int>::toBoolean() const {
  throw TypeMismatchException("Expected type: boolean, but int array were provided");
}

template<>
inline bool Array<bool>::toBoolean() const {
  throw TypeMismatchException("Expected type: boolean, but boolean array were provided");
}

template<>
inline std::string Array<int>::getName() const {
  return "int[]";
}

template<>
inline std::string Array<bool>::getName() const {
  return "boolean[]";
}