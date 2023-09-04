/************ Task 1   (Number Guessig Game) **********/

#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int main()
{
    system("cls");
    int number,guess,tries=0;
    srand(time(0));
    number=rand()%100+1;
    cout << "Number Guessing Game \n\n";

    do
    {
        cout <<"Enter the  number b/w 1 to 100 : ";
        cin >> guess;
        tries++;
        if(guess > number)
        cout <<"Too high!\n\n";
        else if(guess<number)
        cout <<"Too low\n\n";
        else
        cout <<"\nCorrect!, number guessed  in "<<tries<<" tries";
    }
    while(guess!=number);

    return 0;
}