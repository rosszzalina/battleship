#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {
    const int n = 10;
    int size;
    int arr[n] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    cout << "Welcome to the Memory Game!";
    cout << endl;
    cout << "Enter the size of an array: ";
    cin >> size;
    if (size != n) {
        cout << "Please enter the correct size: " << n << endl;
        return 1;
    }
    int found[n] = {0}; // Array to keep track of found elements
    int cnt = 0, moves = 0;
    srand(time(0)); // Seed for random number generation
    random_shuffle(arr, arr + n); // Shuffle the array

    while (cnt < n) {
        // Display the array elements (either '?' or the numbers found)
        for (int i = 0; i < n; i++) {
            if (found[i] == 0) {
                cout << "? ";
            } else {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
        int a, b;
        cout << "Enter two indices: ";
        cin >> a >> b;
        if (a < 0 || a >= n || b < 0 || b >= n || found[a] == 1 || found[b] == 1 || a == b) {
            cout << "Invalid indices, please try again." << endl;
            continue;
        }
        moves++;
        cout << "The number at index " << a << " is " << arr[a] << endl;
        cout << "The number at index " << b << " is " << arr[b] << endl;
        if (arr[a] == arr[b]) {
            cout << "These numbers are equal!" << endl;
            found[a] = 1;
            found[b] = 1;
            cnt += 2; // Increment by 2 as we found a pair
        } else {
            cout << "These numbers are not equal." << endl;
        }
        system("cls"); // Use "clear" for Unix-based systems (Linux or macOS)
        if (cnt == n) {
            cout << "Congratulations! You found all pairs in " << moves << " moves." << endl;
            break;
        }
    }
    return 0;
}
