#include<iostream>
using namespace std;

class unionFind
{
   private:
	int a[100];
	int size;
   int parent(int x)
   {
	if(a[x]==x)
	   return x;
	else
	   return parent(a[x]);
   }
   public:
   unionFind(int n)
   {
	for(int i=0;i<n;i++)
	  a[i] = i;
	size = n;
   }
   bool find(int x, int y)
   {
	return parent(x)==parent(y);
   }
   void unite(int x, int y)
   {
	int p = parent(x), q=parent(y);
	a[p] = q;
   }
   void print()
   {
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<endl;
   }
};

int main()
{
	unionFind A(6);
	A.unite(0,1);
	A.print();
	A.unite(4,2);
	A.unite(1,2);
	A.print();
	A.unite(3,5);
	cout<<A.find(1,5)<<endl;
	cout<<A.find(3,5)<<endl;
}
