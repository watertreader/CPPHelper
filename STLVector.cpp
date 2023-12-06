#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct It
{
    std::vector<T>& vec_;
    int pointer_;

    It(std::vector<T>& vec) : vec_{vec}, pointer_{0} {}

    It(std::vector<T>& vec, int size) : vec_{vec}, pointer_{size} {}

    bool operator!=(const It<T>& other) const
    {
        return !(*this == other);
    }

    bool operator==(const It<T>& other) const
    {
        return pointer_ == other.pointer_;
    }

    It& operator++()
    {
        ++pointer_;            
        return *this;
    }

    T& operator*() const
    {
        return vec_.at(pointer_);   
    }
};

template<typename T>
struct Vector
{
    std::vector<T> vec_;

    void push_back(T item)
    {
        vec_.push_back(item);
    };

    It<T> begin()
    {
        return It<T>(vec_);
    }

    It<T> end()
    {
        return It<T>(vec_, vec_.size());
    }
};

int main()
{
  Vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);

  bool first = true;
  for (It<int> it = vec.begin(); it != vec.end(); ++it)
  {
      if (first) //modify container once while iterating
      {
          vec.push_back(4);
          first = false;
      }

      std::cout << *it << '\n'; //print it 
      (*it)++;                  //change it
  }

  for (It<int> it = vec.begin(); it != vec.end(); ++it)
  {
      std::cout << *it << '\n'; //should see changed value
  }
}
