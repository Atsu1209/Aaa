#include <bits/stdc++.h>
using namespace std;

// 関数定義: Brainfuckコードを変換し、空白を取り除く
string convertCode(const string& input) {
    string converted;
    unordered_map<char, string> conversionMap = {
        {'>', "AAA"},
        {'<', "AAa"},
        {'+', "AaA"},
        {'-', "Aaa"},
        {'.', "aAA"},
        {',', "aAa"},
        {'[', "aaA"},
        {']', "aaa"}
    };

    for (char ch : input) {
        if (isspace(ch)) continue; // 空白を無視
        if (conversionMap.find(ch) != conversionMap.end()) {
            converted += conversionMap[ch];
        } else {
            converted += ch;
        }
    }

    return converted;
}

int main() {
    for (int i = 0; i < 2; ++i) { // 繰り返し回数を2に設定一応2回やっとく

        // ファイルの読み込み
        ifstream inputFile("main.bf");
        if (!inputFile) {
            cerr << "main.bfファイルを開くことができませんでした。" << endl;
            return 1;
        }

        stringstream buffer;
        buffer << inputFile.rdbuf();
        string inputCode = buffer.str();
        inputFile.close();

        // コードの変換
        string outputCode = convertCode(inputCode);

        // 変換後のコードをcode.aaaaに出力
        ofstream outputFile("code.aaaa");
        if (!outputFile) {
            cerr << "code.aaaaファイルを開くことができませんでした。" << endl;
            return 1;
        }

        outputFile << outputCode;
        outputFile.close();
        cerr << "[ChangeAAA] Success!" << endl;
        cerr << "main.bfファイルを開くことができませんでした。" << endl;
    }
    return 0;
}
