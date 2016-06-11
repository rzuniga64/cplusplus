#include "PongGame.h"
#include <cmath>
#include <climits>

static double PI = acos(-1.0);

/* Game functions */

PongGame::PongGame(int maxx, int maxy) {
    /* make paddles */
    paddleHalfHeight = PADDLE_HEIGHT / 2; 
    paddleHalfWidth = 5;
    leftPaddle = new PongPaddle(maxy, paddleHalfWidth, paddleHalfWidth, paddleHalfHeight);
    rightPaddle = new PongPaddle(maxy, maxx-paddleHalfWidth, paddleHalfWidth, paddleHalfHeight);
    /* make ball */
    int ballRadius = 10;
    ball = new PongBall(0, maxx, maxy, 2 * paddleHalfWidth, ballRadius);

    /* data members for keeping score */
    leftScore = 0;
    rightScore = 0;
    scoreY = (int)(0.9 * maxy);
    leftScoreX = (int)(maxx * 0.33);
    rightScoreX = (int)(maxx * 0.67);
    volleyCount = 0;
    /* data members for drawing net */
    netSegHeight = maxy / 10;
    netSegWidth = fmin(maxx / 100, 2);
    netX = (int)(maxx * 0.5);
    windowWidth = maxx;
    windowHeight = maxy;

    /* make players */
	//leftPlayer = new HumanPlayer(this, leftPaddle, 'w', 's');
	//rightPlayer = new HumanPlayer(this, rightPaddle, 'p', 'l');
	leftPlayer = new ZunigaComputerPlayer(this, leftPaddle);
	rightPlayer = new ZunigaComputerPlayer(this, rightPaddle);
}


void PongGame::handleKeyDown(char key) {
    if (key == 'r')
        ball->reset();
    else if (key == ' ') {
        ball->release();
    }
    else {
        leftPlayer->handleKeyDown(key);
        rightPlayer->handleKeyDown(key);
    }
}

void PongGame::handleKeyUp(char key) {
    leftPlayer->handleKeyUp(key);
    rightPlayer->handleKeyUp(key);
}

void PongGame::update() {
	int elapsedMS = updateTimer.deltaT();
	//cout << elapsedMS << endl;
	updateTimer.start();

    leftPaddle->update(elapsedMS-lastLeftThink);
	rightPaddle->update(elapsedMS-lastRightThink);
    if (ball->update(leftPaddle, rightPaddle, elapsedMS))
        volleyCount++;
    if (volleyCount >= NUM_VOLLEYS_INCREASE) {
        volleyCount = 0;
        ball->increaseSpeed();
    }
    if (ball->outOnRight()) {
        leftScore += 1;
        ball->reset();
    }
    else if (ball->outOnLeft()) {
        rightScore += 1;
        ball->reset();
    }
	leftTimer.start();
    leftPlayer->chooseMove();
	lastLeftThink = leftTimer.deltaT();

	rightTimer.start();
    rightPlayer->chooseMove();
	lastRightThink = rightTimer.deltaT();
}

void PongGame::draw() {
    drawNet();
    leftPaddle->draw();
    rightPaddle->draw();
    ball->draw();
    drawScore(leftScoreX, scoreY, leftScore);
    drawScore(rightScoreX, scoreY, rightScore);
}

void PongGame::drawNet() {
    int y = 0;
    setColor(WHITE);
    for (int i=0; i<=10; i++) {
        drawFilledBox(netX-netSegWidth/2, (int)(y - netSegHeight * 0.4), 
                      netX + netSegWidth/2, (int)(y + netSegHeight * 0.4));
        y += netSegHeight;
    }
}

void PongGame::drawScore(int x, int y, int score) {
    int numDigits = (score > 0 ? (int)log10((double)score)+1 : 1);
    int digitWidth = 16;
    int digitSpace = digitWidth + 16;
    int xpos = (int)(x + (numDigits*0.5)*digitSpace - digitSpace*0.5);
    for (int i=0; i<numDigits; i++)
    {
        drawEightSegmentDigit(score%10, xpos, y, digitWidth, digitWidth*2);
        xpos -= digitSpace;
        score = score / 10;
    }
}

