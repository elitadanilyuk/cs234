#pragma once
// Provided by:   ____________(your name here)__________
// Email Address: ____________(your email address here)________
// FILE: linkplus.h
// PROVIDES: A toolkit of 14 functions for manipulating linked lists. Each
// node of the list contains a piece of data and a pointer to the next node.
// The type of the data is defined as Node::Item in a typedef statement.
// The complete type definitions used by the toolkit are:
//
// Note: Ten of these 14 functions are from the original link1.h.
// The four new functions are list_occurrences, list_insert_at,
// list_remove_at, and list_copy_segment.
//
//   struct Node                   Item may be any of the C++ built-in types
//   {                             (int, char, etc.), or a class with a default
//       typedef _____ Item;       constructor, an assignment operator,
//       Item data;                and a test for equality (x == y).
//       Node *link;
//   };
//
// FUNCTIONS in the linked list toolkit:
//   size_t list_length(Node* head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The value returned is the number of nodes in the linked
//     list. The list itself is unaltered.
//
//   void list_head_insert(Node*& head_ptr, const Node::Item& entry) 
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: A new node containing the given entry has been added at
//     the head of the linked list; head_ptr now points to the head of the new,
//     longer linked list.
//
//   void list_insert(Node* previous_ptr, const Node::Item& entry) 
//     Precondition: previous_ptr points to a node in a linked list.
//     Postcondition: A new node containing the given entry has been added
//     after the node that previous_ptr points to.
//
//   Node* list_search(Node* head_ptr, const Node::Item& target) 
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The pointer returned points to the first node containing
//     the specified target in its data member. If there is no such node, the
//     null pointer is returned. The list itself is unaltered.
//
//   Node* list_locate(Node* head_ptr, size_t position) 
//     Precondition: head_ptr is the head pointer of a linked list, and
//     position > 0.
//     Postcondition: The pointer returned points to the node at the specified
//     position in the list. (The head node is position 1, the next node is
//     position 2, and so on). If there is no such position, then the null
//     pointer is returned. The list itself is unaltered.
//
//   void list_head_remove(Node*& head_ptr) 
//     Precondition: head_ptr is the head pointer of a linked list, with at
//     least one node.
//     Postcondition: The head node has been removed and returned to the heap;
//     head_ptr is now the head pointer of the new, shorter linked list.
//
//   void list_remove(Node* previous_ptr) 
//     Precondition: previous_ptr points to a node in a linked list, and this
//     is not the tail node of the list.
//     Postcondition: The node after previous_ptr has been removed from the
//     linked list.
//
//   void list_clear(Node*& head_ptr) 
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: All nodes of the list have been returned to the heap,
//     and the head_ptr is now NULL.
//
//   void list_copy(Node* source_ptr, Node*& head_ptr, Node*& tail_ptr) 
//     Precondition: source_ptr is the head pointer of a linked list.
//     Postcondition: head_ptr and tail_ptr are the head and tail pointers for
//     a new list that contains the same items as the list pointed to by
//
//   void list_piece
//     Node* start_ptr, Node* end_ptr, Node*& head_ptr, Node*& tail_ptr) 
//     Precondition: start_ptr and end_ptr are pointers to nodes on the same
//     linked list, with the start_ptr node at or before the end_ptr node.
//     Postcondition: head_ptr and tail_ptr are the head and tail pointers for
//     a new linked list that contains the items from start_ptr to end_ptr.
//     The original list is unaltered.
//
//   size_t list_occurrences(Node* head_ptr, const Node::Item& target)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The return value is the count of the number of times
//     target appears as the data portion of a node on the linked list.
//     The linked list itself is unchanged.
//
//   void list_insert_at(Node*& head_ptr, const Node::Item& entry, size_t position)
//     Precondition: head_ptr is the head pointer of a linked list, and
//     position > 0 and position <= list_length(head_ptr)+1.
//     Postcondition: A new node has been added to the linked list with entry
//     as the data. The new node occurs at the specified position in the list.
//     (The head node is position 1, the next node is position 2, and so on.)
//     Any nodes that used to be after this specified position have been
//     shifted to make room for the one new node.
//
//   Node::Item list_remove_at(Node*& head_ptr, size_t position)
//     Precondition: head_ptr is the head pointer of a linked list, and
//     position > 0 and position <= list_length(head_ptr).
//     Postcondition: The node at the specified position has been removed from
//     the linked list and the function has returned a copy of the data from
//     the removed node.
//     (The head node is position 1, the next node is position 2, and so on.)
//
//   Node* list_copy_segment(Node* head_ptr, size_t start, size_t finish)
//     Precondition: head_ptr is the head pointer of a linked list, and
//     (1 <= start) and (start <= finish) and (finish <= list_length(head_ptr)).
//     Postcondition: The value returned is the head pointer for
//     a new list that contains copies of the items from the start position to
//     the finish position in the list that head_ptr points to.
//     (The head node is position 1, the next node is position 2, and so on.)
//     The list pointed to by head_ptr is unchanged.
//  
// DYNAMIC MEMORY usage by the toolkit: 
//   If there is insufficient dynamic memory, then the following functions call
//   new_handler before any changes are made to the list that head_ptr points
//   to : list_head_insert, list_insert, list_copy, list_piece, list_insert_at,
//   list_copy_segment.

#include "Node.h"

// non-member functions for the linked list toolkit
void list_clear(Node*& head_ptr);

// friend functions for class Node for the linked list toolkit
//void list_head_remove(Node*& head_ptr);
//void list_remove(Node* previous_ptr);
//void list_clear(Node*& head_ptr);
//void list_copy(const Node* source_ptr, Node*& head_ptr, Node*& tail_ptr);
//void list_piece(Node* start_ptr, Node* end_ptr, Node*& head_ptr, Node*& tail_ptr);
//size_t list_occurrences(Node* head_ptr, const Node::value_type& target);
//void list_insert_at(Node*& head_ptr, const Node::value_type& entry, size_t position);
//Node::value_type list_remove_at(Node*& head_ptr, size_t position);
//Node* list_copy_segment(Node* head_ptr, size_t start, size_t finish);
//void list_piece(Node* start_ptr, Node* end_ptr, Node*& head_ptr, Node*& tail_ptr);
//size_t list_occurrences(Node* head_ptr, const Node::value_type& target);
//Node::value_type list_remove_at(Node*& head_ptr, size_t position);
