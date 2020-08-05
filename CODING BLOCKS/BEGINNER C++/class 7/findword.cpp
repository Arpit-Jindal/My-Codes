#include <iostream>
using namespace std;

void input(char arr[][100], int n ){
		for (int i=0;i<n;i++){
			cin>>arr[i];
		}
}

bool strcmp(char word1[],char word2[]){
	int i=0;
	int j=0;
	while(word1[i]!='\0'&& word2[j]!='\0'){
		if (word1[i]!=word2[j])return false;
		++i;
		++j;
	} 
	return word1[i]==word2[j];
}

bool searchword(char arr[][100], int n,char word[]){

}
int main(){
	int n;
	cin>>n;
	char arr[10][100];
	input(arr,n);
	char word[100];
	cin>>word;

	cout<< searchword(arr,n,word);
	
}