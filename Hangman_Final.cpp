#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
#include<fstream>
using namespace std;

const int MAX_TRIES = 7;
int letterFill(char, string, string&);

void fileIO(string words[])
{
	int count = 0;
	string st;
	ifstream fin("words.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, st);
			words[count] = st;
			count++;
		}
		fin.close();
	}
	else
		cout << "NO file found\n";
}
int main()
{
	string name;
	char letter;
	string words[15];
	fileIO(words);
	int num_of_wrong_guesses = 0;
	string word;

	srand(time(NULL));
	int n = rand() % 10;
	word = words[n];


	string unknown(word.length(), '*');


	cout << "\n\nWelcome to hangman...";
	
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n~~~~~~~";

    
	while (num_of_wrong_guesses < MAX_TRIES)
	{
        if(num_of_wrong_guesses==0)
        {
            cout<<"\t\t\t\\t\\tt\\n";
        }
        if( num_of_wrong_guesses==1)
        {
            cout<<"\t\t\t\t\n";
            cout<<"\t\t\t\t|\n";
        }
        else if(num_of_wrong_guesses==2)
        {
             cout<<"\t\t\t\t| \n";
            cout<<"\t\t\t\tO\n";
        }
        else if(num_of_wrong_guesses==3)
        {
            cout<<"\t\t\t\t| \n";
            cout<<"\t\t\t\tO\n";
            cout<<"\t\t\t\t|\n";
        }
        else if(num_of_wrong_guesses==4)
        {
            cout<<"\t\t\t\t | \n";
            cout<<"\t\t\t\t O \n";
            cout<<"\t\t\t\t/| \n";
        }
        else if(num_of_wrong_guesses==5)
        {
            cout<<"\t\t\t\t | \n";
            cout<<"\t\t\t\t O   \n";
            cout<<"\t\t\t\t/|\\  \n";
        }
        else if(num_of_wrong_guesses==6)
        {
            cout<<"\t\t\t\t  | \n";
            cout<<"\t\t\t\t  O \n";
            cout<<"\t\t\t\t /|\\ \n";
            cout<<"\t\t\t\t / \n";
        }   
        else if(num_of_wrong_guesses==7)
        //else
        {
            cout<<"\t\t\t\t  | \n";
            cout<<"\t\t\t\t  O \n";
            cout<<"\t\t\t\t /|\\ \n";
            cout<<"\t\t\t\t / \\ \n";
        }
       
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		
		if (letterFill(letter, word, unknown) == 0)
		{
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "You found a letter! Isn't that exciting!" << endl;
		}
		
		cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
	
		if (word == unknown)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}
	}
	if (num_of_wrong_guesses == MAX_TRIES)
	{
		cout<<"\t\t\t\t  | \n";
		cout<<"\t\t\t\t  O \n";
            cout<<"\t\t\t\t /|\\ \n";
            cout<<"\t\t\t\t / \\ \n";
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was : " << word << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}



int letterFill(char guess, string secretword, string& guessword)
{
	int i;
	int matches = 0;
	int len = secretword.length();
	for (i = 0; i < len; i++)
	{
		
		if (guess == guessword[i])
			return 0;
	
	
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}