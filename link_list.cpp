#include <stdio.h> //printf, scanf, NULL
#include <stdlib.h>//malloc, free
#include <iostream>
using namespace std;

class node
{
	public:
		int key;
		class node *next=NULL;
};

typedef class node  Node; //define Node = struct node

void Insert(int);

Node *Delete(int);

void Print();

void Swap(int, int);//a<b

void Reverse();

Node *Head = NULL, *current;

int main()
{
    Node *x;
    int i=0,j=0;
    char w;
    

		while(w!='e')
		{
			cin>>w;		
				
			while( w=='i')	//	insert
			{
				cin>>i;
				if (i==0)//0=end
				{
					break;
				}		
				Insert(i);			
			}
			while(w=='d')	//	delete
			{
				cin>>i;
				if (i==0)//0=end
				{
					break;
				}
					
				x=Delete(i);
				
				if(x!=NULL)
				{
					free(x);
				}			
			}
			while(w=='r')	//	reverse
			{
				Reverse();
				break;
			}
			while(w=='s')	//	swap
			{
				cin>>i>>j;
				Swap(i,j);
				break;
			}				
	
	}
	Print();
    return 0;
}

void Insert(int k)
{
    Node* tmp=Head;
	if(Head == NULL){
		Head = new Node;
		Head->key = k;
		current = Head;
	}
	else{
        for(current = Head; current != NULL; current = current->next){
            if(current->key > k){
                if(current == Head){
                    tmp = new Node;
                    tmp->key = k;
                    tmp->next = current;
                    Head = tmp;
                }
                else{
                	tmp->next = new Node;
		            tmp->next->key = k;
		            tmp->next->next = current;
                }
                return ;
            }
            tmp = current;
        }
        tmp->next = new Node;
        tmp->next->key = k;
        tmp->next->next = current;
	}
	return;
}

Node *Delete(int k)
{
    Node* tmp;
    if(Head->key == k){
        tmp = Head;
        Head = Head->next;
        return tmp;
    }
	for(current = Head; current->next != NULL; current = current->next)
		if(current->next->key == k){
            tmp = current->next;
            current->next = current->next->next;
            return tmp;
		}
    return NULL;
}

void Print()
{
	for(current = Head; current != NULL; current = current->next)
		cout << current->key << " ";
    return;
}


void Swap(int a, int b)
{
	for(current = Head;current->key != a&&current->key != b; current = current->next);
	current->key == b ? current->key = a : current->key = b;
	for(current = current->next;current->key != a&& current->key != b; current = current->next);
	current->key == a ? current->key = b : current->key = a;
    return;
}

void Reverse()
{
	Node* tmp = NULL;
	for(current = Head; current-> next != NULL ;current = Head){
		Head = Head->next ;
		current->next = tmp;
		tmp = current;
	}
	Head->next = tmp;
	return;
}