void PongGame::getWindowDimensions(int & windowWidth, int & windowHeight) {
    windowWidth = this->windowWidth;
    windowHeight = this->windowHeight;
}

void PongGame::getBallXRange(int & ballMinX, int & ballMaxX) {
	ball->getXRange(ballMinX, ballMaxX);
}

void PongGame::getBallYRange(int & ballMinY, int & ballMaxY) {
	ball->getYRange(ballMinY, ballMaxY);
}

void PongGame::getPaddleYRange(int & paddleMinY, int & paddleMaxY) {
    paddleMinY = paddleHalfHeight;
    paddleMaxY = windowHeight - paddleHalfHeight;
}

void PongGame::getPaddleDimensions(int & paddleWidth, int & paddleHeight) {
    paddleWidth = paddleHalfWidth * 2;
    paddleHeight = paddleHalfHeight * 2;
}


int PongGame::getPaddleY(PongPaddle * paddle) {
    return (int)(paddle->ypos);
}

int PongGame::getOtherPaddleY(PongPaddle * paddle) {
    if (paddle == leftPaddle)
        return getPaddleY(rightPaddle);
    else
        return getPaddleY(leftPaddle);
}

bool PongGame::ballHeadingToward(PongPaddle * paddle) {
	double xvel, yvel;
	ball->getVelocity(xvel, yvel);
    return (ball->isReleased() && 
            ((paddle == leftPaddle && (xvel < 0)) ||
             (paddle == rightPaddle && (xvel > 0))));
}

int PongGame::ballXDistToPaddle(PongPaddle * paddle) {
    int dist = -1;
    if (ballHeadingToward(paddle))
        dist = ball->xDistToPaddle(paddle);
    return dist;
}

int PongGame::getBallY() {
	return ball->getY();
}

void PongGame::getBallPosition(int & xpos, int & ypos) {
	ball->getPosition(xpos, ypos);
}

void PongGame::getBallVelocity(double & xVel, double & yVel) {
	ball->getVelocity(xVel, yVel);
}

/* Paddle functions */

PongPaddle::PongPaddle(int maxy, int xpos, int halfWidth, int halfHeight) {
    this->maxy = maxy;
    this->xpos = xpos;
    this->ypos = maxy/2;
    this->halfWidth = halfWidth;
    this->halfHeight = halfHeight;
    this->segHeight = halfHeight / 4;
    this->speed = PADDLE_SPEED;
    this->command = 0;
}

void PongPaddle::draw() {
    setColor(WHITE);
    drawFilledBox(xpos-halfWidth, (int)(ypos-halfHeight), xpos+halfWidth, (int)(ypos+halfHeight));
}

void PongPaddle::moveUp() {
	command = 1;
}

void PongPaddle::moveDown() {
	command = -1;
}

void PongPaddle::update(int elapsedMS) {
	if (command < 0) {
        int dist = (int)(ypos - halfHeight);
        if (dist > 0)
            ypos-=fmin((double)dist, speed*elapsedMS);
	}
	else if (command > 0) {
		int dist = (int)(maxy-halfHeight - ypos);
        if (dist > 0)
            ypos+=fmin((double)dist, speed*elapsedMS);
	}
	command = 0;
}

int PongPaddle::getX() const {
	return static_cast<int>(xpos);
}

int PongPaddle::getY() const {
    return static_cast<int>(ypos);
}

void PongPaddle::segmentIntersect(int y, int radius, 
                                  int & segmentsFromMid, int & directionFromMid) {
    int dist = (int)fabs(y-ypos);
    if (dist < halfHeight+radius)
        segmentsFromMid = dist / segHeight;
    else
        segmentsFromMid = -1;
    if (y < ypos)
        directionFromMid = -1;
    else
        directionFromMid = 1;
}

/* Ball functions */

PongBall::PongBall(int minx, int maxx, int maxy, int paddleWidth, int radius) {
    this->paddleWidth = paddleWidth;
    this->minx = minx + paddleWidth / 2;
    this->maxx = maxx - paddleWidth / 2;
	this->miny = radius;
    this->maxy = maxy - radius;
    this->radius = radius;
    this->speed = -1;
    reset();
}

