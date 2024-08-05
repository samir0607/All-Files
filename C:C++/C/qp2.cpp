#include <iostream>
#include <fstream>
#include <vector>
struct RGBColor {
    unsigned char r, g, b;
};
int main() {
    std::ifstream inputFile("Photo.jpeg", std::ios::binary);
    if (!inputFile) {
        std::cout << "Could not open or find the image." << std::endl;
        return -1;
    }
    int width = 0, height = 0;
    inputFile.read(reinterpret_cast<char*>(&width), sizeof(int));
    inputFile.read(reinterpret_cast<char*>(&height), sizeof(int));
    std::vector<RGBColor> imagePixels(width * height);
    inputFile.read(reinterpret_cast<char*>(imagePixels.data()), sizeof(RGBColor) * width * height);
    int totalPixels = width * height;
    int totalRed = 0, totalGreen = 0, totalBlue = 0;
    for (const RGBColor& pixel : imagePixels) {
        totalRed+=pixel.r;
        totalGreen+=pixel.g;
        totalBlue+=pixel.b;
    }
    unsigned char avgRed = static_cast<unsigned char>(totalRed/totalPixels);
    unsigned char avgGreen = static_cast<unsigned char>(totalGreen/totalPixels);
    unsigned char avgBlue = static_cast<unsigned char>(totalBlue/totalPixels);
    std::cout << "Average Color: R=" << static_cast<int>(avgRed)
              << " G=" << static_cast<int>(avgGreen)
              << " B=" << static_cast<int>(avgBlue) << std::endl;
    return 0;
}
