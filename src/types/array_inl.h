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
inline bool Array<int>::toBool() const {
  throw TypeMismatchException("Expected type: boolean, but int array were provided");
}

template<>
inline bool Array<bool>::toBool() const {
  throw TypeMismatchException("Expected type: boolean, but boolean array were provided");
}

template<>
inline Type Array<int>::getType() const {
  return Type::INT_ARRAY;
}

template<>
inline Type Array<bool>::getType() const {
  return Type::BOOLEAN_ARRAY;
}

template<typename T>
size_t Array<T>::getLength() const {
  return array_.size();
}

template<typename T>
void Array<T>::setElementValue(size_t index, T value) {
  array_[index] = value;
}

template<typename T>
T Array<T>::getElementValue(size_t index) const {
  return array_[index];
}
