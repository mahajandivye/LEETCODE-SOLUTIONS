// Complexity
// Time complexity:
// O(N)
// Space complexity:
// O(1)
// Code
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        int i = 0;
        while(index < n)
        {
            int cnt = 0;
            char temp = chars[index];
            chars[i++] = temp;
            while(index < n && chars[index] == temp)
            {
                cnt++;
                index++;
            }
            if(cnt > 1){
            string s = to_string(cnt);
            for(auto &it : s)
            {
                if(i < n)chars[i++] = it;
            }
            }
        }
        chars.resize(i);
        return i;
    }
};