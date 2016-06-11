#ifndef PONG_PLAYER_H
#define PONG_PLAYER_H

#include <cmath>

class PongGame;
class PongPaddle;

class PongPlayer {
public:
	PongPlayer(PongGame * game, PongPaddle * paddle);
	virtual void handleKeyDown(char) {};
	virtual void handleKeyUp(char) {};
	virtual void chooseMove() = 0;
protected:
	PongGame * game;
	PongPaddle * paddle;
};

class HumanPlayer : public PongPlayer {
public:
    HumanPlayer(PongGame * game, PongPaddle * paddle, char upKey, char downKey);
    void handleKeyDown(char key);
    void handleKeyUp(char key);
    void chooseMove();
private:
    char upKey;
    char downKey;
    char currentKey;
    int keyTimer;
};

#endif
