#include "PongGame.h"
#include "PongPlayer.h"

PongPlayer::PongPlayer(PongGame * game, PongPaddle * paddle){
	this->game = game;
	this->paddle = paddle;
}

HumanPlayer::HumanPlayer(PongGame * game, PongPaddle * paddle, char upKey, char downKey)
: PongPlayer(game, paddle) {
    this->upKey = upKey;
    this->downKey = downKey;
    currentKey = '\0';
}

void HumanPlayer::handleKeyDown(char key) {
    if (key == upKey || key == downKey)
        currentKey = key;
}

void HumanPlayer::handleKeyUp(char key) {
    if (key == currentKey)
        currentKey = '\0';
}

void HumanPlayer::chooseMove() {
    if (currentKey == upKey)
        paddle->moveUp();
    else if (currentKey == downKey)
        paddle->moveDown();
}
