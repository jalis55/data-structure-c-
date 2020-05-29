
#include<bits/stdc++.h>
using namespace std;

list <int> graph[5];

void printGraph(list<int>graph[], int n){
    cout << "The graph is:" << endl;
    for (int i = 0; i < n; i++){
        cout << i << " -> ";
        for (int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
}
void findaj(list<int>graph[],int n,int val){

       // cout << i << " -> ";
        for (int j = 0; j < graph[val].size(); j++){
            cout << graph[val][j] << ' ';
        }
        cout << endl;

}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    printGraph(graph, 5);
    findaj(graph,5,2);
    return 0;
}
