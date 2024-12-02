#include "common.h"


class Solution {
public:
struct Couple {
    int index;
    int size;
};
vector<string> alpha = {"abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
    Couple func( string digits, vector<string>& vec, int beg) {
        int act = (int)(digits[beg] - '2'); 
        string ss  = alpha[act];
        if (beg == digits.size()-1) {
            int index = vec.size() - 1;
            for (int i = 0; i < ss.size(); ++i) {
                string t = " ";
                t[0] = ss[i];
                vec.push_back(t);
                ++index;
            }
            return {index, (int)ss.size()};
        }

        Couple outCpl;
        outCpl.size = 0;
        outCpl.index = vec.size() - 1;
        for (int i = 0; i < alpha[act].size(); ++i) {
            Couple cpl = func(digits, vec, beg + 1);
            string cur   = " ";
            cur[0]       = alpha[act][i];
            for (int j = cpl.index - cpl.size+1; j < cpl.index+1; j++) {
                vec[j] = cur + vec[j] ;
                outCpl.index++;
            }
            outCpl.size += cpl.size;
        }

        return outCpl;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() < 1) return {};
        func(digits,result,0);
        return result;
    }
};
