/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carta.h
 * Author: mari2bar
 *
 * Created on 24 de febrero de 2020, 22:35
 */

#ifndef CARTA_H
#define CARTA_H
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include "Carta.h"

using namespace std;

class Carta {
public:
    virtual ~Carta();
    Carta(int, string, string, bool, int, int);

    bool getMostrado() {
        return mostrando;
    };

    string getTipo() {
        return tipo;
    };

    string getValor() {
        return valor;
    };

    int getColor() {
        return color;
    };

    void mostrarCaracteristicas() {

    };

    void setMostrando(bool _mostrando) {
        mostrando = _mostrando;
    };

    string dibujar(int numero) {
        if (mostrando == true) {
            if (numero == 1 || numero == 7) {
                return "----------";
            } else if (numero == 2) {
                if (valor != "10") {
                    return "|" + valor + "     " + tipo + " |";
                } else {
                    return "|" + valor + "    " + tipo + " |";
                }
            } else if (numero == 6) {
                if (valor != "10") {
                    return "|" + tipo + "      " + valor + "|";
                } else {
                    return "|" + tipo + "     " + valor + "|";
                }
            } else if (numero == 4) {
                return "|   " + tipo + "    |";
            } else if (numero == 3 || numero == 5) {
                return "|        |";
            }
        } else {
            if (numero == 1 || numero == 7) {
                return "----------";
            } else {
                return "|////////|";
            }
        }
    }

    int getID() {
        return id;
    }

    void getNext(Carta *&next) {
        next = delantera;
    }

    void getPrevius(Carta *&previus) {
        previus = trasera;
    }

    void setNext(Carta *next) {
        delantera = next;
    }

    void setPrevius(Carta *previus) {
        trasera = previus;
    }

    int getNumero() {
        return numero;
    };
private:
    int color;
    int numero;
    int id;
    string tipo;
    string valor;
    bool mostrando;
    Carta *trasera;
    Carta *delantera;
};

#endif /* CARTA_H */

