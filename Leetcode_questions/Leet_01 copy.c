#include <stdio.h>
#include <stdlib.h>

int sum_of_numbers(int nums[], int length, int target);

int main(void) {
    int length;
    printf("Length of the array: ");
    if (scanf("%d", &length) != 1 || length <= 0) {
        fprintf(stderr, "Invalid length.\n");
        return 1;
    }

    int *nums = malloc((size_t)length * sizeof *nums);
    if (!nums) {
        fprintf(stderr, "Allocation failed.\n");
        return 1;
    }

    printf("Numbers: ");
    for (int i = 0; i < length; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            fprintf(stderr, "Invalid number at index %d.\n", i);
            free(nums);
            return 1;
        }
    }

    int target;
    printf("Target: ");
    if (scanf("%d", &target) != 1) {
        fprintf(stderr, "Invalid target.\n");
        free(nums);
        return 1;
    }

    int count = sum_of_numbers(nums, length, target);
    if (count == 0) {
        printf("No adjacent pair sums to %d\n", target);
    } else {
        printf("\n");
    }

    free(nums);
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