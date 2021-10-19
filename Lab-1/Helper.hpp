#pragma once

#include <iostream>
#include "TimeTests.hpp"
#include "WorkTests.hpp"

void HelperWorkTest() {
    int size = 1;
    do {
        cout << "Size of sequence: " << endl;
        cin >> size;
        if (size >= 1) WorkTest(size);
        else cout << "Size must be positive number" << endl;
    } while (size < 1);
}

void HeplerTimeTest() {
    int min_size = 0, max_size = 0, step_size = 0, measurements = 1;
    do {
        cout << "Min size of sequence: " << endl;
        cin >> min_size;
        if (min_size < 1) cout << "Size must be positive number" << endl;
    } while (min_size < 1);
    do {
        cout << "Max size of sequence: " << endl;
        cin >> max_size;
        if (max_size < 1) cout << "Size must be positive number" << endl;
    } while (max_size < 1);
    do {
        cout << "Step size of sequence: " << endl;
        cin >> step_size;
        if (step_size < 1) cout << "Size must be positive number" << endl;
    } while (step_size < 1);
    do {
        cout << "Count of measurments: " << endl;
        cin >> measurements;
        if (measurements < 1) cout << "Count must be positive number" << endl;
    } while (measurements < 1);
    TimeTest(min_size, max_size, step_size, measurements);
}

void MainFunction() {
    cout << "This program help you to test sequence's sorts."<< endl;
    int choose = 0;
    do {
        cout << "You can choose :" << endl;
        cout << "1. Auto work tests" << endl << "2. Time tests" << endl << "3. Exit" << endl;
        cin >> choose;
        switch (choose) {
            case 1:
                HelperWorkTest();
                break;
            case 2:
                HeplerTimeTest();
                break;
            case 3:
                break;
            default:
                cout << "Wrong! Try again!" << endl;
                break;
        }
    } while (choose != 3);

}