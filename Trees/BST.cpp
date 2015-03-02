#include<iostream>
using namespace std;

struct node
{
   int val;
   node* left;
   node* right;
   node* parent;
};
class BST
{
   node* root;
   int number;
   node* newNode(int x)
   {
	node* temp = new node;
	temp->val = x;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
	return temp;
   }
   public:
   BST()
   {
	root = NULL;
	number = 0;
   }
   void insert(int x)
   {
	node* n = newNode(x);
	node* temp = root;
	node* tempP = NULL;
	if(root==NULL)
	  root = n;
	else
	{
	  while(temp!=NULL)
	  {
	     tempP = temp;
	     if(n->val > temp->val)
		temp = temp->right;
	     else
		temp = temp->left;
	  }
	  if(tempP->val >= n->val)
	  {
	     tempP->left = n;
	     n->parent = tempP;
	  }
	  else
	  {
	     tempP->right = n;
	     n->parent = tempP;
	  }
 	}
   }
   node* search(int val)
   {
	node* temp = root;
	while(temp!=NULL && temp->val!=val)
	{
	   if(temp->val > val)
	      temp = temp->left;
	   else
	      temp = temp->left;
	}
	return temp;
   }
   node* deleteNode(int v)
   {
	node* temp = search(v);
	if(temp==NULL)
	  return NULL;

        else if(temp->left==NULL && temp->right==NULL)
	{
    	   cout<<"Dodod";
	   if(temp->parent->left==temp)
		temp->parent->left = NULL;
	   else
		temp->parent->right=NULL;
	   temp->parent = NULL;
	   return temp;
	}
	else if(temp->left==NULL && temp->right!=NULL)
	{
	   (temp->parent)->right = temp->right;
	   temp->right->parent = temp->parent;
	   temp->right = NULL;
	   temp->parent = NULL;
	   return temp;
	}
	else if(temp->right==NULL && temp->left!=NULL)
	{
	   (temp->parent)->left = temp->left;
           temp->left->parent = temp->parent;
	   temp->left = NULL;
	   temp->parent = NULL;
	   return temp;
	}
	else
	{
	   node* t = temp->right;
	   while(t->left!=NULL)
	      t=t->left;

	   temp->val = t->val;
	   t->val = v;

	   if(t->parent == temp)
		t->parent->right = t->right;
	   else
	   	t->parent->left = t->right;

	   if(t->right!=NULL)
		   t->right->parent = t->parent;
	   t->parent = NULL;
	   return t;
	}
   }
   void print(node* a)
   {
	if(a!=NULL)
	{
	   cout<<a->val<<endl;
	   print(a->left);
	   print(a->right);
	}
   }
   node* getRoot()
   {
	return root;
   }
};

int main()
{
	BST A;
	A.insert(3);
	A.insert(4);
	A.insert(2);
	A.insert(0);
	A.insert(1);
	A.insert(-1);
	node *tp = A.search(-1); 
	A.deleteNode(0);
	A.print(A.getRoot());
}
