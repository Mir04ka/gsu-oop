#ifndef GSU_OOP_EXCEPTION_H
#define GSU_OOP_EXCEPTION_H
#include <string>

using namespace std;

class Exception {
  private:
    string message;
    float badArgument;
  public:
    Exception(string message, float badArgument);
    ~Exception();

    string getMessage() const;
    float getBadArgument() const;
};

#endif //GSU_OOP_EXCEPTION_H