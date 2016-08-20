/*
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "LSD.h"
#include "LSO.h"
#include "LVO.h"

int main()
{
    int opcion = 1;

    while (opcion != 0)
    {
        principal(&opcion);
        switch (opcion)
        {
            case 0: break; // Salir
            case 1: // Menu Administracion de estructuras
                {
                    while (opcion != 0)
                    {
                        admin(&opcion);
                        switch (opcion)
                        {
                            case 0: break; //Volver al menu anterior
                            case 1: //Menu LSD
                                while (opcion !=0)
                                {
                                    menu_LSD(&opcion);
                                    switch (opcion)
                                    {
                                        case 0: break;
                                    }
                                    opcion = -1;
                                    break;
                                }
                            case 2: //Menu LSO
                                break;
                            case 3: //Menu LVO
                                break;
                        }
                    }
                    opcion = -1;
                    break;

                }

            case 2: break;
        }
    }
    return 0;
}
