/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mari2bar
 *
 * Created on 20 de febrero de 2020, 22:49
 */

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include "Carta.h"
#include "Cola.h"
#include "Pila.h"
#include "Juego.h"

using namespace std;

/*
 * 
 */
void empilarCartasAleatorias(Pila *&_pila) {
}

void empezarPilaCartas() {
    Pila pila = Pila();
    Pila *_pila = &pila;
    /* Picas */
    Carta carta1 = Carta(1, "♠", "A", false,1,1);
    pila.agregarPila(&carta1);
    Carta carta2 = Carta(1, "♠", "2", false,2,1);
    pila.agregarPila(&carta2);
    Carta carta3 = Carta(1, "♠", "3", false, 3,1);
    pila.agregarPila(&carta3);
    Carta carta4 = Carta(1, "♠", "4", false,4,1);
    pila.agregarPila(&carta4);
    Carta carta5 = Carta(1, "♠", "5", false,5,1);
    pila.agregarPila(&carta5);
    Carta carta6 = Carta(1, "♠", "6", false,6,1);
    pila.agregarPila(&carta6);
    Carta carta7 = Carta(1, "♠", "7", false,7,1);
    pila.agregarPila(&carta7);
    Carta carta8 = Carta(1, "♠", "8", false,8,1);
    pila.agregarPila(&carta8);
    Carta carta9 = Carta(1, "♠", "9", false,9,1);
    pila.agregarPila(&carta9);
    Carta carta10 = Carta(1, "♠", "10", false,10,1);
    pila.agregarPila(&carta10);
    Carta carta11 = Carta(1, "♠", "J", false,11,1);
    pila.agregarPila(&carta11);
    Carta carta12 = Carta(1, "♠", "Q", false,12,1);
    pila.agregarPila(&carta12);
    Carta carta13 = Carta(1, "♠", "K", false,13,1);
    pila.agregarPila(&carta13);

    /* Treboles */
    Carta carta14 = Carta(1, "♣", "A", false,1,2);
    pila.agregarPila(&carta14);
    Carta carta15 = Carta(1, "♣", "2", false,2,2);
    pila.agregarPila(&carta15);
    Carta carta16 = Carta(1, "♣", "3", false,3,2);
    pila.agregarPila(&carta16);
    Carta carta17 = Carta(1, "♣", "4", false,4,2);
    pila.agregarPila(&carta17);
    Carta carta18 = Carta(1, "♣", "5", false,5,2);
    pila.agregarPila(&carta18);
    Carta carta19 = Carta(1, "♣", "6", false,6,2);
    pila.agregarPila(&carta19);
    Carta carta20 = Carta(1, "♣", "7", false,7,2);
    pila.agregarPila(&carta20);
    Carta carta21 = Carta(1, "♣", "8", false,8,2);
    pila.agregarPila(&carta21);
    Carta carta22 = Carta(1, "♣", "9", false,9,2);
    pila.agregarPila(&carta22);
    Carta carta23 = Carta(1, "♣", "10", false,10,2);
    pila.agregarPila(&carta23);
    Carta carta24 = Carta(1, "♣", "J", false,11,2);
    pila.agregarPila(&carta24);
    Carta carta25 = Carta(1, "♣", "Q", false,12,2);
    pila.agregarPila(&carta25);
    Carta carta26 = Carta(1, "♣", "K", false,13,2);
    pila.agregarPila(&carta26);

    /* Diamantes */
    Carta carta27 = Carta(0, "♦", "A", false,1,3);
    pila.agregarPila(&carta27);
    Carta carta28 = Carta(0, "♦", "2", false,2,3);
    pila.agregarPila(&carta28);
    Carta carta29 = Carta(0, "♦", "3", false,3,3);
    pila.agregarPila(&carta29);
    Carta carta30 = Carta(0, "♦", "4", false,4,3);
    pila.agregarPila(&carta30);
    Carta carta31 = Carta(0, "♦", "5", false,5,3);
    pila.agregarPila(&carta31);
    Carta carta32 = Carta(0, "♦", "6", false,6,3);
    pila.agregarPila(&carta32);
    Carta carta33 = Carta(0, "♦", "7", false,7,3);
    pila.agregarPila(&carta33);
    Carta carta34 = Carta(0, "♦", "8", false,8,3);
    pila.agregarPila(&carta34);
    Carta carta35 = Carta(0, "♦", "9", false,9,3);
    pila.agregarPila(&carta35);
    Carta carta36 = Carta(0, "♦", "10", false,10,3);
    pila.agregarPila(&carta36);
    Carta carta37 = Carta(0, "♦", "J", false,11,3);
    pila.agregarPila(&carta37);
    Carta carta38 = Carta(0, "♦", "Q", false,12,3);
    pila.agregarPila(&carta38);
    Carta carta39 = Carta(0, "♦", "K", false,13,3);
    pila.agregarPila(&carta39);

    /* Corazon */
    Carta carta40 = Carta(0, "♥", "A", false,1,4);
    pila.agregarPila(&carta40);
    Carta carta41 = Carta(0, "♥", "2", false,2,4);
    pila.agregarPila(&carta41);
    Carta carta42 = Carta(0, "♥", "3", false,3,4);
    pila.agregarPila(&carta42);
    Carta carta43 = Carta(0, "♥", "4", false,4,4);
    pila.agregarPila(&carta43);
    Carta carta44 = Carta(0, "♥", "5", false,5,4);
    pila.agregarPila(&carta44);
    Carta carta45 = Carta(0, "♥", "6", false,6,4);
    pila.agregarPila(&carta45);
    Carta carta46 = Carta(0, "♥", "7", false,7,4);
    pila.agregarPila(&carta46);
    Carta carta47 = Carta(0, "♥", "8", false,8,4);
    pila.agregarPila(&carta47);
    Carta carta48 = Carta(0, "♥", "9", false,9,4);
    pila.agregarPila(&carta48);
    Carta carta49 = Carta(0, "♥", "10", false,10,4);
    pila.agregarPila(&carta49);
    Carta carta50 = Carta(0, "♥", "J", false,11,4);
    pila.agregarPila(&carta50);
    Carta carta51 = Carta(0, "♥", "Q", false,12,4);
    pila.agregarPila(&carta51);
    Carta carta52 = Carta(0, "♥", "K", false,13,4);
    pila.agregarPila(&carta52);
    cout << " Bienvenido a SOLITARIO: ";
    Juego *juego;
    string seguir;
    cout << endl << endl << " 1.- jugar" << endl << "2.- salir" << endl;
    cin>>seguir;
    if (seguir == "1") {
        empilarCartasAleatorias(_pila);
        juego = new Juego(_pila);
        juego->Dibujar();
        juego->hacerMovimiento();
        juego->~Juego();
        empezarPilaCartas();
    }else if(seguir=="2"){
        cout<<"Feliz Día"<<endl;
    }else{
        empezarPilaCartas();
    }
}

int main() {
    empezarPilaCartas();
    return 0;
}
