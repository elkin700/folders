#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int infi=1e9;
void floydWarshall (vector<vector<int>>& grafo, unordered_map<char, int>& vertexMap){
    int v = grafo.size();
    vector<vector<int>> dist(grafo);
    for(int h=0;h<v;h++){
        for(int j=0;j<v;j++){
            for(int k=0;k<v;k++){
                if(dist[j][h] != infi && dist[h][k] != infi && dist[j][h] + dist[h][k] < dist[j][k]){
                    dist[j][k] = dist[j][h] + dist[h][k];
                }
            }
        }
    }
    cout<<"Matriz de distacia mínima: "<<endl;
    for(int j=0;j<v;j++){
            for(int k=0;k<v;k++){
                if (dist[j][k]==infi){
                    cout<<"Infinito";
                }else{
                    cout<< dist[j][k]<< " ";
                }
        }
        cout << endl;
    }
}
int main(){
    int v, a;
    cout<<"Ingrese los vértices: ";
    cin>>v;
    cout<<"Ingrese las aristas: ";
    cin>>a;
    unordered_map<char, int> vertexMap;
    vector<vector<int>>grafo(v, vector<int>(v, infi));
    cout<<"Ingrese las aristas en el siguiente orden [vértice de origen, vértice de destino y peso]: "<<endl;
    char m,n;
    int b;
    for (int k=0;k<a;k++){
        cin>> m >> n >> b;
        if (vertexMap.find(m) == vertexMap.end()) {
            vertexMap[m] = vertexMap.size();
        }
        if (vertexMap.find(n) == vertexMap.end()) {
            vertexMap[n] = vertexMap.size();
        }
        grafo[vertexMap[m]][vertexMap[n]] = b;
    }
    floydWarshall(grafo, vertexMap);
    return 0;
    }
    /* 
    */