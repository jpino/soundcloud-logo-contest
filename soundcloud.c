#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK 1000000

int main()
{
    // Soundcloud logo
    int logo[84] = {0,0,0,0,0,3,3,9,9,9,6,0,0,0,
                      0,0,0,3,4,9,5,9,9,9,9,4,0,0,
                      0,1,2,7,5,9,5,9,9,9,9,7,1,0,
                      3,9,5,9,5,9,5,9,9,9,9,9,9,3,
                      6,9,5,9,5,9,5,9,9,9,9,9,9,6,
                      1,8,5,9,5,9,5,9,9,9,9,9,8,1};


    char buffer[CHUNK];

    FILE *fp;
    int offset;
    int evaluation;
    int x;
    int chunk_number = 0;
    int chunk_size = CHUNK;

    fp = fopen("pi-billion.txt","r");
    if (fp == NULL) {
        printf("Could not open file 'pi-billion.txt'\n");
        return 1;
    }

    // Skip the "3." at the beginning of the file
    fseek(fp, 2, SEEK_SET);

    // Read the file in chunks of size CHUNK
    while(fgets(buffer, CHUNK, fp) != NULL) {
        if (feof(fp)) {
            // The last chunk may not be of CHUNK length
            chunk_size = strlen(buffer);
        } else {
            // Adjacent chunks overlap 83 characters
            fseek(fp, -82, SEEK_CUR);
        }

        offset = 0;

        // Run every chunk in subchunks (or sequences) of length 84
        while (offset + 84 <= chunk_size) {
            evaluation = 0;
            for(x=0; x<84; x++) {
                // This evaluation expression results in the goodness of the
                // current sequence, calculated as the sum of absolute
                // differences (SAD). It works by taking the absolute difference
                // between each pixel in the Soundcloud logo and the
                // corresponding pixel in the current sequence. These
                // differences are summed to create a simple metric of
                // similarity. More complex expressions can be used, but being
                // a brute force algorithm, its core should be kept simple.
                // Lower is better.
                evaluation += abs(logo[x] - (buffer[offset+x] - '0'));

                // Performance tweak: we are not interested in sequences with
                // evaluations greater than 195.
                if (evaluation > 195) {
                    break;
                }
            }

            if (evaluation < 196) {
                // Print good enough sequences
                printf("eval: %d | offset: %d | sequence: %.84s\n",
                       evaluation,
                       (CHUNK - 83) * chunk_number + offset + 1,
                       &(buffer[offset]));
            }

            offset++;
        }
        chunk_number++;
    }

    fclose (fp);
    return 0;
}