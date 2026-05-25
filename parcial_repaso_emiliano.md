# Material de Consulta — Parcial FIUBA Fundamentos de Programación

**Profesor Gustavo Bianchi — Cátedra Azcurra**
**Para:** Emiliano (2 días para el parcial)

---

## Estrategia de estudio para los 2 días

**Tarde de hoy (4–5 horas):**
1. Repasar pasaje por valor vs. referencia — el 80% de los errores en parcial vienen de acá.
2. Leer ejercicios 1–4 de este documento.
3. Practicar a mano (sí, en papel) el ejercicio 5 — inserción en vector ordenado.

**Mañana de mañana (3–4 horas):**
1. Leer ejercicios 5–7 de este documento.
2. Repasar diagonales de matriz (índices `[i][i]` y `[i][N-1-i]`).
3. Antes de salir: escribir en papel los `typedef` y `#define` típicos. Tu mano tiene que conocerlos.

---

## Reglas del parcial — no olvides

1. **El `main` solo lleva instrucciones secuenciales.** Nada de `if`, `while`, `for` dentro del `main`.
2. **Las funciones NO imprimen resultados.** Devuelven por `return` o por parámetro de referencia.
3. **Nada de variables globales.** Todo se pasa por parámetros.
4. **Toda función con condición debe contemplar el caso borde** (vector vacío, cantidad cero).
5. **Prohibido `break`.** El ciclo termina cuando su condición de corte se cumple.
6. **Llaves:** función abre en columna 1 del renglón siguiente; estructuras de control abren en el mismo renglón.
7. **Una sola instrucción → sin llaves** en `if`, `for`, `while`.

---

# Ejercicio 1 — Función `es_primo` y programa modular asociado

**Original:** Guía de Funciones, Ej. 2.
**Variación:** Programa modular que recibe un rango `[a, b]` validado y devuelve la cantidad de primos en el rango y su sumatoria.

**Por qué cae:** La función `es_primo` es el bloque de construcción más reutilizado en parciales. Aparece en Modular Ej. 5, 6 y 12.

```c
#include <stdio.h>
#include <stdbool.h>

bool es_primo(int n)
{
    int i;
    bool primo;

    primo = (n >= 2);
    if (primo && n > 2 && n % 2 == 0)
        primo = false;
    for (i = 3; i <= n / 2 && primo; i += 2)
        if (n % i == 0)
            primo = false;
    return primo;
}

void leer_rango(int *min, int *max)
{
    bool valido;

    valido = false;
    while (!valido) {
        printf("Ingrese limite inferior: ");
        scanf("%d", min);
        printf("Ingrese limite superior: ");
        scanf("%d", max);
        valido = (*min <= *max);
        if (!valido)
            printf("Rango invalido. min debe ser <= max.\n");
    }
}

void contar_primos_rango(int min, int max, int *cantidad, long *suma)
{
    int i;

    *cantidad = 0;
    *suma = 0;
    for (i = min; i <= max; i++)
        if (es_primo(i)) {
            (*cantidad)++;
            *suma += i;
        }
}

int main(void)
{
    int min, max, cant;
    long suma;

    leer_rango(&min, &max);
    contar_primos_rango(min, max, &cant, &suma);
    printf("Primos en [%d, %d]: %d\n", min, max, cant);
    printf("Suma de primos: %ld\n", suma);

    return 0;
}
```

**Teoría — atención:**
- La condición de corte del `for` (`i <= n / 2 && primo`) **reemplaza al `break` prohibido**. Cuando encontramos un divisor, `primo` se vuelve `false` y el ciclo termina solo.
- `(*cantidad)++` con paréntesis **es obligatorio**: sin paréntesis, `*cantidad++` se parsea como `*(cantidad++)`, que incrementa el puntero, no el valor.
- Tipos: usar `long` para la suma porque el rango puede dar valores grandes.

---

# Ejercicio 2 — Descomposición con pasaje por referencia múltiple

**Original:** Guía de Funciones, Ej. 10 (segundos → días, horas, minutos, segundos).
**Variación:** Descomponer una distancia en **kilómetros, metros, centímetros y milímetros** dada una distancia en milímetros, con validación.

