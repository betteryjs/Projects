//
// Created by yjs on 23-3-29.
//
#include <iostream>
#include <bitset>
#include <algorithm>


using namespace std;


bitset<4> reverse(bitset<4> res){

}

static unsigned long rev(unsigned long v) {
    unsigned long s = 8 * sizeof(v); // bit size; must be power of 2
    unsigned long mask = ~0;
    while ((s >>= 1) > 0) {
        mask ^= (mask << s);
        v = ((v >> s) & mask) | ((v << s) & ~mask);
    }
    return v;
}


int main(){
    const int number=4;
    bitset<number> v{"0011"};
    bitset<number> mask{"011"};
    cout << v.to_ulong()<<endl;
    cout << rev(3)<<endl;


    Projects

    return 0;
}


