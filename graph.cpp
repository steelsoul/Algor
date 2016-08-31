// Example program
#include <iostream>
#include <string>
#include <vector>

class DenseGraph
{
    int Vcnt, Ecnt;
    bool digraph;
    vector<vector<bool>> adj;
    
    public:
    
    DenseGraph(int V, bool digraph = false): adj(V), Vcnt(V), Ecnt(0), digraph(digraph)
    {
        for (int i = 0; i < V; i++) adj[i].assign(V, false);
    }
};

template typename<T>
class cDFS
{
    int cnt; 
    const Graph &G;
    vector<int> ord;
    
    public:
    
    void searchC(int v)
    {
        ord[v] = cnt++;
        typename Graph::adjIterator A(G, v);
        for (int t = A.begin(); t != A.end(); t = A.nxt())
        {
            if (ord[t] == -1) searchC(t);
        }
    }
    
    cDFS(const Graph& g, int v = 0): cnt(0), G(g), ord(G.V(), -1)
    {
        searchC(v);
    }
    
    int count() const
    {
        return cnt;
    }
    
    int operator[](int v)
    {
        return ord[v];
    }
    
};

int main()
{
  std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello, " << name << "!\n";
}
