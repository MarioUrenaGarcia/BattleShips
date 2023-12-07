void partida_jugador()
{
    // Variables
    PLAYER jugador1;  // Datos de jugador
    PLAYER jugador2;  // Datos de jugador 2
    int victoria = 0; // Para determinar si el juego ha terminado o no
    int turno = 2;    // Para determinar de quien es el turno
    int azar = 0;
    int acertado = 0;
    int acertado_cpu = 0;
    int casilla_disparada[2] = {0}; // Almacena la casilla en donde CPU disparo en la ronda anterior.
    // Procesos

    // Primero el jugador1 registra sus datos
    printf("JUGADOR 1 Introzca su nombre:     ");
    scanf("%s", jugador1.nombre);
    jugador1.num = 1;
    jugador1.mina = 1;
    jugador1.mina_viva = 0;
    jugador1.mina_mapa = 0;
    jugador1.barcos_restantes = 5;

    // Luego el jugador 2 registra sus datos
    printf("JUGADOR 2 Introzca su nombre:     ");
    scanf("%s", jugador2.nombre);
    jugador2.num = 2;
    jugador2.mina = 1;
    jugador2.mina_viva = 0;
    jugador2.mina_mapa = 0;
    jugador2.barcos_restantes = 5;

    // Luego se inicializan los tableros
    inicializar_tablero(jugador1.tablero_defensa);
    inicializar_tablero(jugador2.tablero_defensa);
    inicializar_tablero(jugador1.tablero_ataque);
    inicializar_tablero(jugador2.tablero_ataque);

    // Luego se colocan los barcos del jugador1
    system("clear");
    printf(YELLOW "\n\n\t%s ¿Quieres colocar tus barcos al azar? (1 Si/ 0 No):     " RESET, jugador1.nombre);
    scanf("%d", &azar);
    if (azar == 1)
    {
        printf(YELLOW "\n\nColocando tus Barcos:  \n" RESET);
        colocar_barcos_azar(jugador1.tablero_defensa);
    }
    else
    {
        colocar_barcos(jugador1.tablero_defensa, jugador1.nombre);
    }

    // Luego se colocan los barcos del jugador 2
    printf(YELLOW "\n\n\t%s ¿Quieres colocar tus barcos al azar? (1 Si/ 0 No):     " RESET, jugador2.nombre);
    scanf("%d", &azar);
    if (azar == 1)
    {
        printf(YELLOW "\n\nColocando tus Barcos:  \n" RESET);
        colocar_barcos_azar(jugador2.tablero_defensa);
    }
    else
    {
        colocar_barcos(jugador2.tablero_defensa, jugador2.nombre);
    }

    // Inicio de partida
    turno = generar_numero(2); // Se decide quien empieza
    system("clear");

    while (victoria == 0)
    {
        if (turno == 0) // turno de jugador 1
        {

            if (jugador1.mina_mapa == 1)
            {
                mover_mina(&jugador1, jugador2.tablero_defensa, jugador1.tablero_ataque, &acertado);
            }

            system("clear");
            printf(YELLOW "\n\n\t\tTurno de %s\n\n" RESET, jugador1.nombre);
            printf(BLUE "Tu tablero de defensa:     " RESET);



            if (acertado == 1)
            {
                printf(RED "¡Te han disparado un barco!\n" RESET);
            }
            else
            {
                printf(GREEN "No te han disparado ningún barco\n" RESET);
            }

            imprimir_tablero(jugador1.tablero_defensa);
            presionar_enter();

            system("clear");
            printf(YELLOW "\n\n\t\tTurno de %s\n\n" RESET, jugador1.nombre);
            printf(RED "Tu tablero de ATAQUE\n" RESET);
            imprimir_tablero(jugador1.tablero_ataque);

            if (jugador1.mina == 1)
            {
                printf(YELLOW "FASE DE MINA ACUÁTICA" RESET);
                lanzamiento_mina(jugador1.tablero_ataque, jugador2.tablero_defensa, &jugador1, &acertado);
            }

            printf(YELLOW "FASE DE DISPARO\n" RESET);
            atacar(jugador1.tablero_ataque, jugador2.tablero_defensa, &acertado);

            presionar_enter();
            turno = 1;
            victoria = detectar_victoria(jugador2.tablero_defensa);
            if (victoria == 1)
            {
                victoria = 1; // Determina que gano el jugador
            }
        }
        else if (turno == 1) // turno de jugador 2
        {

            if (jugador2.mina_mapa == 1)
            {
                mover_mina(&jugador2, jugador1.tablero_defensa, jugador2.tablero_ataque, &acertado);
            }

            system("clear");
            printf(YELLOW "\n\n\t\tTurno de %s\n\n" RESET, jugador2.nombre);
            printf(BLUE "Tu tablero de defensa:     " RESET);

            if (acertado == 1)
            {
                printf(RED "¡Te han disparado un barco!\n" RESET);
            }
            else
            {
                printf(GREEN "No te han disparado ningún barco\n" RESET);
            }

            imprimir_tablero(jugador2.tablero_defensa);
            presionar_enter();

            system("clear");
            printf(YELLOW "\n\n\t\tTurno de %s\n\n" RESET, jugador2.nombre);
            printf(RED "Tu tablero de ATAQUE\n" RESET);
            imprimir_tablero(jugador2.tablero_ataque);

            if (jugador2.mina == 1)
            {
                printf(YELLOW "FASE DE MINA ACUÁTICA" RESET);
                lanzamiento_mina(jugador2.tablero_ataque, jugador1.tablero_defensa, &jugador2, &acertado);
            }

            printf(YELLOW "FASE DE DISPARO\n" RESET);
            atacar(jugador2.tablero_ataque, jugador1.tablero_defensa, &acertado);

            presionar_enter();
            turno = 0;
            victoria = detectar_victoria(jugador1.tablero_defensa);
            if (victoria == 1)
            {
                victoria = 2; // Determina que gano el jugador
            }
        }

        // Guardar estado de partida
        guardar_partida(jugador1);
    }

    // Fin de partida
}