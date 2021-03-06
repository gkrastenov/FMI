// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Player {

    int strength;
    int health = 10000;
    int luck;
    void levelUp(int value) { level = value; }
    int attack() { return (strength * level * luck) / 10; }
private:
    int level = 1;
};

void fight(Player playerOne, Player playerTwo)
{
    int level = 1;
    while (playerOne.health > 0 && playerTwo.health > 0)
    {
        int attackPlayerOne = playerOne.attack();
        int attackPlayerTwo = playerTwo.attack();


        if (attackPlayerOne > attackPlayerTwo)
        {
            playerOne.luck--;
            playerTwo.luck++;
        }
        
        if (attackPlayerOne < attackPlayerTwo)
        {
            playerOne.luck++;
            playerTwo.luck--;
        }

        if (attackPlayerOne == attackPlayerTwo)
        {
            playerOne.luck--;
            playerTwo.luck--;
        }
        playerOne.health -= attackPlayerTwo;
        playerTwo.health -= attackPlayerOne;

        if (playerOne.health <= 0 || playerTwo.health <= 0)
        {
            break;
        }

        level++;
        playerOne.levelUp(level);
        playerTwo.levelUp(level);
    }

    if (playerOne.health == playerTwo.health)
    {
        cout << "This game did not have winner";
        return;
    }
    if (playerOne.health < playerTwo.health)
    {
        cout << "The winner is player one";
    }
    else {
        cout << "The winner is player two";
    }
}

int main()
{
    Player playerOne, playerTwo;
    cout<<"Player one \n";
    cout << "Luck"<<endl;
    cout << "Number between 2 and 5: ";
    cin >> playerOne.luck;
    cout << "Strength: \n";
    cin >> playerOne.strength;

    cout << "Player two \n";
    cout << "Luck \n";
    cout << "Number between 2 and 5: ";
    cin >> playerTwo.luck;
    cout << "Strength: \n";
    cin >> playerTwo.strength;

    fight(playerOne, playerTwo);
}
