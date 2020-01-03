#include "c.cc"

//MAIN EXPERIMENTAL: MODEL ERDOS
//*****************************************************************************
//PER EXECUTAR-LO, CAL COMENTAR O ELIMINAR EL MAIN DEL FITXER c.cc
//*****************************************************************************
int main() {
    
    cout << "Main experimental: Model d'Erdos." << endl;
    
    srand(time(0));
    
    time_t timer;
    time_t timer_ant;
    
    //Tamany del graf a testejar
    int n = 1500;
    
    //Límit superior de la probabilitat
    float p = 0.8;
    
    //Offset
    float off = 0.002;
    
    //Repeticions
    int rep = 50;
    
    cout << "Tamany del graf: " << n << "." << endl;
    
    matrix M;
    int no_cami, cami;
    
    //% de probabilitat a testejar: de 0..100
    for (float i = 0; i <= p; i += off) {
        no_cami = cami = 0;
        //Nº de repeticions per cada percentatge: 200
        for (int j = 0; j < rep; ++j) {
            
            M = generaGrafAleatoriErdos(n, i);
            
            if (comprovaConnectivitat(M)) ++cami;
            else ++no_cami;
        }
        cout << cami << " " << no_cami << endl;
        
        //comptabilització del temps
        time(&timer);
        cout << "diff: " << timer - timer_ant << endl;
        timer_ant = timer;
    }
}
