# PBLF
## 将screen_height宏定义为屏幕宽，screen_width宏定义为屏幕长
IMAGE bk;//代表背景
IMAGE tube1_up, tube1_down;//第一对管道
IMAGE tube2_up, tube2_down;//第二对管道
const int pipeup;//管道上补偿；
const int piupedown;//管道下补偿
IMAGE byd1,byd2,byd3;// ==三种鸟代表三种状态，实际游戏只需要一种状态，开场动画做出三种状态就可以了==
**实际上我们还需要一个getcontrol函数来检测是否有键盘或者鼠标的输入，以此来作为是否要结束init函数的标志，为了简化，将其改为键盘输入就好。**
IMAGE land;//地面
int bird_x;//鸟的横坐标，不变
int bird_y = 220;//鸟的纵坐标，会随之变化
const double g = 6.5;//重力
long time;//游戏进行的时间，与管道的生成有关
void init_game();//开始游戏
void game();
void draw_pipe();//画管道
void quit_game();//退出游戏
bool is_dead();//鸟是不是死了,1活着0死了
bool is_col();//检测碰撞，1撞0没撞
void init_game() {
	

}
bool is_dead() {
	if (is_col())return 0;
	else return 1;
}
**目前初步框架是这样的，后期可能有改动**
