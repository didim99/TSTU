
template <typename T>
LinkedList<T>::LinkedList() {
  currItem = NULL;
  firstItem = NULL;
  lastItem = NULL;
  size = 0;
}

template <typename T>
void LinkedList<T>::add(T *data) {
  add(data, size);
}

template <typename T>
void LinkedList<T>::add(T *data, size_t index) {
  if (index < 0 || index > size)
    throw IndexOutOfRangeException();

  listItem *newItem = new listItem;
  newItem->data = data;
  newItem->prev = NULL;
  newItem->next = NULL;

  if (index == size) {
    if (!firstItem) firstItem = newItem;
    if (!lastItem) lastItem = newItem;
    else {
      newItem->prev = lastItem;
      lastItem->next = newItem;
      lastItem = newItem;
    }
  } else if (index == 0) {
    newItem->next = firstItem;
    firstItem->prev = newItem;
    firstItem = newItem;
  } else {
    listItem *item = firstItem;
    for (size_t i = 0; i < index; i++)
      item = item->next;
    newItem->prev = item->prev;
    newItem->next = item;
    item->prev->next = newItem;
    item->prev = newItem;
  }

  currItem = newItem;
  size++;
}

template <typename T>
void LinkedList<T>::remove(listItem *item) {

  if (item == lastItem) {
    if (size > 1) {
      lastItem = item->prev;
      lastItem->next = NULL;
      if (currItem == item)
        currItem = lastItem;
    } else {
      firstItem = NULL;
      lastItem = NULL;
      currItem = NULL;
    }
  } else if (item == firstItem) {
    firstItem = item->next;
    firstItem->prev = NULL;
    if (currItem == item)
      currItem = firstItem;
  } else {
    item->prev->next = item->next;
    item->next->prev = item->prev;
    if (currItem == item)
      currItem = item->next;
  }

  delete item->data;
  delete item;
  size--;
}

template <typename T>
void LinkedList<T>::remove(size_t index) {
  if (index < 0 || index >= size)
    throw IndexOutOfRangeException();
  
  listItem *item = firstItem;
  for (size_t i = 0; i < index; i++)
    item = item->next;
  remove(item);
}

template <typename T>
void LinkedList<T>::removeCurrent() {
  if (!currItem)
    throw IllegalStateException();
  remove(currItem);
}

template <typename T>
void LinkedList<T>::clear() {
  if (size > 0) {
    moveToLast();
    while (size > 0)
      removeCurrent();
  }
}

template <typename T>
T *LinkedList<T>::get(size_t index) {
  if (index < 0 || index >= size)
    throw IndexOutOfRangeException();

  listItem *item = firstItem;
  for (size_t i = 0; i < index; i++)
    item = item->next;
  return item->data;
}

template <typename T>
bool LinkedList<T>::next() {
  if (!currItem || !currItem->next) return false;
  currItem = currItem->next;
  return true;
}

template <typename T>
bool LinkedList<T>::prev() {
  if (!currItem || !currItem->prev) return false;
  currItem = currItem->prev;
  return true;
}

template <typename T>
void LinkedList<T>::moveToFirst() {
  if (!firstItem)
    throw IllegalStateException();
  currItem = firstItem;
}

template <typename T>
void LinkedList<T>::moveToLast() {
  if (!lastItem)
    throw IllegalStateException();
  currItem = lastItem;
}
