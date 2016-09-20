/* -- Grupo 5: Medina, Guadalupe
               Montenegro, Luis

  -- Estructura elegida: Lista Secuencial Ordenada con Busqueda Binaria (LSO BB), porque suponemos que se van a realizar mas
                         evocaciones que altas y bajas. y los costos de evocaciones son menores con LSO que para las demas
                         estructuras.

                         Si existieran mas altas que otras operaciones(bajas o evocaciones), elegiriamos LSD
                         Si existieran mas bajas que otras operaciones(bajas o evocaciones), elegiriamos LVO


    El Siguiente cuadro indica que estructura es mejor en costos cada caso (alta,baja, evocacion) siendo la primera la mejor.

m: medio
M: m�ximo      _____________________ ______________________ ________________________ ____________________
              |               (m/M) |                (m/M) |                (m) (M) |              (m/M) |
              | Altas:MEJOR--> LSD  | Bajas: MEJOR--> LVO  | EvoE: MEJOR--> LSO LSO | EvoF:MEJOR--> LSO  |
              |                LVO  |                 LSD  |                LVO LSD |               LVO  |
              |                LSO  |                 LSO  |                LSD LVO |               LSD  |
              |_____________________|______________________|________________________|____________________|

  -- Funciones de costos:
                         - Alta y Baja -> Cantidad de corrimientos para LSD y LSO
                                       -> Actualizacion de puntero para LVO
                         - Evocaciones -> Cantidad de celdas consultadas para todas las listas



 ------------------------------------------ NOTAS y ACLARACIONES: ------------------------------------------

* Utilizamos un parametro extra en la funcion Localizar de cada estructura llamado "conCosto", el cual si es 1(cuando
es llamado por evocar) voy a contar las celdas consultadas.
(no siempre es necesario pero por convencion lo utilizamos en las tres estructuras)

-- listas.h:
* Se encuentran definiciones de constantes, variables y estructuras.
* Tambien estan las funciones comunes a las listas.

-- LSD.h
* El costo para un ALTA (en corrimientos), siempre es 0(cero) ya que agrego el elemento al final de la lista y por
consiguiente no se realiza ningun corrimiento

-- LSO.h
* Al final de la lista usamos un Articulo con codigo "ZZZZZZ"(+inf) para el correcto funcionamiento de la busqueda
binaria

-- LVO.h
* Como inicio de la lista usamos un nodo ficticio, que en el campo dato tiene codigo "000000" y el campo next apunta
al primer articulo de la lista o a null si esta vacia.
* Localizar devuelve adem�s del exito, el nodo anterior a donde fracas� o tuvo exito el localizar.

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
        printf("\n\t      Administracion de estructuras      \n"
                 "\t      -----------------------------      \n"
               "\n[1] Lista Secuencial Desordenada"
               "\n[2] Lista Secuencial Ordenada - Busqueda Binaria"
               "\n[3] Lista Vinculada Ordenada"
               "\n\n[0] Volver\n"
               "\nElija una opcion: ");
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
    cant_evocaciones_exito_LSO = 0;
    cant_evocaciones_fracaso_LSO = 0;
    total_corrimientos_alta_LSO = 0;
    total_corrimientos_baja_LSO = 0;
    total_consultadas_exito_LSO = 0;
    total_consultadas_fracaso_LSO = 0;
    maximo_alta_LSO = 0;
    maximo_baja_LSO = 0;
    maximo_evo_exito_LSO = 0;
    maximo_evo_fracaso_LSO = 0;

    // -- LVO
    cant_LVO = 0;
    strcpy(LVO.dato.articulo, "000000");
    LVO.next = NULL;
    cant_altas_LVO = 0;
    cant_bajas_LVO = 0;
    cant_evocaciones_exito_LVO = 0;
    cant_evocaciones_fracaso_LVO = 0;
    total_corrimientos_alta_LVO = 0;
    total_corrimientos_baja_LVO = 0;
    total_consultadas_exito_LVO = 0;
    total_consultadas_fracaso_LVO = 0;
    maximo_alta_LVO = 0;
    maximo_baja_LVO = 0;
    maximo_evo_exito_LVO = 0;
    maximo_evo_fracaso_LVO = 0;



    /* Fin inicializacion */

    encabezado();
    printf("\t       Comparacion de estructuras       \n"
           "\t       --------------------------       \n");
    lectura_archivo_operaciones();

    encabezado();
    printf("\t       Comparacion de estructuras       \n"
           "\t\tTotal de Articulos: %d\n"
           "\t       --------------------------       \n"

           "\nCant. de Altas:\t\t\tLSD: %d \tLSO: %d \tLVO: %d"
           "\nCant. de Bajas:\t\t\tLSD: %d \tLSO: %d \tLVO: %d"
           "\nCant. de Evocaciones-Exito:\tLSD: %d  \tLSO: %d  \tLVO: %d"
           "\nCant. de Evocaciones-Fracaso:\tLSD: %d  \tLSO: %d  \tLVO: %d\n",
           cant_LSO,cant_altas_LSD, cant_altas_LSO, cant_altas_LVO,
           cant_bajas_LSD, cant_bajas_LSO, cant_bajas_LVO,
           cant_consultas_exito_LSD, cant_evocaciones_exito_LSO, cant_evocaciones_exito_LVO,
           cant_consultas_fracaso_LSD, cant_evocaciones_fracaso_LSO, cant_evocaciones_fracaso_LVO);
    printf("\nCostos de Altas"
           "\n---------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\nLSD:\t0\t\t0"
           "\nLSO:\t%.2f\t\t%d"
           "\nLVO:\t%.2f\t\t%.2f",
           ((float)total_corrimientos_alta_LSO/(float)cant_altas_LSO), maximo_alta_LSO,
           (total_corrimientos_alta_LVO/(float)cant_altas_LVO),maximo_alta_LVO
           );
    printf("\n\nCostos de Bajas"
             "\n---------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\nLSD:\t%.2f\t\t%d"
           "\nLSO:\t%.2f\t\t%d"
           "\nLVO:\t%.2f\t\t%.2f",
           ((float)celd_corr_baja_LSD/(float) cant_bajas_LSD), maximo_baja_corr_LSD,
           ((float)total_corrimientos_baja_LSO/(float)cant_bajas_LSO), maximo_baja_LSO,
           (total_corrimientos_baja_LVO/(float)cant_bajas_LVO),maximo_baja_LVO
           );

    printf("\n\nCostos de Evocaciones Exitosas"
             "\n------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\nLSD:\t%.2f\t\t%d"
           "\nLSO:\t%.2f\t\t%d"
           "\nLVO:\t%.2f\t\t%d",
           ((float)celd_cons_exito_LSD/(float)cant_consultas_exito_LSD), maximo_cons_exito_LSD,
           ((float)total_consultadas_exito_LSO/(float)cant_evocaciones_exito_LSO), maximo_evo_exito_LSO,
           ((float)total_consultadas_exito_LVO/(float)cant_evocaciones_exito_LVO), maximo_evo_exito_LVO

           );
    printf("\n\nCostos de Evocaciones NO Exitosas"
             "\n---------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\nLSD:\t%.2f\t\t%d"
           "\nLSO:\t%.2f\t\t%d"
           "\nLVO:\t%.2f\t\t%d\n\n",
           ((float)celd_cons_fracaso_LSD/(float)cant_consultas_fracaso_LSD), maximo_cons_fracaso_LSD,
           ((float)total_consultadas_fracaso_LSO/(float)cant_evocaciones_fracaso_LSO), maximo_evo_fracaso_LSO,
           ((float)total_consultadas_fracaso_LVO/(float)cant_evocaciones_fracaso_LVO), maximo_evo_fracaso_LVO
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
