#ifndef MATRIZINAMICA_H
#define MATRIZDINAMICA_H

#include "MatrizBase.h" // Se incluye la definición de la clase base
#include <iostream>
#include <iomanip>
#include <cstdlib> // Librería para utilizar rand() y srand()

// Clase Concreta Dinámica
template <typename T>
class MatrizDinamica : public MatrizBase<T> {
    private:
        // Puntero doble para la matriz dinámica
        T **_datos;

        // Método auxiliar para signar memoria, usado por los constructores y el operador de asignación.

        void _asignarMemoria(){
            // Asignación de un arreglo de punteros
            this->_datos = new T*[this->_filas];

            // Asignación de la memoria para cada fila
            for (int i = 0; i < this->_filas; ++i) {
                this ->_datos[i] = new T[this->_columnas];
            }
        }

        // Método auxiliar para liberar memoria.
        void _liberarMemoria(){
            if (this->_datos != nullptr){
                // Liberar cada fila
                for (int i = 0; i < this->_filas; ++i){
                    delete[] this->_datos[i];
                }
                // Liberar el arreglo de punteros
                delete[] this->_datos;
                this->_datos = nullptr;
            }
        }

        // Método auxiliar para realizar una copia profunda (Deep Copy).
        void _copiaProfunda(const MatrizDinamica<T>& otra){
            // Copiar dimensiones
            this->_filas = otra._filas;
            this->_columnas = otra._columnas;

            // Asignar una nueva memoria
            this->_asignarMemoria();

            // Copiar los elementos
            for (int i = 0; i < this->_filas; ++i){
                for (int j = 0; j <this->_columnas; ++j){
                    this->_datos[i][j] = otra._datos[i][j];
                }
            }
        }
    
    public:
        // Constructor que inicializa la clase base y asigna memoria.
        MatrizDinamica(int filas, int columnas) : MatrizBase<T>(filas, columnas), _datos(nullptr){
            this ->_asignarMemoria();
        }

        // Destructor para liberar la memoria asignada.
        ~MatrizDinamica() override {
            std::cout << "Liberando memoria de MatrizDinamica (" << this->_filas << "x" << this->_columnas << ", Tipo " << typeid(T).name() << ")..." << std::endl;
            this->_liberarMemoria();
        }

        // Constructor de copia para realizar la copia profunda
        MatrizDinamica(const MatrizDinamica<T>& otra) : MatrizBase<T>(otra._filas, otra._columnas), _datos(nullptr){
            this->_copiaProfunda(otra);
        }

        // Operador de Asignación que asigna el contenido de un objeto a otro
        MatrizDinamica<T>& operator=(const MatrizDinamica<T>& otra){
            if (this != &otra) { // Evita autoa-signación
                this->_liberarMemoria();
                this->_copiaProfunda(otra);
            }
            return *this;
        }

        // Implementación de métodos virtuales

        // Archivo MatrizDinamica.h (fragmento de la implementación de métodos virtuales)

        // Carga de la matriz con valores aleatorios.
        void cargarValores() override {
            for (int i = 0; i < this->_filas; ++i){
                for (int j = 0; j < this->_columnas; ++j) {
                    // Generación simple para int/float
                    if constexpr (std::is_integral_v<T>) {
                        this->_datos[i][j] = static_cast<T>(std::rand() %10);
                    } else {
                        this->_datos[i][j] = static_cast<T>(std::rand() %500) / 100.0f;
                    }
                }
            }
        }

        // Suma polimórfica que devuelve una nueva MatrizDinamica con el resultado.
        MatrizBase<T>* sumar(const MatrizBase<T>& otra) const override {
            
            // Verificar las dimensiones
            if(this->_filas != otra.getFilas() || this->_columnas != otra.getColumnas()){
                std::cerr << "Error: Las dimensiones de las matrices no son compatibles para la suma. " << std::endl;
                return nullptr;
            }

            // Creación del objeto resultado para devolver un puntero.
            MatrizDinamica<T>* resultado = new MatrizDinamica<T>(this->_filas, this->_columnas);
            return resultado;
        }

        void imprimir() const override {
            std::cout << std::fixed << std::setprecision(1);
            for (int i = 0; i < this->_filas; ++i) {
                std::cout << "|";
                for (int j = 0; j < this->_columnas; ++j) {
                    std::cout << " " << this->_datos[i][j] << " |";
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