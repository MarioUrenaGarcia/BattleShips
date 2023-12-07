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

/**
 * Que hace: Pantalla para que el usuario no vea el tablero del otro jugador.
 */
void pantalla_cambio()
{
    system("clear");
    printf("\n\n\t Pasale la computadora a tu oponente, no seas tramposo\n\n");

    presionar_enter();
}

void manual_usuario()
{
    system("clear");

    printf("\n\n\t Inicio del Juego\n\n");

    printf("Elige el modo de juego: contra la computadora, contra otro jugador o cargar un juego guardado.\n\n");

    printf("Configura tu partida con opciones como semilla de aleatoriedad y la modalidad de la mina.\n\n");

    printf("Configuración de la Partida\n\n");

    printf("Decide quién comienza el juego con el primer turno mediante selección aleatoria.\n\n");

    printf("Introduce los nombres de los jugadores humanos.\n\n");

    printf("Coloca estratégicamente tus barcos en una matriz de 10x10, siguiendo las reglas de Battleships.\n\n");

    printf("Desarrollo del Juego\n\n");

    printf("Realiza turnos alternados entre los jugadores.\n\n");

    printf("En cada turno, verifica si el tiro anterior del rival atinó a alguno de tus barcos.\n\n");

    printf("Selecciona coordenadas para disparar en el tablero del rival.\n\n");

    printf("El juego indicará si el disparo fue acertado o falló.\n\n");

    printf("El juego termina cuando un jugador hunde todos los barcos del rival.\n\n");

    printf("Modalidad de Mina Acuática\n\n");

    printf("Antes de comenzar, elige la opción de utilizar una mina acuática.\n\n");

    printf("Cada jugador puede usarla una vez por juego en lugar de realizar un tiro normal.\n\n");

    printf("Elige una coordenada para colocar la mina en el tablero del rival.\n\n");

    printf("La mina se moverá aleatoriamente en cada turno, marcando casillas como tiros.\n\n");

    printf("Si la mina alcanza un barco, se considera un tiro acertado y la mina desaparece.\n\n");

    printf("Reglas Especiales\n\n");

    printf("Coordenadas: Usa el formato A1, B3, etc., para ingresar disparos.\n\n");

    printf("Posicionamiento de barcos: Indica la coordenada y dirección (A, B, D, I).\n\n");

    printf("Guardar y cargar juego: Guarda tu progreso y carga partidas anteriores.\n\n");

    printf("Ejecución del Programa desde la Línea de Comandos\n\n");

    printf("Inicia el juego con diferentes modos: un solo jugador, dos jugadores, cargar juego guardado.\n\n");

    printf("Personaliza la semilla de aleatoriedad y activa la modalidad de la mina si lo deseas.\n\n");

    printf("Ejemplos de Ejecución desde la Línea de Comandos\n\n");

    printf("./battleships.out: Inicia el juego de manera regular.\n\n");

    printf("./battleships.out -h: Despliega ayuda y el manual de usuario.\n\n");

    printf("./battleships.out -1p <nombre_del_jugador>: Crea un juego de un solo jugador.\n\n");

    printf("./battleships.out -1p <nombre_del_jugador> -s <semilla> -m: Configura un juego de un solo jugador con semilla y modalidad de mina.\n\n");

    printf("./battleships.out -2p <nombre_del_jugador1> <nombre_del_jugador_2>: Inicia un juego de dos jugadores.\n\n");

    printf("./battleships.out -2p <nombre_del_jugador1> <nombre_del_jugador_2> -s <semilla> -m: Configura un juego de dos jugadores con semilla y modalidad de mina.\n\n");

    printf("./battleships.out -f <ruta_archivo>: Carga y resume un juego guardado.\n\n");

    printf("¡Prepárate para la batalla submarina y que gane el estratega más astuto! \n\n");

}

        