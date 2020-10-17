#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "list.h"

// In this series of exercises, you'll implement a simple linked list storing
// a collection of key/value pairs sorted alphabetically by key strings.
// You should read the type definition of linked list node in list.h file

// list_init initializes a sorted (linked) list.
// A linked list is identified by its head pointer.
// To initialize a list, this function sets its head pointer to NULL.
// This function takes as its argument "headdp", a double pointer that
// points to the head pointer to be initialized.
void list_init(lnode_t **headdp)
{
  *headdp = 0;
}

// sum_accum is an accumulator function that adds "new_val" into the
// current sum value pointed to by "existing_val".
// This function has already been implemented for you.
void sum_accum(int *existing_val, int new_val)
{
  (*existing_val) += new_val;
}

// Insert a key value pair into the linked list while maintaining sorted order.
// Return true if the key does not already exists; false otherwise.
//
// If the key already exists, accumulate the new value into the existing value
// using the given function pointer "accum".  The implementation of an example
// accumulator function can be seen earlier (sum_accum)
//
//
// Notes: 1) you need to allocate space for a new linked list node,
// but you do not need to allocate space to copy the entire key string; it's enough to
// store the key string pointer in the linked list node.
// 2) since the new node may be inserted in the beginning of the list,
// you may need to change the head pointer of the linked list.
// Therefore, this function takes as its arguments "headdp", a double pointer
// that points to the head pointer of the linked list, thereby allowing you to change
// the head pointer.
//
// You may use strcmp from C library (instead of your own string_cmp in str.h).


// bool r = list_insert_with_accum(&headp, "world", 1, sum_accum);

bool list_insert_with_accum(lnode_t **headdp, char *key, int val,
    void (*accum)(int *existing_val, int new_val))
{

  if ((*headdp) == NULL){ // when the linked list is empty
    *headdp = (struct lnode *)malloc(sizeof(struct lnode));
    (*headdp)->tuple.key = key;
    (*headdp)->tuple.val = val;
    (*headdp)->next = NULL;
    return 1; // because the list is empty already,
    // of course the key value does not already exist
  }
  else { // the case where the linked list already exist
    // this case, I will have to go through the list

    // first create a fake pointer
    lnode_t *headp = (*headdp);
    lnode_t *node_ptr = (headp);

    while(strcmp(((node_ptr)->tuple.key), key) <= 0 && (node_ptr)->next != NULL){
      if (strcmp(((node_ptr->next)->tuple.key), key) <= 0){
        (node_ptr) = (node_ptr)->next;
      } else {
        break;
      }
    }

    if (strcmp(((node_ptr)->tuple.key), key) == 0){ // if the new added value already exists
      accum(&(node_ptr->tuple.val), val);
      // go_through(*headdp);
      return 0;
    }
    else {                                        // if the new added value does NOT already exist
      // create new instance
      struct lnode *new_node = (struct lnode *)malloc(sizeof(struct lnode));
      new_node->tuple.key = key;
      new_node->tuple.val = val;


      if (strcmp(((*headdp)->tuple.key), key) > 0){ // if the new added value comes before all the list
        new_node->next = (*headdp);
        (*headdp) = new_node;
      } else {                                      // if the new added value comes between or at the end
        if ((node_ptr)->next == NULL){                  // case 1: if it comes at the end
          new_node->next = NULL;
          (node_ptr)->next = new_node;
        }
        else {                                          // case 2: if it comes in between
          new_node->next = node_ptr->next;
          node_ptr->next = new_node;

        }
      }
      return 1;
    }
  }
}



// typedef struct  bst_node {
//     char * data;
//     struct bst_node * right;
//     struct bst_node * left;
// } bst_node ;

// typedef struct {
//   char *key;
//   int val;
// } kv_t;

// typedef struct lnode {
//   struct lnode *next;
//   kv_t tuple;
// } lnode_t;

// Find if a given key string exists in the sorted linked list.
// Return the value associated with the key if key is found.
// Otherwise, return -1.
// This function takes as argument headp, a single pointer that points to
// the first linked list node
//
// You may use strcmp from C library (instead of your own string_cmp in str.h).
int list_find(lnode_t *headp, char *key)
{
  if (headp == NULL){
    return -1;
  }
  while (headp->tuple.key != key){
    headp = headp->next;
  }
  return headp->tuple.val;

}

// typedef struct  bst_node {
//     char * data;
//     struct bst_node * right;
//     struct bst_node * left;
// } bst_node ;

// typedef struct {
//   char *key;
//   int val;
// } kv_t;

// typedef struct lnode {
//   struct lnode *next;
//   kv_t tuple;
// } lnode_t;

// Traverse the linked list starting from node pointed to by "headp"
// and store all the encountered key-value tuples in the array "tuples".
// The capacity of the "tuples" array is "max", thus, the function should not
// store more than "max" pointers in "tuples".
// Return value is the actual number of key-value tuples
// written to "tuples".
int list_get_all_tuples(lnode_t *headp, kv_t *tuples, int max)
{
  int actual_num = 0;
  if (headp == NULL){
    return -1;
  } else {
    while(headp != NULL){
      tuples->key = headp->tuple.key;
      tuples->val = headp->tuple.val;
      tuples = tuples + 1;
      headp = headp->next;
      actual_num = actual_num + 1;
    }
  }

  return actual_num;
}

void go_through(lnode_t *headp)
{
  printf("\n\n--------go through activated--------\n");
  printf("key \tval\n");
  while(headp != NULL){
    printf("%s\t%d\n", headp->tuple.key, headp->tuple.val);
    headp = headp->next;
  }
  printf("--------go through done--------\n\n");
}