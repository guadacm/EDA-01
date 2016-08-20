/* Funciones para Lista Secuencial Desordenada */
#ifndef LSD_H_INCLUDED
#define LSD_H_INCLUDED

void menu_LSD(int *op)
{
    while (*op != 0)
    {
        encabezado();
        printf("Lista Secuencial Desordenada\n");
        printf("_____________________________\n");
        printf("\n[1] Nuevo articulo");
        printf("\n[2] Eliminar articulo");
        printf("\n[3] Consultar articulo");
        printf("\n[4] Mostrar articulos");
        printf("\n[5] Memorizacion previa");
        printf("\n\n[0] Volver\n");
        printf("\nElija una opcion: ");
        scanf("%d", op);

        switch (*op)
        {
            case 0: break;
            case 1: printf("Algo\n"); system("pause"); break;
            case 2: printf("Algo\n"); system("pause"); break;
            case 3: printf("Algo\n"); system("pause"); break;
            case 4: printf("Algo\n"); system("pause"); break;
            case 5: printf("Algo\n"); system("pause"); break;
        }
    }
    *op = -1;

}

#endif // LSD_H_INCLUDED
