#include <vector>
#include <iostream>
using namespace std;

/********  Naive Union-Find Disjoint Set Implementation   *****/
class UFDS
{
private:
  vector<int> parent;
  int size;

public:
  UFDS(int size)
  {
    this->size = size;
    this->parent.resize(size + 1);
  }
  void make_set()
  {
    for (int i = 0; i < size; i++)
      parent[i] = i;
  }
  int findSet(int v)
  {
    if (v == parent[v])
      return v;
    return findSet(parent[v]);
  }
  void unionSet(int a, int b)
  {
    a = findSet(a);
    b = findSet(b);
    if (a != b)
      parent[b] = a;
  }
};

int main()
{
  //Sample Usage
  UFDS *uf = new UFDS(5);
  uf->make_set();
  uf->unionSet(1, 2);
  uf->unionSet(3, 4);
  uf->unionSet(1, 3);
  uf->unionSet(0, 1);
  for (int i = 0; i < 5; i++)
  {
    cout << uf->findSet(i) << endl;
  }
  return 0;
}

/* 
Sample implementation

UFDS*uf=new UFDS(5);

make_set()
0 1 2 3 4 

unionSet(1,2) ->    0 1 3 4
                      |
                      2

unionSet(3,4) ->    0 1 3
                      | |
                      2 4

unionSet(1,3) ->    0 1
                     / \
                    2   3
                        |
                        4

unionSet(0,1) ->      0
                      |
                      1
                     / \
                    2   3
                        |
                        4
  
Clearly we can observe that in this naive implementation of find_set 
the time complexity can be O(n) in worst case. 

*/