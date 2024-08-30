#!/bin/bash

# Stores the operating system's name in the variable `os_name`
os_name=$(uname -s)

# Outputs "Hello" followed by the operating system's name
echo "Hello $os_name!"
