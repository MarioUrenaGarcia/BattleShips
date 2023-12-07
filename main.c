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
  if (argc == 1)
  {
    seleccion = main_menu();
  }
  else if (argc == 2)
  {
    system("clear");
    printf(RED " \n\n\tERROR: Faltan argumentos\n\n" RESET);
    return 1;
  }

  else if (argc > 2)
  {
    if (strcmp(argv[1], "-h") == 0)
    {
      seleccion = 5;
      return 0;
    }
    else if (strcmp(argv[1], "-1p") == 0)
    {
      seleccion = 1;
    }
    else if (strcmp(argv[1], "-2p") == 0)
    {
      partida_jugador_argv(argv);
      return_to_menu(&seleccion); // Función que regresa al menú principal
    }
    else if (strcmp(argv[1], "-f") == 0)
    {
      seleccion = 3;
    }
    else
    {
      printf("ERROR: Argumento no válido\n");
      return 1;
    }
  }
  else
  {
    printf("Argumento no válido\n");
    return 1;
  }
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