#ifndef MATRIZESTATICA_H
#define MATRIZESTATICA_H

#include "MatrizBase.h"
#include <iostream>
#include <iomanip>
#include <type_traits> // Importe para usar std::is:integral_v


// Clase Concreta Estática
// M y N son parámetros "NO-TYPE" de template para el tamaño fijo.
template <typename T, int M, int N>
class MatrizEstatica : public MatrizBase<T> {

    private:
        // Arreglo nativo estatico
        T _datos[M][N];

    public:
        // Constructor que inicializa la clase base con las dimensiones fijas M y N
        MatrizEstatica() : MatrizBase<T>(M, N){}

        // Destructor
        ~MatrizEstatica() override {
            std::cout  << "Destructor de MatrizEstatica (" << M << "x" << N << ", Tipo " << typeid(T).name() << ") llamado." << std::endl;
        }

        // Implementación de métodos virtuales

        // Llena el arreglo estático
        void cargarValores() override {
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < N; ++j) {
                    if constexpr (std::is_integral_v<T>) {
                        _datos[i][j] = static_cast<T>(std::rand() % 5);
                    } else {
                        _datos[i][j] = static_cast<T>(std::rand() % 300) / 100.0f;
                    }
                }
            }
        }

        // Suma Polimórfica, devuelve una nueva MatrizEstatica con el resultado.

        MatrizBase<T>* sumar(const MatrizBase<T>& otra) const override { 
            // Verificar dimensiones
            if(this->_filas != otra.getFilas() || this->_columnas != otra.getColumnas()) {
                std::cerr << "Error: Las dimensiones de las matrices no son compatibles para la suma." << std::endl;
                return nullptr;
            }

            // Creación del objeto resultado
            MatrizEstatica<T, M, N>* resultado = new MatrizEstatica<T, M, N>();

            return resultado;
        }

        // Imprimir el contenido
        void imprimir() const override {
            std::cout << std::fixed << std::setprecision(1);
            for (int i = 0; i < M; ++i){
                std::cout << "|";
                for (int j = 0; j < N; ++j) {
                    std::cout << " " << _datos[i][j] << " |";
                }
                std::cout << std::endl;
            }
        }

        // Método para obtener un elemento para la sobrecarga del operador +
        T getElemento(int i, int j) const {
            return _datos[i][j];
        }

};

#endif