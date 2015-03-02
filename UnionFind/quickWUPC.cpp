#include<iostream>
using namespace std;

class unionFind
{
   private:
	int a[100];
	int size;
	int sz[100];
   int parent(int x)
   {
	int i=x;
	while(a[i]!=i)
	  i=a[i];
	if(a[x]!=i)
	a[x] = i;
	return i;
   }
   public:
   unionFind(int n)
   {
	for(int i=0;i<n;i++)
	{
	  a[i] = i;
	  sz[i]=1;
	}
	size = n;
   }
   bool find(int x, int y)
   {
	return parent(x)==parent(y);
   }
   void unite(int x, int y)
   {
	int p = parent(x), q=parent(y);
	if(sz[p] < sz[q])
	{
	   a[p] = q;
	   sz[q] +=sz[p];
	}
	else
	{
	   a[q] = p;
	   sz[p] +=sz[q];
	}
   }
   void print()
   {
	for(int i=0;i<size;i++)
		cout<<i<<" "<<a[i]<<" "<<sz[i]<<endl;
   }
};
int main()
{
	unionFind A(6);
	A.unite(0,1);
	A.unite(4,2);
	A.unite(1,2);
	A.unite(3,5);
	A.print();
	cout<<A.find(2,5)<<endl;
	cout<<A.find(3,5)<<endl;
	A.print();
}

