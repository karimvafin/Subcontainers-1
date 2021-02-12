#include <iostream>
using namespace std;

struct subforwardlist
{
	int data;
	subforwardlist* next;
};

bool init(subforwardlist** sfl)///////////////////////////working
{
	*sfl = NULL;
	return true;
}

unsigned int size(subforwardlist** sfl)/////////////////////////working
{
	unsigned int size = 0;
	while (*sfl != NULL)
	{
		sfl = &((*sfl)->next);
		size++;
	}
	return size;
}

bool push_back(subforwardlist** sfl, int d)//////////////////////////working
{
	subforwardlist* tmp = new subforwardlist;
	tmp->data = d;
	tmp->next = NULL;
	subforwardlist* tmp1 = *sfl;
	while (*sfl != NULL)
	{
		sfl = &((*sfl)->next);
	}
	*sfl = tmp;
	return true;
}

int pop_back(subforwardlist** sfl)////////////////////working
{
    if (size(sfl) == 0) return false;
	int i = 0;
	subforwardlist** tmp1 = sfl;
	while ((*sfl) ->next != NULL)
	{
		sfl = &((*sfl)->next);
		i++;
	}
    int e = (*sfl)->data;
	delete *sfl;
	*sfl= NULL;
	return e;
}

bool push_forward(subforwardlist** sfl, int d)/////////////////////working
{
	subforwardlist* tmp = new subforwardlist;
	tmp->next = (*sfl);
	tmp->data = d;
	*sfl = tmp;
	return true;
}

int pop_forward(subforwardlist** sfl)///////////////////////working
{
    if (size(sfl) == 0) return false;
	subforwardlist* tmp = (*sfl)->next;
	int e = (*sfl)->data;
	delete *sfl;
	*sfl = tmp;
	return e;
}

bool push_where(subforwardlist** sfl, unsigned int where, int d)////////////////////working
{
    if (where > size(sfl)+1) return false;

	subforwardlist* tmp = new subforwardlist;
	tmp->data = d;
	for (int i = 2; i < where; i++)
	{
		sfl = &((*sfl)->next);
	}
	tmp->next = (*sfl)->next;
	(*sfl)->next = tmp;
	return true;
}

bool erase_where(subforwardlist** sfl, unsigned int where)//////////////////////working
{
	for (int i = 2; i < where; i++)
	{
		sfl = &((*sfl)->next);
	}
	subforwardlist* tmp = (*sfl)->next->next;
	delete (*sfl)->next;
	(*sfl)->next = tmp;
	return true;
}

void clear(subforwardlist** sfl) ////////////////////////working
{
	if (*sfl == NULL) return;
	clear(&((*sfl)->next));
	delete *sfl;
	*sfl = NULL;
	return;
}

void print(subforwardlist* sfl) ////////////////////////////working
{
	while (sfl != NULL)
	{
		cout << sfl->data << " ";
		sfl = (sfl)->next;
	}
	cout << endl;
	return;
}


int main()
{
	subforwardlist* start;
	init(&start);

	push_back(&start, 1);
	push_back(&start, 3);
	push_back(&start, 6);
	push_back(&start, 0);
	push_back(&start, 8);
	push_back(&start, 78);
	push_back(&start, 9);
	cout << size(&start) << endl;
	print(start);
	cout << endl;

	pop_back(&start);
	cout << size(&start) << endl;
	print(start);
	cout << endl;

	pop_forward(&start);
	cout << size(&start) << endl;
	print(start);
	cout << endl;

	push_forward(&start,2);
	cout << size(&start) << endl;
	print(start);
	cout << endl;

	push_where(&start, 3, 5000);
	cout << size(&start) << endl;
	print(start);
	cout << endl;

	erase_where(&start, 3);
	cout << size(&start) << endl;
	print(start);
	cout << endl;

    clear(&start);
    cout << size(&start) << endl;
	print(start);
	return 0;
}
