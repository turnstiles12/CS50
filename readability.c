#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void)
{

    float words = 0;
    float letters = 0;
    float sentences = 0;
    string text = get_string("Text: ");    //input text using ("Text: ")
    int length = strlen(text); //Determine how many characters in the string
    for(int i = 0; i < length; i++){ //Check if each character is a letter or not
        int letterCheck = isalpha(text[i]);
        if(letterCheck != 0) //if it's a letter
        {
            letters++; //Add number of letters
        }
        if(letterCheck !=0 && isblank(text[i+1])) //words
        {
          words++;
        }
        if ((text[i]) =='.' && isalpha(text[i-1]))// sentences
        {
            sentences++;
            words ++;
        }
        if ((text[i]) =='?' && isalpha(text[i-1]))
        {
            sentences++;
            words++;
        }
        if ((text[i]) =='!' && isalpha(text[i-1]))
        {
            sentences++;
            words++;
        }
    }
    float total = words/100;
    float L = letters/total;
    float S = sentences/total;
    float gradeLevel = 0.0588 * L - 0.296 * S -15.8; // caclulate grade level
    if (gradeLevel > 16)
    {
        printf("Grade 16+\n");
    }
    else if(gradeLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade: %.0f\n", gradeLevel);
    }
        printf("Letters: %.0f\n", letters);
        printf("Words: %.0f\n", words);
        printf("Sentences: %.0f\n", sentences);
}
