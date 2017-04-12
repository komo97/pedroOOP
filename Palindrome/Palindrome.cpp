// Palindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

///<summary>
///Assigns lenght the value of the size of the char array that is occupied.
///Only works for arrays that have been initialized with '\0'.
///</summary>
///<param name="arr"> The char array to work with.</param>
///<param name="lenght"> The int that will hold the lenght of the used part of the array.</param>
void Count(char* arr, int &lenght)
{
	lenght = 0;
	while (arr[lenght++] != '\0');
}

///<summary>
///Helper for intializing a char Array. Sets every value of the array to '\0'.
///</summary>
///<param name="size"> The complete size of the array.</param>
void InitCharArray(char* &arr, int size)
{
	for (int i = size; --i;)
	{
		arr[i] = '\0';
	}
}

///<summary>
///Removes the spaces of a sentence in a char array
///</summary>
void RemoveSpaces(char* &arr, int &wordLenght)
{
	int lengthWithoutSpaces = 0;
	for (int i = wordLenght; --i;)
	{
		if (arr[i] != ' ') ++lengthWithoutSpaces;
	}

	char* arrCopy = new char[lengthWithoutSpaces];

	for (int j = 0, i = 0; i < wordLenght; ++i)
	{
		if (arr[i] != ' ')
			arrCopy[j++] = arr[i];
	}
	wordLenght = lengthWithoutSpaces;
	arr = arrCopy;
}

///<summary>
///Checks if a char array is a palindrome
///</summary>
bool IsPalindrome(char* &arr, int wordLenght)
{
	int i = 0, j = wordLenght - 1;

	while (i < wordLenght && arr[i++] == arr[j--]);

	return i == wordLenght;
}

int main()
{
	//Inicializando la variable a trabajar, hay que declararla por que sino no funciona. (Qusiera usar strings :() 
	char* word = new char[100];
	int wordLenght = 0;

	InitCharArray(word, 100);

	std::cout << "Introduce tu palabra. Maximo 100 caracteres." << std::endl;
	std::cin.getline(word, 100);

	Count(word, wordLenght);

	RemoveSpaces(word, wordLenght);

	std::cout << (IsPalindrome(word,wordLenght) ? "Si es palindromo." : "No es palindromo");

	return 0;
}

