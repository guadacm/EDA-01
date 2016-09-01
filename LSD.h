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
        printf("\n[4] Pertenece");
        printf("\n[5] Mostrar articulos");
        printf("\n[6] Memorizacion previa");
        printf("\n\n[0] Volver\n");
        printf("\nElija una opcion: ");
        scanf("%d", op);

        switch (*op)
        {
        case 0:
            break;

        case 1:
                encabezado();
                printf("Lista Secuencial Desordenada\n");
                printf("_________________________\n");
                printf("\n[1] Nuevo articulo");
                Articulo nuevo;
                printf("\n\n Codigo: \t");
                fflush(stdin);
                scanf("%s", nuevo.codigo);
                strupr(nuevo.codigo);
                printf(" Articulo:\t");
                fflush(stdin);
                scanf(" %[^\n]",nuevo.articulo);
                printf(" Marca:\t\t");
                fflush(stdin);
                scanf(" %[^\n]",nuevo.marca);
                printf(" Club:\t\t");
                fflush(stdin);
                scanf(" %[^\n]",nuevo.club);
                printf(" Cantidad:\t");
                fflush(stdin);
                scanf("%d",&nuevo.cantidad);
                printf(" Valor($):\t");
                fflush(stdin);
                scanf("%f",&nuevo.valor);
                if(alta_LSD(nuevo, 0) == 1) printf("\n Enhorabuena tio, El articulo fue agregado con exito\n\n");
                else printf("\nYa existe ese codigo, ingresaste los datos al pe :( \n\n");
                system("pause");
                break;

        case 2:
            encabezado();
            printf("Lista Secuencial Desordenada\n");
            printf("_________________________\n");
            printf("\n[2] Eliminar articulo");
            printf("\n\n Codigo: \t");
            fflush(stdin);
            scanf("%s",c);
            strupr(c);
            if(baja_LSD(c,0)==1) printf("\nEl articulo %s fue eliminado con exito\n\n",c);
            else printf("\nEl articulo %s no fue eliminado o no existe\n\n",c);
            system("pause");
            break;

        case 3:
            encabezado();
            printf("Lista Secuencial Desordenada\n");
            printf("_________________________\n");
            printf("\n[3] Consultar articulo\n");
            printf("Algo\n");
            system("pause");
            break;

        case 4:
            encabezado();
            printf("Lista Secuencial Desordenada\n");
            printf("_________________________\n");
            printf("\n[4] Pertenece\n");
            printf("\n Ingrese el codigo del articulo a consultar: ");
            fflush(stdin);
            scanf("%s",c);
            strupr(c);
            if (pertenece_LSD(c) == 1) printf("\n\t El articulo codigo (%s) PERTENECE\n\n",c);
            else printf("\n\t El articulo codigo (%s) NO PERTENECE\n\n",c);
            system("pause");
            break;

        case 5:
            encabezado();
            printf("Lista Secuencial Desordenada\n");
            printf("_________________________\n");
            printf("\n[5] Mostrar Estructura\n");
            mostrar_LS(LSD,cant_LSD);
            system("pause");
            break;

        case 6:
            encabezado();
            printf("Lista Secuencial Desordenada\n");
            printf("_________________________\n");
            printf("\n[6] Memorizacion Previa\n");
            memorizacion_previa(1);
            system("pause");
            break;
        }
    }
    *op = -1;

}
int pertenece_LSD (char codigo []){
    int i=0;
    while(i<cant_LSD && (strcmp(LSD[i].codigo,codigo)!=0)){i++;}
    return i<cant_LSD ;
}

int localizar_LSD(char codigo[], int *i)            //Localizacion Exitosa=1, noExitosa=0, i=posicion donde esta el elemento o deberia estar
{
    //char code[8];
    //strcpy(code,codigo);
    //strupr(code);
    strupr(codigo);
    (*i)=0;
    while((*i)<cant_LSD && (strcmp(LSD[*i].codigo,codigo)!=0)){(*i)++;}
    return (*i)<cant_LSD ;
    //if ( strcmp(LSD[*i].codigo,codigo) == 0) return 1; // localizado
    //else return 0; //no localizado
}


int alta_LSD(Articulo nuevo, int tipo) 	//int Tipo: (0)Entrada por telcado // (1)entrada por archivo  // return(1)=exito  //return(0)=fracaso
{
    int celda,exito;
    exito=localizar_LSD(nuevo.codigo,&celda);
    //printf("\n exito de localizar=%d - Celda=%d\n",exito,celda);
    if (cant_LSD==DIM)
    {
        //printf("\nERROR: Estructura Llena.");
        return 0;
    }
    if ( exito == 0)
    {
        if (tipo==0)
        {
            LSD[celda]=nuevo; //entrada por teclado
        }
        if (tipo==1)
        {
            LSD[celda]=nuevo;
        }
        cant_LSD+=1;
        return 1;
    }
    else
    {
        return 0;
    }

}

int baja_LSD(char codigo[], int tipo){
    int celda,exito;
    char c;
    strupr(codigo);
    exito=localizar_LSD(codigo,&celda);
    if ( exito == 1)
    {
        if(tipo == 0)
                c = confirmacion_baja_LS(LSD[celda]);
            if(c == 'S' || c == 's' )
        {
        if (celda==cant_LSD-1){cant_LSD-=1; return 1;}
        strcpy(LSD[celda].codigo,LSD[cant_LSD-1].codigo);
        strcpy(LSD[celda].articulo,LSD[cant_LSD-1].articulo);
        strcpy(LSD[celda].marca,LSD[cant_LSD-1].marca);
        strcpy(LSD[celda].club,LSD[cant_LSD-1].club);
        LSD[celda].cantidad=LSD[cant_LSD-1].cantidad;
        LSD[celda].valor=LSD[cant_LSD-1].valor;
        cant_LSD-=1;
        return 1; // exito dando de baja
        }
    }
    else
    {
        return 0; //fracaso dando de baja
    }

}





#endif // LSD_H_INCLUDED
