#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "battleship.h"

/*

  Mario Ureña García y Ricardo Ponce de León Vargas

  Descripción e intención del programa: Juego de Batalla Naval en C

  Entradas:

  Salidas:

*/

// Main ----------------------------------------------------------------------------

int main(int argc, char *argv[])
{

  // Variables
  int tablero[10][10] = {0};

  // Procesos
  main_menu();

  // FINALIZACIÓN DEL PROGRAMA
  printf("\n\n\tPrograma Finalizado con ÉXITO\n\n");
  return 0;
}

// Funciones -----------------------------------------------------------------------
