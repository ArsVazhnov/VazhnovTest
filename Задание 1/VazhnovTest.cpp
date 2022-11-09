#include <map>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char asciiToLower(char in)
{
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

int main()
{
  string word;
  string result;
  map<char, int> charMap;

  getline(cin, word);
  transform(word.begin(), word.end(), word.begin(), asciiToLower);

  for (int i = 0; i < word.length(); i++)
  {
    charMap[word[i]] = 0;
  }

  for (int i = 0; i < word.length(); i++)
  {
    charMap[word[i]] += 1;
  }

  for (int i = 0; i < word.length(); i++)
  {
    if (charMap[word[i]] > 1)
    {
      result.append(")");
    }
    if (charMap[word[i]] == 1)
    {
      result.append("(");
    }
  }

  cout << result;

  return 0;
}