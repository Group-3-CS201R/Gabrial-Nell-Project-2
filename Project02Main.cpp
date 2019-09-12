// Name: Gabrial Nell
// Class: CS201 - T/Th @ 5:30-6:45
// Instructor: Michael Essmyer
// Project #: 2
// Email: gjn96p@mail.umkc.edu

#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;
void menuMaker();
int jobChoice();
int numWallsChoice();
int totalAreaHouse(int numWalls);
double totalPaintingCans(int numArea);
double totalCostInterior(double numCans);
double totalCostExtorior(double numCans);
double totalCostInteriorExtorior(double numCans);
double totalCostCalculator(double numCans, int userChoice);
void printCostStats(double area, double numCans, int userChoice, double totalCost);

int main() {
    // variables needed to store return values from other functions
    int userChoice;
    int numWalls;
    int totalArea;
    double totalCost;
    double numCans;
    // sequence of folling is: print menu, get the choice of job, from user get the number of walls from user,
    // calculate the total area, calculate the total cans, calculate the cost of the job, print out the final stats
    menuMaker();
    userChoice = jobChoice();
    numWalls = numWallsChoice();
    totalArea = totalAreaHouse(numWalls);
    numCans = totalPaintingCans(totalArea);
    totalCost = totalCostCalculator(numCans, userChoice);
    printCostStats(totalArea, numCans, userChoice, totalCost);
    return 0;
}

// function that handles printing out a welcome message and the menu of types of paint jobs a user can choose from
// function is void and has no return value.
void menuMaker() {
    cout << "Welcome to paint shop" << endl;
    cout << "We have couple of options that you can choose from:" << endl;
    cout << "1- Paint the interior of a house" << endl;
    cout << "2- Paint the exterior of a house" << endl;
    cout << "3- Paint both interior and exterior of a house" << endl;
    return;
}

// function to get input from user for what type of paint job they wish to have performed. 
// returns an int representing the job choice
int jobChoice() {
    string choice;
    cout << "What option fits you more ?" << endl;
    getline(cin, choice);
    // if user does not enter a valid choice (1, 2, or 3), loop will continue prompting them until they do
    while (choice != "1" && choice != "2" && choice != "3") {
        cout << "Please input a valid number" << endl;
        getline(cin, choice);
    }
    // converts the user input to an integer type(the loop guarantees the string will contain 1, 2, or 3) and returns it
    return stoi(choice);
}

// function that prompts user to enter the number of walls to be painted.
// returns an int representing the number of walls to be painted
int numWallsChoice() {
    int numWalls;
    cout << "Now, how many walls do you want to paint" << endl;
    cin >> numWalls;
    return numWalls;
}

// function that takes in numWalls as parameter, then prompts user for the height and length of each wall, calculates
// area of each wall then adds to toal area.
// retuens in representing total area(of all walls) to be painted.
int totalAreaHouse(int numWalls) {
    // calculates the total area of the house and returns the value to be used elsewhere in the program
    int length;
    int height;
    int totalArea = 0;
    // iterates once for each wall, getting height and length of that wall, and adding to the total area
    for (int i = 0; i <numWalls; i++) {
        cout << "What is the length and height for wall " << i + 1 << " : " << endl;
        cout << "Length = ";
        cin >> length;
        cout << endl << "Height = ";
        cin >> height;
        totalArea += height * length;
    }
    return totalArea;
}

// function that takes area as paramater and calculates the total paint cans needed, with no rounding.
// returns a double representing the number of cans needed to paint the area user wishes to paint.
double totalPaintingCans(int numArea) {
    double numCans;
    numCans = numArea / 400.0;
    return numCans;
}

// function that takes number of cans as parameter and calculates cost for painting an interior.
// returns a double representing the price of painting an interior with number of cans.
double totalCostInterior(double numCans) {
    // ceil is used here to round up, since cans must be a whole number
    double interiorPrice = ceil(numCans) * 100;
    return interiorPrice;
}

// function that takes number of cans as parameter and calculates cost for painting an exterior
// returns a double representing the price of painting an exterior with number of cans.
double totalCostExtorior(double numCans) {
    // ceil is used here to round up, since cans must be a whole number
    double exteriorPrice = ceil(numCans) * 150;
    return exteriorPrice;
}

// function that takes number of cans as parameter and calculates cost for painting interior and exterior walls.
// returns a double representing the price of painting an interior and exterior walls with number of cans.
double totalCostInteriorExtorior(double numCans) {
    // ceil is used here to round up, since cans must be a whole number
    double interiorPrice = ceil(numCans) * 100;
    double exteriorPrice = ceil(numCans) * 150;
    // gives the total cost to paint both the interior and exterior walls
    double totalPrice = interiorPrice + exteriorPrice;
    return totalPrice;
}

// takes the number of cans and the type of job that user wishes to perfrom and uses these to calculate to toal cost
// returns a double representing the total cost of job
double totalCostCalculator(double numCans, int userChoice) {
    double totalCost;
    switch(userChoice) {
        case 1:
            totalCost = totalCostInterior(numCans);
            break;
        case 2:
            totalCost = totalCostExtorior(numCans);
            break;
        case 3:
            totalCost = totalCostInteriorExtorior(numCans);
            break;
    }
    return totalCost;
}

// handles printing out the stats for the cost of a particular job using the information given by the user
void printCostStats(double area, double numCans, int userChoice, double totalCost) {
    cout << "As each can covers 400 feet" << endl;
    cout << "With area = " << area << " square feet, you will need to get " << numCans << endl;
    cout << "So in total we need " << ceil(numCans) << " cans" << endl;
    cout << "Now lets calculate the cost to paint the interior of the house" << endl;
    // since price per can differs for each job, this switch ensures that the proper amount is output for user's choice
    switch (userChoice) {
        case 1:
            cout << "The price of the can is $ 100" << endl;
            break;
        case 2:
            cout << "The price of the can is $ 150" << endl;
            break;
        case 3:
            cout << "The price of the can for interior is $ 100 and the price of the can for exterior is $ 150" << endl;
            break;
    } 
    cout << "The total cost is $ " << totalCost << endl;
}