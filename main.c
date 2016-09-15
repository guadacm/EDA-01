/* -- Grupo 5: Medina, Guadalupe
 *             Montenegro, Luis
 *
 * -- Estructura elegida:
 *
 * -- Funciones de costos:
 *                        - Alta y Baja -> Cantidad de corrimientos para LSD y LSO
 *                                      -> Actualizacion de puntero para LVO
 *                        - Pertenencia -> Cantidad de celdas consultadas para todas las listas
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
    printf("\n\t****************************************\n"
             "\t*** ESTRUCTURA DE DATOS Y ALGORITMOS ***\n"
             "\t****************************************\n");
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
    /* Inicializacion de Estructuras y variables */
    // -- LSD
    cant_LSD = 0;
    cant_altas_LSD = 0;
    cant_bajas_LSD = 0;
    cant_consultas_exito_LSD = 0;
    cant_consultas_fracaso_LSD = 0;
    celd_cons_exito_LSD = 0;
    celd_cons_fracaso_LSD = 0;
    celd_corr_baja_LSD = 0;
    maximo_cons_exito_LSD = 0;
    maximo_cons_fracaso_LSD = 0;
    maximo_alta_corr_LSD = 0;
    maximo_baja_corr_LSD = 0;

    // -- LSO
    cant_LSO = 0;
    strcpy(LSO[0].codigo, "ZZZZZZ"); // -- +inf
    cant_altas_LSO = 0;
    cant_bajas_LSO = 0;
    cant_consultas_exito_LSO = 0;
    cant_consultas_fracaso_LSO = 0;

    // -- LVO
    cant_altas_LVO = 0;
    cant_bajas_LVO = 0;
    cant_consultas_exito_LVO = 0;
    cant_consultas_fracaso_LVO = 0;


    /* Fin inicializacion */

    encabezado();
    printf("\t       Comparacion de estructuras       \n"
           "\t       --------------------------       \n");
    lectura_archivo_operaciones();

    encabezado();
    printf("\t       Comparacion de estructuras       \n"
           "\t       --------------------------       \n"
           "\nCant. de Altas:\t\t\tLSD: %d \tLSO: %d \tLVO: %d"
           "\nCant. de Bajas:\t\t\tLSD: %d \tLSO: %d \tLVO: %d"
           "\nCant. de Consultas-Exito:\tLSD: %d \tLSO: %d \tLVO: %d"
           "\nCant. de Consultas-Fracaso:\tLSD: %d \tLSO: %d \tLVO: %d\n",
           cant_altas_LSD,
           cant_altas_LSO,
           cant_altas_LVO,
           cant_bajas_LSD,
           cant_bajas_LSO,
           cant_bajas_LVO,
           cant_consultas_exito_LSD,
           cant_consultas_exito_LSO,
           cant_consultas_exito_LVO,
           cant_consultas_fracaso_LSD,
           cant_consultas_fracaso_LSO,
           cant_consultas_fracaso_LVO);
    printf("\nCostos de Altas"
           "\n---------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\nLSD:\t0\t\t%d"
           "\nLSO:\t0\t\t0"
           "\nLVO:\t0\t\t0",
           maximo_alta_corr_LSD
           );
    printf("\n\nCostos de Bajas"
             "\n---------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\nLSD:\t0\t\t%d"
           "\nLSO:\t0\t\t0"
           "\nLVO:\t0\t\t0",
           (float)(celd_corr_baja_LSD/ cant_bajas_LSD),
           maximo_baja_corr_LSD
           );

    printf("\n\nCostos de Evocaciones"
             "\n---------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\nLSD:\t%.2f\t\t%d"
           "\nLSO:\t0\t\t0"
           "\nLVO:\t0\t\t0\n\n",
            (float)((float)celd_cons_exito_LSD/(float)cant_consultas_exito_LSD),
            maximo_cons_exito_LSD

           );
    system("pause");
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
