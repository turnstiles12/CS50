#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
void encipher(string key);
int main(int argc, string argv[]) //Get key
{
    if (argc!=2)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    int l = strlen(argv[1]);
    for(int i = 0; i<l; i++)
    {

        if(isalpha(argv[1][i])==0)//If there are non-letters
        {
            printf("Key can only contain letters.\n");
            return 1;
        }
        if(l!=26) //If not 26 letters
        {
            printf("Key must contain 26 letters.\n");
            return 1;
        }
        for(int t=0; t<l; t++)
        {
            for(int j=t+1; j<l; j++)
            {
                if(argv[1][t]==argv[1][j])//If a letter is repeated
                {
                    printf("Key must only contain one of each letter.\n");
                    return 1;
                }
            }
        }

    }
    encipher(argv[1]);//output ciphertext

}

void encipher(string key)//create cipher text and print it
{
    string pt = get_string("plaintext: ");//output ("plaintext: ") and have user input their plaintext
    int ptLength = strlen(pt);
    printf("ciphertext: ");
    for (int i=0; i<ptLength; i++)//For each alphabetic character
    {
        //convert pt into the ciphertext usint the key
        if(isalpha(pt[i])!=0) //If it's a letter
        {
            if(isupper(pt[i])!=0)
            {
                char letter = toupper(key[(pt[i]-65)]);//convert key letter to upper
                printf("%c", letter);
            }
            else
            {
                char letter = tolower(key[(pt[i]-97)]);//convert key letter to lower
                printf("%c", letter);//print the cipher text
            }
        }
        else
        {
            printf("%c", pt[i]);
        }
    }
    printf("\n");
}
