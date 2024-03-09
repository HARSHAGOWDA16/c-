#include "game.h"
#include <iostream>
#include <cstdlib> // for rand()

Game::Game() : world(nullptr), rows(0), cols(0), playerRow(0), playerCol(0) {}

Game::~Game() {
    
    if (world != nullptr) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                delete world[i][j];
            }
            delete[] world[i];
        }
        delete[] world;
    }
}

void Game::setUpGame(int rows, int cols) {
   
    this->rows = rows;
    this->cols = cols;


    playerRow = rand() % rows;
    playerCol = rand() % cols;

   
    world = new Location**[rows];
    for (int i = 0; i < rows; ++i) {
        world[i] = new Location*[cols];
        for (int j = 0; j < cols; ++j) {
          
            world[i][j] = nullptr;
        }
    }

   
    const int numCrystals = rows * cols / 5; 
    for (int i = 0; i < numCrystals; ++i) {
        int x = rand() % rows;
        int y = rand() % cols;
        if (world[x][y] == nullptr) {
            world[x][y] = new Crystal();
        }
    }
}

void Game::drawGame() {
   
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == playerRow && j == playerCol) {
                std::cout << "P "; 
            } else {
                if (world[i][j] != nullptr) {
                    world[i][j]->draw();
                } else {
                    std::cout << ". "; 
                }
            }
        }
        std::cout << std::endl;
    }
}

void Game::playGame() {
    setUpGame(8, 8);
    char move;

    do {
        drawGame();
        std::cout << "Enter direction to move (W/A/S/D): ";
        std::cin >> move;

        switch (move) {
            case 'W':
            case 'w':
                if (playerRow > 0) {
                    playerRow--;
                }
                break;
            case 'A':
            case 'a':
                if (playerCol > 0) {
                    playerCol--;
                }
                break;
            case 'S':
            case 's':
                if (playerRow < rows - 1) {
                    playerRow++;
                }
                break;
            case 'D':
            case 'd':
                if (playerCol < cols - 1) {
                    playerCol++;
                }
                break;
            default:
                std::cout << "Invalid move! Please enter W/A/S/D." << std::endl;
                break;
        }

        
        if (world[playerRow][playerCol] != nullptr) {
            world[playerRow][playerCol]->visit(p);
        }

      
        std::cout << "Continue exploring? (Y/N): ";
        std::cin >> move;
    } while (move == 'Y' || move == 'y');
}
