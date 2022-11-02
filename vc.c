/*
Vigenere Cipher

Description: This program takes in a passphrase and key then produces an encryption or decryption of that text using the vigenere cipher

Usage

User selects the option to either Encrypt or Decrypt
Please enter passphrase: select
Please enter key: party
The ciphered text with (Key shift = 'party') is: hecxai

Vigenere Cipher Encryption Formular:
c[i]= (p[i] +k[i mod klength]) mod N, C= cipher, k= keyword, P= plaintext, N= number of letters in the alphabeth
Letter a=0, b=1, c=2, d=3,................ z=25
key = 'party'
          ( (int)Letter + (int)keyLetter) mod 26 ==> return a ciphered letter as a number, aka cipherValue
                                                   ==> (char)cipherValue = '[some letter]'

                                                NOTE: ASCII 'a'=97, 'b'=98, 'c'=99 .. (for lower case letters)
                                                      ASCII 'A' = 65, 'B'=66, 'C'=67 .. (for upper case letters)


Vigenere Cipher Decryption Formular:
p[i] = (c[i] - k[i mod klength] + N) mod N

Please enter encrpted text: hecxai
please enter key: party
The ciphered text with (Key shift = 'party') is: select
*/

// Initialze libraries
#include <stdio.h>  //fgets() , printf(0, stdin
#include <string.h> //strlen()
#include <ctype.h>  // isupper() , islower() , tolower(), toupper(), isalpha()

// Declare vigenere cipher
void vigenereCipher(char *passphrase, char *k, char *encryptedtext, int keyNumber);
void vigenereDecipher(char *deciphertext, char *k, int keyNumber);


int main()

{
   
    int x,y;
    char k[6];              // Declare a string for the key
    char passphrase[101];   // Declare a string to store user generated passphrase to encrypt
    char deciphertext[101]; // Declare a string to store user generated cipher text to decrypt
    char encryptedtext[101]; // Decalre a string to store encrypted text
    int keyNumber = 0;


    // Display options for the user
    printf( "\nPlease choose one of the following options:\n");

    // Encrypt or Decrypt
    printf( "1 = Encrypt\n");
    printf( "2 = Decrypt\n");

    // read the option selected
    scanf("%d", &x);

    if (x == 1)

    {
        // Ask the user for a passphrase to encrypt
        printf( "Please enter passphrase: \n");

        // Get the users input (the passphrase)
        getchar();
        fgets(passphrase, sizeof(passphrase), stdin);

        // Ask the user for key
        printf( "Please enter keyword to be used to encrypt: \n");

        // Get the users input (the key)
        fgets(k, sizeof(k), stdin);

        // print the encrypted plain text
        printf( "The Encrypted text with (Key shift = '%s' ) is: ", k);

        // Print the actual encryption
        vigenereCipher(passphrase, k,encryptedtext, keyNumber);

        // Ask if the user wants to decrypt thr encrypted text
        printf( "Would you like to decrypt the encrypted text \n");

         // Yes or No
        printf( "1 = Yes\n");
        printf( "2 = No\n");

        // read the option selected
        scanf("%d", &y);

        if (y==1)
        {
            printf( "The Decrypted text with (Key shift = '%s') is:", k);
             // Print the actual decryption
            vigenereDecipher(encryptedtext, k, keyNumber);
            printf( "\n");
        }
        else if (y==2)
        {
            printf( "You selected NO ");
        }
    }
    else if (x == 2)
    {
        // Ask the user for the cipher text to decrypt
        printf( "Please enter cipher text: \n");

        // Get the users input (the ciphertext)
        getchar();
        fgets(deciphertext, sizeof(deciphertext), stdin);

        // Ask the user for key
        printf( "Please enter keyword to be used to decrypt \n");

        // Get the users input (the key)
        fgets(k, sizeof(k), stdin);

        // print the decrypted text
        printf( "The Decrypted text with (Key shift = '%s') is: ", k);

        // Print the actual decryption
        vigenereDecipher(deciphertext, k,keyNumber);
    }

    else
    {
        printf( "Please select a valid input \n");
    }

   

    return 0;
}

// C[i] = (p[i] + k[i mod klength] ) mod N, C = cipher, k = keyword, p = passphrase, N = number of letters in the alphabet
void vigenereCipher(char *passphrase, char *k, char *encryptedtext, int keyNumber)
{
    
    int i;
    char cipher;
    int cipherValue;
    int len = strlen(k);
    
    for (i = 0; i < len; i++)
    {
        if (isalpha(k[i]))
        {   
            keyNumber++;
        }
        
    }
    
    // Loop through the length of the plain text string
    for (i = 0; i < strlen(passphrase); i++)
    {
       
        // if the character is lowercase, where range is [97 -122]
        if (islower(passphrase[i]))
        {
            cipherValue = (((((int)passphrase[i]) - 97) + ((int)tolower(k[i % keyNumber]) - 97)));
            cipherValue = (97 + (cipherValue % 26));
            cipher = (char)cipherValue;
        }
        else // Else it's upper case, where letter range is [65 - 90]
        {
            cipherValue = ((int)passphrase[i] - 65 + (int)toupper(k[i % keyNumber]) - 65) % 26 + 65;
            cipher = (char)cipherValue;
        }

        // Print the ciphered character if it is alphanumeric (a letter)
        if (isalpha(passphrase[i]))
        {   
            encryptedtext[i] = cipher; // get value of the encrypted text and assign to a string
            printf( "%c", cipher);

        }
        else // if the character is not a letter then print the character (e.g. space)
        {   
             
            //printf( "%c", passphrase[i]);
        }


    }
       
}

// Decryption
// p[i] = (c[i] - k[i mod klength] + N) mod N C = cipher, k = keyword, p = passphrase, N = number of letters in the alphabet
void vigenereDecipher(char *deciphertext, char *k, int keyNumber)
{

    int i;
    char decipher;
    int decipherValue;
    int len = strlen(k);

    for (i = 0; i < len; i++)
    {
        if (isalpha(k[i]))
        {   
            keyNumber++;
        }
        
    }

    // Loop through the length of the cipher text
    for (i = 0; i < strlen(deciphertext); i++)
    {
        // if the character is lowercase, where range is [97 -122]
        if (islower(deciphertext[i]))
        {
            decipherValue = (((((int)deciphertext[i]) - 97) - ((int)tolower(k[i % keyNumber]) - 97)));
            if (decipherValue < 0)
            {
                decipherValue = decipherValue + 26;
            }
            decipherValue = (97 + (decipherValue % 26));
            decipher = (char)decipherValue;
        }
        else // Else it's upper case, where letter range is [65 - 90]
        {
            decipherValue = (((((int)deciphertext[i]) - 65) - ((int)toupper(k[i % keyNumber]) - 65)));
            if (decipherValue < 0)
            {
                decipherValue = decipherValue + 26;
            }
            decipherValue = (65 + (decipherValue % 26));
            decipher = (char)decipherValue;
        }

        // Print the ciphered character if it is alphanumeric (a letter)
        if (isalpha(deciphertext[i]))
        {  
            printf( "%c", decipher);
        }
        else // if the character is not a letter then print the character (e.g. space)
        {
            //printf( "%c", deciphertext[i]);
        }
    }
        printf( "\n");
}