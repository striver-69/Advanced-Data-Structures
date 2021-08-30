#include <vector>
#include <iostream>
using namespace std;

/********   Union-Find Disjoint Set Path Compression Implementation along with union by size or rank  *****/
class UFDS
{

private:
  vector<int> parent, Size, Rank;
  int size, numberOfSets;

public:
  UFDS(int size)
  {
    this->numberOfSets = size;
    this->size = size;
    this->parent.resize(size + 1);
    this->Size.resize(size + 1);
    this->Rank.resize(size + 1);
  }

  void make_set()
  {
    for (int i = 0; i < size; i++)
    {
      parent[i] = i;
      Size[i] = 1;
      Rank[i] = 0;
    }
  }

  int findSet(int v)
  {
    if (v == parent[v])
      return v;
    return parent[v] = findSet(parent[v]);
  }

  bool isSameSet(int a, int b)
  {
    return findSet(a) == findSet(b);
  }

  void unionSet(int a, int b)
  {
    a = findSet(a);
    b = findSet(b);
    if (a != b)
    {
      if (Size[a] < Size[b])
        swap(a, b);
      parent[b] = a;
      Size[a] += Size[b];
      if (Rank[a] == Rank[b])
        Rank[a]++;
      numberOfSets--;
    }
  }

  int getSize(int i)
  {
    return Size[findSet(i)];
  }

  int numberOfDisjointSets()
  {
    return numberOfSets;
  }
};

int main()
{
  // Sample Usage
  UFDS *uf = new UFDS(5);
  uf->make_set();
  uf->unionSet(1, 0);
  uf->unionSet(1, 2);
  uf->unionSet(4, 3);
  for (int i = 0; i < 5; i++)
  {
    cout << uf->findSet(i) << endl;
  }
  cout << uf->numberOfDisjointSets() << endl;
  cout << uf->getSize(2) << endl;
  cout << uf->getSize(4) << endl;
  cout << uf->isSameSet(0, 4) << endl;
  return 0;
}

/*** How to use above UFDS class **/

/*
	Here , 'N' is the no. of disjoint sets initially
	UFDS uf(N) : Creates a object of UFDS class having 'N' disjoint sets
	findSet(i) : Return in which set the element 'i' is
  make_set() : Initializes the rank and parent vectors.
	isSameSet(i,j) : Return true if element 'i' and 'j' are of same
					 set else false
	unionSet(i,j) : Return none while makes a union of two seperate set
					of 'i' and 'j'
	setSize(i) : Return the size of set of which 'i' is a part
	numDisjointSets() : Retrun the no. of total disjoint sets at present
*/