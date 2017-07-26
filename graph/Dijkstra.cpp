#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

#define max_size_vertexs 50
#define INFINITY 65535

typedef char VertexType;
typedef int Path[max_size_vertexs];
typedef int short_path_length[max_size_vertexs];

typedef struct{
    VertexType ver[max_size_vertexs];
    int edge[max_size_vertexs][max_size_vertexs];
    int vertexN,edgeN;
}DirectedNet;

// get the position of a vertex
int get_index(DirectedNet &DNet,VertexType e){
    for(int i=0;i<DNet.vertexN;i++){
        if(DNet.ver[i] == e){
            return i;
        }
    }
}

//create the directed Net
void CreateDNet(DirectedNet &DNet){
    VertexType v1,v2;
    int i,weight;
    cout<<"input the num of vertexs and edges:";
    cin>>DNet.vertexN>>DNet.edgeN;
    // init the net
    for(i=0;i<DNet.vertexN;i++){
        for(int j=0;j<DNet.vertexN;j++){
            DNet.edge[i][j] = INFINITY;
        }
        DNet.edge[i][i] = 0;
    }
    cout<<"input the vertexs:";
    for(i=0;i<DNet.vertexN;i++){
        cin>>DNet.ver[i];
    }
    for(i=0;i<DNet.edgeN;i++){
        cout<<"input the edge(v1,v2,weight):";
        cin>>v1>>v2>>weight;
        DNet.edge[get_index(DNet,v1)][get_index(DNet,v2)] = weight;
    }
}

// print the net
void print_matrix(DirectedNet &DNet){
    int i,j;
    cout<<"the matrix of Directed Net:"<<endl;
    cout<<"  ";
    for(i=0;i<DNet.vertexN;i++){
        cout<<setw(6)<<DNet.ver[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<DNet.vertexN;i++){
        cout<<DNet.ver[i]<<" ";
        for(j=0;j<DNet.vertexN;j++){
            cout<<setw(6)<<DNet.edge[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void shortest_path(DirectedNet &DNet,VertexType v0,Path *p,short_path_length *len){
    // cout<<"v0 index:"<<get_index(DNet,v0)<<endl;
    int i,w,k,min;
    int final[max_size_vertexs];
    for(i=0;i<DNet.vertexN;i++){
        final[i] = 0;
        (*len)[i] = DNet.edge[get_index(DNet,v0)][i];
        (*p)[i] = 0;
        // cout<<(*len)[i]<<endl;
    }
    // the origin node
    (*len)[get_index(DNet,v0)] = 0;
    final[get_index(DNet,v0)] = 1;

    for(i = 1;i<DNet.vertexN;i++){
        min = INFINITY;
        for(w = 0;w<DNet.vertexN;w++){
            if(final[w] == 0 && (*len)[w] < min){
                k = w;
                min = (*len)[w];
            }
        }// end for
        final[k] = 1;
        for(w = 0;w < DNet.vertexN;w ++){
            if(final[w] == 0 && (min+DNet.edge[k][w] <(*len)[w])){
                (*len)[w] = min+DNet.edge[k][w];
                (*p)[w] = k;
            }
            
        }
    }
}

int main(){
    DirectedNet DNet;
    VertexType v0 = '2';
    Path *p = (Path *)malloc(max_size_vertexs*sizeof(Path));
    short_path_length *len = (short_path_length*)malloc(max_size_vertexs*sizeof(short_path_length));
    CreateDNet(DNet);
    print_matrix(DNet);
    shortest_path(DNet,v0,p,len);
    for(int i=0;i<DNet.vertexN;i++){
        cout<<v0<<" to "<<DNet.ver[i]<<" length is "<<(*len)[i]<<endl;
    }
    return 0;
}
