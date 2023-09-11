# Project-7-Mathematical-Function-Encryption
Project 7! A side project of mine where I continued to explore cryptography. In this program specifically I worked to implement of an encryption scheme based on a mathematical function.

This program allows for the encryption and decryption of messages using the given mathematical function and a user-provided message.

Here's a breakdown of what this code does:

User Input and Initialization:

The program begins by defining the lowercase English alphabet in an array called alphabet.
It also initializes a vector called resOfFunction to store the results of applying the mathematical function to each alphabet index.
Encryption (Parts A and B):

The code consists of a loop that runs twice, once for Part A and once for Part B.
Inside the loop, the mathematical function resultOfFunction is applied to each alphabet index, and the results are stored in resOfFunction.
The user is prompted to enter the encrypted message.
The program decrypts the message using the decryptMessage function and displays the result.
Functions and Their Purposes:

string getInputMessage(): This function ensures that the user enters a message containing only letters and no numbers. It repeatedly prompts the user until a valid input is received.

float resultOfFunction(int alphaValue): This function calculates the result of the given mathematical function for a given alphabet index (0 to 25) and returns the result modulo 26.

string decryptMessage(const string &encryptedMessage, const vector<float> &resOfFunction): This function decrypts the encrypted message by mapping each character back to its original alphabet index using the results of the mathematical function.

Project Goals and Learning:
This project serves as a hands-on introduction to cryptography. By working on this code, the developer gains insights into the practical implementation of encryption and decryption algorithms. Understanding how to map characters to numbers, apply mathematical functions, and reverse the process is essential knowledge for building secure communication systems.

In summary, Project 6 has provided a valuable learning experience in the field of cryptography, equipping the developer with skills and knowledge to understand and apply encryption schemes. The ability to encrypt and decrypt messages is a fundamental skill in the world of information security, and this project contributes to the developer's expertise in this area.
