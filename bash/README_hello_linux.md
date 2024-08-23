## Bash Script Creation Guide

Create a simple bash script that outputs a greeting along with the operating system's name.

### Steps to Create the Bash Script

1. **Open the Terminal:**
   - Open your terminal by searching for "Terminal" in your applications menu or by pressing `Ctrl + Alt + T` (Linux) or `Cmd + Space` and typing "Terminal" (macOS).

2. **Navigate to the Desired Directory:**
   - Use the `cd` command to navigate to the directory where you want to create the script. For example:
     ```bash
     cd ~/Desktop
     ```

3. **Create a New File:**
   - Create a new file using the `touch` command or a text editor like `nano`. To create a file named `hello_linux.sh`, run:
     ```bash
     touch hello_linux.sh
     ```
   - Alternatively, open the file directly in a text editor:
     ```bash
     nano hello_linux.sh
     ```

4. **Write the Script:**
   - Open the file in a text editor (`nano`, `vim`, etc.) and add the following lines:
     ```bash
     #!/bin/bash
     os_name=$(uname -o)
     echo "Hello $os_name!"
     ```
   - **Shebang (`#!/bin/bash`)**: The first line of the script that specifies which shell to use for executing the script.


5. **Save and Exit the Editor:**
   - In `nano`, press `Ctrl + O` to save the file, then press `Enter` to confirm. After saving, press `Ctrl + X` to exit the editor.

6. **Make the Script Executable:**
   - Change the file permissions to make the script executable by using the `chmod` command:
     ```bash
     chmod +x hello_linux.sh
     ```

7. **Run the Script:**
   - Run the script by typing:
     ```bash
     ./hello_linux.sh
     ```

8. **View the Output:**
   - After running the script, you should see an output like:
     ```
     Hello GNU/Linux!
     ```
   - The output will vary depending on the operating system you are using.


### Conclusion

By following these steps, you can create, edit, and execute a simple bash script on your system. This exercise helps in understanding basic shell scripting and terminal commands.
