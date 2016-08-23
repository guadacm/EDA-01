/*
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "principal.h"
#include "LSD.h"
#include "LSO.h"
#include "LVO.h"

int main()
{
    initLS(LSD);

    int opcion = 1;
// -- MENU PRINCIPAL
    while (opcion != 0)
    {
        principal(&opcion);
    }
    return 0;
}
