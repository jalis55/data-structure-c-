#include<bits/stdc++.h>

using namespace std;


class Graph{

public:

    int V;
    vector <int> *graph ;
    Graph(int size);
    void addEdge(int u,int v);
    void printGraph();
    int* adjacentVertices(int val);
    void showCommonVertices(int x,int y);
    bool checkConnection(int src, int dest,int pred[], int dist[]);
    void shortestPath(int s,int dest);

};

Graph::Graph(int size){
    V=size;
    graph=new vector <int> [2*V];

}
void Graph::addEdge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);


}
int* Graph::adjacentVertices(int val){

       int* adj=new int[V];
       for(int i=0;i<V;i++){
        adj[i]=-1;
       }
        int k=0;
        for (int j = 0; j < graph[val].size(); j++){

            adj[k]=graph[val][j];
            k++;
        }
        return adj;



}

void Graph::showCommonVertices(int x,int y){
        int* ptr1;
        int* ptr2;
        int i,j;
        ptr1=adjacentVertices(x);
        ptr2=adjacentVertices(y);
        for(i=0;i<V;i++){
            if(ptr1[i]== -1){
                break;

            }

         }
        for(j=0;j<V;j++){
            if(ptr2[j]== -1){
                break;

            }

         }
         cout<<"common adjacent vertices between "<<x<<" and "<<y<<":";
         for(int n=0;n<i;n++){
            for(int m=0;m<j;m++){
                if(ptr1[n]==ptr2[m]){
                    cout<<ptr1[n]<<" ";
                }
            }
         }
         cout<<endl;



}
bool Graph::checkConnection(int src, int dest,int pred[], int dist[]){

	list<int> queue;


	bool visited[V];


	for (int i = 0; i < V; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
		pred[i] = -1;
	}


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
void Graph::shortestPath(int s,int dest){

	int pred[V], dist[V];

	if (checkConnection(s, dest,pred, dist) == false) {
		cout << "Given source and destination"
			<< " are not connected";
		return;
	}


	vector<int> path;
	int crawl = dest;
	path.push_back(crawl);
	while (pred[crawl] != -1) {
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}




	cout << "Path is between "<<s<<" and " <<dest <<" is:";
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " ";

	cout << "\nTotal weight between " <<s <<" and " << dest<< " is : "
		<< dist[dest];
}







int main(){
    int graph_size=7;
    Graph gh(graph_size);
    gh.addEdge(0,1);
    gh.addEdge(0,2);
    gh.addEdge(1,4);
    gh.addEdge(1,3);
    gh.addEdge(1,5);
    gh.addEdge(1,6);
    gh.addEdge(2,4);
    gh.addEdge(2,3);
    gh.addEdge(3,6);
    gh.addEdge(5,6);

    int ver=1;
    int* ptr;
    ptr = gh.adjacentVertices(ver);

        cout<<"Adjacent vertices of "<<ver<<":";
        for(int i=0;i<graph_size;i++){
            if(ptr[i]== -1){
                break;

            }
            cout<<ptr[i]<<" ";
         }
         cout<<endl;

    gh.showCommonVertices(1,2);
    gh.shortestPath(0, 6);

}
