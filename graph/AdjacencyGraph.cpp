#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

#define max_vertex_num 50
bool visited[max_vertex_num];
queue<int> q;

typedef char VertexType;
typedef char EdgeType;

// edge
typedef struct EdgeNode{
    EdgeType adjvex;
    //EdgeType weight;
    struct EdgeNode *nextEdge;  // next vertex
}EdgeNode;

// vertex
typedef struct VertexNode{
    VertexType data;
    EdgeNode *firstEdge;
}VertexNode,AdjList[max_vertex_num];

// AdjList
typedef struct{
    AdjList vertexs;
    int vertexNum,edgeNum;
}ALGraph;

int get_index(ALGraph &G,VertexType e){
    for(int i=0;i<G.vertexNum;i++){
        if(G.vertexs[i].data == e){
            return i;
        }
    }
}

void createALG(ALGraph &G){
    int i,j,k;
    EdgeNode *e;
    VertexType v1,v2;

    cout<<"input the num of vertexs and edges:";
    cin>>G.vertexNum>>G.edgeNum;
    cout<<"input the vertexs:";
    // init the vertexs
    for(i = 0;i < G.vertexNum;i ++){
        cin>>G.vertexs[i].data;
        G.vertexs[i].firstEdge = NULL;
    }
    // init the edges, undirected graph
    for(k = 0;k < G.edgeNum;k ++){
        cout<<"input the edge(v1,v2):";
        cin>>v1>>v2;
        i = get_index(G,v1);
        //j = get_index(G,v2);
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex = v2;
        e->nextEdge = G.vertexs[i].firstEdge;
        G.vertexs[i].firstEdge = e;
    }
}

void print_ALG(ALGraph &G){
    cout<<"the AdjList of the graph:"<<endl;
    for(int i=0;i<G.vertexNum;i++){
        EdgeNode *e;
        e = G.vertexs[i].firstEdge;
        cout<<G.vertexs[i].data<<":";
        // print the AdjList
        while(e){
            if(e){
                cout<<"->";
            }
            cout<<e->adjvex<<" ";
            e = e->nextEdge;
        }
        cout<<endl;
    }
}

void DFS(ALGraph &G,int i){
    EdgeNode *p;
    visited[i] = true;
    cout<<G.vertexs[i].data<<" ";
    p = G.vertexs[i].firstEdge;
    while(p){
        if(!visited[get_index(G,p->adjvex)]){
            DFS(G,get_index(G,p->adjvex));
        }
        p = p->nextEdge;
    }
}

void DFSTrans(ALGraph &G){
    int i;
    for(i=0;i<G.vertexNum;i++){
        visited[i] = false;
    }
    for(i=0;i<G.vertexNum;i++){
        if(!visited[i])
            DFS(G,i);
    }
    cout<<endl;
}

bool has_edge(ALGraph &G,int i,int j){
    VertexNode v = G.vertexs[i];
    EdgeNode *p = v.firstEdge;
    while(p){
        // cout<<"p->adjvex:"<<p->adjvex<<endl;
        if(p->adjvex == G.vertexs[j].data){
            return true;
        }
        p = p->nextEdge;
    }
    return false;
}

void BFS(ALGraph &G,int i){
    cout<<G.vertexs[i].data<<" ";
    visited[i] = true;
    q.push(i);
    int j,k;
    while(!q.empty()){
        k = q.front();
        q.pop();
        // cout<<"k="<<k<<endl;
        for(j = 0; j < G.vertexNum; j ++){
            if(!visited[j] && k!=j && has_edge(G,k,j)){
                cout<<G.vertexs[j].data<<" ";
                visited[j] = true;
                q.push(j);
            }
        }
    }

}

void BFSTrans(ALGraph &G){
    int i;
    for(i=0;i<G.vertexNum;i++){
        visited[i] = false;
    }

    for(i=0;i<G.vertexNum;i++){
        if(!visited[i]){
            BFS(G,i);
        }
    }
    cout<<endl;
}

int main(int argc, char const *argv[]){

    ALGraph G;
    createALG(G);
    print_ALG(G);
    cout<<"the DFS:";
    DFSTrans(G);
    cout<<"the BFS:";
    BFSTrans(G);
    return 0;
}
