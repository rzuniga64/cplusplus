#include "ZunigaComputerPlayer.h"
#include "PongGame.h"


ZunigaComputerPlayer::ZunigaComputerPlayer(PongGame * game, PongPaddle * paddle)
: PongPlayer(game, paddle) {}

void ZunigaComputerPlayer::chooseMove() {

	if (paddle->getY() < game->getBallY())
		paddle->moveUp();
	else if (paddle->getY() > game->getBallY())
		paddle->moveDown();
}

