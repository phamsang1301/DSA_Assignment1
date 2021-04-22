
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;

struct ringsignList  
{
	int nRingsign; 
	ringsignList* pNext;
};


struct knight
{
	int HP;
	int level;
	int nInitRingsign;
};


struct eventList 
{
	int nEventCode;
	eventList* pNext;
};

int checkPalindrome (ringsignList* pRingsign);
ringsignList*  combat (knight& theKnight, eventList* pEvent);



// ringsignList*addHead(ringsignList *& plist, int ringSign)
// {	

// 	ringsignList * newRingsignList = new ringsignList();
// 	newRingsignList->nRingsign = ringSign;
// 	newRingsignList->pNext = plist;
// 	return newRingsignList;
// }

void reverseList(ringsignList*& plist)
{

		ringsignList* current = plist;
        ringsignList *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->pNext;
 
            // Reverse current node's pointer
            current->pNext = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        plist = prev;
	
}

void plusOneIntoLastElement(ringsignList *& pList)
{

	while (pList->nRingsign == 0)
	{
		pList = pList->pNext;
	}
	reverseList(pList);
	if (pList->nRingsign < 9)
	{
		pList->nRingsign++;
		
	}
	else 
	{
		ringsignList * current = pList;
		while(current != NULL)
		{
			current->nRingsign++;

			if (current->nRingsign == 10)
			{	
				current->nRingsign = 0;
				if (current->pNext ==NULL)
				{
					ringsignList* newRingsign = new  ringsignList();
					newRingsign->nRingsign = 1;
					newRingsign->pNext = NULL;
					current->pNext = newRingsign;
					break;
				}

			}
			else 
			{
				break;
			}
			current = current->pNext;

		}

	}
	reverseList(pList);
}
void removeTail(ringsignList *& pList)
{
	if (pList->pNext == NULL)
	{
		pList = NULL;
	}
	else if (pList->pNext->pNext == NULL)
	{
		pList->pNext = NULL;
	
	}
	else 
	{
		ringsignList* current = pList;
		while (current ->pNext->pNext != NULL) 
		{
			current = current->pNext;
		}
		current->pNext =NULL;
	}
}
void addTail(ringsignList*& pList, int a)
{
	ringsignList* newRingsign =  new ringsignList();
	newRingsign->nRingsign = a;
	newRingsign->pNext = NULL;
	if (pList->pNext == NULL)
	{
		pList->pNext = newRingsign;
	}
	else if (pList->pNext->pNext == NULL)
	{
		pList->pNext->pNext = newRingsign;
	}
	else 
	{
		ringsignList* current = pList;
		while(current->pNext != NULL)
		{
			current = current->pNext;
		}
		current->pNext = newRingsign;
	}
}
void removeValueNearTail(ringsignList*& pList, int value)
{
	if (pList->nRingsign == value && pList->pNext == NULL)
	{
		pList = NULL;
	}
	else if (pList->pNext->nRingsign == value && pList->pNext->pNext == NULL)
	{
		pList->pNext = NULL;
	}
	else
	{
		int index = -1;
		int saveIndex;
		ringsignList* current = pList;

		while (current != NULL)
		{
			index++;
			if (current->nRingsign == value)
			{
				saveIndex = index;
			}
			current = current->pNext;
		}

		ringsignList* cur =  pList;
		if (saveIndex == 0)
		{
			pList = pList->pNext;
		}
		else
		{
			for (int i = 0; i < saveIndex - 1; i++)
			{
				
				cur = cur->pNext;
			}
			if (cur->pNext->pNext != NULL)
			{
				cur->pNext = cur->pNext->pNext;
			}
			else 
			{
				cur->pNext = NULL;
			}
		}
	}
}
	// else 
// 	{
// 		reverseList(pList);
// 		if (pList->nRingsign == value)
// 		{
// 			pList = pList->pNext;
// 		}
// 		else
// 		{
// 			bool flag = true;
// 			ringsignList* current  = pList;
// 			while (current != NULL) 
// 			{
// 				if (current->pNext->nRingsign == value)
// 				{
					// if (current->pNext->pNext != NULL)
					// {
					// 	current->pNext = current->pNext->pNext;
					// }
					// else 
					// {
					// 	current->pNext = NULL;
					// }
// 					break;
// 				}
				
// 				current = current->pNext;
// 				if (current->pNext  == NULL)
// 				{
// 					flag = false;
// 					reverseList(pList);
// 					return;
// 				}
// 			}

// 		}

// 		reverseList(pList);

// 	}


void remove3FirstElement(ringsignList*& pList)
{
	if (pList->pNext == NULL 
		|| pList->pNext->pNext == NULL 
		|| pList->pNext->pNext->pNext == NULL)
	{
		pList = NULL;
	}
	else 
	{
		for (int i = 0; i < 3; i++)
		{
			pList = pList->pNext;
		}
	}

}
void removeAllValueX(ringsignList *& plist, int valueX)
{

	ringsignList *tmp = plist;
     bool flag = true;
    while (plist->nRingsign == valueX)
    {
		if (plist->pNext == NULL)
		{
			plist = NULL;
			flag = false;
			break;
		}
		else 
		{
			plist = plist->pNext;
		}
    }
	if (flag)
	{
		while (tmp->pNext != NULL)
		{
			if (tmp->pNext->nRingsign == valueX)
			{
				tmp->pNext = tmp->pNext->pNext;
			}
			else
			{
				tmp = tmp->pNext;
			}
		}
	}
}
bool checkNULL(ringsignList *plist)
{
	return (plist == NULL);
}

