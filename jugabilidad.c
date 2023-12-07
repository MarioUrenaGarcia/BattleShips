#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "battleship.h"

/*
    Que hace: Bucle de partida contra computadora, se encarga de que los jugadores se turnen para atacar y de que se acabe la partida cuando uno de los jugadores se quede sin barcos.
*/

void partida_jugador()
{
    // Variables
    PLAYER jugador1;  // Datos de jugador
    PLAYER jugador2;  // Datos de jugador 2
    int victoria = 0; // Para determinar si el juego ha terminado o no
    int turno = 2;    // Para determinar de quien es el turno
    int azar = 0;
    int acertado = 0;
    int acertado_cpu = 0;
    int casilla_disparada[2] = {0}; // Almacena la casilla en donde CPU disparo en la ronda anterior.
    // Procesos

    // Primero el jugador1 registra sus datos
    printf("JUGADOR 1 Introzca su nombre:     ");
    scanf("%s", jugador1.nombre);
    jugador1.num = 1;
    jugador1.mina = 1;
    jugador1.mina_viva = 0;
    jugador1.mina_mapa = 0;
    jugador1.barcos_restantes = 5;

    // Luego el jugador 2 registra sus datos
    printf("JUGADOR 2 Introzca su nombre:     ");
    scanf("%s", jugador2.nombre);
    jugador2.num = 2;
    jugador2.mina = 1;
    jugador2.mina_viva = 0;
    jugador2.mina_mapa = 0;
    jugador2.barcos_restantes = 5;

    // Luego se inicializan los tableros
    inicializar_tablero(jugador1.tablero_defensa);
    inicializar_tablero(jugador2.tablero_defensa);
    inicializar_tablero(jugador1.tablero_ataque);
    inicializar_tablero(jugador2.tablero_ataque);

    // Luego se colocan los barcos del jugador1
    system("clear");
    printf(YELLOW "\n\n\t%s ¿Quieres colocar tus barcos al azar? (1 Si/ 0 No):     " RESET, jugador1.nombre);
    scanf("%d", &azar);
    if (azar == 1)
    {
        printf(YELLOW "\n\nColocando tus Barcos:  \n" RESET);
        colocar_barcos_azar(jugador1.tablero_defensa);
    }
    else
    {
        colocar_barcos(jugador1.tablero_defensa, jugador1.nombre);
    }

    // Luego se colocan los barcos del jugador 2
    printf(YELLOW "\n\n\t%s ¿Quieres colocar tus barcos al azar? (1 Si/ 0 No):     " RESET, jugador2.nombre);
    scanf("%d", &azar);
    if (azar == 1)
    {
        printf(YELLOW "\n\nColocando tus Barcos:  \n" RESET);
        colocar_barcos_azar(jugador2.tablero_defensa);
    }
    else
    {
        colocar_barcos(jugador2.tablero_defensa, jugador2.nombre);
    }

    // Inicio de partida
    turno = generar_numero(2); // Se decide quien empieza
    system("clear");

    while (victoria == 0)
    {
        if (turno == 0) // turno de jugador 1
        {

            if (jugador1.mina_mapa == 1)
            {
                mover_mina(&jugador1, jugador2.tablero_defensa, jugador1.tablero_ataque, &acertado);
            }

            system("clear");
            printf(YELLOW "\n\n\t\tTurno de %s\n\n" RESET, jugador1.nombre);
            printf(BLUE "Tu tablero de defensa:     " RESET);

            if (acertado == 1)
            {
                printf(RED "¡Te han disparado un barco!\n" RESET);
            }
            else
            {
                printf(GREEN "No te han disparado ningún barco\n" RESET);
            }

            imprimir_tablero(jugador1.tablero_defensa);
            presionar_enter();

            system("clear");
            printf(YELLOW "\n\n\t\tTurno de %s\n\n" RESET, jugador1.nombre);
            printf(RED "Tu tablero de ATAQUE\n" RESET);
            imprimir_tablero(jugador1.tablero_ataque);

            if (jugador1.mina == 1)
            {
                printf(YELLOW "FASE DE MINA ACUÁTICA" RESET);
                lanzamiento_mina(jugador1.tablero_ataque, jugador2.tablero_defensa, &jugador1, &acertado);
            }

            printf(YELLOW "FASE DE DISPARO\n" RESET);
            atacar(jugador1.tablero_ataque, jugador2.tablero_defensa, &acertado);

            presionar_enter();
            turno = 1;
            victoria = detectar_victoria(jugador2.tablero_defensa);
            if (victoria == 1)
            {
                victoria = 1; // Determina que gano el jugador
            }
        }
        else if (turno == 1) // turno de jugador 2
        {

            if (jugador2.mina_mapa == 1)
            {
                mover_mina(&jugador2, jugador1.tablero_defensa, jugador2.tablero_ataque, &acertado);
            }

            system("clear");
            printf(YELLOW "\n\n\t\tTurno de %s\n\n" RESET, jugador2.nombre);
            printf(BLUE "Tu tablero de defensa:     " RESET);

            if (acertado == 1)
            {
                printf(RED "¡Te han disparado un barco!\n" RESET);
            }
            else
            {
                printf(GREEN "No te han disparado ningún barco\n" RESET);
            }

            imprimir_tablero(jugador2.tablero_defensa);
            presionar_enter();

            system("clear");
            printf(YELLOW "\n\n\t\tTurno de %s\n\n" RESET, jugador2.nombre);
            printf(RED "Tu tablero de ATAQUE\n" RESET);
            imprimir_tablero(jugador2.tablero_ataque);

            if (jugador2.mina == 1)
            {
                printf(YELLOW "FASE DE MINA ACUÁTICA" RESET);
                lanzamiento_mina(jugador2.tablero_ataque, jugador1.tablero_defensa, &jugador2, &acertado);
            }

            printf(YELLOW "FASE DE DISPARO\n" RESET);
            atacar(jugador2.tablero_ataque, jugador1.tablero_defensa, &acertado);

            presionar_enter();
            turno = 0;
            victoria = detectar_victoria(jugador1.tablero_defensa);
            if (victoria == 1)
            {
                victoria = 2; // Determina que gano el jugador
            }
        }

        // Guardar estado de partida
        guardar_partida(jugador1);
    }

    // Fin de partida
    if (victoria == 1)
    {
        system("clear");
        printf(GREEN "VICTORIA" RESET);
        printf(" de ");
        printf(YELLOW "%s\n" RESET, jugador1.nombre);
        imprimir_tablero(jugador1.tablero_defensa);
        printf("\n");
    }
    else if (victoria == 2)
    {
        system("clear");
        printf(GREEN "VICTORIA" RESET);
        printf(" de ");
        printf(YELLOW "%s\n" RESET, jugador2.nombre);
        imprimir_tablero(jugador2.tablero_defensa);
        printf("\n");
    }
}