**Por qué cae:** Es **el** ejercicio para evaluar el dominio del pasaje por referencia con más de un valor de salida. Casi seguro cae algo así.

```c
#include <stdio.h>
#include <stdbool.h>

bool es_valido(long milimetros)
{
    return milimetros > 0;
}

void descomponer_distancia(long milimetros, int *km, int *m, int *cm, int *mm)
{
    long resto;

    *km = milimetros / 1000000;
    resto = milimetros % 1000000;
    *m = resto / 1000;
    resto = resto % 1000;
    *cm = resto / 10;
    *mm = resto % 10;
}

long leer_milimetros(void)
{
    long mm;
    bool valido;

    valido = false;
    while (!valido) {
        printf("Ingrese distancia en milimetros: ");
        scanf("%ld", &mm);
        valido = es_valido(mm);
        if (!valido)
            printf("Valor ingresado invalido.\n");
    }
    return mm;
}

int main(void)
{
    long total;
    int km, m, cm, mm;

    total = leer_milimetros();
    descomponer_distancia(total, &km, &m, &cm, &mm);
    printf("%ld mm = %d km, %d m, %d cm, %d mm\n", total, km, m, cm, mm);

    return 0;
}
```

**Teoría — atención:**
- La función `descomponer_distancia` retorna `void` porque **toda la información sale por los 4 parámetros pasados por referencia**.
- Uso `resto` local en lugar de modificar el parámetro `milimetros`: es prolijidad. El parámetro recibido se conserva intacto para uso posterior.
- En el `scanf` con `long` se usa `%ld`. Si fuera `long long`, sería `%lld`. **Tu mano debe saber esto sin pensar.**

---

# Ejercicio 3 — MCD por algoritmo de Euclides

**Original:** Guía de Funciones, Ej. 12.
**Variación:** Programa que calcula MCD y **MCM** de dos números.

**Por qué cae:** Algoritmo de Euclides es el "must know" de toda materia introductoria. Y la combinación MCD-MCM es típica.

```c
#include <stdio.h>

int mcd(int a, int b)
{
    int resto;

    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

int mcm(int a, int b)
{
    return (a * b) / mcd(a, b);
}

void leer_positivo(int *valor)
{
    do {
        printf("Ingrese un numero entero positivo: ");
        scanf("%d", valor);
    } while (*valor <= 0);
}

int main(void)
{
    int a, b;

    leer_positivo(&a);
    leer_positivo(&b);
    printf("MCD(%d, %d) = %d\n", a, b, mcd(a, b));
    printf("MCM(%d, %d) = %d\n", a, b, mcm(a, b));

    return 0;
}
```

**Teoría — atención:**
- Euclides: **MCD(a, b) = MCD(b, a mod b)**, hasta que `b = 0`. El último valor de `a` es el MCD.
- En Euclides, **se puede modificar `a` y `b` libremente porque son parámetros por valor** — no afectan al `main`.
- **Identidad clave:** `a * b = mcd(a, b) * mcm(a, b)`. De ahí `mcm = (a * b) / mcd`. Memorizarla.
- En el `main` no hay ningún `if` ni `while`: solo invocaciones y `printf`. **Así debe verse tu `main` en el parcial.**

---

# Ejercicio 4 — Vector: encontrar elemento extremo, su frecuencia y posiciones

**Original:** Guía de Arreglos, Ej. 5 (máximo + cantidad + posiciones).
**Variación:** Cargar vector de reales positivos (centinela 0), encontrar el **mínimo**, cuántas veces aparece y en qué posiciones.

**Por qué cae:** Patrón clásico de recorrido único con tres valores de salida. Pone a prueba el uso de vectores y el pasaje por referencia.

