#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//declaring the letter count function
int letter_count(string letters);

//declaring the word count function
int word_count(string words);

//declaring the sentence count function
int sentence_count(string sens);


int main(void)
{
    //taking input from users
    string text = get_string("Text: ");

    //nol(number of letters) calling the letter count function
    int nol = letter_count(text);
    // printf("%i letter(s)\n", nol);

    //now(number of words) calling the word count function
    int now = word_count(text);
    // printf("%i word(s)\n", now);

    //nos(number of sentence) calling sentence count function
    int nos = sentence_count(text);
    // printf("%i sentence(s)\n", nos);

    //calculation
    float cal = (0.0588 * nol / now * 100) - (0.296 * nos / now * 100) - 15.8;
    //converting the value to an integer
    int index = round(cal);

    //printing out the Grade
    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index > 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i", index);
    }
    printf("\n");
}


//definition of letter count funtion
int letter_count(string letters)
{
    int no_of_letters = 0;

    //string iteration for letter count
    for (int i = 0, sl = strlen(letters); i < sl; i++)
    {
        //checking for only capital or small letters in the string
        //word count
        if (islower(letters[i]) || isupper(letters[i]))
        {
            no_of_letters++;
        }
    }
    return no_of_letters;
}


//definition of word count function
int word_count(string words)
{
    //declaring count variables
    int no_of_words = 0;
    int no_of_letters = 0;

    //string iteration for word count
    for (int i = 0, sl = strlen(words); i < sl; i++)
    {
        //repeating letter count logic for use in word count
        if (islower(words[i]) || isupper(words[i]))
        {
            no_of_letters++;
        }
        //word count
        if (words[i] == 32)
        {
            no_of_words++;
        }
    }

    //declaring a variable for differentiation
    int logic = no_of_words;

    //final word count
    //word count if their is no space and number of letters is greater that 1
    if (logic == 0 && no_of_letters > 1)
    {
        logic++;
        return logic;
    }
    else if (logic >= 1)
    {
        logic++;
        return logic;
    }
    else
    {
        return no_of_words;
    }
}

//defining sentence count function
int sentence_count(string sens)
{
    //declaring count varible
    int logic = 0;
    int no_of_sen = 0;

    //string iteration for sentence count
    for (int i = 0, sl = strlen(sens); i < sl; i++)
    {
        //repeating word count for use in sentence count using logic
        if (sens[i] == 32)
        {
            logic++;
        }
        //sentence count
        if (sens[i] == '.' || sens[i] == '!' || sens[i] == '?')
        {
            no_of_sen++;
        }
    }

    //final sentence count
    if (no_of_sen == 0 && logic >= 1)
    {
        no_of_sen++;
        return no_of_sen;
    }
    else
    {
        return no_of_sen;
    }
}