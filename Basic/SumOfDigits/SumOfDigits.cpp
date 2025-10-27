#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    int temp = n;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    cout << sum << endl;
    return 0;
}
