#include<iostream>
using namespace std;
void addEdge(int arr[][5], int vertex1, int vertex2);

int main(){
    // A graph with 5 vertices can be initialized as the following 2D array with No edges
    int graph[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    };

    //Example
    addEdge(graph, 0, 1); //Put edge between Node 0 and 1
    addEdge(graph, 2, 3); // Put edge between Node 2 and 3

    //Print the Graph
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

// A function that will take in the graph, and 2 vertices and make an edge (connection) between them
void addEdge(int arr[][5], int vertex1, int vertex2){
    arr[vertex1][vertex2] = 1;
    arr[vertex2][vertex1] = 1;
}
