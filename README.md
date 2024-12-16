# Compilación.
Si está disponible, usar `make` en la consola. De otro modo:

    ```
    mkdir -p build/
    mpicc -o build/go_mpi src/*c
    ```

# Uso

    mpirun -np k build/go_mpi -P -M < data/testfile.txt

Donde P es reemplazado por el modo de particionar
la matriz de entrada (V: vertical, H: horizontal).
El parametro M indica el modo de ejecución (S: silencioso,
V: verboso).

El formato de testfile.txt debe ser tal que:
```
n
VVVVVVV...V
VVVVVVV...V
.
.
.
VVVVVVV...V
```

Donde `n` indica la dimensión de la matriz cuadrada y V = {0,1,2} donde
0 indica ausencia de ficha, 1 y 2 la presencia de una ficha del tipo
correspondiente.
