# PBLF
IMAGE bk;//代表背景
IMAGE tube1_up, tube1_down;//第一对管道
IMAGE tube2_up, tube2_down;//第二对管道
const int pipeup;//管道上补偿；
const int piupedown;//管道下补偿
IMAGE byd;//代表鸟
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
