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

};

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

}
