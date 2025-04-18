#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void sort(int arr[], int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = i+1; j < size; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

float calculate_mean(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (float)sum / size;
}

float calculate_median(int arr[], int size) {
    sort(arr, size);
    if(size % 2 == 0) {
        return (arr[size/2 - 1] + arr[size/2]) / 2.0;
    } else {
        return arr[size/2];
    }
}

void calculate_mode(int arr[], int size) {
    int maxCount = 0;
    int count;
    printf("Mode: ");
    for(int i = 0; i < size; i++) {
        count = 1;
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j])
                count++;
        }

        if(count > maxCount) {
            maxCount = count;
        }
    }

    for(int i = 0; i < size; i++) {
        count = 1;
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j])
                count++;
        }

        if(count == maxCount) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int numbers[SIZE] = {2, 4, 4, 6, 8, 10, 4, 6};

    printf("Numbers: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Mean: %.2f\n", calculate_mean(numbers, SIZE));
    printf("Median: %.2f\n", calculate_median(numbers, SIZE));
    calculate_mode(numbers, SIZE);

    return 0;
}
