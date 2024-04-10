#include <gint/display.h>
#include <gint/keyboard.h>
#include <math.h>

int main(void) {
	float pos_j1 = 26;
	float pos_j2 = 26;
	int score_j1 = 0;
	int score_j2 = 0;
	float ball_x = 90;
	float ball_y = 30;
	int ball_dx = 0;
	int ball_dy = 0;
	float speed = 0.5;
	draw(&pos_j1, &pos_j2, &score_j1, &score_j2, &ball_x, &ball_y, &speed);
    getkey();
	while (true) {
		pollevent();

		if (keydown(KEY_XOT)&&pos_j1>0) {
			pos_j1-=speed;
		}
		if (keydown(KEY_FRAC)&&pos_j1<52) {
			pos_j1+=speed;
		}
		if (keydown(KEY_TAN)&&pos_j2>0) {
			pos_j2-=speed;
		}
		if (keydown(KEY_ARROW)&&pos_j2<52) {
			pos_j2+=speed;
		}

//		if (keydown(KEY_PLUS)) {
//			speed+=0.1;
//		}
//		if (keydown(KEY_MINUS)) {
//			speed-=0.1;
//		}

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
		} else if (ball_y>64) {
	 		ball_dy = 0;
		} else if (5<ball_x && ball_x<6 && pos_j1-3<ball_y && ball_y<pos_j1+15 && ball_dx == 0)  {
			ball_dx = 1;
		} else if (110<ball_x && ball_x<111 && pos_j2-3<ball_y && ball_y<pos_j2+15 && ball_dx == 1)  {
			ball_dx = 0;
		}

		if (ball_x<0) {
			ball_x = 58;
	 		ball_y = 30;
			score_j2++;
		} 
		if (ball_x>121) {
			ball_x = 58;
	 		ball_y = 30;
			score_j1++;
		}

		if (keydown(KEY_EXIT)) {
			return 0;
		}

		clearevents();
		draw(&pos_j1, &pos_j2, &score_j1, &score_j2, &ball_x, &ball_y);
		for (float j = 0; j<1000; j++) {}
	}
	return 0;
}

void draw(float *pos_j1, float *pos_j2, int *score_j1, int *score_j2, float *ball_x, float *ball_y) {
	dclear(C_BLACK);
	drect(3, *pos_j1, 6, *pos_j1+15, C_WHITE);
	drect(113, *pos_j2, 116, *pos_j2+15, C_WHITE);
	drect(*ball_x, *ball_y, *ball_x+3, *ball_y+3, C_WHITE);
	dprint(55,1, C_WHITE, "%d", *score_j1);
	dprint(62,1, C_WHITE, "%d", *score_j2);
    for (int i; i<5; i++) {
		drect(59, i*2*7+2, 60, i*2*7+7+2, C_WHITE);
	}
	dupdate();
}