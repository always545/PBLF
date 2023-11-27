#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cstring>
/**
只实现3个部分，管道和鸟的移动，管道和鸟的贴图，碰撞的检测。

**/
IMAGE bk;//代表背景
void init() {
	initgraph(600, 600);
	loadimage(&bk, _T("res\\background.png"));
	putimage(0, 0, &bk);
	_getch();
	return;
}
int main() {
	init();
	return 0;
}