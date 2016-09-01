// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Edge {
	int v,w;
	Edge(int v = -1, int w = -1) : v(v), w(w) {}
};

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
	
	int V() const { return Vcnt; }
	int E() const { return Ecnt; }
	
	bool directed() const { return digraph; }
	
	void insert(Edge e)
	{
		int v = e.v, w = e.w;
		if (!adj[v][w]) Ecnt++;
		adj[v][w] = true;
		if (!digraph) adj[w][v] = true;
	}
	
	void remove(Edge e)
	{
		int v = e.v, w = e.w;
		if (adj[v][w]) Ecnt--;
		adj[v][w] = false;
		if (digraph) adj[w][v] = false;
	}
	
	bool edge(int v, int w) const
	{
		return adj[v][w];
	}
	class adjIterator;
	friend class adjIterator;
 };
 
 class DenseGraph::adjIterator
 {
	 const DenseGraph& G;
	 int i, v;
	 
	 public:
	 adjIterator(const DenseGraph& G, int v): G(G), i(-1) ,v(v)
	 {
	 }
	 
	 int beg() { i = -1; return nxt(); }
	 int nxt() 
	 {
		 for (i++; i < G.V(); i++)
			 if (G.adj[v][i]) return i;
		 return -1;
	 }
	 bool end()
	 {
		return i >= G.V(); 
	 }
 };

typedef DenseGraph Graph;
 
//template typename<T>
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
        for (int t = A.beg(); t != A.end(); t = A.nxt())
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

}
