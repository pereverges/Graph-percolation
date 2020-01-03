
#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>

using namespace std;

typedef vector<vector<int> > matrix;

/* Funció per imprimir per pantalla un graf representat per la seva matriu d'adjacència.
 
 Pre:   M és la matriu d'adjacència del graf. Per tant, és una matriu quadrada.
 Post:  S'ha escrit per la sortida estàndard la matriu d'adjacència M del graf.
 */
void escriureGraf(matrix M){
    int tam = M.size();
    for(int i = 0; i < tam; ++i){
        for(int j = 0; j < tam; ++j) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/* Funció que genera la matriu d'adjacència d'un graf aleatori seguint el model d'ERDOS.
 
 Pre: n és el nombre de vèrtexs que tindrà el graf. p és el percentatge de probabilitat de crear una aresta entre qualsevol parell de vèrtexs.
 Post: Retorna la matriu d'adjacència del graf amb n vèrtexs. Les arestes s'han establert en funció de la probabilitat p.
 */
matrix generaGrafAleatoriErdos(int n, float p){
    matrix M(n, vector<int>(n,0));
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            float rnd = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.0));
            if(fmod(rnd, 100.0) < p) {
                M[i][j] = 1;
                M[j][i] = 1;
            }
        }
    }
    return M;
}

/* Funció que genera la matriu d'adjacència d'un graf aleatori seguint el model UNIFORME.
 
 Pre: n és el nombre de vèrtexs que tindrà el graf i m és el nombre d'arestes que tindrà el graf.
 Post: Retorna la matriu d'adjacència d'un graf amb n vèrtexs i m arestes. Les m arestes s'han establert aleatòriament entre els diferents parells formats pels n vèrtexs.
 */
matrix generaGrafAleatoriUniforme(int n, int m) {
    matrix M(n,vector<int>(n,0));
    
    int v1, v2;
    for (int i = 0; i < m; ++i) {
        
        do {
            v1 = rand() % n;
            v2 = rand() % n;
        } while (M[v1][v2] == 1);
        
        M[v1][v2] = 1;
        M[v2][v1] = 1;
    }
    
    return M;
}

/* Funció que genera un graf aleatori seguint el model de connexió preferencial de Barabasi-Albert.
 
 Pre: n són els vèrtexs inicials, t són els temps de generació i m són el nombre d'arestes a inserir per a cada temps de generació.
 Post: Retorna la matriu d'adjacència d'un graf generat mitjançant el model de Barabasi-Albert.
 */
matrix generaGrafAleatoriBarabasi(int n, int t, int m) {
    
    //matriu d'adjacència
    matrix M(n+t, vector<int>(n+t, 0));
    
    //vector de graus: tot vèrtex te grau 'fictici' 1
    vector<int> graus(n+t, 1);
    
    //graus inicials n (1 per cada vèrtex inicial)
    int sumaGraus = n;
    int sumaGrausAux;
    
    //cout << n << " " << n+t << endl;
    
    for (int i = n; i < n+t; ++i) {
        
        //cout << "entro" << endl;
        
        sumaGrausAux = sumaGraus;
        
        //afegim les m arestes que surten d'aquest nou node
        for (int j = 0; j < m; ++j) {
            
            //recorregut pels vèrtexs que ja són al graf
            for (int k = 0; k < i; ++k) {
                
                //si no són adjacents i aleatoriament surt escollit
                if (M[i][k] == 0 and rand() % sumaGrausAux < graus[k]) {
                    M[i][j] = 1;
                    M[j][i] = 1;
                    ++graus[i];
                    ++graus[j];
                    sumaGraus += 2;
                }
            }
        }
    }
    
    return M;
}

/* Funció que comprova si hi ha un camí des d'un vèrtex a un altre.
 
 Pre: M és la matriu d'adjacència d'un graf. u i v són dos vèrtexs del graf. visitat és un vector que indica els nodes que ja s'han visitat.
 Post: Retorna true si hi ha un camí des de u a v en el graf representat per M. Altrament retorna false.
 */
bool hiHaCami(matrix& M, int u, int v, vector<bool>& visitat) {
    visitat[u] = true;
    
    //u,v són adjacents -> hi ha camí u-v
    if (M[u][v] == 1) return true;
    
    bool cami = false;
    
    //comprovem si hi ha camí cap a 'v' des d'alguna adjacència de 'u'
    for (int i = 0; i < M.size() and not cami; ++i) {
        if (i != u and not visitat[i] and M[i][u] == 1) {
            cami = hiHaCami(M, i, v, visitat);
        }
    }
    
    //hem comprovat totes les adjacències de 'u' i en cap d'elles hem trobat un camí cap a 'v'
    return cami;
} 

/* Funció que determina si un graf és 2v-connex.
 
 Pre: M és la matriu d'adjacència del graf.
 Post: Retorna true si el graf representat per M és 2v-connex. Altrament retorna false.
 */
bool comprovaConnectivitat(matrix& M) {
    int v1, v2;
    
    v1 = rand() % M.size();
    
    v2 = -1;
    for (int i = 0; i < M.size() and v2 == -1; ++i) {
        if (M[i][v1] == 0) v2 = i;
    }
    
    if (v2 == -1) return true;
    
    vector<bool> visitat(M.size(), false);
    return hiHaCami(M, v1, v2, visitat);
}

//MAIN TESTEIG
//*****************************************************************************
//COMENTAR O ELIMINAR SI ES VOL EXECUTAR ALGUN DELS MAINS DELS DIFERENTS MODELS
//*****************************************************************************
/*
 int main() {
 
 cout << "Main de testeig." << endl;
 
 srand(time(0));
 
 int n = 0;
 
 cout << endl;
 cout << "**********************************************" << endl;
 cout << "** Apartat C:  Generació de grafs aleatoris **" << endl;
 cout << "**********************************************" << endl << endl;
 
 while (n != 3) {
 cout << "Tria la funció a testejar:" << endl;
 cout << "   0: Graf aleatori Erdos" << endl;
 cout << "   1: Graf aleatori Uniforme" << endl;
 cout << "   2: Graf aleatori Connexio preferencial (Barbasi)" << endl;
 cout << "   3: Acabar" << endl;
 cin >> n;
 cout << endl;
 
 if (n < 0 or n > 3) cout << "Index incorrecte! Torna a introduir l'index." << endl;
 else if (n != 3) {
 
 matrix M;
 int v, m, p, t;
 
 if (n == 0) {
 cout << "Introdueix el nombre de vertexs: " << endl;
 cin >> v;
 cout << endl << "Introdueix la probabilitat [0..100]: " << endl;
 cin >> p;
 cout << endl;
 M = generaGrafAleatoriErdos(v, p);
 }
 
 else if (n == 1) {
 cout << "Introdueix el nombre de vertexs: " << endl;
 cin >> v;
 cout << endl << "Introdueix el nombre d'arestes: " << endl;
 cin >> m;
 cout << endl;
 M = generaGrafAleatoriUniforme(v, m);
 }
 
 else if (n == 2) {
 cout << "Introdueix el nombre de vertexs inicials: " << endl;
 cin >> v;
 cout << endl << "Introdueix el temps de generacio: " << endl;
 cin >> t;
 cout << endl << "Introdueix les arestes que s'han d'afegir en cada temps: " << endl;
 cin >> m;
 cout << endl;
 M = generaGrafAleatoriBarabasi(v, t, m);
 }
 
 cout << "La matriu d'adjacencia del graf aleatori generat es: " << endl;
 escriureGraf(M);
 }
 }
 }
 */
