# include <stdio.h>
# include <string.h>

typedef struct {
    char localidad[5];
    char central[4];
    char numero[5];
}t_telefono;


void pedir_localidad(char localidad_buscada[5])
{
    printf("Localidad buscada: ");
    scanf("%s", localidad_buscada);
}

void listar_telefonos(FILE *telefonos, char localidad_buscada[5])
{
    t_telefono telefono;

    fread(&telefono, sizeof(t_telefono), 1, telefonos);
    while (!feof(telefonos)){
        if (strcmp(telefono.localidad, localidad_buscada) == 0)
            printf("Telefono: %s-%s-%s\n", telefono.localidad, telefono.central, telefono.numero);
        fread(&telefono, sizeof(t_telefono), 1, telefonos);
    }
    
}

void listar_telefonos_ordenados(FILE *telefonos, char localidad_buscada[5])
{
    t_telefono telefono; int cmp;

    fread(&telefono, sizeof(t_telefono), 1, telefonos);
    cmp = strcmp(telefono.localidad, localidad_buscada);

    while (!feof(telefonos) && cmp <= 0){
        if (cmp == 0)
            printf("Telefono: %s-%s-%s\n", telefono.localidad, telefono.central, telefono.numero);
        fread(&telefono, sizeof(t_telefono), 1, telefonos);
        cmp = strcmp(telefono.localidad, localidad_buscada);
    }
}

void main()
{
    FILE *telefonos;
    char localidad_buscada[5];

    telefonos = fopen("telefonos.dat", "rb");
    if (telefonos == NULL)
        printf("No se pudo abrir el archivo");
    else {
        pedir_localidad(localidad_buscada);
        listar_telefonos(telefonos, localidad_buscada);
        fclose(telefonos);
    }
}