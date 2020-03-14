#include <string>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
};

class GildedRose
{
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    
    void updateQuality();

private:
    void updateNormalQuality(Item & item);
    void updateAgedQuality(Item & item);
    void updateBackstageQuality(Item & item);
    void updateConjuredQuality(Item & item);
    void refineQuality(Item & item);
};