void PongBall::reset() {
    xpos = (minx+maxx) / 2;
    ypos = (miny+maxy) / 2;
    if (speed < 0)
        speed = INITIAL_BALL_SPEED;
    else
        speed = fmax(speed/(1+BALL_SPEED_INCREASE), INITIAL_BALL_SPEED);
    released = false;
    printedOut = false;
	wallBounced = paddleBounced = false;
}

void PongBall::increaseSpeed() {
    double angle = atan2(yVelocity, xVelocity);
    speed *= (1+BALL_SPEED_INCREASE);
    if (VERBOSE)
        cout << "increasing speed to: " << speed << endl;
    xVelocity = speed * cos(angle);
    yVelocity = speed * sin(angle);
}

void PongBall::release() {
    if (!released) {
		int maxDegrees = static_cast<int>(24.0 / speed);
        double angle = ((rand()%maxDegrees-maxDegrees/2) + 
						(rand()%2==0 ? 180 : 0))*PI / 180.0;
        xVelocity = speed * cos(angle);
        yVelocity = speed * sin(angle);
    }
    released = true;
};

bool PongBall::outOnLeft() {
    return (xpos < minx-paddleWidth/2);
}

bool PongBall::outOnRight() {
    return (xpos > maxx+paddleWidth/2);
}

void PongBall::draw() {
    setColor(WHITE);
    drawFilledCircle((int)xpos, (int)ypos, radius);
}

int clip(int val, int min, int max) {
	return (val < min ? min : (val > max ? max : val));
}

bool PongBall::bounce(PongPaddle * leftPaddle, 
					  PongPaddle * rightPaddle, int & elapsedMS,
					  bool & wallBounce, bool & paddleBounce, 
					  int & paddleSegs, int & paddleDir) {
	bool top, bottom, left, right;
	top = bottom = left = right = false;
	wallBounce = paddleBounce = false;

	double xnext = xpos + xVelocity * elapsedMS;
	double ynext = ypos + yVelocity * elapsedMS;
	double xDist = maxx, yDist = maxy;

	// figure out if we'd bounce on the next time step
	if ((bottom = ynext <= miny) || (top = ynext >= maxy) || 
		(left = (xnext <= minx+radius+paddleWidth/2 && xVelocity < 0)) || 
		(right = (xnext >= maxx-radius-paddleWidth/2 && xVelocity > 0))) {
		if (left || right) {
			paddleBounce = true;
			if (left)
				leftPaddle->segmentIntersect((int)ynext, radius, 
											 paddleSegs, paddleDir);
			else
				rightPaddle->segmentIntersect((int)ynext, radius,
											  paddleSegs, paddleDir);
            if (VERBOSE && !printedOut) {
                if (xpos <= minx+radius+paddleWidth && xVelocity < 0) {
                    if (paddleSegs < 0)
                        cout << "OUT!!!" << endl;
                    cout << "out on left at height: " << ypos << endl;
                    printedOut = true;
                }
                else if (xpos >= maxx-radius-paddleWidth && xVelocity > 0) {
                    if (paddleSegs < 0)
                        cout << "OUT!!!" << endl;
                    cout << "out on right at height: " << xpos << endl;
                    printedOut = true;
                }
            }
			if (paddleSegs < 0) {
				paddleBounce = false;
			}
			if (paddleBounce)
				xDist = (left ? xpos - (minx+radius+paddleWidth/2) :
						 maxx-radius-paddleWidth/2 - xpos);
		}
		if (top || bottom) {
			wallBounce = true;
			yDist = (bottom ? ypos - miny : maxy - ypos);
		}
		// limit elapsed time to keep us from going out of bounds
		if (xDist < yDist && paddleBounce)
			elapsedMS = clip(static_cast<int>(xDist/xVelocity), 0, elapsedMS);
		else if (wallBounce)
			elapsedMS = clip(static_cast<int>(yDist/yVelocity), 0, elapsedMS);
	}
	return paddleBounce || wallBounce;
}

