#ifndef SLL_H
#define SLL_H

#define BOOK_MAX 20
#define AUTHOE_MAX 20

#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "ERROR_STATE.h"


typedef struct node
{
    s32 Value;
	u32 No_Of_Node;
    u8 Book_Name[BOOK_MAX];
    u8 Author_Name[AUTHOE_MAX];
    struct node *Next;
}Node_t;


typedef struct
{
    u32 Size;
    Node_t *Head;
}List_t;

typedef enum
{
    LIST_EMPTY,
    LIST_NEMPTY,
    LAST_NODE,
    NLAST_NODE,
}List_State_t;


typedef enum
{
	RET_LESS_ONE,
	RET_OUT_SIZE,
	RET_IN_RANGE,
	RET_NULL_ERROR
}Range_State_t;


extern Error_State_t CreateList(List_t **ListAddress);
extern Error_State_t List_Empty(List_t *List , List_State_t *ReturnValue);
extern Error_State_t AddToBack(List_t *List,u8 BookN[],u8 BookA[],s32 Data);
static Error_State_t RemoveFromFront(List_t *List, s32 *Ret_Data);
static Error_State_t RemoveFromBack(List_t *List ,s32 *Ret_Data);
extern Range_State_t CheckRange(List_t *List,u32 Pos);
extern Error_State_t RemoveFromPosistion(List_t *List,u8 Pos);
extern void DisplayData(List_t *List);










#endif
