/* Funciones para Lista Secuencial Desordenada */
#ifndef LSD_H_INCLUDED
#define LSD_H_INCLUDED

void menu_LSD(int *op)
{
    encabezado();
    printf("Lista Secuencial Desordenada\n");
    printf("_____________________________\n");
    printf("\n[1] ");
    printf("\n[2] ");
    printf("\n\n[0] Volver\n");
    printf("\nElija una opcion: ");
    scanf("%d", op);
}

#endif // LSD_H_INCLUDED
