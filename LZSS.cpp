#include "LZSS.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

int Encode()
{
  std::string input
  {
    std::istreambuf_iterator<char>(std::cin.rdbuf()),
    std::istreambuf_iterator<char>()
  };

  LZSS::Encoded encoded = LZSS::Encode(input);
  std::cout << encoded;

  return 0;
}

int Decode()
{
  LZSS::Encoded encoded;
  std::cin >> encoded;
  std::cout << LZSS::Decode(encoded);

  return 0;
}

int main(int argc, char** argv)
{
  if(argc > 1)
  {
    if(argv[1] != "-d" || argc > 2)
    {
      std::cout << "Progam reads from stdin and writes to stdout.\n";
      std::cout << "Usage (encode): cat myfile.txt | " << argv[0] << " > myfile.lzss\n";
      std::cout << "Usage (decode): cat myfile.lzss | " << argv[0] << " -d > myfile.lzss\n";
      return -1;
    }

    return Decode();
  }

  return Encode();
}
