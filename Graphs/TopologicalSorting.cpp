#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

class Graph
{
private:
  vector<vector<int> > adj;
  vector<bool> vis;
  vector<int> path;
  int size;

public:
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
  void dfs(int i)
  {
    vis[i] = true;
    for (int j = 0; j < adj[i].size(); j++)
    {
      int v = adj[i][j];
      if (!vis[v])
        dfs(v);
    }
    path.push_back(i);
  }

  void topologicalSorting()
  {
    vis.resize(size, false);
    path.clear();
    for (int i = 0; i < size; i++)
    {
      if (!vis[i])
        dfs(i);
    }
    reverse(path.begin(), path.end());
  }

  void printTopological()
  {
    for (int i = 0; i < size; i++)
      cout << path[i] << " -> ";
  }
};

int main()
{
  Graph *g = new Graph(6);
  g->insertEdge(5, 0);
  g->insertEdge(5, 2);
  g->insertEdge(4, 0);
  g->insertEdge(4, 1);
  g->insertEdge(2, 3);
  g->insertEdge(3, 1);
  // g->printGraph();
  g->topologicalSorting();
  g->printTopological();
  return 0;
}