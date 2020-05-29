#include<bits/stdc++.h>

using namespace std;


class Graph{
public:

   int **myarray;
   int n;
   Graph(int size);
   void addEdge(int src,int des);
   void printGraph();
   int* nonAdjacentVertices(int vertices);
   void addUnknownVertices(int vertices);
   bool findPath(int x,int y);
   void searchVertex(int arr[3]);


};

Graph::Graph(int size){
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
void Graph::addEdge(int src,int des){
    myarray[src][des]=1;

}
void Graph::printGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<myarray[i][j]<<" ";
        }
        cout<<endl;
    }

}
int* Graph::nonAdjacentVertices(int vertices){
       int* nonadj=new int[n];
       for(int i=0;i<n;i++){
        nonadj[i]=-1;
       }
        int k=0;

        for(int i=0;i<5;i++){
            if(myarray[vertices][i]==0){
                if(i==vertices){
                    continue;
                }
                nonadj[k]=i;
                k=k+1;
            }
        }
        return nonadj;

}
void Graph::addUnknownVertices(int vertices){
            int* num;
        num=nonAdjacentVertices(vertices);
            if(num[0]== -1){
                cout<<"no nonadjacent vertices"<<endl;
            }
        else{

            for(int i=0;i<5;i++){
                if(num[i]== -1){
                    break;
                }
                if(i==vertices){
                    continue;
                }
               // cout<<num[i]<<endl;
                addEdge(vertices,num[i]);
         }
    }

}
bool Graph::findPath(int x,int y){
    return (myarray[x][y]==1);
}

void Graph::searchVertex(int arr[3]){
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



int main(){
    int graph_size=5;
    Graph gh(graph_size);
    //adding edge
    gh.addEdge(0,1);
    gh.addEdge(0,4);
    gh.addEdge(1,2);
    gh.addEdge(2,3);
    gh.addEdge(3,4);
    gh.printGraph();



    //retriving non adjacent vertices
    int ver=0;
    int* ptr;
    ptr = gh.nonAdjacentVertices(ver);
    if(ptr[0]== -1){
        cout<<"no nonadjacent vertices"<<endl;
    }
    else{

        cout<<"Nonadjacent vertices of "<<ver<<" is:";
        for(int i=0;i<graph_size;i++){
            if(ptr[i]== -1){
                break;

            }
            cout<<ptr[i]<<" ";
         }
         cout<<endl;

    }



    int arr_vertices[3]={0,4,3};
    gh.searchVertex(arr_vertices);
    //adding unknown vertices

    //gh.addUnknownVertices(4);
    cout<<"\n--------------------------------";
    int add_unknown_vertices_to=4;
    cout<<"\nAfter adding unknown vertices to "<<add_unknown_vertices_to<<endl;
    gh.addUnknownVertices(add_unknown_vertices_to);
    gh.printGraph();

}
