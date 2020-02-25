/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carta.cpp
 * Author: mari2bar
 * 
 * Created on 24 de febrero de 2020, 22:35
 */

#include "Carta.h"
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <random>

Carta::~Carta() {
}

Carta::Carta(int _color, string _tipo, string _valor, bool _mostrando) {
    color = _color;
    tipo = _tipo;
    valor = _valor;
    mostrando = _mostrando;
}