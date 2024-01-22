#pragma once
#ifndef OPENFILEERROR_H
#define OPENFILEERROR_H

#include <stdexcept>
#include <string>

class OpenFileError : public std::exception {
public:
    explicit OpenFileError(const std::string& message);

    const char* what() const noexcept override;

private:
    std::string message;
};

#endif // OPENFILEERROR_H