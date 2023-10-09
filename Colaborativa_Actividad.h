//
// Created by lenovo on 06/10/2023.
//

#ifndef COLABORATIVA_ACTIVIDAD_COLABORATIVA_ACTIVIDAD_H
#define COLABORATIVA_ACTIVIDAD_COLABORATIVA_ACTIVIDAD_H


#include <iostream>
using namespace std;

const int MAX_LIBROS = 20;
const int MAX_USUARIOS = 100;

class Libro {
private:
    //Atributos de la clase libro
    string titulo;
    string categoria;
    bool disponible;

public:
    //Constructores de la clase Libro

    //Constructor vacio
    Libro() : titulo(""), categoria(""), disponible(true) {}

    //Construtor parametrizado
    Libro(string titulo, string categoria) : titulo(titulo), categoria(categoria), disponible(true) {}

    // Getters
    string getTitulo() {
        return titulo;
    }

    string getCategoria() {
        return categoria;
    }

    bool estaDisponible() {
        return disponible;
    }


    void marcarComoNoDisponible(bool valor = true) {
        disponible = !valor;

        /*: Este metodo permite marcar el libro como no disponible. Si se llama con valor igual a true,
         * el libro se marcarÃ¡ como no disponible; si se llama con valor igual a false o no se proporciona ningÃºn valor,
         * el libro se marcarÃ¡ como disponible (esto se hace invirtiendo el valor actual de disponible).*/
    }
};

class Usuario {
private:
    //Atributos de la clase Usuario
    string nombre;
    string apellidos;
    string dni;
    Libro libroActual;
    Libro historial[MAX_LIBROS];
    int numLibrosEnHistorial;

public:
    //Constructores de la clase Usuario

    //Constructor vacio
    Usuario() : nombre(""), apellidos(""), dni(""), numLibrosEnHistorial(0) {}

    //Constructor parametrizado
    Usuario(string nombre, string apellidos, string dni) : nombre(nombre), apellidos(apellidos), dni(dni), numLibrosEnHistorial(0) {}

    // Getters
    string getNombre() {
        return nombre;
    }

    string getApellidos() {
        return apellidos;
    }

    string getDni() {
        return dni;
    }

    Libro getLibroActual() {
        return libroActual;
    }

    //MÃ©todos

    //Metodo para determinar el numero de libros que se encuentran en el historial del usuario
    int getNumLibrosEnHistorial() {
        return numLibrosEnHistorial;
    }

    //Metodo para asignar un libro a un usuario
    void asignarLibroActual(Libro libro) {
        libroActual = libro;
    }


    //Metodo para agregar un libro al historial de libros de un usuario
    void agregarAlHistorial(Libro libro) {
        if (numLibrosEnHistorial < MAX_LIBROS) {
            historial[numLibrosEnHistorial] = libro;
            numLibrosEnHistorial++;
        }
    }

    //Metodo para coger uno de los libros que se encuentran en el historial de un usuario
    Libro getLibroHistorial(int indice) {
        if (indice >= 0 && indice < numLibrosEnHistorial) {
            return historial[indice];
        }
        return Libro();
    }

    //Metodo para hacer que el libro vuelva a estar disponible al devolverse
    bool devolverLibro(string titulo) {
        for (int i = 0; i < numLibrosEnHistorial; i++) {
            if (historial[i].getTitulo() == titulo) {
                historial[i].marcarComoNoDisponible();
                return true;
            }
        }return false; // No se encontrÃ³ el libro en el historial

    }
};

class Biblioteca {
private:
    //Atributos de la clase Biblioteca
    Libro catalogo[MAX_LIBROS];
    Usuario usuarios[MAX_USUARIOS];
    int numLibros;
    int numUsuarios;

public:
    // Contructores de la clase biblioteca

    //Constructor vacÃ­o
    Biblioteca() : numLibros(0), numUsuarios(0) {}

    //MÃ©todos

    //MÃ©todo para aÃ±adir un libro a una biblioteca
    //Este es un mÃ©todo pÃºblico llamado agregarLibro. Permite agregar un libro nuevo al catÃ¡logo de la biblioteca.
    void agregarLibro(string titulo, string categoria) {
        if (numLibros < MAX_LIBROS) {
            catalogo[numLibros] = Libro(titulo, categoria);
            numLibros++;
        } else {
            cout << "No se pueden agregar mÃ¡s libros, se ha alcanzado el lÃ­mite." << endl;
        }

        /*Verifica si el nÃºmero de libros (numLibros) es menor que el mÃ¡ximo permitido (MAX_LIBROS). Si es asÃ­,
         * crea una instancia de la clase Libro con el tÃ­tulo y la categorÃ­a proporcionados y la agrega al catÃ¡logo en la posiciÃ³n numLibros*/
    }

    //MÃ©todo para aÃ±adir nuevos usuarios en el registro de la biblioteca
    void agregarUsuario(string nombre, string apellidos, string dni) {
        if (numUsuarios < MAX_USUARIOS) {
            usuarios[numUsuarios] = Usuario(nombre, apellidos, dni);
            numUsuarios++;
        } else {
            cout << "No se pueden agregar mÃ¡s usuarios, se ha alcanzado el lÃ­mite." << endl;
        }

        /*Verifica si el nÃºmero de usuarios (numUsuarios) es menor que el mÃ¡ximo permitido (MAX_USUARIOS). Si es asÃ­,
         * crea una instancia de la clase Usuario con los datos proporcionados y la agrega al registro de usuarios en la posiciÃ³n numUsuarios. */
    }

