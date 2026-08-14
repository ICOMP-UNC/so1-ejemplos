# basic examples

```sh
echo $SHELL   # muestra el shell en uso
cd            # ir al home
cd ..         # subir un nivel
cd -          # volver al directorio anterior
pwd           # ruta actual
```

# list content

```sh
ls            # lista archivos
ls -lh        # lista con tamaños legibles
ls -d */      # lista solo directorios
ls -i         # muestra inodos (ID único de archivo)
```

# Create and manipulate files

```sh
mkdir proyectos          # crear carpeta
mkdir -p dir/subdir      # crear estructura anidada
touch notas.txt          # archivo vacío
echo "texto" > archivo   # escribir en archivo
echo "más texto" >> archivo # añadir texto
cp archivo copia.txt     # copiar
mv archivo nuevo.txt     # mover/renombrar
```
# See content

```sh
cat archivo.txt          # mostrar completo
head archivo.txt         # primeras líneas
tail archivo.txt         # últimas líneas
less archivo.txt         # navegación interactiva
```

# Links

```sh
# enlace permanente (nivel inodo)
# no soporta directorios y otras limitaciones
ln archivo.txt enlace1   

# enlace simbolico (referencia a traves del nombre, en vez de hacerlo por el inodo)
# puede ser a directorios
ln -s archivo.txt enlace2
```

# Remove

```shell
rm archivo.txt           # borrar archivo
rm -i archivo.txt        # borrar con confirmación (iterativo)
rmdir carpeta            # borrar carpeta vacía
rm -rf carpeta/          # borrar todo dentro
alias rm = "rm -i"       # rm iterativo por alias
```

To delete all files and directories, including hidden ones, 
in a specified directory and its subdirectories, you can use the find command.
Here's how to do it:

```sh
# -mindepth 1: Ensures that the root directory itself is not included in the results, only its contents.
find /path/to/challenge_directory -mindepth 1 -delete
```

# Pipe

```sh
who | sort                # usuarios usando el sistema en orden alfabetico
ps aux | grep firefox     # buscar procesos
```

# Conditions

```sh
test -f car.c && echo "is a file"
```

# AND Condition

```sh
test  -d car.c || echo "not a dir"
```

# intercambiar el nombre de dos archivos 
# usando repetidamente el comando mv

```sh
mv arch1 aux; mv ach2 arch1; mv aux arch1
```

# imprime dentro de una hora, en orden alfabetico, de entre las primeras
# 100 lineas de arc las lineas que contengan la palabra Warning, 
# comprobando antes que arc es accesible.
# El cojunto de comandos se ejecuta en segundo plano

```sh
(sleep 3600; test -r arc && head -100 arc | grep Warning | sort ) &
```

# Command output as argument

```sh
# remove files filtered by grep
rm `grep  -l <match> *`
```

# How to reboot or shut down using the command line:

```sh
shutdown   # apagar
reboot     # reiniciar
halt       # detener
poweroff   # apagar inmediato
```


