/* Example code for Exercises in C.
Based on an example from http://www.learn-c.org/en/Linked_lists
Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

Functions "reverse", "pop", "push" & "remove_by_value" written by CS GOH 27 March 2017
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
 *
 * val: value to store in the node.
 * next: pointer to the next node
 *
 * returns: pointer to a new node
 */
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
 *
 * list: pointer to pointer to Node
 */
void print_list(Node **list) {

    Node *current = *list;
    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
 *
 * list: pointer to pointer to Node
 *
 * returns: int or -1 if the list is empty
 */
int pop(Node **list) {
    // FILL THIS IN!
    if (*list == NULL ){
  		return -1;
  	}

  	if ((*list)->next == NULL ){
  		free(*list);
  		return -1;
  	}

    Node* temp = *list;
    Node* cur = *list;
    cur = cur->next;
  	*list = cur ;
  	free(temp);
  	return (*list)->val;
}


/* Adds a new element to the beginning of the list.
 *
 * list: pointer to pointer to Node
 * val: value to add
 */
void push(Node **list, int val) {
    // FILL THIS IN!
  Node *head = make_node(val,*list);
  *list = head;
}


/* Removes the first element with the given value
 *
 * Frees the removed node.
 *
 * list: pointer to pointer to Node
 * val: value to remove
 *
 * returns: number of nodes removed
 */
int remove_by_value(Node **list, int val) {
    // if list empty
    if (*list == NULL){
      return 0;
    }

    Node* current= *list; // value at head of the list.
    if (current->val == val){
      pop(list);
      return 1;
    }

    if (current->next == NULL) return 0;

    if (current->next->val == val){ // if value at 2nd Node
      Node* temp = current->next;
      current->next = current->next->next;
      free(temp);
      return 1;
    }

    while(current->next->next != NULL){
      if(current->next->val == val){
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
        return 1;
      }
      current = current->next;
    }
    if (current->next->val == val){ // if val at end of list
      Node* temp = current->next;
      current->next = NULL;
      free(temp);
      return 1;
    }
    return 0;
}


/* Reverses the elements of the list.
 *
 * Does not allocate or free nodes.
 *
 * list: pointer to pointer to Node
 */
void reverse(Node **list) {
    // FILL THIS IN!
    if (*list == NULL){
      return ;
    }

    Node* prev = *list;
    if (prev->next == NULL) // only 1 element
      return;

    Node* cur = prev->next;
    prev->next = NULL;

    while (cur->next !=NULL){  // if not at the end of the list
      Node *temp = cur->next;
      // point back
      cur->next = prev;

      // move on
      prev = cur;
      cur = temp;
    }
    cur->next = prev;

    *list = cur;
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 2);
    print_list(list);

    reverse(list);
    print_list(list);
}
