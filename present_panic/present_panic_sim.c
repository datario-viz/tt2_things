#include <stdlib.h>
#include <time.h>

int present_panic_sim (int p, int t, int target) {
    int g = p - t;
    int total_scissors = 0;
    int streak = 0;
    int *board = (int *)malloc(p*sizeof(int));
    int i;

    // Initialize the board: 0 for trolls, 1 for ginger
    for (i=0;i<t;i++) {
        board[i] = 0; // troll
    }
    for (i=t;i<p;i++) {
        board[i] = 1; // ginger
    }

    srand((unsigned int)time(NULL)+rand());

    while (streak < target) {
        int index = rand() % p;
        total_scissors++;

        if (board[index] == 1) { // ginger
            streak++;
            board[index] = board[--p]; // Remove ginger and shrink board
        } else { // troll
            streak = 0;
            t--;
            p = t + g; // Reset board
            for (i = 0; i < t; i++) board[i] = 0; // troll
            for (i = t; i < p; i++) board[i] = 1; // ginger
        }
    }

    free(board);
    return total_scissors;
}
