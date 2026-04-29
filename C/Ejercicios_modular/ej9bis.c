#include <stdio.h>

#define CANT_PARTICIPANTES 5
#define CANT_SALTOS 3
#define ANIO_ACTUAL 2026

void ingresar_datos(int *p_num, int *p_fecha)
{
    printf("Numero de participante: ");
    scanf("%i", p_num);
    printf("Fecha de nacimiento (AAAAMMDD): ");
    scanf("%i", p_fecha);
}


float obtener_mejor_salto()
{
    float max_local = 0.0;
    float salto_actual;
    int j;

    for (j = 1; j <= CANT_SALTOS; j++) {
        printf("Ingrese salto %i: ", j);
        scanf("%f", &salto_actual);

        if (salto_actual > max_local)
            max_local = salto_actual;
    }
    return max_local;
}


int calcular_edad(int fecha_nacimiento)
{
    return ANIO_ACTUAL - (fecha_nacimiento / 10000);
}


void mostrar_resumen_atleta(int num, int edad, float marca)
{
    printf(">> Atleta %i | Edad: %i | Mejor Marca: %.2f m\n", num, edad, marca);
}


void marca_global(int num, float marca, int *p_ganador, float *p_mejor_marca)
{
    if (marca > *p_mejor_marca) {
        *p_mejor_marca = marca;
        *p_ganador = num;
    }
}
int main()
{
    int i;
    int num, fecha, edad;
    float marca_local;
    
    int num_ganador = 0;
    float mejor_marca_global = 0.0;

    for (i = 1; i <= CANT_PARTICIPANTES; i++) {
        printf("\n--- Procesando Atleta %i ---\n", i);
        
        ingresar_datos(&num, &fecha);
        
        marca_local = obtener_mejor_salto();
        
        edad = calcular_edad(fecha);
        
        
        /* 4. Punto A: Mostrar datos en pantalla */
        mostrar_resumen_atleta(num, edad, marca_local);
        
        /* 5. Punto B: Lógica de récord global (Pasaje por referencia para actualizar el main) */
        marca_global(num, marca_local, &num_ganador, &mejor_marca_global);
    }

    printf("\n========================================\n");
    printf("GANADOR GLOBAL: Participante Nro %i (%.2f m)\n", num_ganador, mejor_marca_global);
    printf("========================================\n");

    return 0;
}
