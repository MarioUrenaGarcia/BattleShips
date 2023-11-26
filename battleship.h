/*
  REGLAS
  1. Las cadenas de caracteres no deben superar el tamaño de [264]

*/

#define RED "\x1b[31m"
#define WHITE "\x1B[37m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

#define TAB_SIZE 10 // Tamaño del tablero para que sea manipulable

// Estructuras____________________________________________________________________________________
typedef struct
{
    // Datos de identidad
    char nombre[264];                        // Nombre del jugador
    int tablero_defensa[TAB_SIZE][TAB_SIZE]; // Tablero de defensa del jugador, osea donde tiene sus barcos, y donde verá donde le han atacado
    int tablero_ataque[TAB_SIZE][TAB_SIZE];  // Tablero de ataque del jugador, osea donde elegira donde atacar, y donde verá donde ha atacado
    int num;                                 // Número de jugador, 1 o 2

    // Datos de juego
    /*
    La mina es un elemento de un solo uso en el juego.
    Esta se lanza a una casilla del tablero de ataque. Si cae sobre un barco, esta se destruye;
    pero si cae sobre una casilla vacía, esta se convierte en una mina activa que irá recorriendo
    turno por turno el tablero entero hasta que se encuentre con un barco, en cuyo caso este será
    destruido, o hasta que se acabe el juego, en cuyo caso la mina se desactiva.
    */
    int mina;      // Determina si el jugador puede lanzar una mina o no
    int mina_viva; // Determina si la mina está activa o no, si esta no ha sido lanzada o si sigue sin encontrar un barco vale 0 y si ya explotó vale 1

    int barcos_restantes; // Determina cuantos barcos le quedan al jugador

} PLAYER; // Estructura que representa a un jugador

// Interfaz_______________________________________________________________________________________

int main_menu();                                // Menú principal
void imprimir_tablero(int tablero[][TAB_SIZE]); // Imprime el tablero de juego, el tablero de entrada depende de la situación.
void return_to_menu(int *seleccion);            // Regresa al menú principal