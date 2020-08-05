#include <iostream>
using namespace std;

int StringLength(char arr[]) {
    int len = 0;

    while (arr[len] != '\0') {
        ++len;
    }
    return len;
}
void kRotate(char arr[], int k){
	int en = StringLength(arr) - 1;
	for (int i=1;i<=k;i++){
    	char last=arr[en];
    	for (int i = en;i>0;i--) {
        	arr[i] = arr[i-1];
    	}
    	arr[0] = last;
	}
}

int main(){
	char arr[100];
    cin >> arr;
    int k;
    cin  >> k;

    kRotate(arr, k);
    cout << arr;
}