#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

//定义游戏区域大小
#define WIDTH 20
#define HEIGHT 20

//定义方向枚举
enum Direction{STOP=0,LEFT,RIGHT,UP,DOWN};

//全局变量
int gameOver;
int x,y;//蛇头坐标
int fruitX,fruitY;//食物坐标
int score;
int tailX[100],tailY[100];//蛇身坐标数组
int nTail;//蛇身长度
enum Direction dir;//当前方向

//辅助函数：隐藏光标
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info={1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}

//辅助函数：移动光标到指定位置
void GotoXY(int x,int y)
{
    HANDLE hOut;
    COORD Coordinate;
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    Coordinate.X=x;
    Coordinate.Y=y;
    SetConsoleCursorPosition(hOut,Coordinate);
}

//初始化函数
void Setup()
{
    gameOver=0;
    dir=STOP;//初始状态不动
    x=WIDTH/2;
    y=HEIGHT/2;
    srand(time(NULL));//随机生成食物
    fruitX=rand()%(WIDTH-2)+1;//避免生成在边界上
    fruitY=rand()%(HEIGHT-2)+1;//避免生成在边界上
    score=0;
    nTail=0;
    HideCursor();//隐藏光标
}

//绘图函数
void Draw()
{
    //每次绘图前将光标移回左上角，覆盖打印，而不是清屏
    GotoXY(0,0);
    //打印上墙壁
    for(int i=0;i<WIDTH+2;i++){
        printf("#");}
        printf("\n");
        //打印中间区域
        for(int i=0;i<HEIGHT;i++){
            for(int j=0;j<WIDTH;j++){
                if(j==0){
                    printf("#");//打印左墙壁
                }
                if(i==y&&j==x){
                    printf("O");//打印蛇头
                }else if(i==fruitY&&j==fruitX){
                    printf("F");//打印食物
                }else{
                    int print=0;
                    //遍历并打印蛇身
                    for(int k=0;k<nTail;k++){
                        if(tailX[k]==j&&tailY[k]==i){
                            printf("o");//打印蛇身
                            print=1;
                        }
                    }
                    if(!print){
                        printf(" ");//空白处
                    }
                }
                if(j==WIDTH-1){
                    printf("#");//打印右墙壁
                }
            }
            printf("\n");
        }
        //打印下墙壁
        for(int i=0;i<WIDTH+2;i++){
            printf("#");}//打印下墙壁
                printf("\n");
                printf("Score:%d\n",score);
                printf("Control:W,A,S,D|Quit:X\n");
        
    
}

//输入处理函数
void Input()
{
    //_kbhit()检测是否有按键被按下，是非阻塞的
    if(_kbhit()){
        //_getch()获取按下的键值
        switch(_getch()){
            case 'a':
                if(dir!=RIGHT){
                    dir=LEFT;//防止直接反向掉头
                }
                break;
            case 'd':
                if(dir!=LEFT){
                    dir=RIGHT;
                }
                break;
            case 'w':
                if(dir!=DOWN){
                    dir=UP;
                }
                break;
            case 's':
                if(dir!=UP){
                    dir=DOWN;
                }
                break;
            case 'x':
                gameOver=1;
                break;
        }
    }
}

//逻辑处理函数
void Logic(){
    //记录蛇身移动轨迹
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<nTail;i++){
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    //根据方向移动蛇头
    switch(dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
                default:
                    break;
    }
    //碰撞检测（碰到墙壁游戏结束）
    if(x>WIDTH||x<0||y>=HEIGHT||y<0){
        gameOver=1;
    }
    //碰撞检测（碰到自己游戏结束）
    for(int i=0;i<nTail;i++){
        if(tailX[i]==x&&tailY[i]==y){
            gameOver=1;
        }
    }
    //吃食物逻辑
    if(x==fruitX&&y==fruitY){
        score+=10;
        nTail++;
        fruitX=rand()%WIDTH;
        fruitY=rand()%HEIGHT;
    }
}

//主函数
int main()
{
    Setup();

    while(!gameOver){
        Draw();
        Input();
        Logic();
        Sleep(200);//控制游戏速度,数字越小速度越快（单位：毫秒）

    }
    //显示游戏结束
    GotoXY(WIDTH/2-4,HEIGHT/2);
    printf("Game Over!\n");
    GotoXY(0,HEIGHT+3);//移动到底部防止覆盖
    system("pause");//暂停防止窗口关闭
    return 0;
}
