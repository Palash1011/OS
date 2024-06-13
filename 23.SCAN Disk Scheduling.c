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

void scan(int requests[], int n, int head, int disk_size) {
    int total_movement = 0;
    int i, j;
    int direction;  // 1 for moving towards end, -1 for moving towards start

    // Sort the request array
    sort(requests, n);

    // Find the initial direction
    if (head < requests[0]) {
        direction = 1;
    } else if (head > requests[n-1]) {
        direction = -1;
    } else {
        // Head is between some requests
        if ((requests[n-1] - head) >= (head - requests[0])) {
            direction = 1;
        } else {
            direction = -1;
        }
    }

    printf("Movement of Cylinders\n");
    
    // Serve the requests
    while (1) {
        if (direction == 1) {
            for (i = 0; i < n; i++) {
                if (requests[i] >= head) {
                    printf("Move from %d to %d\n", head, requests[i]);
                    total_movement += abs(requests[i] - head);
                    head = requests[i];
                }
            }
            // Change direction at the end
            direction = -1;
        } else {
            for (i = n-1; i >= 0; i--) {
                if (requests[i] <= head) {
                    printf("Move from %d to %d\n", head, requests[i]);
                    total_movement += abs(requests[i] - head);
                    head = requests[i];
                }
            }
            // Change direction at the start
            direction = 1;
        }

        // Check if all requests have been serviced
        int done = 1;
        for (i = 0; i < n; i++) {
            if (requests[i] != -1) {
                done = 0;
                break;
            }
        }
        if (done) break;
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

    scan(requests, n, head, disk_size);

    return 0;
}