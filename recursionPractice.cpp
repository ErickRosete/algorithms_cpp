#include <iostream>
#include <vector>
using namespace std;

int waysBoard(int n){
    if(n < 0)
        return 0;
    if(n == 1 || n == 0)
        return 1;
    return waysBoard(n-1) + waysBoard(n-4);
}

int possibleBinaryStrings(int n){
    int validBinEndingWithZero = 0;
    int validBinEndingWithOne = 0;
    for(int i=1; i<=n; i++){
        if(i == 1){
            validBinEndingWithOne++;
            validBinEndingWithZero++;
        } else {
            int temp = validBinEndingWithZero;
            validBinEndingWithZero = validBinEndingWithOne + validBinEndingWithZero;
            validBinEndingWithOne = temp;
        }
    }
    return validBinEndingWithOne + validBinEndingWithZero;
}
int recPossibleBinaryStrings(int n){
    if(n == 0)
        return 1;
    if(n == 1)
        return 2;
    return recPossibleBinaryStrings(n-1) + recPossibleBinaryStrings(n-2);
}

int friendPairing(int n){
    if(n==0 || n == 1)
        return 1;
    // alone + pair
    return friendPairing(n-1) + (n-1) * friendPairing(n-2);

}
int power(int num, int pow){
    if(pow == 0)
        return 1;
    return num * power(num, pow-1);
}

int fastPower(int num, int pow){
    if(pow == 0)
        return 1;
    int smallAns = fastPower(num, pow/2);
    smallAns *= smallAns;
    if(pow & 1)
        return num * smallAns;
    return smallAns;
}

void print_one_to_n(int n){
    if(n == 0){
        cout << endl << "Printing from 1 to " << n << endl;
        return;
    }
    print_one_to_n(n-1);
    cout << n << " ";
}
void print_n_to_one(int n){
    if(n == 0){
        return;
    }
    cout << n << " ";
    print_n_to_one(n-1);
}
bool checkSortedVector(vector<int> vect, int cidx){
    if(cidx == vect.size() - 1)
        return true;
    if(vect[cidx] < vect[cidx+1] && checkSortedVector(vect, cidx+1))
        return true;
    return false;
}

bool checkSortedArray(int arr[], int n){
    if(n <= 1){
        return true;
    }
    if(arr[0] < arr[1] && checkSortedArray(arr+1 , n-1))
        return true;
    return false;
}

int fibonnacci(int num){
    if(num == 0 || num == 1)
        return num;
    return fibonnacci(num-1) + fibonnacci(num-2);
}

int factorial(int num){
    if(num == 0)
        return 1;
    return num * factorial(num-1);
}

int main(int argc, char const *argv[])
{   
    factorial(5);
    fibonnacci(5);
    int arr[] = {1,2,3,4,5};
    checkSortedArray(arr, 5);
    vector<int> vect = {1,2,3,4,5};
    checkSortedVector(vect, 0);
    print_n_to_one(5);
    print_one_to_n(5);
    fastPower(2, 3);
    power(2, 3);
    friendPairing(3);
    recPossibleBinaryStrings(3);
    possibleBinaryStrings(3);
    waysBoard(4);
    return 0;
}