/*
    Que hace: Bucle de partida contra computadora, se encarga de que los jugadores se turnen para atacar y de que se acabe la partida cuando uno de los jugadores se quede sin barcos.
*/

void partida_cpu()
{
    // Variables
    PLAYER jugador1;  // Datos de jugador
    PLAYER cpu;       // Datos de CPU
    int victoria = 0; // Para determinar si el juego ha terminado o no
    int turno = 2;    // Para determinar de quien es el turno
    int azar = 0;
    int acertado = 0;
    int acertado_cpu = 0;
    int casilla_disparada[2] = {0}; // Almacena la casilla en donde CPU disparo en la ronda anterior.
    // Procesos

    // Inicializar datos de CPU
    strcpy(cpu.nombre, "KAREN");
    cpu.num = 2;
    cpu.mina = 1;
    cpu.mina_viva = 0;
    cpu.mina_mapa = 0;
    cpu.barcos_restantes = 5;

    // Primero el jugador registra sus datos
    printf("Introzca su nombre:     ");
    scanf("%s", jugador1.nombre);
    jugador1.num = 1;
    jugador1.mina = 1;
    jugador1.mina_viva = 0;
    jugador1.mina_mapa = 0;
    jugador1.barcos_restantes = 5;

    // Luego se inicializan los tableros
    inicializar_tablero(jugador1.tablero_defensa);
    inicializar_tablero(cpu.tablero_defensa);
    inicializar_tablero(jugador1.tablero_ataque);
    inicializar_tablero(cpu.tablero_ataque);

    // Luego se colocan los barcos del jugador
    system("clear");
    printf(YELLOW "\n\n\t¿Quieres colocar tus barcos al azar? (1 Si/ 0 No):     " RESET);
    scanf("%d", &azar);
    if (azar == 1)
    {
        printf(YELLOW "\n\nColocando tus Barcos:  \n" RESET);
        colocar_barcos_azar(jugador1.tablero_defensa);
    }
    else
    {
        colocar_barcos(jugador1.tablero_defensa, jugador1.nombre);
    }

    // Luego se colocan los barcos de la CPU aleatoriamente
    printf(YELLOW "\n\nColocando los Barcos de %s:  \n" RESET, cpu.nombre);
    colocar_barcos_azar(cpu.tablero_defensa);

    // Inicio de partida
    turno = generar_numero(2); // Se decide quien empieza
    system("clear");

    while (victoria == 0)
    {
        if (turno == 0) // turno de jugador
        {

            if (jugador1.mina_mapa == 1)
            {
                mover_mina(&jugador1, cpu.tablero_defensa, jugador1.tablero_ataque, &acertado);
            }

            system("clear");
            printf(YELLOW "\n\n\t\tTurno de %s\n\n" RESET, jugador1.nombre);
            printf(BLUE "Tu tablero de defensa:     " RESET);

            if (acertado == 1)
            {
                printf(RED "¡Te han disparado un barco!\n" RESET);
            }
            else
            {
                printf(GREEN "No te han disparado ningún barco\n" RESET);
            }

            imprimir_tablero(jugador1.tablero_defensa);
            presionar_enter();

            system("clear");
            printf(YELLOW "\n\n\t\tTurno de %s\n\n" RESET, jugador1.nombre);
            printf(RED "Tu tablero de ATAQUE\n" RESET);
            imprimir_tablero(jugador1.tablero_ataque);

            if (jugador1.mina == 1)
            {
                printf(YELLOW "FASE DE MINA ACUÁTICA" RESET);
                lanzamiento_mina(jugador1.tablero_ataque, cpu.tablero_defensa, &jugador1, &acertado);
            }

            printf(YELLOW "FASE DE DISPARO\n" RESET);
            atacar(jugador1.tablero_ataque, cpu.tablero_defensa, &acertado);

            presionar_enter();
            turno = 1;
            victoria = detectar_victoria(cpu.tablero_defensa);
            if (victoria == 1)
            {
                victoria = 1; // Determina que gano el jugador
            }
        }
        else if (turno == 1) // turno de CPU
        {
            system("clear");
            printf(YELLOW "\n\n\t\tTurno de %s\n\n" RESET, cpu.nombre);
            mostrar_barra_carga(0, 100);
            ataque_azar(jugador1.tablero_defensa, &acertado, &acertado_cpu, casilla_disparada);
            mostrar_barra_carga(100, 100);
            system("clear");
            turno = 0;
            victoria = detectar_victoria(jugador1.tablero_defensa);
            if (victoria == 1)
            {
                victoria = 2; // Determina que gano el CPU
            }
        }

        // Guardar estado de partida
        guardar_partida(jugador1);
    }

    // Fin de partida
    if (victoria == 1)
    {
        system("clear");
        printf(GREEN "VICTORIA" RESET);
        printf(" de ");
        printf(YELLOW "%s\n" RESET, jugador1.nombre);
        imprimir_tablero(jugador1.tablero_defensa);
        printf("\n");
    }
}

