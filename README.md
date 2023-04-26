# Características 
El proyecto Minitalk de la escuela 42 es un programa cliente-servidor que permite la comunicación entre dos procesos a través de señales. El objetivo es enviar mensajes entre el cliente y el servidor en forma de señales binarias.

## Características
El proyecto debe incluir las siguientes características:

- Un servidor que pueda recibir señales de múltiples clientes al mismo tiempo
- Un cliente que pueda enviar mensajes al servidor
- La capacidad de enviar mensajes de cualquier longitud
- La capacidad de manejar errores y excepciones
- Compilación y Ejecución

## Para compilar el proyecto, se proporciona un Makefile con diferentes reglas:

- *make* o *make all*: compila el servidor y el cliente
- *make server*: compila solamente el servidor
- *make client*: compila solamente el cliente
- *make clean*: elimina los archivos objeto y otros archivos generados
- *make fclean*: elimina los archivos objeto, los archivos generados y los ejecutables
- *make re*: realiza una reconstrucción completa del proyecto
- *make bonus*: Crear bonus 
Para ejecutar el servidor, se debe primero compilarlo y luego ejecutar el archivo server con los siguientes argumentos:
> ./server

Para ejecutar el cliente, se debe primero compilarlo y luego ejecutar el archivo client con los siguientes argumentos:
> ./client [server_pid] [message]

Donde `server_pid` es el PID del servidor al que se enviará el mensaje y `message` es el mensaje que se enviará al servidor.

## Conclusiones
El proyecto Minitalk es un desafío interesante para mejorar las habilidades en programación y en particular en manejo de señales en C. Además, es una oportunidad para practicar el trabajo en equipo y la gestión de proyectos en un entorno de programación.
