#include <iostream>
#include <fstream>
#include <string>
#include <vector>

char base64[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', ' ', '.' };

int main(int argc, char const* argv[])
{
    std::ifstream inputFile = std::ifstream("CU_steg.bmp", std::ios::binary);
    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(inputFile), {});

    std::string message = "";
    for (int i = 0; i < 44 * 6; i++)
    {
        message += std::to_string(buffer.at(0x2710 + i * 100) & 0b1);
    }

    std::string decodedMessage = "";
    for (int i = 0; i < 44; i++)
    {
        decodedMessage += base64[std::stoi(message.substr(i * 6, 6), nullptr, 2)];
    }

    std::cout << "Decoded message: " << decodedMessage << std::endl;

    return 0;
}
