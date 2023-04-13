// Granero Javier - Abril 12

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CLIENTES 5

char *tiposProductos[] = {"Galletas","Snacks","Cigarrillos","Caramelos","Bebidas"};

struct {

    int productoID;
    int cantidad;
    char *tipoProducto;
    float precioUnitario;

} typedef Producto;

struct {

    int clienteID;
    char *nombreCliente;
    int cantidadProductosAPedir;
    Producto *productos;

} typedef Cliente;

void cargar_datos_clientes(Cliente *lista, int cantidad);
void mostrar_lista_clientes(Cliente *lista, int cantidad);
float costo_total_producto(float precio, int cantidad);

int main() {

    int cantidad_clientes;
    Cliente *lista_clientes;

    printf("\n > Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidad_clientes);

    while(cantidad_clientes <= 0 || cantidad_clientes > MAX_CLIENTES) {

        if(cantidad_clientes <= 0) {
            printf("\n\t (!) Ingrese un valor positivo: ");
            scanf("%d", &cantidad_clientes);
        }
        else {
            printf("\n\t (!) La cantidad m%cxima de clientes es %d. Ingrese un valor permitido: ", 160, MAX_CLIENTES);
            scanf("%d", &cantidad_clientes);
        }

    }

    fflush(stdin);

    lista_clientes = (Cliente *) malloc(sizeof(Cliente) * cantidad_clientes);

    printf("\n\n\t --- Carga de datos de los clientes --- \n");

    cargar_datos_clientes(lista_clientes, cantidad_clientes);

    getchar();

    printf("\n\n\t --- Datos de los clientes --- \n");

    mostrar_lista_clientes(lista_clientes, cantidad_clientes);

    getchar();

    return 0;

}


void cargar_datos_clientes(Cliente *lista, int cantidad) {

    int i, j;
    char *buff;

    Producto *producto_aux;

    srand(time(NULL));

    for(i=0; i<cantidad; i++) {

        lista->clienteID = i+1;

        buff = (char *) malloc(sizeof(char) * 100);
        
        printf("\n > Ingrese el nombre del cliente %d: ", i+1);
        gets(buff);

        lista->nombreCliente = (char *) malloc(sizeof(char) * (strlen(buff) + 1));

        strcpy(lista->nombreCliente, buff);

        free(buff);

        lista->cantidadProductosAPedir = rand() % 5 + 1;

        lista->productos = (Producto *) malloc(sizeof(Producto) * lista->cantidadProductosAPedir);

        producto_aux = lista->productos;        // Sin este auxiliar no funciona (estudiar caso) (!)

        for(j=0; j<lista->cantidadProductosAPedir; j++) {

            producto_aux->productoID = j+1;

            producto_aux->tipoProducto = tiposProductos[rand() % 5];

            producto_aux->cantidad = rand() % 10 + 1;

            producto_aux->precioUnitario = (float) (rand() % 10000 + 10) / 100;

            producto_aux++;

        }

        lista++;

    }

}


void mostrar_lista_clientes(Cliente *lista, int cantidad) {

    int i, j;

    for(i=0; i<cantidad; i++) {

        float acum_pago_total = 0;

        printf("\n\n\t\t --- CLIENTE ID: %d --- \n", lista->clienteID);
        printf("\n\n > Nombre: %s", lista->nombreCliente);
        printf("\n > Cantidad de productos pedidos: %d", lista->cantidadProductosAPedir);

        for(j=0; j<lista->cantidadProductosAPedir; j++) {

            printf("\n\n >> PRODUCTO ID: %d", lista->productos->productoID);
            printf("\n\t >> Tipo de producto: %s", lista->productos->tipoProducto);
            printf("\n\t >> Cantidad pedida: %d", lista->productos->cantidad);
            printf("\n\t >> Precio unitario: $%.2f\n\n", lista->productos->precioUnitario);

            acum_pago_total = acum_pago_total + costo_total_producto(lista->productos->precioUnitario, lista->productos->cantidad);

            lista->productos++;
        
        }

        printf("\n\t >> Pago total del cliente %d: $%.2f", i+1, acum_pago_total);

        printf("\n\t\t --------------------- \n\n");

        lista++;

    }

}


float costo_total_producto(float precio, int cantidad) {

    return((precio * (float) cantidad));

}