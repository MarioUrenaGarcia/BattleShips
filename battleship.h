#define RED "\x1b[31m"
#define WHITE "\x1B[37m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

#define TAB_SIZE 10 // Tamaño del tablero para que sea manipulable
// Interfaz
int main_menu();
void imprimir_tablero(int tablero[][TAB_SIZE]);
void return_to_menu(int *seleccion);