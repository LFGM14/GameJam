#include "pch.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace System;
using namespace std;

const int SCREEN_WIDTH = 110;
const int SCREEN_HEIGHT = 50;

void setxy(float x, int y) {
    Console::SetCursorPosition(x, y);
}

float aleatorio() {
    return ((float)rand() / RAND_MAX);
}

void Dibujar_horario(int a, int b, int espera) {
    for (int i = a; i <= SCREEN_WIDTH; i++) {
        setxy(i, b);
        cout << (char)219;
        _sleep(espera);
    }
    for (int i = b; i <= SCREEN_HEIGHT; i++) {
        setxy(SCREEN_WIDTH, i);
        cout << (char)219;
        _sleep(espera);
    }
    for (int i = SCREEN_WIDTH; i >= a; i--) {
        setxy(i, SCREEN_HEIGHT);
        cout << (char)219;
        _sleep(espera);
    }
    for (int i = SCREEN_HEIGHT; i >= b; i--) {
        setxy(a, i);
        cout << (char)219;
        _sleep(espera);
    }
}

void startScreen() {
    Dibujar_horario(0, 0, 10);
    setxy(35, 10);
    cout << "Marte pero imagina que es Marte";
    setxy(25, 13);
    cout << "Instrucciones: ";
    setxy(25, 15);
    cout << "-Recolecta las 4 muestras de tierra marciana.";
    setxy(25, 17);
    cout << "-No choques con los asteroides. Si lo haces, perderás automáticamente.";
    setxy(25, 19);
    cout << "-Tendrás naves de velocidades distintas dependiendo de tu partida,";
    setxy(25, 21);
    cout << "utiliza tu velocidad a tu ventaja.";
    system("pause>0");
    system("cls");
}

void credits() {
    Dibujar_horario(0, 0, 0);
    setxy(35, 10);
    cout << "Proyecto hecho por: ";
    setxy(25, 13);
    cout << "-Stephanie Vásquez Zamora";
    setxy(25, 17);
    cout << "-Luis Gonzales Matute";
    system("pause>0");
    system("cls");
}

void delShip(float& x, int& y) {
    setxy(x, y);
    cout << "            ";
    setxy(x, y + 1);
    cout << "            ";
}

void shipMovement(float& x, int& y) {
    if (_kbhit()) {
        char c = _getch();
        delShip(x, y);
        if (c == 'a' || c == 'A') {
            if (x > 0) {
                x--;
            }
        }
        if (c == 'd' || c == 'D') {
            if (x < SCREEN_WIDTH - 13) {
                x++;
            }
        }
        if (c == 's' || c == 'S') {
            if (y < SCREEN_HEIGHT - 2) {
                y++;
            }
        }
        if (c == 'w' || c == 'W') {
            if (y > 0) {
                y--;
            }
        }
    }
}

void shipDrawing(float& x, int& y) {
    setxy(x, y);
    cout << "   __|__";
    setxy(x, y + 1);
    cout << "*---o0o---*";
    shipMovement(x, y);
}

void delAst(float& x, int& y) {
    setxy(x, y);
    cout << "      ";
    setxy(x, y + 1);
    cout << "      ";
    setxy(x, y + 2);
    cout << "      ";
    setxy(x, y + 3);
    cout << "      ";
}

void astStatic(float& x, int& y) {
    setxy(x, y);
    cout << " *** ";
    setxy(x, y + 1);
    cout << "*****";
    setxy(x, y + 2);
    cout << " *** ";
}

void astDrawing(float& x1, float& x2, float& x3, int& y1, int& y2, int& y3) {
    setxy(x1, y1);
    cout << " *** ";
    setxy(x1, y1 + 1);
    cout << "*****";
    setxy(x1, y1 + 2);
    cout << " *** ";

    setxy(x2, y2);
    cout << " *** ";
    setxy(x2, y2 + 1);
    cout << "*****";
    setxy(x2, y2 + 2);
    cout << " *** ";

    setxy(x3, y3);
    cout << " *** ";
    setxy(x3, y3 + 1);
    cout << "*****";
    setxy(x3, y3 + 2);
    cout << " *** ";
}

void floor(float& x, int y) {
    setxy(x, y);
    for (int i = 0; x < SCREEN_WIDTH; i++) {
        for (int j = 0; j > 2; j++) {
            cout << char(219);
        }
    }
}


bool checkCollision(float x, float asteroidX, int y, int asteroidY) {
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 2; j++) {
            if (x + i >= asteroidX && x + i <= asteroidX + 4 && y + j >= asteroidY && y + j <= asteroidY + 2) {
                return true;  // Colisión detectada
            }
        }
    }
    return false;  // No se encontró colisión
}



void shipGame() {
    float x = 10;
    int y = 0;
    float xEst1 = 18, xEst2 = 60; int yEst1 = 11;
    float xEst3 = 15, xEst4 = 85; int yEst2 = 21;
    float x1 = 1, dx1 = aleatorio();
    int y1 = 5;
    float x2 = 1, dx2 = aleatorio();
    int y2 = 15;
    float x3 = 1, dx3 = aleatorio();
    int y3 = 25;
    float xFloor = 0; int yFloor = 35;

    int direction1 = 1;
    int direction2 = 1;
    int direction3 = 1;

    

    while (1) {
        delAst(x1, y1);
        delAst(x2, y2);
        delAst(x3, y3);

        astStatic(xEst1, yEst1);
        astStatic(xEst2, yEst1);
        astStatic(xEst3, yEst2);
        astStatic(xEst4, yEst2);
        shipDrawing(x, y);

        x1 += dx1 * direction1;
        x2 += dx2 * direction2;
        x3 += dx3 * direction3;

        if (x1 <= 0 || x1 >= SCREEN_WIDTH - 5) {
            direction1 *= -1;
        }

        if (x2 <= 0 || x2 >= SCREEN_WIDTH - 5) {
            direction2 *= -1;
        }

        if (x3 <= 0 || x3 >= SCREEN_WIDTH - 5) {
            direction3 *= -1;
        }

        astDrawing(x1, x2, x3, y1, y2, y3);

        if (checkCollision(x, x1, y, y1) || checkCollision(x, x2, y, y2) || checkCollision(x, x3, y, y3) || checkCollision(x, xEst1, y, yEst1) || checkCollision(x, xEst2, y, yEst1) || checkCollision(x, xEst3, y, yEst2) || checkCollision(x, xEst4, y, yEst2)) {
            // cuando la nave se choque con los asteroides, se regresa a la posición inicial
            x = 10;
            y = 0;
        }

        _sleep(10);
    }
}

int main() {
    Console::CursorVisible = false;
    srand(time(NULL));
    Console::SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    startScreen();
    shipGame();
    system("pause>0");
    return 0;
}
