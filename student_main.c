#include <stdio.h>

int main() {
    int n1, n2, i, j, k;
    int set1[100], set2[100];
    int intersection[100];
    int count = 0;

    // Read Set 1
    if (scanf("%d", &n1) != 1) return 0;
    for(i = 0; i < n1; i++) {
        scanf("%d", &set1[i]);
    }

    // Read Set 2
    if (scanf("%d", &n2) != 1) return 0;
    for(i = 0; i < n2; i++) {
        scanf("%d", &set2[i]);
    }

    /* YOUR CODE GOES HERE!
         Hints:
         1. You need to find numbers that are in BOTH set1 and set2.
         2. BUT, only include each common number ONCE in your result.
         3. Store the common numbers in the 'intersection' array.
    */
    //----------------------------------------------------------------//
    for(i = 0; i < n1; i++){
        for(j = 0; j < n2; j++){
            if(set1[i] == set2[j]){
                int dup = 0;
                for(k = 0; k < count; k++){
                    if(intersection[k] == set1[i]){
                        dup = 1;
                    }
                }
                if(dup == 0){
                    intersection[count] = set1[i];
                    count++;
                }
                break;
            }
        }
    }

    for(i = 0; i < count-1; i++){
        for(j = 0; j < count-i-1; j++){
            if(intersection[j] > intersection[j+1]){
                int temp = intersection[j];
                intersection[j] = intersection[j+1];
                intersection[j+1] = temp;
            }
        }
    }
    //----------------------------------------------------------------//
    for(i = 0; i < count; i++) {
        printf("%d ", intersection[i]);
    }
    printf("\n");

    return 0;
}