/*
    Que hace: Inicializa un tablero de 10x10 con 0s
*/
void inicializar_tablero(int tablero[][TAB_SIZE])
{
    // Variables
    int i, j;

    // Procesos
    for (i = 0; i < TAB_SIZE; i++)
    {
        for (j = 0; j < TAB_SIZE; j++)
        {
            tablero[i][j] = 0;
        }
    }
}

/*
    Que hace: Función para que el usuario coloque sus barcos en el tablero.
    @param tablero: Tablero en el que se colocarán los barcos
    @param nombre: Nombre del jugador
*/
void colocar_barcos(int tablero[][TAB_SIZE], char nombre[])
{
    int i, j;
    int barcos[5] = {5, 4, 3, 3, 2}; // Arreglo que contiene los tamaños de los barcos
    char input;
    int x, y;             // Coordenadas de los barcos
    char direccion;       // Dirección de los barcos
    int direccion_valida; // Bandera para validar que la dirección sea válida en los bucles de comprobación

    // Bucle para colocar los barcos (5)
    for (i = 0; i < 5; i++)
    {
        system("clear");
        printf(YELLOW "\n\nColocando barcos de %s\n" RESET, nombre);
        imprimir_tablero(tablero);

        printf("Coloque un barco de tamaño %d\n", barcos[i]);

        // Pedir coordenada Y
        printf("Introduzca la coordenada y: ");
        scanf(" %c", &input);
        y = input - 'A'; // Convertir letra a número

        // Validar existencia de coordenada Y
        while (y > TAB_SIZE - 1 || y < 0)
        {
            printf("\nCoordenada no válida, intente de nuevo: ");
            scanf(" %c", &input);
            y = input - 'A';
        }

        // Pedir coordenada X
        printf("\nIntroduzca la coordenada x: ");
        scanf(" %d", &x);
        x = x - 1;

        // Validar existencia de coordenada X
        while (x > TAB_SIZE - 1 || x < 0)
        {
            printf("\nCoordenada no válida, intente de nuevo: ");
            scanf(" %d", &x);
            x = x - 1;
        }

        // validar que no cruce con otro barco
        while (tablero[y][x] == 1)
        {
            printf("\nCoordenadas no válida, intente de nuevo: ");
            printf("Introduzca la coordenada y: ");
            scanf(" %c", &input);
            y = input - 'A'; // Convertir letra a número

            printf("\nIntroduzca la coordenada x: ");
            scanf(" %d", &x);
            x = x - 1;
        }

        // Validar que el barco no se salga del tablero
        do
        {
            direccion_valida = 1; // Asumimos que la dirección es válida inicialmente
            printf("\nIntroduzca la dirección del barco (A, B, D, I): ");
            scanf(" %c", &direccion);

            if ((direccion == 'A' || direccion == 'a') && y - barcos[i] + 1 < 0)
            {
                direccion_valida = 0;
            }
            else if ((direccion == 'B' || direccion == 'b') && y + barcos[i] > TAB_SIZE)
            {
                direccion_valida = 0;
            }
            else if ((direccion == 'D' || direccion == 'd') && x + barcos[i] > TAB_SIZE)
            {
                direccion_valida = 0;
            }
            else if ((direccion == 'I' || direccion == 'i') && x - barcos[i] + 1 < 0)
            {
                direccion_valida = 0;
            }

            if (direccion_valida == 0)
            {
                printf("\nDirección no válida, intente de nuevo (el barco sale del tablero): ");
            }

        } while (direccion_valida == 0);

        // Validar que el barco no se cruce con otro barco
        do
        {
            direccion_valida = 1; // Asumimos que la dirección es válida inicialmente

            if (direccion == 'A' || direccion == 'a')
            {
                for (j = 0; j <= barcos[i]; j++)
                {
                    if (tablero[y - j][x] == 1)
                    {
                        direccion_valida = 0;
                    }
                }
            }
            else if (direccion == 'B' || direccion == 'b')
            {
                for (j = 0; j <= barcos[i]; j++)
                {
                    if (tablero[y + j][x] == 1)
                    {
                        direccion_valida = 0;
                    }
                }
            }
            else if (direccion == 'D' || direccion == 'd')
            {
                for (j = 0; j <= barcos[i]; j++)
                {
                    if (tablero[y][x + j] == 1)
                    {
                        direccion_valida = 0;
                    }
                }
            }
            else if (direccion == 'I' || direccion == 'i')
            {
                for (j = 0; j <= barcos[i]; j++)
                {
                    if (tablero[y][x - j] == 1)
                    {
                        direccion_valida = 0;
                    }
                }
            }

            if (direccion_valida == 0)
            {
                printf("\nDirección no válida, intente de nuevo (el barco se cruza con otro barco): ");
            }

        } while (direccion_valida == 0);

        // Colocar el barco en la matriz
        for (j = 0; j < barcos[i]; j++)
        {
            if (direccion == 'A' || direccion == 'a')
            {
                tablero[y - j][x] = 1;
            }
            else if (direccion == 'B' || direccion == 'b')
            {
                tablero[y + j][x] = 1;
            }
            else if (direccion == 'D' || direccion == 'd')
            {
                tablero[y][x + j] = 1;
            }
            else if (direccion == 'I' || direccion == 'i')
            {
                tablero[y][x - j] = 1;
            }
        }
    }
}

