#include <bits/stdc++.h>
using namespace std;

using ull = uint64_t;

const int IP[64] = {
    58,50,42,34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,
    64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,
    59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,
    63,55,47,39,31,23,15,7
};

const int FP[64] = {
    40,8,48,16,56,24,64,32,
    39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30,
    37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28,
    35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26,
    33,1,41,9,49,17,57,25
};

const int E[48] = {
    32,1,2,3,4,5,
    4,5,6,7,8,9,
    8,9,10,11,12,13,
    12,13,14,15,16,17,
    16,17,18,19,20,21,
    20,21,22,23,24,25,
    24,25,26,27,28,29,
    28,29,30,31,32,1
};

const int P[32] = {
    16,7,20,21,29,12,28,17,
    1,15,23,26,5,18,31,10,
    2,8,24,14,32,27,3,9,
    19,13,30,6,22,11,4,25
};

const int PC1[56] = {
    57,49,41,33,25,17,9,
    1,58,50,42,34,26,18,
    10,2,59,51,43,35,27,
    19,11,3,60,52,44,36,
    63,55,47,39,31,23,15,
    7,62,54,46,38,30,22,
    14,6,61,53,45,37,29,
    21,13,5,28,20,12,4
};

const int PC2[48] = {
    14,17,11,24,1,5,
    3,28,15,6,21,10,
    23,19,12,4,26,8,
    16,7,27,20,13,2,
    41,52,31,37,47,55,
    30,40,51,45,33,48,
    44,49,39,56,34,53,
    46,42,50,36,29,32
};

const int SHIFT[16] = {
    1,1,2,2,2,2,2,2,
    1,2,2,2,2,2,2,1
};

