#include <iostream>
#include <vector>
using namespace std;

void toLowerCase(string &plain) {
    for (char &c : plain) {
        if (c >= 'A' && c <= 'Z')
            c += 32;
    }
}
void removeSpaces(string &plain) {
    string temp;
    for (char c : plain) {
        if (c != ' ')
            temp += c;
    }
    plain = temp;
}

void generateKeyTable(string &key, vector<vector<char> > &keyT) {
    keyT.resize(5, vector<char>(5, 0));
    vector<int> hash(26, 0);

    for (char c : key) {
        if (c != 'j')
            hash[c - 'a'] = 2;
    }
    hash['j' - 'a'] = 1;

    int i = 0, j = 0;
    for (char c : key) {
        if (hash[c - 'a'] == 2) {
            hash[c - 'a'] = 1;
            keyT[i][j++] = c;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }

    for (int k = 0; k < 26; k++) {
        if (hash[k] == 0) {
            keyT[i][j++] = char(k + 'a');
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
}

void search(vector<vector<char> > &keyT, char a, char b, vector<int> &arr) {
    if (a == 'j') a = 'i';
    if (b == 'j') b = 'i';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (keyT[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            }
            if (keyT[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

void encrypt(string &str, vector<vector<char> > &keyT) {
    int n = str.size();
    vector<int> arr(4);
    for (int i = 0; i < n; i += 2) {
        search(keyT, str[i], str[i + 1], arr);

        if (arr[0] == arr[2]) { // same row wali Condition
            str[i] = keyT[arr[0]][(arr[1] + 1) % 5];
            str[i + 1] = keyT[arr[2]][(arr[3] + 1) % 5];
        } 
        else if (arr[1] == arr[3]) { // same column wali Condition
            str[i] = keyT[(arr[0] + 1) % 5][arr[1]];
            str[i + 1] = keyT[(arr[2] + 1) % 5][arr[3]];
        } 
        else { // else rectangle
            str[i] = keyT[arr[0]][arr[3]];
            str[i + 1] = keyT[arr[2]][arr[1]];
        }
    }
}

void decrypt(string &str, vector<vector<char> > &keyT) {
    int n = str.size();
    vector<int> arr(4);

    for (int i = 0; i < n; i += 2) {
        search(keyT, str[i], str[i + 1], arr);

        if (arr[0] == arr[2]) { // same row wali condition
            str[i] = keyT[arr[0]][(arr[1] + 4) % 5];
            str[i + 1] = keyT[arr[2]][(arr[3] + 4) % 5];
        } 
        else if (arr[1] == arr[3]) { // same column wali condition
            str[i] = keyT[(arr[0] + 4) % 5][arr[1]];
            str[i + 1] = keyT[(arr[2] + 4) % 5][arr[3]];
        } 
        else { // else Rectangle Check
            str[i] = keyT[arr[0]][arr[3]];
            str[i + 1] = keyT[arr[2]][arr[1]];
        }
    }
}

int main() {
    string key, str;
    cout << "Enter the key: ";
    getline(cin, key);
    cout << "Enter the plain text: ";
    getline(cin, str);

    removeSpaces(key);
    toLowerCase(key);

    removeSpaces(str);
    toLowerCase(str);

    if (str.size() % 2 != 0)
        str += 'z';

    vector<vector<char> > keyT;
    generateKeyTable(key, keyT);

    string cipher = str;
    encrypt(cipher, keyT);
    cout << "Cipher text: " << cipher << endl;

    string decrypted = cipher;
    decrypt(decrypted, keyT);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}