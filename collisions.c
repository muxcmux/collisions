#include <stdlib.h>
#include <stdio.h>

/* qsort comparison function */
int int_cmp(const void *a, const void *b)
{
const int *ia = (const int *)a; // casting pointer types
const int *ib = (const int *)b;
return *ia  - *ib;

}

void space_balls(){

    int min_y = 0;
    int max_y = 50;
    int dia = 5;

    int points[] = {-7,-3,30,8,55};

    size_t points_len = sizeof(points)/sizeof(int);

    qsort(points, points_len, sizeof(int), int_cmp);

    int done = 0;
    int error;
    int p1;
    int p2;
    int diff;
    while( !done ){
        error = 0;

        for(int i = 0; i < points_len; i++) {
                printf("%d ", points[i]);
        }
        printf("%s\n", "");

        for(int i = 1; i < points_len; i++) {
            p1 = points[i-1];
            p2 = points[i];
            diff = abs(p2 - p1);

            if(diff < dia){
                points[i-1] -= 1;
                points[i] += 1;
                error = 1;
            }
        }

        if (points[0] < min_y){
            //points[0] += 1;
            points[0] = min_y;
            error = 1;
        }

        if (points[points_len -1 ] > max_y){
            //points[points_len -1 ] -= 1;
            points[points_len -1 ] = max_y;
            error = 1;
        }

        done = !error;
    }

    for(int i = 0; i < points_len; i++) {
        printf("%d ", points[i]);
    }
    printf("%s\n", "");

}

int main(){

    space_balls();
}