#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *   Que hace: Imprime el menú principal del juego.
 */

int main_menu()
{
    int input;

    // Limpiar pantalla
    system("clear");

    // Créditos y TÍtulo
    printf("\n\n\tEste juego fue creado por Mario Ureña García y Ricardo Ponce de León Vargas\n\nBATTLESHIPS\n\n");

    // Opciones del menu_______________________________________________________________

    printf("\n1. Jugar contra Computadora");
    printf("\n2. Jugar contra Jugador");
    printf("\n3. Jugar contra Cargar Partida");
    printf("\n4. Salir del Juego");
    printf("\n\n");

    scanf("%d", &input);

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
void return_to_menu(int *seleccion)
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
}

/**
 * Imprime el tablero de juego.
 * @param tablero Matriz que representa el tablero de juego.
 */

void imprimir_tablero(int tablero[][10])
{
    int i, j;
    printf("\n");
    for (i = 0; i < 10; i++)
    {
        printf("\t");
        for (j = 0; j < 10; j++)
        {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }
}