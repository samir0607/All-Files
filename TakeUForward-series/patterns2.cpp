#include <iostream>
using namespace std;

void pattern14(int N)
{
  for(int i=0;i<N;i++){
    // Inner loop will loop for i times and
    // print alphabets from A to A + i.
    for(char ch = 'A'; ch<='A'+i;ch++){
      cout<<ch<<" ";
    }
    cout<<endl;
  }
}
void pattern15(int N)
{
  for(int i=0;i<N;i++){
    // Inner loop will loop for i times and
    // print alphabets from A to A + i.
    for(char ch = 'A'; ch<='A'+(N-1-i);ch++){
      cout<<ch<<" ";
    }
    cout<<endl;
  }
}
void pattern16(int N)
{
  for(char ch = 'A'; ch<'A'+N;ch++){
    // Inner loop will loop for i times and
    // print alphabets from A to A + i.
    for(int j = 0; j<=ch-'A'; j++){
      cout<<ch<<" ";
    }
    cout<<endl;
  }
}
void pattern17(int N){
  for(int i=0;i<N;i++){
    for(int j=0;j<N-i-1;j++){
      cout<<" ";
    }
    
    // for printing the characters.
    char ch = 'A';
    int breakpoint = (2*i+1)/2;
    for(int j=1;j<=2*i+1;j++){
      cout<<ch;
      if(j <= breakpoint) ch++;
      else ch--;
    }
    
    // for printing the spaces again after characters.
    for(int j=0;j<N-i-1;j++){
      cout<<" ";
    }
  }
}

int main()
{   
    int N = 5;
    pattern16(N);

    return 0;
}