#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// WIN32;_DEBUG;_CONSOLE;%(PreprocessorDefinitions)
/*
    This program is written by Muhammad Farasat Hussain. :D
*/

typedef struct string
{
    char characters[50];

} string;

typedef struct character
{
    char alphabeth;

    struct character *nextAlphabeth;

} character;

typedef struct word
{
    character *alphabethList;

    struct word *nextWord;

} word;

typedef enum bool
{
    false,
    true

} bool;

// Reference.
character *deleteAllAlphabeths(character *head);

// Clear console screen.
void clearScreen()
{
    system("cls");
}

// Printing menu on console screen.
void printMenu()
{
    printf("\n\n          Menu\n");
    printf("          ----\n");
    printf("\n          A ... Display all words");                     // done.
    printf("\n          B ... Reverse complete list inner and outer"); // done.
    printf("\n          C ... Reverse only inner list");               // done.
    printf("\n          D ... Reverse only outer list");               // done.
    printf("\n          E ... Rotate list left");                      // done.
    printf("\n          F ... Rotate list right");                     // done.
    printf("\n          G ... Uppercase all letters");                 // done.
    printf("\n          H ... Lowercase all letters");                 // done.
    printf("\n          I ... Uppercase specific letter");             // done.
    printf("\n          J ... Lowercase specific letter");             // done
    printf("\n          K ... Uppercase first letter");                // done
    printf("\n          L ... Lowercase first letter");                // done
    printf("\n          M ... Replace list string");                   // done
    printf("\n          N ... Append word in word list");              // done.
    printf("\n          O ... Insert a word in a particular index");   // done.
    printf("\n          P ... Delete particular index");               // done.
    printf("\n          Q ... Quit application");                      // done.
}

// Checking user commnad.
bool IsCommandValid(char command)
{
    if (command < 'R')
    {
        return true;
    }

    return false;
}

// Converting lowercase into uppercase.
char toUpper(char command)
{
    if (command >= 'a' && command <= 'z') // ToUpper if character is in lower case.
    {
        command = command - 32;
    }

    return command;
}

// Converting lowercase into uppercase.
char toLower(char command)
{
    if (command >= 'A' && command <= 'Z') // ToLower if character is in upper case.
    {
        command = command + 32;
    }

    return command;
}

// Reading command from user.
char readCommand()
{
    char command;

    while (true)
    {
        printf("\n\n          Please select one of them: ");
        scanf(" %c", &command);

        // ToUpper if character is in lower case.
        command = toUpper(command);

        if (IsCommandValid(command))
        {
            break;
        }

        printf("\n          You are entering an invalid commnad!!");
    }

    return command;
}

// Reading a string from user.
string readWord()
{
    string word;

    printf("\n          Please enter a word: ");
    scanf("%s", word.characters);

    return word;
}

// Inserting a character at the start of the list.
character *insertAtStart(character *head, char element)
{
    character *newHead = (character *)malloc(sizeof(character));

    newHead->alphabeth = element;
    newHead->nextAlphabeth = head;

    return newHead;
}

// Inserting a character at the last of the list.
character *insertAtLast(character *head, char element)
{
    character *newHead = (character *)malloc(sizeof(character));

    character *pointer = head;

    while (pointer->nextAlphabeth != NULL)
    {
        pointer = pointer->nextAlphabeth;
    }

    newHead->alphabeth = element;

    pointer->nextAlphabeth = newHead;
    newHead->nextAlphabeth = NULL;

    return head;
}

// Creating a word by joing all characters.
character *createAlphabethList(character *head, string word)
{
    head = NULL; // I need to ask it.

    for (int i = 0; word.characters[i] != '\0'; i++)
    {
        if (head == NULL)
        {
            head = insertAtStart(head, word.characters[i]);
        }
        else
        {
            head = insertAtLast(head, word.characters[i]);
        }
    }

    return head;
}

// Deleting all characters.
character *deleteAllAlphabeths(character *head)
{
    character *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->nextAlphabeth;
        free(temp);
    }

    return head;
}

// Inserting a word at the start of the list.
word *insertWordAtStart(word *aWord, character *alphabethList)
{
    word *newHead = (word *)malloc(sizeof(word));

    newHead->alphabethList = alphabethList;
    newHead->nextWord = aWord;

    return newHead;
}

// Inserting a word at the last of the list.
word *insertWordAtLast(word *aWord, character *alphabethList)
{
    word *newHead = (word *)malloc(sizeof(word));

    word *pointer = aWord;

    while (pointer->nextWord != NULL)
    {
        pointer = pointer->nextWord;
    }

    newHead->alphabethList = alphabethList;

    pointer->nextWord = newHead;

    newHead->nextWord = NULL;

    return aWord;
}

