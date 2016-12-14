#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>

class solution {
  public:
    std::vector<std::vector<std::string>> isAdditiveNumber(const std::string & num) {
        std::vector<std::vector<std::string>> paths;
        for (size_t len1 = 1; len1 < num.size()-1; len1++) {
            for (size_t len2 = len1+1; len2 < num.size(); len2++) {
                std::vector<std::string> vec;
                vec.push_back(num.substr(0, len1));
                vec.push_back(num.substr(len1, len2-len1));
                auto temp = grow(num, vec);
                if (!temp.empty() && temp.size() > 2)
                    paths.push_back(temp);
            }
        }
        std::for_each(paths.begin(), paths.end(),
                      [](const std::vector<std::string> & v){
                          std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, " "));
                          std::cout << std::endl;
                      });

        return paths;
    }

  private:
    size_t lenOf(const std::vector<std::string> & vec) {
        return std::accumulate(vec.begin(), vec.end(), 0,
                               [](size_t i, const std::string & s){
                                   return i+s.size();
                               });
    }
    
    std::vector<std::string> grow(const std::string & num, const std::vector<std::string> & curr) {
        std::vector<std::string> result;
        if (lenOf(curr) == num.size())
            result = curr;
        else {
     	    std::string next = getNext(num, curr);
	    if (!next.empty()) {
            	auto cpy = curr;
	    	cpy.push_back(next);
		result = grow(num, cpy);
	    }
        }
        return result;
    }
    
    std::string getNext(const std::string & num, const std::vector<std::string> & curr) {
        if (curr.size() < 2)
            return std::string();
        else {
            if (lenOf(curr) == num.size())
                return std::string();
            else {
                size_t start = lenOf(curr);
                int nextint = std::stoi(curr[curr.size()-1])+std::stoi(curr[curr.size()-2]);
                if (num.find(std::to_string(nextint), start) == start)
                    return std::to_string(nextint);
                else
                    return std::string();
            }
        }
    }
};

int main() {
    // std::string num{"112358"};
    std::string num{"199100199"};

    solution soln;
    auto paths = soln.isAdditiveNumber(num);
}
