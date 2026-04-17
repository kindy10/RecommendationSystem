//
// Created by HP on 4/17/2026.
//

#ifndef RECOMMENDER_H
#define RECOMMENDER_H

#include <vector>
#include  "DataLoader.h"

class Recommender {
public:
    //Calculate the similarity score between two users
    static double calculateSimilarity(const std::map<std::string,double>&userA,
        const std::map<std::string,double>&userB);

    //find the best recommendations for a user
    static std::vector<std::pair<std::string,double>> getRecommendations(
        const std::string& targetUser,const RatingMatrix& allRatings);
};

#endif //RECOMMENDER_H
