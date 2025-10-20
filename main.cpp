#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MatrizBase.h"
#include "MatrizDinamica.h"
#include "MatrizEstatica.h"
#include "OperadorSuma.h"

// Función que ejecuta la demostración principal
void ejecutarDemoFloat() {
    std::cout << "--- Sistema gérico de Álgebra Lineal ---" << std::endl;
    std::cout << "\n>> Demostración de Genericidad (Tipo FLOAT) <<" << std::endl;

    std::srand(std::time(nullptr));

    // Creación de Matriz Dinámica
    std::cout << "\n// 1. Creación de Matriz Dinámica (a través del puntero base)" << std::endl;
    std::cout << "Creando Matriz Dinámica A (3x2)..." << std::endl;
    // Se crea la MatrizDinamica y se asigna a un puntero MatrizBase<float>*
    MatrizBase<float>* A = new MatrizDinamica<float>(3, 2);
    A->cargarValores(); // Llama a MatrizDinamica::cargarValores()
    std::cout << "A =" << std::endl;
    A->imprimir();

    // Creación de Matriz Estática
    std::cout << "\n// 2. Creación de Matriz Estática (a través del puntero base)" << std::endl;
    std::cout << "Creando Matriz Estática B (3x2)..." << std::endl;
    // Se crea la MatrizEstatica (3x2) y se asigna a un puntero MatrizBase<float>*
    MatrizBase<float>* B = new MatrizEstatica<float, 3, 2>();
    B->cargarValores(); // Llama a MatrizEstatica::cargarValores()
    std::cout << "B =" << std::endl;
    B->imprimir();

    // Operación Polimórfica
    std::cout << "\n// 3. Operación Polimórfica (Suma)" << std::endl;
    std::cout << "SUMANDO: Matriz C = A + B ..." << std::endl;
    
    // Se llama a operator+ que usa A.sumar(B) para crear C, y luego realiza la suma.
    MatrizBase<float>* C = (*A) + (*B);

    if (C != nullptr) {
        std::cout << "(La suma es manejada por el método virtual de MatrizDinamica/MatrizEstatica)" << std::endl;
        std::cout << "\nMatriz Resultado C (3x2, Tipo FLOAT):" << std::endl;
        C->imprimir(); // Llama al imprimir() de la clase concreta de C
    }

    // Limpieza de Memoria
    std::cout << "\n>> Demostración de Limpieza de Memoria <<" << std::endl;

    // Liberar C.
    if (C != nullptr) {
        std::cout << "Llamando al destructor de C..." << std::endl;
        delete C; 
    }

    // Liberar B.
    std::cout << "Llamando al destructor de B..." << std::endl;
    delete B; 

    // Liberar A.
    std::cout << "Llamando al destructor de A..." << std::endl;
    delete A; 

    std::cout << "Sistema cerrado." << std::endl;
}

int main() {
    ejecutarDemoFloat();
    return 0;
}