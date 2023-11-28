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
  int tablero[TAB_SIZE][TAB_SIZE] = {0};
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
      return_to_menu(&seleccion); // Función que regresa al menú principal
      break;
    }
    case 3: // Cargar Partida
    {
      printf(YELLOW "\n\n\t\tCargar Partida\n\n" RESET);
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
      // Código de prueba para verificar el funcionamiento de la función mover_mina
      int tablero_victima[TAB_SIZE][TAB_SIZE] = {0};
      int tablero_visible[TAB_SIZE][TAB_SIZE] = {0};
      int acertado = 0;

      PLAYER jugador;
      jugador.mina = 1;
      jugador.mina_viva = 0;
      jugador.mina_x = 0;
      jugador.mina_y = 0;

      lanzamiento_mina(tablero_visible, tablero_victima, &jugador, &acertado);
      while (jugador.mina_viva == 0)
      {
        mover_mina(&jugador, tablero_victima, tablero_visible, &acertado);
        imprimir_tablero(tablero_visible);
        getchar();
      }
      imprimir_tablero(tablero_visible);
      return 0;
    }
    }
  } while (1);

  printf("Algo Falló\n\n"); // Si llega a este punto es porque algo falló en el bucle principal
  return 1;
}