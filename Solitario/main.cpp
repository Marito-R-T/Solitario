/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mari2bar
 *
 * Created on 20 de febrero de 2020, 22:49
 */

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <random>


using namespace std;

/*Inicio de Clases: */
class Carta {
private: //Atributos
    int color;
    string tipo;
    string valor;
    bool mostrando;
    Carta *trasera;
    Carta *delantera;
public: // Metodos
    Carta(int, string, string, bool);

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
    
    void setMostrando(bool _mostrando){
        mostrando=_mostrando;
    };

    string dibujar(int numero) {
        if (mostrando == true) {
            if (numero == 1 || numero == 7) {
                return "----------";
            } else if (numero == 2) {
                if (valor != "10") {
                    return "|" + valor + "     " + tipo + "|";
                } else {
                    return "|" + valor + "    " + tipo + "|";
                }
            } else if (numero == 6) {
                if (valor != "10") {
                    return "|" + tipo + "     " + valor + "|";
                } else {
                    return "|" + tipo + "    " + valor + "|";
                }
            } else if (numero == 4) {
                return "|   " + tipo + "   |";
            }else if(numero==3 || numero == 5){
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
};

class Pila {
private:
    Carta *ultima;
    bool terminado;
    int posicion;
    int poscarta;
public:
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
};

class Cola {
private:
    Carta *primera;
    Carta *ultima;
    int posicion;
    bool terminado;
public:
    int cantidad;

    Cola() {
        cantidad = 0;
    };
    void agregarCola(Carta *);
    void sacarCola();
    void obtenerCola(int);

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
                dibujo = primera->dibujar(posicion);
                posicion++;
                return dibujo;
            } else {
                dibujo = primera->dibujar(posicion);
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
};

class Juego {
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
public:
    Juego(Pila *&);
    void Dibujar();
};

/* Inicio de metodos de clases: */

/* Sentencia de clases de CARTA */
Carta::Carta(int _color, string _tipo, string _valor, bool _mostrando) {
    color = _color;
    tipo = _tipo;
    valor = _valor;
    mostrando = _mostrando;
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

/* JUEGO  */

Juego::Juego(Pila *&pila) {
    cout<<endl<<endl;
    srand((int) time(0));
    Carta *carta;
    for (int i = 0; i < 24; i++) {
        int entero;
        int total = 52 - i;
        entero = (rand() % total) + 1;
        pila->sacarPila(entero, carta);
        c1.agregarCola(carta);
    }
    for (int i = 0; i < 28; i++) {
        int entero;
        int total = 28 - i;
        entero = (rand() % total) + 1;
        pila->sacarPila(entero, carta);
        carta->setMostrando(true);
        switch (i) {
            case 0:
                p1.agregarPila(carta);
                break;
            case 1: carta->setMostrando(false); case 2:
                p2.agregarPila(carta);
                break;
            case 3: case 4: carta->setMostrando(false); case 5:
                p3.agregarPila(carta);
                break;
            case 6: case 7: case 8: carta->setMostrando(false); case 9:
                p4.agregarPila(carta);
                break;
            case 10: case 11: case 12: case 13: carta->setMostrando(false); case 14:
                p5.agregarPila(carta);
                break;
            case 15: case 16: case 17: case 18: case 19: carta->setMostrando(false); case 20:
                p6.agregarPila(carta);
                break;
            case 21: case 22: case 23: case 24: case 25: case 26: carta->setMostrando(false); case 27:
                p7.agregarPila(carta);
                break;
        }
    }
}

void Juego::Dibujar() {
    c1.setPosicion();
    c2.setPosicion();
    c1.setTerminado();
    c2.setTerminado();
    p1.setPosicion();
    p1.setPosicionCarta();
    p1.setTerminado();
    p2.setPosicion();
    p2.setPosicionCarta();
    p2.setTerminado();
    p3.setPosicion();
    p3.setPosicionCarta();
    p3.setTerminado();
    p4.setPosicion();
    p4.setPosicionCarta();
    p4.setTerminado();
    p5.setPosicion();
    p5.setPosicionCarta();
    p5.setTerminado();
    p6.setPosicion();
    p6.setPosicionCarta();
    p6.setTerminado();
    p7.setPosicion();
    p7.setPosicionCarta();
    p7.setTerminado();
    p8.setPosicion();
    p8.setPosicionCarta();
    p8.setTerminado();
    p9.setPosicion();
    p9.setPosicionCarta();
    p9.setTerminado();
    p10.setPosicion();
    p10.setPosicionCarta();
    p10.setTerminado();
    p11.setPosicion();
    p11.setPosicionCarta();
    p11.setTerminado();
    while (!c1.getTerminado() || !c2.getTerminado() || !p1.getTerminado() || !p2.getTerminado()
            || !p3.getTerminado() || !p4.getTerminado() || !p5.getTerminado() || !p6.getTerminado()
            || !p7.getTerminado() || !p8.getTerminado() || !p9.getTerminado() || !p10.getTerminado() || !p11.getTerminado()) {
        cout << "    " << c1.dibujar(1) << "    " << c2.dibujar(2) << "    " << p1.Dibujar() << "    " << p2.Dibujar() << "    " << p3.Dibujar()
                << "    " << p4.Dibujar() << "    " << p5.Dibujar() << "    " << p6.Dibujar() << "    " << p7.Dibujar()
                << "    " << p8.Dibujar() << "    " << p9.Dibujar() << "    " << p10.Dibujar() << "    " << p11.Dibujar() << endl;
    }
}

/*
 * 
 */
int main() {
    /* Picas */
    Pila pila = Pila();
    Pila *_pila = &pila;
    Carta carta1 = Carta(1, "♠", "A", false);
    pila.agregarPila(&carta1);
    Carta carta2 = Carta(1, "♠", "2", false);
    pila.agregarPila(&carta2);
    Carta carta3 = Carta(1, "♠", "3", false);
    pila.agregarPila(&carta3);
    Carta carta4 = Carta(1, "♠", "4", false);
    pila.agregarPila(&carta4);
    Carta carta5 = Carta(1, "♠", "5", false);
    pila.agregarPila(&carta5);
    Carta carta6 = Carta(1, "♠", "6", false);
    pila.agregarPila(&carta6);
    Carta carta7 = Carta(1, "♠", "7", false);
    pila.agregarPila(&carta7);
    Carta carta8 = Carta(1, "♠", "8", false);
    pila.agregarPila(&carta8);
    Carta carta9 = Carta(1, "♠", "9", false);
    pila.agregarPila(&carta9);
    Carta carta10 = Carta(1, "♠", "10", false);
    pila.agregarPila(&carta10);
    Carta carta11 = Carta(1, "♠", "J", false);
    pila.agregarPila(&carta11);
    Carta carta12 = Carta(1, "♠", "Q", false);
    pila.agregarPila(&carta12);
    Carta carta13 = Carta(1, "♠", "K", false);
    pila.agregarPila(&carta13);

    /* Treboles */
    Carta carta14 = Carta(1, "♣", "A", false);
    pila.agregarPila(&carta14);
    Carta carta15 = Carta(1, "♣", "2", false);
    pila.agregarPila(&carta15);
    Carta carta16 = Carta(1, "♣", "3", false);
    pila.agregarPila(&carta16);
    Carta carta17 = Carta(1, "♣", "4", false);
    pila.agregarPila(&carta17);
    Carta carta18 = Carta(1, "♣", "5", false);
    pila.agregarPila(&carta18);
    Carta carta19 = Carta(1, "♣", "6", false);
    pila.agregarPila(&carta19);
    Carta carta20 = Carta(1, "♣", "7", false);
    pila.agregarPila(&carta20);
    Carta carta21 = Carta(1, "♣", "8", false);
    pila.agregarPila(&carta21);
    Carta carta22 = Carta(1, "♣", "9", false);
    pila.agregarPila(&carta22);
    Carta carta23 = Carta(1, "♣", "10", false);
    pila.agregarPila(&carta23);
    Carta carta24 = Carta(1, "♣", "J", false);
    pila.agregarPila(&carta24);
    Carta carta25 = Carta(1, "♣", "Q", false);
    pila.agregarPila(&carta25);
    Carta carta26 = Carta(1, "♣", "K", false);
    pila.agregarPila(&carta26);

    /* Diamantes */
    Carta carta27 = Carta(0, "♦", "A", false);
    pila.agregarPila(&carta27);
    Carta carta28 = Carta(0, "♦", "2", false);
    pila.agregarPila(&carta28);
    Carta carta29 = Carta(0, "♦", "3", false);
    pila.agregarPila(&carta29);
    Carta carta30 = Carta(0, "♦", "4", false);
    pila.agregarPila(&carta30);
    Carta carta31 = Carta(0, "♦", "5", false);
    pila.agregarPila(&carta31);
    Carta carta32 = Carta(0, "♦", "6", false);
    pila.agregarPila(&carta32);
    Carta carta33 = Carta(0, "♦", "7", false);
    pila.agregarPila(&carta33);
    Carta carta34 = Carta(0, "♦", "8", false);
    pila.agregarPila(&carta34);
    Carta carta35 = Carta(0, "♦", "9", false);
    pila.agregarPila(&carta35);
    Carta carta36 = Carta(0, "♦", "10", false);
    pila.agregarPila(&carta36);
    Carta carta37 = Carta(0, "♦", "J", false);
    pila.agregarPila(&carta37);
    Carta carta38 = Carta(0, "♦", "Q", false);
    pila.agregarPila(&carta38);
    Carta carta39 = Carta(0, "♦", "K", false);
    pila.agregarPila(&carta39);

    /* Corazon */
    Carta carta40 = Carta(0, "♥", "A", false);
    pila.agregarPila(&carta40);
    Carta carta41 = Carta(0, "♥", "2", false);
    pila.agregarPila(&carta41);
    Carta carta42 = Carta(0, "♥", "3", false);
    pila.agregarPila(&carta42);
    Carta carta43 = Carta(0, "♥", "4", false);
    pila.agregarPila(&carta43);
    Carta carta44 = Carta(0, "♥", "5", false);
    pila.agregarPila(&carta44);
    Carta carta45 = Carta(0, "♥", "6", false);
    pila.agregarPila(&carta45);
    Carta carta46 = Carta(0, "♥", "7", false);
    pila.agregarPila(&carta46);
    Carta carta47 = Carta(0, "♥", "8", false);
    pila.agregarPila(&carta47);
    Carta carta48 = Carta(0, "♥", "9", false);
    pila.agregarPila(&carta48);
    Carta carta49 = Carta(0, "♥", "10", false);
    pila.agregarPila(&carta49);
    Carta carta50 = Carta(0, "♥", "J", false);
    pila.agregarPila(&carta50);
    Carta carta51 = Carta(0, "♥", "Q", false);
    pila.agregarPila(&carta51);
    Carta carta52 = Carta(0, "♥", "K", false);
    pila.agregarPila(&carta52);
    Juego juego = Juego(_pila);
    juego.Dibujar();
    return 0;
}