/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.cpp
 * Author: mari2bar
 * 
 * Created on 24 de febrero de 2020, 23:06
 */

#include "Juego.h"
#include "Pila.h"
#include "Cola.h"
#include "Carta.h"
#include "stdlib.h"

Juego::~Juego() {
    c1.~Cola();
    c2.~Cola();
    for (int i = 0; i < 7; i++) {
        pilas1[i].~Pila();
    }
    for (int i = 0; i < 4; i++) {
        pilas2[i].~Pila();
    }
}

/* JUEGO  */

Juego::Juego(Pila *&pila) {
    cout << endl << endl;
    srand((int) time(0));
    Carta *carta;
    for (int i = 0; i < 24; i++) {
        int entero;
        int total = 52 - i;
        entero = (rand() % total) + 1;
        pila->sacarPila(entero, carta);
        c1.agregarCola(carta);
    }
    for (int i = 0; i < 28; i++) {
        int entero;
        int total = 28 - i;
        entero = (rand() % total) + 1;
        pila->sacarPila(entero, carta);
        carta->setMostrando(true);
        switch (i) {
            case 0:
                pilas1[0].agregarPila(carta);
                break;
            case 1: carta->setMostrando(false);
            case 2:
                pilas1[1].agregarPila(carta);
                break;
            case 3: case 4: carta->setMostrando(false);
            case 5:
                pilas1[2].agregarPila(carta);
                break;
            case 6: case 7: case 8: carta->setMostrando(false);
            case 9:
                pilas1[3].agregarPila(carta);
                break;
            case 10: case 11: case 12: case 13: carta->setMostrando(false);
            case 14:
                pilas1[4].agregarPila(carta);
                break;
            case 15: case 16: case 17: case 18: case 19: carta->setMostrando(false);
            case 20:
                pilas1[5].agregarPila(carta);
                break;
            case 21: case 22: case 23: case 24: case 25: case 26: carta->setMostrando(false);
            case 27:
                pilas1[6].agregarPila(carta);
                break;
        }
    }
}

void Juego::Dibujar() {
    c1.setPosicion();
    c2.setPosicion();
    c1.setTerminado();
    c2.setTerminado();
    pilas1[0].setPosicion();
    pilas1[0].setPosicionCarta();
    pilas1[0].setTerminado();
    pilas1[1].setPosicion();
    pilas1[1].setPosicionCarta();
    pilas1[1].setTerminado();
    pilas1[2].setPosicion();
    pilas1[2].setPosicionCarta();
    pilas1[2].setTerminado();
    pilas1[3].setPosicion();
    pilas1[3].setPosicionCarta();
    pilas1[3].setTerminado();
    pilas1[4].setPosicion();
    pilas1[4].setPosicionCarta();
    pilas1[4].setTerminado();
    pilas1[5].setPosicion();
    pilas1[5].setPosicionCarta();
    pilas1[5].setTerminado();
    pilas1[6].setPosicion();
    pilas1[6].setPosicionCarta();
    pilas1[6].setTerminado();
    pilas2[0].setPosicion();
    pilas2[0].setPosicionCarta();
    pilas2[0].setTerminado();
    pilas2[1].setPosicion();
    pilas2[1].setPosicionCarta();
    pilas2[1].setTerminado();
    pilas2[2].setPosicion();
    pilas2[2].setPosicionCarta();
    pilas2[2].setTerminado();
    pilas2[3].setPosicion();
    pilas2[3].setPosicionCarta();
    pilas2[3].setTerminado();
    while (!c1.getTerminado() || !c2.getTerminado() || !pilas1[0].getTerminado() || !pilas1[1].getTerminado()
            || !pilas1[2].getTerminado() || !pilas1[3].getTerminado() || !pilas1[4].getTerminado() || !pilas1[5].getTerminado()
            || !pilas1[6].getTerminado() || !pilas2[0].getTerminado() || !pilas2[1].getTerminado() || !pilas2[2].getTerminado() || !pilas1[3].getTerminado()) {
        cout << "    " << c1.dibujar(1) << "    " << c2.dibujar(2) << "   |   " << pilas1[0].Dibujar() << "    " << pilas1[1].Dibujar() << "    " << pilas1[2].Dibujar()
                << "    " << pilas1[3].Dibujar() << "    " << pilas1[4].Dibujar() << "    " << pilas1[5].Dibujar() << "    " << pilas1[6].Dibujar()
                << "   |   " << pilas2[0].Dibujar() << "    " << pilas2[1].Dibujar() << "    " << pilas2[2].Dibujar() << "    " << pilas2[3].Dibujar() << endl;
    }
}

