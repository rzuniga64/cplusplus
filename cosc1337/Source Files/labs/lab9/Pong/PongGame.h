#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <iostream>
#include <ctime>
#include "Graphics.h"
#include "PongPlayer.h"
#include "ZunigaComputerPlayer.h"

using namespace std;

class PongPlayer;
class PongPaddle;
class PongBall;

/* a bunch of constants which should really be members of the appropriate classes,
   but are here so that they are easy to find/change if it is useful. */
   
#define PADDLE_SPEED 0.4 // how fast the paddles can move (pixels per ms)
#define INITIAL_BALL_SPEED 0.5 // how fast the ball goes initially (pixels per ms)
#define BALL_SPEED_INCREASE 0.1 // percent to increase ball speed after set number of volleys
#define NUM_VOLLEYS_INCREASE 5 // after how many volleys to increase the speed
#define PADDLE_HEIGHT 64 // the height of the paddle (taller paddles make the game easier)
#define VERBOSE false // whether the game should print out useful debugging info 

class PongGame {
public:
    PongGame(int xmax, int ymax);
    /* The following four functions are called from main */
    void update();
    void draw();
    void handleKeyDown(char key);
    void handleKeyUp(char key);

    /* The remaining public function are intended to be used by 
        player objects to get information about game so that the
        player can select a paddle action.  */

    /* Returns the current y position of the ball */
    int getBallY();
    /* Receives a paddle and returns the current y position of the paddle */
    int getPaddleY(PongPaddle * paddle);
    /* Receives a paddle and returns the number of pixels that the ball has left to
       travel before it will either hit the paddle or go out of bounds.  If the
       ball is moving toward the other paddle, the function returns -1. */
    int ballXDistToPaddle(PongPaddle * paddle);
    /* Outputs the minimum and maximum values for the x and y dimensions of the
       ball's center (accounts for radius of ball and width of paddle) */
    void getBallXRange(int & ballMinX, int & ballMaxX);
    void getBallYRange(int & ballMinY, int & ballMaxY);
    /* Outputs the minimum and maximum value for the y dimension of the
       paddle's center (accounts for width and height of paddle) */
    void getPaddleYRange(int & paddleMinY, int & paddleMaxY);
    /* Receives a paddle and returns a Boolean that is true if the ball is 
       currently heading toward the paddle and false if it is heading toward 
     the opponent's paddle */
    bool ballHeadingToward(PongPaddle * paddle);
    /* Outputs the x and y positions of the ball */
    void getBallPosition(int & xpos, int & ypos);
    /* Outputs the x and y components of the ball's velocity */
    void getBallVelocity(double & xVel, double & yVel);
    /* Outputs the width and height of the window, in pixels. */
    void getWindowDimensions(int & windowWidth, int & windowHeight);
    /* Receives a paddle and returns the current y position of the opponent's paddle */
    int getOtherPaddleY(PongPaddle * paddle);
    /* Outputs the size of the paddle objects in pixels. */
    void getPaddleDimensions(int & paddleWidth, int & paddleHeight);
private:
    void drawNet();
    void drawScore(int x, int y, int score);
    
    /* Change players to be new base class pointers */
    PongPlayer * leftPlayer;
    PongPlayer * rightPlayer;
    
    PongPaddle * leftPaddle;
    PongPaddle * rightPaddle;
    PongBall * ball;

	// Drawing and animation info.
    int windowWidth;
    int windowHeight;
    int paddleHalfHeight;
    int paddleHalfWidth;
    int paddleSegmentHeight;
    int netSegHeight;
    int netSegWidth;
    int netX;
    
    // Score information
    int leftScore;
    int rightScore;
    int scoreY;
    int volleyCount;
    int leftScoreX;
    int rightScoreX;

	// Timing information
	GraphicsTimer updateTimer;
	GraphicsTimer leftTimer;
	GraphicsTimer rightTimer;
	int lastLeftThink;
	int lastRightThink;
};

class PongPaddle {
	/* Game and Ball are friended so that the Player classes can have a
	   more restricted interface to the Paddle. */
    friend class PongGame;
	friend class PongBall;
public:
    PongPaddle(int maxy, int xpos, int halfWidth, int halfHeight);
    /* The moveUp and moveDown functions are the only functions of the
       PongPaddle class that you should call. */
    void moveUp();
    void moveDown();
	int getY() const;
private:
	void update(int elapsedMS);
	int getX() const;
    void segmentIntersect(int y, int radius, int & segmentsFromMid, int & directionFromMid);
    void draw();
    int maxy;
    int xpos;
    double ypos;
    double speed;
    int incr;
    int halfWidth;
    int halfHeight;
    int segHeight;
    // to enforce that each player can only choose one move per update
	int command;
};

class PongBall {
public:
    PongBall(int minx, int maxx, int maxy, int paddleWidth, int radius);
    void reset();
    void draw();
    // returns true if ball is successfully volleyed 
    bool update(PongPaddle * left, PongPaddle * right, int elapsedMS);
	// get information about the ball's current state
	bool isReleased() const {return released;}
	void getXRange(int & minx, int & maxx) const;
	void getYRange(int & miny, int & maxy) const;
	int getY() const;
	void getPosition(int & xpos, int & ypos) const;
	void getVelocity(double & xvel, double & yvel) const;
	int xDistToPaddle(PongPaddle * paddle) const;
    bool outOnRight();
    bool outOnLeft();

	// ball controls
    void increaseSpeed();
    void release();
	
private:
	bool bounce(PongPaddle * left, PongPaddle * right, int & elapsedMS,
				bool & wallBounce, bool & paddleBounce, 
				int & paddleSegs, int & paddleDir);
    int minx, maxx, miny, maxy;
    double xpos, ypos;
	bool wallBounced, paddleBounced;
    int paddleWidth;
    int radius;
    double speed, xVelocity, yVelocity;
    bool printedOut;
    bool released;
};

#endif
