#include <ranges>
#include <iostream>
int main() {
    for (int x : std::views::iota(1, 5)) std::cout << x << " ";
}
