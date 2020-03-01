/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.cpp
 * Author: mari2bar
 * 
 * Created on 24 de febrero de 2020, 22:43
 */

#include "Cola.h"
#include "Carta.h"

using namespace std;

Cola::~Cola() {
}
/* Sentencia de clases de COLA */

void Cola::agregarCola(Carta *carta) {
    if (cantidad==0) {
        primera = carta;
        primera->setNext(NULL);
        primera->setPrevius(NULL);
        ultima = carta;
        ultima->setNext(NULL);
        ultima->setPrevius(NULL);
    } else {
        if (ultima == primera) {
            carta->setNext(primera);
            carta->setPrevius(NULL);
            primera->setPrevius(carta);
            ultima = carta;
        } else {
            carta->setNext(ultima);
            carta->setPrevius(NULL);
            ultima->setPrevius(carta);
            ultima = carta;
        }
    }
    cantidad++;
}

void Cola::obtenerCola(int numero, Carta *&carta) {
    if (numero > 0) {
        Carta *siguiente = ultima;
        for (int i = 0; i < numero - 1; i++) {
            siguiente->getNext(siguiente);
            if (siguiente == NULL) {
                break;
            }
        }
        if (siguiente != NULL) {
            carta=siguiente;
            cout << "En la posicion " << numero << " esta: " << siguiente->getValor() << " de " << siguiente->getTipo() << endl;
        } else {
            carta = NULL;
            cout << "No hay carta en la posicion: " << numero << endl;
        }
    } else {
        carta = NULL;
        cout << "ERROR" << endl;
    }
}

void Cola::sacarCola(Carta *&carta) {
    if (primera != NULL) {
        carta = primera;
        Carta *segunda;
        primera->getPrevius(segunda);
        primera->setPrevius(NULL);
        if (segunda != NULL) {
            segunda->setNext(NULL);
            primera = segunda;
        } else {
            ultima = NULL;
            primera = NULL;
        }
        cantidad--;
    } else {
        cout << "no hay nada" << endl;
    }
}

void Cola::sacarUltima(Carta *&carta) {
    if (cantidad != 0) {
        carta = ultima;
        Carta *pen;
        ultima->getNext(pen);
        ultima->setNext(NULL);
        if (pen != NULL) {
            pen->setPrevius(NULL);
            ultima = pen;
        } else {
            ultima = NULL;
            primera = NULL;
        }
        cantidad--;
        
    } else {
        carta = NULL;
        cout << "no hay nada" << endl;
    }
}
