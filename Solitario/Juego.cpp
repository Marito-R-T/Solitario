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

Juego::~Juego() {
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
                p1.agregarPila(carta);
                break;
            case 1: carta->setMostrando(false);
            case 2:
                p2.agregarPila(carta);
                break;
            case 3: case 4: carta->setMostrando(false);
            case 5:
                p3.agregarPila(carta);
                break;
            case 6: case 7: case 8: carta->setMostrando(false);
            case 9:
                p4.agregarPila(carta);
                break;
            case 10: case 11: case 12: case 13: carta->setMostrando(false);
            case 14:
                p5.agregarPila(carta);
                break;
            case 15: case 16: case 17: case 18: case 19: carta->setMostrando(false);
            case 20:
                p6.agregarPila(carta);
                break;
            case 21: case 22: case 23: case 24: case 25: case 26: carta->setMostrando(false);
            case 27:
                p7.agregarPila(carta);
                break;
        }
    }
}

void Juego::Dibujar() {
    c1.setPosicion();
    c2.setPosicion();
    c1.setTerminado();
    c2.setTerminado();
    p1.setPosicion();
    p1.setPosicionCarta();
    p1.setTerminado();
    p2.setPosicion();
    p2.setPosicionCarta();
    p2.setTerminado();
    p3.setPosicion();
    p3.setPosicionCarta();
    p3.setTerminado();
    p4.setPosicion();
    p4.setPosicionCarta();
    p4.setTerminado();
    p5.setPosicion();
    p5.setPosicionCarta();
    p5.setTerminado();
    p6.setPosicion();
    p6.setPosicionCarta();
    p6.setTerminado();
    p7.setPosicion();
    p7.setPosicionCarta();
    p7.setTerminado();
    p8.setPosicion();
    p8.setPosicionCarta();
    p8.setTerminado();
    p9.setPosicion();
    p9.setPosicionCarta();
    p9.setTerminado();
    p10.setPosicion();
    p10.setPosicionCarta();
    p10.setTerminado();
    p11.setPosicion();
    p11.setPosicionCarta();
    p11.setTerminado();
    while (!c1.getTerminado() || !c2.getTerminado() || !p1.getTerminado() || !p2.getTerminado()
            || !p3.getTerminado() || !p4.getTerminado() || !p5.getTerminado() || !p6.getTerminado()
            || !p7.getTerminado() || !p8.getTerminado() || !p9.getTerminado() || !p10.getTerminado() || !p11.getTerminado()) {
        cout << "    " << c1.dibujar(1) << "    " << c2.dibujar(2) << "   |   " << p1.Dibujar() << "    " << p2.Dibujar() << "    " << p3.Dibujar()
                << "    " << p4.Dibujar() << "    " << p5.Dibujar() << "    " << p6.Dibujar() << "    " << p7.Dibujar()
                << "   |   " << p8.Dibujar() << "    " << p9.Dibujar() << "    " << p10.Dibujar() << "    " << p11.Dibujar() << endl;
    }
}


void Juego::hacerMovimiento(){
    
}
/*
 * 
 */