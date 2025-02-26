# Simple Shell (Windows Only)

## Overview
This is a simple shell program for Windows that allows users to execute basic shell commands, including built-in commands such as `cd`, `pwd`, and `exit`. It also supports executing external commands.

## Features
- Supports built-in commands:
  - `cd <directory>`: Change the current directory.
  - `pwd`: Display the current directory.
  - `exit`: Exit the shell.
- Supports execution of external commands.
- Provides a simple command-line interface.

## Requirements
- Windows OS (This program uses Windows-specific system calls and will not work on Linux or macOS)
- A C compiler such as MinGW or MSVC

## Installation and Compilation
1. Clone the repository:
   ```sh
   git clone https://github.com/CyberPokemon/Simple-Shell.git
   cd "Simple-Shell"
   ```
2. Ensure you have a C compiler installed (e.g., MinGW or Microsoft Visual Studio).
3. Open a terminal or command prompt and navigate to the project directory.
4. Compile the program using:
   ```sh
   gcc main.c shell.c execute.c -o shell.exe
   ```
5. Run the shell using:
   ```sh
   ./shell.exe
   ```

## Usage
1. Start the shell by running `shell.exe`.
2. Type commands and press `Enter` to execute.
3. Use `exit` to terminate the shell.

## File Structure
- `main.c`: Entry point of the program.
- `shell.c`: Handles the main shell loop and user input.
- `execute.c`: Executes commands, including built-in and external commands.
- `shell.h`: Header file containing function declarations.

## Notes
- The shell is designed to work **only on Windows** due to the use of Windows API functions such as `CreateProcess`.
- Ensure that `cmd.exe` is available on your system, as external commands are executed through it.

## License
This project is open-source and available under the MIT License.

