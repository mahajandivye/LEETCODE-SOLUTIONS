class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size();
        int n2 = b.size();
        int index1 = n1-1;
        int index2 = n2-1;
        string ans = "";
        int rem = 0;
        while(index1 >= 0 || index2 >=0)
        {
            int sum = 0;
            if(index1 >= 0 && a[index1] == '1') sum += 1;
            if(index2 >= 0 && b[index2] == '1') sum += 1;
            sum += rem;
            if(sum == 2){ans.push_back('0');rem = 1;}
            else if(sum == 3){ans.push_back('1');rem = 1;}
            else if(sum == 1) {ans.push_back('1'); rem = 0;}
            else {ans.push_back('0');rem = 0;}
            index1--;
            index2--;
        }
        if(rem == 1)ans.push_back('1');
        reverse(ans.begin() , ans.end());
        return ans;
    }
};