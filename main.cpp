#include <iostream>
#include <string>
#include <vector>

class solution {
  public:
    std::vector<std::vector<int>> isAdditiveNumber(const std::string & num) {
        
    }

  private:
    std::vector<std::vector<int>> grow(const std::string & num, const std::vector<int> & curr) {
        std::vector<std::vector<int>> result;
        if (std::accumulate(curr.begin(), curr.end(), 0, [](size_t i, const std::vector<int> & v){return i+v.size();}) == nums.size())
            result.push_back(curr);
        else {
            std::vector<int> next = getNext(num, curr);
            for (auto & nx : next) {
                
            }
        }
        return result;
    }

    std::vector<int> getNext(const std::string & num, const std::vector<int> & curr) {
        
    }
};
