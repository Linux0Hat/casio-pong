#include <gint/display.h>
#include <gint/keyboard.h>
#include <math.h>

int main(void) {
	float pos_j1 = 87;
	float pos_j2 = 87;
	int score_j1 = 0;
	int score_j2 = 0;
	float ball_x = 300;
	float ball_y = 100;
	int ball_dx = 0;
	int ball_dy = 0;
	float speed = 2.2;
	draw(&pos_j1, &pos_j2, &score_j1, &score_j2, &ball_x, &ball_y, &speed);
    getkey();
	while (true) {
		int t = 0;
		pollevent();

		if (keydown(KEY_XOT)&&pos_j1>0) {
			pos_j1-=speed;
		} else if (keydown(KEY_FRAC)&&pos_j1<174) {
			pos_j1+=speed;
		} 
		if (keydown(KEY_TAN)&&pos_j2>0) {
			pos_j2-=speed;
		} else if (keydown(KEY_ARROW)&&pos_j2<174) {
			pos_j2+=speed;
		}

		if (keydown(KEY_PLUS)) {
			speed+=0.1;
		} else if (keydown(KEY_MINUS) && speed > 0) {
			speed-=0.1;
		}

		if (ball_dx==1) {
			ball_x+=speed;
		} else {
			ball_x-=speed;
		}
		if (ball_dy==1) {
			ball_y+=speed;
		} else {
			ball_y-=speed;
		}

		if (ball_y<0) {
	 		ball_dy = 1;
		} else if (ball_y>214) {
	 		ball_dy = 0;
		} else if (16<ball_x && ball_x<20 && pos_j1-10<ball_y && ball_y<pos_j1+50 && ball_dx == 0)  {
			ball_dx = 1;
		} else if (366<ball_x && ball_x<370 && pos_j2-10<ball_y && ball_y<pos_j2+50 && ball_dx == 1)  {
			ball_dx = 0;
		}

		if (ball_x<0) {
			ball_x = 193;
	 		ball_y = 100;
			score_j2++;
		} else if (ball_x>406) {
			ball_x = 193;
	 		ball_y = 100;
			score_j1++;
		}

		if (keydown(KEY_EXIT)) {
			return 0;
		}

		clearevents();
		draw(&pos_j1, &pos_j2, &score_j1, &score_j2, &ball_x, &ball_y);
		//for (float j = 0; j<400; j++) {}
	}
	return 0;
}

void draw(float *pos_j1, float *pos_j2, int *score_j1, int *score_j2, float *ball_x, float *ball_y) {
	dclear(C_BLACK);
	drect(10, *pos_j1, 20, *pos_j1+50, C_WHITE);
	drect(376, *pos_j2, 386, *pos_j2+50, C_WHITE);
	drect(*ball_x, *ball_y, *ball_x+10, *ball_y+10, C_WHITE);
	dprint(182,4, C_WHITE, "%d", *score_j1);
	dprint(208,4, C_WHITE, "%d", *score_j2);
    for (int i; i<5; i++) {
		drect(195, i*2*23+7, 200, i*2*23+23+7, C_WHITE);
	}
	dupdate();
}