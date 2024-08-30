# basic examples

```sh
echo $SHELL
cd
pwd
```

# list content

```sh
ls

## listar directorio
ls -d 

# print the index number of each file (inodo)
# A cada archivo se le asigna un indice unico
ls -i
```

# Create a directory

```sh
mkdir
mkdir -p
```

```sh
touch
```
# echo y redireccion

```sh
echo "header" > template
cp
mv
```

# see file content

```sh
cat
less
more
head
```

# enlace permanente (nivel inodo)
# no soporta directorios y otras limitaciones
ln txt tx1

# enlace simbolico (referencia a traves del nombre, en vez de hacerlo por el inodo)
# puede ser a directorios
ln -s txt tx2

# Remove

```shell
rm

# iterativo
rm -i

# rm iterativo por alias
alias rm = "rm -i"

# solo borra dirs vacios
rmdir

rm -rf 
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
# usuarios usando el sistema en orden alfabetico
who | sort
```

# OR Condition

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

How to reboot or shut down using the command line:

    shutdown
    reboot
    halt
    poweroff

https://zpenterprises.co/how-to-reboot-or-shut-down-linux-using-the-command-line/

