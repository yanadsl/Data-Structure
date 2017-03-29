#include <stdio.h> //printf, scanf, NULL
#include <stdlib.h>//malloc, free
#include <iostream>

using namespace std;

class node
{
public:
	int key;
	class node *left=NULL, *right=NULL, *parent=NULL;
	void Delete(node *);
	void Insert(node *, node *);
	void Inorder(node *);
	void Preorder(node *);
	class node *root = NULL;
};

typedef class node Node;
node *Search(Node *, int);
/////////////////
Node *Search(Node, int);

node *Search(Node *x, int k){
	while(x != NULL){
		if(k == x->key)
			return x;
		else if(k < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return NULL ;
}

void node::Delete(Node *x){
	Node* tmp=NULL;

	if (x->right == NULL){
		if(x->left == NULL){// left&right = NULL
			if(x == this->root)
				this->root = NULL;
			else
				x->parent->left == x ? x->parent->left=NULL : x->parent->right = NULL;
			return;
		}
		else{// right = NULL
		}
	}
	else{// left = NULL
		if(x->left == NULL){
			if(x != this->root)
				x->parent->left == x ? x->parent->left = x->right : x->parent->right = x->right;
			x->right->parent = x->parent;
			return ;
		}
		else{ //2 leaves
			//find_successor
			tmp = x->right;
			while(tmp->left != NULL) tmp = tmp->left;
			//pick it up
			tmp->parent->left == tmp ? tmp->parent->left = tmp->right : tmp->parent->right = tmp->right;
			if (tmp->right!=NULL)
				tmp->right->parent = tmp->parent;
			//copy x's pointer
			tmp->left = x->left;
			tmp->right = x->right;
			tmp->parent = x->parent;
			//change leaves 'n parents
			if (tmp->left!=NULL)
				tmp->left->parent = tmp;
			if (tmp->right!=NULL)
				tmp->right->parent = tmp;
			if(x == this->root){ //root has no parent
				this->root = tmp;
				return;
			}
			else
				tmp->parent->left == x ? tmp->parent->left = tmp : tmp->parent->right = tmp;
		}	
	}
}
void node::Insert(Node *x, Node *z){	
	if(x == NULL){
		this->root = z;
		return ;
	}	
	while(1){
		if(z->key == x->key){
			cout << "error:" <<z->key << " already exist\n";
			return ;
		}
			
		if(z->key < x->key)
			if(x->left == NULL){
				x->left = z;
				x->left->parent = x;
				return ;
			}
			else
				x=x->left;
		else
			if(x->right == NULL){
				x->right = z;
				x->right->parent = x;
				return ;
			}
			else
				x=x->right;
	}
}
void node::Inorder(Node *x){
	if(x == NULL)
		return;
	Inorder(x->left);
	cout << x->key << " ";
	Inorder(x->right);
	return;
}
void node::Preorder(Node *x){
	if(x == NULL)
		return;
	cout << x->key << " ";
	Preorder(x->left);
	Preorder(x->right);
	return;
}
/////////////////
int main()
{
	char m = 'q';
	int a, b,c;
	Node n; 
	Node *new_node, *to_be_deleted;
	while (m != 'e')
	{
		cin >> m;
		while (m == 'a')
		{

			new_node = (Node *)malloc(sizeof(Node));
			new_node->left = new_node->right = NULL;

			cin >> a;
			new_node->key = a;

			if (a == -1)
				break;
			else
				n.Insert(n.root, new_node);
		}
		while (m == 'b')
		{

			cin >> b;
			if (b == -1)
				break;
			else
			{
				to_be_deleted = Search(n.root, b);
				if (to_be_deleted)
				{
					n.Delete(to_be_deleted);
					free(to_be_deleted);

				}
			}


		}
		while (m == 'c')
		{
		
			cin >> c;
			
			if (c == -1)
				break;
			else
			{
				
				if(Search(n.root,c))
					cout << c << " is in the tree" << endl;
				else
					cout << c << " is not in the tree" << endl;
			}
			
		}

	}

	printf("Inorder: "); n.Inorder(n.root); printf("\n");
	printf("Preorder: "); n.Preorder(n.root); printf("\n");



	system("pause");
	return 0;

}