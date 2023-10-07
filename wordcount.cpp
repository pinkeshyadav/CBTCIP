// C program to count total
// number of words in the string
#include <stdio.h>
#include <string.h>

// Function to count total number
// of words in the string
int countWords(char str[])
{
	// Check if the string is null
	// or empty then return zero
	if (strlen(str) == 0) {
		return 0;
	}
	// Splitting the string around
	// matches of the given regular
	// expression
	char* token;
	char* delim = " \n\t";
	token = strtok(str, delim);
	int count = 0;
	while (token != NULL) {
		count++;
		token = strtok(NULL, delim);
	}

	// Return number of words
	// in the given string
	return count;
}

int main()
{
	// Given String str
	char str[] = "One two	 three\n four\tfive ";
	// Print the result
	printf("No of words : %d", countWords(str));
	return 0;
}
