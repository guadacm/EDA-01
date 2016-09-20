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
        printf("\n\t       Lista Secuencial Ordenada        \n"
                 "\t       -------------------------        \n"
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
                    printf("\n\t       Lista Secuencial Ordenada        \n"
                             "\t       -------------------------        \n"
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
                    printf("\n\t       Lista Secuencial Ordenada        \n"
                             "\t       -------------------------        \n"
                           "\n[2] Eliminar articulo");
                    char cod[8];
                    int baja;
                    printf("\n\nCodigo: ");
                    fflush(stdin);
                    scanf("%s", cod);
                    strupr(cod);
                    baja = baja_LSO(cod, 0);
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
                    printf("\n\t       Lista Secuencial Ordenada        \n"
                             "\t       -------------------------        \n"
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
                        printf("\n\t El articulo %s no existe\n\n",cod);
                    system("pause");
                    break;
                }
            case 4: // -- Articulo entregado a club
                {
                    encabezado();
                    printf("\n\t       Lista Secuencial Ordenada        \n"
                             "\t       -------------------------        \n"
                           "\n[4] Articulo entregado a club");
                    char cod[8];
                    printf("\n\nCodigo: ");
                    fflush(stdin);
                    scanf("%s", cod);
                    strupr(cod);
                    if (pertenece_LSO(cod) == 1)
                        printf("\n\t Articulo codigo (%s) entregado a club\n\n",cod);
                    else
                        printf("\n\t Articulo codigo (%s) NO entregado a club\n\n",cod);

                    system("pause");
                    break;
                }
            case 5: // -- Mostrar articulos
                {
                    encabezado();
                    printf("\n\t       Lista Secuencial Ordenada        \n"
                             "\t       -------------------------        \n");
                    mostrar_LS(LSO, cant_LSO);
                    system("pause");
                    break;
                }
            case 6: // -- Memorizacion previa
                {
                    encabezado();
                    printf("\n\t       Lista Secuencial Ordenada        \n"
                             "\t       -------------------------        \n");
                    memorizacion_previa(2);
                    system("pause");
                    break;
                }
        }
    }
    *op = -1;

}

int localizar_LSO(char codArt[], int *posicion, int conCosto) //-- DEVUELVE: 1.Exito 0.Fracaso
{
    consultadas = 0;
    int li, ls, testigo, i;
    int aux[DIM];
    for(i = 0; i < DIM; i++)
        aux[i] = 0;
    if (cant_LSO != 0)
    {
        li = 0;
        ls = cant_LSO;
        while (li !=ls)
        {
            testigo = (li + ls - 1) / 2;
            aux[testigo] = 1;
            if(conCosto == 1) consultadas++;
            if(strcmp(codArt, LSO[testigo].codigo) > 0)
            {
                li = testigo + 1;
            }
            else
            {
                ls = testigo;
            }

        }
        *posicion = li;
        if(aux[li] == 0 && conCosto == 1)
            consultadas++;
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
        int corrimientos = 0;
        int loc;
        if (localizar_LSO(nuevo.codigo, &loc, 0) == 0)
        {
            int i;
            for(i = cant_LSO; i >= loc; i--)
            {
                LSO[i + 1] = LSO[i];
                corrimientos++;
            }
            LSO[loc] = nuevo;
            cant_LSO++;
            cant_altas_LSO++;
            total_corrimientos_alta_LSO = total_corrimientos_alta_LSO + corrimientos;
            if(maximo_alta_LSO < corrimientos)
                maximo_alta_LSO = corrimientos;
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
        int corrimientos = 0;
        int loc;
        char c = 'S';
        if(localizar_LSO(codArt, &loc, 0) == 1)
        {
            if(entrada == 0)
                c = confirmacion_baja(LSO[loc]);
            if(c == 'S' || c == 's' )
            {
                int i;
                for(i = loc; i<cant_LSO; i++)
                {
                    LSO[i] = LSO[i + 1];
                    corrimientos++;
                }
                cant_LSO--;
                cant_bajas_LSO++;
                total_corrimientos_baja_LSO = total_corrimientos_baja_LSO + corrimientos;
                if(maximo_baja_LSO < corrimientos)
                    maximo_baja_LSO = corrimientos;
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
    int per = localizar_LSO(codArt, &loc, 0) && (strcmp(LSO[loc].codigo, "ZZZZZZ") != 0);
    if (per == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

Articulo evocar_LSO(char codArt[])
{
    int loc;
    Articulo aux;
    strcpy(aux.codigo, "ZZZZZZ");
    if(localizar_LSO(codArt, &loc, 1) == 1)
    {

        if(maximo_evo_exito_LSO < consultadas)
            maximo_evo_exito_LSO = consultadas;

        total_consultadas_exito_LSO += consultadas;

        cant_evocaciones_exito_LSO++;
        return LSO[loc];
    }
    else
    {
        if(maximo_evo_fracaso_LSO < consultadas)
            maximo_evo_fracaso_LSO = consultadas;

        total_consultadas_fracaso_LSO += consultadas;

        cant_evocaciones_fracaso_LSO++;
        return aux;
    }

}

#endif // LSO_H_INCLUDED
