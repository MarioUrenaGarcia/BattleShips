#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "battleship.h"
/**
 *   Que hace: Imprime el menú principal del juego.
 */

int main_menu()
{
    int input;

    // Limpiar pantalla
    system("clear");

    // Créditos y TÍtulo
    printf("\n\n\tEste juego fue creado por Mario Ureña García y Ricardo Ponce de León Vargas\n\n");
    printf(YELLOW "BATTLESHIPS\n\n" RESET);

    // Opciones del menu_______________________________________________________________

    printf("\n1. Jugar contra Computadora");
    printf("\n2. Jugar contra Jugador");
    printf("\n3. Cargar Partida");
    printf("\n4. Salir del Juego");
    printf("\n5. PRUEBAS");
    printf("\n\n");

    scanf(" %d", &input);

    // Si la entrada no es válida volver a preguntar
    while (input < 1 || input > 5)
    {
        // Borrar pantalla y volver a imprimir el menú
        system("clear");

        // Reimprimir los créditos y el título
        printf("\n\n\tEste juego fue creado por Mario Ureña García y Ricardo Ponce de León Vargas\n\n");
        printf(YELLOW "BATTLESHIPS\n\n" RESET);
        printf("\n1. Jugar contra Computadora");
        printf("\n2. Jugar contra Jugador");
        printf("\n3. Jugar contra Cargar Partida");
        printf("\n4. Salir del Juego");
        printf("\n5. PRUEBAS");
        printf("\n\n");

        printf("\nEntrada no válida, intente de nuevo: ");
        scanf("%d", &input);
    }

    switch (input)
    {
    case 1: // Jugar contra Computadora
    {
        system("clear");
        return 1;
        break;
    }
    case 2: // Jugar contra Jugador
    {
        system("clear");
        return 2;
        break;
    }
    case 3: // Cargar Partida
    {
        system("clear");
        return 3;
        break;
    }
    case 4: // Salir del Juego FUNCIONAL
    {
        system("clear");
        return 4;
        break;
    }
    case 5: // Opción para hacer pruebas
    {
        system("clear");
        return 5;
        break;
    }
    }
}

/*
    Que hace: Abrir menu si presiona la tecla Q
*/
void return_to_menu(int *seleccion) // Seleccion es un puntero porque es necesario para el main, si no se usa el puntero solamente ejecuta la entrada que metiste al inicio por primera vez.
{
    char input;
    printf("\nPresione Q para regresar al menú principal: ");
    getchar();
    scanf("%c", &input);
    printf("\n\n");
    if (input == 'q' || input == 'Q')
    {
        *seleccion = main_menu(); // Regresar al menú principal
    }

    // Si la entrada no es válida volver a preguntar
    while (input != 'q' && input != 'Q')
    {
        // Borrar última línea anterior
        printf("\nEntrada no válida, intente de nuevo: ");
        getchar();
        scanf("%c", &input);
        printf("\n\n");
        if (input == 'q' || input == 'Q')
        {
            *seleccion = main_menu(); // Regresar al menú principal
        }
    }
}

/**
 * Imprime el tablero de juego, el tablero de entrada depende de la situación.
 * @param tablero Matriz que representa el tablero de juego.
 */

void imprimir_tablero(int tablero[][TAB_SIZE])
{
    int i, j;
    printf("\n");
    // Imprimir borde superior
    printf("\t   ");
    for (i = 0; i < TAB_SIZE; i++)
    {
        printf("--");
    }
    printf("\n");

    for (i = 0; i < TAB_SIZE; i++)
    {
        printf("\t");
        // Imprimir letras de fila
        printf("%c ", i + 65); // 65 es el valor ASCII de la letra A

        // Imprimir borde izquierdo
        printf("| ");

        for (j = 0; j < TAB_SIZE; j++)
        {
            if (tablero[i][j] == 0)
            {
                printf(CYAN "■ " RESET); // Imprimir espacio vacío. 0 Representa un espacio vacío
            }
            else if (tablero[i][j] == 1)
            {
                printf(BLUE "■ " RESET); // Imprimir espacio vacío. 1 Representa un Barco
            }
            else if (tablero[i][j] == 2)
            {
                printf(RED "■ " RESET); // Imprimir espacio vacío. 2 Representa un disparo fallido
            }
            else if (tablero[i][j] == 3)
            {
                printf(YELLOW "■ " RESET); // Imprimir espacio vacío. 3 Representa un disparo exitoso
            }
            else if (tablero[i][j] == 4)
            {
                printf(GREEN "■ " RESET); // Imprimir espacio vacío. 4 Representa una mina
            }
        }
        // Imprimir borde derecho
        printf("|");
        printf("\n");
    }

    // Imprimir borde inferior
    printf("\t  ");
    printf(" ");
    for (i = 0; i < TAB_SIZE; i++)
    {
        printf("--");
    }
    printf("\n");

    // Imprimir numeros de columna
    printf("\t    ");
    for (i = 1; i <= TAB_SIZE; i++)
    {
        if (i < 10)
        {
            printf("%d ", i);
        }
        else
        {
            printf("%d", i);
        }
    }

    printf("\n\n");
}
