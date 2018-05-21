#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_ 1

#include <cstdlib>

template <typename T>
class LinkedList {
public:
  LinkedList();
  ~LinkedList() { clear(); }

  void add(T *item);
  void add(T *item, size_t index);
  void remove(size_t index);
  void removeCurrent();
  void clear();
  
  T *get(size_t index);
  T *getCurrent() { return currItem->data; }
  size_t getSize() { return size; }
  bool isEmpty() { return size == 0; }

  void moveToFirst();
  void moveToLast();
  bool next();
  bool prev();

  class IndexOutOfRangeException {};
  class IllegalStateException {};
private:
  struct listItem {
    T *data;
    listItem *next;
    listItem *prev;
  };

  size_t size;
  listItem *currItem;
  listItem *firstItem;
  listItem *lastItem;

  void init();
  void remove(listItem *item);
};

#include "LinkedList_impl.h"

#endif /* _LINKEDLIST_H_ */
