## Install `prometheus-client-c` sin Docker

El `Makefile` está configurado para usar Docker por defecto, para no usar Docker, podemos compilar manualmente la biblioteca.

### Pasos para compilar `prometheus-client-c` sin Docker:

1. **Revisar Dependencias Necesarias**:
   Asegúrate de tener las dependencias necesarias instaladas en tu sistema:
   
   - **GNU Make**: para ejecutar las tareas de compilación.
   - **CMake**: que se utiliza para configurar el proceso de compilación.
   - **gcc** o **clang**: el compilador C.
   - **libmicrohttpd-dev**: biblioteca para manejar servidores HTTP.

   En sistemas basados en Debian/Ubuntu, puedes instalar estas dependencias ejecutando:
   ```bash
   sudo apt update
   sudo apt install make cmake gcc libmicrohttpd-dev
   ```

2. **Modificar el Makefile**:
   Si el `Makefile` intenta usar Docker por defecto, puedes modificarlo para evitar la sección que lo invoca. Aquí hay dos posibles enfoques:

   - **Opción 1**: Comentar o eliminar las partes del `Makefile` que invocan Docker. Busca las líneas que mencionan Docker (como `docker build` o `docker run`) y coméntalas o elimínalas.
   
     Edita el `Makefile` y busca una sección como esta:
     ```makefile
     docker:
         docker build -t prometheus-client-c-dev .
     ```

     Puedes comentar las líneas:
     ```makefile
     # docker:
     #     docker build -t prometheus-client-c-dev .
     ```

   - **Opción 2**: Ejecuta los comandos de compilación manualmente sin usar el `Makefile` (explicado en los siguientes pasos).

3. **Crear un Directorio de Compilación**:
   Muchos proyectos usan `CMake` para configurar el entorno de compilación. Crea un directorio de compilación dentro del repositorio para organizar los archivos:
   ```bash
   mkdir build
   cd build
   ```

4. **Configurar el Proyecto con CMake**:
   Ejecuta `CMake` desde el directorio `build` para configurar el proyecto:
   ```bash
   cmake ..
   ```

   Esto generará los archivos de compilación necesarios.

5. **Compilar el Proyecto**:
   Ahora puedes compilar el proyecto ejecutando:
   ```bash
   make
   ```

6. **Instalar la Biblioteca**:
   Una vez que se haya completado la compilación, puedes instalar la biblioteca en tu sistema ejecutando:
   ```bash
   sudo make install
   ```

   Esto instalará los archivos en las rutas estándar del sistema, como `/usr/local/lib` y `/usr/local/include`.

### Verificar la Instalación

Puedes verificar que la biblioteca se instaló correctamente comprobando que los archivos de cabecera y las bibliotecas están en las ubicaciones correctas:

```bash
ls /usr/local/include/prom.h
ls /usr/local/lib/libprom.so
```

### Compilar tu Programa Usando `prometheus-client-c`

Ahora que `prometheus-client-c` está instalada, puedes compilar tus programas que dependan de esta biblioteca con el siguiente comando:

```bash
gcc -o my_program my_program.c -lprom
```

Este comando compila el archivo `my_program.c` y enlaza la biblioteca `prom`.

### Resumen

1. Asegúrate de tener las dependencias instaladas.
2. Modifica el `Makefile` para evitar Docker o ignóralo.
3. Usa `CMake` para configurar el proyecto.
4. Compila con `make`.
5. Instala la biblioteca con `sudo make install`.

## promhttp

Necesitas compilar e instalar `promhttp` por separado si deseas exponer tus métricas a través de HTTP. `promhttp` es el servidor HTTP que expone las métricas de Prometheus, y no está incluido en la instalación básica de `prometheus-client-c`. Sigue los pasos a continuación para instalarlo correctamente.

### Instalación de `promhttp`

1. Cambia al directorio donde está implementado `promhttp`:
   ```bash
   cd prometheus-client-c/promhttp
   ```

2. Compila el proyecto:
   ```bash
   make
   ```

3. Instala `promhttp`:
   ```bash
   sudo make install
   ```

### Verificar la Instalación

Para verificar que `promhttp` se instaló correctamente, asegúrate de que los archivos correspondientes estén en las ubicaciones esperadas:

```bash
ls /usr/local/include/promhttp.h
ls /usr/local/lib/libpromhttp.so
```

Una vez que hayas instalado `promhttp`, podrás iniciar el servidor HTTP que expone tus métricas a Prometheus en el puerto configurado, como se describe en los ejemplos de código.
