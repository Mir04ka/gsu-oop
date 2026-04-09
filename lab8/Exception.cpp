#include "Exception.h"

Exception::Exception(string message) {
    this->message = message;
}

Exception::~Exception() {}

string Exception::getMessage() const {
    return message;
}