```c
#include <stdio.h>

#define MAX 100

typedef float vec_real_t[MAX];
typedef int vec_int_t[MAX];

void cargar_vector(vec_real_t v, int *ml)
{
    float dato;

    *ml = 0;
    printf("Ingrese valores positivos (0 para terminar):\n");
    scanf("%f", &dato);
    while (dato != 0 && *ml < MAX) {
        v[*ml] = dato;
        (*ml)++;
        scanf("%f", &dato);
    }
}

void buscar_minimo(vec_real_t v, int ml, float *minimo,
                   int *cantidad, vec_int_t posiciones)
{
    int i;

    *cantidad = 0;
    if (ml > 0) {
        *minimo = v[0];
        *cantidad = 1;
        posiciones[0] = 0;

        for (i = 1; i < ml; i++)
            if (v[i] < *minimo) {
                *minimo = v[i];
                *cantidad = 1;
                posiciones[0] = i;
            } else if (v[i] == *minimo) {
                posiciones[*cantidad] = i;
                (*cantidad)++;
            }
    }
}

void mostrar_resultados(float minimo, int cantidad, vec_int_t posiciones)
{
    int i;

    if (cantidad > 0) {
        printf("Minimo: %.2f\n", minimo);
        printf("Aparece %d vez/veces en las posiciones: ", cantidad);
        for (i = 0; i < cantidad; i++)
            printf("%d ", posiciones[i]);
        printf("\n");
    } else
        printf("No se ingresaron valores.\n");
}

int main(void)
{
    vec_real_t v;
    vec_int_t pos;
    int ml, cant;
    float min;

    cargar_vector(v, &ml);
    buscar_minimo(v, ml, &min, &cant, pos);
    mostrar_resultados(min, cant, pos);

    return 0;
}
```

**Teoría — atención:**
- **Recorrido único:** cuando encuentro un nuevo mínimo, reinicio el contador a 1 y guardo la posición. Si encuentro un valor igual al mínimo actual, lo agrego a las posiciones.
- El vector `posiciones` se pasa **sin `&`** porque los arrays en C se pasan implícitamente por referencia (se pasa la dirección del primer elemento). Esto es **fundamental** y siempre confunde.
- Las posiciones se muestran como `posiciones[i] + 1` porque el usuario espera ver posiciones desde 1, no desde 0.
- Caso borde: si `ml = 0`, `cantidad` queda en 0 y `mostrar_resultados` muestra el mensaje apropiado.

---

# Ejercicio 5 — Inserción en vector ordenado (un solo recorrido, sin auxiliar)

**Original:** Guía de Arreglos, Ej. 7.
**Variación:** Vector **ordenado descendentemente**, insertar manteniendo el orden descendente. Validar que haya espacio. Un solo recorrido, sin vector auxiliar.

**Por qué cae:** Es **el ejercicio filtro** del parcial. Quien lo hace bien aprueba seguro. La consigna prohíbe explícitamente usar auxiliar o más de un recorrido.

```c
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef int vector_t[MAX];

void cargar_vector_desc(vector_t v, int *ml)
{
    int i, cant;

    do {
        printf("Cantidad de elementos a cargar (1 a %d): ", MAX - 1);
        scanf("%d", &cant);
    } while (cant < 1 || cant > MAX - 1);
    *ml = cant;
    printf("Ingrese los valores en orden DESCENDENTE:\n");
    for (i = 0; i < *ml; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }
}

bool insertar_descendente(vector_t v, int *ml, int p)
{
    int i;
    bool insertado;

    insertado = false;
    if (*ml < MAX) {
        i = *ml;
        while (i > 0 && v[i - 1] < p) {
            v[i] = v[i - 1];
            i--;
        }
        v[i] = p;
        (*ml)++;
        insertado = true;
    }
    return insertado;
}

void mostrar_vector(vector_t v, int ml)
{
    int i;

    for (i = 0; i < ml; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void procesar_insercion(vector_t v, int *ml, int p)
{
    bool ok;

    ok = insertar_descendente(v, ml, p);
    if (ok)
        printf("Vector luego de insertar %d: ", p);
    else
        printf("No hay espacio. Vector sin modificar: ");
    mostrar_vector(v, *ml);
}

int main(void)
{
    vector_t v;
    int ml, p;

    cargar_vector_desc(v, &ml);

    printf("Vector original: ");
    mostrar_vector(v, ml);
    
    printf("Ingrese valor a insertar: ");
    scanf("%d", &p);
    procesar_insercion(v, &ml, p);

    return 0;
}
```

