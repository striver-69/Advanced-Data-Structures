#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

class Graph
{
private:
  vector<vector<int> > adj;
  int timer;
  vector<bool> vis;
  vector<int> path;

public:
  Graph(int n)
  {
    adj.resize(n);
    vis.resize(n, false);
    path.clear();
    this->timer = 0;
  }
  void insertEdge(int a, int b)
  {
    adj[a].push_back(b);
    adj[b].push_back(a);
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

  void dfs(int u)
  {
    vis[u] = true;
    path.push_back(u);
    for (int i = 0; i < adj[u].size(); i++)
    {
      int v = adj[u][i];
      if (!vis[v])
        dfs(v);
    }
  }
  void printDFS()
  {
    for (int i = 0; i < path.size(); i++)
    {
      cout << path[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  Graph *g = new Graph(5);
  g->insertEdge(0, 1);
  g->insertEdge(1, 2);
  g->insertEdge(2, 3);
  g->insertEdge(3, 4);
  g->printGraph();
  g->dfs(3);
  g->printDFS();
  return 0;
}