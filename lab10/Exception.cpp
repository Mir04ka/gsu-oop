#include "Exception.h"

Exception::Exception(string message, float badArgument) {
    this->message = message;
    this->badArgument = badArgument;
}

Exception::~Exception() {}

string Exception::getMessage() const {
    return message;
}

float Exception::getBadArgument() const {
    return badArgument;
}