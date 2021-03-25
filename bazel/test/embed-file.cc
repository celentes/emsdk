#include <fstream>
#include <streambuf>
#include <cstdlib>

int main(int argc, char** argv) {
  std::ifstream fox("test/fox.txt");
  std::string out((std::istreambuf_iterator<char>(fox)),
                  std::istreambuf_iterator<char>());

  std::string expected("The quick brown fox jumps over the lazy dog\n");
  if (out == expected) {
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}