/*
    Que hace: Función para que la computadora coloque sus barcos en el tablero al azar.
    @param tablero: Tablero en el que se colocarán los barcos
*/
void colocar_barcos_azar(int tablero[][TAB_SIZE])
{
    int i, j;
    int barcos[5] = {5, 4, 3, 3, 2}; // Arreglo que contiene los tamaños de los barcos
    int x, y;                        // Coordenadas de los barcos
    char direccion;                  // Dirección de los barcos
    int direccion_valida;            // Bandera para validar que la dirección sea válida en los bucles de comprobación

    // Bucle para colocar los barcos (5)
    for (i = 0; i < 5; i++)
    {
        do
        {
            x = generar_numero(TAB_SIZE);
            y = generar_numero(TAB_SIZE);
            direccion = generar_numero(4);

            // Validar que el barco no se salga del tablero
            direccion_valida = 1; // Asumimos que la dirección es válida inicialmente

            if ((direccion == 0) && y - barcos[i] < 0) // Corregido: quitar el +1 en la condición
            {
                direccion_valida = 0;
            }
            else if ((direccion == 1) && y + barcos[i] >= TAB_SIZE)
            {
                direccion_valida = 0;
            }
            else if ((direccion == 2) && x + barcos[i] >= TAB_SIZE)
            {
                direccion_valida = 0;
            }
            else if ((direccion == 3) && x - barcos[i] < 0)
            {
                direccion_valida = 0;
            }

            // Validar que el barco no se cruce con otro barco
            if (direccion_valida == 1) // Comparación explícita
            {
                j = 0;
                while (direccion_valida == 1 && j < barcos[i]) // Comparación explícita y cambio de <= a <
                {
                    if (direccion == 0 && tablero[y - j][x] == 1)
                    {
                        direccion_valida = 0;
                    }
                    else if (direccion == 1 && tablero[y + j][x] == 1)
                    {
                        direccion_valida = 0;
                    }
                    else if (direccion == 2 && tablero[y][x + j] == 1)
                    {
                        direccion_valida = 0;
                    }
                    else if (direccion == 3 && tablero[y][x - j] == 1)
                    {
                        direccion_valida = 0;
                    }
                    j++;
                }
            }
        } while (direccion_valida == 0);

        // Colocar el barco en la matriz
        for (j = 0; j < barcos[i]; j++)
        {
            if (direccion == 0)
            {
                tablero[y - j][x] = 1;
            }
            else if (direccion == 1)
            {
                tablero[y + j][x] = 1;
            }
            else if (direccion == 2)
            {
                tablero[y][x + j] = 1;
            }
            else if (direccion == 3)
            {
                tablero[y][x - j] = 1;
            }
        }
        mostrar_barra_carga(i + 1, 5);
    }
    printf("\n");
}

