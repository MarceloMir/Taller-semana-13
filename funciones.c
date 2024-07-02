#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarCliente(char clientes[][2][40]) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][0], "") == 0) {
            printf("Ingrese nombre del nuevo cliente: ");
            scanf("%s", clientes[i][0]);
            printf("Ingrese cedula del nuevo cliente: ");
            scanf("%s", clientes[i][1]);
            break;
        }
    }
    imprimirClientes(clientes);
}

void imprimirClientes(char clientes[][2][40]) {
    FILE *archivo = fopen("clientes.txt", "w");
    if (archivo != NULL) {
        printf("Se abrio correctamente el archivo: clientes.txt\n");

    
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][0], "") != 0) {
            fprintf(archivo, "%s\t\t%s\n", clientes[i][0], clientes[i][1]);
        }
        fclose(archivo);
    }
    }else{
        printf("No se pudo abrir el archivo clientes.txt\n");
    }


}

void listarPeliculas(char peliculas[][4][40]) {
    FILE *archivo = fopen("Listapeliculas.txt", "w");
    if (archivo != NULL) {
        printf("Se abrió correctamente el arcihvo: Listarpeliculas.txt\n");
    
    
    fprintf(archivo, "numero\t\tPelicula\t\tHora\t\tGenero\n");
    for (int i = 0; i < 10; i++) {
        fprintf(archivo, "\n%s\t\t%s\t\t%s\t\t%s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
    }
    fclose(archivo);
    }else{
        printf("No se pudo abrir el archivo Listarpeliculas.txt");
    }
}

void buscarporNombre(char peliculas[][4][40]) {
    char nPelicula[40];
    printf("Ingrese el nombre de la pelicula que desee buscar: \n");
    scanf("%s", nPelicula);
    FILE *archivo = fopen("busquedaDepelicula.txt", "w");
    if (archivo != NULL) {
        printf("Abierto correctamente: busquedaDepelicula.txt");
    
    
    fprintf(archivo, "numero\t\tPelicula\t\tHora\t\tGenero\n");
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][1], nPelicula) == 0) {
            fprintf(archivo, "\n%s\t\t%s\t\t%s\t\t%s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
        }
    }
    fclose(archivo);
    }else{
        printf("No se pudo abrir el archivo busquedaDepelicula.txt");
    }
}

void buscarporGenero(char peliculas[][4][40]) {
    char Gen[40];
    printf("Ingrese el genero de la pelicula que desea buscar: ");
    scanf("%s", Gen);
    FILE *archivo = fopen("busquedaPorgenero.txt", "w");
    if (archivo != NULL) {
        printf("Abierto Correctamente: BuscarPorgenero.txt");
    
    
    fprintf(archivo, "numero\t\tPelicula\t\tHora\t\tGenero\n");
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][3], Gen) == 0) {
            fprintf(archivo, "\n%s\t\t%s\t\t%s\t\t%s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
        }
    }
    fclose(archivo);
    }else{
        printf("No se pudo abrir el archivo BuscarPorgenero.txt");
    }
}

#define precioGeneral 7
#define precioVermouth 3.5
#define precioTerceraEdad 3

void comprarTicket(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]) {
    char nombre[40];
    int numPelicula;
    printf("\nIngrese su nombre para buscar si esta en la lista--> ");
    scanf("%s", nombre);
    int indexNombre = -1;
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][0], nombre) == 0) {
            indexNombre = i;
            break;
        }
    }
    if (indexNombre == -1) {
        printf("Cliente no encontrado. Ingrese un nombre valido de la lista\n");
        return;
    }
    printf("\nESTAS SON LAS PELICULAS DISPONIBLES... \n");
    listarPeliculas(peliculas);
    printf("\nIngrese el numero de pelicula que desea reservar-> ");
    scanf("%d", &numPelicula);
    if (numPelicula < 1 || numPelicula > 10) {
        printf("\nNO SE HA ENCONTRADO LA PELICULA");
        return;
    }
    if (reserva[numPelicula - 1][indexNombre] != -1) {
        printf("\nYa esta realizada la reserva para esta funcion");
        return;
    }
    int cantGeneral, cantVermouth, cantTerceraEdad;
    printf("\nIngrese la cantidad de boletos generales que desee comprar-> ");
    scanf("%d", &cantGeneral);
    printf("\nIngrese la cantidad de boletos Vermouth que desee comprar-> ");
    scanf("%d", &cantVermouth);
    printf("\nIngrese la cantidad de boletos para tercera edad que desee comprar-> ");
    scanf("%d", &cantTerceraEdad);
    if (cantGeneral == 0 && cantVermouth == 0 && cantTerceraEdad == 0) {
        printf("\n\tIngrese al menos un boleto\n");
    }
    double PrecioTotal = cantGeneral * precioGeneral + cantVermouth * precioVermouth + cantTerceraEdad * precioTerceraEdad;
    FILE *archivo = fopen("comprar ticket.txt", "w");
    if (archivo != NULL) {
        printf("Se abrio el archivo: comprar ticket.txt");
        
    
    fprintf(archivo, "\nESTE ES EL RESUMEN DE SU COMPRA...\n");
    fprintf(archivo, "Cliente: %s\n", nombre);
    fprintf(archivo, "Pelicula: %s\n", peliculas[numPelicula - 1][1]);
    fprintf(archivo, "Cantidad de Entradas Generales: %d\n", cantGeneral);
    fprintf(archivo, "Cantidad de Entradas Vermouth: %d\n", cantVermouth);
    fprintf(archivo, "Cantidad de Entradas Tercera Edad: %d\n", cantTerceraEdad);
    fprintf(archivo, "El precio TOTAL es: %.2f\n", PrecioTotal);
   
    int cantidadTotalBoletos = cantGeneral + cantVermouth + cantTerceraEdad;
    int confirmacion;
    printf("\nDesea confirmar la compra? 1.si / 2.no ");
    scanf("%d", &confirmacion);
    if (confirmacion == 1) {
        reserva[numPelicula - 1][indexNombre] = cantidadTotalBoletos;
        fprintf(archivo, "\n\tCOMPRA CONFIRMADA\n");
    } else {
        fprintf(archivo, "\n\tLA COMPRA HA SIDO CANCELADA\n");
    }
    fclose(archivo);
    }else{
        printf("No se pudo abrir el archivo comprar ticket.txt");
    }
}

void verCompras(char peliculas[][4][40], double precio[3], char clientes[][2][40], int reserva[][4]) {
    FILE *archivo = fopen("Ver compras.txt", "w");
    if (archivo != NULL) {
        printf("Se abrio correctamente: Ver compras.txt");
   
    
    fprintf(archivo, "Estas son sus compras realizadas\n");
    int hayCompras = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (reserva[i][j] != -1 && strcmp(clientes[j][0], "") != 0) {
                fprintf(archivo, "Cliente: %s, Pelicula: %s, Cantidad de boletos: %d\n", clientes[j][0], peliculas[i][1], reserva[i][j]);
                hayCompras = 1;
            }
        }
    }
    if (!hayCompras) {
        fprintf(archivo, "No se han realizado compras.\n");
    }
    fclose(archivo);
    }else{
        printf("No se pudo abrir el archivo Ver compras.txt");
    }
}

