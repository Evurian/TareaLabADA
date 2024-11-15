#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> slumpMemo;
unordered_map<int, bool> slimpMemo;

// Función para verificar si una subcadena desde 'pos' es un Slump
bool isSlump(const string &s, int &pos) {
    if (slumpMemo.count(pos)) return slumpMemo[pos];
    int startPos = pos;

    if (s[pos] != 'D' && s[pos] != 'E') return slumpMemo[startPos] = false;
    pos++;
    
    if (s[pos] != 'F') return slumpMemo[startPos] = false;
    while (s[pos] == 'F') pos++;
    
    if (s[pos] == 'G') {
        pos++;
        return slumpMemo[startPos] = true;
    } else {
        bool result = isSlump(s, pos);
        return slumpMemo[startPos] = result;
    }
}

// Función para verificar si una subcadena desde 'pos' es un Slimp
bool isSlimp(const string &s, int &pos) {
    if (slimpMemo.count(pos)) return slimpMemo[pos];
    int startPos = pos;

    if (s[pos] != 'A') return slimpMemo[startPos] = false;
    pos++;
    
    if (s[pos] == 'H') {
        pos++;
        return slimpMemo[startPos] = true;
    }
    
    if (s[pos] == 'B') {
        pos++;
        if (!isSlimp(s, pos)) return slimpMemo[startPos] = false;
        if (s[pos] == 'C') {
            pos++;
            return slimpMemo[startPos] = true;
        }
    } else if (isSlump(s, pos)) {
        if (s[pos] == 'C') {
            pos++;
            return slimpMemo[startPos] = true;
        }
    }
    return slimpMemo[startPos] = false;
}

// Función para verificar si una cadena es un Slurpy
bool isSlurpy(const string &s) {
    int pos = 0;
    slimpMemo.clear();
    slumpMemo.clear();
    if (!isSlimp(s, pos)) return false;
    if (!isSlump(s, pos)) return false;
    return pos == s.size();
}

int main() {
    int N;
    cin >> N;
    cout << "SLURPYS OUTPUT" << endl;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (isSlurpy(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    cout << "END OF OUTPUT" << endl;
    return 0;
}
