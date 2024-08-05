#include <iostream>
int main(){
    for (int i=5;i>=1;i--){
        for (int j=1;j<=i;j++) {
            std::cout << j;
        }
        if(i<5){
            for (int j=i+1;j<=5;j++){
                std::cout << "__";
            }
        }
        for (int k=i;k>=1;k--){
            std::cout << k;
        }
        std::cout << std::endl;
    }
    return 0;
}