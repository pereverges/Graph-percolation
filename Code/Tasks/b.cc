#include <iostream>
#include "UnionFind.cc"
#include <vector>
#include <time.h>       /* time */
#include <stdlib.h>
#include <stdio.h>      /* printf, NULL */
using namespace std;

bool CalculaPercolacio(vector<vector<int> > matrix){
	
	QuickUnionUF UF = QuickUnionUF(matrix.size()*matrix[0].size()+2);
	
	for (int i = 0; i < matrix.size(); ++i){
		for (int j = 0; j < matrix[0].size(); ++j){
			if (i == 0){
				for (int k = 0; k < matrix.size(); ++k){
					if (matrix[0][k] == 1) UF.Union(0, 1 + k);
				}
			}
			if (i < matrix.size()-1){
				if (matrix[i][j] == 1){
					if (matrix[i+1][j] == 1) UF.Union((i*matrix.size() + j+1), ((i+1)*matrix.size() + j+1));
					if (j >= 1){
						if(matrix[i][j-1] == 1) UF.Union((i*matrix.size() + j+1), (i*matrix.size() + j-1+1));
					}
					if (j < matrix.size()-1){
						if(matrix[i][j+1] == 1) UF.Union((i*matrix.size() + j+1), (i*matrix.size() + j+1+1));
					}
				}
			}
			else if (i == (matrix.size()-1)){
				if (matrix[i][j] == 1) UF.Union((i*matrix.size()+j+1),(matrix.size()*matrix[0].size()+1));
			}
		}
	}
		
	if (UF.connected(0,matrix.size()*matrix[0].size()+1)) return true;
	else return false;
}



