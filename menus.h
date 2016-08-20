#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

void encabezado()
{
    system("cls");
    printf("****************************************\n");
    printf("*** ESTRUCTURA DE DATOS Y ALGORITMOS ***\n");
    printf("****************************************\n\n");
}

void principal(int *op)
{
    encabezado();
    printf("\n[1] Administracion de estructuras");
    printf("\n[2] Comparacion de estructuras");
    printf("\n\n[0] Salir\n");
    printf("\nElija una opcion: ");
    scanf("%d", op);
}

void admin(int *op)
{
    encabezado();
    printf("Administracion de estructuras\n");
    printf("_____________________________\n");
    printf("\n[1] Lista Secuencial Desordenada");
    printf("\n[2] Lista Secuencial Ordenada - Busqueda Binaria");
    printf("\n[3] Lista Vinculada Ordenada");
    printf("\n\n[0] Volver\n");
    printf("\nElija una opcion: ");
    scanf("%d", op);
}

#endif // MENUS_H_INCLUDED
