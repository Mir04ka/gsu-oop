#ifndef GSU_OOP_EXCEPTION_H
#define GSU_OOP_EXCEPTION_H
#include <string>

using namespace std;

class Exception {
private:
    string message;
public:
    Exception(string message);
    ~Exception();

    string getMessage() const;
};

#endif //GSU_OOP_EXCEPTION_H