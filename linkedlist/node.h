#ifndef NODE_H
#define  NODE_H

#include <iostream>
#include <string>

template <typename T>
struct Node {
  T value;
  struct Node<T> *next;
};

#endif
