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


Cola::~Cola() {
}
/* Sentencia de clases de COLA */

void Cola::agregarCola(Carta *carta) {
    if (primera == NULL) {
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

void Cola::obtenerCola(int numero) {
    if (numero > 0) {
        Carta *siguiente = primera;
        for (int i = 0; i < numero - 1; i++) {
            siguiente->getPrevius(siguiente);
            if (siguiente == NULL) {
                break;
            }
        }
        if (siguiente != NULL) {
            cout << siguiente->getMostrado() << endl;
        } else {
            cout << "No hay carta en la posicion: " << numero << endl;
        }
    } else {
        cout << "ERROR" << endl;
    }
}

void Cola::sacarCola() {
    if (primera != NULL) {
        Carta *segunda;
        primera->getPrevius(segunda);
        cout << primera->getMostrado() << endl;
        primera->setPrevius(NULL);
        if (segunda != NULL) {
            segunda->setNext(NULL);
            primera = segunda;
        } else {
            ultima = NULL;
        }
        cantidad--;
    } else {
        cout << "no hay nada" << endl;
    }
}
