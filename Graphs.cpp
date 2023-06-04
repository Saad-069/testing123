#include <iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph {

    int numVertices;
    list<int>*adjacencyList;

public:
    Graph(int num) {
        numVertices = num;
        adjacencyList = new list<int>[numVertices];
    }
    void addEdges(int start, int end) {
        adjacencyList[start].push_back(end);
    //    adjacencyList[end].push_back(start);

    }
    void BFS(int startVertex) {
        vector<bool>visited(numVertices, false);
        queue<int>q;
        visited[startVertex] = true;
        q.push(startVertex);
        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            cout << " " << currentVertex << " ";
            for (int surroundings : adjacencyList[currentVertex]) {

                if (!visited[surroundings]) {
                    visited[surroundings] = true;
                    q.push(surroundings);

                }
}
        }
    }


    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i << " is connected to: ";
            for (const auto& neighbor : adjacencyList[i]) {
               cout << neighbor << " ";
            }
            cout << std::endl;
        }
    }


    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        stack<int> st;
        st.push(startVertex);

        while (!st.empty()) {
            int currentVertex = st.top();
            st.pop();

            if (!visited[currentVertex]) {
                visited[currentVertex] = true;
                cout << currentVertex << " ";

                for (int neighbor : adjacencyList[currentVertex]) {
                    if (!visited[neighbor]) {
                        st.push(neighbor);
                    }
                }
            }
        }
    }
};

int main()
{
    Graph g(10);
    g.addEdges(1, 2);
    g.addEdges(1, 4);
    g.addEdges(4, 3);
    g.addEdges(2, 3);
    g.addEdges(3, 10);
    g.addEdges(3, 9);
    g.addEdges(2, 5);
    g.addEdges(2, 8);
    g.addEdges(2,7);
    g.addEdges(5, 8);
    g.addEdges(5, 7);
    g.addEdges(5, 6);
  //  g.printGraph();
  //  g.BFS(1);
    g.DFS(1);
}

