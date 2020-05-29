#include<bits/stdc++.h>

using namespace std;


class Graph{

public:
    int V;
    vector <int> *graph ;
Graph(int n){
    V=n;
    graph=new vector <int> [2*V];
}
void addEdge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
    cout<<"working"<<endl;
}

void printGraph(){
    for(int i=0;i<V;i++){
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j];
        }
        cout<<endl;
    }
}
vector <int> adjVer(int val){
    vector <int> adj;
            for (int j = 0; j < graph[val].size(); j++){
            cout << graph[val][j] << ' ';
        }
        return adj;


}
void adjVertex(int val){
        for (int j = 0; j < graph[val].size(); j++){
            cout << graph[val][j] << ' ';
        }
        cout << endl;
}

bool checkConnection(int src, int dest,int pred[], int dist[])
{
	// a queue to maintain queue of vertices whose
	// adjacency list is to be scanned as per normal
	// DFS algorithm
	list<int> queue;

	// boolean array visited[] which stores the
	// information whether ith vertex is reached
	// at least once in the Breadth first search
	bool visited[V];

	// initially all vertices are unvisited
	// so v[i] for all i is false
	// and as no path is yet constructed
	// dist[i] for all i set to infinity
	for (int i = 0; i < V; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
		pred[i] = -1;
	}

	// now source is first to be visited and
	// distance from source to itself should be 0
	visited[src] = true;
	dist[src] = 0;
	queue.push_back(src);

	// standard BFS algorithm
	while (!queue.empty()) {
		int u = queue.front();
		queue.pop_front();
		for (int i = 0; i < graph[u].size(); i++) {
			if (visited[graph[u][i]] == false) {
				visited[graph[u][i]] = true;
				dist[graph[u][i]] = dist[u] + 1;
				pred[graph[u][i]] = u;
				queue.push_back(graph[u][i]);

				// We stop BFS when we find
				// destination.
				if (graph[u][i] == dest)
					return true;
			}
		}
	}

	return false;
}

// utility function to print the shortest distance
// between source vertex and destination vertex
void printShortestDistance(int s,int dest)
{
	// predecessor[i] array stores predecessor of
	// i and distance array stores distance of i
	// from s
	int pred[V], dist[V];

	if (checkConnection(s, dest,pred, dist) == false) {
		cout << "Given source and destination"
			<< " are not connected";
		return;
	}

	// vector path stores the shortest path
	vector<int> path;
	int crawl = dest;
	path.push_back(crawl);
	while (pred[crawl] != -1) {
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}

	// distance from source is in distance array
	cout << "Shortest path length is : "
		<< dist[dest];

	// printing path from source to destination
	cout << "\nPath is::\n";
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " ";
}

};


int main(){
    Graph gh(5);
    gh.addEdge(0,1);
    gh.addEdge(0,2);
    gh.addEdge(2,1);
    gh.printGraph();
    gh.adjVertex(2);

    vector<int> adj=gh.adjVer(2);
          for (int i=0; i!= adj.size(); i++)
           {
               cout << ' ' << i;
           }
    gh.printShortestDistance(0, 1);

}
