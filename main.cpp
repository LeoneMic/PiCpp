#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


using namespace std;

/* 

All'esecuzione del programma:
- immettendo un numero n troverà una stima del valore di π n volte;
- immettendo m stamperà a schermo la media di tutte le stime eseguite finora;
- con q si esce dal programma.

---------------------------------------------------------------------------------------------------------------

Trova il valore di π prendendo punti a caso su un quadrato di
lato 1 e controllando se il punto è all'interno del quarto di una circonferenza
di raggio 1 usando l'equazione della circonferenza x^2 + y^2 = 1.
Se x^2 + y^2 <= 1 il punto è all'interno della circonferenza.

Per ottenere il valore stimato di π divide il numero di punti interni al cerchio
con il numero totale di punti presi a caso, infine moltiplicando il risultato per 4.

Risoluzione ottenuta da

l = r 

Aq = l^2 => Aq = r^2
Ac = (πr^2)/4

Messe a sistema

Ac = (πAq)/4 => (Ac/Aq) * 4 = π

*/


// Ritorna un double compreso tra 0 e 1
double randDouble(){
    return static_cast<float> (rand()) / static_cast <float> (RAND_MAX);
}

// Ritorna un bool indicante se il carattere è numero
bool isDigita(char carattere){
    if (carattere == '0' || carattere == '1' || carattere == '2' || carattere == '3' || carattere == '4' ||carattere == '5' || carattere == '6' || carattere == '7' || carattere == '8' || carattere == '9')
    {
        return true;
    }
    return false;
}

// Ritorna un bool indicante se l'intera stringa è un numero
bool isNumero(string str){

    for (int i = 0; i < str.length(); i++)
    {
        if (!isDigita( str[i] )){
            return false;
        }
    }
    return true;

}

// Algoritmo che trova una stima di π 1 volta, ritorna il valore trovato
double getPi(int shooting_points, double& valoreTotalePi, int& esecuzioniTotali){
    int insideTheCircleCounter = 0;
    double x;
    double y;

    for (int i = 0; i < shooting_points; i++)
    {
        x = randDouble();
        y = randDouble();

        if ( ((x*x) + (y*y)) <= 1 )
        {
            insideTheCircleCounter++;
        }
    }

    double ratio = (double)insideTheCircleCounter / shooting_points;

    valoreTotalePi += ratio*4;
    esecuzioniTotali++;

    return ratio*4;
}


int main(){

    srand(time(NULL));


    int puntiTotali = 10000;
    double valorePi = 0;
    int numeroRun;

    string input;
    
    double valoreTotalePi = 0;
    int esecuzioniTotali = 0;


    while (true)
    {

        cout << "Cosa vuoi fare:" << endl;
        cout << "n) Esegui n stime" << endl;
        cout << "m) Mostra la media di tutte le stime" << endl;
        cout << "q) Esci dal programma" << endl;

        cin >> input;
        cout << endl;
        
        if ( isNumero( input ) ){

            // Conversione da stringa a int
            numeroRun = stoi(input);

            // Loop per eseguire l'algoritmo più volte
            for (int i = 0; i < numeroRun; i++)
            {
                valorePi = getPi(puntiTotali, valoreTotalePi, esecuzioniTotali);

                cout << "Pi greco e': " << valorePi << endl;
            }

            cout << endl;
        } 
        else if ( input == "m")
        {
            cout << "La media e': " << valoreTotalePi/esecuzioniTotali << endl << endl;
            
        }
        else if ( input == "q")
        {
            break;
        }
    }
}