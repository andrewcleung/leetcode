#include <iostream>
#include <unordered_set>

using namespace std;
class RandomizedSet
{
public:
    unordered_set<int> set;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (set.find(val) != set.end()) return false;
        set.insert(val);
        return true;
    }

    bool remove(int val)
    {
        auto k = set.find(val);
        if (k == set.end()) return false;
        set.erase(k);
        return true;
    }

    int getRandom()
    {
        auto r = rand() % set.size();
        auto it = set.begin();
        advance(it, r);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main(int argc, char **argv)
{
    return 0;
}