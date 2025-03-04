# Text File Encryption Project

## Basic Information
- **Project:** Command-Line Text Encryption
- **Language:** C++

## Project Description
This project involves creating a command-line application for encrypting and decrypting text files using a Caesar cipher. The application processes an input text file, applies a shift-based encryption or decryption based on a user-specified key, and writes the results to an output file. 

## Materials Used
- **Laptop with Internet Connection**
- **AWS Account with Cloud9 instance configured**

## Skills Showcased
- Command-line argument parsing using `argc` and `argv`
- File input and output handling with file streams
- Implementing the Caesar cipher algorithm
- Handling character encodings and ASCII values
- Error checking and user input validation

## How to Run
1. Compile the program using a C++ compiler, such as g++:
   ```sh
   g++ -o encryptor encryptor.cpp
   ```
2. Run the program with the required command-line arguments:
   ```sh
   ./encryptor -e -k 5 -i input.txt -o output.txt
   ```
   This command encrypts `input.txt` using a shift key of 5 and writes the output to `output.txt`.
3. To decrypt a file, run:
   ```sh
   ./encryptor -d -k 5 -i output.txt -o decrypted.txt
   ```
   This reverses the encryption using the same key.

## Command-Line Arguments
- `-e` or `-d` : Specifies encryption or decryption mode.
- `-k X` : Specifies the key value `X` (integer shift amount).
- `-i <filename>` : Specifies the input file name.
- `-o <filename>` : Specifies the output file name.

## Encryption Method
The program implements a **Caesar cipher**, shifting each letter by the key value specified:
- Encryption: Shift characters forward by `key` positions.
- Decryption: Shift characters backward by `key` positions.
- The cipher wraps around alphabetically (e.g., 'Z' shifts to 'A' if necessary).
- Non-alphabetic characters remain unchanged.

## Additional Information
Ensure that the program correctly validates user input, handles file errors gracefully, and preserves the case of letters while applying the cipher.

## Author
Nathan Culler
