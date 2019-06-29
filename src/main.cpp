#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<class InputIterator>
void _print(InputIterator& i ,input_iterator_tag){
    cout << "this is InputIterator" << endl;
}

template<class BidirectionalIterator>
void _print(BidirectionalIterator& i ,bidirectional_iterator_tag){
    cout << "this is BidirectionalIterator" << endl;
}

template<class RandomAccessIterator>
void _print(RandomAccessIterator i ,random_access_iterator_tag){
    cout << "this is RandomAccessIterator" << endl;
}

template<class InputIterator>
void print(InputIterator i){
    _print(i, typename iterator_traits<InputIterator>::iterator_category());
}

int main(){
    vector<int> vec{123};
    list<int> list;

    print(vec.begin());
    print(list.begin());// 有 BidirectionalIterator 的重载版本使用 BidirectionalIterator， 没有使用 InputIterator 版本

    return 0;
}