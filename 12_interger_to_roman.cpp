#include "common.h"

class Solution {
public:
    int t0[7]     = {1,10,100,1000};
    string t1[7]  = {"I", "V", "X", "L", "C", "D", "M"};
    void append(string& in, string& ext, int n) {
         for (int j = 0; j < n; j++) in += ext;
    }

    string intToRoman(int num) {
        int m = num;
        int q = 0;
        int r = 0;
        string res = "";
        for (int i = 3; i != -1; i--) {
            q = m / t0[i];
            if (q == 0)
                continue;
            r = m % t0[i];
            int e = 2*i;
            if (q <= 3) 
                append(res,t1[e],q);
            else if (q <= 5) {
                append(res,t1[e],5-q);
                res += t1[e+1];
            }
            else if (q <= 8) {
                res += t1[e+1];
                append(res,t1[e],q-5);
            }
            else {
                append(res,t1[e],10-q);
                res += t1[e+2];
            }
            m = r;
        }
        return res;
    }
};
