#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "battleship.h"

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
    int casilla_disparada[1][1]; // Almacena la casilla en donde CPU disparo en la ronda anterior.
    // Procesos

    // Inicializar datos de CPU
    strcpy(cpu.nombre, "KAREN");
    cpu.num = 2;
    cpu.mina = 1;
    cpu.mina_viva = 0;
    cpu.barcos_restantes = 5;

    // Primero el jugador registra sus datos
    printf("Introzca su nombre:     ");
    scanf("%s", jugador1.nombre);
    jugador1.num = 1;
    jugador1.mina = 1;
    jugador1.mina_viva = 0;
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
            printf("Presione enter para continuar");
            getchar();
            getchar();

            system("clear");
            printf(YELLOW "\n\n\t\tTurno de %s\n\n" RESET, jugador1.nombre);
            printf(RED "Tu tablero de ATAQUE\n" RESET);
            imprimir_tablero(jugador1.tablero_ataque);
            atacar(jugador1.tablero_ataque, cpu.tablero_defensa, &acertado);
            printf("Presione enter para continuar:  ");
            getchar();
            getchar();
            turno = 1;
        }
        else if (turno == 1) // turno de CPU
        {
            system("clear");
            printf(YELLOW "\n\n\t\tTurno de %s\n\n" RESET, cpu.nombre);
            ataque_azar(jugador1.tablero_defensa, &acertado, casilla_disparada);
            turno = 0;
        }
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
        getchar();
        scanf("%c", &input);
        y = input - 'A'; // Convertir letra a número

        // Validar existencia de coordenada Y
        while (y > TAB_SIZE - 1 || y < 0)
        {
            printf("\nCoordenada no válida, intente de nuevo: ");
            getchar();
            scanf("%c", &input);
            y = input - 'A';
        }

        // Pedir coordenada X
        printf("\nIntroduzca la coordenada x: ");
        scanf("%d", &x);
        x = x - 1;

        // Validar existencia de coordenada X
        while (x > TAB_SIZE - 1 || x < 0)
        {
            printf("\nCoordenada no válida, intente de nuevo: ");
            scanf("%d", &x);
            x = x - 1;
        }

        // Validar que el barco no se salga del tablero
        do
        {
            direccion_valida = 1; // Asumimos que la dirección es válida inicialmente
            printf("\nIntroduzca la dirección del barco (A, B, D, I): ");
            getchar();
            scanf("%c", &direccion);

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
    scanf("%c", &input);

    input = conv_mayus(input); // Convertir a mayúscula
    y = input - 'A';           // Convertir letra a número

    // Validar existencia de coordenada Y
    while (y > TAB_SIZE - 1 || y < 0)
    {
        printf("\nCoordenada no válida, intente de nuevo: ");
        scanf("%c", &input);
        y = input - 'A';
    }

    // Pedir coordenada X
    printf("\nIntroduzca la coordenada x: ");
    scanf("%d", &x);
    x = x - 1;

    // Validar existencia de coordenada X
    while (x > TAB_SIZE - 1 || x < 0)
    {
        printf("\nCoordenada no válida, intente de nuevo: ");
        scanf("%d", &x);
        x = x - 1;
    }

    // Validar si se ha disparado a esa casilla antes
    while (tablero_visible[y][x] != 0)
    {
        printf("\nYa has disparado a esa casilla, intente de nuevo: ");
        printf("Introduzca la coordenada y: ");
        scanf("%c", &input);
        input = conv_mayus(input); // Convertir a mayúscula
        y = input - 'A';           // Convertir letra a número

        // Validar existencia de coordenada Y
        while (y > TAB_SIZE - 1 || y < 0)
        {
            printf("\nCoordenada no válida, intente de nuevo\n\n");

            scanf("%c", &input);
            y = input - 'A';
        }

        // Pedir coordenada X
        printf("\nIntroduzca la coordenada x: ");
        scanf("%d", &x);
        x = x - 1;

        // Validar existencia de coordenada X
        while (x > TAB_SIZE - 1 || x < 0)
        {
            printf("\nCoordenada no válida, intente de nuevo: ");
            scanf("%d", &x);
            x = x - 1;
        }
    }

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
void ataque_azar(int tablero_victima[][TAB_SIZE], int *acertado, int casilla_disparada[1][1])
{
    // Variables
    int x, y;
    int mult = 0;       // Para determinar si la coordenada adyacente se sumara  o se le testara un 1.
    int valido = 0;     // Para elegir coordenada hasta que sea valida.
    int adyacentes = 1; // Para definir si todavía quedan casillas adyacentes igualadas en 0.

    // Procesos

    // Primero se valida si en la ronda anterior le dio a una casilla, y si es así, se dispara en un rango adyacente a la casilla anteriormente disparada.
    // Además, si ya no quedan espacios disponibles en valor 0 alrededor de esta, entonces ahora dispara en el rango completo (TAB_SIZE) al azar.

    if (*acertado == 1)
    {
        do
        {
            // Si le ha dado a una casilla, entonces dispara en un rango adyacente a esta.
            // Casilla anterios mas un numero aleatorio entre -1 y 1
            mult = generar_numero(2);
            if (mult == 0)
            {
                mult = -1;
            }
            x = casilla_disparada[0][0] + mult;

            // Validar que no se salga del tablero
            if (x > TAB_SIZE - 1 || x < 0)
            {
                x = casilla_disparada[0][0] - mult;
            }

            mult = generar_numero(2);
            if (mult == 0)
            {
                mult = -1;
            }
            y = casilla_disparada[0][0] + mult;

            // Validar que no se salga del tablero
            if (y > TAB_SIZE - 1 || y < 0)
            {
                y = casilla_disparada[0][0] - mult;
            }

            // Validar que no se haya disparado a esa casilla antes
            if (tablero_victima[y][x] == 0)
            {
                valido = 1;
            }

            // Validar que todavía haya casillas adyacentes en 0 alrededor de la casilla anteriormente disparada.
            if (tablero_victima[y + 1][x] == 0 || tablero_victima[y - 1][x] == 0 || tablero_victima[y][x + 1] == 0 || tablero_victima[y][x - 1] == 0)
            {
                adyacentes = 1;
            }
            // Si ya no hay casillas adyacentes entonces elegir en el rango completo de (TAB_SIZE)
            if (adyacentes == 0)
            {
                x = generar_numero(TAB_SIZE);
                y = generar_numero(TAB_SIZE);
                valido = 1;
            }
        } while (valido == 0);

        // Modificar matriz
        if (tablero_victima[y][x] == 1)
        {
            tablero_victima[y][x] = 3;
            *acertado = 1;
        }
        else
        {
            tablero_victima[y][x] = 2;
            *acertado = 0;
        }

        // Guardar coordenada disparada
        casilla_disparada[0][0] = x, y;
    }
    else
    {
        // Si no le ha dado a una casilla, entonces dispara al azar en todo el tablero.
        do
        {
            x = generar_numero(TAB_SIZE);
            y = generar_numero(TAB_SIZE);

            // Validar que no se haya disparado a esa casilla antes
            if (tablero_victima[y][x] == 0)
            {
                valido = 1;
            }
        } while (valido == 0);
        // Modificar matriz
        if (tablero_victima[y][x] == 1)
        {
            tablero_victima[y][x] = 3;
            *acertado = 1;
        }
        else
        {
            tablero_victima[y][x] = 2;
            *acertado = 0;
        }

        // Guardar coordenada disparada
        casilla_disparada[0][0] = x, y;
    }
}