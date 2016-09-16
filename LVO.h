/* Funciones para Lista Vinculada Ordenada */
#ifndef LVO_H_INCLUDED
#define LVO_H_INCLUDED

void menu_LVO(int *op)
{
    cant_LVO = 0;
    strcpy(LVO.dato.articulo, "000000");
    LVO.next = NULL;

    while (*op != 0)
    {
        encabezado();
        printf("Lista Vinculada Ordenada\n"
               "------------------------\n"
               "\n[1] Nuevo articulo"
               "\n[2] Eliminar articulo"
               "\n[3] Consultar articulo"
               "\n[4] Articulo entregado a club"
               "\n[5] Mostrar articulos"
               "\n[6] Memorizacion previa"
               "\n\n[0] Volver\n"
               "\nElija una opcion: ");
        scanf("%d", op);

        switch (*op)
        {
            case 0: break;
            case 1:
                {
                    encabezado();
                    printf("Lista Vinculada Ordenada\n"
                           "------------------------\n"
                           "\n[1] Nuevo articulo");
                    Articulo nuevo;
                    int alta;
                    printf("\n\nCodigo: ");
                    fflush(stdin);
                    scanf("%s", nuevo.codigo);
                    strupr(nuevo.codigo);
                    printf("Articulo: ");
                    fflush(stdin);
                    fgets(nuevo.articulo, 52, stdin);
                    printf("Marca: ");
                    fflush(stdin);
                    fgets(nuevo.marca, 62, stdin);
                    printf("Valor: ");
                    fflush(stdin);
                    scanf("%f", &nuevo.valor);
                    printf("Cantidad: ");
                    fflush(stdin);
                    scanf("%i", &nuevo.cantidad);
                    printf("Club: ");
                    fflush(stdin);
                    fgets(nuevo.club, 72, stdin);
                    borrar_salto(&nuevo);
                    alta = alta_LVO(nuevo);
                    if(alta == 0)
                        printf("\nEl articulo ya existe\n\n");
                    else
                        printf("\nEl articulo fue agregado con exito\n\n");
                    system("pause");
                    break;
                }
            case 2: // -- Eliminar articulo
                {
                    encabezado();
                    printf("Lista Vinculada Ordenada\n"
                           "------------------------\n"
                           "\n[2] Eliminar articulo");
                    char cod[8];
                    int baja;
                    printf("\n\nCodigo: ");
                    fflush(stdin);
                    scanf("%s", cod);
                    strupr(cod);
                    baja = baja_LVO(cod, 0);
                    if(baja == 0)
                        printf("\nEl articulo no existe\n\n");
                    else
                        printf("\nEl articulo fue eliminado con exito\n\n");
                    system("pause");
                    break;
                }
            case 3: // -- Consultar articulo
                {
                    encabezado();
                    printf("Lista Vinculada Ordenada\n"
                           "------------------------\n"
                           "\n[3] Consultar articulo");
                    char cod[8];
                    printf("\n\nCodigo: ");
                    fflush(stdin);
                    scanf("%s", cod);
                    strupr(cod);
                    Articulo consulta = evocar_LVO(cod);
                    if(strcmp(consulta.codigo, "000000"))
                    {
                        imprimirArt(consulta);
                        printf("\n");
                    }
                    else
                        printf("\n\nEl articulo no existe\n\n");
                    system("pause");
                    break;
                }
            case 4: // -- Articulo entregado a club
                {
                    encabezado();
                    printf("Lista Vinculada Ordenada\n"
                           "------------------------\n"
                           "\n[4] Articulo entregado a club");
                    char cod[8];
                    printf("\n\nCodigo: ");
                    fflush(stdin);
                    scanf("%s", cod);
                    strupr(cod);
                    if (pertenece_LVO(cod) == 1)
                        printf("\nArticulo entregado a club\n\n");
                    else
                        printf("\nArticulo NO entregado a club\n\n");

                    system("pause");
                    break;
                }
            case 5: // -- Mostrar articulos
                {
                    encabezado();
                    printf("Lista Vinculada Ordenada\n"
                           "------------------------\n");
                    mostrar_LVO();
                    system("pause");
                    break;
                }
            case 6: // -- Memorizacion previa
                {
                    encabezado();
                    printf("Lista Vinculada Ordenada\n"
                           "------------------------\n");
                    memorizacion_previa(3);
                    system("pause");
                    break;
                }
        }
    }
    *op = -1;
}

int localizar_LVO(char codArt[], Nodo **posicion) //-- DEVUELVE: 1.Exito 0.Fracaso
{
    if (cant_LVO >0)
    {
        Nodo *aux = &LVO;
        Nodo *aux1 = &LVO;
        while ((aux != NULL) && (strcmp(aux->dato.codigo, codArt) < 0))
        {
            aux1 = aux;
            aux = aux->next;
        }
        *posicion = aux1;
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
        *posicion = &LVO;
        return 0;
    }

}

int alta_LVO(Articulo nuevo)
{
    if(cant_LVO < DIM)
    {
        Nodo *loc;
        if (localizar_LVO(nuevo.codigo, &loc) == 0)
        {
            Nodo *nuevoNodo = malloc(sizeof(Nodo));
            nuevoNodo->dato = nuevo;
            nuevoNodo->next = loc->next;
            loc->next = nuevoNodo;

            cant_LVO++;
            cant_altas_LVO++;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
        return 0;
}

int baja_LVO(char codArt[], int entrada)
{
    if(cant_LVO != 0)
    {
        Nodo *loc;
        char c = 'S';
        if(localizar_LVO(codArt, &loc) == 1)
        {
            Nodo *aux = loc->next;
            if(entrada == 0)
                c = confirmacion_baja(loc->next->dato);
            if(c == 'S' || c == 's' )
            {
                loc->next = loc->next->next;
                free(aux);
                cant_LVO--;
                cant_bajas_LVO++;
                return 1;
            }
            else
                return 0;


        }
        else
            return 0;
    }
    else
        return 0;
}

int pertenece_LVO(char codArt[])
{
    Nodo *loc;
    int per = localizar_LVO(codArt, &loc);
    if (per == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

Articulo evocar_LVO(char codArt[])
{
    Nodo *loc;
    Articulo aux;
    strcpy(aux.codigo, "000000");
    if(localizar_LVO(codArt, &loc) == 1)
    {
        cant_consultas_exito_LVO++;
        return loc->next->dato;
    }
    else
    {
        cant_consultas_fracaso_LVO++;
        return aux;
    }

}

void mostrar_LVO()
{
    if (cant_LVO == 0)
        printf("\n\tLa lista esta vacia\n\n");
    else
    {
        int i = 1;
        Nodo *aux = LVO.next;
        printf("\n\t----------LISTA DE ARTICULOS----------\n");
        while (aux != NULL)
        {
            imprimirArt(aux->dato);
            aux = aux->next;
            if ((i % 5) == 0)
            {
                printf("\n");
                system("pause");
            }
            i++;
        }
        printf("\n\tTotal de articulos: %d \n\n", cant_LVO);
    }
}
#endif // LVO_H_INCLUDED