**Teoría — atención (LA CLAVE DEL EJERCICIO):**
- **El recorrido empieza desde el FINAL del vector.** Empiezo en `i = *ml` (la posición libre después del último).
- Mientras el elemento anterior `v[i-1]` sea menor que `p` (porque el orden es descendente), lo **muevo a la derecha**: `v[i] = v[i-1]`. Después decremento `i`.
- Cuando salgo del `while`, `i` apunta exactamente a la posición donde debo poner `p`.
- **Por qué un solo recorrido:** no recorro buscando primero y después insertando. Hago ambas cosas a la vez.
- **Por qué sin auxiliar:** los elementos se desplazan en el mismo vector, no copio a otro vector.
- Si fuera orden ascendente, la condición sería `v[i-1] > p`.
- Reservar `MAX - 1` como tope de carga es la práctica correcta para **garantizar siempre espacio** para una inserción.

---

# Ejercicio 6 — Matriz cuadrada: diagonales y verificación de simetría

**Original:** Guía de Arreglos, Matrices Ej. 2.
**Variación:** Matriz `N x N`, calcular suma de **ambas diagonales** y verificar si es **simétrica** (un solo recorrido del triángulo superior).

**Por qué cae:** La matriz cuadrada con diagonales es el ejercicio canónico de matrices. La verificación de simetría usa la optimización de recorrer **solo el triángulo superior**, que es el "extra" que diferencia un 7 de un 10.

```c
#include <stdio.h>
#include <stdbool.h>

#define N 4

typedef int matriz_t[N][N];

void cargar_matriz(matriz_t m)
{
    int i, j;

    printf("Ingrese los %d valores de la matriz %dx%d:\n", N * N, N, N);
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            printf("m[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
}

int sumar_diagonal_principal(matriz_t m)
{
    int i, suma;

    suma = 0;
    for (i = 0; i < N; i++)
        suma += m[i][i];
    return suma;
}

int sumar_diagonal_secundaria(matriz_t m)
{
    int i, suma;

    suma = 0;
    for (i = 0; i < N; i++)
        suma += m[i][N - 1 - i];
    return suma;
}

bool es_simetrica(matriz_t m)
{
    int i, j;
    bool simetrica;

    simetrica = true;
    for (i = 0; i < N - 1 && simetrica; i++)
        for (j = i + 1; j < N && simetrica; j++)
            if (m[i][j] != m[j][i])
                simetrica = false;
    return simetrica;
}

void mostrar_resultados(matriz_t m)
{
    printf("Suma diagonal principal: %d\n", sumar_diagonal_principal(m));
    printf("Suma diagonal secundaria: %d\n", sumar_diagonal_secundaria(m));
    if (es_simetrica(m))
        printf("La matriz es simetrica.\n");
    else
        printf("La matriz NO es simetrica.\n");
}

int main(void)
{
    matriz_t m;

    cargar_matriz(m);
    mostrar_resultados(m);

    return 0;
}
```

**Teoría — atención:**
- **Diagonal principal:** elementos `m[i][i]` — fila igual a columna.
- **Diagonal secundaria:** elementos `m[i][N-1-i]` — la fila y la columna **suman `N-1`**.
- **Optimización de simetría:** una matriz es simétrica si `m[i][j] == m[j][i]` para todo `i, j`. Pero si verifico el triángulo superior (j > i), ya cubro todos los pares. Por eso `j = i + 1`. **Esto es lo que la cátedra llama "optimizar la cantidad de iteraciones".**
- **Por qué `i < N - 1` en `es_simetrica`:** la última fila no tiene triángulo superior (no hay `j > N-1`), por lo que no hace falta entrar al `for` para `i = N - 1`.
- **Condición de corte sin `break`:** `&& simetrica` en ambos `for` permite terminar apenas se encuentra un par asimétrico.
- En el `main`, **la matriz `m` se pasa sin `&`** — los arrays multidimensionales también van implícitamente por referencia.

---

# Ejercicio 7 — Programa modular completo: capicúas en secuencia

**Original:** Guía de Programación Modular, Ej. 8 (combinado con Ej. 5).
**Variación:** Programa que ingresa números enteros positivos (centinela 0), guarda en un vector **solo los capicúas**, e informa cantidad, suma y el mayor de los capicúas.

