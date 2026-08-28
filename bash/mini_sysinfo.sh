#!/bin/bash
# Script básico para mostrar info del sistema (similar a neofetch --off)

echo "=============================="
echo "   Información del Sistema"
echo "=============================="

# Usuario y host
echo "Usuario: $USER"
echo "Host: $(hostname)"

# Distribución y kernel
echo "Distro: $(lsb_release -d | cut -f2)"
echo "Kernel: $(uname -r)"

# Uptime
echo "Uptime: $(uptime -p)"

# CPU
echo "CPU: $(lscpu | grep 'Model name' | sed 's/Model name:\s*//')"

# Memoria
echo "Memoria RAM: $(free -h | awk '/Mem:/ {print $2 " total, " $3 " usada"}')"

# GPU (si está disponible)
echo "GPU: $(lspci | grep -i 'vga' | sed 's/.*controller: //')"

# Disco
echo "Disco: $(df -h / | awk 'NR==2 {print $2 " total, " $3 " usado"}')"

echo "=============================="
