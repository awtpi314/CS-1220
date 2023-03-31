#include "Plant.h"
#include "Flower.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void PrintVector(vector<Plant*> v) {
    for (Plant* plant : v) {
        plant->PrintInfo();
    }
}

// TODO: Define a PrintVector function that prints an vector of plant (or flower) object pointers

int main() {
    // TODO: Declare a vector called myGarden that can hold object of type plant pointer
    vector<Plant*> myGarden;

    // TODO: Declare variables - plantName, plantCost, flowerName, flowerCost,
    //       colorOfFlowers, isAnnual
    string input;
    string plantName;
    int plantCost;
    string flowerName;
    int flowerCost;
    string colorOfFlowers;
    string isAnnual;

    cin >> input;

    while (input != "-1") {
        if (input != "flower") {
            cin >> plantName;
            cin >> plantCost;

            Plant* p = new Plant();
            p->SetPlantName(plantName);
            p->SetPlantCost(plantCost);
            myGarden.push_back(p);
        }
        else {
            //string inputLine;
            //std::getline(cin, inputLine);
            //int location = inputLine.find(" ", 2);
            //flowerName = inputLine.substr(1, location - 1);
            //inputLine = inputLine.substr(location + 1);
            //location = inputLine.find(" ");
            //flowerCost = std::stoi(inputLine.substr(0, location));
            //inputLine = inputLine.substr(location + 1);
            //location = inputLine.find(" ");
            //isAnnual = inputLine.substr(0, location) == "true";
            //inputLine = inputLine.substr(location + 1);
            //location = inputLine.find(" ");
            //colorOfFlowers = inputLine.substr(0, location);
            cin >> flowerName;
            cin >> flowerCost;
            cin >> isAnnual;
            cin >> colorOfFlowers;

            Flower* f = new Flower();
            f->SetPlantName(flowerName);
            f->SetPlantCost(flowerCost);
            f->SetColorOfFlowers(colorOfFlowers);
            f->SetPlantType(isAnnual == "true");
            myGarden.push_back(f);
        }
        // TODO: Check if input is a plant or flower
        //       Store as a plant object or flower object
        //       Add to the vector myGarden
        cin >> input;
    }

    // TODO: Call the method PrintVector to print myGarden
    PrintVector(myGarden);

    for (size_t i = 0; i < myGarden.size(); ++i) {
        delete myGarden.at(i);
    }

    return 0;
}