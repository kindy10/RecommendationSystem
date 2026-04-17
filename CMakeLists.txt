cmake_minimum_required(VERSION 3.30)
project(Recommendation_System)

set(CMAKE_CXX_STANDARD 23)

add_executable(Recommendation_System src/main.cpp
        include/DataLoader.h
        include/Recommender.h
)
