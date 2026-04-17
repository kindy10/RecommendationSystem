//
// Created by HP on 4/17/2026.
//
#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

RatingMatrix DataLoader::loadSampleData() {
    RatingMatrix ratings;

    //Simulation de donnes : utilisateur -> {Film:Note}
    ratings["Kindy"] ={
        {"Inception",5.0},
        {"Interstellar",4.5},
        {"The Dark knight",1.0}
    };
    ratings["Marc"] ={
        {"Inception",4.0},
        {"Interstellar",5.0},
        {"The Dark knight",2.0},
        {"Dunkirk",4.5}
    };
    ratings["Amadou"] ={
        {"Inception",1.0},
        {"Interstellar",1.5},
        {"The Dark knight",5.0}
    };
    return ratings;

}

/* Reading data for CSV
RatingMatrix DataLoader::loadFromCSV(const std::string& filename) {
    RatingMatrix ratings;
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + filename);
    }
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string user,movie,ratingStr;

        //On decoupe par la virgule : User Movie , Rating
        if (std::getline(ss,user,',') &&
            std::getline(ss,movie,',') &&
            std::getline(ss,ratingStr,',')) {
            try {
                double r = std::stod(ratingStr);
                ratings[user][movie] = r;
            }catch (...) {
                //En cas de note mal ecrite , on ignore la ligne
                continue;
            }
            }
    }
    file.close();
    return ratings;
}
*/