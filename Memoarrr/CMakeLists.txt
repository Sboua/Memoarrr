cmake_minimum_required(VERSION 3.12)
project(Memoarrr)

set(CMAKE_CXX_STANDARD 11)

add_executable(Memoarrr main.cpp board.cpp card.cpp cardDeck.cpp reward.cpp rewardDeck.cpp player.cpp game.cpp board.h card.h reward.h cardDeck.h deck.h player.h game.h rewardDeck.h rules.h rules.cpp expertRules.h expertRules.cpp expertBoard.h expertBoard.cpp config.h)