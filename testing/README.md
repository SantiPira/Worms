## Testing de protocolo

Aunque las pruebas simulan escenarios de juego, por una cuestion de spawn random de los worms los test podrian fallar si se compararan otras cosas que no sean el protocolo. Por esta razon aislamos el testeo en el protocolo.

Para lograr esto, tuvimos que crear un modo no grafico del cliente de modo que este no muestre a traves de QT ni SDL las opciones de conexion del juego y posteriormente el estado del juego.

#### Modo no grafico

Para acceder al modo no grafico se debe pasar al cmake un parametro especial que activa una opcion de compilacion y de esta manera los ejecutables se compilan de manera no grafica.

```
cmake -DTESTING=ON ..
make -j4
```

Adicionalmente a no mostrar el estado del juego el modo no grafico tiene una manera especial de ejecutarse pasando mas argumentos:

```
./cliente <IP> <PUERTO> <OPCION DE CONEXION> <CANTIDAD DE JUGADORES>
```

Las opciones de conexion son:

- create: si se quiere crear una nueva partida

- join: si se quiere unir a una partida ya creada

La cantidad de jugadores solo se debe especificar si la opcion es create para definir la cantidad de jugadores de la partida.

#### Ejecutar tests

Para poder ejecutar los test, debemos compilar el tp para el modo no grafico, para eso se tiene que ejecutar el script:

```
./compile-for-testing.sh
```

Luego de haber compilado en el modo no grafico para correr los tests automaticos se debe copiar el contenido de la carpeta testing a la carpeta build. Para correr los test y que se generen las salidas se debe ejecutar dentro de la carpeta build en un terminal:

```
./run_tests.sh ./ casos/ multi-client no-valgrind 60 10 yes
```

Una vez que se ejecutaron los tests, para comparar las salidas obtenidas con las esperadas, ejecutarmos:

```
./compare_outputs.sh casos salidas
```

Ese script comparar las salidas e informa que lineas faltan o sobran comparando las salidas, o por lo contrario si no existen diferencias.

#### Licencias

El modelo de testing que utilizamos en este proyecto, utiliza el provisto por la catedra de Taller de programacion Veiga para el trabajo practico de Threads adaptado.