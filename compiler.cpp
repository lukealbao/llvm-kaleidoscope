
#include <string>
#include <iostream>

enum Token {
  tok_eof = -1,

  // keywords
  tok_def = -2,
  tok_extern = -3,

  // primary symbols
  tok_identifier = -4,
  tok_number = -5
};

// Global Variables
static std::string IdentifierStr;
static double NumVal;

int gettok() {
  static int LastChar = ' ';
  bool consumingFloat = (LastChar == '.');

  while (isspace(LastChar))
    LastChar = getchar();

  if (isalpha(LastChar)) {
    IdentifierStr = LastChar;

    while (isalnum((LastChar = getchar())))
      IdentifierStr += LastChar;

    if (IdentifierStr == "def")
      return tok_def;
    if (IdentifierStr == "extern")
      return tok_extern;
    return tok_identifier;
  }

  if (isdigit(LastChar) || (LastChar == '.' && !consumingFloat)) {
    std::string NumStr;

    do {
      if (LastChar == '.')
        consumingFloat = true;

      NumStr += LastChar;
      LastChar = getchar();
    } while (isdigit(LastChar) || (LastChar == '.' && !consumingFloat));

    if (LastChar == '.' && consumingFloat) {
      std::cout << "SyntaxError: Invalid Number: " << NumStr << (char) LastChar << std::endl;
      exit(1);
    }

    NumVal = strtod(NumStr.c_str(), 0); // TODO: What is .c_str()?

    return tok_number;
  }

  // TODO: Just trying multi-block tangling.
  return 0;
}

int main() {
  int last = gettok();
  std::cout << IdentifierStr << std::endl;
  return last;
}
