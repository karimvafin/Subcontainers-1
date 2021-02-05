#include <iostream>
using namespace std;

struct subforwardlist
{
	int data;
	subforwardlist* next;
};

bool init(subforwardlist** sfl)
{
	*sfl = NULL;
	return true;
}

bool push_back(subforwardlist** sfl, int d)
{
	subforwardlist* tmp = new subforwardlist;
	tmp->data = d;
	subforwardlist* tmp1 = *sfl;
	while (*sfl != NULL)
	{
		*sfl = (*sfl)->next;
	}
	if (*sfl == tmp1) cout << "warning" << endl;
	*sfl = tmp;
	(*sfl)->next = NULL;
	return true;
}

int pop_back(subforwardlist** sfl)
{
	int i = 0;
	while ((*sfl)->next != NULL)
	{
		*sfl = (*sfl)->next;
		i++;
	}
	cout << i << endl;
	int e = (*sfl)->data;
	delete *sfl;
	*sfl = NULL;
	return e;
}

bool push_forward(subforwardlist** sfl, int d)
{
	subforwardlist* tmp = new subforwardlist;
	tmp->next = (*sfl);
	tmp->data = d;
	*sfl = tmp;
	return true;
}

int pop_forward(subforwardlist** sfl)
{
	subforwardlist* tmp = (*sfl)->next;
	int e = (*sfl)->data;
	delete *sfl;
	*sfl = tmp;
	return e;
}

bool push_where(subforwardlist** sfl, unsigned int where, int d)
{
	subforwardlist* tmp = new subforwardlist;
	tmp->data = d;
	for (int i = 1; i < where; i++)
	{
		(*sfl) = (*sfl)->next;
	}
	tmp->next = (*sfl)->next;
	*sfl = tmp;
	return true;
}

bool erase_where(subforwardlist** sfl, unsigned int where)
{
	for (int i = 1; i < where; i++)
	{
		(*sfl) = (*sfl)->next;
	}
	subforwardlist* tmp = (*sfl)->next->next;
	delete (*sfl)->next;
	(*sfl)->next = tmp;
	return true;
}

unsigned int size(subforwardlist* sfl)
{
	unsigned int size = 0;
	while (sfl != NULL)
	{
		sfl = (sfl)->next;
		size++;
	}
	return size;
}

void clear(subforwardlist** sfl)
{
	if (*sfl == NULL) return;
	clear(&((*sfl)->next));
	delete *sfl;
	*sfl = NULL;
	return;
}

void print(subforwardlist* sfl)
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
	cout << size(start) << endl;
	print(start);
	cout << endl;
	push_forward(&start, 5);
	cout << size(start) << endl;
	print(start);
	cout << endl;
	push_forward(&start, 2);
	cout << size(start) << endl;
	print(start);
	cout << endl;
	cout <<pop_back(&start)<<endl;
	cout << size(start) << endl;
	print(start);
	
	return 0;
}

