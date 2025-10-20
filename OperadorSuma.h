#ifndef OPERADORSUMA_H
#define OPERADORSUMA_H

#include "MatrizBase.h"
#include "MatrizDinamica.h"
#include "MatrizEstatica.h"
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

    if (MatrizDinamica<T>* ptrC = dynamic_cast<MatrizDinamica<T>*>(C)) {
        for (int i = 0; i < A.getFilas(); ++i) {
            for (int j = 0; j < A.getColumnas(); ++j) {
                // Lectura de A y B usando el método polimórfico getElemento()
                ptrC->_datos[i][j] = A.getElemento(i, j) + B.getElemento(i, j);
            }
        }
    } 
    else if (MatrizEstatica<T, 3, 2>* ptrC = dynamic_cast<MatrizEstatica<T, 3, 2>*>(C)) {
        for (int i = 0; i < A.getFilas(); ++i) {
            for (int j = 0; j < A.getColumnas(); ++j) {
                ptrC->_datos[i][j] = A.getElemento(i, j) + B.getElemento(i, j);
            }
        }
    } else {
        std::cerr << "Advertencia: El tipo de matriz C es desconocido o no se pudo castear correctamente para la escritura." << std::endl;
    }

    return C;
}

#endif