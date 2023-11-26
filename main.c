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
  int seleccion = 0;
  // Procesos

  seleccion = main_menu();

  do
  {
    switch (seleccion)
    {
    case 1:
    {
      printf("\n\n\t\tJugar contra Computadora\n\n");
      return_to_menu(&seleccion); // Función que regresa al menú principal
      break;
    }
    case 2:
    {
      printf("\n\n\t\tJugar contra Jugador\n\n");
      return_to_menu(&seleccion); // Función que regresa al menú principal
      break;
    }
    case 3:
    {
      printf("\n\n\t\tCargar Partida\n\n");
      return_to_menu(&seleccion); // Función que regresa al menú principal
      break;
    }
    case 4:
    {
      printf("\n\n\t\tSalir del Juego\n\n");
      printf("\tPrograma Finalizado con ÉXITO\n\n");
      return 0;
      break;
    }
    case 5:
    {
      printf("PRUEBA\n\n");
      imprimir_tablero(tablero);
      return_to_menu(&seleccion); // Función que regresa al menú principal
      break;
    }
    }
  } while (1);

  // FINALIZACIÓN DEL PROGRAMA
  printf("Algo Falló\n\n");
  return 1;
}

// Funciones -----------------------------------------------------------------------
