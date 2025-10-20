#ifndef OPERADORSUMA_H
#define OPERADORSUMA_H

#include "MatrizBase.h"
#include <iostream>

// Función libre para la sobrecarga del operador +
template <typename T>
MatrizBase<T>* operator+(const MatrizBase<T>& A, const MatrizBase<T>& B) {
    // Verificación de Dimensiones
    if (A.getFilas() != B.getFilas() || A.getColumnas() != B.getColumnas()) {
        std::cerr << "Error en Sobrecarga (+): Las dimensiones de las matrices no coinciden. Devolviendo nullptr." << std::endl;
        return nullptr;
    }

    MatrizBase<T>* C = A.sumar(B);

    if (C == nullptr) {
        return nullptr;
    }

    // Realizar la suma usando getElemento() para acceder a los datos
    for (int i = 0; i < A.getFilas(); ++i) {
        for (int j = 0; j < A.getColumnas(); ++j) {
            // Lectura de A y B usando el método polimórfico getElemento()
            // Escritura en C usando setElemento()
            C->setElemento(i, j, A.getElemento(i, j) + B.getElemento(i, j));
        }
    }

    return C;
}

#endif