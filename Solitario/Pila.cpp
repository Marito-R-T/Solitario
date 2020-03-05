/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pila.cpp
 * Author: mari2bar
 * 
 * Created on 24 de febrero de 2020, 23:02
 */

#include "Pila.h"
#include "Carta.h"

Pila::~Pila() {
    for(int i =0; i<cantidad; i++){
        Carta *carta;
        sacarPila(1, carta);
        if(carta != NULL){
            carta->~Carta();
        }
    }
}

/* Sentencia de clases de PILA */

void Pila::agregarPila(Carta *carta) {
    if (cantidad == 0) {
        ultima = carta;
        ultima->setNext(NULL);
        ultima->setPrevius(NULL);
    } else {
        Carta *segunda = ultima;
        segunda->setNext(carta);
        carta->setPrevius(segunda);
        carta->setNext(NULL);
        ultima = carta;
    }
    cantidad++;
}

void Pila::obtenerPila(int numero, Carta *&carta) {
    if (numero > 0 && numero<=cantidad) {
        Carta *siguiente = ultima;
        for (int i = 0; i < numero - 1; i++) {
            siguiente->getPrevius(siguiente);
            if (siguiente == NULL) {
                break;
            }
        }
        if (siguiente != NULL) {
            carta = siguiente;
        } else {
            carta = NULL;
        }
    } else {
        carta = NULL;
    }
}

void Pila::agregarHilera(Carta *&carta, Carta *&_ultima) {
    if (cantidad == 0) {
        Carta *siguiente = carta;
        Carta *siguiente2 = carta;
        siguiente2->getNext(siguiente2);
        cantidad++;
        while (siguiente2 != NULL) {
            siguiente2->getNext(siguiente2);
            siguiente->getNext(siguiente);
            cantidad++;
        }
        ultima = siguiente;
    } else {
        Carta *standbye = carta;
        Carta *siguiente = carta;
        Carta *siguiente2 = carta;
        siguiente2->getNext(siguiente2);
        cantidad++;
        while (siguiente2 != NULL) {
            siguiente2->getNext(siguiente2);
            siguiente->getNext(siguiente);
            cantidad++;
        }
        ultima->setNext(standbye);
        standbye->setPrevius(ultima);
        ultima = siguiente;
    }
}

void Pila::sacarHilera(int numero, Carta *&carta, Carta *&_ultima) {
    if (numero > 0) {
        Carta *siguiente = ultima;
        _ultima = ultima;
        Carta *_penultima;
        for (int i = 0; i < numero - 1; i++) {
            siguiente->getPrevius(siguiente);
            if (siguiente == NULL) {
                break;
            }
        }
        if (siguiente != NULL) {
            siguiente->getPrevius(_penultima);
            if (_penultima != NULL) {
                ultima = _penultima;
                ultima->setNext(NULL);
                if (!ultima->getMostrado()) {
                    ultima->setMostrando(true);
                }
            } else {
                ultima = NULL;
            }
            carta = siguiente;
            carta->setPrevius(NULL);
            cantidad -= numero;
        } else {
            carta = NULL;
            _ultima = NULL;
        }
    } else {
        carta = NULL;
        _ultima = NULL;
        cout << "ERROR" << endl;
    }
}

void Pila::sacarPila() {
    if (ultima != NULL) {
        Carta *segunda;
        ultima->getPrevius(segunda);
        ultima = segunda;
        ultima->setPrevius(NULL);
        cantidad--;
    } else {
        cout << "no hay nada" << endl;
    }
}

void Pila::sacarPila(int numero, Carta *&carta) {
    if (numero > 0) {
        Carta *siguiente = ultima;
        for (int i = 0; i < numero - 1; i++) {
            siguiente->getPrevius(siguiente);
            if (siguiente == NULL) {
                break;
            }
        }
        if (siguiente != NULL) {
            Carta *next;
            Carta *previus;
            siguiente->getNext(next);
            siguiente->getPrevius(previus);
            if (next != NULL) {
                next->setPrevius(previus);
            }
            if (previus != NULL) {
                previus->setNext(next);
            }
            if (siguiente == ultima) {
                ultima = previus;
            }
            siguiente->setNext(NULL);
            siguiente->setPrevius(NULL);
            carta = siguiente;
            cantidad--;
        } else {
            cout << "No hay carta en la posicion: " << numero << endl;
        }
    } else {
        cout << "ERROR" << endl;
    }
}

