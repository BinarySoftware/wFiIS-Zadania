#pragma once

/**
 * Structure holding double linked list's node.
 */
struct Node {
  char data[100]; /**< String contained in node. */
  Node * next; /**< Pointer to the next element. */
  Node * previous; /**< Pointer to prevoius element. */
};

/**
 * Structure holding double linked list's head node.
 */
struct List {
  Node * head; /**< Pointer to the first element. */
};

/**
 * Prepares new list by setting it's head to NULL.
 *
 * @param l - pointer to the list.
 */
void prepare(List * l);

/**
 * Pushes to the end of the list.
 *
 * @param l - pointer to the list.
 * @param buffer - data to be written into node.
 */
void push_back(List * l, const char * buffer);

/**
 * Pushes to the beginning of the list.
 *
 * @param l - pointer to the list.
 * @param buffer - data to be written into node.
 */
void push_front(List * l, const char * buffer);

/**
 * Gets status of the list.
 *
 * @param l - pointer to the list.
 * @return - returns 1 if list is empty, otherwise 0.
 */
int empty(const List * l);

/**
 * Prints all the contents of the list.
 *
 * @param l - pointer to the list.
 */
void dump(const List * l);

/**
 * Deletes given list from the memory.
 *
 * @param l - pointer to the list.
 */
void clear(List * l);
