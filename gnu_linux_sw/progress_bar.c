#include <stdio.h>
#include <unistd.h>  // for sleep()

void progressBar(int progress, int total) {
    int barWidth = 50; // width of the bar
    float ratio = (float)progress / total;
    int pos = barWidth * ratio;

    printf("[");
    for (int i = 0; i < barWidth; i++) {
        if (i < pos) printf("=");
        else if (i == pos) printf(">");
        else printf(" ");
    }
    printf("] %d%%\r", (int)(ratio * 100));
    fflush(stdout);
}

int main() {
    int total = 100;
    for (int i = 0; i <= total; i++) {
        progressBar(i, total);
        usleep(50000); // sleep for 50ms
    }
    printf("\nDone!\n");
    return 0;
}
