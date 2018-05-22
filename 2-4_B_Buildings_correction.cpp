//
// Created by xavier on 18-4-3.
//

#include <iostream>
#include <algorithm>

int n;

struct node{
    int w = 0, s = 0;
    node(){
        int w = 0, s = 0;
    };
}ll[100000];

bool cmp(node a, node b){
    return (a.s + a.w) < (b.s + b.w);
}

int main(){
    long long weight;
    long long pdv;
    while (std::cin >> n){
        weight = 0;
        pdv = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> ll[i].w >> ll[i].s;
        }
        std::sort(ll, ll + n, cmp);
        for (int i = 1; i < n; ++i) {
            weight += ll[i - 1].w;
            if (pdv < weight - ll[i].s) pdv = weight - ll[i].s;
        }
        if (pdv >= 0) std::cout << pdv << std::endl;
        else std::cout << "0" << std::endl;
    }
    return 0;
}
