#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void cscan(int requests[], int n, int head, int disk_size) {
    int total_movement = 0;
    int i, j;

    // Sort the request array
    sort(requests, n);

    printf("Movement of Cylinders\n");

    // Service the requests
    // Move to the right
    for (i = 0; i < n; i++) {
        if (requests[i] >= head) {
            printf("Move from %d to %d\n", head, requests[i]);
            total_movement += abs(requests[i] - head);
            head = requests[i];
        }
    }

    // Jump to the beginning of the disk
    if (head < disk_size - 1) {
        printf("Move from %d to %d\n", head, disk_size - 1);
        total_movement += abs((disk_size - 1) - head);
        head = 0;
        printf("Move from %d to %d\n", disk_size - 1, 0);
        total_movement += abs((disk_size - 1) - 0);
    }

    // Continue from the beginning
    for (i = 0; i < n; i++) {
        if (requests[i] < head) {
            printf("Move from %d to %d\n", head, requests[i]);
            total_movement += abs(requests[i] - head);
            head = requests[i];
        }
    }

    printf("Total head movement: %d\n", total_movement);
}

int main() {
    int n, i, head, disk_size;
    printf("Enter the size of the disk: ");
    scanf("%d", &disk_size);

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the request array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    cscan(requests, n, head, disk_size);

    return 0;
}