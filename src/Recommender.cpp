//
// Created by HP on 4/17/2026.
//
#include "Recommender.h"
#include <cmath>
#include <algorithm>
#include <ranges>
#include <iostream>

double Recommender::calculateSimilarity(const std::map<std::string,double>&userA,
    const std::map<std::string,double>&userB) {
    double dotProduct = 0.0;
    double normA = 0.0;
    double normB = 0.0;

    //Calculate dot product for common movies
    for (auto const& [movie,ratingA] : userA) {
        if (userB.contains(movie)) {
            dotProduct += ratingA*userB.at(movie);
        }
        normA += std::pow(ratingA,2);
    }
    for (auto const& [_,ratingB] : userB) {
        normB += std::pow(ratingB,2);
    }
    return  (normA == 0 || normB == 0 ) ? 0.0 : (dotProduct / (std::sqrt(normA*normB)));
}

std::vector <std::pair<std::string,double>> Recommender::getRecommendations(
    const std::string& targetUser,const RatingMatrix& allRatings) {

    if (!allRatings.contains(targetUser))  return{};
    const auto& targetRating = allRatings.at(targetUser);

    //find the best neighbor
    std::string bestMatch;
    double highestSimilarity = -1.0;

    for (auto const& [name,ratings] : allRatings) {
        if (name == targetUser) continue;

        double similarity = calculateSimilarity(targetRating,ratings);
        if (similarity > highestSimilarity) {
            highestSimilarity = similarity;
            bestMatch = name;
        }
    }
    if (bestMatch.empty() || highestSimilarity <= 0.0) return {};

    //2 pipeline of recommendation:
    //filtering twin movies
    auto recommendationsView = allRatings.at(bestMatch)
        | std::views::filter([&](const auto&pair) {
            const auto& [movie,rating] = pair;
            return !targetRating.contains(movie)&& rating > 3.0;
        });
    //3 Convert to a vector
    std::vector<std::pair<std::string,double>> suggestions;(
        recommendationsView.begin(),recommendationsView.end());
    std::ranges::sort(suggestions,std::ranges::greater{},
        [](const auto& p) {return p.second;});

    std::cout << "[DEBUG] Best match for " << targetUser << " is " << bestMatch
          << " with similarity: " << highestSimilarity << std::endl;

    return suggestions;

    /*3. How does it work?
    Similarity: If Alice and Bob both like "Inception,"
    the dotProduct increases. If they have opposite tastes, the score will be close to 0.

    Recommendation: We identify that Bob is Alice's
    "movie twin." We look at which movies Bob loved (e.g., "Dunkirk") that Alice hasn't seen yet, and suggest them to her.
*/

}