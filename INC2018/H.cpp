#include <iostream>
#include <string> 
#include <cmath> 

using namespace std;

int getLength(int x){
	int length = 1;
	while( (x / 10) != 0 ){
		length++;
		x = x / 10;
	}
	return length;
}

int sOdd(int x){
	int total = x/2;
	if(x%2 != 0) total+=1;
	return total;
}

int countOdd(int x){
	int total = sOdd(x);

	int length = getLength(x);
	int sum = 0;
	int odd = 0;
	int tmpNumber = x;
	for(int i=length-1; i>=1 ; i--){
		int div = pow(10, i);
		int tmpTotal = tmpNumber / div; 
		
		int tmpOdd = sOdd(tmpTotal);
		tmpTotal -= sum;
		
		
		sum += tmpTotal;
		odd += tmpOdd; 
	}
	return total + odd;
	
}

int main(){
	int A, B;

	cin >> A >> B;
    int oddA = countOdd(A-1);
    int evenA = A-1 - oddA; 
    if(evenA < 0) evenA = 0;

	int oddB = countOdd(B);
    int evenB = B - oddB;     
    if(evenB < 0) evenB = 0;
    
    cout << oddB-oddA << " " << evenB-evenA << endl;
    // int oddB = countOdd(B);

    // int evenA = countEven(A);
    // int evenB = countEven(B);
    return 0;
}