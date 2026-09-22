#include <string_view>
#include <vector>


std::vector<std::string_view> splitStrToTokens(std::string_view content){
    if (content.back() == '.')
        content.remove_suffix(1);
    std::vector<std::string_view> result;

    size_t startPos = 0;
    size_t endPos = content.find('.');

    while (endPos != std::string_view::npos){
        result.emplace_back(content.data() + startPos, endPos - startPos);

        startPos = endPos + 1;
        endPos = content.find('.', startPos);
    }
    result.emplace_back(content.data() + startPos, content.size() - startPos);

    return result;
}
