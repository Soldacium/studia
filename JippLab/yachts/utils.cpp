#include <regex>

namespace utils {
    bool isValidDateFormat(const std::string& input) {
        std::regex pattern("\\d{4}-\\d{2}-\\d{2}");
        return std::regex_match(input, pattern);
    }
}
