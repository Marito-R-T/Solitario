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
#include "stdlib.h"

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
    bool VerificarJuego();
    bool todasDescubiertas();
private:
    Cola c1 = Cola();
    Cola c2 = Cola();
    Pila pilas1[7];
    Pila pilas2[4];
};

#endif /* JUEGO_H */