**Por qué cae:** Es el típico "ejercicio integrador" de la última parte del parcial. Combina función booleana, vector, pasaje por referencia, recorrido y caso borde.

```c
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef int vector_t[MAX];

int invertir_numero(int n)
{
    int invertido;

    invertido = 0;
    while (n > 0) {
        invertido = invertido * 10 + n % 10;
        n /= 10;
    }
    return invertido;
}

bool es_capicua(int n)
{
    bool capicua;

    if (n < 0)
        capicua = false;
    else
        capicua = (n == invertir_numero(n));
    return capicua;
}

void cargar_capicuas(vector_t v, int *ml)
{
    int dato;

    *ml = 0;
    printf("Ingrese numeros enteros (0 para terminar):\n");
    scanf("%d", &dato);
    while (dato != 0 && *ml < MAX) {
        if (es_capicua(dato)) {
            v[*ml] = dato;
            (*ml)++;
        }
        scanf("%d", &dato);
    }
}

void calcular_estadisticas(vector_t v, int ml, long *suma, int *mayor)
{
    int i;

    *suma = 0;
    *mayor = 0;
    if (ml > 0) {
        *mayor = v[0];
        for (i = 0; i < ml; i++) {
            *suma += v[i];
            if (v[i] > *mayor)
                *mayor = v[i];
        }
    }
}

void mostrar_resultados(vector_t v, int ml, long suma, int mayor)
{
    int i;

    if (ml > 0) {
        printf("Capicuas encontrados (%d): ", ml);
        for (i = 0; i < ml; i++)
            printf("%d ", v[i]);
        printf("\nSuma de capicuas: %ld\n", suma);
        printf("Mayor capicua: %d\n", mayor);
    } else
        printf("No se ingresaron numeros capicuas.\n");
}

int main(void)
{
    vector_t capicuas;
    int cant, mayor;
    long suma;

    cargar_capicuas(capicuas, &cant);
    calcular_estadisticas(capicuas, cant, &suma, &mayor);
    mostrar_resultados(capicuas, cant, suma, mayor);

    return 0;
}
```

**Teoría — atención:**
- **`invertir_numero` no modifica el original:** `n` es parámetro por valor, lo descompongo con divisiones y módulos.
- **`es_capicua` es función booleana pura:** no imprime, solo retorna `bool`. Maneja el caso `n < 0` (los negativos nunca son capicúas).
- **`cargar_capicuas` filtra durante la carga:** el vector solo contiene los capicúas, no todos los ingresados. Esto es un patrón importante: **filtrar al cargar es más eficiente que cargar todo y filtrar después**.
- **`calcular_estadisticas` devuelve dos valores por referencia** (suma y mayor) — patrón clásico.
- **Caso borde explícito:** si `ml == 0`, las estadísticas quedan en 0 y `mostrar_resultados` informa correctamente.
- **El `main` es perfectamente secuencial:** declaración, carga, cálculo, muestra, return. **Así tiene que verse el `main` en TODO ejercicio del parcial.**

---

# Checklist final antes de entregar el parcial

Antes de levantar la mano y entregar la hoja, revisar:

- [ ] **`main` solo secuencial.** Sin `if`, sin `while`, sin `for`.
- [ ] **`#include <stdio.h>`** y, si uso `bool`, **`#include <stdbool.h>`**.
- [ ] **`#define`** para constantes en MAYÚSCULAS.
- [ ] **`typedef`** para tipos vector/matriz.
- [ ] **Toda función con vectores/matrices recibe el `ml` (máximo lógico)** además del vector.
- [ ] **Pasaje por referencia con `*`** en el formal y **`&`** en el actual (excepto vectores/matrices, que van sin `&`).
- [ ] **Casos borde contemplados:** vector vacío, `ml = 0`, divisores 0, números negativos.
- [ ] **Sin `break`.** Sin variables globales.
- [ ] **Llaves:** función en columna 1 del renglón siguiente, control en el mismo renglón.
- [ ] **Validaciones con `do-while`** o con `while` + flag.
- [ ] **Nada de `printf` o `scanf` dentro de funciones que calculan/procesan.**

---

**Suerte, Emiliano. Si seguís estos patrones, aprobás.**
