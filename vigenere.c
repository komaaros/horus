#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int check(string x);

int main(int argc, string argv[])
{
    
    // checks if there is only one command-line argument
    if (argc == 1)
    {
        printf("Usage: ~/Dropbox/pset2/vigenere <keyword>\n");
        return 1;
    }
    
    // checks if there are two command-line arguments
    else if (argc == 2)
    {
        int chck_arg;
        string second_arg;
        second_arg = argv[1];
        chck_arg = check(second_arg);
        
        /* checks if among second command-line argument
           there is character which is not alphabetic*/
        if (chck_arg == 1)
        {
            printf("Keyword must only contain letters A-Z and a-z\n");
            return 1;
        }
        
        // main program
        else
        {
            int n = 0;
            int y, j;
            string text;
            j = 0;
            y = 0;
            n = strlen(argv[1]);
            int sec_arg[n], key[n];
            
            // takes value of second command-line argument
            for (j = 0; j < n; j++, y++)
            {
                sec_arg[y] = argv[1][j];
            }
            
            // formes key based on second-line argument
            for ( int q = 0; q < n; q++)
            {
                /* checks for lowercase letters in 
                   second command-line argument*/
                if ((sec_arg[q] >= 'a') && (sec_arg[q] <= 'z'))
                {
                    key[q] = sec_arg[q] % 97;
                }
                else
                {
                    key[q] = sec_arg[q] % 65;
                } 
            }
            text = GetString();
            int t;
            t = strlen(text);
            int cipher[t], temp[t];
            int f = 0;
            
            // ciphers the input text
            for (int p = 0; p < t; p++)
            {
            
                // checks whether input text has lowercase letters
                if ((text[p] >= 'a') && (text[p] <= 'z'))
                {
                    temp[p] = text[p] % 97;
                    cipher[p] = (key[f] + temp[p]) % 26;
                    
                    // cycles keyword if it is shorter than input text
                    if (f == (n - 1))
                    {
                        f = 0;
                    }
                    else
                    {
                        f++;
                    }
                    cipher[p] = 97 + cipher[p];
                    printf("%c", (char) cipher[p]);
                }
            
                // checks whether input text has uppercase letters
                else if ((text[p] >= 'A') && (text[p] <= 'Z'))
                {
                    temp[p] = text[p] % 65;
                    cipher[p] = (key[f] + temp[p]) % 26;
                
                    // cycles keyword if it is shorter than input text
                    if (f == (n - 1))
                    {
                        f = 0;
                    }
                    else
                    {
                        f++;
                    }
                    cipher[p] = 65 + cipher[p];
                    printf("%c", (char) cipher[p]);
                }
            
                /* if characters in text are not alphabetic 
                   it prints them out whitout ciphering*/
                else 
                {
                    printf("%c", text[p]);
                }
            } 
            printf("\n");   
            return 0;
        }
    }
    else 
    {
        printf("Usage: ~/Dropbox/pset2/vigenere <keyword>\n");
        return 1;
    }
}

/* function for checking if second command-line 
   argument has non alphabetic characters*/
int check(string x)
{
    int n;
    int i = 0;
    for ( i = 0; i < strlen(x); i++)
    {
        if (!isalpha(x[i]))
        {
            n = 1;
            break;
        }
        else
        {
            n = 0;
        }
    }
    return n;
}
