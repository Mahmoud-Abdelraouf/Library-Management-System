#include "SLL.h"

u32 Node_No = 0;
/********** Fun 1: to create the Heaad of the list whihc make control of the full list **********/
Error_State_t CreateList(List_t **ListAddress)
{
    Error_State_t FunctionState = RET_OK;
    if(ListAddress != NULL)
    {
        List_t *ListPtr = (List_t*)malloc(sizeof(List_t));
        if(NULL != ListPtr)
        {
            ListPtr -> Head = NULL;
            ListPtr -> Size = 0;
            *ListAddress = ListPtr;
        }
        else
        {
            printf("The malloc() Failed to allocate the required size\n");
        }
    }
    else
    {
        FunctionState = RET_NULL_PTR;
    }
    return FunctionState;
}


/********** Fun 2: to check if the list is empty or not **********/
Error_State_t List_Empty(List_t *List , List_State_t *ReturnValue)
{
    Error_State_t FunctionState = RET_OK;
    if(NULL!=List)
    {
        if(List->Size == 0)
        {
            *ReturnValue = LIST_EMPTY;
        }
        else
        {
            *ReturnValue = LIST_NEMPTY;
        }
    }
    else
    {
        FunctionState = RET_NULL_PTR;
    }
    return FunctionState;
}

/********** Fun 3: to initialize the node **********/
void InitNode(Node_t *Node)
{
	for(int i = 0;i<BOOK_MAX;i++)
	{
		Node->Book_Name[i]=0;
	}
	for(int i = 0;i<AUTHOE_MAX;i++)
	{
		Node->Author_Name[i]=0;
	}
}

/********** Fun 4: to create the node and add the elemnts in it **********/
Error_State_t AddToBack(List_t *List,u8 BookN[],u8 BookA[],s32 Data)
{
    Error_State_t FunctionState = RET_OK;
    Node_t *BufferPtr = NULL;
    if(NULL != List)
    {
        Node_t *NodePtr = (Node_t *)malloc(sizeof(Node_t));
		InitNode(NodePtr); //initialize the node
        if(NodePtr != NULL)
        {
            NodePtr -> Value = Data;
            for(int i = 0;i<BookN[i]!='\0';i++)
            {
                NodePtr->Book_Name[i] =BookN[i];
            }
            for(int i = 0;i<BookA[i]!='\0';i++)
            {
                NodePtr->Author_Name[i]=BookA[i];
            }
            NodePtr -> Next	 = NULL;
            BufferPtr = List-> Head;
            if(BufferPtr==NULL)
            {
                List -> Head = NodePtr;
            }
            else
            {
                while(BufferPtr->Next != NULL)
                {
                    BufferPtr = BufferPtr -> Next;
                }
                BufferPtr -> Next = NodePtr;
            }
            List -> Size++;
            Node_No++;
            NodePtr->No_Of_Node=Node_No;
        }
        else
        {
            FunctionState = RET_NULL_PTR;
        }
    }
    else
    {
        FunctionState = RET_NULL_PTR;
    }
    return FunctionState;
}


/********** Fun 5: to remove the node from the back of the list **********/
static Error_State_t RemoveFromBack(List_t *List ,s32 *Ret_Data)
{
    Error_State_t FunctionState = RET_OK;
    List_State_t List_State = LIST_NEMPTY;
    Node_t *BufferPtr = NULL;
    if((NULL != List) && (NULL != Ret_Data))
    {
        List_Empty(List,&List_State);
        if(List_State == LIST_EMPTY)
        {
            printf("Sorry!! There is no data to Remove the List is EMPTY");
        }
        else
        {
            if(List->Head->Next == NULL)
            {
                *Ret_Data = List->Head->Value;
                free(List -> Head);
                List->Head = NULL;
            }
            else
            {
                BufferPtr = List->Head;
                while(BufferPtr->Next->Next != NULL)
                {
                    BufferPtr = BufferPtr->Next;
                }
                *Ret_Data = BufferPtr->Next->Value;
                free(BufferPtr->Next);
                BufferPtr -> Next = NULL;
            }
            List->Size--;
        }
    }
    else
    {
        FunctionState = RET_NULL_PTR;
    }
    return FunctionState;
}

