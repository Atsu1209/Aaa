#include <bits/stdc++.h>
using namespace std;

int main() {

    int mem_size = 100000;
    unsigned int ptr = 0;
    vector<unsigned char> mem(mem_size, 0);
    stack<int> loops;

    ifstream file("code.aaaa");
    stringstream buffer;
    buffer << file.rdbuf();
    string code = buffer.str();
    int len = code.size() / 3;

    for (int prg = 0; prg < len; prg++) {

        string ord = code.substr(prg * 3, 3);

        if (ord == "AAA") ptr = (ptr >= mem_size - 1) ? 0 : ptr + 1;
        if (ord == "AAa") ptr = (ptr <= 0) ? mem_size - 1 : ptr - 1;

        if (ord == "AaA") mem[ptr]++;
        if (ord == "Aaa") mem[ptr]--;

        if (ord == "aAA") putchar(mem[ptr]);
        if (ord == "aAa") mem[ptr] = getchar();

        if (ord == "aaA") {
            if (mem[ptr] != 0) loops.push(prg);
            else {
                int depth = 1;
                while (depth > 0) {
                    prg++;
                    if (code.substr(prg * 3, 3) == "aaA") depth++;
                    if (code.substr(prg * 3, 3) == "aaa") depth--;
                }
            }
        }

        if (ord == "aaa") {
            prg = loops.top() - 1;
            loops.pop();
        }
    }
    putchar('\n');

    return 0; 
}
