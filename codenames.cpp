#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

void printMap();
void randomise();
void decider();

vector<string> chosen;

int main()
{
	decider();
	randomise();
	printMap();

    return 0;
}

void randomise()
{
	srand(time(0));

	for (int i=0; i<(25-1); i++) {
        int r = i + (rand() % (25-i)); // Random remaining position.
        string temp = chosen[i]; chosen[i] = chosen[r]; chosen[r] = temp;
    }

}

void printMap()
{
	for (int i = 0; i < 25; ++i)
    {
    	if(chosen[i] == "RED")
    	{
    		cout << "\033[1;31m";
    	}
    	else if(chosen[i] == "BLUE")
    	{
    		cout << "\033[1;34m";
    	}
    	cout << chosen[i] << "	" << "\033[0m";
    	if((i+1)%5 == 0)
    	{
    		cout << "\n";
    	}
    }
    cout << "\n";
}

void decider()
{
	string decide[2][25] = {
		{"RED", "RED", "RED", "RED", "RED", "RED", "RED", "RED", "RED", "BLUE", "BLUE", "BLUE", "BLUE", "BLUE", "BLUE", "BLUE", "BLUE", "X", "_", "_", "_", "_", "_", "_", "_"},
		{"RED", "RED", "RED", "RED", "RED", "RED", "RED", "RED", "BLUE", "BLUE", "BLUE", "BLUE", "BLUE", "BLUE", "BLUE", "BLUE", "BLUE", "X", "_", "_", "_", "_", "_", "_", "_"}
	};

	srand(time(0));
	int randInd = rand()%2;

    if(randInd == 0){
        cout << "\nRed to start!\n";
    }
    else{
        cout << "\nBlue to start!\n";
    }

	for(int i = 0; i < 25; i++)
	{
		chosen.push_back(decide[randInd][i]);
	}
}