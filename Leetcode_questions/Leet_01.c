#include <stdio.h>

#define MAX_SIZE 100

int sum_of_numbers(int nums[], int length, int target);

int main(void) {
    int length;
    printf("Length of the array: ");
    if (scanf("%d", &length) != 1 || length <= 0 || length > MAX_SIZE) {
        fprintf(stderr, "Invalid length.\n");
        return 1;
    }

    int nums[MAX_SIZE];

    printf("Numbers: ");
    for (int i = 0; i < length; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            fprintf(stderr, "Invalid number at index %d.\n", i);
            return 1;
        }
    }

    int target;
    printf("Target: ");
    if (scanf("%d", &target) != 1) {
        fprintf(stderr, "Invalid target.\n");
        return 1;
    }

    int count = sum_of_numbers(nums, length, target);
    if (count == 0) {
        printf("No adjacent pair sums to %d\n", target);
    } else {
        printf("\n");
    }

    return 0;
}

int sum_of_numbers(int nums[], int length, int target) {
    int count = 0;
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (nums[i] + nums[j] == target) {
                printf("[%d %d] ", nums[i], nums[j]);
                count++;
            }
        }
    }
    return count;
}