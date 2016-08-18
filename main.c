#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion = 1;

    while (opcion != 0){
        system("cls");
        printf("\n[1] Opcion 1");
        printf("\n[2] Opcion 2");
        printf("\n\n[0] Salir\n");
        printf("\nElija una opcion: ");
        scanf("%d", &opcion);
        switch (opcion){
            case 0: break;
            default: {
                system("cls");
                printf("\n\n..:{ Hello World! }:..\n\n");
                system("pause");
            }
        }
    }
    return 0;
}
