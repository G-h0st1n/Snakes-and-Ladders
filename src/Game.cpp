// Game.cpp
#include "Game.h"
#include <iostream>

Game::Game() : board(), player1(1), player2(2), dice(), turn(1), isGameOver(false) {}

void Game::start() {
    // Print instruction menu
    std::cout << "Press C to continue next turn, or E to end the game:\n";
}

void Game::takeTurn() {
    // Implementation of turn execution
    //cout<<"Result: "<<mydice->roll()<<"\n";
    Dice * mydice = new Dice(); //Alternative declaration
    mydice->roll();
    int result = mydice->result;

    //player 1
    cout << turn << " " << player1.getPlayerNumber() << " " << player1.getPosition() << " " << result << " ";
    player1.move(result);
    cout << board.getTileType(player1.getPosition()) << " ";
    if (board.getTileType(player1.getPosition()) == 'L'){
        player1.move(4);
        cout << player1.getPosition(); 
    } else if(board.getTileType(player1.getPosition()) == 'S'){
        player1.move(-7);
        cout << player1.getPosition();
    }else {
        cout << player1.getPosition();
    }
    cout << endl;

    //player 2
    cout << turn << " " << player2.getPlayerNumber() << " " << player2.getPosition() << " " << result << " ";
    player2.move(result);
    cout << board.getTileType(player2.getPosition()) << " ";
    if (board.getTileType(player2.getPosition()) == 'L'){
        player2.move(4);
        cout << player2.getPosition(); 
    } else if(board.getTileType(player2.getPosition()) == 'S'){
        player2.move(-7);
        cout << player2.getPosition();
    }else {
        cout << player2.getPosition();
    }
    cout << endl;
}

void Game::endTurn(){
    turn = turn + 1;
}
void Game::endGame() {
    std::cout << "-- GAME OVER --\n";
}