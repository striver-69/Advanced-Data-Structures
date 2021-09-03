#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

class Graph
{
private:
  vector<vector<int> > adj;
  int size;
  int timer;
  vector<bool> vis;
  vector<int> low, tin;
  void print_bridge(int a, int b)
  {
    cout << a << " " << b << endl;
  }

public:
  Graph(int n)
  {
    this->size = n;
    adj.resize(n);
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

  void dfs(int u, int p = -1)
  {
    vis[u] = true;
    low[u] = tin[u] = timer++;
    for (int i = 0; i < adj[u].size(); i++)
    {
      int to = adj[u][i];
      if (to == p)
        continue;
      if (vis[to])
      {
        low[u] = min(low[u], tin[to]);
      }
      else
      {
        dfs(to, u);
        low[u] = min(low[u], low[to]);
        if (low[to] > low[u])
        {
          print_bridge(u, to);
        }
      }
    }
  }

  void find_bridges()
  {
    this->timer = 0;
    vis.resize(size, false);
    tin.assign(size, -1);
    low.assign(size, -1);
    for (int i = 0; i < size; i++)
    {
      if (!vis[i])
        dfs(i);
    }
  }
};

int main()
{
  Graph *g = new Graph(5);
  g->insertEdge(0, 1);
  g->insertEdge(1, 2);
  g->insertEdge(2, 3);
  g->insertEdge(3, 4);
  g->insertEdge(4,2);
  g->printGraph();
  g->find_bridges();
  return 0;
}