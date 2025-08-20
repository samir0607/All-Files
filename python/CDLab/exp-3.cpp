#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_set>
#include <algorithm>
using namespace std;

unordered_set<string> keywordSet;

void initKeywords() {
    string arr[] = {
        "int","float","double","char","if","else","while","for","do","return",
        "switch","case","break","continue","void","static","struct","class",
        "public","private","protected","const","bool","true","false","namespace",
        "using","include","long","short","signed","unsigned"
    };
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        keywordSet.insert(arr[i]);
    }
}

bool isKeyword(const string &word) {
    return keywordSet.count(word) > 0;
}

bool isOperator(char c) {
    string ops = "+-*/%=<>&|!^";
    return ops.find(c) != string::npos;
}

bool isSpecialSymbol(char c) {
    string symbols = "(){},;[]#";
    return symbols.find(c) != string::npos;
}

bool isNumber(const string &s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

int main() {
    string filename;
    cout << "Enter source filename: ";
    cin >> filename;

    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Error: Cannot open file!\n";
        return 1;
    }

    initKeywords();
    
    string token;
    char c;

    vector<string> foundKeywords, identifiers, constants, operators, symbols;

    while (fin.get(c)) {
        if (isspace(c)) {
            continue; 
        }
        if (isalpha(c) || c == '_') {
            token = c;
            while (fin.peek() != EOF && (isalnum(fin.peek()) || fin.peek() == '_')) {
                token += fin.get();
            }
            if (isKeyword(token)) {
				cout<<token<<" Constant\n";
				foundKeywords.push_back(token);
			}
            else{
				cout<<token<<" Identifier\n";
                identifiers.push_back(token);
			}
        }
        else if (isdigit(c)) {
            token = c;
            while (fin.peek() != EOF && isdigit(fin.peek())) {
                token += fin.get();
            }
			cout<<token<<": Constant\n";
            constants.push_back(token);
        }
        else if (isOperator(c)) {
            string op(1, c);
            if (fin.peek() != EOF) {
                char next = fin.peek();
                string two = op + next;
                if (two == "==" || two == "<=" || two == ">=" || 
                    two == "&&" || two == "||" || two == "!=") {
                    fin.get();
                    op = two;
                }
            }
			cout<<op<<": Operator\n";
            operators.push_back(op);
        }
        else if (isSpecialSymbol(c)) {
			cout<<c<<": Special symbol\n";
            symbols.push_back(string(1, c));
        }
    }

    cout << "\n--- Tokens Found ---\n";
    cout << "Keywords (" << foundKeywords.size() << "):\n ";
    cout << "\n";

    cout << "Identifiers (" << identifiers.size() << "):\n ";
    cout << "\n";

    cout << "Constants (" << constants.size() << "):\n ";
    cout << "\n";

    cout << "Operators (" << operators.size() << "):\n ";
    cout << "\n";

    cout << "Special Symbols (" << symbols.size() << "):\n ";	
    cout << "\n";

    fin.close();
    return 0;
}
