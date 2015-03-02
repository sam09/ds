#include<bits/stdc++.h>
using namespace std;
struct BTreeNode
{
  int n;
  int *key;
  BTreeNode **c;
  bool isLeaf;
};
struct searchKey
{
  BTreeNode *x;
  int pos;
};
BTreeNode* allocateNode(int t)
{
  BTreeNode *tp = new BTreeNode;
  tp->isLeaf = true;
  tp->n = 0;
  tp->key = new int[2*t -1];
  tp->c = new BTreeNode*[2*t];
  for(int i=0; i< (2*t-1); i++)
  {
     tp->key[i] = INT_MAX;
     tp->c[i] = NULL;
  }
  tp->c[2*t-1] = NULL;
  return tp;
}
class BTree
{
    private:
	int order;
        BTreeNode *root;
    public:
	BTree(int x)
	{
	    order = x;
	    root = allocateNode(x);
	    cout<<order<<endl;
	}
	//a method to search the entire tree;
	searchKey* search(int k)
	{
	    int i=0;
	    BTreeNode *x = root;
	    while(1)
	    {
	      while(i <= x->n && k > x->key[i])
		i++;
	      if(i <= x->n && k == x->key[i])
	      {
		searchKey *tp = new searchKey;
		tp->x = x;
		tp->pos = i;
		return tp;
	      }
	      else if(x->isLeaf)
		return NULL;
	      else
		x = x->c[i];
	    }
	}
        void insert(int k)
	{
            BTreeNode *x = root;
	    int i=0;
	    bool done = false;
	    while(!done)
	    {
	      if(x->isLeaf)
              {
		  i=0;
                  while(i < x->n && k > x->key[i])
                     i++;
                  if(i< x->n  && k < x-> key[i] && x->n != (2*order-1))
	          {
		     x->n+=1;
		     int j=x->n;
		     while( j > i)
		     {
		        x->key[j] = x->key[j-1];
		        j--;
		     }
		     x->key[i] = k;
		     done = true;
	          }
	          else if(i >= x->n && i < (2*order-1))
	          {
	  	     x->n+=1;
	             x->key[i] = k;
		     done = true;
	          }
		  else
		  {
		     BTreeNode *tp = allocateNode(order);
	             x->c[i] = tp;
		     x->isLeaf = false;
		     tp->key[0] = k;
		     tp->n+=1;
		     done = true;
		  }
              }
              else
	      {
		  i=0; 
	          while(i < x->n && k > x->key[i])
                      i++;
	          if( i <= x->n && x->c[i]!=NULL)
		     x = x->c[i];
                  else if(x->c[i]==NULL)
		  {
		     BTreeNode *tp = allocateNode(order);
                     x->c[i] = tp;
                     tp->key[0] = k;
                     tp->n+=1;
                     done = true;
		  }
	      }
	   }
	}
	void print(BTreeNode *y)
	{
	   int i;
	   if(y!=NULL)
           {
	      for(i=0;i<y->n;i++)
		cout<<y->key[i]<<" ";
	      cout<<endl;
	      for(i=0;i<=y->n;i++)
		print(y->c[i]);
	   }
	}
	BTreeNode* getRoot()
	{
	   return root;
	}
};
int main()
{
   BTree A(2);
   A.insert(-9);
   A.insert(-4);
   A.insert(1);
   A.insert(-14);
   A.insert(-10);
   A.insert(-8);
   A.insert(11);
   A.insert(0);
   A.insert(-15);
   A.insert(98);
   A.insert(110);
   A.insert(49);
   //cout<<((A.getRoot()->c[3]==NULL)?-1:A.getRoot()->c[3]->key[0]);
   //searchKey *b = A.search(11);
   //cout<<b->pos;
   A.print(A.getRoot());
}
