#include "c.cc"

//MAIN EXPERIMENTAL: MODEL CONNEXIÓ PREFERENCIAL - BARABASI
//*****************************************************************************
//PER EXECUTAR-LO, CAL COMENTAR O ELIMINAR EL MAIN DEL FITXER c.cc
//*****************************************************************************
int main() {
    
    cout << "Main experimental: Model de Connexio Preferencial (Barabasi)." << endl;
    
    srand(time(0));
    
    time_t timer, timer_ant;
    
    time(&timer_ant);
    
    //Tamany inicial del graf
    int n = 1000;
    
    //temps de generació a testejar:
    int t = 100;
    
    //Nombre d'arestes a afegir per a cada vèrtex nou en cada unitat de temps
    int m = 2000;
    
    //Repeticions
    int rep = 10;
    
    cout << "Tamany del graf: " << n << "." << endl;
    cout << "Temps de generació: " << t << "." << endl;
    
    matrix M;
    
    int no_cami, cami;
    no_cami = cami = 0;
    
    /* Descomentar per dur a terme el 1r experiment
     //1er EXPERIMENT: t VARIABLE, m FIXE
     
     cout << "Experiment 1: t variable // m fixe" << endl;
     
     for (int i = 0; i < t; ++i) {
     
     cami = no_cami = 0;
     
     for (int j = 0; j < rep; ++j) {
     
     M = generaGrafAleatoriBarabasi(n, i, m);
     
     if (comprovaConnectivitat(M)) ++cami;
     else ++no_cami;
     }
     
     //comptabilització del temps
     time(&timer);
     cout << "diff: " << timer - timer_ant << endl;
     timer_ant = timer;
     
     cout << cami << " " << no_cami << endl;
     }
     //*/
    
    //2n EXPERIMENT: m VARIABLE, t FIXE
    
    cout << "Experiment 2: t fixe // m variable" << endl;
    
    //Offset per avançar en el nombre d'arestes
    int off = 100;
    
    for (int i = 0; i < m; i += off) {
        
        cami = no_cami = 0;
        
        //cout << i << endl;
        
        for (int j = 0; j < rep; ++j) {
            
            M = generaGrafAleatoriBarabasi(n, t+1, i);
            
            if (comprovaConnectivitat(M)) ++cami;
            else ++no_cami;
            /*
             //comptabilització del temps
             time(&timer);
             cout << "diff: " << timer - timer_ant << endl;
             timer_ant = timer;*/
        }
        
        //comptabilització del temps
        /*time(&timer);
         cout << "diff: " << timer - timer_ant << endl;
         timer_ant = timer;*/
        
        cout << cami << " " << no_cami << endl;
    }
}
