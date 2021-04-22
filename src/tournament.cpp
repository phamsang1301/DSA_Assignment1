#include <cstring>
#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif


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
	while (pList->nRingsign == 0 && pList->pNext != NULL)
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
// void removeValueNearTail(ringsignList*& pList, int value)
// {
	
// 	if (pList->nRingsign == value && pList->pNext == NULL)
// 	{
// 		pList = NULL;
// 	}
// 	else if (pList->pNext->nRingsign == value && pList->pNext->pNext == NULL)
// 	{
// 		pList->pNext = NULL;
// 	}
// 	else 
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
// 					if (current->pNext->pNext != NULL)
// 					{
// 						current->pNext = current->pNext->pNext;
// 					}
// 					else 
// 					{
// 						current->pNext = NULL;
// 					}
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

// }
bool removeValueNearTail(ringsignList*& pList, int value)
{
	bool flag = false;
	ringsignList* cur = pList;
	while(cur)
	{
		if (cur->nRingsign == value)
		{
			flag = true;
			break;
		}
		cur = cur->pNext;
	}
	if (flag)
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
		return flag;
	}
	return flag;
}
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


ringsignList*  combat (knight& theKnight, eventList* pEvent)
{
		// new ringList with 1 element is Knight's ringSign

	ringsignList* pList = new ringsignList();
	pList->nRingsign = theKnight.nInitRingsign;
	pList->pNext = NULL;
	if (pEvent != NULL)
	{
	


	//fighting for honor and love here
	eventList *currentEvent = pEvent;
	int numRound  = 0;
	const int MAX_HP = theKnight.HP;

	while (pEvent->nEventCode != 0 && currentEvent != NULL )
	{
		
		if (currentEvent->nEventCode != 0)
		{


			numRound++;
			int b = numRound%10;
			int levelO = numRound>6? (b> 5? b : 5) : b;
			int X = currentEvent->nEventCode >= 10? currentEvent->nEventCode / 10 : currentEvent->nEventCode;
			int RingsignO = currentEvent->nEventCode % 10;
			// cout << "EventCode: "<<currentEvent->nEventCode << "\t \t";
			// cout << "HP: "<<theKnight.HP << "\t \t"<< levelO << "\n";
			switch (X)
			{
					// list ring = new list ring +1 into the last value of the list
				case 7:
						 plusOneIntoLastElement(pList);
						break;
					
				case 8: 
						if (theKnight.HP < MAX_HP)
						{
							theKnight.HP = MAX_HP;

							if (MAX_HP != 777 && MAX_HP !=  888)
							{
								// remove the last element of  ringsignList
								removeTail(pList); 
								if(checkNULL(pList)) return NULL;
							}
							
						}
					break;
				default: 
					if (theKnight.level == levelO) 
					{
						break;
					}
					if (theKnight.level > levelO)
					{
						switch (X) 
						{
						case 1:
							if (MAX_HP == 999)
							{
								break;
							}
							else if (X != 9)
							{
							// add(b) into  last of ring list.
								addTail(pList,RingsignO);
							}
							else
								{
									reverseList(pList);
								}
							
							break;
						case 2: 
							if (MAX_HP == 999)
							{
								break;
							}
							else if (X != 9)
							{
							// add(b) into  last of ring list.
								addTail(pList,RingsignO);
							}
							else
								{
									reverseList(pList);
								}
							
							break;
						case 3: 
							if (MAX_HP == 888)
							{
								break;
							}
							else if (X != 9)
							{
							// add(b) into  last of ring list.
								addTail(pList,RingsignO);
							}
							else
								{
									reverseList(pList);
								}
							
							break;
						case 6: 
							if (MAX_HP == 999 || MAX_HP == 888)
							{
								break;
							}
							else if (X != 9)
							{
							// add(b) into  last of ring list.
								addTail(pList,RingsignO);
							}
							else
								{
									reverseList(pList);
								}
							
							break;
						default:
							if (X != 9)
							{
							// add(b) into  last of ring list.
								addTail(pList,RingsignO);
							}
							else
								{
									reverseList(pList);
								}							
							break;
						}
						// if (((X != 1 || X != 2 || X != 6) && MAX_HP != 999) 
						
						// && ((X != 3 || X != 6) && MAX_HP != 888 ))
						// {	
						// 	if (X != 9)
						// 	{
						// 	// add(b) into  last of ring list.
						// 		addTail(pList,RingsignO);
						// 	}
						// 	else
						// 	{
						// 		reverseList(pList);
						// 	}
						// }
					}
					if (theKnight.level < levelO)
					{
						// cout << "thua \n" << X << endl;

						int baseDamage;
						switch (X)
						{
							case 1:
							{

								if (MAX_HP != 999)
								{
									baseDamage = 10;
								}
								else
								{
									baseDamage = 0;
								}
								int damage = baseDamage * levelO;
								theKnight.HP = theKnight.HP - damage;
								if (theKnight.HP <= 0) return NULL;
							}
								break;
							case 2:
							{
								if (MAX_HP != 999)
								{
									baseDamage = 18;
								}
								else
								{
									baseDamage = 0;
								} 
								int damage = baseDamage * levelO;
								theKnight.HP = theKnight.HP - damage;
								if (theKnight.HP <= 0) return NULL;
							}
								break;
							case 3:
							{
								if (MAX_HP != 888)
								{
									baseDamage = 45;
								}
								else
								{
									baseDamage = 0;
								} 
								int damage = baseDamage * levelO;
								theKnight.HP = theKnight.HP - damage;
								if (theKnight.HP <= 0) return NULL;
							}
								break;
							case 4:
							{
								baseDamage = 82;
								int damage = baseDamage * levelO;
								theKnight.HP = theKnight.HP - damage;
								if (theKnight.HP <= 0) return NULL;
								if (MAX_HP != 777)
								{
								//delete the last ringsign (value b) in list ringsign
									removeValueNearTail(pList, RingsignO);
									if(checkNULL(pList)) return NULL;
								}
							}
								break;
							case 5:
							{
								baseDamage = 75;
								
								int damage = baseDamage * levelO;
								theKnight.HP = theKnight.HP - damage;
								if (theKnight.HP <= 0) return NULL;
						
								if (MAX_HP != 777)
								{
								//delete 3 fist element of the ring list
									remove3FirstElement(pList);
									if(checkNULL(pList)) return NULL;
								}
							}
								break;
							case 6:
								{
									if (MAX_HP != 888 && MAX_HP != 999 )
									{
										baseDamage = 90;

									}
									else
									{
										baseDamage = 0;
									} 		
									
										int damage = baseDamage * levelO;
										theKnight.HP = theKnight.HP - damage;
										if (theKnight.HP <= 0) return NULL;
								}							
								break;
							case 9:
								baseDamage = 1;
								
								int damage = baseDamage * levelO;
								theKnight.HP = theKnight.HP - damage;
								if (theKnight.HP <= 0) return NULL;
						
								if (MAX_HP != 777)
								{
									//delete all (value  b) in the ring list
									removeAllValueX(pList, RingsignO);
									if(checkNULL(pList)) return NULL;
								}
								break;
						}
						
					}	
					break;
			}  
		}
		else {return pList;}	
		 currentEvent = currentEvent->pNext;
	}
	}
	return pList;
	
}


int checkPalindrome(ringsignList* pRingsign)
{
	
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
