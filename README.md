# una_multimedia_ig_entrega_2

PSEUDOCODIGO DEL MAIN()
Objetivo: Llegar a rendir un final.
Obstáculos: Tiempo + Coalisiones con Manifestantes
Personajes: Jugador + Manifestantes.
Pantallas: 1.INSTRUCCIONES - 2.CRÉDITOS - 3.JUEGO

Si el Usuario aprieta 1...
  Mostrar instrucciones de juego.

Si el Usuario aprieta 2...
  Mostrar créditos.

Si el Usuario aprieta 3...
  Mostrar Estudiante en la calle, donde hay Manifestantes y el Edificio de la UNA.
  Mover Manifestantes de izq a der por la pantalla.
    Si el Usuario aprieta cualquier flecha...
      Mover al Estudiante por el espacio.
    Si un Manifestante llega al extremo derecho de la pantalla...
      Llevar al Manifestante de nuevo a la izquierda.
    Si un Manifestante choca al Estudiante...
      Mostrar cartel con mensaje referido a la lucha universitaria.
      Sacar una vida de Estudiante.
    Si el Estudiante llega al edificio de la UNA...
      Usuario ganó el juego.
    Si el contador llega a 0...
      Estudiante tiene crisis vista en animacion.
      Estudiante pierde una vida.
    Si las vidas perdidas son 3...
      Usuario perdió el juego.
      Mostrar pantalla de 'GAME OVER'.
      Terminar juego.
