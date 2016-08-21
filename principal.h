#ifndef PRINCIPAL_H_INCLUDED
#define PRINCIPAL_H_INCLUDED
#define dim 170

typedef struct Articulo
{
	char codigo[8];
	char articulo[52];
	char marca[62];
	char club[72];
	float valor;
	int cantidad;
} Articulo;

/* PROTOTIPOS*/
void administracion(int *op);
void comparacion(int *op);
void menu_LSD(int *op);
void menu_LSO(int *op);
void menu_LVO(int *op);

void initLS (Articulo []);	            //sirve para LSD y/o LSO
int totalArticulos (Articulo []);       //sirve para LSD y/o LSO
void mostrar_LS (Articulo []);          //sirve para LSD y/o LSO

int localizar_LSD(char [], int *);
Articulo nuevoArticulo_LSD(char []);
int alta_LSD(char [], int );
/* FIN PROTOTIPOS */


Articulo temp;
Articulo Estructura_LSD[dim];
char c[8];
int celda;



void encabezado()
{
    system("cls");
    printf("\n\t****************************************\n");
    printf("\t*** ESTRUCTURA DE DATOS Y ALGORITMOS ***\n");
    printf("\t****************************************\n\n");
}

// -- MENU PRINCIPAL
void principal(int *op)
{
    encabezado();
    printf("\n[1] Administracion de estructuras");
    printf("\n[2] Comparacion de estructuras");
    printf("\n\n[0] Salir\n");
    printf("\nElija una opcion: ");
    scanf("%d", op);
    switch (*op)
    {
        case 0: break;
        case 1: administracion(op); break;
        case 2: comparacion(op); break;
    }
}

void administracion(int *op)
{
    while (*op !=0)
    {
        encabezado();
        printf("Administracion de estructuras\n");
        printf("_____________________________\n");
        printf("\n[1] Lista Secuencial Desordenada");
        printf("\n[2] Lista Secuencial Ordenada - Busqueda Binaria");
        printf("\n[3] Lista Vinculada Ordenada");
        printf("\n\n[0] Volver\n");
        printf("\nElija una opcion: ");
        scanf("%d", op);
        switch (*op)
        {
            case 0: break;
            case 1: menu_LSD(op); break;
            case 2: printf("Algo\n"); break;
            case 3: printf("Algo\n"); break;
        }
    }
    *op = -1;
}

void comparacion(int *op)
{
    encabezado();
    printf("Comparacion de estructuras\n");
    printf("_____________________________\n");
    printf("\n[1] ");
    printf("\n[2] ");
    printf("\n[3] ");
    printf("\n\n[0] Volver\n");
    printf("\nElija una opcion: ");
    scanf("%d", op);

}

#endif // PRINCIPAL_H_INCLUDED
