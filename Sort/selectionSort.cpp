#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{ 5, 4, 3, 2, 1 };

    for (int i = 0; i < v.size() - 1; i++) 
    {
        int min = i;
        for (int j = i + 1; j < v.size(); j++) 
        {
            if (v[i] > v[j]) min = j;
        }
        std::swap(v[i], v[min]);
    }

    for (auto num : v) std::cout << num << " ";
}