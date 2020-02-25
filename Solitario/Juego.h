/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.h
 * Author: mari2bar
 *
 * Created on 24 de febrero de 2020, 23:06
 */

#ifndef JUEGO_H
#define JUEGO_H
#include "Pila.h"
#include "Cola.h"
#include "Carta.h"

class Juego {
public:
    virtual ~Juego();
    Juego(Pila *&);
    void Dibujar();
    void hacerMovimiento();
    void descubrirCola();
    void saberposCola();
    void MoverCarta();
    void MoverColaPila();
    void MoverPilaFinal();
private:
    Cola c1 = Cola();
    Cola c2 = Cola();
    Pila p1 = Pila();
    Pila p2 = Pila();
    Pila p3 = Pila();
    Pila p4 = Pila();
    Pila p5 = Pila();
    Pila p6 = Pila();
    Pila p7 = Pila();
    Pila p8 = Pila();
    Pila p9 = Pila();
    Pila p10 = Pila();
    Pila p11 = Pila();
};

#endif /* JUEGO_H */

