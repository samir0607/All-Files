#include<iostream>
using namespace std;

void pattern1(int n){
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      cout << "* ";
    }
    cout << endl;
  }
}
void pattern2(int n){
  for(int i = 0; i<n; i++){
    for(int j = 0; j<=i; j++){
      cout << "* ";
    }
    cout << endl;
  }
}
void pattern3(int n){
  for(int i = 1; i<=n; i++){
    for(int j = 0; j<n; j++){
      cout << i << " ";
    }
    cout << endl;
  }
}
void pattern4(int n){
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=i; j++){
      cout << j << " ";
    }
    cout << endl;
  }
}
void pattern5(int n){
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=i; j++){
      cout << i << " ";
    }
    cout << endl;
  }
}
void pattern6(int n){
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n-i+1; j++){
      cout << "* ";
    }
    cout << endl;
  }
}
void pattern7(int n){
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n-i+1; j++){
      cout << j << " ";
    }
    cout << endl;
  }
}
void pattern8(int n){
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n-i+1; j++){
      cout << i << " ";
    }
    cout << endl;
  }
}
void pattern9(int n){
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n-i-1; j++){
      cout << " ";
    }
    for(int j = 0; j< 2*i+1; j++){
      cout << "*";
    }
    for(int j = 0; j<n-i-1; j++){
      cout << " ";
    }
    cout << endl;
  }
}
void pattern10(int n){
  for(int i = 0; i<n; i++){
    for(int j = 0; j<i; j++){
      cout << " ";
    }
    for(int j = 0; j< 2*(n-i)-1; j++){
      cout << "*";
    }
    for(int j = 0; j<i; j++){
      cout << " ";
    }
    cout << endl;
  }
}
void pattern11(int n){
  pattern9(n);
  pattern10(n);
}
void pattern12(int n){
  for(int i = 1; i<=n; i++){
    int stars=i;
    if(i>n) stars = 2*n-i;
    for(int j = 0; j<stars; j++){
      cout<<"* ";
    }
    cout<<endl;
  }
}
void pattern13(int n){
  int start=1;
  for(int i = 1; i<=n; i++){ 
    if(i%2==0) start = 0;
    else start=1;
    for(int j = 0; j < i; j++){
      cout << start;
      start = 1 - start;
    }
    cout<<endl;
  }
}
void pattern14(int n){
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=i; j++){
      cout << j;
    }
    for(int j = 0; j<2*(n-i); j++){
      cout << " ";
    }
    for(int j = 1; j<=i; j++){
      cout << i-j+1;
    }
    cout << endl;
  }
}
void pattern15(int n){
  int num = 1;
  for(int i = 1; i<=n ;i++){
    for(int j = 1; j<=i ; j++){
      cout<< num++;
    }
    cout<<endl;
  }
}
void pattern16(int n){
  for(int i = 0; i<n ;i++){
    for(char j = 'A'; j<= 'A' + i ; j++){
      cout<< j;
    }
    cout<<endl;
  }
}
void pattern17(int n){
  for(int i = 0; i<n ;i++){
    for(char j = 'A'; j< 'A' + n - i ; j++){
      cout<< j;
    }
    cout<<endl;
  }
}
void pattern18(int n){
  for(char i = 'A'; i < 'A' + n  ;i++){
    for(int j = 0; j <= i - 'A' ; j++){
      cout<< i;
    }
    cout<<endl;
  }
}
void pattern19(int n){
  for(int i = 0; i < n ;i++){
    for(int j = 1; j < n-i; j++){
      cout << " ";
    }
    for(char j = 'A'; j< 'A' + i ; j++){
      cout<< j;
    }
    for(char j = 'A' + i; j >= 'A' ; j--){
      cout<< j;
    }
    cout<<endl;
  }
}
void pattern20(int n){
  for(int i = 1; i <= n ;i++){
    for(char j = 'E' - i; j < i; j++){
      cout<< j;
    }
    cout<<endl;
  }
}


int main(){
  int t = 5;
  for(int i = 3; i<=t; i++){
    pattern20(i);
  }
  return 0;
}