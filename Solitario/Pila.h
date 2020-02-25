/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pila.h
 * Author: mari2bar
 *
 * Created on 24 de febrero de 2020, 23:02
 */

#ifndef PILA_H
#define PILA_H
#include "Carta.h"

class Pila {
public:
    
    virtual ~Pila();
    int cantidad;

    Pila() {
        cantidad = 0;
    };
    void agregarPila(Carta *);
    void sacarPila();
    void obtenerPila(int, Carta*&);
    void sacarPila(int, Carta *&);

    void setPosicion() {
        posicion = 1;
    };

    void setPosicionCarta() {
        poscarta = 0;
    };

    void setTerminado() {
        terminado = false;
    };

    bool getTerminado() {
        return terminado;
    };

    string Dibujar() {
        if (!terminado && cantidad != 0) {
            int cc = cantidad - poscarta;
            int tamcarta;
            Carta *_carta;
            Carta *_next;
            obtenerPila(cc, _carta);
            _carta->getNext(_next);
            if ((posicion % 4) == 0 && _next != NULL) {
                poscarta++;
                posicion = 1;
            }
            if ((posicion % 7) == 0 && _next == NULL) {
                terminado = true;
                tamcarta = 7;
            } else {
                tamcarta = posicion % 7;
            }
            posicion++;
            return _carta->dibujar(tamcarta);
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
    Carta *ultima;
    bool terminado;
    int posicion;
    int poscarta;
};

#endif /* PILA_H */

