# Proyecto sistemas digitales II

## Bolos

### Propósito del juego 📋

_El presente proyecto consta de un un juego de bolos que será visto desde el navegador de un computador implementado con un mando inalámbrico el cual se interpreta como el control para cambiar el lugar y la fuerza con la que se lanza el bolo, junto con un botón que al ser oprimido lanzará el bolo en pantalla._

### Instrucciones para el juego 🔧

_Para poder llevar a cabo el juego de bolos se deben seguir los siguientes pasos:_
```
1. Verificar que el control inalámbrico esté encendido. 
Se dará cuenta ya que las luces de la ESP32 y del acelerómetro/giroscopio estarán encendidas.
2. Conectar el mando inalámbrico al computador por medio del emparejamiento Bluetooth.
3. Abrir el archivo "bolos" en navegador Edge o Chrome.
4. Dar click en "Connect BT Device" ubicado en la parte superior izquierda.
5. Emparejar el dispositivo ESP32.
```

_Con el cumplimiento de los pasos anteriores el juego debe funcionar correctamente._

## Descripción del mando ⚙️

_El mando inalámbrico del juego está conformado por un módulo ESP32 que fue precisamente escogido para permitir que el mando se comunicara de manera inalámbrica por su módulo Bluetooth, junto con este se tiene el acelerómetro y giroscopio MPU6050 con el que se detecta la posición y la intensidad por medio de registros a bajo nivel para una mayor precisión de los datos tomados por el sensor._

_Adicional a los elementos anteriores, se cuenta con un botón que al ser presionado detectará la señal para lanzar el bolo en la posición en la que fue ubicado._

![Imágen del circuito electrónico del mando inalámbrico](https://raw.githubusercontent.com/nataliagarciaparra/ProyectofinalSDII/master/Circuito-electrónico-del-mando.jpeg)


## Autores ✒️

* **Natalia García Parra** - [natalia.garciap@uqvirtual.edu.co](natalia.garciap@uqvirtual.edu.co)
* **Fabián Forero**
* **Juan Esteban Hernandez** 

