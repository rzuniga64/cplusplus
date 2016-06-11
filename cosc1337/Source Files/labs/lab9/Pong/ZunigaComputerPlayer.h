#ifndef ZUNIGA_COMPUTER_PLAYER_H
#define ZUNIGA_COMPUTER_PLAYER_H

#include "PongPlayer.h"

class ZunigaComputerPlayer : public PongPlayer
{
public:
	ZunigaComputerPlayer(PongGame * game, PongPaddle * paddle);
	void chooseMove();
};

#endif /*ZUNIGA_COMPUTER_PLAYER_H*/

