#ifndef DETAILS_H
#define DETAILS_H

#include <stdexcept>

namespace myExceptions
{

  class ErrorSyntax : public std::exception
  {
  public:
    ErrorSyntax(std::string reason) :
      reason_(reason) {}
    const char* what() const override;
  private:
    std::string reason_;
  };

  class EmptyDictionary : public std::exception
  {
  public:
    EmptyDictionary()
    {
      reason_ = "The dictionary is empty.";
    }
    const char* what() const override;
  private:
    const char* reason_;
  };

  class NoWordFound : public std::exception
  {
  public:
    NoWordFound()
    {
      reason_ = "There are no words containing the prefix to look for.";
    }
    const char* what() const override;
  private:
    const char* reason_;
  };
}

bool isKey(std::string key);
bool isWord(std::string word);
void strlwrWord(std::string&);
int compareKey(std::string, std::string);
void checkFile(std::string name);

#endif
