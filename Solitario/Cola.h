/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.h
 * Author: mari2bar
 *
 * Created on 24 de febrero de 2020, 22:43
 */

#ifndef COLA_H
#define COLA_H
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "Carta.h"

using namespace std;

class Cola {
public:

    Cola() {
        cantidad = 0;
    };

    virtual ~Cola();
    int cantidad;
    void agregarCola(Carta *);
    void sacarCola(Carta *&);
    void sacarUltima(Carta *&);
    void obtenerCola(int, Carta *&);

    void setTerminado() {
        terminado = false;
    };

    bool getTerminado() {
        return terminado;
    };

    void setPosicion() {
        posicion = 1;
    };

    string dibujar(int numero) {
        if (posicion <= 7 && cantidad != 0) {
            string dibujo;
            if (numero == 1) {
                dibujo = ultima->dibujar(posicion);
                posicion++;
                return dibujo;
            } else {
                dibujo = ultima->dibujar(posicion);
                posicion++;
                return dibujo;
            }
        } else {
            terminado = true;
            if (posicion == 1 || posicion == 7) {
                posicion++;
                return "----------";
            } else if (posicion >= 2 && posicion <= 6) {
                posicion++;
                return "|        |";
            } else {
                return "          ";
            }
        }
    }
private:
    Carta *primera;
    Carta *ultima;
    int posicion;
    bool terminado;
};

#endif /* COLA_H */

