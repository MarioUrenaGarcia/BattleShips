#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *   Que hace: Imprime el menú principal del juego
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
    case 1:
    {
        system("clear");
        printf("Jugar contra Computadora"); // Prueba de Funcionamiento de selección de modo de juego

        return 1;
        break;
    }
    case 2:
    {
        system("clear");
        printf("Jugar contra Jugador"); // Prueba de Funcionamiento de selección de modo de juego

        return 2;
        break;
    }
    case 3:
    {
        system("clear");
        printf("Cargar Partida"); // Prueba de Funcionamiento de selección de modo de juego

        return 3;
        break;
    }
    case 4: // Salir del Juego FUNCIONAL
    {
        system("clear");
        exit(0);
        break;
    }
    }
}
