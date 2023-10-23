#include "pch.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace System;
using namespace std;

int MILISEGUNDOS = 0;
int SEGUNDOS = 0;
const int SCREEN_WIDTH = 110;
const int SCREEN_HEIGHT = 40;
const float VELOCIDAD_ALEATORIA = (float)(rand() % 5 + 1);

void setxy(float x, int y) {
    Console::SetCursorPosition(x, y);
}

float aleatorio() {
    return (float)rand() / RAND_MAX;
}
void CambiarColor(int x) {
    switch (x) {
    case 0:
        Console::ForegroundColor = ConsoleColor::White;
        break;
    case 1:
        Console::ForegroundColor = ConsoleColor::Yellow;
        break;
    case 2:
        Console::ForegroundColor = ConsoleColor::Blue;
        break;
    case 3:
        Console::ForegroundColor = ConsoleColor::Red;
        break;
    case 4:
        Console::ForegroundColor = ConsoleColor::Green;
        break;
    case 5:
        Console::ForegroundColor = ConsoleColor::DarkBlue;
        break;
    case 6:
        Console::ForegroundColor = ConsoleColor::DarkGreen;
        break;
    case 7:
        Console::ForegroundColor = ConsoleColor::DarkCyan;
        break;
    case 8:
        Console::ForegroundColor = ConsoleColor::DarkRed;
        break;
    case 9:
        Console::ForegroundColor = ConsoleColor::DarkMagenta;
        break;
    case 10:
        Console::ForegroundColor = ConsoleColor::DarkYellow;
        break;
    case 11:
        Console::ForegroundColor = ConsoleColor::Gray;
        break;
    case 12:
        Console::ForegroundColor = ConsoleColor::DarkGray;
        break;
    case 13:
        Console::ForegroundColor = ConsoleColor::Cyan;
        break;
    case 14:
        Console::ForegroundColor = ConsoleColor::Magenta;
        break;
    }
}

