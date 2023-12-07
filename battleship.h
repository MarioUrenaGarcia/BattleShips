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
#define CYAN "\x1b[36m" // EN EL TABLERO REPTESENTA UN ESPACIO VACÍO

#define TAB_SIZE 10 // Tamaño del tablero para que sea manipulable

// Estructuras____________________________________________________________________________________
typedef struct
{
  // Datos de identidad
  char nombre[264];                        // Nombre del jugador
  int tablero_defensa[TAB_SIZE][TAB_SIZE]; // Tablero de defensa del jugador, o sea donde tiene sus barcos, y donde verá donde le han atacado
  int tablero_ataque[TAB_SIZE][TAB_SIZE];  // Tablero de ataque del jugador, o sea donde elegira donde atacar, y donde verá donde ha atacado
  int num;                                 // Número de jugador, 1 o 2

  // Datos de juego
  /*
  La mina es un elemento de un solo uso en el juego.
  Esta se lanza a una casilla del tablero de ataque. Si cae sobre un barco, esta se destruye;
  pero si cae sobre una casilla vacía, esta se convierte en una mina activa que irá recorriendo
  turno por turno el tablero entero hasta que se encuentre con un barco, en cuyo caso este será
  destruido, o hasta que se acabe el juego, en cuyo caso la mina se desactiva.
  */
  int mina;      // Determina si el jugador puede lanzar una mina o no, osea cuantas hay en inventario. 0 = no, 1 = si
  int mina_viva; // Determina si la mina está activa o no, si esta no ha sido lanzada o si sigue sin encontrar un barco vale 0 y si ya explotó vale 1
  int mina_x;    // Ultima posición de la mina en x
  int mina_y;    // Ultima posición de la mina en y
  int mina_mapa; // Determina si la mina está en el mapa, 0 no 1 si

  int barcos_restantes; // Determina cuantos barcos le quedan al jugador

} PLAYER; // Estructura que representa a un jugador

// Interfaz_______________________________________________________________________________________

int main_menu();                                // Menú principal
void imprimir_tablero(int tablero[][TAB_SIZE]); // Imprime el tablero de juego, el tablero de entrada depende de la situación.
void return_to_menu(int *seleccion);            // Regresa al menú principal
void pantalla_cambio();                         // Pantalla de cambio de jugador
// Jugabilidad____________________________________________________________________________________
void partida_cpu();
void inicializar_tablero(int tablero[][TAB_SIZE]); // Inicializa un tablero de 10x10.
void colocar_barcos(int tablero[][TAB_SIZE], char nombre[]); // Posicionar barcos manualmente.
void colocar_barcos_azar(int tablero[][TAB_SIZE]); // Se colocan los barcos al azar en el tablero.
void atacar(int tablero_visible[][TAB_SIZE], int tablero_victima[][TAB_SIZE], int *acertado); // Función para que el jugador ataque una casilla del tablero del rival.
void ataque_azar(int tablero_victima[][TAB_SIZE], int *acertado, int *acertado_cpu, int casilla_disparada[2]); // Función para que la computadora ataque una casilla del tablero del rival. NO HAY TIROS CONSECUTIVOS.
int detectar_victoria(int tablero[][TAB_SIZE]); // Función para determinar si el jugador ha ganado o no.
void lanzamiento_mina(int tablero_visible[][TAB_SIZE], int tablero_victima[][TAB_SIZE], PLAYER *jugador, int *acertado); // Función para lanzar la mina acuática manualmente.
void mover_mina(PLAYER *jugador, int tablero_victima[][TAB_SIZE], int tablero_visible[][TAB_SIZE], int *acertado); // Funcion del movimiento de mina en el tablero.
void partida_jugador(); // Función que contiene toda la partida.
// General_______________________________________________________________________________________
int generar_numero(int limite); // Se decide que jugador sera el primero en jugar.
void mostrar_barra_carga(int paso, int total); // Impresion de una barra de carga para "generar" el tablero. (incliuye porcentaje)
char conv_mayus(char letra); // Convierte de minus a mayus.
void presionar_enter(); // Impersion en pantalla "PRESIONAR_ENTER", para continuar.
void limpiar_buffer(); // Esta función se utiliza para limpiar el buffer de entrada del teclado.

// Cargar y guardar_______________________________________________________________________________________
void guardar_partida(PLAYER jugador);