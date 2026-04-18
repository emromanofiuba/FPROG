/* PROBLEMA
Escribir un programa que permita al usuario ingresar los montos de las compras
de un cliente y que al finalizar informe por pantalla el importe total a pagar,
teniendo en cuenta que si éste supera los $1000 se le debe aplicar un 10% de descuento.
Se desconoce la cantidad de datos que se van a ingresar.
La carga de datos finaliza cuando el usuario ingresa el monto 0 (cero).
Se debe validar que no se ingresen montos negativos indicando al usuario monto invalido.
*/

/* ALGORITMO DE RESOLUCION
1. declarar las variables monto_compra, contador_compra, total_a_pagar, descuento
    1.1 inicializarlas
2. pedir al usuario ingresar el monto de una compra
3. validarlo con un while monto_compra != 0
    3.1 mostrar al usuario cuantas compras va
    3.2 sumar los monto_compra en total_a_pagar
    3.3 volver a solicitar el ingreso del monto de una compra
4. mostrar un mensaje que su compra ha finalizado.
5. si total_a_pagar >= 1000, se aplica el descuento
6. mostrar total a pagar
*/

# include <stdio.h>
# define LIMITE_DESCUENTO 1000


void main()
{
    float monto_compra, total_a_pagar, descuento, total_a_pagar_descuentado;
    int contador_compra;

    total_a_pagar = 0;
    total_a_pagar_descuentado = 0;
    contador_compra = 0;

    printf("Ingrese el monto de una compra: ");
    scanf("%f", &monto_compra);

    while (monto_compra != 0){
        while (monto_compra < 0) {
            printf("Ingrese un monto valido: ");
            scanf("%f", &monto_compra);
        }
        contador_compra++;
        printf("Compra n° %i\n", contador_compra);

        total_a_pagar += monto_compra;

        printf("\nIngrese nuevamente el monto de una compra: ");
        scanf("%f", &monto_compra);
    }

    printf("\n\nSu compra ha finalizado. Ahora debe pagar\n");

    if (total_a_pagar >= LIMITE_DESCUENTO) {
        descuento = total_a_pagar * 0.1;
        total_a_pagar_descuentado = total_a_pagar - descuento;
        printf("\nComo el total a pagar ($%.2f) es mayor a %i, se le aplica un 10 porciento de descuento.", total_a_pagar, LIMITE_DESCUENTO);
        printf("\nEntonces, el importe total a pagar es $%.2f\n", total_a_pagar_descuentado);
    }
    else
        printf("Total a pagar = $%.2f\n", total_a_pagar);
}