#include <iostream>
#include "Colaborativa_Actividad.h"

int main() {
    Biblioteca biblioteca;

    // Agregar libros
    biblioteca.agregarLibro("Libro1", "Miedo");
    biblioteca.agregarLibro("Libro2", "Fantasia");
    biblioteca.agregarLibro("Libro3", "Policiaca");

    // Agregar usuarios
    biblioteca.agregarUsuario("Damian", "Perez", "34533456D");
    biblioteca.agregarUsuario("Maria", "Juarez", "12312312M");

    // Ejemplo de uso de las funcionalidades
    biblioteca.sacarLibro("34533456D", "Libro1");
    biblioteca.sacarLibro("34533456D", "Libro2");

    biblioteca.verHistorialUsuario("34533456D");
    biblioteca.verHistorialUsuario("12312312M");

    biblioteca.devolverLibro("34533456D", "Libro1");

    biblioteca.listarLibrosDisponibles();

    return 0;

}
