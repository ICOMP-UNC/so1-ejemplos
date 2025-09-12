```md
# System Monitor

## Introducción
En esta guía, aprenderás a desarrollar un programa en C que lea datos de uso de CPU desde el sistema de archivos `/proc/stat`, exponga estos datos a Prometheus utilizando la librería `prometheus-client-c`, y finalmente los visualice en Grafana. Este proceso te permitirá monitorear y analizar en tiempo real el consumo de CPU de tu sistema, entre otros parámetros.

## ¿Qué aprenderemos?
- **Conocimientos Básicos en C:** Familiaridad con la lectura de archivos y manejo básico de entradas/salidas en C.
- **Sistema Operativo Linux:** El archivo `/proc/stat` es específico para sistemas basados en Linux.
- **Prometheus y Grafana:** Instalación y configuración de Prometheus y Grafana.
- **Librería `prometheus-client-c`:** Se requiere esta librería para exponer las métricas en Prometheus. Puedes encontrar el proyecto [aquí](https://github.com/digitalocean/prometheus-client-c).


### Instalación de Prometheus

Ver archivo prometheus-client-c.md

### Instalación de Grafana

Seguir los pasos en https://grafana.com/docs/grafana/latest/setup-grafana/installation/debian/

### Instalación de `prometheus-client-c`
```bash
git clone https://github.com/digitalocean/prometheus-client-c.git
cd prometheus-client-c
make
sudo make install
```

## Paso 1: Lectura de Datos de Consumo de CPU desde `/proc/stat`
El archivo `/proc/stat` es un archivo virtual que almacena diversas estadísticas del sistema, incluyendo el consumo de CPU. Para monitorear el uso de CPU, leeremos los datos de este archivo utilizando un programa en C.

### Explicación de `/proc/stat`
El archivo `/proc/stat` contiene varias líneas que comienzan con "cpu", seguidas de valores que representan el tiempo que la CPU ha pasado en diferentes estados: `user`, `nice`, `system`, `idle`, etc.

Un ejemplo de salida es:
```
cpu  4705 0 3421 1204310 50 120 0 0 0 0
```

- `user`: Tiempo que la CPU ha pasado ejecutando procesos en modo usuario.
- `nice`: Tiempo que la CPU ha pasado ejecutando procesos con prioridad modificada.
- `system`: Tiempo que la CPU ha pasado ejecutando procesos en modo kernel.
- `idle`: Tiempo que la CPU ha estado inactiva.

### Código en C para Leer `/proc/stat`
Ver el programa de ejemplo en C que lee el archivo `/proc/stat` y extrae la primera línea, que contiene información agregada del uso de la CPU: read_cpu_usage.c

#### Explicación del Código:
- **`fopen`:** Abre el archivo `/proc/stat` en modo de solo lectura.
- **`fgets`:** Lee el archivo línea por línea hasta encontrar la línea que comienza con `cpu `.
- **`strncmp`:** Compara los primeros 4 caracteres de la línea para verificar que es la línea de uso de CPU.
- **`fclose`:** Cierra el archivo después de su lectura.

## Paso 2: Exponer los Datos a Prometheus
Una vez que hemos leído los datos de uso de CPU, el siguiente paso es exponer estas métricas para que Prometheus las recolecte.

### Agregar `prometheus-client-c` a tu Proyecto
Para exponer las métricas, debemos utilizar la librería `prometheus-client-c`. 

Para compilar tu codigo, por ejemplo 'expose_metrics.c':

```bash
gcc expose_metrics.c -o metrics -lprom -pthread -lpromhttp
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
./metrics
```

### Acceder a /metrics de Prometheus

Este es el endpoint estándar que expone las métricas en el formato que Prometheus puede recolectar.

Cuando accedes a localhost:8000, sin /metrics, estás viendo la página de estado predeterminada del servidor HTTP de promhttp, que solo indica que el servidor está funcionando.

Acceder a /metrics es lo correcto para obtener las métricas que tu programa está exponiendo, y Prometheus es quien hará peticiones a ese endpoint para recolectar los datos.


## Paso 3: Visualizar los Datos en Grafana
Con Prometheus recolectando las métricas, el siguiente paso es visualizarlas en Grafana.

### Configurar Grafana
1. Inicia sesión en Grafana y configura Prometheus como fuente de datos:
   - URL: `http://localhost:9090` (si Prometheus está en ejecución en la misma máquina).
2. Crea un nuevo dashboard y añade un gráfico con la métrica `cpu_usage`.

### Ejemplo de Consulta
Usa la siguiente consulta en Grafana para visualizar el uso de CPU:
```
cpu_usage
```

## Actividad


### Mejorar tu Dashboard

Deberas agregar las siguientes metricas:

Uso de Memoria: Pueden leer estadísticas de memoria desde /proc/meminfo y exponer métricas para la memoria total, usada y disponible.
I/O de Disco: Rastrear estadísticas de I/O de disco desde /proc/diskstats.
Estadísticas de Red: Exponer métricas de tráfico de red (bytes recibidos/enviados, paquetes, etc.) desde /proc/net/dev.
Conteo de Procesos: Calcular el número de procesos en ejecución leyendo /proc/stat o contando subdirectorios en /proc/ que correspondan a procesos en ejecución.
Cambios de Contexto: Rastrear el número de cambios de contexto desde /proc/stat.

### Preguntas que debes responder en tu informe
1 ¿Cuál es el propósito del sistema de archivos /proc en Linux, y cómo podemos usarlo para recopilar métricas del sistema?
2 ¿Cómo interpretas los campos en /proc/stat relacionados con el uso de la CPU, y cómo se utilizan para calcular el porcentaje de utilización de la CPU?
3 Explica cómo Prometheus recopila y almacena métricas, y cómo Grafana visualiza estos datos. ¿Cuáles son los componentes clave de cada uno?
4 ¿Cuál es la diferencia entre un gauge, un counter y un histograma en Prometheus? Proporciona un ejemplo de cuándo debería usarse cada uno.
5 ¿Por qué sería necesario un mutex al trabajar con métricas en un entorno multi-thread? ¿Qué podría salir mal si no se utiliza?

## Conclusión
Siguiendo esta guía, has creado un programa en C que lee el uso de la CPU desde `/proc/stat`, expone esos datos a Prometheus y los visualiza en Grafana. Ahora puedes monitorear el uso de la CPU de tu sistema en tiempo real y personalizar las visualizaciones según tus necesidades.

## Recursos Adicionales
- [Documentación de `/proc/stat`](https://man7.org/linux/man-pages/man5/proc.5.html)
- [Prometheus Client for C](https://github.com/digitalocean/prometheus-client-c)
- [Documentación de Grafana](https://grafana.com/docs/)