/*
    Que hace: Función para que el jugador ataque una casilla del tablero del rival.
    @param tablero_visible: Tablero en el que se verá el proceso del ataque
    @param tablero_victima: Tablero en el que se verá afectad el resultado del ataque del usuario.
    @param acertado: Determina si el jugador ha acertado o no.
*/
void atacar(int tablero_visible[][TAB_SIZE], int tablero_victima[][TAB_SIZE], int *acertado)
{
    int x, y;
    char input;
    // Pedir coordenada Y
    printf("Introduzca la coordenada y: ");
    scanf(" %c", &input);

    input = conv_mayus(input); // Convertir a mayúscula
    y = input - 'A';           // Convertir letra a número

    // Validar existencia de coordenada Y
    while (y > TAB_SIZE - 1 || y < 0)
    {
        printf("\nCoordenada no válida, intente de nuevo: ");
        scanf(" %c", &input);
        y = input - 'A';
    }

    // Pedir coordenada X
    printf("Introduzca la coordenada x: ");
    scanf(" %d", &x);
    x = x - 1;

    // Validar existencia de coordenada X
    while (x > TAB_SIZE - 1 || x < 0)
    {
        printf("\nCoordenada no válida, intente de nuevo: ");
        scanf(" %d", &x);
        x = x - 1;
    }

    // Validar si se ha disparado a esa casilla antes
    while (tablero_visible[y][x] != 0)
    {
        printf("\nYa has disparado a esa casilla, intente de nuevo: ");
        printf("Introduzca la coordenada y: ");
        scanf(" %c", &input);
        input = conv_mayus(input); // Convertir a mayúscula
        y = input - 'A';           // Convertir letra a número

        // Validar existencia de coordenada Y
        while (y > TAB_SIZE - 1 || y < 0)
        {
            printf("\nCoordenada no válida, intente de nuevo\n\n");

            scanf(" %c", &input);
            y = input - 'A';
        }

        // Pedir coordenada X
        printf("Introduzca la coordenada x: ");
        scanf(" %d", &x);
        x = x - 1;

        // Validar existencia de coordenada X
        while (x > TAB_SIZE - 1 || x < 0)
        {
            printf("\nCoordenada no válida, intente de nuevo: ");
            scanf(" %d", &x);
            x = x - 1;
        }
    }

    // Realizar el ataque
    if (tablero_victima[y][x] == 1)
    {
        tablero_visible[y][x] = 3;
        tablero_victima[y][x] = 3;

        system("clear");
        printf(YELLOW "¡Le diste a un barco!\n" RESET);
        imprimir_tablero(tablero_visible);
        *acertado = 1;
    }
    else
    {
        tablero_visible[y][x] = 2;
        tablero_victima[y][x] = 2;
        system("clear");
        printf(RED "¡Fallaste!\n" RESET);
        imprimir_tablero(tablero_visible);
        *acertado = 0;
    }
}

