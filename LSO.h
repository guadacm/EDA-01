/* Funciones para Lista Secuencial Ordenada */
#ifndef LSO_H_INCLUDED
#define LSO_H_INCLUDED



void menu_LSO(int *op)
{
    cant_LSO = 0; // -- Inicializo la lista
    strcpy(LSO[0].codigo, "ZZZZZZ");

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
                int alta;
                printf("\n\nCodigo: ");
                fflush(stdin);
                scanf("%s", nuevo.codigo);
                strupr(nuevo.codigo);
                alta = alta_LSO(nuevo, 0);
                if(alta == 0)
                    printf("\nEl articulo ya existe\n\n");
                else
                    printf("\nEl articulo se agrego a la lista exitosamente\n\n");
                system("pause");
                break;
            case 2: printf("Algo\n"); system("pause"); break;
            case 3: printf("Algo\n"); system("pause"); break;
            case 4:
                mostrar_LS(LSO, cant_LSO);
                system("pause");
                break;
            case 5:
                memorizacion_previa(2);
                system("pause");
                break;
        }
    }
    *op = -1;

}

int localizar_LSO(char codArt[], int *posicion) //-- DEVUELVE: 1.Exito 0.Fracaso
{
    int li, ls, testigo;
    if (cant_LSO != 0)
    {
        li = 0;
        ls = cant_LSO;
        while (li !=ls)
        {
            testigo = (li + ls - 1) / 2;
            if(strcmp(codArt, LSO[testigo].codigo) <= 0)
            {
                ls = testigo;
            }
            else
            {
                li = testigo + 1;
            }
        }
        *posicion = li;
        if(strcmp(codArt, LSO[li].codigo) == 0)
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
        *posicion = 0;
        return 0;
    }
}

Articulo info_alta_LSO(char codArt[])
{
    Articulo nuevo;
    strcpy(nuevo.codigo, codArt);

    printf("\nArticulo: ");
    fflush(stdin);
    fgets(nuevo.articulo, 52, stdin);
    printf("\nMarca: ");
    fflush(stdin);
    fgets(nuevo.marca, 62, stdin);
    printf("\nValor: ");
    fflush(stdin);
    scanf("%f", &nuevo.valor);
    printf("\nCantidad: ");
    fflush(stdin);
    scanf("%i", &nuevo.cantidad);
    printf("\nClub: ");
    fflush(stdin);
    fgets(nuevo.club, 72, stdin);

    borrar_salto(&nuevo);

    return nuevo;
}

int alta_LSO(Articulo nuevo, int entrada) //-- DEVUELVE: 1.Exito 0.Fracaso
{
    if (cant_LSO < DIM)
    {
        int loc;
        if (localizar_LSO(nuevo.codigo, &loc) == 0)
        {
            if(entrada == 0)
            {
                nuevo = info_alta_LSO(nuevo.codigo);
            }
            int i;
            for(i = cant_LSO; i >= loc; i--)
            {
                LSO[i + 1] = LSO[i];
            }
            LSO[loc] = nuevo;
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
