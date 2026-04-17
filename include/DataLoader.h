//
// Created by HP on 4/17/2026.
//

#ifndef DATALOADER_H
#define DATALOADER_H

#include <map>
#include<string>

using RatingMatrix = std::map<std::string,std::map<std::string,double>>;
class DataLoader {
public:

    static RatingMatrix loadSampleData();
    static RatingMatrix loadFromCSV(const std:: string& filename);
};
#endif //DATALOADER_H
