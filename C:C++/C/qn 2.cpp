#include <iostream>

int main(){
    for (int i=5;i>=1;i--){
        for (int j=i-1;j>=0;j--){
            std::cout << static_cast<char>('e'-j);
        }
        std::cout << "*";
        if(i<5){
            for(int j=i+1;j<=5;j++){
                std::cout << "**";
            }
        }
        for (int k=0;k<i;k++){
            std::cout << static_cast<char>('e'-k);
        }
        std::cout << std::endl;
    }
    return 0;
}