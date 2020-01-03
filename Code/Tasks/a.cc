#include <iostream>
#include "generadorDeGrafsAleatoris.cc"
#include <vector>
#include <stdlib.h>
using namespace std;

typedef vector<vector<int> > matrix;

matrix M1 = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0}};

matrix M2 = {
    {0, 1, 0, 0, 1, 0},
    {1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0}};

matrix M3 = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

matrix M4 = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}};

matrix M5 = {
    {0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 1, 0}};

/* Funció per imprimir un missatge d'error.

 Pre:   msg és el missatge d'error que volem que s'escrigui per sortida estàndard.
 Post:  S'ha escrit msg per la sortida estàndard. NO s'atura l'execucio del programa.
 */
void error(string msg) {
    cout << endl;
    cout << "ERROR: " << msg << "!" << endl;
    cout << endl;
}

/* Funció per llegir un graf a partir de la seva matriu d'adjacència.

 Pre:   Cert.
 Post:  Retorna la matriu d'adjacència que s'ha introduit per l'entrada estàndard.
 */
matrix llegirGraf() {
    int n;
    cout << "Introdueix el nombre de nodes:" << endl;
    cin >> n;

    cout << "Introdueix la matriu d'adjacencia:" << endl;

    matrix M(n, vector<int>(n,0));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> M[i][j];
        }
    }

    return M;
}


/* Funció per executar la percolació per nodes d'un graf.

 Pre:   M és la matriu d'adjacència del graf sense percolar. M és una matriu quadrada.
 Post:  M és ara la matriu d'adjacència del graf percolat per nodes en funció de la
 probabilitat introduida per l'entrada estàndard. M segueix essent una matriu quadrada.
 */
void percolacioNodes(matrix &M) {
    int p = -1;
    while (p < 0 or p > 100) {
        cout << "Introdueix el % de fallida d'un node:" << endl;
        cin >> p;
        if (p < 0 or p > 100) error("El percentatge ha de ser un valor entre 0 i 100");
    }
    cout << endl;

    int tam = M.size();
    for(int i = 0; i < tam; ++i) {
        srand(time(0));
        if(rand() % 100 <= p){
            for(int j = 0; j < tam; ++j) {
                M[i][j] = 0;
                M[j][i] = 0;
            }
        }
    }
}

/* Funció per executar la percolació per arestes d'un graf.

 Pre:   M és la matriu d'adjacència del graf sense percolar. M és una matriu quadrada.
 Post:  M és ara la matriu d'adjacència del graf percolat per arestes en funció de la
 probabilitat introduida per l'entrada estàndard. M segueix essent una matriu quadrada.
 */
void percolacioArestes(matrix &M) {
    cout << "Introdueix el % de fallida d'una aresta:" << endl;
    int p = -1;
    while (p < 0 or p > 100) {
        cin >> p;
        if (p < 0 or p > 100) error("El percentatge ha de ser un valor entre 0 i 100. Torna a introduir el percentatge");
    }
    cout << endl;

    int tam = M.size();
    for(int i = 0; i < tam; ++i) {
        for(int j = i+1; j < tam; ++j) {
            srand(time(0));
            if(rand() % 100 <= p) {
                M[i][j] = 0;
                M[j][i] = 0;
            }
        }
    }
}

/* Funció per escollir un graf d'entre els generats per nosaltres.

 Pre:   Cert.
 Post:  Retorna la matriu d'adjacència d'un dels grafs generats per nosaltres.
 */
matrix escollirGrafHarcoded(){
    cout << "Tria el tipus de graf:" << endl;
    cout << "     1: Graf qualsevol de 5 vertexs" << endl;
    cout << "     2: Graf qualsevol de 6 vertexs" << endl;
    cout << "     3: Graf complet de 10 vertexs" << endl;
    cout << "     4: Graf amb cicle hamiltonia de 5 vertexs" << endl;
    cout << "     5: Graf amb 2 components connexes de 7 vertexs" << endl;

    matrix M;
    int n = 0;
    while (n < 1 or n > 5) {
        cin >> n;

        if (n == 1) M = M1;
        else if (n == 2) M = M2;
        else if (n == 3) M = M2;
        else if (n == 4) M = M4;
        else if (n == 5) M = M5;
        else error("Index incorrecte. Torna a introduir l'index");
    }

    return M;
}

int main(){

    cout << endl;
    cout << "**********************************************" << endl;
    cout << "** Apartat A: Proces de percolacio de grafs **" << endl;
    cout << "**********************************************" << endl << endl;

    int n = -1;
    while (n != 0){
        cout << "Tria una opcio:" << endl;
        cout << "     0: Finalitzar l'execucio" << endl;
        cout << "     1: Introduir el graf manualment" << endl;
        cout << "     2: Escollir d'entre els grafs generats per nosaltres" << endl;
        cin >> n;
        cout << endl;

        if (n < 0 or n > 2) error("Index incorrecte");

        else if (n != 0) {
            matrix M;
            if (n == 1) M = llegirGraf();
            else if (n == 2) M = escollirGrafHarcoded();
            cout << endl;

            cout << "Tria el tipus de percolacio:" << endl;
            cout << "     1: Percolacio per nodes" << endl;
            cout << "     2: Percolacio per arestes" << endl;

            int perc = 0;
            while (perc < 1 or perc > 2) {
                cin >> perc;
                if (perc < 1 or perc > 2) error("Index incorrecte. Torna a introduir l'index");
            }
            cout << endl;

            cout << "Matriu d'adjacencia del graf NO percolat:" << endl;
            escriureGraf(M);

            if (perc == 1) percolacioNodes(M);
            else percolacioArestes(M);

            cout << "Matriu d'adjacencia del graf percolat:" << endl;
            escriureGraf(M);

            cout << endl;
            cout << "--------------------------------------------" << endl;
            cout << "--------------------------------------------" << endl;

            cout << endl;
        }
    }
}
