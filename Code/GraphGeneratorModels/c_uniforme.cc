#include "c.cc"

//MAIN EXPERIMENTAL: MODEL UNIFORME
//*****************************************************************************
//PER EXECUTAR-LO, CAL COMENTAR O ELIMINAR EL MAIN DEL FITXER c.cc
//*****************************************************************************
int main() {
    
    cout << "Main experimental: Model Uniforme." << endl;
    
    srand(time(0));
    
    time_t timer, timer_ant;
    
    //Tamany del graf a testejar
    int n = 3000;
    
    //Num. arestes a afegir
    int m = 6000;
    
    //Offset
    int off = 12;
    
    //Repeticions
    int rep = 50;
    
    cout << "Tamany del graf: " << n << "." << endl;
    
    matrix M;
    int no_cami, cami;
    
    //Nº d'arestes a testejar: de 0 a MAX_ARESTES
    for (int i = 0; i <= m; i += off) {
        no_cami = cami = 0;
        //Nº de repeticions per cada percentatge: 500
        for (int j = 0; j < rep; ++j) {
            
            M = generaGrafAleatoriUniforme(n, i);
            
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
