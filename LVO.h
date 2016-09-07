/* Funciones para Lista Vinculada Ordenada */
#ifndef LVO_H_INCLUDED
#define LVO_H_INCLUDED

void menu_LVO(int *op)
{
    while (*op != 0)
    {
        encabezado();
        printf("Lista Vinculada Ordenada\n");
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

int localizar_LVO(char codArt[], Nodo *posicion) //-- DEVUELVE: 1.Exito 0.Fracaso
{
    if (cant_LVO >0)
    {
        Nodo *aux = LVO;
        Nodo *aux1 = LVO;
        while ((aux != NULL) && (strcmp(aux->dato.codigo, codArt) < 0))
        {
            aux1 = aux;
            aux = aux->next;
        }
        posicion = aux1;
        if(aux == NULL)
            return 0;
        else
        {
            if(strcmp(aux->dato.codigo, codArt) == 0)
                return 1;
            else
                return 0;
        }
    }
    else
    {
        posicion = LVO;
        return 0;
    }

}

#endif // LVO_H_INCLUDED
