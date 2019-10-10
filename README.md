# cmd-uart

Trabajo práctico para la materia Programación de Microprocesadores de la
[Carrera de Especialización en Sistemas Embebidos](http://laboratorios.fi.uba.ar/lse/especializacion.html)
de la UBA.

El firmware corre sobre la placa de desarrollo [EDU-CIAA-NXP](http://www.proyecto-ciaa.com.ar/index_comprar_educiaanxp.html),
y para compilar es necesario utilizar [Firmware v3](https://github.com/epernia/firmware_v3).

El objetivo del firmware es simular una línea de comandos simple mediante la
UART. El funcionamiento se describe en el documento de [arquitectura y diseño
detallado](https://docs.google.com/document/d/12o3bVxmdhhSE5jTOyUo8WwF6yKrkli2oRkp-YUJybcc/edit?usp=sharing).

Los módulos (pares de archivos `.c` y `.h`) son:

* `cmd-uart.c` contiene la función `main`.
* `fsm` implementa la máquina de estados (ver abajo).
    * `state_idle` contiene las funciones `enter` y `update` del estado `IDLE`,
      que sería el "menú principal" en el que el usuario puede elegir un modo
      de funcionamiento (ejemplo: `pvsub` para pasar al modo "Process Variable
      Publisher").
    * `state_tcn` contiene las funciones `enter` y `update` de los estados
      correspondientes a cada uno de los modos de funcionamiento, que aun no
      hacen nada. Lo único que puede hacer el usuario en estos modos es
      ingresar el comando `back` para volver al menú principal.
* `terminal` abstrae la entrada/salida de texto.
* `command_line` para que cada estado pueda definir los comandos y operaciones disponibles.

## Máquina de estados

Cada estado tiene 2 funciones `enter` y `update`. La función `enter` se llama cuando
se ingresa a ese estado, y `update` se llama periódicamente cuando se está en ese
estado.

La función `update` puede devolver una señal. Esa señal puede provocar o no una
transición; no es responsabilidad de un estado saber cuál es el próximo estado.

En `fsm.c` se configuran los estados disponibles y cómo son las transiciones
entre estados. Por ejemplo `{STATE_INIT, SIGNAL_DONE, STATE_IDLE}` determina que
si en el estado `INIT` la función `update` devuelve `SIGNAL_DONE`, entonces hay que
pasar al estado `IDLE`.

