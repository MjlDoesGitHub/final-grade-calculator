// Inspired by https://rogerhub.com/final-grade-calculator/

#include <iostream>
#include <iomanip>
#include "main.h"

int main() {
    std::cout << "This tool will determine what grade (percentage) you need on your final exam in order to get a certain grade in a class.\n";
    float currentGrade = getCurrentGrade();
    float leastGrade = getLeastGrade();
    float finalGrade = getFinalGrade();
    float requiredGrade = calcRequiredGrade(currentGrade, leastGrade, finalGrade);

    std::cout << std::setprecision(4) << "You only need to score at least " << requiredGrade << "% on your final to get a " << leastGrade << "% overall.\n";
    displayPrompt(requiredGrade, leastGrade);
}

float getCurrentGrade()
{
    std::cout << "Your current grade is (%): ";
    float currentGrade{};
    std::cin >> currentGrade;
    return currentGrade;
}

float getLeastGrade()
{
    std::cout << "You want at least a (%): ";
    float leastGrade{};
    std::cin >> leastGrade;
    return leastGrade;
}

float getFinalGrade() {
    std::cout << "Your final is worth (%): ";
    float finalGrade{};
    std::cin >> finalGrade;
    while (finalGrade < 0 || finalGrade == 0 || finalGrade > 100)
    {
        if (finalGrade < 0)
        {
            std::cout << "Your final percentage cannot be negative. Please enter a positive percentage.\n";
        }
        else if (finalGrade == 0)
        {
            std::cout << "Your final percentage cannot be zero. Please enter a positive percentage.\n";
        }
        else if (finalGrade > 100)
        {
            std::cout << "Your final percentage cannot be more than 100%. Please enter a smaller percentage.\n";
        }
        else
        {
            std::cout << "Your final percentage is invalid. Please enter a number.\n";
        }
        std::cout << "Your final is worth (%): ";
        std::cin >> finalGrade;
    }
    return finalGrade;
}

float calcRequiredGrade(float currentGrade, float leastGrade, float finalGrade)
{
    // Required = (Goal − Current × (100% − Final Weight)) / Final Weight
    return 100 * ((leastGrade - currentGrade * (1 - (finalGrade / 100))) / finalGrade);
}

void displayPrompt(float requiredGrade, float leastGrade)
{
    // TODO: Additional prompts for other instances.
    srand(time(0));
    int prompt{ rand() % 5 + 1 };

    if (requiredGrade > 100)
    {
        if (prompt == 1)
        {
            std::cout << "On the bright side, grades don’t really matter anyway.\n";
        }
        else if (prompt == 2)
        {
            std::cout << "Better luck next time!\n";
        }
        else if (prompt == 3)
        {
            std::cout << "Try aiming a little lower.\n";
        }
        else if (prompt == 4)
        {
            std::cout << "Is that even possible to get?\n";
        }
        else if (prompt == 5)
        {
            std::cout << "Maybe there’s extra credit?\n";
        }
        else
        {
            return;
        }
    }
    return;
}