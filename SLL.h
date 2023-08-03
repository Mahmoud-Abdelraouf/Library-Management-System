/**
 * @file SLL.h
 * @brief Header file for singly linked list implementation.
 *
 * This file contains the structures and function prototypes for a singly linked list.
 * The linked list supports adding and removing nodes, checking the list's state, and displaying data.
 *
 */

#ifndef SLL_H_
#define SLL_H_

/**
 * @defgroup LinkedListGroup Singly Linked List
 * @{
 */

#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "ERROR_STATE.h"

/**
 * @struct Node_t
 * @brief Structure for each node in the linked list.
 */
typedef struct node
{
    s32 Value;                    /**< Value of the node. */
    u32 No_Of_Node;               /**< Number of nodes in the list (used internally). */
    u8 Book_Name[BOOK_MAX];       /**< Book name (string) stored in the node. */
    u8 Author_Name[AUTHOR_MAX];   /**< Author name (string) stored in the node. */
    struct node *Next;            /**< Pointer to the next node in the list. */
} Node_t;

/**
 * @struct List_t
 * @brief Structure to represent the linked list.
 */
typedef struct
{
    u32 Size;                     /**< Size of the linked list (number of nodes). */
    Node_t *Head;                 /**< Pointer to the first node (head) of the list. */
} List_t;

/**
 * @enum List_State_t
 * @brief Enumeration for the state of the linked list.
 */
typedef enum
{
    LIST_EMPTY,   /**< Linked list is empty. */
    LIST_NEMPTY,  /**< Linked list is not empty. */
    LAST_NODE,    /**< The last node in the list. */
    NLAST_NODE    /**< Not the last node in the list. */
} List_State_t;

/**
 * @enum Range_State_t
 * @brief Enumeration for range checking return state.
 */
typedef enum
{
    RET_LESS_ONE,   /**< Value less than 1 (invalid range). */
    RET_OUT_SIZE,   /**< Value greater than the size of the list (out of range). */
    RET_IN_RANGE,   /**< Value within a valid range (in the list size). */
    RET_NULL_ERROR  /**< Null pointer error. */
} Range_State_t;

/**
 * @brief Create an empty linked list.
 *
 * This function creates an empty linked list and initializes the List_t structure.
 *
 * @param[out] ListAddress Address of a pointer to a List_t structure, will hold the created list.
 *
 * @return Error_State_t ERROR_OK if successful, otherwise an appropriate error code.
 */
extern Error_State_t CreateList(List_t **ListAddress);

/**
 * @brief Check if the linked list is empty or not.
 *
 * This function checks if the linked list is empty or not and returns the result.
 *
 * @param[in] List Pointer to the List_t structure representing the linked list.
 * @param[out] ReturnValue Address of a List_State_t variable to store the result (LIST_EMPTY or LIST_NEMPTY).
 *
 * @return Error_State_t ERROR_OK if successful, otherwise an appropriate error code.
 */
extern Error_State_t List_Empty(List_t *List, List_State_t *ReturnValue);

/**
 * @brief Add a new node with the given book name, author name, and value to the back of the linked list.
 *
 * This function adds a new node with the provided book name, author name, and value to the back of the linked list.
 *
 * @param[in] List Pointer to the List_t structure representing the linked list.
 * @param[in] BookN Book name (string) to be stored in the new node.
 * @param[in] BookA Author name (string) to be stored in the new node.
 * @param[in] Data Value to be stored in the new node.
 *
 * @return Error_State_t ERROR_OK if successful, otherwise an appropriate error code.
 */
extern Error_State_t AddToBack(List_t *List, u8 BookN[], u8 BookA[], s32 Data);

/**
 * @}
 */

#endif /**< SLL_H_ */
