/* Funciones para Lista Secuencial Ordenada */
#ifndef LSO_H_INCLUDED
#define LSO_H_INCLUDED

void menu_LSO(int *op)
{
    cant_LSO = 0; // -- Inicializo la lista
    strcpy(LSO[0].codigo, "ZZZZZZ"); // -- +inf

    while (*op != 0)
    {
        encabezado();
        printf("Lista Secuencial Ordenada\n"
               "-------------------------\n"
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
            case 1: // -- Nuevo articulo
                {
                    encabezado();
                    printf("Lista Secuencial Ordenada\n"
                           "-------------------------\n"
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
                    alta = alta_LSO(nuevo);
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
                    printf("Lista Secuencial Ordenada\n"
                           "-------------------------\n"
                           "\n[2] Eliminar articulo");
                    char cod[8];
                    int baja;
                    printf("\n\nCodigo: ");
                    fflush(stdin);
                    scanf("%s", cod);
                    strupr(cod);
                    baja = baja_LSO(cod, 0);
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
                    printf("Lista Secuencial Ordenada\n"
                           "-------------------------\n"
                           "\n[3] Consultar articulo");
                    char cod[8];
                    printf("\n\nCodigo: ");
                    fflush(stdin);
                    scanf("%s", cod);
                    strupr(cod);
                    Articulo consulta = evocar_LSO(cod);
                    if(strcmp(consulta.codigo, "ZZZZZZ"))
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
                    printf("Lista Secuencial Ordenada\n"
                           "-------------------------\n"
                           "\n[4] Articulo entregado a club");
                    char cod[8];
                    printf("\n\nCodigo: ");
                    fflush(stdin);
                    scanf("%s", cod);
                    strupr(cod);
                    if (pertenece_LSO(cod) == 1)
                        printf("\nArticulo entregado a club\n\n");
                    else
                        printf("\nArticulo NO entregado a club\n\n");

                    system("pause");
                    break;
                }
            case 5: // -- Mostrar articulos
                {
                    encabezado();
                    printf("Lista Secuencial Ordenada\n"
                           "-------------------------\n");
                    mostrar_LS(LSO, cant_LSO);
                    system("pause");
                    break;
                }
            case 6: // -- Memorizacion previa
                {
                    encabezado();
                    printf("Lista Secuencial Ordenada\n"
                           "-------------------------\n");
                    memorizacion_previa(2);
                    system("pause");
                    break;
                }
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

int alta_LSO(Articulo nuevo) //-- DEVUELVE: 1.Exito 0.Fracaso.
{
    if (cant_LSO < DIM)
    {
        int loc;
        if (localizar_LSO(nuevo.codigo, &loc) == 0)
        {
            int i;
            for(i = cant_LSO; i >= loc; i--)
            {
                LSO[i + 1] = LSO[i];
            }
            LSO[loc] = nuevo;
            cant_LSO++;
            cant_altas_LSO++;
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

int baja_LSO(char codArt[], int entrada) //-- DEVUELVE: 1.Exito 0.Fracaso
{
    if(cant_LSO != 0)
    {
        int loc;
        char c = 'S';
        if(localizar_LSO(codArt, &loc) == 1)
        {
            if(entrada == 0)
                c = confirmacion_baja(LSO[loc]);
            if(c == 'S' || c == 's' )
            {
                int i;
                for(i = loc; i<cant_LSO; i++)
                {
                    LSO[i] = LSO[i + 1];
                }
                cant_LSO--;
                cant_bajas_LSO++;
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

int pertenece_LSO(char codArt[])
{
    int loc;
    int per = localizar_LSO(codArt, &loc) && (strcmp(LSO[loc].codigo, "ZZZZZZ") != 0);
    if (per == 1)
    {
        cant_consultas_exito_LSO++;
        return 1;
    }
    else
    {
        cant_consultas_fracaso_LSO++;
        return 0;
    }

}

Articulo evocar_LSO(char codArt[])
{
    int loc;
    Articulo aux;
    strcpy(aux.codigo, "ZZZZZZ");
    if(localizar_LSO(codArt, &loc) == 1)
        return LSO[loc];
    else
        return aux;
}

#endif // LSO_H_INCLUDED
