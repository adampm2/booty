#include <cs50.h>
#include <stdio.h>
#include <wctype.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, string argv[])
{

    // this gets the key to encode/decode your text.


    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // sets the string length to a variable

    int stlen = strlen(argv[1]);

    if (stlen != 26)
    {
        printf ("Key must contain 26 characters.\n");
        return 1;
    }

        // set a string equal to an array for easier recall.
       // used two var's is alphasum and isalpha to conclude if there are 26 characters AND only alpha characters are there.

    string key = argv[1];
    int var_isalphasum = 0;
    int var_isalpha = 0;

    // for loop to count the number of alpha characters

    for (int i_0 = 0; i_0 < stlen; i_0++)
    {
        var_isalpha = isalpha(key[i_0]);
        if(var_isalpha != 0)
        {
            var_isalphasum = var_isalphasum + 1;
        }

    }

    // if statement to return error if less than 26 alpha characters

    if(var_isalphasum != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // prompted for the string plaintext and stored it into the pt variable.
    // also recalled the key being used and the plaintext being used

    string pt = get_string("plaintext:");
    printf("Your key is: %s.\n", argv[1]);
    printf("Plaintext: %s\n", pt);

// this formats the substitution into all lowercase.  so when you input your key it goes from A to a and z to z to get a general basis of the key.
// the end format will not matter if a capital letter and lowercase letter is transformed into each other because we are retaining case from plaintext to cyphertext.


    for(int i_1 = 0; i_1 < stlen; i_1++)
    {
        while(isupper(key[i_1]))
        {
            key[i_1] = tolower(key[i_1]);
        }
    }


// this will split each character up into capitals, lowercase and other.
// will do nothing to nonalpha, but will retain case and convert them to one another.
//prompted the output name of "cyphertext"
//stored the string abc and ABC so that they can be used to compare what character is what and at what location it is stored at.

    printf("cyphertext is: ");
    string abc = "abcdefghijklmnopqrstuvwxyz";
    string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //this for loop looks through all letters in the string "pt" aka the plaintext


    for(int i_2 = 0; i_2 < strlen(pt); i_2++ )
    {
        int ptint_1 = pt[i_2]; //added a variable here because declairing a array as an int was causing errors.  not sure if it matters.

        if( (ptint_1 >= 65 && ptint_1 <= 90) || (ptint_1 >= 97 && ptint_1 <= 122) ) // if logic to make sure my letter is only A->Z or a->z
        {

           if (pt[i_2] >= 65 && pt[i_2] <= 90) // if logic to determine if the program is encoding caps
           {

            for(int i_3 = 0; i_3 < stlen; i_3++) // for loop to find out which letter each i_3th letter is (0-25)
            {
                int int_1 = key[i_3]; // added to stop errors.  sets a variable equal to the int of array at value i_3
                int ABC_1 = ABC[i_3]; // ditto


                if(ptint_1 == ABC_1) // if logic to determine if the letter at ptint_1 (which equals pt[i_2], which is i_2th letter in the plain text string)
                                    //is equal the 0->25th letter in the UPPERCASE alphabet ABC_1 which is equal to the array ABC[i_3].
                {
                    printf("%c", key[i_3] -32 );  // prints out the letter at the value i_3 (0->25) of the key, which corresponds to the first letter in the key
                                                // swapping with the letter A, and the second with b , third with C.
                }

            }

           }

           if (pt[i_2] >= 97 && pt[i_2] <= 122) //if logic to determine if the program is encoding lowercase
            {
               for(int i_4 = 0; i_4 < stlen; i_4++) // for loop to find out which letter each i_3th letter is (0-25)
                {
                    int keyint_2 = key[i_4]; // added to stop errors.  sets a variable equal to the int of array at value i_4
                    int abc_1 = abc[i_4];  // ditto

                    if(ptint_1 == abc_1)  // if logic to determine if the letter at ptint_1 (which equals pt[i_2], which is i_2th letter in the plain text string)
                                    //is equal the 0->25th letter in the lowercase alphabet abc_1 which is equal to the array abc[i_3].
                        {
                            printf("%c", key[i_4]); // prints out the letter at the value i_4 (0->25) of the key, which corresponds to the first letter in the key
                                                // swapping with the letter a, and the second with b , third with c.
                        }

                }
            }
        }
            else // else statement to print out any character that is not A -> z to retain spaces, punctuation, and special characters.
            {
                printf("%c", pt[i_2]);
            }

        }


    printf("\n"); // prints a new line so it looks pretty.

//fin

}
