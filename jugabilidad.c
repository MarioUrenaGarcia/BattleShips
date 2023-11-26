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
    PLAYER jugador1; // Datos de jugador
    PLAYER cpu;      // Datos de CPU

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

    // Luego se colocan los barcos del jugador
    colocar_barcos(jugador1.tablero_defensa, jugador1.nombre);
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

void colocar_barcos(int tablero[][TAB_SIZE], char nombre[])
{
    int i, j;
    int barcos[5] = {5, 4, 3, 3, 2}; // Arreglo que contiene los tamaños de los barcos
    char input;
    int x, y;             // Coordenadas de los barcos
    char direccion;       // Dirección de los barcos
    int direccion_valida; // Bandera para validar que la dirección sea válida en los bucles de comprobación

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

        do
        {
            direccion_valida = 1; // Asumimos que la dirección es válida inicialmente
            printf("\nIntroduzca la dirección del barco (A, B, D, I): ");
            getchar();
            scanf("%c", &direccion);

            // Validar que el barco no se salga del tablero
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