void EscriuMatriu(vector<vector<int> > matrix){
	
	for (int i=0; i < matrix.size(); ++i){
		for (int j=0; j < matrix[0].size(); ++j){
			if (j == 0) cout << matrix[i][j];
			else cout << " " << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void EscriuMatriuArestes(vector<vector<char> > matrix){
	
	for (int i=0; i < matrix.size(); ++i){
		for (int j=0; j < matrix[0].size(); ++j){
			if (j == 0) cout << matrix[i][j];
			else cout << " " << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

vector<vector<int> > GeneraMatriu(int tam, int q){
	
	int cont = 0;
	
	vector<vector<int> > M(tam,vector<int>(tam,0));
	for (int i = 0; i < M.size(); ++i){
		for (int j = 0; j < M[0].size(); ++j){
			int rnd = rand();
			rnd %= 100;
			if(rnd >= q) {
				++cont;
				M[i][j] = 1;
			}
		}
	}
	return M;
}

vector<vector<char> > GeneraMatriuArestes(int tam, int q){
	
	vector<vector<char> > M(tam*2-1,vector<char>(tam*2-1,' '));
	int n;
	
	for (int i = 0; i < M.size(); ++i){
		for (int j = 0; j < M.size(); ++j){
			if (i % 2 == 0 and j % 2 == 0) M[i][j] = '0';
		}
	}
	for (int i = 0; i < M.size(); ++i){
		for (int j = 0; j < M.size(); ++j){
			if (i%2 == 0 and j%2 != 0){
				n = rand();
				n %= 100;
				if (n > q){
					M[i][j] = '%';
					if (j > 0) {
						M[i][j-1] = '1';
					}
					
					if (j < M.size()){
						M[i][j+1] = '1';
						
					}	
				}
			}
		}
	}
	for (int j = 0; j < M.size(); ++j){
		for (int i = 0; i < M.size(); ++i){
			if (i%2 != 0 and j%2 == 0){
				n = rand();
				n %= 100;
				if (n > q){
					M[i][j] = '%';
					M[i-1][j] = '1';
					M[i+1][j] = '1';
				}	
			}
		}
	}
	
	return M;
}

vector<vector<int> > MatriuArestes(vector<vector<char> > matrix){
	
	vector<vector<int> > M(matrix.size(),vector<int>(matrix.size(),0));
	for (int i = 0; i < M.size(); ++i){
		for (int j = 0; j < M.size(); ++j){
			if (matrix[i][j] == '1' or matrix[i][j] == '%') M[i][j] = 1;
		}
	}
	
	return M;
}

int TrobaTransicioDeFase(int tam){
	
	int fallo = 100;
	vector<vector<int> > matrix = GeneraMatriu(tam,fallo);
	while (not CalculaPercolacio(matrix)){
		--fallo;
		matrix = GeneraMatriu(tam,fallo);
	}
	return fallo;
}

int TrobaTransicioDeFaseArestes(int tam){
	
	int fallo = 100;
	srand(time(NULL));
	vector<vector<char> > matrix = GeneraMatriuArestes(tam,fallo);
	vector<vector<int> > M = MatriuArestes(matrix);
	while (not CalculaPercolacio(M)){
		--fallo;
		matrix = GeneraMatriuArestes(tam,fallo);
		M = MatriuArestes(matrix);
	}
	return fallo;
}

void PercolacioNodes(){
	
	int n,tam;
	cout << "Introdueix el tamany del taulell" << endl;
	cin >> tam;
	cout << endl;
	cout << "Vol introduir el % de fallada d'un node i saber si percola o vol saber el %?" << endl;
	cout << "1: Introdueixo el % de fallada d'un node" << endl;
	cout << "2: Calcular el %" << endl;
	cin >> n;
	cout << endl;
	
	if (n == 1){
		cout << "Introduir el % de fallada d'un node:" << endl;
		cin >> n;
		vector<vector<int> > matrix = GeneraMatriu(tam,n);
		cout << endl;
		cout << "El taulell resultant amb tamany " << tam << " es:" << endl;
		cout << endl;
		EscriuMatriu(matrix);
		bool b = CalculaPercolacio(matrix);
		if (b) cout << "El taulell percola" << endl;
		else cout << "El taulell no percola" << endl;
		cout << endl;
	}
	
	else if (n == 2){
		int k = 0;
		int p;
		cout << "Introdueix el nombre d'experiments que vol fer per trobar la transició de fase" << endl;
		cin >> p;
		cout << endl;
		
		for (int i = 0; i < p; ++i){
			int aux = TrobaTransicioDeFase(tam);
			k += aux;
		}
		
		k /= p;
		cout << "\033[1;31mDesprés de \033[0m" << p << "\033[1;31m experiments podem garantir que la transició de fase d'un taulell de tamany \033[0m" << tam << "*" << tam << "\033[1;31m es produeix al voltant d'una tasa de fallada de nodes de \033[0m" << k << "%." << endl;
	}
}

void PercolacioArestes(){
	
	int n,tam;
	cout << "Introdueix el tamany del taulell" << endl;
	cin >> tam;
	cout << endl;
	cout << "Vol introduir el % de fallada d'una aresta i saber si percola o vol saber el %?" << endl;
	cout << "1: Introdueixo el % de fallada d'una aresta" << endl;
	cout << "2: Calcular el %" << endl;
	cin >> n;
	cout << endl;
	
	if (n == 1){
		cout << "Introduir el % de fallada d'una aresta:" << endl;
		cin >> n;
		vector<vector<char> > matrix = GeneraMatriuArestes(tam,n);
		cout << endl;
		cout << "El taulell resultant amb tamany " << tam << " es:" << endl;
		cout << endl;
		EscriuMatriuArestes(matrix);
		vector<vector<int> > M = MatriuArestes(matrix);
		bool b = CalculaPercolacio(M);
		if (b) cout << "El taulell percola" << endl;
		else cout << "El taulell no percola" << endl;
		cout << endl;
	}
	
	else if (n == 2){
		int k = 0;
		int p;
		cout << "Introdueix el nombre d'experiments que vol fer per trobar la transició de fase" << endl;
		cin >> p;
		cout << endl;
		
		for (int i = 0; i < p; ++i){
			k += TrobaTransicioDeFaseArestes(tam);
		}
		
		k /= p; 
		cout << "\033[1;31mDesprés de \033[0m" << p << "\033[1;31m experiments podem garantir que la transició de fase d'un taulell de tamany \033[0m" << tam << "*" << tam << "\033[1;31m es produeix al voltant d'una tasa de fallada d'arestes de \033[0m" << k << "%." << endl;
	}
	
}

int main(){
	
	//(b) Estudiar la transició de fase a graelles quadrades n × n, sota un procés de
	//percolació de nodes i un d’arestes, de la propietat estudiada a https://algs4.
	//cs.princeton.edu/lectures/15UnionFind-2x2.pdf.
	
	//hem de generar un taulell n*n, definir quin es l'inici i quin és el final, i quin és el paràmetre q que representa la probabilitat de fallada dels nodes o les arestes
	//Monte Carlo: comencem amb totes les caselles bloquejants i anem afegint caselles de pas de forma random fins que obtinguem un cami entre els dos costats del taulell
	while (true){
		cout << endl;
		cout << "Estudi de la transició de fase a graelles quadrades n*n sota un procés de percolació de nodes i un d'arestes" << endl;
		cout << endl;
		cout << "Quin tipus de procés de percolació vol?" << endl;
		cout << "1: Percolació de nodes" << endl;
		cout << "2: Percolació d'arestes" << endl;
		int n;
		cin >> n;
		cout << endl;
		
		if (n == 1) PercolacioNodes();
		else PercolacioArestes();
		cout << endl;
	}
}
