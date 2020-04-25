#include <iostream>
#include <vector>

int main()
{
  std::vector<int> v{5, 4, 3, 2, 1};

  for (int i = 1; i < v.size(); i++)
  {
    for (int j = i; j >= 0 && v[j] < v[j - 1]; j--)
    {
      std::swap(v[j], v[j - 1]);
    }
  }

  for (auto num : v)
    std::cout << num << " ";
}