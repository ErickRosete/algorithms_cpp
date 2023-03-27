#include <sstream>
#include <iostream>
#include <map>
using namespace std;

string getHint(string secret, string guess) {
    map<char, int> counterSecret;
    map<char, int> counterGuess;
    int bulls = 0;
    int cows = 0;
    for(int i = 0; i < secret.length(); i++){
        cout << secret[i] << endl;
        if(secret[i] == guess[i]){
            bulls++;
        }
        counterGuess[guess[i]]++;
        counterSecret[secret[i]]++;
    }
    map<char, int>::iterator it;
    for(it = counterSecret.begin(); it != counterSecret.end(); it++){
        cows += min(counterGuess[it->first], it->second);
    }
    cows -= bulls;
    
    ostringstream output;
    output << bulls << "A" << cows << "B";
    return output.str();

}

int main()
{
    string s = getHint("1123", "0111");
    cout << s << endl;
}