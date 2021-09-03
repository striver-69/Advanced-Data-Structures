#include <vector>
#include <iostream>

using namespace std;

class Graph
{
private:
  vector<bool> vis;
  vector<int> path;
  int size;

public:
  vector<vector<int> > adj;
  Graph(int n)
  {
    adj.resize(n);
    vis.resize(n, false);
    path.clear();
    this->size = n;
  }
  //directed graph
  void insertEdge(int a, int b)
  {
    adj[a].push_back(b);
  }
  void printGraph()
  {
    for (int i = 0; i < adj.size(); i++)
    {
      cout << i << " ->";
      for (int j = 0; j < adj[i].size(); j++)
      {
        cout << adj[i][j] << " ";
      }
      cout << endl;
    }
  }
};

class UnionFind
{
private:
  vector<int> rank, parent;

public:
  UnionFind(int n)
  {
    rank.resize(n);
    parent.resize(n);
    for (int i = 0; i < n; i++)
    {
      rank[i] = 1;
      parent[i] = i;
    }
  }

  int find(int x)
  {
    if (x == parent[x])
      return x;
    return parent[x] = find(parent[x]);
  }

  void Union(int node1, int node2)
  {
    int a = find(node1);
    int b = find(node2);
    if (rank[a] > rank[b])
      parent[b] = a;
    else if (rank[b] > rank[a])
      parent[a] = b;
    else
    {
      parent[b] = a;
      rank[a]++;
    }
  }

  bool same(int x, int y)
  {
    return find(x) == find(y);
  }

  bool Cycle(Graph g)
  {
    bool flag = false;
    vector<vector<int> > adj = g.adj;
    for (int i = 0; i < adj.size(); i++)
    {
      for (int j = 0; j < adj[i].size(); j++)
      {
        if (same(i, adj[i][j]))
          return true;
        Union(i, adj[i][j]);
      }
    }
    return false;
  }
};

int main()
{
  Graph g(6);
  g.insertEdge(0, 1);
  g.insertEdge(1, 2);
  g.insertEdge(2, 3);
  g.insertEdge(3, 4);
  // g.insertEdge(4, 2);
  g.insertEdge(5, 4);
  g.printGraph();
  UnionFind uf(6);
  cout << uf.Cycle(g);
  return 0;
}