// Adding word in the list.
word *addWordInList(word *aWord, character *alphabethList)
{
    if (aWord == NULL)
    {
        return insertWordAtStart(aWord, alphabethList);
    }

    return insertWordAtLast(aWord, alphabethList);
}

// Printing list on the console screen.
void printList(word *wordList)
{
    int length = 0;
    if (wordList == NULL)
    {
        printf("\n          List is empty");
    }
    else
    {
        word temp = *wordList;

        printf("\n\n          ");

        for (&temp; &temp != NULL; temp = *temp.nextWord)
        {
            printf("[");
            for (temp.alphabethList; temp.alphabethList != NULL; temp.alphabethList = temp.alphabethList->nextAlphabeth)
            {
                printf(" %c ", temp.alphabethList->alphabeth);
            }
            printf("]");

            if (temp.nextWord == NULL)
            {
                break;
            }
        }
    }
}

// Reversing only word list / outer list.
word *reverseOuterList(word *head)
{
    word *firstword = NULL;
    word *middleword = head;
    word *secondword = head;

    while (secondword != NULL)
    {
        secondword = secondword->nextWord;
        middleword->nextWord = firstword;
        firstword = middleword;
        middleword = secondword;
    }

    head = firstword;

    return head;
}

// Reversing only character list node / inner list.
character *reverseInnerListNode(character *head)
{
    character *firstword = NULL;
    character *middleword = head;
    character *secondword = head;

    while (secondword != NULL)
    {
        secondword = secondword->nextAlphabeth;
        middleword->nextAlphabeth = firstword;
        firstword = middleword;
        middleword = secondword;
    }

    head = firstword;

    return head;
}

// Reversing complete character list / inner list.
word *reverseInnerList(word *head)
{
    word *temp = head;

    for (temp; temp != NULL; temp = temp->nextWord)
    {
        temp->alphabethList = reverseInnerListNode(temp->alphabethList);
    }

    return head;
}

// Counting total nodes of list.
int countTotalIndex(word *wordList)
{
    int totalIndex = 0;
    word *temp = wordList;

    for (temp; temp != NULL; temp = temp->nextWord)
    {
        totalIndex++;
    }

    return totalIndex;
}

// Validating index.
bool isIndexValid(int index, int totalIndex)
{
    if (index < 1)
    {
        return false;
    }

    if (index > totalIndex)
    {
        return false;
    }

    return true;
}

// Reading index from user.
int readValidIndex(int totalIndex)
{
    int index;

    while (true)
    {
        printf("\n          Enter index: ");
        scanf("%d", &index);

        if (isIndexValid(index, totalIndex))
        {
            break;
        }

        printf("\n          You are entering an invalid index");
    }

    return index - 1;
}

// Deleting inner / character list node.
character *deleteInnerListNode(character *head)
{
    character *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->nextAlphabeth;
        free(temp);
    }

    return head;
}

// Delete first node from word list / outer list.
word *deleteFirstNode(word *head)
{
    word *newHead = head->nextWord;

    head->alphabethList = deleteInnerListNode(head->alphabethList);

    free(head);

    return newHead;
}

// Deleting node by particular index.
word *deleteIndex(word *head, int index)
{
    if (head == NULL)
    {
        return head;
    }

    word *tempOne = head;
    word *tempTwo = head->nextWord;

    if (index == 0)
    {
        return deleteFirstNode(head);
    }

    for (int i = 0; i < index - 1; i++)
    {
        tempOne = tempOne->nextWord;
        tempTwo = tempTwo->nextWord;
    }

    tempOne->nextWord = tempTwo->nextWord;

    tempTwo->alphabethList = deleteInnerListNode(tempTwo->alphabethList);

    free(tempTwo);

    return head;
}

// Deleting all nodes from word list / outer list.
word *deleteAllIndex(word *head, int totalIndex)
{
    if (head == NULL)
    {
        return head;
    }

    for (int i = 0; i < totalIndex; i++)
    {
        head = deleteIndex(head, 0);
    }

    return head;
}

// Converting character list node from lowercase to uppercase.
character *doLowerToUpper(character *head)
{
    character *temp = head;

    for (temp; temp != NULL; temp = temp->nextAlphabeth)
    {
        temp->alphabeth = toUpper(temp->alphabeth);
    }

    return head;
}

// Converting complete list from lowercase to uppercase.
word *doUpper(word *head)
{
    if (head == NULL)
    {
        return head;
    }

    word *temp = head;

    for (temp; temp != NULL; temp = temp->nextWord)
    {
        temp->alphabethList = doLowerToUpper(temp->alphabethList);
    }

    return head;
}