/********** Fun 6: to remove the node from the front of the list **********/
Error_State_t RemoveFromFront(List_t *List, s32 *Ret_Data)
{
    Error_State_t FunctionState = RET_OK;
    List_State_t List_State = LIST_NEMPTY;
    Node_t *BufferPtr = NULL;
    if(NULL != List && NULL != Ret_Data)
    {
        List_Empty(List,&List_State);
        if(List_State == LIST_EMPTY)
        {
            printf("Sorry!! The List is EMPTY... \n");
        }
        else
        {
            *Ret_Data = List -> Head -> Value;
            BufferPtr = List-> Head;
            List -> Head = BufferPtr -> Next;
            free(BufferPtr);
            List -> Size--;
        }
    }
    else
    {
        FunctionState = RET_NULL_PTR;
    }
    return FunctionState;
}


/********** Fun 7: to detect the range of the list and control other process depend on that **********/
Range_State_t CheckRange(List_t *List,u32 Pos)
{
    Range_State_t FunctionState = RET_OUT_SIZE;
    if(NULL!=List)
    {
        if(Pos >List->Size)
        {
            FunctionState = RET_OUT_SIZE;
        }
        else if(Pos<1)
        {
            FunctionState = RET_LESS_ONE;
        }
        else
        {
            FunctionState = RET_IN_RANGE;
        }
    }
    else
    {
        FunctionState = RET_NULL_ERROR;
    }
    return FunctionState;
}


/********** Fun 8: to remove any node throughout the list **********/
Error_State_t RemoveFromPosistion(List_t *List,u8 Pos)
{
    Error_State_t FunctionState = RET_OK;
    List_State_t List_State = LIST_NEMPTY;
    Node_t *PreviousPos = NULL; //to store the address, previous the exact node which the user wants to remove
    Node_t *NextPos = NULL; //to store the address of the exact node which the user wants to remove
    Node_t *BufferPtr = List->Head;
    if(NULL!=List)
    {
        List_Empty(List,&List_State);
        if(List_State == LIST_EMPTY)
        {
            FunctionState = RET_LIST_EMPTY;
        }
        else
        {
            //is the list have one node
            if(List->Head->Next == NULL)
            {
                //*Ret_Data = List -> Head -> Value;
                free(List->Head);
            }
            //if the user want to remove the 1st node in the list
            else if (Pos==1)
            {
                List -> Head = BufferPtr -> Next;
                List->Head->No_Of_Node=BufferPtr->No_Of_Node;
                free(BufferPtr);
            }
            //if the user want to remove the last node in the list
            else if (Pos==List->Size)
            {
                while(BufferPtr->Next->Next != NULL)
                {
                    BufferPtr = BufferPtr->Next;
                }
                List -> Head = BufferPtr -> Next;
                List->Head->No_Of_Node=BufferPtr->No_Of_Node;
                free(BufferPtr->Next);
                BufferPtr->Next = NULL;
            }
            //if the user want to remove certain node from the middle of the node
            else
            {
                PreviousPos = List->Head;
                for(int i = 1;i<Pos-1;i++)
                {
                    PreviousPos = PreviousPos -> Next;
                }
                NextPos = PreviousPos->Next;
                PreviousPos->Next = NextPos->Next;
                PreviousPos->Next->No_Of_Node=NextPos->No_Of_Node;
                free(NextPos);
            }
            List->Size--;
        }
    }
    else
    {
        FunctionState = RET_NULL_PTR;
    }
    return FunctionState;
}


/********** Fun 9: to display all node in the list **********/
void DisplayData(List_t *List)
{
    Node_t *BufferPtr = List->Head;
    if(NULL!=List)
    {
        if(List->Size==0)
	{
		printf("The library is empty. No books to view!!\n");
	}
        else
        {
		printf("-------------------- The Available Books --------------------\n");
            	while(BufferPtr != NULL)
            	{
                	printf("Book NO.%d\n",BufferPtr->No_Of_Node);
			printf("The Book Name   : %s\n",BufferPtr->Book_Name);
                	printf("The Book Author : %s\n",BufferPtr->Author_Name);
                	printf("The Book Price  : %d\n",BufferPtr->Value);
                	printf("------------------------------------------\n");
               		BufferPtr = BufferPtr->Next;
            	}
        }
    }
    else
    {
        printf("Sorry,You pass NULL Pointer!!");
    }
}
