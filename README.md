punto 1:

el programa se ejecuta con un argumento de 123123

cerrando la puerta antes del ciclo for, antes de que se invocan los workers en los procesos, y posteriormente abrirla de nuevo, se observan timepos de 0.02 medidas de reloj por segundo

cerrando la puerta dentro del ciclo antes de incrementar y abriendola de nuevo justo despues de incrementarla arroja unas medidas de tiempo de aproximadamente 94134894.889294 relojes/segundo, un tiempo mucho mayor.

Esta diferencia se debe a que las puertas se cierran y se abren dentro del ciclo, asi por cada iteracion se cierran y abren y para valores muy altos esto conlleva un costo mayor de procesamiento.


punto 3:

se define el fork y se hace un wait en el proceso hijo, asi se ejecuta el padre de manera similiar a como es por defecto.


punto 4:

4.1

El uso de la CPU por cada proceso debería ser del 100 %, debido a que en la instrucción se está indicando que cada uno use el 100 % de esta (5:100)

Esto demuestra que la CPU siempre estuvo ocupada con cada proceso y que cuando uno terminó, el otro siguió ocupandóla, teniendo así el 100 % de la CPU para cada proceso.

4.2

El proceso 0 toma 4 tiempos en su ejecución, mientras que el llamado al proceso I/O toma 6 tiempos, debido a que el primer tiempo de este proceso corresponde a la ejecución, 4 más corresponden al uso de la I/O o la espera a que el dispositivo complete la tarea y un tiempo más para el cambiar al estado de realizado



