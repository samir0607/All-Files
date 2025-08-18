#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

string encrypt(string text, int s) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
		if(isupper(text[i]))
            result += (text[i] + s - 'A') % 26 + 'A';
		else
		    result += (text[i] + s - 'a') % 26 + 'a';
    }
	
    return result;
}

string decrypt(string text, int s) {
	string result = "";
	for(int i = 0; i< text.length(); i++) {
		if (isupper(text[i]))
			result += (text[i] - s - 'A' + 26) % 26 + 'A';
		else
			result += (text[i] - s - 'a' + 26) % 26 + 'a';
	}
	return result;
}

void findKey(string encrypted) {
	for(int i = 0; i<=26; i++) {
		cout<<"\nText: "<< decrypt(encrypted,i) << " Key: " <<i;
	}
}

int main()
{
    string text; 
	cout<<"Enter Text: ";
	cin>>text;
    int s; 
	cout<<"Shifts: ";
	cin>>s;
    // cout << "Text : " << text;
    // cout << "\nShift: " << s;
	string encrypted = encrypt(text, s);
    cout << "\nCipher: " << encrypted;

	string decrypted = decrypt(encrypted, s);
    cout << "\nDecrypted: " << decrypted;

	findKey(encrypted);
    return 0;
}