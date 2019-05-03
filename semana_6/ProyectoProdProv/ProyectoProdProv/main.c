#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "products.h" //se necesita solo un include ( si luego se incluye otro .h dentro del primer .h )


int main()
{
    /*1. Todos los productos con su proveedor
    2. Por cada proveedor sus productos
    3. Por cada proveedor la cantidad de productos
    4. El precio promedio de los productos de cada proveedor
    5. El / Los proveedores que proveen la mayor cantidad de articulos*/
    sProduct productos [10] ;
    sProvider proveedores [3] ;
    createTestProducts( productos ) ;
    createTestProvider( proveedores ) ;
    showProductsArray( productos , proveedores , 10 , 3 ) ;

    return 0;
}
