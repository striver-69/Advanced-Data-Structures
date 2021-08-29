#include <vector>
#include <iostream>
using namespace std;

/********   Union-Find Disjoint Set Path Compression Implementation   *****/
class UFDS {
private:
	vector<int> parent;
  int size;
public:
  UFDS(int size){
    this->size=size;
    this->parent.resize(size+1);
  }
	void make_set() {
		for (int i = 0; i < size; i++)
			parent[i] = i;
	}
	int findSet(int v) {
		if(v==parent[v])
      return v;
    return parent[v]=findSet(parent[v]);
	}
	void unionSet(int a, int b) {
		a=findSet(a);
    b=findSet(b);
    if(a!=b)
      parent[b]=a;
  }
};

int main()
{
  //Sample Usage
  UFDS*uf=new UFDS(5);
  uf->make_set();
  uf->unionSet(1,0);
  uf->unionSet(1,2);
  uf->unionSet(1,3);
  uf->unionSet(4,3);  
  for(int i=0;i<5;i++)
  {
    cout<<uf->findSet(i)<<endl;
  }
  return 0;
}


/* 
Sample implementation

UFDS*uf=new UFDS(5);

make_set()
0 1 2 3 4 

unionSet(1,0) ->    1 2 3 4
                    |
                    0

unionSet(1,2) ->    1  3 4
                    | \
                    0  2
                    

unionSet(1,3) ->    1     4
                 /  |  \
                3   0   2                 


unionSet(4,3) ->     4
                   /   \
                  3     1
                      /   \
                     0     2

  
Clearly we can observe that in this naive implementation of find_set 
the time complexity can be O(logn) in average case. 

In the worst case the find_set complexity would be O(n) as we are 
always connecting second tree with first without any optimal 
heuristics.

*/