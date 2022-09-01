#include"main.h"

void main(void)
{
    List_t *List = NULL;
	List_State_t ListState = LIST_NEMPTY;
    u32 choose = 0;
    u32 price = 0;
	u32 position = 0;
    u8 BookMat[BOOK_MAX];
    u8 AuthorMat[AUTHOE_MAX];
    CreateList(&List);
    printf("--------------- WELCOME TO THE LIBRARY APP ---------------\n");
    do
    {
        printf("---------------------------------------------\n");
        printf("Choose one of the following options:\n");
        printf("To view all books               Enter '1'\n");
        printf("To add a New book               Enter '2'\n");
        printf("To Delete a book                Enter '3'\n");
        printf("To view No. of available books  Enter '4'\n");
        printf("To Exist the Library App        Enter '5'\n");
        printf("---------------------------------------------\n");
        printf("---> You Choice is: ");
        scanf("%d",&choose);
		fflush(stdin);
        switch(choose)
        {
            case 1:
            {
               if(List->Size==0)
                {
                    printf("The library is empty. No books to view!!\n");
                }
                else
                {
                    printf("-------------------- The Available Books --------------------\n");
                    DisplayData(List,BookMat,AuthorMat);
                }

                break;
            }
            case 2:
            {
                printf("Enter the name of the book: ");
                gets(BookMat);
                printf("Enter the name of the author: ");
                gets(AuthorMat);
                fflush(stdin);
                printf("Enter the book price: ");
                scanf("%d",&price);
                AddToBack(List,BookMat,AuthorMat,price);
                printf("The Book has been added succefully :)\n");
                break;
            }
			case 3:
			{
				List_Empty(List,&ListState);
				if(ListState==LIST_EMPTY)
				{
					printf("Sorry!! The library is EMPTY, there are no Books to display\n");
				}
				else
				{
					printf("Enter the Number of the book you want to delete (from 1 to %d): ",List->Size);
					scanf("%d",&position);
					if(CheckRange(List,position)==RET_OUT_SIZE)
					{
						printf("The number you chose is outside the specified range!!\n");
					}
					else
					{
						RemoveFromPosistion(List,position);
						printf("The Book has been deleted succefully :)\n");
					}
				}
				break;
			}
			case 4:
			{
				if(List->Size==0)
				{
					printf("The Library is empty. No available books to view !\n");
				}
				else
				{
					printf("The Number of available Books is %d",List->Size);
				}
				break;
			}
        }
    }
    while(choose!=5);
    printf("Thanks for using LIBRARY APP\n");
    printf("This APP is created by: Eng.Mahmoud Abdelraoof Mahmoud\n");
    printf("                 GOOD BYE\n");
    printf("******************************************************************************\n");
}
