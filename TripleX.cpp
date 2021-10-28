#include <iostream>
#include <ctime>

void PrintIntroduction(int difficultLevel)
{

    //Printing the Story
    std::cout << "\n\nYou're a secret agent breaking into a level " << difficultLevel << " secure server room...\n";
    std::cout << "Enter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    //Declaring 3 numbers
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print the Sum & the product
    std::cout
        << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes multiply to give " << CodeProduct << "\n";
    std::cout << "+ The sum of the codes = " << CodeSum << "\n";

    int GuessA, GuessB, GuessC;

    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "\n";

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "***Well done agent! You have extracted a file! Keep going! *** .";

        return true;
    }
    else
    {
        std::cout << "***You entered the Wrong code! Careful agent! Try again! ***. \n\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    const int MaxLevel = 5;
    int DifficultyLevel = 1;
    while (DifficultyLevel <= MaxLevel)
    {
        bool bLevelComplete = PlayGame(DifficultyLevel);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++DifficultyLevel;
        }
    }
    std::cout << "\n***Great work agent! You got all the files! Now get out of there!***";
    //Return something.
    return 0;
}