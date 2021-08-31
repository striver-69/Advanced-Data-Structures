#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

class Graph
{
private:
  vector<vector<int> > adj;
  //BFS
  queue<int> Q;
  vector<bool> vis;
  vector<int> dis, par;

public:
  Graph(int n)
  {
    adj.resize(n);
    vis.resize(n);
    par.resize(n);
    dis.resize(n);
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

  void BFS(int s)
  {
    Q.push(s);
    vis[s] = true;
    par[s] = -1;
    while (!Q.empty())
    {
      int v = Q.front();
      Q.pop();
      for (int i = 0; i < adj[v].size(); i++)
      {
        int u = adj[v][i];
        if (!vis[u])
        {
          vis[u] = true;
          Q.push(u);
          dis[u] = dis[v] + 1;
          par[u] = v;
        }
      }
    }
  }
  void displayShortestPath(int u)
  {
    vector<int> path;
    for (int v = u; v != -1; v = par[v])
      path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "Path :";
    for (int i = 0; i < path.size(); i++)
    {
      cout << path[i] << " ";
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
  g->printGraph();
  g->BFS(3);
  g->displayShortestPath(0);
  return 0;
}