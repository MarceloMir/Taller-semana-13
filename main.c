#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    char peliculas[10][4][40] = {
        {"1", "Avatar", "10:20", "Fantasia"},
        {"2", "StarWars", "11:30", "CFiccion"},
        {"3", "Avengers", "12:50", "Accion"},
        {"4", "Insidious", "22:00", "Terror"},
        {"5", "ElConjuro", "21:00", "Terror"},
        {"6", "InsideOut", "10:20", "Animacion"},
        {"7", "Godzilla", "15:30", "CFiccion"},
        {"8", "Anabel", "20:00", "Terror"},
        {"9", "Thor", "12:50", "Accion"},
        {"10", "IronMan", "12:50", "Accion"}
    };
    double precio[3] = {7, 3.5, 3};
    char clientes[5][2][40] = {
        {"", ""},
        {"", ""},
        {"", ""},
        {"", ""},
        {"", ""}
    };

    int reserva[10][4] = {
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1}
    };

    int opcion1 = 0, opcion2 = 0, opcion3 = 0;
    do {
        printf("Escoja una opcion:\n1.Ingresar Cliente\n2.Ver Peliculas\n3.Buscar Pelicula\n4.Comprar Ticket\n5.Ver Compras\n>>");
        scanf("%d", &opcion2);
        switch (opcion2) {
        case 1:
            ingresarCliente(clientes);
            break;
        case 2:
            listarPeliculas(peliculas);
            break;
        case 3:
            printf("1.Por nombre\n2.Por Genero\n>>");
            scanf("%d", &opcion3);
            switch (opcion3) {
            case 1:
                buscarporNombre(peliculas);
                break;
            case 2:
                buscarporGenero(peliculas);
                break;
            default:
                break;
            }
            break;
        case 4:
            comprarTicket(peliculas, precio, clientes, reserva);
            break;
        case 5:
            verCompras(peliculas, precio, clientes, reserva);
            break;
        default:
            break;
        }
        printf("Desea escoger una nueva opcion: 1.Si/2.No\n>>");
        scanf("%d", &opcion1);
    } while (opcion1 == 1);

    return 0;
}
