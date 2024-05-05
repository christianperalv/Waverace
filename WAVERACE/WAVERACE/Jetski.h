#pragma once
#include <iostream>
using namespace std;

// Declaración de la clase Jetski
class Jetski {
private:
    // Variables miembro privadas
    int speed;          // Velocidad del jetski
    int distance;       // Distancia recorrida por el jetski
    int nitro;          // Cantidad de nitro disponible para el jetski
    string Name;        // Nombre del jetski

public:
    // Constructores

    // Constructor por defecto
    Jetski() {
        speed = 0;
        distance = 0;
        nitro = 1;
        Name = "";
    }

    // Constructor parametrizado
    Jetski(int gspeed, int pAtc, string pName) {
        speed = gspeed;
        distance = pAtc;
        nitro = 1;
        Name = pName;
    }

    // Métodos de acceso

    // Getter para la velocidad
    int getspeed() {
        return speed;
    }

    // Setter para la velocidad
    void setspeed(int p) {
        speed = p;
    }

    // Getter para la distancia
    int getdistance() {
        return distance;
    }

    // Setter para la distancia
    void setdistance(int pDistance) {
        distance = pDistance;
    }

    // Getter para el nitro
    int getnitro() {
        return nitro;
    }

    // Setter para el nitro
    void setnitro() {
        nitro--;
    }

    // Getter para el nombre
    string getName() {
        return Name;
    }

    // Setter para el nombre
    void setName(string pName) {
        Name = pName;
    }

    // Método para imprimir los parámetros del jetski
    void getParameters() {
        cout << "Speed: " << speed << endl;
        cout << "Distance: " << distance << endl;
        cout << "Nitro: " << nitro << endl;
        cout << "Name: " << Name << endl;
    }
};