void Juego::hacerMovimiento() {
    cout << endl << endl << "que movimiento realizar?" << endl << "1) Mostrar Carta" << endl << "2) Mover Carta Descubierta" << endl << "3) Mover Cartas a otra Pila" << endl << "4) Mover Carta al Final" << endl << "5) Conocer Carta" << endl;
    cout << "6) Conocer Carta de Pilas (1-7)" << endl << "52) Rendirse" << endl;
    int decision;
    cin>>decision;
    Carta *carta;
    Carta *carta2;
    int objetivo1;
    int objetivo2;
    switch (decision) {
        case 1:
            if (c1.cantidad == 0 && c2.cantidad != 0) {
                while (c2.cantidad != 0) {
                    c2.sacarUltima(carta);
                    carta->setMostrando(false);
                    c1.agregarCola(carta);
                }
            }
            c1.sacarUltima(carta);
            carta->setMostrando(true);
            c2.agregarCola(carta);
            Dibujar();
            VerificarJuego();
            break;
        case 2:
            if (c2.cantidad > 0) {
                cout << "A que fila desea moverla? (1-7)" << endl;
                cin>>objetivo1;
                if (objetivo1 <= 7) {
                    c2.obtenerCola(1, carta);
                    pilas1[objetivo1 - 1].obtenerPila(1, carta2);
                    if (carta2 == NULL || (carta->getColor() != carta2->getColor() && carta->getNumero() == (carta2->getNumero() - 1))) {
                        if (carta2 != NULL || carta->getNumero() == 13) {
                            c2.sacarUltima(carta);
                            pilas1[objetivo1 - 1].agregarPila(carta);
                            Dibujar();
                        } else {
                            cout << "Movimiento invalido" << endl;
                        }
                    } else {
                        cout << "Movimiento invalido" << endl;
                    }
                } else {
                    cout << "No es una pila accesible" << endl;
                }
            } else {
                cout << "No hay carta descubierta" << endl;
            }
            VerificarJuego();
            break;
        case 3:
            Carta *ultima;
            int cantidad;
            cout << "De Que fila Desea Mover La Carta (1-7)" << endl;
            cin>>objetivo1;
            cout << "Numero de cartas" << endl;
            cin>>cantidad;
            cout << "A que fila Desea Moverlo? (1-7)" << endl;
            cin>>objetivo2;
            if (objetivo1 <= 7 && objetivo2 <= 7) {
                pilas1[objetivo1 - 1].obtenerPila(cantidad, carta);
                pilas1[objetivo2 - 1].obtenerPila(1, carta2);
                if ((carta2 == NULL && carta != NULL) || (carta != NULL && (carta->getColor() != carta2->getColor()) && (carta->getNumero() == carta2->getNumero() - 1))) {
                    if (carta->getMostrado() && (carta2 != NULL || carta->getNumero() == 13)) {
                        pilas1[objetivo1 - 1].sacarHilera(cantidad, carta, ultima);
                        pilas1[objetivo2 - 1].agregarHilera(carta, ultima);
                        Dibujar();
                    } else {
                        cout << "Movimiento invalido" << endl;
                    }
                } else {
                    cout << "Movimiento invalido" << endl;
                }
            } else {
                cout << "No es una pila accesible" << endl;
            }
            hacerMovimiento();
            break;
        case 4:
            cout << "De Que fila mover al final? (1-7)" << endl;
            cin>>objetivo1;
            Carta *anterior;
            pilas1[objetivo1 - 1].obtenerPila(1, carta);
            if (carta != NULL) {
                int valor = carta->getID();
                if (valor == 1) {
                    pilas2[0].obtenerPila(1, carta2);
                    if (carta2 == NULL && carta->getNumero() == 1) {
                        carta->getPrevius(anterior);
                        if (anterior != NULL) {
                            anterior->setMostrando(true);
                        }
                        pilas1[objetivo1 - 1].sacarPila(1, carta);
                        pilas2[0].agregarPila(carta);
                        Dibujar();
                    } else if (carta2 != NULL && carta->getNumero() == carta2->getNumero() + 1) {
                        carta->getPrevius(anterior);
                        if (anterior != NULL) {
                            anterior->setMostrando(true);
                        }
                        pilas1[objetivo1 - 1].sacarPila(1, carta);
                        pilas2[0].agregarPila(carta);
                        Dibujar();
                    } else {
                        cout << "Movimiento invalido" << endl;
                    }
                } else if (valor == 2) {
                    pilas2[1].obtenerPila(1, carta2);
                    if (carta2 == NULL && carta->getNumero() == 1) {
                        carta->getPrevius(anterior);
                        if (anterior != NULL) {
                            anterior->setMostrando(true);
                        }
                        pilas1[objetivo1 - 1].sacarPila(1, carta);
                        pilas2[1].agregarPila(carta);
                        Dibujar();
                    } else if (carta2 != NULL && carta->getNumero() == carta2->getNumero() + 1) {
                        carta->getPrevius(anterior);
                        if (anterior != NULL) {
                            anterior->setMostrando(true);
                        }
                        pilas1[objetivo1 - 1].sacarPila(1, carta);
                        pilas2[1].agregarPila(carta);
                        Dibujar();
                    } else {
                        cout << "Movimiento invalido" << endl;
                    }
                } else if (valor == 3) {
                    pilas2[2].obtenerPila(1, carta2);
                    if (carta2 == NULL && carta->getNumero() == 1) {
                        carta->getPrevius(anterior);
                        if (anterior != NULL) {
                            anterior->setMostrando(true);
                        }
                        pilas1[objetivo1 - 1].sacarPila(1, carta);
                        pilas2[2].agregarPila(carta);
                        Dibujar();
                    } else if (carta2 != NULL && carta->getNumero() == carta2->getNumero() + 1) {
                        carta->getPrevius(anterior);
                        if (anterior != NULL) {
                            anterior->setMostrando(true);
                        }
                        pilas1[objetivo1 - 1].sacarPila(1, carta);
                        pilas2[2].agregarPila(carta);
                        Dibujar();
                    } else {
                        cout << "Movimiento invalido" << endl;
                    }
                } else if (valor == 4) {
                    pilas2[3].obtenerPila(1, carta2);
                    if (carta2 == NULL && carta->getNumero() == 1) {
                        carta->getPrevius(anterior);
                        if (anterior != NULL) {
                            anterior->setMostrando(true);
                        }
                        pilas1[objetivo1 - 1].sacarPila(1, carta);
                        pilas2[3].agregarPila(carta);
                        Dibujar();
                    } else if (carta2 != NULL && carta->getNumero() == carta2->getNumero() + 1) {
                        carta->getPrevius(anterior);
                        if (anterior != NULL) {
                            anterior->setMostrando(true);
                        }
                        pilas1[objetivo1 - 1].sacarPila(1, carta);
                        pilas2[3].agregarPila(carta);
                        Dibujar();
                    } else {
                        cout << "Movimiento invalido" << endl;
                    }
                }
            } else {
                cout << "Pila Vacia";
            }
            hacerMovimiento();
            break;
        case 5:
            cout << "Que posicion quiere saber?" << endl;
            cin>>objetivo1;
            c1.obtenerCola(objetivo1, carta);
            cout << endl;
            hacerMovimiento();
            break;
        case 6:
            int pos;
            cout << "De que pila quiere saber?" << endl;
            cin >> objetivo1;
            cout << "Que posición?" << endl;
            cin >> pos;
            if (objetivo1 > 0 && objetivo1 < 8) {
                pilas1[objetivo1-1].obtenerPila(pos, carta);
                if (carta != NULL) {
                    cout << "En la posicion " << pos << " esta: " << carta->getValor() << " de " << carta->getTipo() << endl;
                } else {
                    cout << "No hay carta Disponible" << endl;
                }
            }
            hacerMovimiento();
            break;
        case 52:
            cout << "gracias por jugar esta partida!!";
            break;
        default:
            hacerMovimiento();
    }
}

bool Juego::VerificarJuego() {
    if (c1.cantidad == 0 && c2.cantidad == 0 && todasDescubiertas()) {
        cout << "FELICIDADES ACABA DE GANAR" << endl << "FELICIDADES ACABA DE GANAR" << endl << "FELICIDADES ACABA DE GANAR" << endl << "FELICIDADES ACABA DE GANAR" << endl << endl << endl;
        return true;
    } else {
        hacerMovimiento();
        return false;
    }

}

bool Juego::todasDescubiertas() {
    int entero = 1;
    bool f = true;
    Carta *verificar;
    for (int i = 0; i < 7; i++) {
        pilas1[i].obtenerPila(entero, verificar);
        while (verificar != NULL) {
            if (!verificar->getMostrado()) {
                f = false;
            }
            entero++;
            pilas1[i].obtenerPila(entero, verificar);
        }
        entero = 1;
    }
    return f;
}
/*
 * 
 */