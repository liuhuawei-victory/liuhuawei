#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h> // 引入usleep函数  
#include <time.h>   // 引入time函数  
  
#define WIDTH 20  
#define HEIGHT 20  
#define SNAKE_LENGTH 100  
  
int x[SNAKE_LENGTH], y[SNAKE_LENGTH];  
int tail;  
int n_apples;  
int apple_x[10], apple_y[10]; // 假设苹果数量不超过10个  
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };  
enum eDirection dir;  
int game_over;  
int score;  
  
void Setup() {  
    // 初始化随机数生成器  
    srand(time(NULL));  
  
    game_over = 0;  
    dir = STOP;  
    tail = 0;  
    score = 0;  
    n_apples = 1;  
  
    // 初始化蛇  
    for (int i = 0; i < SNAKE_LENGTH; i++) {  
        x[i] = WIDTH / 2;  
        y[i] = HEIGHT / 2;  
    }  
  
    // 初始化苹果  
    placeApple();  
}  
  
void placeApple() {  
    int valid;  
    do {  
        apple_x[0] = rand() % WIDTH;  
        apple_y[0] = rand() % HEIGHT;  
        valid = 1;  
        for (int i = 0; i < tail; i++) {  
            if (apple_x[0] == x[i] && apple_y[0] == y[i]) {  
                valid = 0;  
                break;  
            }  
        }  
    } while (!valid);  
}  
  
void Draw() {  
    // ... (与原始代码相同，略去以节省空间)  
}  
  
void Input() {  
    char c = getchar(); // 简单使用getchar()读取一个字符，实际应更复杂  
    switch (c) {  
        case 'a':  
            dir = LEFT;  
            break;  
        case 'd':  
            dir = RIGHT;  
            break;  
        case 'w':  
            dir = UP;  
            break;  
        case 's':  
            dir = DOWN;  
            break;  
        case 'x':  
        case 'q': // 添加'q'以便退出游戏  
            game_over = 1;  
            break;  
    }  
    // 清除输入缓冲区中的剩余字符  
    while (getchar() != '\n');  
}  
  
void Logic() {  
    // ... (与原始代码类似，但处理苹果和尾巴的逻辑有所不同)  
  
    int head_x = x[0];  
    int head_y = y[0];  
  
    // 蛇头移动  
    switch (dir) {  
        // ... (与原始代码相同)  
    }  
  
    // 检查是否吃到苹果  
    for (int i = 0; i < n_apples; i++) {  
        if (head_x == apple_x[i] && head_y == apple_y[i]) {  
            score += 10;  
            tail++;  
            if (n_apples < 10) { // 防止数组越界  
                n_apples++;  
                placeApple();  
            }  
  
            // 将尾巴移动到旧位置（这里简化为只复制最后一个有效位置）  
            for (int j = tail; j > 0; j--) {  
                x[j] = x[j - 1];  
                y[j] = y[j - 1];  
            }  
            break; // 假设一次只能吃一个苹果  
        }  
    }  
  
    // ... (其他逻辑与原始代码相同)  
}  
  
int main() {  
    Setup();  
  
    while (!game_over) {  
        Draw();  
        Input();  
        usleep(100000); // 延时  
        Logic();  
    }  
  
    Draw();  
    printf("Game Over\n");  
    printf("Your Score: %d\n", score);  
  
    return 0;  
}