#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int *num = malloc(sizeof(int));
    
    system("mixerctl -n outputs.master | cut -d',' -f2 > /tmp/vol");
    FILE *tmp = fopen("/tmp/vol", "r");
    fscanf(tmp, "%i", num);
    
    (*num) *= 100;
    (*num) /= 255;
    
    int ttime = 0;
    
    if(tm.tm_hour > 12)
        ttime = 1;

    printf("<span foreground=\"#98989b\">TIME:</span> %d:%d %s  <span foreground=\"#98989b\">VOL:</span> %d%%  <span foreground=\"#98989b\">BAT:</span>", (ttime == 0) ? tm.tm_hour : tm.tm_hour - 12, tm.tm_min, (ttime == 0) ? "AM" : "PM", *num);
    free(num);
}
