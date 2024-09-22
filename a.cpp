#include <iostream>
#include <vector>
#include <cmath> 
#include <limits> 

using namespace std;

int main() {
    int N; 
    cin >> N;

    vector<int> num(N); 
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    int X; 
    cin >> X;
    int min_diff = numeric_limits<int>::max(); 
    int index = -1; 
    for (int i = 0; i < N; i++) {
        int diff = abs(num[i] - X); 
        if (diff < min_diff) { 
            min_diff = diff; 
            index = i; 
        }
    }
    cout << index << endl;

    return 0;
}