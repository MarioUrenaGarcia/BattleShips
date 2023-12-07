#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "battleship.h"

// Pruebaa

/*

  Mario Ureña García y Ricardo Ponce de León Vargas

  Descripción e intención del programa: Juego de Batalla Naval en C

*/

// Main ----------------------------------------------------------------------------

int main(int argc, char *argv[])
{

  // Variables
  int seleccion = 0;

  // Procesos
  seleccion = main_menu();

  do
  {
    switch (seleccion)
    {
    case 1: // Jugar contra Computadora
    {
      printf(YELLOW "\n\n\t\tJugar contra Computadora\n\n" RESET);
      partida_cpu();
      return_to_menu(&seleccion); // Función que regresa al menú principal
      break;
    }
    case 2: // Jugar contra Jugador
    {
      printf(YELLOW "\n\n\t\tJugar contra Jugador\n\n" RESET);
      partida_jugador();
      return_to_menu(&seleccion); // Función que regresa al menú principal
      break;
    }
    case 3: // Cargar Partida
    {
      printf(YELLOW "\n\n\t\tCargar Partida\n\n" RESET);
      reanudar_partida();
      return_to_menu(&seleccion); // Función que regresa al menú principal
      break;
    }
    case 4: // Salir del Juego
    {
      printf(YELLOW "\n\n\t\tSalir del Juego\n\n" RESET);

      // FINALIZACIÓN DEL PROGRAMA
      printf("\tPrograma Finalizado con ÉXITO\n\n");
      return 0;
      break;
    }
    case 5: // PRUEBAS
    {
      manual_usuario();
      return_to_menu(&seleccion); // Función que regresa al menú principal
      return 0;
    }
    }
  } while (1);

  printf("Algo Falló\n\n"); // Si llega a este punto es porque algo falló en el bucle principal
  return 1;
}