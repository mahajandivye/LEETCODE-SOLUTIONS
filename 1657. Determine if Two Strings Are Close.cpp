class Solution {
public:

    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        map<char , int> mpp1;
        map<char , int> mpp2;
        if(n1 != n2)return false;
        for(int i=0;i<n1;i++)
        {
            mpp1[word1[i]]++;
        }
        for(int i=0;i<n2;i++)
        {
            mpp2[word2[i]]++;
        }
        multiset<int> st1;
        multiset<int> st2;
        auto it1 = mpp1.begin();
        auto it2 = mpp2.begin();
        for(it1 , it2;it1 != mpp1.end() && it2 != mpp2.end();it1++ , it2++)
        {
            if(mpp2.find(it1->first) == mpp2.end())return false;
            st1.insert(it1->second);
            st2.insert(it2->second);
        }
        auto it11 = st1.begin();
        auto it22 = st2.begin();
        for(it11 , it22;it11 != st1.end() , it22 != st2.end();it11++ , it22++)
        {
            if(*it11 != *it22)return false;
        }
        return true;
    }
};