#include<bangtal.h>
#include<stdio.h>

SceneID scene1;
ObjectID startButton, endButton, playButton, santa;
int santaX = 0, santaY = 500;
TimerID timer1;

void endGame(bool success) {
	if (success) {
		showMessage("선물 배달 성공~~~");
	}
	else {
		showMessage("헉, 선물 배달 실패!!!");
	}

	hideObject(playButton);

	setObjectImage(startButton, "restart.png");

	showObject(startButton);
	showObject(endButton);

	santaX = 0;
	locateObject(santa, scene1, santaX, santaY);

	stopTimer(timer1);

}

void startGame() {
	hideObject(startButton);
	hideObject(endButton);

	showObject(playButton);

	setTimer(timer1, 10.0f);

	startTimer(timer1);
}

ObjectID createObject(const char* name, const char* image, SceneID scene, int x, int y, bool shown) {
	
	ObjectID object = createObject(name, image);
	locateObject(object, scene, x, y);

	if (shown) {
		showObject(object);
	}
	return object;
}
 
void mouseCallback(ObjectID object, int x, int y, MouseAction action) {

	if (object == endButton) {
		endGame();
	}
	else if (object == startButton) {
		startGame();
	}
	else if (object == playButton) {
		santaX = santaX + 30;
		locateObject(santa, scene1, santaX, santaY);

		if (santaX > 1280) {
			endGame(true);
		}
	}
}

void timerCallback(TimerID timer) {
	if (timer == timer1) {
		endGame(false);
	}
}

int main() {

	setMouseCallback(mouseCallback);

}

 ObjectID createObject(const char* name, const char* image, SceneID scene, int x, int y, bool shown)
{
	return ObjectID();
}