void clockwise(int a, int b, int espera) {
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

void delShip(float& x, int& y) {
    setxy(x, y);
    cout << "            ";
    setxy(x, y + 1);
    cout << "            ";
}

void shipMovement(float& x, int& y, float xRandMovement) {
    if (_kbhit()) {
        char c = _getch();
        delShip(x, y);
        if (c == 'a' || c == 'A') {
            if (x > 0) {
                x -= xRandMovement;
            }
        }
        if (c == 'd' || c == 'D') {
            if (x < SCREEN_WIDTH - 13) {
                x += xRandMovement;
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
    setxy(20, SCREEN_HEIGHT - 2);
    cout << "Velocidad: " << VELOCIDAD_ALEATORIA; // Puedes mostrar la velocidad actual aquí
}

void shipDrawing(float& x, int& y) {
    CambiarColor(14);
    //las Y permanecen constantes para que el movimiento se sienta menos torpe
    setxy(x, y);
    cout << "   __|__";
    setxy(x, y + 1);
    cout << "*---o0o---*";
    shipMovement(x, y, VELOCIDAD_ALEATORIA);
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

void astStatic(float& x, int& y, int color) {
    CambiarColor(color);
    setxy(x, y);
    cout << " *** ";
    setxy(x, y + 1);
    cout << "*****";
    setxy(x, y + 2);
    cout << " *** ";
}

void astDrawing(float& x1, float& x2, float& x3, int& y1, int& y2, int& y3, int color1, int color2, int color3) {
    CambiarColor(color1);
    setxy(x1, y1);
    cout << " *** ";
    setxy(x1, y1 + 1);
    cout << "*****";
    setxy(x1, y1 + 2);
    cout << " *** ";
    CambiarColor(color2);
    setxy(x2, y2);
    cout << " *** ";
    setxy(x2, y2 + 1);
    cout << "*****";
    setxy(x2, y2 + 2);
    cout << " *** ";
    CambiarColor(color3);
    setxy(x3, y3);
    cout << " *** ";
    setxy(x3, y3 + 1);
    cout << "*****";
    setxy(x3, y3 + 2);
    cout << " *** ";
}

void drawGround() {
    CambiarColor(3);
    setxy(0, SCREEN_HEIGHT - 3);
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        cout << (char)219;
    }
    setxy(0, SCREEN_HEIGHT - 4);
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        cout << (char)219;
    }
    setxy(0, SCREEN_HEIGHT - 5);
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        cout << (char)30;
    }

    setxy(35, SCREEN_HEIGHT - 2);
    cout << "Asteroides: 7"; //contador de asteroides 
    setxy(54, SCREEN_HEIGHT - 2);
    cout << "Tiempo: " << SEGUNDOS << "s"; //contador de tiempo
}

void drawSafeZone() {
    CambiarColor(4);
    setxy(0, 0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= 5; j++) {
            cout << char(219);
        }
        cout << endl;
    }
}

void drawSample(float x, int y, int color) {
    CambiarColor(color);
    setxy(x, y);
    cout << char(15);
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
    int lifes = 3; 
    float x = 10;
    int y = 0;
    float xEst1 = 18, xEst2 = 60; int yEst1 = 11; int est1C = 2, est2C = 3;
    float xEst3 = 15, xEst4 = 85; int yEst2 = 21; int est3C = 6, est4C = 9;
    float x1 = 1, dx1 = aleatorio();
    int y1 = 5;
    float x2 = 1, dx2 = aleatorio();
    int y2 = 15;
    float x3 = 1, dx3 = aleatorio();
    int y3 = 25;
    int mov1C = 1, mov2C = 7, mov3C = 11;
    float xFloor = 0; int yFloor = 35;
    float xSample1 = 15, xSample2 = 50, xSample3 = 85, xSample4 = 105; int ySample = SCREEN_HEIGHT - 6; int sample1C = 5, sample2C = 8, sample3C = 10, sample4C = 13;
    int sampleCounter = 0;
    int sampleDelivered = 0;
    bool loaded=false;
    //safeZone hitbox
    int xSafeZone = 5;
    int ySafeZone = 3;

    int direction1 = 1;
    int direction2 = 1;
    int direction3 = 1;


    drawSample(xSample1, ySample, sample1C);

    while (1) {
        delAst(x1, y1);
        delAst(x2, y2);
        delAst(x3, y3);

        astStatic(xEst1, yEst1,est1C);
        astStatic(xEst2, yEst1,est2C);
        astStatic(xEst3, yEst2,est3C);
        astStatic(xEst4, yEst2,est4C);
        shipDrawing(x, y);

        drawSafeZone();

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

        astDrawing(x1, x2, x3, y1, y2, y3,mov1C,mov2C,mov3C);

        if (checkCollision(x, xSample1, y, ySample) && (sampleCounter == 0||sampleCounter==1)) {
            sampleCounter++;
            xSample1 = SCREEN_WIDTH + 1;
            loaded = true;

        }

        if (checkCollision(x, x1, y, y1) || checkCollision(x, x2, y, y2) || checkCollision(x, x3, y, y3) || checkCollision(x, xEst1, y, yEst1) || checkCollision(x, xEst2, y, yEst1) || checkCollision(x, xEst3, y, yEst2) || checkCollision(x, xEst4, y, yEst2)) {
            // cuando la nave se choque con los asteroides, se regresa a la posición inicial
            x = 10;
            y = 0;
            loaded = false;
            switch (sampleDelivered) {
            case 0:
                drawSample(xSample1, ySample, sample1C);
                xSample1 = 15;
                lifes--;
                break;
            case 1:
                drawSample(xSample2, ySample, sample2C);
                lifes--;
                xSample2 = 50;
                break;
            case 2:
                drawSample(xSample3, ySample, sample3C);
                lifes--;
                xSample3 = 85;
                break;
            case 3:
                drawSample(xSample4, ySample, sample4C);
                lifes--;
                xSample4 = 105;
                break;
            default:
                break;
            }
            if (lifes == 0) {
                // Has perdido
                system("cls");
                setxy(35, 10);
                cout << "¡Has perdido!";
                setxy(30, 12);
                cout << "Muestras recogidas: " << sampleCounter;
                setxy(30, 14);
                cout << "Muestras entregadas: " << sampleDelivered;
                setxy(30, 16);
                cout << "Tiempo: " << SEGUNDOS << "s";
                setxy(25, 18);
                cout << "¿Deseas intentarlo de nuevo? (Y/N)";
                char choice = _getch();
                if (choice == 'Y' || choice == 'y') {
                    system("cls");
                    shipGame();
                    return;// Vuelve a jugar
                }
                else {
                    return;// vuelva a la pantalla de inicio
                }
            }
        }
        if (checkCollision(x, xSafeZone, y, ySafeZone) && loaded == true) {
            switch (sampleDelivered)
            {
            case 0:
                sampleDelivered++;
                drawSample(xSample2, ySample, sample2C);
                x = 10;
                y = 0;
                loaded = false;
                xSample1 = SCREEN_WIDTH + 1;
                break;
            case 1:
                drawSample(xSample3, ySample, sample3C);
                sampleDelivered++;
                x = 10;
                y = 0;
                loaded = false;
                xSample2 = SCREEN_WIDTH + 1;
                break;
            case 2:
                drawSample(xSample4, ySample, sample4C);
                sampleDelivered++;
                x = 10;
                y = 0;
                loaded = false;
                xSample3 = SCREEN_WIDTH + 1;
                break;
            case 3:
                // para que gane
                system("cls");
                setxy(35, 10);
                cout << "¡Felicidades! Has ganado.";
                setxy(30, 12);
                cout << "Muestras recogidas: " << sampleCounter;
                setxy(30, 14);
                cout << "Muestras entregadas: " << sampleDelivered;
                setxy(30, 16);
                cout << "Tiempo: " << SEGUNDOS << "s";
                setxy(25, 18);
                cout << "¿Deseas jugar de nuevo? (Y/N)";
                char choice = _getch();
                if (choice == 'Y' || choice == 'y') {
                    system("cls");
                    shipGame();
                    return;// Vuelve a jugar
                }
                else {
                    return;// vuelva a la pantalla de inicio
                }
            }
        }
        if (checkCollision(x, xSample2, y, ySample) && (sampleCounter == 1||sampleCounter==2) && sampleDelivered == 1) {
            sampleCounter++;
            xSample2 = SCREEN_WIDTH + 1;
            loaded = true;
        }
        if (checkCollision(x, xSample3, y, ySample) && (sampleCounter == 3 || sampleCounter == 2) && sampleDelivered == 2) {
            sampleCounter++;
            xSample3 = SCREEN_WIDTH + 1;
            loaded = true;
        }
        if (checkCollision(x, xSample4, y, ySample) && (sampleCounter == 3 || sampleCounter == 4) && sampleDelivered == 3) {
            sampleCounter++;
            xSample4 = SCREEN_WIDTH + 1;
            loaded = true;
        }

        MILISEGUNDOS++;
        if (MILISEGUNDOS == 26) { //es lo más cercano que encontramos a un segundo
            SEGUNDOS++;
            MILISEGUNDOS = 0;
        }
        drawGround();
        // para actualiar los contadores

        setxy(5, SCREEN_HEIGHT - 2);
        cout << "Vidas: " << lifes;
        setxy(70, SCREEN_HEIGHT - 2);
        cout << "X: " << x;
        setxy(77, SCREEN_HEIGHT - 2);
        cout << "Y: " << y;
        setxy(5, SCREEN_HEIGHT - 1);
        cout << "Muestras recogidas: " << sampleCounter;
        setxy(40, SCREEN_HEIGHT - 1);
        cout << "Muestras entregadas: " << sampleDelivered;
        setxy(80, SCREEN_HEIGHT - 1);
        if (loaded == 1) {
            cout << "Cargado: " << "Si";
        } else {
            cout << "Cargado: " << "No";
        }
        _sleep(10);
    }
}
void credits() {
    cout << " `. ___";
    cout << " __,' __`. _..----....____" << endl;
    cout << " __...--.'``;. ,. ;``--..__ .' ,-._ _.-'" << endl;
    cout << " _..-''-------' `' `' `' O ``-''._ (,;') _,' " << endl;
    cout << ",'________________ \`-._`-','" << endl;
    cout << " `._ ```````````------...___ '-.._'-:" << endl;
    cout << " ```--.._ ,. ````--...__\-." << endl;
    cout << " `.--. `-` ____ | |`" << endl;
    cout << " `. `. ,'`````. ; ;`" << endl;
    cout << " `._`. __________ `. \'__/`" << endl;
    cout << " `-:._____/______/___/____`. \ `" << endl;
    cout << " | `._ `. \ " << endl;
    cout << " `._________`-. `. `.___" << endl;
    cout << " Marte `------'`" << endl;
    setxy(35, 10);
    cout << "Proyecto hecho por: ";
    setxy(25, 13);
    cout << "-Stephanie Vásquez Zamora";
    setxy(25, 17);
    cout << "-Luis Gonzales Matute";
    setxy(25, 24);
    cout << "Oprime un boton para continuar";
    system("pause>0");
    system("cls");
    shipGame();
}
void startScreen() {
    clockwise(0, 0, 10);
    setxy(35, 10);
    cout << "Marte pero imagina que es Marte";
    setxy(25, 13);
    cout << "Instrucciones: ";
    setxy(25, 15);
    cout << "-Recolecta las 4 muestras de tierra marciana.";
    setxy(25, 17);
    cout << "-No choques con los asteroides. Si lo haces, perderás una vida.";
    setxy(25, 19);
    cout << "-Después de perder 3 vidas, perderás.";
    setxy(25, 21);
    cout << "-Si recolectas y entregas las 4 muestras de tierra, ganaras.";
    setxy(25, 23);
    cout << "-Tendrás naves de velocidades distintas dependiendo de tu partida,";
    setxy(25, 25);
    cout << "utiliza tu velocidad a tu ventaja.";
    setxy(25, 27);
    cout << "Presiona Y para continuar.";
    char choice = _getch();
    if (choice == 'Y' || choice == 'y') {
        system("cls");
        credits();
        return;// Vuelve a jugar
    }
}

int main() {
    Console::CursorVisible = false;
    srand(time(NULL));
    Console::SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    startScreen();
    system("pause>0");
    return 0;
}
