#include <iostream>
using namespace std;

int StringLength(char arr[]) {
    int len = 0;

    while (arr[len] != '\0') {
        ++len;
    }
    return len;
}

void stringRotate(char arr[]) {
    int en = StringLength(arr) - 1;
    char last=arr[en];
    for (int i = en;i>0;i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = last;
}

int main() {
    char arr[10];
    cin >> arr;
    stringRotate(arr);
    cout << arr;
}