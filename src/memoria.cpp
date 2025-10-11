#include <iostream>
#include <memory>

using namespace std;

class Empleado{
    private: //Nacen de la relacion tiene
        char nombre[10]; //10B
        int edad; //4B
        char direccion[255]; //255B
        int telefono; //4B
    public: //Nacen de la relacion usa
        int LeerEdad(){
            return edad;
        }
}; //273B

int main(int argc, char const *argv[])
{
    //Tamaños de memoria estatica
    //Enteros
    cout << "Tamaño de int: " << sizeof(int) << endl;
    cout << "Tamaño de long: " << sizeof(long) << endl;
    //Punto Flotante
    cout << "Tamaño de float: " << sizeof(float) << endl;
    cout << "Tamaño de double: " << sizeof(double) << endl;
    //Bytes
    cout << "Tamaño de char: " << sizeof(char) << endl;
    cout << "Tamaño de byte: " << sizeof(byte) << endl;
    cout << "Tamaño de bool: " << sizeof(bool) << endl;
    //Punteros
    cout << "Tamaño de puntero: " << sizeof(int *) << endl;
    //Tamaños tipo NO nativos
    Empleado empleados [10]; //2730B
    cout << "Tamaño de Empleado: " << sizeof(Empleado) << endl;
    cout << "Empleados: " << empleados << endl;
    cout << "Empleados: " << empleados[0].LeerEdad() << endl;

    //Casteos
    int a = 37;
    char b = (char)a;
    cout << b <<endl;

    //Punteros en C y C++
    int* dirA = (int*)malloc(sizeof(int)); //C
    *dirA=24;
    free(dirA);
    
    int* dirB = new int(24); //C++
    delete dirB;

    //smart pointer
    unique_ptr<int> dirC;

    cout<<*dirA<<endl;
    cout<<*dirA<<endl;

    return 0;
}