// Converting character list node from uppercase to lowercase.
character *doUpperToLower(character *head)
{
    character *temp = head;

    for (temp; temp != NULL; temp = temp->nextAlphabeth)
    {
        temp->alphabeth = toLower(temp->alphabeth);
    }

    return head;
}

// Converting complete list from uppercase to lowercase.
word *doLower(word *head)
{
    if (head == NULL)
    {
        return head;
    }

    word *temp = head;

    for (temp; temp != NULL; temp = temp->nextWord)
    {
        temp->alphabethList = doUpperToLower(temp->alphabethList);
    }

    return head;
}

// Converting a particular letter from lower to uppercase.
character *doUpperCaseSpecificLetter(character *head, char letter)
{
    character *temp = head;

    for (temp; temp != NULL; temp = temp->nextAlphabeth)
    {
        if (temp->alphabeth >= 'a' && temp->alphabeth <= 'z')
        {
            if (temp->alphabeth == letter)
            {
                temp->alphabeth = temp->alphabeth - 32;
            }
        }
    }

    return head;
}

// Converting a particular letter of all nodes from lower to uppercase.
word *doUpperCaseSpecificLetterOfCompleteList(word *head, char letter)
{
    if (head == NULL)
    {
        return head;
    }

    if (letter >= 'A' && letter <= 'Z')
    {
        letter = letter + 32;
    }

    word *temp = head;

    for (temp; temp != NULL; temp = temp->nextWord)
    {
        temp->alphabethList = doUpperCaseSpecificLetter(temp->alphabethList, letter);
    }

    return head;
}

// Converting a particular letter from upper to lowercase.
character *doLowerCaseSpecificLetter(character *head, char letter)
{
    character *temp = head;

    for (temp; temp != NULL; temp = temp->nextAlphabeth)
    {
        if (temp->alphabeth >= 'A' && temp->alphabeth <= 'Z')
        {
            if (temp->alphabeth == letter)
            {
                temp->alphabeth = temp->alphabeth + 32;
            }
        }
    }

    return head;
}

// Converting a particular letter of all nodes from upper to lower.
word *doLowerCaseSpecificLetterOfCompleteList(word *head, char letter)
{
    if (head == NULL)
    {
        return head;
    }

    if (letter >= 'a' && letter <= 'z')
    {
        letter = letter - 32;
    }

    word *temp = head;

    for (temp; temp != NULL; temp = temp->nextWord)
    {
        temp->alphabethList = doLowerCaseSpecificLetter(temp->alphabethList, letter);
    }

    return head;
}

// Converting only first letter of each node from lower to uppercase.
word *doUpperCaseFirstLetterOfEveryWord(word *head)
{
    word *temp = head;

    for (temp; temp != NULL; temp = temp->nextWord)
    {
        temp->alphabethList->alphabeth = toUpper(temp->alphabethList->alphabeth);
    }

    return head;
}

// Converting only first letter of each node from upper to lowercase.
word *doLowerCaseFirstLetterOfEveryWord(word *head)
{
    word *temp = head;

    for (temp; temp != NULL; temp = temp->nextWord)
    {
        temp->alphabethList->alphabeth = toLower(temp->alphabethList->alphabeth);
    }

    return head;
}

// Reading a letter from user.
char getLetter()
{
    char letter;

    printf("\n          Enter a letter: ");
    scanf(" %c", &letter);

    return letter;
}

// Inserting a new node at particular index.
word *insertAt(word *wordList, character *alphabethList, int index)
{
    if (index == 0)
    {
        return insertWordAtStart(wordList, alphabethList);
    }

    word *temp = (word *)malloc(sizeof(word));

    temp->alphabethList = alphabethList;

    word *tempA = wordList;

    for (int i = 0; i < index - 1; i++)
    {
        tempA = tempA->nextWord;
    }

    temp->nextWord = tempA->nextWord;
    tempA->nextWord = temp;

    return wordList;
}

// Overwriting a index value.
word *overwriteIndexValue(word *wordList, character *alphabethList, int index)
{
    word *temp = wordList;

    for (int i = 0; i < index; i++)
    {
        temp = temp->nextWord;
    }

    temp->alphabethList = alphabethList;

    return wordList;
}

// Rotating list to right.
word *rotateRight(word *wordList)
{
    if (wordList == NULL)
    {
        return wordList;
    }

    word *pointerA = wordList;
    word *pointerB = wordList->nextWord;
    word *pointerC = NULL;

    while (pointerB->nextWord != NULL)
    {
        pointerA = pointerA->nextWord;
        pointerB = pointerB->nextWord;
    }

    pointerA->nextWord = NULL;
    pointerC = pointerB;
    pointerC->nextWord = wordList;
    wordList = pointerC;

    return wordList;
}

