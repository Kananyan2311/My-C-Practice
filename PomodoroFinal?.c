#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN "cls"
#else
    #include <unistd.h>
    #define CLEAR_SCREEN "clear"
#endif

int workMinutes = 25, shortBreak = 5, longBreak = 15;
int seconds = 0, cycle = 1;

void delay(int seconds) {
    sleep(seconds);
}

void printPomo(int minutes, int seconds) {
    system(CLEAR_SCREEN);
    printf("**********\n");
    printf("  %02d:%02d\n", minutes, seconds);
    printf("**********\n");
}

void startTimer(int *minutes) {
    seconds = 0; 
    while (*minutes >= 0) {
        while (seconds >= 0) {
            printPomo(*minutes, seconds);
            delay(1);
            seconds--;
        }
        (*minutes)--;
        seconds = 59;
    }
    printf("Time's up!\n");
    delay(1);
}

void endSession() {
    printf("     ／l、             \n");
    printf("     （ﾟ､ ｡ ７         \n");
    printf("       l  ~ヽ       \n");
    printf("       じしf_,)ノ\n");
    printf("        Finished        \n");
}

void pomodoroCycle() {
    while (cycle <= 4) {
        startTimer(&workMinutes);
        if (cycle == 4) {
            startTimer(&longBreak);
        } else {
            startTimer(&shortBreak);
        }
        cycle++;
    }
    endSession();
}

int main() {
    printf("     ／l、             \n");
    printf("     （ﾟ､ ｡ ７         \n");
    printf("       l  ~ヽ       \n");
    printf("       じしf_,)ノ\n");
    printf("Starting Pomodoro Timer!\n");
    printf("Press 1 to start: ");
    
    int sel;
    scanf("%d", &sel);
    
    if (sel == 1) {
        pomodoroCycle();
    } else {
        printf("Invalid selection. Exiting...\n");
    }

    return 0;
}
