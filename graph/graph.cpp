#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
#define maxVertexNum 100

typedef char VertexType;
typedef int EdgeType;

typedef struct{
    VertexType ver[maxVertexNum];
    EdgeType edge[maxVertexNum][maxVertexNum];
    int vertexN,edgeN;  // current num of ver and edge
}MGraph;

queue<VertexType> que;
bool visited[maxVertexNum];

int getIndex(MGraph &G,VertexType v){
    for(int i=0;i<G.vertexN;i++){
        if(G.ver[i] == v){
            return i;
        }
    }
}

// the directed graph
void directed_edge(MGraph &G){
    VertexType ver1,ver2;
    for(int i=0;i<G.edgeN;i++){
        cout<<"input the edge(v1 v2):";
        cin>>ver1>>ver2;
        G.edge[getIndex(G,ver1)][getIndex(G,ver2)] = 1;
    }
}

// the undirected graph
void undirected_edge(MGraph &G){
    VertexType ver1,ver2;
    // input the edges
    for(int i=0;i<G.edgeN;i++){
        cout<<"input the edge(v1 v2):";
        cin>>ver1>>ver2;
        G.edge[getIndex(G,ver1)][getIndex(G,ver2)] = 1;
        G.edge[getIndex(G,ver2)][getIndex(G,ver1)] = 1;
    }
    
}

void createGraph(MGraph &G){
    VertexType ver1,ver2;
    printf("%s", "input the num of vertexs and edges:");
    scanf("%d %d",&(G.vertexN),&(G.edgeN));
    printf("%s", "input the vertexs:");
    //input the vertexs
    for(int i=0;i<G.vertexN;i++){
        cin>>G.ver[i];
    }
    // init the edges
    for(int i=0;i<G.vertexN;i++){
        for(int j=0;j<G.vertexN;j++){
            G.edge[i][j] = 0;
        }
    }
    directed_edge(G);
    
}

// print the matrix
void print_matrix(MGraph &G){
    printf("%s\n", "the matrix of the graph:");
    cout<<"  ";
    for(int i=0;i<G.vertexN;i++){
        cout<<G.ver[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<G.vertexN;i++){
        cout<<G.ver[i]<<" ";
        for(int j=0;j<G.vertexN;j++){
            cout<<G.edge[i][j]<<" ";
        }
        cout<<endl;
    }
}

void visit(VertexType v){
    cout<<v<<" ";
}

// Breadth First Search 
void BFS(MGraph &G,VertexType v){
    visit(v);
    visited[getIndex(G,v)] = true;
    que.push(v);// insert into the queue

    while(!que.empty()){
        VertexType tmp = que.front();
        que.pop();
        for(int w = 0;w<G.vertexN;w++){
            if(G.edge[getIndex(G,tmp)][w]!=0 && visited[w]!=true){
                visited[w] = true;
                visit(G.ver[w]);
                que.push(G.ver[w]);
            }
        }
    }

}

void BFSTran(MGraph &G){
    for(int i=0;i<G.vertexN;i++){
        visited[i] = false;
    }
    for(int i=0;i<G.vertexN;i++){
        if(!visited[i]){
            BFS(G,G.ver[i]);
        }
    }
    printf("\n");
}

// Depth first search
void DFS(MGraph &G,VertexType v){
    visit(v);
    visited[getIndex(G,v)] = true;
    for(int i=0;i<G.vertexN;i++){
        if(!visited[i] && (G.edge[getIndex(G,v)][i]>0)){
            DFS(G,G.ver[i]);
        }
    }

}

void DFSTran(MGraph &G){
    for(int i=0;i<G.vertexN;i++){
        visited[i] = false;
    }
    for(int i=0;i<G.vertexN;i++){
        if(!visited[i]){
            DFS(G,G.ver[i]);
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[]){
    MGraph G;
    createGraph(G);
    print_matrix(G);
    cout<<"the BFS:";
    BFSTran(G);
    cout<<"the DFS:";
    DFSTran(G);
    return 0;
}