int checkPalindrome(ringsignList* pRingsign)
{
	// while (pRingsign->nRingsign == 0)
	// {
	// 	pRingsign = pRingsign->pNext;
	// }
	// ringsignList * list1 = pRingsign;
	// ringsignList * list2 = pRingsign;

	// else 
	// {
	// 	bool flag = false;
	// 	reverseList(list2);
	// 	while (list1 && list2) 
	// 	{
	// 		if (list1->nRingsign == list2->nRingsign) 
	// 		{
	// 			flag = true;
	// 			list1 = list1->pNext;
	// 			list2 = list2->pNext;
				
	// 		}
	// 		else
	// 			return 0;
	// 	}
	// 	if(flag) return 1; 
	// } 
	
	// return 0;
	
    int count = 0;
    ringsignList *ptr = pRingsign;
    while(ptr)
    {
		++count;
        ptr=ptr->pNext;
    }
	if (count == 1)
	{
		return 1;
	}
	else
	{
		ptr=pRingsign;
		int arr[count],count1=0;
		while(ptr!=NULL)
		{
		// cout<<ptr->nRingsign;
			arr[count1]=ptr->nRingsign;
			count1++;
			ptr=ptr->pNext;
		}
		ptr=pRingsign;

		while(ptr!=NULL)
		{
			if(ptr->nRingsign!=arr[count-1])
			{
			return 0;
			}
			ptr = ptr->pNext;
			count--;
			if(count==-1)
			{
				return 1;
			}
		}
	}
	return 0;
}
void check(int numRound, int pEventCode)
{
			int b = numRound%10;
			int levelO = numRound>6? (b> 5? b : 5) : b;
			int X =  pEventCode/ 10;
			int RingsignO = pEventCode % 10;
			cout  << "level0: " << levelO << endl;
			cout << RingsignO;
}
int main()
{
    ringsignList *plist = new ringsignList();
    plist->nRingsign = 0;
    plist->pNext = NULL;

//     ringsignList *newRingsignList = new ringsignList();
// 	newRingsignList->nRingsign = 0;
// 	newRingsignList->pNext = NULL;

//     ringsignList *newRingsignList1 = new ringsignList();
// 	newRingsignList1->nRingsign = 0;
// 	newRingsignList->pNext = newRingsignList1;

// 	ringsignList * newRingsign = new ringsignList();
// 	newRingsign-> nRingsign = 2;
	

//     newRingsignList1->pNext = newRingsign;     
//     plist->pNext = newRingsignList;
//     newRingsign->pNext = newRingsignList1;
// 	ringsignList *newRingsignList2 = new ringsignList();
// 	newRingsignList2->nRingsign = 0;
// 	newRingsignList1->pNext = newRingsignList2;
//     ringsignList *newRingsignList3 = new ringsignList();
// 	newRingsignList3->nRingsign = 0;
// newRingsignList2->pNext = newRingsignList3;
//     ringsignList *newRingsignList4 = new ringsignList();
// 	newRingsignList4->nRingsign = 3;
// newRingsignList3->pNext = newRingsignList4;
//     ringsignList *newRingsignList5 = new ringsignList();
// 		newRingsignList5->nRingsign = 4;
// newRingsignList4->pNext = newRingsignList5;
//     ringsignList *newRingsignList6 = new ringsignList();
// 		newRingsignList4->nRingsign = 6;
// newRingsignList5->pNext = newRingsignList6;
//     ringsignList *newRingsignList7 = new ringsignList();
// 		newRingsignList7->nRingsign = 7;
// newRingsignList6->pNext = newRingsignList7;
//     ringsignList *newRingsignList8 = new ringsignList();
// 	newRingsignList8->nRingsign = 8;
// newRingsignList7->pNext = newRingsignList8;
// newRingsignList8->pNext = NULL;

	// reverseList(plist);
	// plusOneIntoLastElement(plist);
	// removeTail(plist);

	// addTail(plist, 9);

	// remove3FirstElement(plist);

	// removeAllValueX(plist, 1);
	// if (plist == NULL){
	// 	cout << "NULL!";
	// }
	// for (int i  = 1; i < 10; i++)
	// {
	// 	addTail(plist, 0);
	// }

	
	// removeValueNearTail(plist,8);


	// // // plusOneIntoLastElement(plist);

	// ringsignList *cur = plist;

    // while ( plist != NULL)
    // {
    //     cout << plist->nRingsign << " ";

	// 	plist = plist->pNext;
	// }
	// cout << checkPalindrome(cur);
	// check(1,11);
	cout << 48 % 31;

}
