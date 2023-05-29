#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
private:
   int numNodes;
   vector<vector<int>> adjList;
   vector<bool> visited;

public:
   Graph(int nodes) : numNodes(nodes), adjList(nodes), visited(nodes, false) {}

   void addEdge(int u, int v)
   {
      adjList[u].push_back(v);
      adjList[v].push_back(u);
   }

   void DFS(int startNode)
   {
      visited[startNode] = true;
      cout << startNode << " ";

      for (int neighbor : adjList[startNode])
      {
         if (!visited[neighbor])
         {
            DFS(neighbor);
         }
      }
   }

   void BFS(int startNode)
   {
      visited[startNode] = true;
      queue<int> q;
      q.push(startNode);

      while (!q.empty())
      {
         int node = q.front();
         q.pop();
         cout << node << " ";

         for (int neighbor : adjList[node])
         {
            if (!visited[neighbor])
            {
               visited[neighbor] = true;
               q.push(neighbor);
            }
         }
      }
   }
};

int main()
{
   int numNodes, numEdges;
   int u, v;
   int startNode;
   char choice;

   cout << "Enter the number of nodes: ";
   cin >> numNodes;

   Graph graph(numNodes);

   cout << "Enter the number of edges: ";
   cin >> numEdges;

   cout << "Enter the edges (u v):\n";
   for (int i = 0; i < numEdges; i++)
   {
      cin >> u >> v;
      graph.addEdge(u, v);
   }

   cout << "Enter the starting node: ";
   cin >> startNode;

   cout << "Enter 'D' for Depth First Search (DFS) or 'B' for Breadth First Search (BFS): ";
   cin >> choice;

   cout << "Traversal: ";
   if (choice == 'D' || choice == 'd')
   {
      graph.DFS(startNode);
   }
   else if (choice == 'B' || choice == 'b')
   {
      graph.BFS(startNode);
   }
   else
   {
      cout << "Invalid choice!" << endl;
   }

   cout << endl;

   return 0;
}