const int S[8][4][16] = {
{
 {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
 {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
 {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
 {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
},
{
 {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
 {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
 {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
 {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
},
{
 {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
 {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
 {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
 {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
},
{
 {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
 {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
 {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
 {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
},
{
 {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
 {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
 {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
 {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
},
{
 {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
 {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
 {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
 {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
},
{
 {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
 {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
 {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
 {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
},
{
 {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
 {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
 {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
 {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
}
};

// Generic permutation.
// Table positions are numbered from 1, as in DES.
ull permute(ull input, const int table[], int outBits, int inBits) {
    ull output = 0;

    for (int i = 0; i < outBits; i++) {
        output <<= 1;
        output |= (input >> (inBits - table[i])) & 1ULL;
    }

    return output;
}

string toBinary(ull x, int bits) {
    string ans = "";

    for (int i = bits - 1; i >= 0; i--) {
        ans += ((x >> i) & 1ULL) ? '1' : '0';
    }

    return ans;
}

ull rotate28(ull x, int shift) {
    x &= 0x0FFFFFFF;

    return ((x << shift) | (x >> (28 - shift)))
           & 0x0FFFFFFF;
}

// Generate all 16 round keys.
vector<ull> generateKeys(ull key) {
    ull k = permute(key, PC1, 56, 64);

    ull C = (k >> 28) & 0x0FFFFFFF;
    ull D = k & 0x0FFFFFFF;

    vector<ull> keys;

    for (int i = 0; i < 16; i++) {
        C = rotate28(C, SHIFT[i]);
        D = rotate28(D, SHIFT[i]);

        ull combined = (C << 28) | D;
        ull roundKey = permute(combined, PC2, 48, 56);

        keys.push_back(roundKey);
    }

    return keys;
}

// DES S-box substitution: 48 bits -> 32 bits.
ull sboxSubstitution(ull input) {
    ull output = 0;

    for (int i = 0; i < 8; i++) {
        int chunk = (input >> (42 - 6 * i)) & 63;

        int row = ((chunk & 32) >> 4) | (chunk & 1);
        int col = (chunk >> 1) & 15;

        int value = S[i][row][col];

        output = (output << 4) | value;
    }

    return output;
}

// DES round function: 32 bits -> 32 bits.
ull roundFunction(ull R, ull key) {
    ull expanded = permute(R, E, 48, 32);

    ull mixed = expanded ^ key;

    ull substituted = sboxSubstitution(mixed);

    return permute(substituted, P, 32, 32);
}

// Perform one DES round on already-split L and R.
pair<ull, ull> oneRound(ull L, ull R, ull key) {
    ull newL = R;
    ull newR = L ^ roundFunction(R, key);

    return {newL, newR};
}

// Encrypt or decrypt one 64-bit block.
ull DES(ull block, ull key, bool decrypt) {
    vector<ull> keys = generateKeys(key);

    if (decrypt) {
        reverse(keys.begin(), keys.end());
    }

    ull data = permute(block, IP, 64, 64);

    ull L = (data >> 32) & 0xFFFFFFFF;
    ull R = data & 0xFFFFFFFF;

    for (int i = 0; i < 16; i++) {
        auto result = oneRound(L, R, keys[i]);

        L = result.first;
        R = result.second;
    }

    // DES uses R16 || L16 before the final permutation.
    ull combined = (R << 32) | L;

    return permute(combined, FP, 64, 64);
}

string toHex(ull x) {
    stringstream ss;

    ss << uppercase << hex << setw(16)
       << setfill('0') << x;

    return ss.str();
}

ull readHex(string s) {
    return stoull(s, nullptr, 16);
}

int main() {
    int choice;

    cout << "===== DES LAB PROGRAMS =====\n";
    cout << "1. General P-box\n";
    cout << "2. Initial and Final Permutation\n";
    cout << "3. Generate 16 Round Keys\n";
    cout << "4. S-box Substitution\n";
    cout << "5. DES Round Function\n";
    cout << "6. One DES Round\n";
    cout << "7. DES Encryption\n";
    cout << "8. DES Decryption\n";
    cout << "9. Encrypt and Decrypt Verification\n";
    cout << "10. Double DES\n";
    cout << "11. Triple DES (EDE)\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        int n, m;

        cout << "Enter input bit count: ";
        cin >> n;

        string bits;
        cout << "Enter binary input: ";
        cin >> bits;

        if ((int)bits.size() != n || n > 64) {
            cout << "Invalid input length\n";
            return 0;
        }

        ull input = stoull(bits, nullptr, 2);

        cout << "Enter output bit count: ";
        cin >> m;

        vector<int> table(m);

        cout << "Enter " << m << " table positions:\n";
        for (int i = 0; i < m; i++) {
            cin >> table[i];

            if (table[i] < 1 || table[i] > n) {
                cout << "Invalid table position\n";
                return 0;
            }
        }

        cout << "Output: "
             << toBinary(permute(input, table.data(), m, n), m)
             << '\n';
    }

    else if (choice == 2) {
        string text;

        cout << "Enter 64-bit block in hex: ";
        cin >> text;

        ull block = readHex(text);

        ull afterIP = permute(block, IP, 64, 64);
        ull afterFP = permute(afterIP, FP, 64, 64);

        cout << "After IP: " << toHex(afterIP) << '\n';
        cout << "After FP: " << toHex(afterFP) << '\n';
    }

    else if (choice == 3) {
        string text;

        cout << "Enter 64-bit key in hex: ";
        cin >> text;

        vector<ull> keys = generateKeys(readHex(text));

        for (int i = 0; i < 16; i++) {
            cout << "K" << i + 1 << " = "
                 << toHex(keys[i]).substr(4) << '\n';
        }
    }

    else if (choice == 4) {
        string text;

        cout << "Enter 48-bit input in hex: ";
        cin >> text;

        ull input = readHex(text);

        cout << "32-bit output: "
             << hex << uppercase
             << sboxSubstitution(input) << '\n';
    }

    else if (choice == 5) {
        string r, k;

        cout << "Enter 32-bit R in hex: ";
        cin >> r;

        cout << "Enter 48-bit round key in hex: ";
        cin >> k;

        cout << "Round function output: "
             << toHex(roundFunction(readHex(r), readHex(k)))
             << '\n';
    }

    else if (choice == 6) {
        string l, r, k;

        cout << "Enter L in hex: ";
        cin >> l;

        cout << "Enter R in hex: ";
        cin >> r;

        cout << "Enter 48-bit round key in hex: ";
        cin >> k;

        auto result = oneRound(readHex(l), readHex(r), readHex(k));

        cout << "New L: " << toHex(result.first) << '\n';
        cout << "New R: " << toHex(result.second) << '\n';
    }

    else if (choice == 7 || choice == 8) {
        string p, k;

        cout << "Enter 64-bit block in hex: ";
        cin >> p;

        cout << "Enter 64-bit key in hex: ";
        cin >> k;

        ull result = DES(readHex(p), readHex(k), choice == 8);

        cout << "Result: " << toHex(result) << '\n';
    }

    else if (choice == 9) {
        string p, k;

        cout << "Enter plaintext in hex: ";
        cin >> p;

        cout << "Enter key in hex: ";
        cin >> k;

        ull plaintext = readHex(p);
        ull key = readHex(k);

        ull cipher = DES(plaintext, key, false);
        ull recovered = DES(cipher, key, true);

        cout << "Ciphertext: " << toHex(cipher) << '\n';
        cout << "Recovered:  " << toHex(recovered) << '\n';

        if (recovered == plaintext) {
            cout << "Verification successful\n";
        } else {
            cout << "Verification failed\n";
        }
    }

    else if (choice == 10) {
        string p, k1, k2;

        cout << "Enter plaintext in hex: ";
        cin >> p;

        cout << "Enter key 1 in hex: ";
        cin >> k1;

        cout << "Enter key 2 in hex: ";
        cin >> k2;

        ull plaintext = readHex(p);
        ull key1 = readHex(k1);
        ull key2 = readHex(k2);

        ull cipher = DES(DES(plaintext, key1, false),
                         key2, false);

        ull recovered = DES(DES(cipher, key2, true),
                            key1, true);

        cout << "Ciphertext: " << toHex(cipher) << '\n';
        cout << "Recovered:  " << toHex(recovered) << '\n';
    }

    else if (choice == 11) {
        string p, k1, k2, k3;

        cout << "Enter plaintext in hex: ";
        cin >> p;

        cout << "Enter key 1 in hex: ";
        cin >> k1;

        cout << "Enter key 2 in hex: ";
        cin >> k2;

        cout << "Enter key 3 in hex: ";
        cin >> k3;

        ull plaintext = readHex(p);
        ull key1 = readHex(k1);
        ull key2 = readHex(k2);
        ull key3 = readHex(k3);

        // EDE: Encrypt with K1, decrypt with K2, encrypt with K3.
        ull cipher = DES(
            DES(DES(plaintext, key1, false), key2, true),
            key3, false
        );

        ull recovered = DES(
            DES(DES(cipher, key3, true), key2, false),
            key1, true
        );

        cout << "Ciphertext: " << toHex(cipher) << '\n';
        cout << "Recovered:  " << toHex(recovered) << '\n';
    }

    else {
        cout << "Invalid choice\n";
    }

    return 0;
}