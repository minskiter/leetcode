#include "header.h"

class LRUCache
{
private:
    int _capacity;                                           // 容量
    int _size;                                               // 实际大小
    list<pair<int, int>> _list;                              // 双端链表
    unordered_map<int, list<pair<int, int>>::iterator> _pos; // 位置hash

public:
    LRUCache(int capacity) : _size(0), _capacity(capacity)
    {
    }

    int get(int key)
    {
        if (_pos.find(key) == _pos.end())
            return -1;
        // 变更链表位置
        auto itor = _pos[key];
        _list.emplace_back(itor->first, itor->second);
        _list.erase(itor);
        _pos[key] = prev(_list.end());
        return _pos[key]->second;
    }

    void put(int key, int value)
    {
        if (_pos.find(key) != _pos.end())
        {
            auto itor = _pos[key];
            _list.emplace_back(itor->first, value);
            _list.erase(itor);
            _pos[key] = prev(_list.end());
            return;
        }
        if (_size < _capacity)
        {
            ++_size;
            _list.emplace_back(key, value);
            _pos[key] = prev(_list.end());
        }
        else
        {
            _pos.erase(_list.begin()->first);
            _list.pop_front();
            _list.emplace_back(key, value);
            _pos[key] = prev(_list.end());
        }
    }
};

int main()
{
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache.get(1) << endl;    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache.get(2) << endl;    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache.get(1) << endl;   // 返回 -1 (未找到)
    cout << lRUCache.get(3) << endl;    // 返回 3
    cout << lRUCache.get(4) << endl;    // 返回 4
    return 0;
}