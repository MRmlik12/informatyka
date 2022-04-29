#include <iostream>
#include <string>

int main() {
  std::string w;
  std::cin >> w;

  int l = w.length();
  int y = l - 1;
  std::string palindrom = "";
  
  for (int x = 0; x < l; x++) {
    if (w[x] == w[y]) {
      palindrom += w[x];
    }

    y--;
  }

  if (w != palindrom) {
    std::cout << "Nie jest palindromem" << std::endl;
    return 0;
  }

  std::cout << "Jest palindromem" << std::endl;
} 