/*
    Que hace: Función para que la computadora ataque una casilla del tablero del rival. NO HAY TIROS CONSECUTIVOS.
    @param tablero_victima: Tablero en el que se verá afectad el resultado del ataque del usuario.
    @param casilla_disparada: En caso de que en el tiro anterior le haya dado a un barco, se disparará en un rango adyacente a la casilla anteriormente disparada.
    @param acertado: Determina si el jugador ha acertado o no.
*/
void ataque_azar(int tablero_victima[][TAB_SIZE], int *acertado, int *acertado_cpu, int casilla_disparada[2])
{
    int x, y;
    int valido = 0;
    int direccion; // Variable para almacenar la dirección de ataque
    int adyacentes = 0;

    // Establecer las coordenadas basadas en la dirección seleccionada
    x = casilla_disparada[1];
    y = casilla_disparada[0];

    // Ver si las casillas adyacentes a la casilla anteriormente disparada son válidas
    if ((x + 1 >= TAB_SIZE || tablero_victima[y][x + 1] == 2 || tablero_victima[y][x + 1] == 3) && (x - 1 < 0 || tablero_victima[y][x - 1] == 2 || tablero_victima[y][x - 1] == 3) && (y + 1 >= TAB_SIZE || tablero_victima[y + 1][x] == 2 || tablero_victima[y + 1][x] == 3) && (y - 1 < 0 || tablero_victima[y - 1][x] == 2 || tablero_victima[y - 1][x] == 3))
    {
        adyacentes = 0;
    }
    else
    {
        adyacentes = 1;
    }

    if (*acertado_cpu == 1)
    {
        do
        {
            // Seleccionar una dirección aleatoria: 0 = arriba, 1 = abajo, 2 = izquierda, 3 = derecha
            direccion = generar_numero(4);

            if (direccion == 0 && y > 0)
                y--;
            else if (direccion == 1 && y < TAB_SIZE - 1)
                y++;
            else if (direccion == 2 && x > 0)
                x--;
            else if (direccion == 3 && x < TAB_SIZE - 1)
                x++;

            // Verificar que la casilla no haya sido atacada antes
            if (tablero_victima[y][x] != 2 && tablero_victima[y][x] != 3)
            {
                valido = 1;
            }
        } while (valido == 0);
    }
    else
    {
        // Si no acertó en el último disparo, elegir una casilla al azar
        do
        {
            x = generar_numero(TAB_SIZE);
            y = generar_numero(TAB_SIZE);
        } while (tablero_victima[y][x] == 2 || tablero_victima[y][x] == 3); // Evitar casillas ya atacadas
    }

    // Realizar el ataque
    if (tablero_victima[y][x] == 1)
    {
        tablero_victima[y][x] = 3;
        *acertado = 1;
        *acertado_cpu = 1;
        casilla_disparada[0] = y;
        casilla_disparada[1] = x;
    }
    else if (tablero_victima[y][x] == 0)
    {
        // En caso de que el disparo pasado haya sido un acierto, se marca la casilla como fallida , sin embargo, no se cambia el valor de acertado_cpu, para que en el siguiente turno se dispare en una casilla adyacente a la original
        if (*acertado_cpu == 1)
        {
            tablero_victima[y][x] = 2;
            *acertado = 0;
            *acertado_cpu = 1;
        }
        else if (*acertado_cpu == 1 && adyacentes == 0) // En caso de que cpu ya haya intentado con todas las casillas adyacentes, entonces ahora si se cambia el valor de acertado_cpu a 0, para que en el siguiente turno se dispare en una casilla aleatoria
        {
            tablero_victima[y][x] = 2;
            *acertado = 0;
            *acertado_cpu = 0;

            // Actualizar la última casilla disparada
            casilla_disparada[0] = y;
            casilla_disparada[1] = x;
        }
    }
}

