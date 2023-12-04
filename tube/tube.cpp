#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<easyx.h>
#include<mmsystem.h>
#pragma comment( lib, "MSIMG32.LIB")
#pragma comment(lib, "Winmm.lib")
#define screen_width 600//屏幕宽
#define screen_height 600//屏幕高
#define landheight 500//地面的高度
/**
只实现3个部分，管道和鸟的移动，管道和鸟的贴图，碰撞的检测。

**/  
IMAGE endtitle;//菜
IMAGE Title;//标题
IMAGE bird[3];//实现开始界面的动态鸟，来个老大
IMAGE bk,bk1;//代表背景
IMAGE byd1;//三种鸟对应三种状态，实际上游戏中只需要第一种状态就可以，三种状态是为了呈现出
//开场时鸟在飞的感觉
/**
* 我们还需要一个getcontrol函数来检测是否有输入，如果有输入才能跳出init的循环。
**/
IMAGE tube1_up, tube1_down, tube2_up, tube2_down;//四个管道
IMAGE button;//开始按钮，实际只需要检测鼠标有没有输入或者键盘有没有输入；
IMAGE land;//地面
//检测键盘有没有输入
const int start_x = 50;//鸟的横坐标，不能变
int start_y = landheight;//开始的高度，可以变
const int jump = 100;//跳起来的高度
const int G = 20;//重力
//跳跃函数
const int col_r = 10;//鸟碰撞体积（右
const int col_d = 10;//鸟碰撞体积（下
int tube_x,tube_y,tube_width,tube_height;//管道出现的x,y坐标和管道的碰撞体积（width，height）
//重置屏幕
void reset();
//鸟向上
int up() {
	start_y -= jump;
	return start_y;
}
//鸟向下
int down() {
	start_y += G;
	return start_y;
}
//检测键盘有无输入
bool get_control() {
	bool result = false;
	if (_kbhit()) {
		char ch = _getch();
		if (ch == ' ') {
			result = true;
		}
	}
	return result;
}
void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg) //新版png
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}//贴图，但是要求所贴图片背景必须是透明的
//加载所有图片
void pre() {
	loadimage(&bk, _T("res\\background.png"));
	loadimage(&bk1, _T("res\\background.png"));
	loadimage(&tube1_up, _T("res\\pie_up.png"));
	loadimage(&tube2_up, _T("res\\pie_up.png"));
	loadimage(&tube1_down, _T("res\\pie_down.png"));
	loadimage(&tube2_down, _T("res\\pie_down.png"));
	loadimage(&button, _T("res\\start_button.png"));
	loadimage(&land, _T("res\\land.png"));
	loadimage(&byd1, _T("res//origin-bird.png"));
	loadimage(&Title, _T("res\\title.jpg"));
	loadimage(&bird[0], _T("res\\birds.png"));
	loadimage(&bird[1], _T("res\\origin-bird.jpg"));
	loadimage(&bird[2], _T("res\\ld.jpg"));
	loadimage(&endtitle, _T("res\\noob.jpg"));
}
void end() {
	while (!get_control()) {
		putimage(0, screen_height/6, &endtitle);
	}
}
//初始化
void init() {
	pre();
	putimage(0, 0, &bk);
	mciSendString(_T("open see.mp3 alias laoda"), NULL, 0, NULL);//打开音乐，指定别名laoda
	mciSendString(_T("play laoda repeat"), NULL, 0, NULL);//播放音乐
	while (1) {
		reset();
		static int i = 0;
		putimage(screen_width/2-220, 25, &Title);
		putimage(screen_height / 2-25, screen_width / 2, &button);
		transparentimage3(&bk, 0, landheight, &land);
		putimage(75, 0, &bird[i]);
		i++;
		if (i == 3)i = 0;
		if (get_control()) {
			mciSendString("stop laoda", NULL, 0, NULL);		//停止播放音乐
			mciSendString("close laoda", NULL, 0, NULL);		//关闭音乐
			break;
		}
		Sleep(300);
	}
}
void reset() {
	putimage(0, 0, &bk);
}
//初始化函数，完全版，实现了背景图,start按键以及对应的键盘操作。
//开始游戏，需要将其中的while循环的条件改为没有碰撞
void start() {
	putimage(0, 0, &bk);
	transparentimage3(&bk, 0, landheight, &land);
	int n = 0;
	while (n != 2) {
		//transparentimage3(&bk, start_x, start_y, &byd1);
		putimage(start_x, start_y, &byd1);
		if (get_control()) {
			//transparentimage3(&bk, start_x, up(), &byd1);
			reset();
			putimage(start_x, up(), &byd1);
			n++; Sleep(200);
		}
		else if (start_y < landheight) {
			//transparentimage3(&bk, start_x, down(), &byd1);
				reset();
				putimage(start_x, down(), &byd1);
				Sleep(100);	
			
		}
	}
}
//主函数
int main() {
	initgraph(screen_height, screen_width);
	init();
	start();
	end();
	return 0;
}