// Beginning C++ Game Programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	const int MAX_WRONG = 8;

	vector<string> words;
	words.push_back("APPLE");
	words.push_back("ORANGE");
	words.push_back("BANANA");

	srand(time(0));
	random_shuffle(words.begin(), words.end());

	const string THE_WORD = words[0];
	int guesses = 0;
	string soFar(THE_WORD.size(), '-');
	string used = "";

	cout << "Welcome to Hangman. Good luck!\n";

	while ((guesses < MAX_WRONG) && (soFar != THE_WORD))
	{
		cout << "\n\nYou have " << (MAX_WRONG - guesses) << " incorrect guesses left.\n";
		cout << "\nYou've used the following letters: \n" << used << endl;
		cout << "\nSo far, the word is:\n" << soFar << endl;

		char guess;
		cout << "\nEnter your guess: ";
		cin >> guess;
		guess = toupper(guess);

		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}

		used += guess;

		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "\nThat's right! " << guess << " is in the word.\n";

			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "\nSorry, " << guess << " isn't in the word.\n";
			++guesses;
		}
	}

	if (guesses == MAX_WRONG)
	{
		cout << "\nYou've been hanged!";
	}
	else
	{
		cout << "\nYou've guessed it!";
	}

	cout << "\nThe word was " << THE_WORD << endl;

	return 0;
}