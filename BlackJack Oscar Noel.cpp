
#include <iostream>

using namespace std;

//Variables de uso
int picas[13];
int diamantes[13];
int corazon[13];
int trebol[13];
bool finalJuego = false;

//Variables Jugador 1
string jugador1 ;
int puntosJugador1 = 0;
bool retirada = false;
bool ganador = false;
bool perdedor = false;
int AS;

//Variables Jugador 2
string crupier = "Crupier";
int puntosJugador2 = 0;
bool retirada2 = false;
bool ganador2 = false;
bool perdedor2 = false;


//Funciones
void Start() {
    cout << "Hola y bienvenido al BLACK JACK, hoy es una noche especial.\nCon quien tengo el gusto de jugar?" << endl;
    cin >> jugador1;
}
//Inicializar cartas

//Las cartas a 0 no se repiten
void inicializaArray(int(&pArray)[13]) {
    for (int i = 0; i < 13; i++) {
        pArray[i] = 1;
    }
}

void resultado() {
    if ((puntosJugador1 > puntosJugador2) && puntosJugador1 <= 21) {
        cout << "//////////////////////////////////////////////////////////\n";
        system("color a");
        cout << "MENUDA SUERTE!\nHAS GANADO!";
        system("pause");
    }
    else if ((puntosJugador2 <= 21) && puntosJugador2 > puntosJugador1) {
        cout << "//////////////////////////////////////////////////////////\n";
        system("color a");
        cout << "QUE PENA!\nHAS PERDIDO!";
        system("pause");
    }
    else if (puntosJugador2 > 21 || puntosJugador1 > 21) {
        cout << "//////////////////////////////////////////////////////////\n";
        system("color a");
        if (puntosJugador2 > 21) {
            cout << "EL CRUPIER HA PERDIDO";
        }
        else {
            cout << "QUE PENA!\nHAS PERDIDO!";
        }
        system("pause");
    }
    else if ((puntosJugador2 <= 21 && puntosJugador1 <= 21) && (puntosJugador2 == puntosJugador1)) {
        cout << "//////////////////////////////////////////////////////////\n";
        system("color a");
        cout << "EMPATE";
        system("pause");
    }

}

//Comprobar cartas picas o diamantes o corazones o trebol

void eleccionCarta(int& totalPoints, string player) {
    bool eleccion = false;
    int cartaInicial = 0;
    string tipoPalo;
    while (!eleccion) {
        //Elije una carta del 1 al 13
        cartaInicial = rand() % 13;

        if ((rand() % 4) == 0) {
            if (picas[cartaInicial] == 1) {
                picas[cartaInicial] = 0;
                eleccion = true;
                tipoPalo = "picas";
            }
        }
        else if ((rand() % 4) == 1) {
            if (diamantes[cartaInicial] == 1) {
            diamantes[cartaInicial] = 0;
            eleccion = true;
            tipoPalo = "diamantes";
            }
        }
        else if ((rand() % 4) == 2) {
            if (corazon[cartaInicial] == 1) {
                corazon[cartaInicial] = 0;
                eleccion = true;
                tipoPalo = "corazon";
            }
        }
            else {              
                trebol[cartaInicial] = 0;
                eleccion = true;
                tipoPalo = "trebol";
            }
        
    }
    if (cartaInicial == 0 ) {
        cout << "Menuda suerte acabas de tener! " << player << ".\nHa sacado un AS, que numero quieres elegir 1 o 11?"  << endl;
        if (player == crupier) {
            if (puntosJugador2 <= 10) {
                AS = 11;
                puntosJugador2 = puntosJugador2 + AS;
                cout << player << " ha elegido " << AS << ".\nAhora tienes un total de " << puntosJugador2 << " puntos" << endl;
            }
            else {
                AS = 1;
                puntosJugador2 = puntosJugador2 + AS;
                cout << player << " ha elegido " << AS << ".\nAhora tienes un total de " << puntosJugador2 << " puntos" << endl;
            }
        } else {
            cin >> AS;
            totalPoints = totalPoints + AS;
            cout << player << " ha elegido un " << AS << ".\nAhora tienes un total de " << puntosJugador1 << " puntos" << endl;
        }
    }
    else if (cartaInicial == 11 || cartaInicial == 12 || cartaInicial == 13) {
        totalPoints = totalPoints + 10;
        if(cartaInicial==11) {

            cout << "El jugador " << player << " ha sacado un J.\nTiene un total de " << totalPoints << endl;

        }
        else if(cartaInicial==12) {

            cout << "El jugador " << player << " ha sacado un Q.\nTiene un total de " << totalPoints << endl;

        }
        else {
            cout << "El jugador " << player << " ha sacado un K.\nTiene un total de " << totalPoints << endl;
            
        }
    }


    else if(cartaInicial >= 2 && cartaInicial <= 10) {
        totalPoints += cartaInicial + 1;
        cout << "El jugador " << player << " ha sacado un " << cartaInicial + 1 << " de " << tipoPalo << ".\nTiene un total de " << totalPoints << " puntos en su mano." << endl;
    }
}


bool checkPoints(int& points, bool& winner, bool& loser) {
    if (points == 21) {
        winner = true;
        return true;
    }
    else if (points > 21) {
        loser = true;
        return true;
    }
    return false;
}


int main() {
    Start();
    inicializaArray(picas);
    inicializaArray(diamantes);
    inicializaArray(corazon);
    inicializaArray(trebol);
    srand(time(NULL));
    //primer reparto de cartas
    eleccionCarta(puntosJugador1, jugador1);

    eleccionCarta(puntosJugador1, jugador1);

    //Puede pasar que ganemos o perdamos nada más comenzar
    retirada = checkPoints(puntosJugador1, ganador, perdedor);

    eleccionCarta(puntosJugador2, crupier);

    while (!retirada) {
        int choice = 0;
        //Comienza el juego con el jugador 1
        while (choice != 1 && choice != 2) {
            cout << "Tienes " << puntosJugador1 << " puntos en total.\nQuieres pedir carta?" << endl;
            
            cout << "1.- Si" << endl;
            cout << "2.- No" << endl;
         
            cin >> choice;
            if (choice != 1 && choice != 2) {
                cout << "Por favor, elije una opción valida." << endl;
            }
        }
        if (choice == 1) {
            eleccionCarta(puntosJugador1, jugador1);
            retirada = checkPoints(puntosJugador1, ganador, perdedor);
            ////////COMPROBAR JUGADA
        }
        else {
            /////////////RETIRADA
            retirada = true;
        }
        while (retirada == true && puntosJugador2 < 21 && puntosJugador2 < puntosJugador1) {
            eleccionCarta(puntosJugador2, crupier);
        }
    }
    resultado();
}

