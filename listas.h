#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#define DIM 170
typedef struct Articulo
{
	char codigo[8];
	char articulo[52];
	char marca[62];
	float valor;
	int cantidad;
	char club[72];
} Articulo;

typedef struct nodo
{
    Articulo dato;
    struct nodo *next;
} Nodo;

/* PROTOTIPOS */
void encabezado();
void borrar_salto(Articulo *art);

// -- LSD
int localizar_LSD(char codigo[], int *i);
Articulo evocar_LSD (char codigo[],int *exito);

// -- LSO
int localizar_LSO(char codArt[], int *posicion);
int alta_LSO(Articulo nuevo);
int baja_LSO(char codArt[], int entrada);
int pertenece_LSO(char codArt[]);
Articulo evocar_LSO(char codArt[]);

// -- LVO
int localizar_LVO(char codArt[], Nodo **posicion);
int alta_LVO(Articulo nuevo);
int baja_LVO(char codArt[], int entrada);
int pertenece_LVO(char codArt[]);
Articulo evocar_LVO(char codArt[]);
void mostrar_LVO();
/* FIN PROTOTIPOS */


/* VARIABLES */
// -- LSD
Articulo LSD[DIM];
int cant_LSD;
int cant_altas_LSD;
int cant_bajas_LSD;
int cant_consultas_exito_LSD, cant_consultas_fracaso_LSD;
int celd_cons_exito_LSD, celd_cons_fracaso_LSD;
int maximo_cons_exito_LSD, maximo_cons_fracaso_LSD;
int maximo_alta_corr_LSD, maximo_baja_corr_LSD;
int celd_corr_baja_LSD;

// -- LSO
Articulo LSO[DIM];
int cant_LSO;
int cant_altas_LSO;
int cant_bajas_LSO;
int cant_consultas_exito_LSO, cant_consultas_fracaso_LSO;

// -- LVO
Nodo LVO; // Apunta al primer nodo de la lista
int cant_LVO;
int cant_altas_LVO;
int cant_bajas_LVO;
int cant_consultas_exito_LVO, cant_consultas_fracaso_LVO;
/* FIN VARIABLES */

void imprimirArt(Articulo Art)
{
    printf("\n Codigo: \t%s"
           "\n Articulo: \t%s"
           "\n Marca: \t%s"
           "\n Valor: \t$%.2f"
           "\n Cantidad: \t%i"
           "\n Club: \t\t%s\n",
            Art.codigo,
            Art.articulo,
            Art.marca,
            Art.valor,
            Art.cantidad,
            Art.club);
}

void mostrar_LS (Articulo LS[], int cant)             // Muestra la lista de articulos para LSD ò LSO
{
    if(cant == 0)
    {
        printf("\n\tLa lista esta vacia\n\n");
    }
    else
    {
        int i, j = 1;
        printf("\n\t----------LISTA DE ARTICULOS----------\n");
        for(i = 0; i < cant; i++)
        {
            imprimirArt(LS[i]);
            if ((j % 5) == 0)
            {
                printf("\n");
                system("pause");
            }
            j++;
        }
        printf("\n\tTotal de articulos: %d \n\n",cant);
    }

}

void memorizacion_previa(int lista) // lista: 1.LSD - 2.LSO - 3.LVO
{
    Articulo nuevo;
    FILE *fp;

    if ((fp = fopen("PruebaArticulos.txt", "r")) == NULL)
        printf("\n\nERROR: no se pudo abrir el archivo\n\n");
    else
    {
        while(!(feof(fp)))
        {
            fgets(nuevo.codigo, 8, fp);
            strupr(nuevo.codigo);
            fgets(nuevo.articulo, 52, fp);
            fgets(nuevo.marca, 62, fp);
            fscanf(fp, "%f\n", &nuevo.valor);
            fscanf(fp, "%i\n", &nuevo.cantidad);
            fgets(nuevo.club, 72, fp);
            borrar_salto(&nuevo);

            switch(lista)
            {
                case 1:
                    alta_LSD(nuevo);
                    break;
                case 2:
                    alta_LSO(nuevo);
                    break;
                case 3:
                    alta_LVO(nuevo);
                    break;

            }
        }
        printf("\n\nLa memorizacion se ha llevado a cabo\n\n");
    }
    fclose(fp);
}

char confirmacion_baja(Articulo baja)
{
    char c;
    printf("\n Codigo: \t%s", baja.codigo);
    printf("\n Articulo: \t%s", baja.articulo);
    printf("\n Marca: \t%s", baja.marca);
    printf("\n Valor: \t$%.2f", baja.valor);
    printf("\n Cantidad: \t%i", baja.cantidad);
    printf("\n Club: \t\t%s", baja.club);

    printf("\n\nEsta seguro que quiere eliminar este articulo? S/N: ");
    fflush(stdin);
    scanf("%c", &c);
    return c;
}

void borrar_salto(Articulo *art) //Borra en '\n' que almacena fgets.
{
    int i = 0;
    for (i = 0; i < 8; i++) { //Codigo
        if ((*art).codigo[i] == '\n') {
            (*art).codigo[i] = '\0';
        }
    }
    for (i = 0; i < 52; i++) { //Articulo
        if ((*art).articulo[i] == '\n') {
            (*art).articulo[i] = '\0';
        }
    }
    for (i = 0; i < 62; i++) { //Marca
        if ((*art).marca[i] == '\n') {
            (*art).marca[i] = '\0';
        }
    }
    for (i = 0; i < 72; i++) { //Club
        if ((*art).club[i] == '\n') {
            (*art).club[i] = '\0';
        }
    }
}

void lectura_archivo_operaciones()
{
    int cod_op,auxiliar;
    Articulo nuevo;
    FILE *fp;
    if((fp = fopen("Operaciones.txt", "r")) == NULL)
        printf("\n\nERROR: No se pudo abrir el archivo\n\n");
    else
    {
        while (!(feof(fp)))
        {
            fscanf(fp, "%d\n", &cod_op);
            if ((cod_op == 1) || (cod_op == 2)) // -- (1. Alta) (2. Baja)
            {
                fgets(nuevo.codigo, 8, fp);
                fgets(nuevo.articulo, 52, fp);
                fgets(nuevo.marca, 62, fp);
                fscanf(fp, "%f\n", &nuevo.valor);
                fscanf(fp, "%i\n", &nuevo.cantidad);
                fgets(nuevo.club, 72, fp);
            }
            else
                fgets(nuevo.codigo, 8, fp);

            strupr(nuevo.codigo);
            borrar_salto(&nuevo);

            switch(cod_op)
            {
                case 1:
                    alta_LSD(nuevo);
                    alta_LSO(nuevo);
                    alta_LVO(nuevo);
                    break;
                case 2:
                    baja_LSD(nuevo.codigo,1);
                    baja_LSO(nuevo.codigo,1);
                    baja_LVO(nuevo.codigo,1);
                    break;
                case 3:
                    evocar_LSD(nuevo.codigo,&auxiliar);
                    pertenece_LSO(nuevo.codigo);
                    pertenece_LVO(nuevo.codigo);
                    break;

            }
        }
        printf("\n\nLa secuencia de operaciones ha finalizado\n\n");
        fclose(fp);
    }
    system("pause");
}
#endif // LISTAS_H_INCLUDED
