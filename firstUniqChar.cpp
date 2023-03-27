#include <iostream>
#include <map>
using namespace std;

int firstUniqChar(string s) {
    map<char, int> mp;
    map<char, int>::iterator it;

    for(char& c : s) {
        it = mp.find(c);
        if(it == mp.end()) {
            mp[c] = 1;
        } else {
            mp[c] += 1;
        }
    }
    
    for(int i = 0; i < s.length(); i++) {
        if(mp[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int s = firstUniqChar("codingminutes");
    cout << s << endl;
    s = firstUniqChar("aabb");
    cout << s << endl;
    s = firstUniqChar("test");
    cout << s << endl;
}