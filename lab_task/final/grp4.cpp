#include<bits/stdc++.h>

using namespace std;


class Graph{
public:
    int n;
    Graph(int size){
        n=size;
    }
    //static int myarray[n][n] ={}; //not working
    int myarray[5][5] = {};

    void addEdge(int src,int des){
        myarray[src][des]=1;
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

    int* nonAdjacentVertices(int vertices){
        static int nonadj[5]={-1,-1,-1,-1,-1};
        int k=0;

        for(int i=0;i<5;i++){
            if(myarray[vertices][i]==0){
                if(i==vertices){
                    continue;
                }
                cout<<i<<endl;
                nonadj[k]=i;
                k=k+1;
            }
        }
        return nonadj;

    }
    void addUnknownVertices(int vertices){
        int* num;
        num=nonAdjacentVertices(vertices);
            if(num[0]== -1){
                cout<<"no nonadjacent vertices"<<endl;
            }
        else{
                cout<<"-------------------------------------\n";
            for(int i=0;i<5;i++){
                if(num[i]== -1){
                    break;
                }
                if(i==vertices){
                    continue;
                }
                cout<<num[i]<<endl;
                addEdge(vertices,num[i]);
         }
    }

    }
    bool findPath(int x,int y){
        return (myarray[x][y]==1);
    }
    void searchVertex(int arr[3]){
        if(findPath(arr[0],arr[1])){
            if(findPath(arr[1],arr[2])){
                cout<<"Vertex can be reached";
            }
            else{
                cout<<"Vertex can not be reached";
                return;
            }
        }
        else{
            cout<<"Vertex can not be reached";
            return;
        }
    }
};

int main(){
    Graph gh(5);
    //adding edge
    gh.addEdge(0,1);
    gh.addEdge(0,4);
    gh.addEdge(1,2);
    gh.addEdge(2,3);
    gh.addEdge(3,4);
    gh.printGraph();
    cout<<"-------------------\n";
    int* ptr;

    //retriving non adjacent vertices
    ptr = gh.nonAdjacentVertices(0);
    if(ptr[0]== -1){
        cout<<"no nonadjacent vertices"<<endl;
    }
    else{
        cout<<"-------------------------------------\n";
        for(int i=0;i<5;i++){
            if(ptr[i]== -1){
                break;

            }
            cout<<ptr[i]<<endl;
         }

    }
    //adding unknown vertices
    cout<<"---------------------------\n";
    //gh.addUnknownVertices(4);
    cout<<"---------------------------\n";
    gh.printGraph();

    int arr_vertices[3]={0,4,3};
    gh.searchVertex(arr_vertices);









}
