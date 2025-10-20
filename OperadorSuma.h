#ifndef OPERADORSUMA_H
#define OPERADORSUMA_H

#include "MatrizBase.h"
#include "MatrizDinamica.h"
#include "MatrizEstatica.h"

// Función libre para la sobrecarga del operador +

template <typename T>
MatrizBase<T>* operator+(const MatrizBase<T>& A, const MatrizBase<T>& B) {
    // Verificación de Dimensiones
    if (A.getFilas() != B.getFilas() || A.getColumnas() != B.getColumnas()) {
        std::cerr << "Error en Sobrecarga (+): Las dimensiones de las matrices no coinciden. Devolviendo nullptr." << std::endl;
        return nullptr;
    }

    // Llamado al método virtual sumar de la matriz A.

    MatrizBase<T>* C = A.sumar(B);

    // Si A es Dinámica y B es Dinámica
    if (const MatrizBase<T>* ptrA = dynamic_cast<const MatrizDinamica<T>*>(&A)){
        if (const MatrizDinamica<T>* ptrB = dynamic_cast<MatrizDinamica<T>*>(&B)){
            
            MatrizDinamica<T> * ptrC = dynamic_cast<MatrizDinamica<T>*>(C);
            if (ptrC) {
                for (int i = 0; i < A.getFilas(); ++i) {
                    for (int j = 0; j < A.getColumnas(); ++j) {
                        ptrC->_datos[i][j] = ptrA->_datos[i][j] + ptrB->_datos[i][j];
                    }
                }
            }
        }
    }

    return C;


};

#endif