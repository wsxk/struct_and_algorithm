#include "list2.c"

void interface(void);
int compare(element i,element j);
void visit(list L);

int main()
{
    list store[Maxsize];
    int choice;    //用户指令
    int current=0;   //表示当前表
    int mark = 0;   
    int total = 0; //记录列表的数量
    int i;             //获取位置
    element e;

    for(current = 0;current <Maxsize;current++) //初始化
        store[current]= NULL;
    current =  0;

    printf("Welcome to the LIST system!\n");
    while(1)
    {
        interface();
        scanf("%d",&choice);
        switch (choice)
        {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
            case 1:
                if(total ==Maxsize)
                {
                    printf("\nError,There are too many lists!\n");
                    break;
                }
                for(mark = 0;mark < Maxsize;mark ++)
                {
                    if(store[mark]== NULL)
                        break;
                }
                current = mark;//current 指向当前列表
                store[current]=InitList(store[current]);
                total++;
                printf("\nCreate successfully!\n");
                break;
            
            case 2:
                store[current]=DestroyList(store[current]);
                break;

            case 3:
                store[current]=ClearList(store[current]);
                break;
            
            case 4:
                IsEmpty(store[current]);
                break;
            
            case 5:
                ListLength(store[current]);
                break;
            
            case 6:
                printf("\nPlease input the position:");
                scanf("%d",&i);
                e = GetItem(store[current],i,&e);
                break;
            
            case 7:
                printf("\nPlease input the number:");
                scanf("%d",&e);
                LocateElem(store[current],e,compare);
                break;

            case 8:
                printf("\nPlease choose the element:");
                scanf("%d",&e);
                PriorElem(store[current],e,i);
                break;

            case 9:
                printf("\nPlease choose the element:");
                scanf("%d",&e);
                NextElem(store[current],e,i);
                break;

            case 10:
                printf("\nPlease choose the position:");
                scanf("%d",&i);
                printf("\nPlease integer the element:");
                scanf("%d",&e);
                InsertList(store[current],i,e);
                break;

            case 11:
                printf("\nPlease choose the position:");
                scanf("%d",&i);
                DeleteList(store[current],i,&e);
                break;

            case 12:
                ListTraverse(store[current],visit);
                break;

            case 13:
                printf("\nPlease integer the list:");
                scanf("%d",&i);
                if(store[i]!=NULL)
                {
                    current = i;
                    printf("Change successfully!\n");
                }else
                {
                    printf("Error,the list doesn't exist\n");
                }
                break;

            case 14:
                break;

            default:
                printf("\nWrong code! Please choose the right one!\n");
                break;
        }
        if(choice == 14)
        {
            printf("Thanks to use the list system!\n");
            break;
        }
        system("pause");
        system("cls");
    }
    
    system("pause");
    return 0;
}

void interface(void)
{ 
    printf("------------------------------------------------\n");
    printf("1: create a new list \n");
    printf("2: Destroy a existed list\n");
    printf("3: clear the list \n");
    printf("4: Tell you whether the list is  empty or not\n");
    printf("5: Tell you the length of the list\n");
    printf("6: Get the item of the list\n");
    printf("7: Look for the element accorded with the standard \n");
    printf("8: Get the Prior element \n");
    printf("9: Get the next element \n");
    printf("10: Insert the element \n");
    printf("11: Delete the element \n");
    printf("12: As for all elements in the list,use the function you choose(It will show all the element)\n");
    printf("13: Change the list  \n");
    printf("14: quit\n");
    printf("------------------------------------------------\n");
    printf("Choose the number to use the function\n");
}

int compare(element i,element j)
{
    if(i == j)
        return 1;
    return 0;
}

void visit(list L)
{
    printf("The list has the element:\n");
    while (L->next!=NULL)
    {
        printf("%d ",L->ele);
        L = L->next;
    }
    return;
}