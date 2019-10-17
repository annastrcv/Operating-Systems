#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct page{
    int number;
    int Rbit;
    char counter; // 1 byte
};
int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("Not enough arguments.\n");
        return 1;
    }
    int page_frames_count;
    sscanf(argv[1], "%d", &page_frames_count);

    printf("page count %d\n", page_frames_count);

    FILE* input = fopen ("linput.txt", "r");
    int current_page_number;

    struct page pages[1000];
    for(int i = 0; i < 1000; i++)
    {
        pages[i].number = i;
        pages[i].Rbit = 0;
        pages[i].counter = 0;
    }

    struct page page_frames[page_frames_count];
    int loaded_pages_count = 0;

    int hit = 0;
    int miss = 0;

    int tick = 0;
    while(fscanf(input,"%d", &current_page_number) != EOF) {
        if(tick % 10 == 0){
            for(int j = 0; j < loaded_pages_count; j++){
                page_frames[j].counter >>= 1;
                page_frames[j].Rbit |= (page_frames[j].Rbit<<7); // shift on 7 bits to write to the leftmost bit
            }
        }

        // printf("while\n");
        int success = 0;
        for(int i = 0; i < loaded_pages_count; i++){
            if(page_frames[i].number == current_page_number){
                hit++;
                page_frames[i].Rbit = 1;
                success = 1;
                break;
            }
        }
        if (success)
            continue;

        miss++; // if it's not a hit, then it's a miss
        if (loaded_pages_count < page_frames_count){
                page_frames[loaded_pages_count] = pages[current_page_number];
                page_frames[loaded_pages_count].Rbit = 1;
                loaded_pages_count++;
            }
            int min_counter = 1000;
            int worst_page;
            for(int j = 0; j < loaded_pages_count; j++){
                if(page_frames[j].counter <= min_counter)
                {
                    min_counter = page_frames[j].counter;
                    worst_page = j;
                }
            }
            pages[page_frames[worst_page].number]= page_frames[worst_page];
            page_frames[worst_page]= pages[current_page_number];
            tick++;
    }

    printf("The number of hits =  %d and misses = %d\n", hit, miss);
    printf("The ratio: %f\n", (float)hit/miss);

    fclose(input);
    return 0;
}