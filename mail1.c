
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidEmail(char* email);

int main ()
{
    // declaring char array (string)

    char emailInput [100];

    // repeat until stopped by user
    while (true)
    {
    printf ("To stop program enter 'stop'\n");
    printf("Enter your Email address here: ");
    scanf("%s", emailInput); // no '&' because the address in memory is provided because it is a character array.

    // comparing input with string stop
    // based on docs 0 means that input and string are identical
    if (strcmp(emailInput, "stop") == 0)
    {
        printf("Programm stopped\n");
        break;
    }
    
    // validating email
    bool isValid = false;
    isValid = isValidEmail(emailInput);

    //checks isValid boolean exp. depending on value
    //it either prints valid or invalid
    printf("The email is %s\n", isValid ? "Valid" : "Invalid");
    }
    return 0;
}

bool isValidEmail(char* email)
{
    int atCount = 0;
    int dot1 = 0;
    if(strlen(email) == 0)
    {
        return false;
    }

    //strlen --> iterating through the entire string.
    for (int i = 0; i < strlen(email); i++)
    {

        // if at any point in the string a @ is present
        if (email[i] == '@')
        {
            atCount ++; 
           if (email[i+1] == '.')
            {
                return false;
            }
            
        }    
        // checking for char that are not permitted 
        if (email[i] == ' ' || email[i] == '!' || email[i] == '#' 
            || email[i] == ':' || email[i] == ';' || email[i] == '<' 
            || email[i] == '>' || email[i] == ',' 
            || email[i] == '[' || email[i] == ']' || email[i] == '{' 
            || email[i] == '}' || email[i] == '~' || email [i] == '&' 
            || email [i] == '$' || email [i] == '%' )
        {
            return false;
        }
    }

    if (atCount == 1)
    {
        if (email[0] != '@')
        {
            // strchr to find first occurence
            //char* declares a pointer to a char
            // pointer dot to store result of strchr
            char* dot = strchr(email, '.');

            if (dot != NULL && dot > strchr(email, '@'))
            {
                return true;
            }

            if (dot < strchr(email, '@') && email[0] != '.')
            {
                return true;
            }

            if (dot > 2)
            {
                return false;
            }

        }
       
        if (strstr(email, "@gmail.") || strstr(email, "@outlook.") || strstr(email, "@yahoo.") || strstr(email, "@hotmail.")) 
        {
            return true;
        } 
        else 
        {
            return false;
        }
        
    }
    
    return false; // If any of the conditions failed
}
