#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void myhandler(int signo) {
    printf("Signal received ~~~~%d\n", signo);
}

int main() {
    signal(SIGINT, myhandler);

    while (1) {
        printf("signal test\n");
        sleep(1);
    }

    return 0;
}
