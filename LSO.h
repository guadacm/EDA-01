/* Funciones para Lista Secuencial Ordenada */
#ifndef LSO_H_INCLUDED
#define LSO_H_INCLUDED



void menu_LSO(int *op)
{
    cant_LSO = 0; // -- Inicializo la lista
    while (*op != 0)
    {
        encabezado();
        printf("Lista Secuencial Ordenada\n");
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
            case 1:
                encabezado();
                printf("Lista Secuencial Ordenada\n");
                printf("_________________________\n");
                printf("\n[1] Nuevo articulo");
                Articulo nuevo;
                printf("\nIngrese el codigo del nuevo articulo: ");
                fflush(stdin);
                scanf("%s",nuevo.codigo);
                alta_LSO(nuevo, 0);
                system("pause");
                break;
            case 2: printf("Algo\n"); system("pause"); break;
            case 3: printf("Algo\n"); system("pause"); break;
            case 4: printf("Algo\n"); system("pause"); break;
            case 5: printf("Algo\n"); system("pause"); break;
        }
    }
    *op = -1;

}

int localizar_LSO(char codArt[], int *posicion) //-- DEVUELVE: 1.Exito 0.Fracaso
{
    int li, ls, testigo;
    if (cant_LSO > 0)
    {
        li = 0;
        ls = cant_LSO-1;
        while (li != ls)
        {
            testigo = (li + ls +1) / 2;
            if (strcmp(codArt, LSO[testigo].codigo) >= 0)
            {
                li = testigo;
            }
            else
            {
                ls = testigo - 1;
            }
        }
        *posicion = li;
        if (strcmp(codArt, LSO[*posicion].codigo) == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int alta_LSO(Articulo nuevo, int entrada) //-- DEVUELVE: 1.Exito 0.Fracaso
{
    if (cant_LSO < DIM)
    {
        int loc;
        if (localizar_LSO(nuevo.codigo, &loc) == 0)
        {
            if (cant_LSO != 0)
            {
                if (strcasecmp(nuevo.codigo, LSO[loc].codigo) > 0)//(x > lista[loc])
                {
                    int i;
                    for(i = cant_LSO; i > loc + 1; i--)
                    {
                        LSO[i] = LSO[i-1];
                    }
                    LSO[loc + 1] = nuevo;
                }
                else
                {
                    int i;
                    for(i = cant_LSO; i > loc; i--)
                    {
                        LSO[i] = LSO[i-1];
                    }
                    LSO[loc] = nuevo;
                }
            }
            else
            {
                LSO[loc] = nuevo;
            }
            cant_LSO++;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

#endif // LSO_H_INCLUDED
