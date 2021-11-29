//
// Created by Анна Едка
//
#include <cmath>

int check_counter_condition(double element){
    return ((cos(pow(element, 2)) > 0) && element < 0);
}

int count(double arr[], int first, int last){
    // 1 element left
    if (last == first) {
        return check_counter_condition(arr[first]);
    }
    // 2 elements left
    else if (last - first == 1){
        return check_counter_condition(arr[first]) + check_counter_condition(arr[last]);
    }
    else {
        // makes a recursive function for the first third and the remaining part
        int move = (last - first) / 3;
        return count(arr, first, first + move) + count(arr, first + move + 1, last);
    }
}