    //MÃ©todo que muestra la lista de libros que se encuentran en la biblioteca disponibles
    void listarLibrosDisponibles() {
        cout << "Libros disponibles en la biblioteca:" << endl;
        for (int i = 0; i < numLibros; i++) {
            if (catalogo[i].estaDisponible()) {
                cout << "Titulo: " << catalogo[i].getTitulo() << ", Categoria: " << catalogo[i].getCategoria() << endl;
            }
        }

        /*Para cada libro en el catÃ¡logo, verifica si estÃ¡ disponible llamando al mÃ©todo estaDisponible() del objeto Libro.
        Si el libro estÃ¡ disponible, muestra su tÃ­tulo y categorÃ­a en la consola.*/
    }

    //MÃ©todo que permite ver el historial de libros que tiene un usuario
    void verHistorialUsuario(string dni) {
        for (int i = 0; i < numUsuarios; i++) { // Itera a travÃ©s de los usuarios registrados en la biblioteca para encontrar al usuario con el DNI proporcionado.
            if (usuarios[i].getDni() == dni) { // Si se encuentra el usuario, muestra su nombre y apellidos
                cout << "Historial de lectura de " << usuarios[i].getNombre() << " " << usuarios[i].getApellidos() << ":" << endl;

                if (usuarios[i].getNumLibrosEnHistorial() == 0) { //  verifica si tiene libros en su historial. Si no tiene ningÃºn libro, muestra un mensaje indicando que no ha sacado ningÃºn libro.
                    cout << "El usuario " << usuarios[i].getNombre() << " " << usuarios[i].getApellidos() << " no ha sacado ningun libro." << endl;
                } else {
                    for (int j = 0; j < usuarios[i].getNumLibrosEnHistorial(); j++) {
                        Libro libro = usuarios[i].getLibroHistorial(j); //Si el usuario tiene libros en su historial, itera a travÃ©s de ellos y muestra los tÃ­tulos y categorÃ­as de los libros.
                        if (!libro.getTitulo().empty()) {
                            cout << "Titulo: " << libro.getTitulo() << ", Categoria: " << libro.getCategoria() << endl;
                        }
                    }
                }
            }
        }
    }

    //MÃ©todo que permite a un usuario sacar un libro de la biblioteca
    void sacarLibro(string dni, string titulo) {
        for (int i = 0; i < numUsuarios; i++) { //Utiliza un bucle for para iterar a travÃ©s de los usuarios registrados en la biblioteca (usuarios) para encontrar al usuario con el DNI proporcionado
            if (usuarios[i].getDni() == dni) {
                for (int j = 0; j < numLibros; j++) {
                    /*Una vez que encuentra al usuario, utiliza otro bucle for para iterar a travÃ©s del catÃ¡logo de libros (catalogo)
                     * para encontrar el libro con el tÃ­tulo proporcionado (titulo) y que estÃ© disponible (usando el mÃ©todo estaDisponible()).*/
                    if (catalogo[j].getTitulo() == titulo && catalogo[j].estaDisponible()) { //Si se encuentra un libro disponible con el tÃ­tulo deseado, realiza las siguientes acciones:
                        usuarios[i].asignarLibroActual(catalogo[j]); //Asigna el libro actual al usuario
                        catalogo[j].marcarComoNoDisponible(); // Marcar el libro como no disponible
                        usuarios[i].agregarAlHistorial(catalogo[j]);
                        cout << "Libro '" << titulo << "' asignado a " << usuarios[i].getNombre() << " " << usuarios[i].getApellidos() << "." << endl;
                    }
                }
            }
        }
    }

    //MÃ©todo que permite al usuario devolver un libro a la biblioteca
    void devolverLibro(string dni, string titulo) {
        for (int i = 0; i < numUsuarios; i++) { //Utiliza un bucle for para iterar a travÃ©s de los usuarios registrados en la biblioteca (usuarios) para encontrar al usuario con el DNI proporcionado
            if (usuarios[i].getDni() == dni) {
                /*Una vez que encuentra al usuario, verifica si puede devolver el libro llamando al mÃ©todo devolverLibro() de la clase Usuario.
                 Si el usuario tiene el libro en su historial y puede devolverlo, se ejecutan las siguientes acciones*/
                if (usuarios[i].devolverLibro(titulo)) {
                    for (int j = 0; j < numLibros; j++) {
                        if (catalogo[j].getTitulo() == titulo) {
                            catalogo[j].marcarComoNoDisponible(false); // Marca el libro como disponible llamando al mÃ©todo
                            cout << "Libro '" << titulo << "' devuelto por " << usuarios[i].getNombre() << " " << usuarios[i].getApellidos() << "." << endl;

                        }
                    }
                } else { //Si el usuario no tiene el libro en su historial, se muestra un mensaje indicando que el usuario no tiene ese libro en su historial.
                    cout << "El usuario no tiene el libro '" << titulo << "' en su historial." << endl;
                }
            }
        }
    }
};


#endif //COLABORATIVA_ACTIVIDAD_COLABORATIVA_ACTIVIDAD_H
