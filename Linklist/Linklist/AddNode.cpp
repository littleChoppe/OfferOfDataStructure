# include <iostream>
# include <stack>

using namespace std;

struct  ListNode
{
	int value;
	ListNode * pNext;
};

void AddToTail(ListNode ** pHead, int value)
{
	ListNode * pNew = new ListNode();
	pNew->value = value;
	pNew->pNext = NULL;

	if (*pHead == NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode * pNode = *pHead;
		while (pNode->pNext != NULL)
		{
			pNode = pNode->pNext;
		}
		pNode->pNext = pNew;
	}
}


void RemoveNode(ListNode ** pHead, int value)
{
	if (pHead == NULL || *pHead == NULL)
		return;

	ListNode * pToBeDelete = NULL;
	if ((*pHead)->value == value)
	{
		pToBeDelete = *pHead;
		*pHead = (*pHead)->pNext;
	}
	else
	{
		ListNode * pNode = *pHead;
		while (pNode->pNext != NULL && pNode ->pNext->value != value)
		{
			pNode = pNode->pNext;
		}

		if (pNode->pNext != NULL && pNode->pNext->value == value)
		{
			pToBeDelete = pNode->pNext;
			pNode->pNext = pNode->pNext->pNext;
		}
	}

	if (pToBeDelete != NULL)
	{
		delete pToBeDelete;
		pToBeDelete = NULL;
	}
}

void PrintListReversingly_Stack(ListNode * pHead)
{
	stack<ListNode *> nodes;
	ListNode * pNode = pHead;
	while (pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf_s("%d\t", pNode->value);
		nodes.pop();
	}
	printf_s("\n");
}

void PrintListReversingly_Recursively(ListNode * pHead)
{
	if (pHead != NULL)
	{
		if (pHead->pNext != NULL)
			PrintListReversingly_Recursively(pHead->pNext);
		printf_s("%d\t", pHead->value);
	}
}

int main()
{
	ListNode * pHead = NULL;
	AddToTail(&pHead, 1);
	AddToTail(&pHead, 2);
	AddToTail(&pHead, 3);

	PrintListReversingly_Stack(pHead);
	RemoveNode(&pHead, 1);
	PrintListReversingly_Recursively(pHead);
	return 0;
}