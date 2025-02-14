#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minutes = 25, seconds = 0, minutesb1 = 5, minutesb2 = 15;// Default Pomodoro duration
int prevSel = 0, sel = 0;

void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

void printPomo() {
    system("cls"); // Clear screen (use "clear" for Linux/macOS)
    printf("**********\n");
    printf("  %02d:%02d\n", minutes, seconds);
    printf("**********\n");
}

void counterMain() {
    while (minutes >= 0) {
        while (seconds >= 0) {
            printPomo();
            delay(1000); // 1 second delay
            seconds--;
        }
        minutes--;
        seconds = 59;
    }
    printf("Time's up!\n");
    delay(1000);
}
void counterB1() {
    while (minutesb1 >= 0) {
        while (seconds >= 0) {
            printPomo();
            delay(1000); // 1 second delay
            seconds--;
        }
        minutesb1--;
        seconds = 59;
    }
    printf("Time's up!\n");
    delay(1000);
}
void counterB2() {
    while (minutesb2 >= 0) {
        while (seconds >= 0) {
            printPomo();
            delay(1000); // 1 second delay
            seconds--;
        }
        minutesb2--;
        seconds = 59;
    }
    printf("Time's up!\n");
    delay(1000);
}

void end(){
    printf("     ／l、             \n");
    printf("     （ﾟ､ ｡ ７         \n");
    printf("       l  ~ヽ       \n");
    printf("       じしf_,)ノ\n");
    printf("        Finished        \n");
}
counterSelect(){
    if(sel == 1){
        prevSel = 1;
            counterMain();
            sel = 2;
            delay(1000);
        }
        else if (sel == 2 && prevSel == 1){
            prevSel = 2;
            counterB1;
            sel = 1;
            delay(1000);
        }
        else if (sel == 1 && prevSel == 2){
            prevSel = 3;
            counterMain();
            sel = 2;
            delay(1000);
        }
        else if (sel == 2 && prevSel == 3){
            prevSel = 4;
            counterB1();
            sel = 3;
            delay(1000);
        }
        else if (sel == 3 && prevSel == 4){
            counterB2();
            end();
        }
        
    
    }

int main() {
    printf("     ／l、             \n");
    printf("     （ﾟ､ ｡ ７         \n");
    printf("       l  ~ヽ       \n");
    printf("       じしf_,)ノ\n");
    printf("Starting Pomodoro Timer!\n");
    printf("Type 1 to start: ");
    scanf("%d", &sel);
    counterSelect();
    return 0;
}
