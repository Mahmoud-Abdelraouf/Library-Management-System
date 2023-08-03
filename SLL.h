/**
 * @file SLL.h
 * @brief Header file for singly linked list implementation.
 *
 * This file contains the structures and function prototypes for a singly linked list.
 * The linked list supports adding and removing nodes, checking the list's state, and displaying data.
 */

#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "ERROR_STATE.h"

/**
 * @defgroup LinkedListGroup Singly Linked List
 * @{
 */

typedef struct node
{
    s32 Value;                    /**< Value of the node. */
    u32 No_Of_Node;               /**< Number of nodes in the list (used internally). */
    u8 Book_Name[BOOK_MAX];       /**< Book name (string) stored in the node. */
    u8 Author_Name[AUTHOR_MAX];   /**< Author name (string) stored in the node. */
    struct node *Next;            /**< Pointer to the next node in the list. */
} Node_t;

typedef struct
{
    u32 Size;                     /**< Size of the linked list (number of nodes). */
    Node_t *Head;                 /**< Pointer to the first node (head) of the list. */
} List_t;

typedef enum
{
    LIST_EMPTY,   /**< Linked list is empty. */
    LIST_NEMPTY,  /**< Linked list is not empty. */
    LAST_NODE,    /**< The last node in the list. */
    NLAST_NODE    /**< Not the last node in the list. */
} List_State_t;

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
 * @brief Initialize the node with empty values for Book_Name and Author_Name.
 *
 * This function initializes the node with empty values for Book_Name and Author_Name.
 * It sets all characters in both arrays to zero (null terminator).
 *
 * @param[in, out] Node Pointer to the Node_t structure to be initialized.
 */
void InitNode(Node_t *Node);

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
 * @brief Remove the node from the back of the list.
 *
 * This function removes the node from the back of the linked list and returns the value stored in that node.
 *
 * @param[in] List Pointer to the List_t structure representing the linked list.
 * @param[out] Ret_Data Address of a variable to store the value of the removed node.
 *
 * @return Error_State_t ERROR_OK if successful, otherwise an appropriate error code.
 */
static Error_State_t RemoveFromBack(List_t *List, s32 *Ret_Data);

/**
 * @brief Remove the node from the front of the list.
 *
 * This function removes the node from the front of the linked list and returns the value stored in that node.
 *
 * @param[in] List Pointer to the List_t structure representing the linked list.
 * @param[out] Ret_Data Address of a variable to store the value of the removed node.
 *
 * @return Error_State_t ERROR_OK if successful, otherwise an appropriate error code.
 */
extern Error_State_t RemoveFromFront(List_t *List, s32 *Ret_Data);

/**
 * @brief Detect the range of the list and control other processes dependent on that.
 *
 * This function detects whether the given position (index) is within the valid range of the linked list.
 * The function returns the range state, which can be RET_LESS_ONE, RET_OUT_SIZE, or RET_IN_RANGE.
 *
 * @param[in] List Pointer to the List_t structure representing the linked list.
 * @param[in] Pos The position (index) to be checked.
 *
 * @return Range_State_t The range state, which can be RET_LESS_ONE, RET_OUT_SIZE, or RET_IN_RANGE.
 */
Range_State_t CheckRange(List_t *List, u32 Pos);

/**
 * @brief Remove a node from the specified position in the list.
 *
 * This function removes a node from the specified position in the linked list.
 *
 * @param[in] List Pointer to the List_t structure representing the linked list.
 * @param[in] Pos The position (index) of the node to be removed.
 *
 * @return Error_State_t ERROR_OK if successful, otherwise an appropriate error code.
 */
extern Error_State_t RemoveFromPosition(List_t *List, u32 Pos);

/**
 * @brief Display all nodes in the list.
 *
 * This function displays all nodes in the linked list along with their book names, author names, and values.
 *
 * @param[in] List Pointer to the List_t structure representing the linked list.
 */
void DisplayData(List_t *List);

/**
 * @}
 */

#endif
