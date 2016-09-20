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
        printf("\n\t        Lista Vinculada Ordenada        \n"
                 "\t        ------------------------        \n"
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
                    printf("\n\t        Lista Vinculada Ordenada        \n"
                             "\t        ------------------------        \n"
                           "\n[1] Nuevo articulo");
                    Articulo nuevo;
                    int alta;
                    printf("\n\n Codigo: \t");
                    fflush(stdin);
                    scanf("%s", nuevo.codigo);
                    strupr(nuevo.codigo);
                    printf(" Articulo:\t");
                    fflush(stdin);
                    fgets(nuevo.articulo, 52, stdin);
                    printf(" Marca:\t\t");
                    fflush(stdin);
                    fgets(nuevo.marca, 62, stdin);
                    printf(" Valor($):\t");
                    fflush(stdin);
                    scanf("%f", &nuevo.valor);
                    printf(" Cantidad:\t");
                    fflush(stdin);
                    scanf("%i", &nuevo.cantidad);
                    printf(" Club:\t\t");
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
                    printf("\n\t        Lista Vinculada Ordenada        \n"
                             "\t        ------------------------        \n"
                           "\n[2] Eliminar articulo");
                    char cod[8];
                    int baja;
                    printf("\n\nCodigo: ");
                    fflush(stdin);
                    scanf("%s", cod);
                    strupr(cod);
                    baja = baja_LVO(cod, 0);
                    if(baja == 0)
                        printf("\nEl articulo %s no fue eliminado o no existe\n\n",cod);
                    else
                        printf("\nEl articulo %s fue eliminado con exito\n\n",cod);
                    system("pause");
                    break;
                }
            case 3: // -- Consultar articulo
                {
                    encabezado();
                    printf("\n\t        Lista Vinculada Ordenada        \n"
                             "\t        ------------------------        \n"
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
                        printf("\n\t El articulo %s no existe\n\n",cod);
                    system("pause");
                    break;
                }
            case 4: // -- Articulo entregado a club
                {
                    encabezado();
                    printf("\n\t        Lista Vinculada Ordenada        \n"
                             "\t        ------------------------        \n"
                           "\n[4] Articulo entregado a club");
                    char cod[8];
                    printf("\n\nCodigo: ");
                    fflush(stdin);
                    scanf("%s", cod);
                    strupr(cod);
                    if (pertenece_LVO(cod) == 1)
                        printf("\n\t Articulo codigo (%s) entregado a club\n\n",cod);
                    else
                        printf("\n\t Articulo codigo (%s) NO entregado a club\n\n",cod);

                    system("pause");
                    break;
                }
            case 5: // -- Mostrar articulos
                {
                    encabezado();
                    printf("\n\t        Lista Vinculada Ordenada        \n"
                             "\t        ------------------------        \n");
                    mostrar_LVO();
                    system("pause");
                    break;
                }
            case 6: // -- Memorizacion previa
                {
                    encabezado();
                    printf("\n\t        Lista Vinculada Ordenada        \n"
                             "\t        ------------------------        \n");
                    memorizacion_previa(3);
                    system("pause");
                    break;
                }
        }
    }
    *op = -1;
}

int localizar_LVO(char codArt[], Nodo **posicion, int conCosto) //-- DEVUELVE: 1.Exito 0.Fracaso
{
    consultadas = 0;
    if (cant_LVO >0)
    {
        Nodo *aux = LVO.next;
        Nodo *aux1 = &LVO;
        while ((aux != NULL) && (strcmp(aux->dato.codigo, codArt) < 0))
        {
            if(conCosto == 1)
                consultadas++;
            aux1 = aux;
            aux = aux->next;

        }
        if (aux != NULL)
            consultadas++;
        *posicion = aux1;
        if((aux != NULL) && strcmp(aux->dato.codigo, codArt) == 0)
            return 1;
        else
            return 0;
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
        if (localizar_LVO(nuevo.codigo, &loc, 0) == 0)
        {
            Nodo *nuevoNodo = malloc(sizeof(Nodo));
            nuevoNodo->dato = nuevo;

            /*if (loc->next == NULL)
            {
                total_corrimientos_alta_LVO += 0.5;
                if (maximo_alta_LVO < 0.5)
                    maximo_alta_LVO = 0.5;
            }
            else
            {*/
                total_corrimientos_alta_LVO += 1.0; // actualizo dos punteros, el del nuevo nodo y el del anterior
                if (maximo_alta_LVO < 1.0)
                    maximo_alta_LVO = 1.0;
            //}

            nuevoNodo->next = loc->next;
            loc->next = nuevoNodo;
            cant_LVO++;
            cant_altas_LVO++;
            return 1;
        }
        else
            return 0;
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
        if(localizar_LVO(codArt, &loc, 0) == 1)
        {
            Nodo *aux = loc->next;
            if(entrada == 0)
                c = confirmacion_baja(loc->next->dato);
            if(c == 'S' || c == 's' )
            {
                loc->next = loc->next->next;
                free(aux);
                total_corrimientos_baja_LVO+=0.5;
                if (maximo_baja_LVO < 0.5) maximo_baja_LVO = 0.5;
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
    int per = localizar_LVO(codArt, &loc, 0);
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
    if(localizar_LVO(codArt, &loc, 1) == 1)
    {
        total_consultadas_exito_LVO += consultadas;
        if(maximo_evo_exito_LVO < consultadas)
            maximo_evo_exito_LVO = consultadas;

        cant_evocaciones_exito_LVO++;
        return loc->next->dato;
    }
    else
    {
        total_consultadas_fracaso_LVO += consultadas;
        if(maximo_evo_fracaso_LVO < consultadas)
            maximo_evo_fracaso_LVO = consultadas;

        cant_evocaciones_fracaso_LVO++;
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
