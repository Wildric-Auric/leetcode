#include "common.h"

struct Triplet {
public:
    int a = 0;
    int b = 0;
    int c = 0;

};
struct Cmp
{
   bool operator() (const Triplet& lhs, const Triplet& rhs) const
   {
      return (lhs.a < rhs.a) || 
               (lhs.a == rhs.a && lhs.b < rhs.b) || 
               (lhs.a == rhs.a && lhs.b == rhs.b && lhs.c < rhs.c);
    }
   
};



class Solution {
public:
    void swap(int& a, int& b) {
        int t = a;
        a=b;
        b=t;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        //std::vector<unordered_map<int, char>> mapps(nums.size());
        unordered_map<int, char> mapp;
        
        map<Triplet, char, Cmp> un;
        Triplet t;
        int target = 0;

        auto ttt = un.end();
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i]!=nums[0]) goto label;
        }
        if (nums[0] == 0)
            return {{0,0,0}};
        return {};
        label:
        for ( i = 0; i < nums.size(); ++i) {
            target = nums[i];
            mapp.clear();
            for ( j = i+1; j < nums.size(); ++j) {
                if (j == i) continue;
                int s = nums[j] + target;
                auto f = mapp.find(-s) ;
                if ( f == mapp.end()) {
                    mapp.insert(make_pair(nums[j], 1 ));
                    continue;
                }
                t = {nums[j],target,f->first};
                if (t.a > t.c)  swap(t.a, t.c);
                if (t.a > t.b)  swap(t.a, t.b);
                if (t.b > t.c)  swap(t.b, t.c);
                mapp.insert(make_pair(nums[j], 1 ));
                ttt = un.find(t);
                if (ttt != un.end()) continue;
                un.insert(make_pair(t,0 ));
                res.push_back({t.a,t.b,t.c});   
            }
        }
        return res;
    }
};