// Rotating list to left.
word *rotateLeft(word *wordList)
{
    if (wordList == NULL)
    {
        return wordList;
    }

    word *tempA = wordList->nextWord;
    word *tempB = wordList;
    wordList = tempA;

    word *tempC = NULL;

    while (tempA->nextWord != NULL)
    {
        tempA = tempA->nextWord;
    }

    tempB->nextWord = NULL;

    tempC = tempB;

    tempA->nextWord = tempC;

    tempC->nextWord = NULL;

    return wordList;
}

int main()
{


    character *alphabethList = NULL;

    word *wordList = NULL;

    char command;
    int index;
    string word;
    int totalIndex;
    char letter;

    while (true)
    {
        clearScreen();
        printMenu();
        command = readCommand();

        switch (command)
        {
        case 'A': // Display word list.

            clearScreen();

            printf("\n          YOUR CREATED LIST:\n");
            printf("          ==================\n\n\n");

            printList(wordList);

            while (true)
            {
                printf("\n\n\n\n          Please enter B to go back: ");
                scanf(" %c", &command);

                command = toUpper(command);

                if (command == 'B')
                {
                    clearScreen();
                    break;
                }

                printf("          You are entering an invalid input");
            }

            break;
        case 'B': // reverse both outer and inner list. for example list is "[Hello]->[World]->NULL" after reverse "[dlroW]->[olleH]->NULL".
            wordList = reverseOuterList(wordList);
            wordList = reverseInnerList(wordList);
            break;
        case 'C': // reverse only inner list. for example a word is "[Hello]->NULL" after reverse "[olleH]->NULL".
            wordList = reverseInnerList(wordList);
            break;
        case 'D': // reverse only outer list. for example a word is "[Hello]->[World]->NULL" after reverse "[World]->[Hello]->NULL".
            wordList = reverseOuterList(wordList);
            break;
        case 'E': // Rotate left.
            wordList = rotateLeft(wordList);
            break;
        case 'F': // Rotate right.
            wordList = rotateRight(wordList);
            break;
        case 'G': // Uppercase all letters.
            wordList = doUpper(wordList);
            break;
        case 'H': // Lowercase all letters.
            wordList = doLower(wordList);
            break;
        case 'I': // Uppercase specific letter.
            letter = getLetter();
            wordList = doUpperCaseSpecificLetterOfCompleteList(wordList, letter);
            break;
        case 'J': // Lowercase specific letter.
            letter = getLetter();
            wordList = doLowerCaseSpecificLetterOfCompleteList(wordList, letter);
            break;
        case 'K': // Uppercase first letter.
            wordList = doUpperCaseFirstLetterOfEveryWord(wordList);
            break;
        case 'L': // Lowercase first letter.
            wordList = doLowerCaseFirstLetterOfEveryWord(wordList);
            break;
        case 'M': // Replace index value.
            if (wordList != NULL)
            {
                word = readWord();
                alphabethList = createAlphabethList(alphabethList, word);
                totalIndex = countTotalIndex(wordList);
                index = readValidIndex(totalIndex);
                wordList = overwriteIndexValue(wordList, alphabethList, index);
            }
            break;
        case 'N': // Add new word.
            word = readWord();
            alphabethList = createAlphabethList(alphabethList, word);
            wordList = addWordInList(wordList, alphabethList);
            break;
        case 'O': // Insert node at particular index.
            if (wordList != NULL)
            {
                word = readWord();
                alphabethList = createAlphabethList(alphabethList, word);
                totalIndex = countTotalIndex(wordList);
                index = readValidIndex(totalIndex);
                wordList = insertAt(wordList, alphabethList, index);
            }
            break;
        case 'P': // Delete by index.
            if (wordList != NULL)
            {
                totalIndex = countTotalIndex(wordList);
                index = readValidIndex(totalIndex);
                wordList = deleteIndex(wordList, index);
            }
            break;
        case 'Q': // Delete complete list and exit application.

            printf("\n          Do you really want to close your application? [Y/N]  ");

            while (true)
            {
                scanf(" %c", &command);

                command = toUpper(command);

                if (command == 'N' || command == 'Y')
                {
                    break;
                }

                printf("\n          You are entering an invalid input");
                printf("\n\n          Please enter either Y or N: ");
            }

            if (command == 'Y')
            {
                totalIndex = countTotalIndex(wordList);
                wordList = deleteAllIndex(wordList, totalIndex);
                exit(0);
            }
            else
            {
                break;
            }

        default:
            break;
        }
    }

    return 0;
};