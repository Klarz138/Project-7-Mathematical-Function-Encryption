/*
Katherine Larsen 
Given the function: f(x) = 3x^5 − 9x^3 − 5x + 1 (mod 26)
which takes as input any integer x ranging from 0 to 25. Consider the following encryption scheme:

To encrypt an ℓ-character message m = m1m2 · · · mℓ :
• Interpret every character mi as an alphanumeric letter: a ↔ 0, b ↔ 1, and so on.
• Compute the values f (m1), f (m2), . . . , f (mℓ).
• Re-interpret these values as letters and output the concatenation as the ciphertextpher key. 

I have coded this problem to be user friendly (i.e the user enters the messages. (The messages are not hardcoded in). This allows for the program to be more versitile and adatable if different messages wanted to be decrypted. 
*/

//Include proper libraries 
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cctype> 

using namespace std;

//Function to ensure message contains only letters and not numbers
string getInputMessage();
//Function that applies 3x^5 - 9x^3 - 5x + 1 (mod 26). The result of this formula will later be applied to decrypt
float resultOfFunction(int alphaValue);

//Function to decrypt user entered message
string decryptMessage(const string &encryptedMessage, const vector<float> &resOfFunction);

int main()
{
    //Declaring variables: 
    //initializes an array called alphabet with 26 characters, representing the lowercase English alphabet letters in order.
    char alphabet[26] = {
        'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i', 'j', 'k', 'l',
        'm', 'n', 'o', 'p', 'q', 'r',
        's', 't', 'u', 'v', 'w', 'x',
        'y', 'z'
    };

    //Store the results of applying the mathematical function to each alphabet index
    vector<float> resOfFunction;

//Loop through the whole proce
for (int k = 0;  k < 2; k++)
{
    if (k == 0)
    {
        cout << "Part A: Decrypt the ciphertext 'gbshbjuhbwxhzhxwhu'\n";
    }
    
    else if (k == 1)
    {
        cout << "Part B. Decrypt the ciphertext 'ahwxhbwcfmmbwdebn'\n";
    }


//Loop thr alphabet array 
    for (size_t i = 0; i < sizeof(alphabet) / sizeof(alphabet[0]); i++)
    {
        int alphaIndex = i;
        //Set the resultofFunction to the alpha index so it may later be mapped backwards
        float functionResult = resultOfFunction(alphaIndex);
        resOfFunction.push_back(functionResult);
    }

    // Have the user enter the encrypted message
    cout << "Enter the encrypted message: ";
    string encryptedMessage = getInputMessage();

  //Performs the decryption process using the decryptMessage function
  //resofFunction = vector containing the results of the mathematical function applied to each alphabet index
    string decryptedMessage = decryptMessage(encryptedMessage, resOfFunction);
    cout << "Decrypted message: " << decryptedMessage << "\n\n";
}//end of for loop
    return 0;
    
}//end of main 


// Function to get input message containing only letters
string getInputMessage()
{
    string inputMessage;
    
    while (true)
{
    getline(cin, inputMessage);

    bool isOnlyLetters = true;

  //Loop thr the message and ensure input is only accepted when only letters and not numbers are entered
    for (size_t i = 0; i < inputMessage.size(); i++)
    {
        if (!isalpha(inputMessage[i]))
        {
            isOnlyLetters = false;
            break;
        }
    }

    if (isOnlyLetters)
    {
        break;
    }
    else
    {
        cout << "Invalid input. Please enter a message containing only letters: ";
    }
}
    return inputMessage;
}


//Function that performs the encryption of each alpha character 
//f (x) = 3x5 − 9x3 − 5x + 1 (mod 26)
//which takes as input any integer x ranging from 0 to 25. Consider the following encryption scheme: to encrypt an ℓ-character message m = m1m2 · · · mℓ
float resultOfFunction(int alphaValue)
{
    int functionResult = 3 * (pow(alphaValue, 5)) - 9 * (pow(alphaValue, 3)) - (5 * alphaValue) + 1;
    float modResult = functionResult % 26;
    return modResult;
}

//Function that decrypts the message 
string decryptMessage(const string &encryptedMessage, const vector<float> &resOfFunction)
{
    string decryptedMessage;

  //Loop through each character in the message
for (size_t i = 0; i < encryptedMessage.size(); i++)
{
  //Retrieving the character at the current index i from the encryptedMessage string and storing it in the variable encryptedChar. --> Can thus work with the current character during decrypt process
    char encryptedChar = encryptedMessage[i];

  //Calculates encrypted index for the current character. - 'a' from encryptedChar maps the character to its corresponding encrypted index. (I.E if encryptedChar is 'g', then encryptedIndex would be 6.)
    int encryptedIndex = encryptedChar - 'a';

  //Placeholder for the decrypted index
    float decryptedIndex = -1;  

        //Find the index in resOfFunction that matches the encrypted index
        for (size_t j = 0; j < resOfFunction.size(); j++)
        {
            //checking if the value at index i in the resOfFunction array matches the encryptedIndex
            //If they match --> found the original alphabet index that corresponds to the current encrypted character
            if (resOfFunction[j] == encryptedIndex)
            {
                decryptedIndex = j;
                break;
            }
        } //end of for loop
        
        
    //If the decryption was successful, you calculate the ASCII value of the decrypted character by adding 
    //the decryptedIndex to the ASCII value of 'a'. --> maps the decrypted index back to the original 
    //letter in the alphabet.
        if (decryptedIndex != -1)
        {
            char decryptedChar = decryptedIndex + 'a';
            
            //After calculating the decrypted character, append it to the decryptedMessage.
            //This accumulates the characters as iterate thr encrypted message, reconstructing the original message
            decryptedMessage += decryptedChar;
        }
        else
        {
            cout << "Decryption Failed! It seems the encrypted character is not a proper result of the mathematical function. Please check your encrypted message and try again.";
        }
    }

    return decryptedMessage;
}
