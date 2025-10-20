#ifndef MATRIZBASE_H
#define MATRIZBASE_H


template <typename T>
class MatrizBase {
    
    // Miembros protegidos para almacenar las dimensiones de la matriz.
    protected:
        int _filas;
        int _columnas;

    public:

        // Constructor que inicializa las dimensiones.
        MatrizBase(int filas, int columnas) : _filas(filas), _columnas(columnas){}

        // Destructor virtual para garantizar que se llame al destructor correcto.
        virtual ~MatrizBase(){}

        // Métodos virutales puros para generar polimorfismo.

        // Lógica para llenar la matriz con datos.
        virtual void cargarValores() = 0;

        // Devuelve un puntero a un nuevo objeto MatrizBase<T> que contendrá el resultado de la suma.
        virtual MatrizBase<T>* sumar(const MatrizBase<T>& otra) const = 0;

        // Lógica para mostrar los contenidos de la matriz.
        virtual void imprimir() const = 0;

        // Método virtual puro necesario para que operator+ pueda acceder a los elementos de A y B
        virtual T getElemento(int i, int j) const = 0;

        // Métodos auxiliares
        int getFilas() const { return _filas; }
        int getColumnas() const { return _columnas; }
        

};

#endif