/* Funciones para Lista Secuencial Desordenada */
#ifndef LSD_H_INCLUDED
#define LSD_H_INCLUDED

char c[8];
Articulo temp;
int celda;

void menu_LSD(int *op)
{
    cant_LSD = 0;

    while (*op != 0)
    {
        encabezado();
        printf("Lista Secuencial Desordenada\n");
        printf("_____________________________\n");
        printf("\n[1] Nuevo articulo");
        printf("\n[2] Eliminar articulo");
        printf("\n[3] Consultar articulo");
        printf("\n[4] Articulo entregado a club");
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
            if(alta_LSD(nuevo) == 1) printf("\n Enhorabuena tio, El articulo fue agregado con exito\n\n");
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
            printf("\n\n Codigo: \t");
            int aux;
            Articulo temp;
            fflush(stdin);
            scanf("%s",c);
            strupr(c);
            temp=evocar_LSD(c,&aux);
            if (aux==1)
            {
                imprimirArt(temp);
            }
            else printf("\n\t El articulo %s no existe\n\n",c);
            system("pause");
            break;

        case 4:
            encabezado();
            printf("Lista Secuencial Desordenada\n");
            printf("_________________________\n");
            printf("\n[4] Articulo entregado a club\n");
            printf("\n Ingrese el codigo del articulo a consultar: ");
            fflush(stdin);
            scanf("%s",c);
            strupr(c);
            if (pertenece_LSD(c) == 1) printf("\n\t Articulo codigo (%s) entregado a club\n\n",c);
            else printf("\n\t Articulo codigo (%s) NO entregado a club\n\n",c);
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

int pertenece_LSD (char codArt [])
{
    int exito,celda;
    strupr(codArt);
    exito=localizar_LSD(codArt,&celda,0);
    return exito;
}

int localizar_LSD(char codArt[], int *i, int conCosto)            //Localizacion Exitosa=1, noExitosa=0, i=posicion donde esta el elemento o deberia estar
{
    //strupr(codArt);
    (*i)=0;
    while((*i)<cant_LSD && (strcmp(LSD[*i].codigo,codArt)!=0))
    {
        (*i)++;
    }
    if (((*i)<cant_LSD)==1 && conCosto==1) {
            if (maximo_cons_exito_LSD < (*i)){ maximo_cons_exito_LSD = (*i); }
            celd_cons_exito_LSD+=(*i);}

    if (((*i)<cant_LSD)==0 && conCosto==1){
            if (maximo_cons_fracaso_LSD < (*i)){ maximo_cons_fracaso_LSD = (*i); }
            celd_cons_fracaso_LSD+=(*i);}

    return (*i)<cant_LSD ;
}


int alta_LSD(Articulo nuevo) 	/// return(1)=exito  //return(0)=fracaso
{
    int celda,exito;
    exito=localizar_LSD(nuevo.codigo,&celda,0);
    if (cant_LSD==DIM)
    {
        return 0;
    }
    if ( exito == 0)
    {
        LSD[celda]=nuevo;
        maximo_alta_corr_LSD+=0;
        cant_LSD++;
        cant_altas_LSD++;
        return 1;
    }
    else
    {
        return 0;
    }
}

int baja_LSD(char codArt[], int tipo)
{
    int celda,exito;
    char c;
    strupr(codArt);
    exito=localizar_LSD(codArt,&celda,0);
    if ( exito == 1)
    {
        if(tipo == 0)
           c = confirmacion_baja(LSD[celda]);
        if(c == 'S' || c == 's' || tipo == 1 )
        {
            if (celda==cant_LSD-1)
            {
                celd_corr_baja_LSD+=0;
                cant_LSD--;
                cant_bajas_LSD++;
                return 1;
            }
            /*strcpy(LSD[celda].codigo,LSD[cant_LSD-1].codigo);
            strcpy(LSD[celda].articulo,LSD[cant_LSD-1].articulo);
            strcpy(LSD[celda].marca,LSD[cant_LSD-1].marca);
            strcpy(LSD[celda].club,LSD[cant_LSD-1].club);
            LSD[celda].cantidad=LSD[cant_LSD-1].cantidad;
            LSD[celda].valor=LSD[cant_LSD-1].valor;*/
            LSD[celda] = LSD[cant_LSD-1];
            cant_LSD--;
            cant_bajas_LSD++;
            celd_corr_baja_LSD+=1;
            if (maximo_baja_corr_LSD < 1) maximo_baja_corr_LSD+=1;
            return 1; // exito dando de baja
        }
        else
            return 0;
    }
    else
    {
        return 0; //fracaso dando de baja
    }
}

Articulo evocar_LSD (char codArt[],int *exito)
{
    int ex,celda;
    Articulo temp;
    strupr(codArt);
    ex=localizar_LSD(codArt,&celda,1);
    if (ex==1)
    {
        *exito=1;
        /*if (maximo_cons_exito_LSD < celda){ maximo_cons_exito_LSD = celda; }
        celd_cons_exito_LSD+=celda;
        cant_consultas_exito_LSD++;*/
        cant_consultas_exito_LSD++;
        return LSD[celda];
    }
    else
    {
        *exito=0;
        /*if (maximo_cons_fracaso_LSD < celda){ maximo_cons_fracaso_LSD = celda; }
        celd_cons_fracaso_LSD+=celda;
        cant_consultas_fracaso_LSD++;*/
        cant_consultas_fracaso_LSD++;
        return temp;
    }
}



#endif // LSD_H_INCLUDED
