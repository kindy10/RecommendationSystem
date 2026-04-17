#include <iostream>
#include <filesystem>
#include <iomanip>
#include "DataLoader.h"
#include "Recommender.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    try {
        std::cout << "========================================" << std::endl;
        std::cout << "     RECOMMENDATION SYSTEM        " << std::endl;
        std::cout << "========================================\n" << std::endl;

        RatingMatrix ratings = DataLoader::loadSampleData();
        std::string targetUser ="Kindy";

        std::cout<<"[+] Data loaded for "<<ratings.size()<<" users."<< std::endl;
        std::cout<<"[+] Analyzing tastes for: "<<targetUser<<"..."<<std::endl;

        auto recommendations = Recommender::getRecommendations(targetUser, ratings);

        std::cout<<"\n--- TOP RECOMMENDATIONS ---" << std::endl;
        if (recommendations.empty()) {
            std::cout << "No recommendations found." << std::endl;
        }else {
            std::cout<<std::left<<std::setw(20)<<"MOVIE TITLE"<<" | " << "SCORE" << std::endl;
            std::cout << "----------------------------------------" << std::endl;

            for (const auto& [movie,score] : recommendations) {
                std::cout<<std::left <<std::setw(20)<<movie
                    <<" | "<<std::fixed<<std::setprecision(1)<<score<<" /5.0"<<std::endl;
            }
        }

    }catch (std::exception& e) {
        std::cout<<"Fatal Error: "<<e.what()<<std::endl;
        return 1;
    }

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.