#include<iostream>
#include<list>
#include<stack>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void DFS(int v, bool visited[], stack<int> &Stack);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFS(int v, bool visited[], stack<int> &Stack){
    
    visited[v]=true;

    list<int>::iterator it;
    for(it=adj[v].begin(); it != adj[v].end(); it++){
        if(!visited[*it]){
            DFS(*it, visited, Stack);
        }
    }
    Stack.push(v);
}

void Graph::topologicalSort()
{
    stack<int> Stack;

    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i]=false;
    
    for(int i=0; i<V; i++){
        if(!visited[i]){
            DFS(i, visited, Stack);
        }
    }

    while(Stack.empty() == false){
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(6);                    // Graph contains 8 nodes
    g.addEdge(0, 3);               // Project 2 depends on 5
    g.addEdge(5, 1);               // Project 0 depends on 5
    g.addEdge(1, 3);               // Project 0 depends on 4
    g.addEdge(5, 0);               // Project 1 depends on 4
    g.addEdge(3, 2);               // Project 3 depends on 2

    cout << "Following is a Topological Sort (build order) of the given graph \n";
    g.topologicalSort();

    return 0;
}