/*
    Que hace: Función para determinar si el jugador ha ganado o no.
    @param tablero: Tablero en el que se verá afectad el resultado del ataque del usuario.
    @return victoria: Determina si el jugador ha ganado o no.
*/
int detectar_victoria(int tablero[][TAB_SIZE])
{
    int i, j;
    int victoria = 1; // Asumimos que el jugador ha ganado

    for (i = 0; i < TAB_SIZE; i++)
    {
        for (j = 0; j < TAB_SIZE; j++)
        {
            if (tablero[i][j] == 1)
            {
                victoria = 0; // Si encuentra un barco, entonces el jugador no ha ganado
            }
        }
    }

    return victoria;
}

/*
    Que hace: Función para lanzar la mina acuática manualmente.

    La mina es un elemento de un solo uso en el juego.
    Esta se lanza a una casilla del tablero de ataque. Si cae sobre un barco, esta se destruye;
    pero si cae sobre una casilla vacía, esta se convierte en una mina activa que irá recorriendo
    turno por turno el tablero entero hasta que se encuentre con un barco, en cuyo caso este será
    destruido, o hasta que se acabe el juego, en cuyo caso la mina se desactiva.

    @param tablero: Tablero en el que se verá afectad el resultado del ataque del usuario.
    @param jugador: Jugador que está lanzando la mina. Para desactivar la mina acuatica de su inventario.
*/
void lanzamiento_mina(int tablero_visible[][TAB_SIZE], int tablero_victima[][TAB_SIZE], PLAYER *jugador, int *acertado)
{
    int lanzar;
    int x, y;
    char input;

    if (jugador->mina == 1)
    {
        printf("\nDesea lanzar su mina? (1 Si/ 0 No):     ");
        scanf("%d", &lanzar);

        if (lanzar == 1)
        {
            // Pedir coordenada Y
            printf("Introduzca la coordenada y: ");
            scanf(" %c", &input);

            input = conv_mayus(input); // Convertir a mayúscula
            y = input - 'A';           // Convertir letra a número

            // Validar existencia de coordenada Y
            while (y > TAB_SIZE - 1 || y < 0)
            {
                printf("\nCoordenada no válida, intente de nuevo: ");
                scanf(" %c", &input);
                y = input - 'A';
            }

            // Pedir coordenada X
            printf("Introduzca la coordenada x: ");
            scanf(" %d", &x);
            x = x - 1;

            // Validar existencia de coordenada X
            while (x > TAB_SIZE - 1 || x < 0)
            {
                printf("\nCoordenada no válida, intente de nuevo: ");
                scanf(" %d", &x);
                x = x - 1;
            }

            // Validar si se ha disparado a esa casilla antes
            while (tablero_visible[y][x] != 0)
            {
                printf("\nYa has disparado a esa casilla, intente de nuevo: ");
                printf("Introduzca la coordenada y: ");
                scanf(" %c", &input);
                input = conv_mayus(input); // Convertir a mayúscula
                y = input - 'A';           // Convertir letra a número

                // Validar existencia de coordenada Y
                while (y > TAB_SIZE - 1 || y < 0)
                {
                    printf("\nCoordenada no válida, intente de nuevo\n\n");

                    scanf(" %c", &input);
                    y = input - 'A';
                }

                // Pedir coordenada X
                printf("Introduzca la coordenada x: ");
                scanf(" %d", &x);
                x = x - 1;

                // Validar existencia de coordenada X
                while (x > TAB_SIZE - 1 || x < 0)
                {
                    printf("\nCoordenada no válida, intente de nuevo: ");
                    scanf(" %d", &x);
                    x = x - 1;
                }
            }

            // Modificar la matriz para posicionar la mina en caso de que no haya colisionado con un barco
            if (tablero_victima[y][x] == 0)
            {
                tablero_visible[y][x] = 4;

                system("clear");
                printf(YELLOW "¡Mina colocada!\n" RESET);
                imprimir_tablero(tablero_visible);
                *acertado = 0;
            }
            else if (tablero_victima[y][x] == 1)
            {
                tablero_visible[y][x] = 3;
                tablero_victima[y][x] = 3;

                system("clear");
                printf(YELLOW "¡Le diste a un barco!\n" RESET);
                imprimir_tablero(tablero_visible);
                *acertado = 1;
            }

            // Desactivar mina del inventario
            jugador->mina = 0;
            jugador->mina_x = x;
            jugador->mina_y = y;
            jugador->mina_mapa = 1;
        }
    }
}

