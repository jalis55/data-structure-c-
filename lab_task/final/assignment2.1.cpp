#include<bits/stdc++.h>

using namespace std;


class Graph{
public:
   int **myarray;
   int n;
    Graph(int size){
       n=size;
       myarray=new int* [n];
       if(myarray){
        for(int i=0;i<n;i++){
            myarray[i]=new int [n];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                myarray[i][j]=0;
            }
        }
       }
    }

    void addEdge(int src,int des){
        myarray[src][des]=1;
        myarray[des][src]=1;
    }
        //Print the Graph
    void printGraph(){
            for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<myarray[i][j]<<" ";
        }
        cout<<endl;
    }

    }

    int* adjacentVertices(int vertices){


       int* adj=new int[n];
       for(int i=0;i<n;i++){
        adj[i]=-1;
       }
        int k=0;

        for(int i=0;i<n;i++){
            if(myarray[vertices][i]==1){
                if(i==vertices){
                    continue;
                }

                adj[k]=i;
                k=k+1;
            }
        }
        return adj;

    }
    void showCommonVertices(int x,int y){
        int* ptr1;
        int* ptr2;
        int i,j;
        ptr1=adjacentVertices(x);
        ptr2=adjacentVertices(y);
        for(i=0;i<n;i++){
            if(ptr1[i]== -1){
                break;

            }

         }
        for(j=0;j<n;j++){
            if(ptr2[j]== -1){
                break;

            }

         }
         cout<<"common adjacent vertices between "<<x<<" and "<<y<<":"<<endl;
         for(int n=0;n<i;n++){
            for(int m=0;m<j;m++){
                if(ptr1[n]==ptr2[m]){
                    cout<<ptr1[n]<<" ";
                }
            }
         }
         cout<<endl;
    }



//shortest path

int printShortestPath(int parent[], int s, int d);
int shortestPath(int src,int dest);

};


int Graph::printShortestPath(int parent[], int s, int d)
{
	static int level = 0;

	// If we reached root of shortest path tree
	if (parent[s] == -1)
	{
		cout << "Shortest Path between " << s << " and "
			<< d << " is " << s << " ";
		return level;
	}

	printShortestPath(parent, parent[s], d);

	level++;
	if (s < n)
		cout << s << " ";

	return level;
}
int Graph::shortestPath(int src, int dest)
{
	// Mark all the vertices as not visited
	bool *visited = new bool[2*n];
	int *parent = new int[2*n];


	// Initialize parent[] and visited[]
	for (int i = 0; i < 2*n; i++)
	{
		visited[i] = false;
		parent[i] = -1;
	}

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[src] = true;
	queue.push_back(src);

	// 'i' will be used to get all adjacent vertices of a vertex
	list<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		int s = queue.front();

		if (s == dest)
			return printShortestPath(parent, s, dest);

		queue.pop_front();

		// Get all adjacent vertices of the dequeued vertex s
		// If a adjacent has not been visited, then mark it
		// visited and enqueue it
		list<int> adj;
		for (int r = 0; r <n; ++r)
   {
      for (int c = 0; c <n; ++c)
      {
         adj.push_back(myarray[r][c]);
      }
   }


		for (int i = adj[s].begin(); i != adj[s].end(); ++i)

		{

			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
				parent[*i] = s;
			}
		}

	}
}

int main(){
    int graph_size=7;
    Graph gh(graph_size);
    //adding edge
    gh.addEdge(0,1);
    gh.addEdge(0,2);
    gh.addEdge(1,3);
    gh.addEdge(1,4);
    gh.addEdge(1,5);
    gh.addEdge(1,6);
    gh.addEdge(2,4);
    gh.addEdge(2,3);
    gh.addEdge(5,6);
    gh.addEdge(6,3);
    gh.printGraph();



    //retriving adjacent vertices
    int ver=1;
    int* ptr;
    ptr = gh.adjacentVertices(ver);

        cout<<"-------------------------------------\n";
        cout<<"Adjacent vertices of "<<ver<<endl;
        for(int i=0;i<graph_size;i++){
            if(ptr[i]== -1){
                break;

            }
            cout<<ptr[i]<<" ";
         }
         cout<<endl;


    //adding unknown vertices
    cout<<"---------------------------\n";
    gh.showCommonVertices(1,6);
    cout<<"---------------------------\n";
    gh.shortestPath(0,6);

}
