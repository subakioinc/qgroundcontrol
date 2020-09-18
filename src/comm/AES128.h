
/*
******************************************************************
**       Advanced Encryption Standard implementation in C.      **
**       By Niyaz PK                                            **
**       E-mail: niyazlife@gmail.com                            **
**       Downloaded from Website: www.hoozi.com                 **
******************************************************************
This is the source code for decryption using the latest AES algorithm.
AES algorithm is also called Rijndael algorithm. AES algorithm is 
recommended for non-classified use by the National Institute of Standards 
and Technology(NIST), USA. Now-a-days AES is being used for almost 
all encryption applications all around the world.

THE MAIN FEATURE OF THIS AES ENCRYPTION PROGRAM IS NOT EFFICIENCY; IT
IS SIMPLICITY AND READABILITY. THIS SOURCE CODE IS PROVIDED FOR ALL
TO UNDERSTAND THE AES ALGORITHM.

Comments are provided as needed to understand the program. But the 
user must read some AES documentation to understand the underlying 
theory correctly.

It is not possible to describe the complete AES algorithm in detail 
here. For the complete description of the algorithm, point your 
browser to:
http://www.csrc.nist.gov/publications/fips/fips197/fips-197.pdf

Find the Wikipedia page of AES at:
http://en.wikipedia.org/wiki/Advanced_Encryption_Standard
******************************************************************
*/

// Include stdio.h for standard input/output.
// Used for giving output to the screen.
#include<stdio.h>
#include<string.h>


#define AES128          128
#define AES256          256

#define ENCRYPTION      0
#define DECRYPTION      1

#define PRINT_DBG       1
#define PRINT           0

// The number of columns comprising a state in AES. This is a constant in AES. Value=4
#define Nb 4


void aes_cipher(unsigned char* out, unsigned char* in, unsigned char mode, unsigned int data_len);
void aes_create(unsigned char* key_in, int key_len);
void aes_destroy();
