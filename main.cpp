#include <iostream>
#include <map>

/**
 * @function Check if lines are anagrams.
 * @param [in] line_1 Line to be checked if anagram to line_2.
 * @param [in] line_2 Line to be checked if anagram to line_1.
 * @return true if lines are anagrams.
 */
bool isAnagram(std::string& line_1, std::string& line_2)
{
    std::map<char, int> lineMap;
    std::map<char, int>::iterator it;

    for (char c : line_1)
    {
        it = lineMap.find(c);

        if (it == lineMap.end())
        {
            lineMap.insert(std::make_pair(c, 1));
        }
        else
        {
            it->second++;
        }
    }

    for (char c : line_2)
    {
        it = lineMap.find(c);
        if (it == lineMap.end())
        {
            return false;
        }
        else
        {
            if (it->second > 1) it->second--;
            else lineMap.erase(it);
        }
    }
    if (!lineMap.empty()) return false;
    else return true;
}

int main() {

    std::cout << "Please enter the line 1:\n";
    std::string line_1;
    std::getline(std::cin, line_1);

    std::cout << "Please enter the line 2:\n";
    std::string line_2;
    std::getline(std::cin, line_2);

    if (line_1 == line_2)
    {
        std::cout << "Lines are equal!\n";
    }
    else
    {
        std::cout << "Lines are " << (isAnagram(line_1, line_2) ? "anagrams" : "NOT anagrams") << "\n";
    }

    return 0;
}
