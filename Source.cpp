#include <iostream>
#include <string>

using namespace std;

struct node {
	int num;
	node* ptr;
};

struct list {
	node* head = nullptr;
	node* prev = nullptr;
	node* current = nullptr;
	node* next = nullptr;
	node* tail = nullptr;
};

node* XOR(node* a, node* b)
{
	return (node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void printNext(list* lst)
{
	if (lst->current == nullptr)
	{
		printf("NULL \n");
	}
	else if (lst->current == lst->tail)
	{
		lst->prev = lst->current;
		lst->current = lst->head;
		if (lst->head != nullptr)
		{
			lst->next = lst->head->ptr;
		}
		printf_s("%d \n", lst->current->num);
	}
	else
	{
		lst->prev = lst->current;
		lst->current = lst->next;
		lst->next = XOR(lst->current, lst->next);
		printf_s("%d \n", lst->current->num);
	}

	return;
}

void printPrev(list* lst) 
{
	if (lst->current == nullptr)
	{
		printf("NULL \n");
	}
	else if (lst->current == lst->head)
	{
		lst->next = lst->current;
		lst->current = lst->tail;
		lst->prev = lst->tail->ptr;
		printf_s("%d \n", lst->current->num);
	}
	else
	{
		lst->next = lst->current;
		lst->current = lst->prev;
		lst->prev = XOR(lst->current, lst->prev);
		printf_s("%d \n", lst->current->num);
	}

	return;
}

void addBeg(list* lst, int num) 
{
	node* newnode = new node();
	newnode->num = num;

	newnode->ptr = lst->head;
	if (lst->head != nullptr)									//if old head does exist
	{
		if (lst->head->ptr != nullptr)							//if old head has a next
		{
			lst->head->ptr = XOR(newnode, lst->head->ptr);
		}
		else													//if old head doesnt have a next
		{																			
			lst->tail = lst->head;
			lst->head->ptr = newnode;
		}
	}
	else														//if head doesnt exist
	{
		lst->tail = newnode;
	}
	

	if (lst->current == nullptr)
	{
		lst->current = newnode;
	}
	else if (lst->current == newnode->ptr)
	{
		lst->prev = newnode;
	}

	lst->head = newnode;

	return;
}

void addEnd(list* lst, int num) 
{
	node* newnode = new node();
	newnode->num = num;

	newnode->ptr = lst->tail;
	if (lst->tail != nullptr)
	{
		if (lst->tail->ptr != nullptr)
		{
			lst->tail->ptr = XOR(newnode, lst->tail->ptr);
		}
		else
		{
			lst->head = lst->tail;
			lst->tail->ptr = newnode;
		}
	}
	else
	{
		lst->head = newnode;
	}
	
	if (lst->current == nullptr)
	{
		lst->current = newnode;
	}
	else if (lst->current == newnode->ptr)
	{
		lst->next = newnode;
	}

	lst->tail = newnode;

	return;
}

void addAct(list* lst, int num) 
{
	if (lst->current == lst->head || lst->current == nullptr)
	{
		addBeg(lst, num);
	}
	else if (lst->current == lst->tail)
	{
		node* newnode = new node();
		newnode->num = num;

		newnode->ptr = XOR(lst->tail->ptr, lst->tail);
		lst->tail->ptr->ptr = XOR(XOR(lst->tail, lst->tail->ptr->ptr), newnode);
		lst->tail->ptr = newnode;
		lst->prev = newnode;
	}
	else
	{
		node* newnode = new node();
		newnode->num = num;

		newnode->ptr = XOR(lst->prev, lst->current);
		lst->prev->ptr = XOR(XOR(newnode, lst->prev->ptr), newnode);
		lst->current->ptr = XOR(newnode, lst->next);
		lst->prev = newnode;
	}
}

void delBeg(list* lst) 
{
	if (lst->head != nullptr)
	{
		if (lst->head == lst->current)
		{
			lst->current = lst->head->ptr;
		}

		node* tmp = lst->head->ptr;
		if (lst->head->ptr != nullptr)
		{
			lst->head->ptr->ptr = XOR(lst->head, lst->head->ptr->ptr);
		}
		delete lst->head;
		lst->head = tmp;
	}

	return;
}

void delEnd(list* lst) 
{
	if (lst->head != nullptr)
	{
		if (lst->tail == lst->current)
		{
			lst->current = lst->tail->ptr;
		}

		node* tmp = lst->tail->ptr;
		if (lst->tail->ptr != nullptr)
		{
			lst->tail->ptr->ptr = XOR(lst->tail->ptr->ptr, lst->tail);
		}
		delete lst->tail;
		lst->tail = tmp;
	}

	return;
}
	
void delAct(list* lst) 
{
	if (lst->current != nullptr)
	{
		if (lst->current == lst->head)
		{
			if (lst->current->ptr == nullptr)
			{
				lst->current = nullptr;
				lst->prev = nullptr;
				lst->next = nullptr;
			}
			else
			{
				lst->current = lst->tail;
				lst->prev = lst->tail->ptr;
				lst->next = lst->head;
			}

			delBeg(lst);
		}
		else if (lst->current == lst->tail)
		{
			if (lst->current->ptr == nullptr)
			{
				lst->current = nullptr;
				lst->prev = nullptr;
				lst->next = nullptr;
			}
			else
			{
				lst->current = lst->head;
				lst->next = lst->head->ptr;
				lst->prev = lst->tail;
			}

			delEnd(lst);
		}
		else
		{
			lst->next->ptr = XOR(lst->prev, XOR(lst->current, lst->next->ptr));
			lst->prev->ptr = XOR(lst->next, XOR(lst->current, lst->prev->ptr));
			
			delete lst->current;
			lst->current = lst->prev;
			lst->prev = XOR(lst->current, XOR(lst->current, lst->prev->ptr));
		}
	}

	return;
}

void delVal(list* lst, int num)
{
	node* tmpcur = lst->head, * tmpprev = nullptr, * tmpnext = nullptr;

	while (tmpcur != nullptr)
	{
		if (tmpcur->num == num)
		{
			node* tmpc = lst->current, * tmpp = lst->prev, * tmpn = lst->next;
			lst->current = tmpcur;
			lst->prev = tmpprev;
			lst->next = tmpnext;

			delAct(lst);

			lst->current = tmpc;
			lst->prev = tmpp;
			lst->next = tmpn;

			tmpcur = lst->head;
			tmpprev = nullptr;
			tmpnext = nullptr;
		}
		
		else
		{
			tmpnext = XOR(tmpprev, tmpcur->ptr);
			tmpprev = tmpcur;
			tmpcur = tmpnext;
		}

	}
	
	return;
}
	
void prntForw(list* lst) 
{
	node* tmpcur = lst->head, * tmpprev = nullptr, * tmpnext;

	if (tmpcur == nullptr)
	{
		printf("NULL");
	}
	else
	{
		while (tmpcur != nullptr)
		{
			printf_s("%d ", tmpcur->num);

			tmpnext = XOR(tmpprev, tmpcur->ptr);
			tmpprev = tmpcur;
			tmpcur = tmpnext;
		}
	}

	printf_s("\n");

	return;
}

void prntBackw(list* lst) 
{
	node* tmpcur = lst->tail, * tmpprev, * tmpnext = nullptr;

	if (tmpcur == nullptr)
	{
		printf("NULL");
	}
	else
	{
		while (tmpcur != nullptr)
		{
			printf_s("%d ", tmpcur->num);

			tmpprev = XOR(tmpnext, tmpcur->ptr);
			tmpnext = tmpcur;
			tmpcur = tmpprev;
		}
	}

	printf_s("\n");

	return;
}

void deleteList(list* lst)
{
	node* tmpcur = lst->tail, * tmpprev = nullptr, * tmpnext = nullptr;

	while (tmpprev != nullptr)
	{
		tmpprev = XOR(tmpnext, tmpcur->ptr);
		delete tmpnext;
		tmpnext = tmpcur;
		tmpcur = tmpprev;
	}

	return;
}

int switchCheck(string str, list* lst)
{
	int num;

	if (str == "ACTUAL")
	{
		if (lst->current != nullptr)
		{
			printf_s("%d \n", lst->current->num);
			//cout << lst.current->num << endl;
		}
		else
		{
			printf_s("NULL \n");
		}

		return 0;
	}
	else if (str == "NEXT")
	{
		printNext(lst);
		return 0;
	}
	else if (str == "PREV")
	{
		printPrev(lst);
		return 0;
	}
	else if (str == "ADD_BEG")
	{
		cin >> num;
		addBeg(lst, num);
		return 0;
	}
	else if (str == "ADD_END")
	{
		cin >> num;
		addEnd(lst, num);
		return 0;
	}
	else if (str == "ADD_ACT")
	{
		cin >> num;
		addAct(lst, num);
		return 0;
	}
	else if (str == "DEL_BEG")
	{
		delBeg(lst);
		return 0;
	}
	else if (str == "DEL_END")
	{
		delEnd(lst);
		return 0;
	}
	else if (str == "DEL_VAL")
	{
		cin >> num;
		delVal(lst, num);
		return 0;
	}
	else if (str == "DEL_ACT")
	{
		delAct(lst);
		return 0;
	}
	else if (str == "PRINT_FORWARD")
	{
		prntForw(lst);
		return 0;
	}
	else if (str == "PRINT_BACKWARD")
	{
		prntBackw(lst);
		return 0;
	}
	else
	{
		return -1;
	}

	return 0;
}

int main()
{
	list lst;
	string swtch;
	int num = 0;

	while (cin >> swtch && swtch != "QUIT")
	{
		switchCheck(swtch, &lst);
	}

	deleteList(&lst);

	return 0;
}