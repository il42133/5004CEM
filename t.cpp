#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;
#define NUM_THREADS 4

//Function for addition
void *add(void *arg) {
    int *nums = (int *) arg;
    int result = nums[0] + nums[1];
    printf("Addition: %d\n", result);
    pthread_exit(NULL);
}

//Function for subtraction
void *subtract(void *arg) {
    int *nums = (int *) arg;
    int result = nums[1] - nums[0];
    printf("Subtraction: %d\n", result);
    pthread_exit(NULL);
}

//Function for multiplication
void *multiply(void *arg) {
    int *nums = (int *) arg;
    int result = nums[1] * nums[0];
    printf("Multiplication: %d\n", result);
    pthread_exit(NULL);
}

//Function for division
void *division(void *arg) {
    int *nums = (int *) arg;
    int result = nums[1] / nums[0];
    printf("Division: %d\n", result);
    pthread_exit(NULL);
}

//Main function to create threads
int main () {
    pthread_t threads[NUM_THREADS];
    int rc, i, x ,y;
    cout << "Type a number: ";
    cin >> x;
    cout << "Type another number: ";
    cin >> y;
    int nums[2] = {x, y};
    for(i = 0; i < NUM_THREADS; i++) {
        if (i == 0) {
            rc = pthread_create(&threads[i], NULL, add, &nums[2]);
            if (rc) {
                printf("Error: unable to create thread, %d\n", rc);
                exit(-1);
            }
        } else if (i == 1) {
            rc = pthread_create(&threads[i], NULL, subtract, &nums[2]);
            if (rc) {
                printf("Error: unable to create thread, %d\n", rc);
                exit(-1);
            }
        } else if (i == 2) {
            rc = pthread_create(&threads[i], NULL, multiply, &nums[2]);
            if (rc) {
                printf("Error: unable to create thread, %d\n", rc);
                exit(-1);
            }
        } else if (i == 3) {
            rc = pthread_create(&threads[i], NULL, division, &nums[2]);
            if (rc) {
                printf("Error: unable to create thread, %d\n", rc);
                exit(-1);
            }
        }
    }
    pthread_exit(NULL);
}