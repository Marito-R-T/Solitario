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
}
/* Sentencia de clases de PILA */

void Pila::agregarPila(Carta *carta) {
    if (ultima == NULL) {
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
    if (numero > 0) {
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
            cout << "No hay carta en la posicion: " << numero << endl;
        }
    } else {
        carta = NULL;
        cout << "ERROR" << endl;
    }
}

void Pila::sacarPila() {
    if (ultima != NULL) {
        Carta *segunda;
        (*ultima).getPrevius(segunda);
        cout << ultima->getMostrado() << endl;
        ultima = segunda;
        ultima->setNext(NULL);
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

