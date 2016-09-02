/*
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "LSD.h"
#include "LSO.h"
#include "LVO.h"

int opcion = -1;

void encabezado()
{
    system("cls");
    printf("\n\t****************************************\n");
    printf("\t*** ESTRUCTURA DE DATOS Y ALGORITMOS ***\n");
    printf("\t****************************************\n\n");
}

// -- MENU ADMINISTRACION
void administracion()
{
    while (opcion !=0)
    {
        encabezado();
        printf("Administracion de estructuras\n");
        printf("_____________________________\n");
        printf("\n[1] Lista Secuencial Desordenada");
        printf("\n[2] Lista Secuencial Ordenada - Busqueda Binaria");
        printf("\n[3] Lista Vinculada Ordenada");
        printf("\n\n[0] Volver\n");
        printf("\nElija una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 0: break;
            case 1: menu_LSD(&opcion); break;
            case 2: menu_LSO(&opcion); break;
            case 3: menu_LVO(&opcion); break;
        }
    }
    opcion = -1;
}

// -- MENU COMPARACION
void comparacion()
{
    encabezado();
    printf("Comparacion de estructuras\n");
    printf("_____________________________\n");
    printf("\n[1] ");
    printf("\n[2] ");
    printf("\n[3] ");
    printf("\n\n[0] Volver\n");
    printf("\nElija una opcion: ");
    scanf("%d", &opcion);

}

// -- MENU PRINCIPAL
void principal()
{
    encabezado();
    printf("\n[1] Administracion de estructuras");
    printf("\n[2] Comparacion de estructuras");
    printf("\n\n[0] Salir\n");
    printf("\nElija una opcion: ");
    scanf("%d", &opcion);
    switch (opcion)
    {
        case 0: break;
        case 1: administracion(); break;
        case 2: comparacion(); break;
    }
}

int main()
{

// -- MENU PRINCIPAL
    while (opcion != 0)
    {
        principal(&opcion);
    }
    return 0;
}
