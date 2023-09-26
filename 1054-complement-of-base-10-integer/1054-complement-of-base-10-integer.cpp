class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) {
            return 1;
        }

        int mask = 1;
        while(mask <= n) {
            n = n ^ mask;
            mask = mask << 1;
        }

        return n;
    }
};

/*

5 -> 101
2 -> 010
return 2;

Use XOR operation

*/