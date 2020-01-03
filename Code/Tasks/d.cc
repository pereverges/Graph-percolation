#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include "generadorDeGrafsAleatoris.cc"
using namespace std;

void percolacioNodes(matrix &M, int p) {
    int tam = M.size();
    for(int i = 0; i < tam; ++i) {
        if(rand() % 100 <= p){
            for(int j = 0; j < tam; ++j) {
                M[i][j] = 0;
                M[j][i] = 0;
            }
        }
    }
}

void percolacioArestes(matrix &M, int p) {
    int tam = M.size();
    for(int i = 0; i < tam; ++i) {
        for(int j = i+1; j < tam; ++j) {
            if(rand() % 100 <= p) {
                M[i][j] = 0;
                M[j][i] = 0;
            }
        }
    }
  }


int main() {

    cout << "Main experimental: Model d'Erdos comprovar connectivitat connex/ no connex." << endl;

    srand(time(0));

    //tamany dels grafs a testejar:
    //10, 30, 70, 100, 200

    vector<int> v = {10, 30, 70, 100, 150, 200, 250};

    for(int k = 0; k < v.size(); ++k){
      int n = v[k];

      cout << "Tamany del graf: " << n << "." << endl;

      matrix M;
      int no_connex, connex;

      //% de probabilitat a testejar: de 0..100
      for (int i = 0; i <= 100; ++i) {
          no_connex = connex = 0;
          //Nº de repeticions per cada percentatge: 200
          for (int j = 0; j < 200; ++j) {

              M = generaGrafAleatoriErdos(n, i);

              if (esConnex(M)) ++connex;
              else ++no_connex;
          }
          cout << no_connex << " " << connex << endl;
      }
    }

    cout << "Main experimental: Model d'Erdos comprovar connectivitat connex/ no connex." << endl;

    srand(time(0));

    //tamany dels grafs a testejar:
    //10, 30, 70, 100, 200

    v = {70, 100, 150, 200, 250};

    for(int k = 0; k < v.size(); ++k){
      int n = v[k];

      cout << "Tamany del graf: " << n << "." << endl;

      matrix M;
      int no_connex, connex;

      //% de probabilitat a testejar: de 0..100
      for (int i = 0; i <= 100; ++i) {
          no_connex = connex = 0;
          //Nº de repeticions per cada percentatge: 200
          for (int j = 0; j < 200; ++j) {

              M = generaGrafAleatoriErdos(n, i*0.1);

              if (esConnex(M)) ++connex;
              else ++no_connex;
          }
          cout << no_connex << " " << connex << endl;
      }
    }

    cout << "Main experimental: Grafs bipartits comprovar connectivitat connex/ no connex." << endl;

    srand(time(0));

    //tamany dels grafs a testejar:
    //10, 30, 70, 100, 200

    v = {10, 30, 70, 100, 150, 200, 250};

    for(int k = 0; k < v.size(); ++k){
      int n = v[k];

      cout << "Tamany del graf: " << n << "." << endl;

      matrix M;
      int no_connex, connex;

      //% de probabilitat a testejar: de 0..100
      for (int i = 0; i <= 100; ++i) {
          no_connex = connex = 0;
          //Nº de repeticions per cada percentatge: 200
          for (int j = 0; j < 200; ++j) {

              M = generadorGrafBipartit(n/2, n/2, i);
              if (esConnex(M)) ++connex;
              else ++no_connex;
          }
          cout << no_connex << " " << connex << endl;
      }
    }

    cout << "Main experimental: Grafs bipartits comprovar connectivitat connex/ no connex." << endl;

    srand(time(0));

    //tamany dels grafs a testejar:
    //10, 30, 70, 100, 200

    v = {70, 100, 150, 200, 250};

    for(int k = 0; k < v.size(); ++k){
      int n = v[k];

      cout << "Tamany del graf: " << n << "." << endl;

      matrix M;
      int no_connex, connex;

      //% de probabilitat a testejar: de 0..100
      for (int i = 0; i <= 100; ++i) {
          no_connex = connex = 0;
          //Nº de repeticions per cada percentatge: 200
          for (int j = 0; j < 200; ++j) {

              M = generadorGrafBipartit(n/2, n/2, i*0.2);
              if (esConnex(M)) ++connex;
              else ++no_connex;
          }
          cout << no_connex << " " << connex << endl;
      }
    }

    cout << "Main experimental: Binairs comprovar connectivitat connex/ no connex percolacio Nodes." << endl;

    srand(time(0));

    //tamany dels grafs a testejar:
    //10, 30, 70, 100, 200

    v = {10, 30, 70, 100, 150, 200, 250};

    for(int k = 0; k < v.size(); ++k){
      int n = v[k];

      cout << "Tamany del graf: " << n << "." << endl;

      matrix M;
      int no_connex, connex;

      //% de probabilitat a testejar: de 0..100
      for (int i = 0; i <= 100; ++i) {
          no_connex = connex = 0;
          //Nº de repeticions per cada percentatge: 200
          for (int j = 0; j < 200; ++j) {

              M = generadorArbresBinaris(n);
              percolacioNodes(M,i);
              if (esConnex(M)) ++connex;
              else ++no_connex;
          }
          cout << no_connex << " " << connex << endl;
      }
    }

    cout << "Main experimental: Binairs comprovar connectivitat connex/ no connex percolacio Nodes." << endl;

    srand(time(0));

    //tamany dels grafs a testejar:
    //10, 30, 70, 100, 200

    v = {70, 100, 150, 200, 250};

    for(int k = 0; k < v.size(); ++k){
      int n = v[k];

      cout << "Tamany del graf: " << n << "." << endl;

      matrix M;
      int no_connex, connex;

      //% de probabilitat a testejar: de 0..100
      for (int i = 0; i <= 100; ++i) {
          no_connex = connex = 0;
          //Nº de repeticions per cada percentatge: 200
          for (int j = 0; j < 200; ++j) {

              M = generadorArbresBinaris(n);
              percolacioNodes(M,i*0.05);
              if (esConnex(M)) ++connex;
              else ++no_connex;
          }
          cout << no_connex << " " << connex << endl;
      }
    }

    cout << "Main experimental: Binairs comprovar connectivitat connex/ no connex percolacio Arestes." << endl;

    srand(time(0));

    //tamany dels grafs a testejar:
    //10, 30, 70, 100, 200

    v = {10, 30, 70, 100, 150, 200, 250};

    for(int k = 0; k < v.size(); ++k){
      int n = v[k];

      cout << "Tamany del graf: " << n << "." << endl;

      matrix M;
      int no_connex, connex;

      //% de probabilitat a testejar: de 0..100
      for (int i = 0; i <= 100; ++i) {
          no_connex = connex = 0;
          //Nº de repeticions per cada percentatge: 200
          for (int j = 0; j < 200; ++j) {

              M = generadorArbresBinaris(n);
              percolacioArestes(M,i);
              if (esConnex(M)) ++connex;
              else ++no_connex;
          }
          cout << no_connex << " " << connex << endl;
      }
    }

    cout << "Main experimental: Binairs comprovar connectivitat connex/ no connex percolacio Arestes." << endl;

    srand(time(0));

    //tamany dels grafs a testejar:
    //10, 30, 70, 100, 200

    v = {70, 100, 150, 200, 250};

    for(int k = 0; k < v.size(); ++k){
      int n = v[k];

      cout << "Tamany del graf: " << n << "." << endl;

      matrix M;
      int no_connex, connex;

      //% de probabilitat a testejar: de 0..100
      for (int i = 0; i <= 100; ++i) {
          no_connex = connex = 0;
          //Nº de repeticions per cada percentatge: 200
          for (int j = 0; j < 200; ++j) {

              M = generadorArbresBinaris(n);
              percolacioArestes(M,i*0.05);
              if (esConnex(M)) ++connex;
              else ++no_connex;
          }
          cout << no_connex << " " << connex << endl;
      }
    }

    cout << "Main experimental: Binairs comprovar connectivitat connex/ no connex percolacio Nodes." << endl;

    srand(time(0));

    //tamany dels grafs a testejar:
    //10, 30, 70, 100, 200

    v = {10, 30, 70, 100, 150, 200, 250};

    for(int k = 0; k < v.size(); ++k){
      int n = v[k];

      cout << "Tamany del graf: " << n << "." << endl;

      matrix M;
      int no_connex, connex;

      //% de probabilitat a testejar: de 0..100
      for (int i = 0; i <= 100; ++i) {
          no_connex = connex = 0;
          //Nº de repeticions per cada percentatge: 200
          for (int j = 0; j < 200; ++j) {

              M = generadorDeCamins(n);
              percolacioNodes(M,i);
              if (esConnex(M)) ++connex;
              else ++no_connex;
          }
          cout << no_connex << " " << connex << endl;
      }
    }

    cout << "Main experimental: Binairs comprovar connectivitat connex/ no connex percolacio Nodes." << endl;

    srand(time(0));

    //tamany dels grafs a testejar:
    //10, 30, 70, 100, 200

    v = {70, 100, 150, 200, 250};

    for(int k = 0; k < v.size(); ++k){
      int n = v[k];

      cout << "Tamany del graf: " << n << "." << endl;

      matrix M;
      int no_connex, connex;

      //% de probabilitat a testejar: de 0..100
      for (int i = 0; i <= 100; ++i) {
          no_connex = connex = 0;
          //Nº de repeticions per cada percentatge: 200
          for (int j = 0; j < 200; ++j) {

              M = generadorDeCamins(n);
              percolacioNodes(M,i*0.05);
              if (esConnex(M)) ++connex;
              else ++no_connex;
          }
          cout << no_connex << " " << connex << endl;
      }
    }

    cout << "Main experimental: Binairs comprovar connectivitat connex/ no connex percolacio Arestes." << endl;

    srand(time(0));

    //tamany dels grafs a testejar:
    //10, 30, 70, 100, 200

    v = {10, 30, 70, 100, 150, 200, 250};

    for(int k = 0; k < v.size(); ++k){
      int n = v[k];

      cout << "Tamany del graf: " << n << "." << endl;

      matrix M;
      int no_connex, connex;

      //% de probabilitat a testejar: de 0..100
      for (int i = 0; i <= 100; ++i) {
          no_connex = connex = 0;
          //Nº de repeticions per cada percentatge: 200
          for (int j = 0; j < 200; ++j) {

              M = generadorDeCamins(n);
              percolacioArestes(M,i);
              if (esConnex(M)) ++connex;
              else ++no_connex;
          }
          cout << no_connex << " " << connex << endl;
      }
    }

    cout << "Main experimental: Binairs comprovar connectivitat connex/ no connex percolacio Arestes." << endl;

    srand(time(0));

    //tamany dels grafs a testejar:
    //10, 30, 70, 100, 200

    v = {70, 100, 150, 200, 250};

    for(int k = 0; k < v.size(); ++k){
      int n = v[k];

      cout << "Tamany del graf: " << n << "." << endl;

      matrix M;
      int no_connex, connex;

      //% de probabilitat a testejar: de 0..100
      for (int i = 0; i <= 100; ++i) {
          no_connex = connex = 0;
          //Nº de repeticions per cada percentatge: 200
          for (int j = 0; j < 200; ++j) {

              M = generadorDeCamins(n);
              percolacioArestes(M,i*0.05);
              if (esConnex(M)) ++connex;
              else ++no_connex;
          }
          cout << no_connex << " " << connex << endl;
      }
    }

    cout << "Main experimental: Camins comprovar connectivitat connex/ no connex percolacio Nodes." << endl;

    srand(time(0));

    //tamany dels grafs a testejar:
    //10, 30, 70, 100, 200

    v = {70, 100, 150, 200, 250};

    for(int k = 0; k < v.size(); ++k){
      int n = v[k];

      cout << "Tamany del graf: " << n << "." << endl;

      matrix M;
      int no_connex, connex;

      //% de probabilitat a testejar: de 0..100
      for (int i = 0; i <= 100; ++i) {
          no_connex = connex = 0;
          //Nº de repeticions per cada percentatge: 200
          for (int j = 0; j < 200; ++j) {

              M = generadorDeCamins(n);
              percolacioNodes(M,i*0.05);
              if (esConnex(M)) ++connex;
              else ++no_connex;
          }
          cout << no_connex << " " << connex << endl;
      }
    }

    //main per experimentar amb el calcul del diametre en un graf aleatori generat amb Erdos

 int n = 200;

 for (int i = 100; i >= 0; --i){

   int k = 0;
   for (int j = 0; j < 50; ++j){
     matrix M = generaGrafAleatoriErdos(n,i);
     k += diametreGraph(M);
   }
   k /= 100;
   cout << "El diametre del graf amb tamany " << n << " i probabilitat " << i << " es de " << k << endl;
 }

}
