#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;
int n;
vector<vector<int>> dist;

struct State
{
   int cost;
   int city;
   vector<int> path;

   bool operator<(const State &other) const
   {
      return cost > other.cost;
   }
};

int heuristic(vector<bool> &visited, int city)
{
   int min_dist = INF;
   for (int i = 0; i < n; i++)
   {
      if (!visited[i])
      {
         min_dist = min(min_dist, dist[city][i]);
      }
   }
   return min_dist;
}

int tsp_a_star(int start_city, vector<int> &path)
{
   priority_queue<State> pq;
   pq.push({0, start_city, {start_city}});
   while (!pq.empty())
   {
      State cur = pq.top();
      pq.pop();
      if (cur.path.size() == n)
      {
         path = cur.path;
         path.push_back(start_city);
         return cur.cost + dist[cur.city][start_city];
      }
      vector<bool> visited(n);
      for (int c : cur.path)
      {
         visited[c] = true;
      }
      for (int i = 0; i < n; i++)
      {
         if (!visited[i])
         {
            int h = heuristic(visited, i);
            int new_cost = cur.cost + dist[cur.city][i] + h;
            vector<int> new_path = cur.path;
            new_path.push_back(i);
            pq.push({new_cost, i, new_path});
         }
      }
   }
   return -1;
}

void print_path(const vector<int> &path)
{
   for (int i = 0; i < path.size(); i++)
   {
      cout << path[i] + 1;
      if (i != (path.size() - 1))
         cout << " -> ";
   }
   cout << endl;
}
int main()
{
   cout << "Enter the number of cities: ";
   cin >> n;
   cout << "\nEnter the distance matrix:" << endl;
   dist.resize(n, vector<int>(n));

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cout << "Enter value for row " << i + 1 << ", column" << j + 1 << ": ";
         cin >> dist[i][j];
      }
   }

   cout << "    ";

   for (int i = 0; i < 1; i++)
   {
      cout << "  C" << i + 1;
   }
   for (int i = 1; i < n; i++)
   {
      cout << "    C" << i + 1;
   }
   cout << endl;

   for (int i = 0; i < n; i++)
   {
      cout << "C" << i + 1;
      for (int j = 0; j < n; j++)
      {
         cout << "    " << dist[i][j];
      }
      cout << endl;
   }

   int start_city = 0;
   vector<int> path;
   int ans = tsp_a_star(start_city, path);
   cout << "\nShortest path vertices: ";
   print_path(path);
   cout << "Shortest path length: " << ans << endl;
   return 0;
}

// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0
