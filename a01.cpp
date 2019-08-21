#include <iostream>
#include <string>
using namespace std;

// prototype go here
int index (char *p, char needle);
int count_digits (char *pp);

int main() {
    string haystack;
    char needle;

    // Also try different values for the string and character
    haystack = "A quick brown fox (id: 45) jumped over a lazy dog (id: 9)";
    needle = '@';

    int loc, count;
    loc = index(&haystack[0], needle);
    cout << "Loc: " << loc << endl;

    count = count_digits(&haystack[0]);
    cout << "Count: " << count << endl;

    return 0;
}

// functions go here
int index (char *p, char needle) {
  int index = 0;
  while(*p!='\0'){
    index = index + 1;
    if(*p == int(needle)) {
      return index;
    }
    *p++;
  }
  return -1;
}

int count_digits (char*pp) {
  int count = 0;
  while(*pp != '\0'){
    if (*pp >= 48 and *pp <= 57) {
      count = count + 1;
    }
    *pp++;
  }
  return count;
}
