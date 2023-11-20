#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*

  Mario Ureña García y Ricardo Ponce de León Vargas

  Descripción e intención del programa:

  Entradas:

  Salidas:

*/

// Declarar Estructuras ------------------------------------------------------------

// Declarar funciones --------------------------------------------------------------
void main_menu();
// Main ----------------------------------------------------------------------------

int main(int argc, char *argv[])
{
  printf("\n\n\tEste código fue creado por Mario Ureña García y Ricardo Ponce de León Vargas\n\n");

  // Variables
  int tablero[10][10];
  // Procesos
  main_menu();
  // FINALIZACIÓN DEL PROGRAMA
  printf("\n\n\tPrograma Finalizado con ÉXITO\n\n");
  return 0;
}

// Funciones -----------------------------------------------------------------------

/**
 *   Que hace
 *   @param
 *   @return
 *   @Ejemplo
 */
void main_menu()
{
  int input;

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
    printf("Jugar contra Computadora");
    break;
  }
  case 2:
  {
    system("clear");
    printf("Jugar contra Jugador");
    break;
  }
  case 3:
  {
    system("clear");
    printf("Cargar Partida");
    break;
  }
  case 4:
  {
    system("clear");
    exit(0);
    break;
  }
  }
}
