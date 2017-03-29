#include <stdlib.h>//malloc, free
#include <iostream>

using namespace std;

class node
{
public:
	void push_front(int);
	void push_back(int);
	void pop_back();
	void pop_front();
	void Print();
	int key;
	class node *next=NULL;
	int num=0;
	int Deque_size;
};
typedef class node  Node; //define Node = struct node
Node *Head = NULL, *current = NULL, *last = NULL;

void node::Print()
{
    if(Head == NULL)
        cout <<"the list is empty.";
	for(current = Head; current != NULL; current = current->next)
		cout << current->key << " ";

}

void node::pop_front()
{
	num--;
	if(Head==last){
		delete Head;
		Head =NULL;
		return;
	}
	current=Head;
	Head=Head->next;
	delete current;

}

void node::pop_back()
{
	num--;
	if(Head==last){
		delete Head;
		Head =NULL;
		return;
	}
	for(current=Head;current->next!=last;current=current->next);
	delete last;
	last =current;
	last->next= NULL;

}

void node::push_front(int k)
{
	num++;
	if(Head == NULL){
		Head = new Node;
		Head->key = k;
		last = Head;
		return;
	}
	if(num>Deque_size)
		pop_back();
	current=new Node;
	current->key=k;
	current->next=Head;
	Head=current;
}

void node::push_back(int k)
{
	num++;
	if(Head == NULL){
		Head = new Node;
		Head->key = k;
		last = Head;
		return;
	}
	if(num>Deque_size)
		pop_front();
	last->next=new Node;
	last->next->key=k;
	last=last->next;
}

int main()
{
	node n;
	char y;
	char w = 'z';
	int i;
	//printf("Deque size:");
	cin >> n.Deque_size;
	while (w != 'e')
	{
		cin >> w;

		while (w == 'a')	//	push_front
		{
			cin >> i;
			n.push_front(i);
			//cout << "是否繼續輸入數字?" << endl;
			cin >> y;
			if (y == 'n')
			{

				break;
			}

		}
		while (w == 'b')	//	push_back
		{
			cin >> i;
			n.push_back(i);
			//cout << "是否繼續輸入數字?" << endl;
			cin >> y;
			if (y == 'n')
			{

				break;
			}


		}
		while (w == 'c')	//	pop_front
		{
			n.pop_front();
			//cout << "是否繼續?" << endl;
			cin >> y;
			if (y == 'n')
			{

				break;
			}
		}
		while (w == 'd')	//	pop_back
		{
			n.pop_back();
			//cout << "是否繼續?" << endl;
			cin >> y;
			if (y == 'n')
			{

				break;
			}
		}

	}

	n.Print();
	system("pause");
	return 0;

}