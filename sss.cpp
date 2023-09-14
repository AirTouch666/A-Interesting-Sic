#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<queue>
#include<ctype.h>
#define A 17	//地图的高
#define B 17	//地图的宽
#define C 30	//雷的总数
using namespace std;
 
//全局变量
DWORD a,b;
char map[A][B],news,spare;
int BoomTotalNum,floatx,floaty,flag[A][B],flagnum,mode,slect[A][B],game;
 
//颜色属性
const WORD FORE_BLUE  =  FOREGROUND_BLUE;	//蓝色文本属性
const WORD FORE_GREEN = FOREGROUND_GREEN;	//绿色文本属性
const WORD FORE_RED   =   FOREGROUND_RED;	//红色文本属性
 
//开垦地图结构体 
struct node {
   
	int x;
	int y;
};
queue <node> dui;
 
//打印位置
void position(int x,int y) {
   
	COORD pos={
   x,y};
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out,pos);
}
 
//隐藏光标 
void Hide() {
   
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  
	CONSOLE_CURSOR_INFO CursorInfo;  
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息  
	CursorInfo.bVisible = false; //隐藏控制台光标  
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态   
}
 
//初始化
void Beginning() {
   
	while(!dui.empty()) {
   
		dui.pop();
	}
	game=1;
	//BoomTotalNum=C;
	floatx=A/2;
	floaty=B/2;
	flagnum=0;
	BoomTotalNum=C;
	mode=0;
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //获得标准输出设备句柄  
    CONSOLE_SCREEN_BUFFER_INFO csbi;                        //定义窗口缓冲区信息结构体  
    GetConsoleScreenBufferInfo(handle_out, &csbi);          //获得窗口缓冲区信息
    int x,y;
	srand((unsigned)time(0));
	for(int i=0;i<A;i++) for(int j=0;j<B;j++) {
   
		map[i][j]=' ';
		flag[i][j]=0;
		slect[i][j]=0;
	}
	while(BoomTotalNum) {
   
		x=rand()%A;
		y=rand()%B;
		if(map[x][y]==' ') {
   
			map[x][y]='@';
			BoomTotalNum--;
		}
	}
	SetConsoleTextAttribute(handle_out, FORE_GREEN);  
	for(int i=0;i<A;i++) {
   
		for(int j=0;j<B;j++) printf("█");
		printf("\n");
	}
	position(floaty*2,floatx);
	SetConsoleTextAttribute(handle_out, FORE_RED);  
	printf("");	//光标位置
	position(44,9);
	printf("扫雷模式");
	position(44,5);
	printf("剩余雷数：%d ",C-flagnum);
	SetConsoleTextAttribute(handle_out, FORE_GREEN);  
	position(5,22);
	printf("按“空格”切换模式");
	position(5,23);
	printf("按“Enter”确认");
	position(5,24);
	printf("按“方向键”选择方块"); 
	
}
 
//打印地图的一块儿 
void Lump(int xx,int yy) {
   
	switch(map[xx][yy]) {
   
		case '1' : printf("①");break;	//周围雷的数量（下同） 
		case '2' : printf("②");break;
		case '3' : printf("③");break;
		case '4' : printf("④");break;
		case '5' : printf<
