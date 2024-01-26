#include <iostream>
#include <fstream>
#include <json/json.h>

#include "error.h"

namespace errors {
    OpenFileError::OpenFileError(const std::string& message) : message(message) {}

    const char* OpenFileError::what() const noexcept {
        return message.c_str();
    }

    UserInputError::UserInputError(const std::string& message) : message(message) {}

    const char* UserInputError::what() const noexcept {
        return message.c_str();
    }
}
