#include <cassert>
#include <vector>
#include <iostream>
using namespace std;
class QuickUnionUF{
private:
  int *parent;
  int *rank;
  int count;
  int size;
public:
  QuickUnionUF(int N){
    count = N;
    size = N;
    parent = new int[N];
    rank = new int[N];
    for(int i = 0; i < N; i++){
      parent[i] = i;
      rank[i] = 0;
    }
  }

  int find(int i){
    while(i != parent[i]){
      parent[i] = parent[parent[i]];
      i = parent[i];
    }
    return i;
  }

  bool connected(int p, int q){
    return find(p) == find(q);
  }

  void Union(int p, int q){
    int rootP = find(p);
    int rootQ = find(q);
    if(rootP == rootQ) return;

    if(rank[rootP] < rank[rootQ]) parent[rootP] = rootQ;
    else if(rank[rootP] > rank[rootQ]) parent[rootQ] = rootP;
    else{
      parent[rootQ] = rootP;
      rank[rootP]++;
    }
    count--;
  }

  int counter(){
    return count;
  }

  void printSets(){
    for(int i = 0; i < size; i++){
      //cout << "parent " << find(i) << " " << "rank " << rank[i] << " ";
      cout << find(i) << " ";

    }
    cout << endl;
  }
};