/*
    Que hace: Función para desplazar la mina acuatica en el tablero de ataque y defensa. La mina es como tirar 2 veces por partida, pues su posicion anterior antes
    de moverse la marca como atacada, y si en el siguiente turno se encuentra con un barco, este es marcado como atacado, y la mina se desactiva.

    La mina se desplaza aleatoriamente a una casilla adyacente a ella. Horizontal o Vertical.
    @param tablero_visible: Tablero en el que se verá el proceso del ataque
    @param tablero_victima: Tablero en el que se verá afectado el resultado del ataque del usuario.
*/
void mover_mina(PLAYER *jugador, int tablero_victima[][TAB_SIZE], int tablero_visible[][TAB_SIZE], int *acertado)
{
    int x, y;
    int direccion;
    int direccion_valida;
    int direcciones_invalidas[4] = {-1, -1, -1, -1};
    int fin_movimiento = 0;

    if (jugador->mina_viva == 0 && jugador->mina == 0)
    {
        // Establecer las coordenadas originales de la mina
        x = jugador->mina_x;
        y = jugador->mina_y;

        // Se analiza que la derecha x+ izquierda x- arriba y- abajo y+ no sean casillas atacadas (2 o 3) o que no esten fuera del arreglo, si las 4 casillas están atacadas o fuera del arreglo, la mina se desactiva y explota.
        // En caso de que se cumpla la condición anterior, entonces la mina explota y se desactiva.
        if ((x + 1 >= TAB_SIZE || tablero_victima[y][x + 1] == 2 || tablero_victima[y][x + 1] == 3) && (x - 1 < 0 || tablero_victima[y][x - 1] == 2 || tablero_victima[y][x - 1] == 3) && (y + 1 >= TAB_SIZE || tablero_victima[y + 1][x] == 2 || tablero_victima[y + 1][x] == 3) && (y - 1 < 0 || tablero_victima[y - 1][x] == 2 || tablero_victima[y - 1][x] == 3))
        {
            // Marcar la posición de la mina como atacada, y desactivarla
            tablero_visible[y][x] = 2;
            tablero_victima[y][x] = 2;
            jugador->mina_mapa = 0;
            jugador->mina_viva = 1;
        }
        else // En caso de que no esté atrapada, mover la mina
        {
            // Seleccionar una dirección aleatoria: 0 = arriba, 1 = abajo, 2 = izquierda, 3 = derecha
            do
            {
                do
                {
                    x = jugador->mina_x;
                    y = jugador->mina_y;

                    direccion = generar_numero(4);
                } while (direcciones_invalidas[direccion] == direccion);

                // Ajustar dirección de la mina
                if (direccion == 0)
                {
                    y--;
                }
                else if (direccion == 1)
                {
                    y++;
                }
                else if (direccion == 2)
                {
                    x--;
                }
                else if (direccion == 3)
                {
                    x++;
                }
                // Determinar si la dirección es válida
                // Determinar que el lugar a donde se moverá esté dentro del arreglo
                if (x < 0 || x >= TAB_SIZE || y < 0 || y >= TAB_SIZE)
                {
                    direccion_valida = 0;
                    direcciones_invalidas[direccion] = direccion;
                }
                else
                {
                    direccion_valida = 1;
                }

                // Determinar que el lugar a donde se moverá no esté atacado
                if (direccion_valida == 1 && (tablero_visible[y][x] == 2 || tablero_visible[y][x] == 3))
                {
                    direccion_valida = 0;
                    direcciones_invalidas[direccion] = direccion;
                }

                // Si el proceso de confirmacion fue exitoso entonces marcar la mina en su nuevo lugar
                if (direccion_valida == 1)
                {
                    // Si el sitio está vacío
                    if (tablero_victima[y][x] == 0)
                    {
                        tablero_visible[y][x] = 4;
                        fin_movimiento = 1;
                    }
                    // Si el sitio tiene un barco
                    else if (tablero_victima[y][x] == 1)
                    {
                        tablero_visible[y][x] = 3;
                        tablero_victima[y][x] = 3;
                        fin_movimiento = 1;
                        *acertado = 1;

                        // Desactivar mina
                        jugador->mina_mapa = 0;
                        jugador->mina_viva = 1;
                    }
                    // Dejar rastro
                    tablero_victima[jugador->mina_y][jugador->mina_x] = 2;
                    tablero_visible[jugador->mina_y][jugador->mina_x] = 2;

                    // Marcar la nueva posición de la mina
                    jugador->mina_x = x;
                    jugador->mina_y = y;
                }
            } while (fin_movimiento == 0);
        }
    }
}