bool PongBall::update(PongPaddle * left, PongPaddle * right, int elapsedMS) {
	bool volley = false;
    if (released) {
		bool bounce, wallBounce, paddleBounce;
		int paddleSegs, paddleDir;
		bounce = this->bounce(left, right, elapsedMS, wallBounce,
							  paddleBounce, paddleSegs, paddleDir);
		// update ball position
		xpos = xpos+xVelocity * elapsedMS, minx, maxx;
		ypos = ypos+yVelocity * elapsedMS, miny, maxy;
		// now update velocities for next time
		if (wallBounce && !wallBounced) {
			wallBounced = true;
			yVelocity *= -1;
		}
		if (paddleBounce && !paddleBounced) {
			paddleBounced = true;
			volley = true;
			double angle = (paddleSegs * paddleDir * 20 + 
							(rand()%5-2)) * PI / 180;
			xVelocity = speed * cos(angle) * (xVelocity < 0 ? 1 : -1);
			yVelocity = speed * sin(angle);
			if (VERBOSE) {
				cout << "HIT!!!" << endl;
				cout << "new velocity: " << xVelocity << " " << yVelocity << endl;
				printedOut = false;
			}
		}
		// if we're not out of range, reset bounced bools
		if (!wallBounce) wallBounced = false;
		if (!paddleBounce) paddleBounced = false;
	}
	return volley;
}
#if 0
bool PongBall::update(PongPaddle * left, PongPaddle * right, int elapsedMS) {
    bool volley = false;

    if (released) {
		int nextY = ypos + yVelocity * elapsedMS;
		// if next position would put us over edge, pretend fewer ms passed
		if (nextY < radius || nextY > maxy-radius) {
			//cout << "BOUNCE at " << xpos << ", " << ypos << endl;
			double distToEdge = (nextY < radius ? ypos-radius : (maxy-radius)-ypos);
			elapsedMS = static_cast<int>(distToEdge/abs(yVelocity));
			//cout << "allowed ms: " << elapsedMS << endl;
			xpos += xVelocity * elapsedMS;
			ypos += yVelocity * elapsedMS;
			//cout << "udpated pos: " << xpos << ", " << ypos << endl;
			// update velocity for next time;
			yVelocity = -yVelocity;
		}
		else {
            int paddleSegs = -1, paddleDir;
            if (xpos < minx+radius+paddleWidth && xVelocity < 0)
                left->segmentIntersect((int)ypos, radius, paddleSegs, paddleDir);
            else if (xpos > maxx-radius-paddleWidth && xVelocity > 0)
                right->segmentIntersect((int)ypos, radius, paddleSegs, paddleDir);
            if (VERBOSE && !printedOut) {
                if (xpos <= minx+radius+paddleWidth && xVelocity < 0) {
                    if (paddleSegs < 0)
                        cout << "OUT!!!" << endl;
                    cout << "out on left at height: " << ypos << endl;
                    printedOut = true;
                }
                else if (xpos >= maxx-radius-paddleWidth && xVelocity > 0) {
                    if (paddleSegs < 0)
                        cout << "OUT!!!" << endl;
                    cout << "out on right at height: " << ypos << endl;
                    printedOut = true;
                }
            }
            if (paddleSegs >= 0) {
				if (VERBOSE)
					cout << "HIT!!!" << endl;
                volley = true;
                printedOut = false;
                double angle = (paddleSegs * paddleDir * 20 + (rand()%5-2)) * PI / 180;
                xVelocity = speed * cos(angle) * (xVelocity < 0 ? 1 : -1);
                yVelocity = speed * sin(angle);
            }
			xpos += xVelocity * elapsedMS;
	        ypos += yVelocity * elapsedMS;
        }
    }
    return volley;
}
#endif

void PongBall::getXRange(int & minx, int & maxx) const {
	minx = this->minx;
	maxx = this->maxx;
}

void PongBall::getYRange(int & miny, int & maxy) const {
	miny = this->miny;;
	maxy = this->maxy;
}

int PongBall::getY() const {
	return ypos;
}

void PongBall::getPosition(int & xpos, int & ypos) const {
	xpos = this->xpos;
	ypos = this->ypos;
}

void PongBall::getVelocity(double & xvel, double & yvel) const {
	xvel = this->xVelocity;
	yvel = this->yVelocity;
}

int PongBall::xDistToPaddle(PongPaddle * paddle) const {
	return static_cast<int>(abs(xpos - paddle->getX()) - 
							radius - paddleWidth / 2);
}
