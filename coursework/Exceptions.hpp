#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include <exception>

class SyntaxError: public std::exception {
public:
    explicit SyntaxError(const std::string& reason_):
    reason_(("Syntax error in: " + reason_ +"\n" )) {};

    const char* what() const noexcept override {return reason_.c_str();}
private:
    std::string reason_;
};

class WordIsNotFound: public std::exception{ ;
public:
    explicit WordIsNotFound(const std::string& reason_):
    reason_(("Word:" + reason_ + " doesn't exist\n")){};
    const char* what() const noexcept override{return reason_.c_str();}
private:
    std::string reason_;
};

class EmptyDictionary: public std::exception{
public:
    EmptyDictionary(): reason_("Dictionary is empty\n"){}
    const char *what() const noexcept override {return reason_;}
private:
    const char *reason_;
};
#endif
