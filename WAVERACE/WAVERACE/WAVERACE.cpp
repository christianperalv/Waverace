#include <iostream>     
#include <cstdlib>     
#include <ctime>        
#include "Jetski.h"     // Incluye el archivo de encabezado que contiene la declaración de la clase Jetski

// Definición de la clase Jetski
class Jetski {
private:
    std::string nombre;             // Nombre del jetski
    int velocidad;                  // Velocidad del jetski
    int distanciaRecorrida;         // Distancia recorrida por el jetski
    int nitro;                      // Cantidad de nitro disponible para el jetski

public:
    // Constructor parametrizado de la clase Jetski
    Jetski(std::string nombre) : nombre(nombre), velocidad(0), distanciaRecorrida(0), nitro(1) {}

    // Método para lanzar el dado y aumentar la velocidad del jetski
    void lanzarDado() {
        int puntos = rand() % 6 + 1;    // Genera un número aleatorio entre 1 y 6
        velocidad += puntos;            // Aumenta la velocidad del jetski con los puntos obtenidos
        std::cout << "El jugador " << nombre << " ha lanzado el dado y ha obtenido " << puntos << " puntos." << std::endl;
    }

    // Método para usar el nitro y modificar la velocidad del jetski
    void usarNitro() {
        if (nitro > 0) {                    // Verifica si hay nitro disponible
            nitro--;                        // Reduce la cantidad de nitro disponible
            int aleatorio = rand() % 2;     // Genera un número aleatorio entre 0 y 1
            if (aleatorio == 0) {           // Si el número aleatorio es 0
                velocidad /= 2;             // Divide la velocidad del jetski por 2
                std::cout << "¡Nitro usado por " << nombre << "! La velocidad se divide por dos." << std::endl;
            }
            else {                        // Si el número aleatorio es 1
                velocidad *= 2;             // Duplica la velocidad del jetski
                std::cout << "¡Nitro usado por " << nombre << "! La velocidad se duplica." << std::endl;
            }
        }
        else {                            // Si no hay nitro disponible
            std::cout << "El jugador " << nombre << " no tiene nitro disponible." << std::endl;
        }
    }

    // Método para calcular la distancia recorrida por el jetski en un turno
    void calcularDistancia() {
        distanciaRecorrida += velocidad * 100;   // Calcula la distancia recorrida por el jetski en el turno
    }

    // Getter para obtener la distancia recorrida por el jetski
    int getDistanciaRecorrida() const {
        return distanciaRecorrida;     // Devuelve la distancia recorrida por el jetski
    }

    // Getter para obtener el nombre del jetski
    std::string getNombre() const {
        return nombre;                  // Devuelve el nombre del jetski
    }
};

// Función principal (main) del programa
int main() {
    srand(time(0));     // Inicializa la semilla para la generación de números aleatorios basada en el tiempo actual

    // Creación de dos objetos de la clase Jetski
    Jetski jetski1("Jetski 1");
    Jetski jetski2("Jetski 2");

    // Bucle para simular los cinco turnos de la carrera
    for (int turno = 1; turno <= 5; turno++) {
        std::cout << "Turno " << turno << std::endl;

        // Lanzar el dado para cada jetski y aumentar su velocidad
        jetski1.lanzarDado();
        jetski2.lanzarDado();

        // Opcionalmente, usar nitro para cada jetski
        // jetski1.usarNitro();
        // jetski2.usarNitro();

        // Calcular la distancia recorrida por cada jetski en el turno actual
        jetski1.calcularDistancia();
        jetski2.calcularDistancia();

        // Mostrar la distancia recorrida por cada jetski en el turno actual
        std::cout << "Distancia recorrida por " << jetski1.getNombre() << ": " << jetski1.getDistanciaRecorrida() << " metros." << std::endl;
        std::cout << "Distancia recorrida por " << jetski2.getNombre() << ": " << jetski2.getDistanciaRecorrida() << " metros." << std::endl;
    }

    // Determinar el resultado de la carrera y mostrarlo
    if (jetski1.getDistanciaRecorrida() > jetski2.getDistanciaRecorrida()) {
        std::cout << "¡" << jetski1.getNombre() << " ha ganado la carrera!" << std::endl;
    }
    else if (jetski2.getDistanciaRecorrida() > jetski1.getDistanciaRecorrida()) {
        std::cout << "¡" << jetski2.getNombre() << " ha ganado la carrera!" << std::endl;
    }
    else {
        std::cout << "¡Ha ocurrido un empate!" << std::endl;
    }

    return 0;   // Devuelve 0 para indicar que el programa finalizó correctamente
}
