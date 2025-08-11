# una_multimedia_ig_entrega_2

PSEUDOCODIGO DEL MAIN()
Objetivo: Llegar a rendir un final.
Obstáculos: Tiempo + Obstáculos físicos.
Personajes: Jugador + Manifestantes.

Mientras el juego no termine.
  Mostrar el menú de opciones.
  Si el jugador selecciona instrucciones.
    Mostrar instrucciones de juego.
  Si el jugador selecciona créditos.
   Mostrar créditos.
  Si el jugador selecciona jugar.
    Comenzar el juego.

    Nivel 1. En la casa.
    Mostrar jugador en una casa, donde hay una mochila y una puerta.
    Empezar contador regresivo.
    Si el jugador aprieta cualquier flecha.
      Mover al jugador por el espacio.
    Si el jugador llega a donde está la mochila.
      Seleccionar mochila. 
      Desbloquear puerta.
    Si el jugador llega a puerta con mochila desbloqueada.
      Pasar a Nivel 2.
    Si el jugador llega a puerta sin mochila desbloqueada.
      Recordarle que debe seleccionar la mochila.
    Si el contador llega a 0.
      Perder una vida.
    Si las vidas perdidas son 3.
      Terminar juego.

    Nivel 2. En el subte.
    Mostrar jugador en el subte, donde hay un molinete y un hombre de negro.
    Si el jugador aprieta cualquier flecha.
      Mover al jugador por el espacio.
    Si el jugador llega hasta el molinete.
      Avisarle que no tiene saldo. 
      Desbloquear molinete.
    Si el contador llega a 0.
      Perder una vida.
    Si las vidas perdidas son 3.
      Terminar juego.

    Nivel 3. En la calle.
    Mostrar jugador en la calle, donde hay manifestantes y el edificio de la UNA.
    Mover manifestas de izq a der por la pantalla.
    Si el jugador aprieta cualquier flecha.
      Mover al jugador por el espacio.
    Si el jugador se choca con un manifestante.
      No dejarlo avanzar.
    Si el jugador pasa por un hueco.
      Dejarlo avanzar.
    Si el jugador llega al edificio de la UNA.
      Jugador ganó el juego.
    Si el contador llega a 0.
      Perder una vida.
    Si las vidas perdidas son 3.
      Terminar juego.
