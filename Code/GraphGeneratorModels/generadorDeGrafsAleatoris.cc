#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include "c.cc"
using namespace std;
#define INF 1e18
typedef vector<vector<int> > matrix;

// Generador de grafs complets, la n representa el numero de vertexs
matrix generadorGrafComplet(int n){
  return generaGrafAleatoriErdos(n, 100);
}

// genera graph bipartits, n1 mida d'una banda del graph,
// n2 mida de l'altres, p probabilitat de que hi hagi una aresta entre dos vertexs.
matrix generadorGrafBipartit(int n1, int n2, int p){
  matrix M(n1+n2, vector<int>(n1+n2,0));
  for(int i = 0; i < n1; i++){
    for(int j = n1; j < n2+n1; j++){
      if(rand() % 100 <= p) {
          M[i][j] = 1;
          M[j][i] = 1;
      }
    }
  }
  return M;
}

// Graph que simplement es un cami
matrix generadorDeCamins(int n){
  matrix M(n, vector<int>(n,0));
  vector<int> v;
  for(int i = 0; i < n; i++){
    v.push_back(i);
  }
  random_shuffle(v.begin(), v.end());
  for(int i = 0; i < n-1; i++){
    M[v[i]][v[i+1]] = 1;
    M[v[i+1]][v[i]] = 1;
  }
  return M;
}

//generar graph aletoris que son arbres binaris
matrix generadorArbresBinaris(int n){
  matrix M(n, vector<int>(n,0));
  vector<int> v;
  for(int i = 0; i < n; i++){
    v.push_back(i);
  }
  random_shuffle(v.begin(), v.end());
  for(int i = 1; i < n; i++){
    M[v[i]][v[(i-1)/2]] = 1;
    M[v[(i-1)/2]][v[i]] = 1;
  }
  return M;
}

// auxiliar de la funcio esConnex
void checkConectivity(vector<int>& visited, matrix& M, int i){
  visited[i] = true;
  for(int j = 0; j < M.size(); j++){
    if(M[i][j] == 1){
      if(!visited[j]){
        checkConectivity(visited, M, j);
      }
    }
  }
}

// cert si el graph es connex
bool esConnex(matrix& M){
  vector<int> visited(M.size(),false);
  checkConectivity(visited, M, 0);
  for(int i = 0; i < M.size(); i++){
    if(!visited[i]) return false;
  }
  return true;
}

// funcio per aconseguir el diametre d'un grpah, fem servir l'algoritme de floydWarshall que
// et retorna la mida entre cada parell de vertexs
int minEdge(matrix& M, int ini, int fi){
  int n = M.size();
  bool visited[n] = {false};
  int distance[n] = {0};

  queue<int> Q;
  distance[ini] = 0;
  Q.push(ini);
  visited[ini] = true;
  while(!Q.empty()){
    int x = Q.front();
    Q.pop();
    for(int i = 0; i < n; i++){
      if(!visited[i]){
        if(M[x][i] != 0){
          distance[i] =  distance[x]+1;
          Q.push(i);
          visited[i] = true;
        }
      }
    }
  }
  return distance[fi];
}

int diametreGraph(matrix& M){
  int res = 0;
  for(int i = 0; i < M.size(); i++){
    for(int j = i+1; j < M.size(); j++){
      res = max(minEdge(M,i,j), res);
    }
  }
  return res;
}


void printMatriuAdjacencia(matrix M){
    int tam = M.size();
    for(int i = 0; i < tam; ++i){
        for(int j = 0; j < tam; ++j) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}






/*
int main() {
  int n1;
  //int n1, n2, p;
  //cout << "Escriu el numero de vertex del graf" << endl;
  cin >> n1;
  //cout << "Escriu el numero de vertex del graf" << endl;
  //cin >> n2;
  //cout << "Escriu la probabilitat de que dos vertex siguin adjacents" << endl;
  //cin >> p;
  matrix M = generadorArbresBinaris(n1);
  printMatriuAdjacencia(M);
  //cout << esConnex(M) << endl;

}
*/
