#include <iostream>
#include <chrono>
#include "matrix.h"
#include "munkres.h"
using namespace std;
using namespace chrono;
int main() {
    double iou_cost_array[] = {
            0.9, 0.2, 0.1, 0.05, 0.04, 0.03, 0.02, 0.01, 0.01, 0.,
            0.09, 0.9, 0.1, 0.05, 0.04, 0.03, 0.02, 0.01, 0.01, 0.,
            0.009, 0.2, 0.9, 0.05, 0.04, 0.03, 0.02, 0.01, 0.01, 0.,
            0.009, 0.2, 0.1, 0.9, 0.04, 0.03, 0.02, 0.01, 0.01, 0.,
            0.009, 0.2, 0.1, 0.05, 0.8, 0.03, 0.02, 0.01, 0.01, 0.,
            0.009, 0.2, 0.1, 0.05, 0.04, 0.87, 0.02, 0.01, 0.01, 0.,
            0.009, 0.2, 0.1, 0.05, 0.04, 0.03, 0.94, 0.01, 0.01, 0.,
            0.009, 0.2, 0.1, 0.05, 0.04, 0.03, 0.02, 0.99, 0.01, 0.,
            0.009, 0.2, 0.1, 0.05, 0.04, 0.03, 0.02, 0.01, 0.89, 0.,
            0.009, 0.2, 0.1, 0.05, 0.04, 0.03, 0.02, 0.01, 0.01, 0.92,
    };
    int rows = 10;
    int cols = 10;
    Matrix<double> iou_cost_matrix(rows, cols);
    for (int i = 0; i<rows; i++){
        for (int j = 0; j<cols; j++){
            iou_cost_matrix(i, j) = 1 - iou_cost_array[j + i * cols];
        }
    }
    auto start_time = chrono::system_clock::now();
    Munkres<double> matcher;
    matcher.solve(iou_cost_matrix);
    auto end_time = chrono::system_clock::now();
    auto cost_time = chrono::duration<double, milli>(end_time - start_time).count();
    cout << "cost time : " << cost_time << " ms ." << endl;
    cout << "result: " << endl;
    for (int i = 0; i<rows; i++){
        for (int j = 0; j<cols; j++){
            cout << iou_cost_matrix(i, j) << " , ";
        }
        cout << endl;
    }
    return 0;
}
