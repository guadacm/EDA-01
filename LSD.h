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
        case 0:
            break;

        case 1:
            printf("\n Ingrese el codigo del nuevo articulo: ");
            fflush(stdin);
            scanf("%s",c);
            alta_LSD(c,0);
            system("pause");
            break;

        case 2:
            printf("Algo\n");
            system("pause");
            break;

        case 3:
            printf("\n Ingrese el codigo del articulo a consultar: ");
            fflush(stdin);
            scanf("%s",c);
            if (localizar_LSD(c,&celda) == 1)
            {
                printf("\n\t----------ARTICULO CONSULTADO----------\n");
                printf("\n Codigo: \t%s",Estructura_LSD[celda].codigo);
                printf("\n Articulo: \t%s",Estructura_LSD[celda].articulo);
                printf("\n Marca: \t%s",Estructura_LSD[celda].marca);
                printf("\n Club: \t\t%s",Estructura_LSD[celda].club);
                printf("\n Valor: \t$%.2f",Estructura_LSD[celda].valor);
                printf("\n Cantidad: \t%d",Estructura_LSD[celda].cantidad);
                printf("\n \n");
            }
            else printf("\n El articulo con codigo (%s) NO existe\n\n",c);
            system("pause");
            break;

        case 4:
            mostrar_LS(Estructura_LSD);
            system("pause");
            break;

        case 5:
            printf("Algo\n");
            system("pause");
            break;
        }
    }
    *op = -1;

}

void initLS (Articulo LS[])	                 //inicializa la estrucutura LSD ò LSO con "------" en el campo de codigo de cada articulo
{
    int i;
    for(i=0; i<dim; i++) strcpy(LS[i].codigo,"------");
}

int totalArticulos (Articulo LS[])           // total de articulos dentro de una LSD ò LSO
{
    int i;
    int total=0;
    for (i=0; i<dim; i++)
    {
        if(strcmp("------",LS[i].codigo) != 0) total++;
    }
    return total;
}

void mostrar_LS (Articulo LS[])             // Muestra la lista de articulos para LSD ò LSO
{
    int total,i;
    total=totalArticulos(LS);
    if(total==0)
    {
        printf("\n\tLa lista esta vacia\n");
        return;
    }
    printf("\n\t----------LISTA DE ARTICULOS----------\n");
    for(i=0; i<total; i++)
    {
        printf("\n Codigo: \t%s",LS[i].codigo);
        printf("\n Articulo: \t%s",LS[i].articulo);
        printf("\n Marca: \t%s",LS[i].marca);
        printf("\n Club: \t\t%s",LS[i].club);
        printf("\n Valor: \t$%.2f",LS[i].valor);
        printf("\n Cantidad: \t%d",LS[i].cantidad);
        printf("\n \n");
    }
    printf("\n\tTotal de articulos: %d \n\n",total);
}

int localizar_LSD(char codigo[], int *i)            //Localizacion Exitosa=1, noExitosa=0, i=posicion donde esta el elemento o deberia estar
{
    //char code[8];
    char vacio[8]= {'-','-','-','-','-','-'};
    //strcpy(code,codigo);
    //strupr(code);
    strupr(codigo);
    (*i)=0;
    while((*i)<dim && (strcmp(Estructura_LSD[*i].codigo,vacio)!=0))
    {
        if ( strcmp(Estructura_LSD[*i].codigo,codigo) == 0) return 1; // localizado
        else (*i)++;

    }
    if ((*i)<=dim ) return 0; //no localizado
}


Articulo nuevoArticulo_LSD(char codigo[])
{
    Articulo nuevo;
    strcpy(nuevo.codigo,codigo);
    printf("\n Ingrese los datos del nuevo articulo:\n\n");
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
    return nuevo;
}


int alta_LSD(char codigo[], int tipo) 	//int Tipo: (0)Entrada por telcado // (1)entrada por archivo  // return(1)=exito  //return(0)=fracaso
{
    int celda;
    Articulo temp;
    strupr(codigo);
    localizar_LSD(codigo,&celda);
    if (totalArticulos(Estructura_LSD)==dim)
    {
        printf("\nERROR: Estructura Llena.");
        return 0;
    }
    if ((strcmp(Estructura_LSD[celda].codigo,codigo)) != 0)
    {
        if (tipo==0)
        {
            Estructura_LSD[celda]=nuevoArticulo_LSD(codigo); //entrada por teclado
        }
        if (tipo==1)
        {
            // sentencias aun no creadas
        }
        printf("\nEl articulo codigo (%s) fue agregado satisfactoriamente!",codigo);
        return 1;
    }
    else
    {
        printf("\nERROR: Ya existe un articulo con el mismo codigo (%s).",codigo);
        return 0;
    }

}





#endif // LSD_H_INCLUDED
