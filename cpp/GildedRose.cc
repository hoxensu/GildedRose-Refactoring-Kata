#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}
    
void GildedRose::updateQuality() 
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name == "Sulfuras, Hand of Ragnaros")
        {
            continue;
        }

        if (items[i].name == "Aged Brie")
        {
            updateAgedQuality(items[i]);
        } 
        else if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
        {
            updateBackstageQuality(items[i]);
        }
        else if (items[i].name == "Conjured Mana Cake")
        {
            updateConjuredQuality(items[i]);
        }
        else
        {
            updateNormalQuality(items[i]);
        }
        
        items[i].sellIn = items[i].sellIn - 1;
    }
}
    
void GildedRose::updateNormalQuality(Item & item)
{
    if (item.sellIn <= 0)
    {
        item.quality = item.quality - 2;
    }
    else
    {
        item.quality = item.quality - 1;
    }
    refineQuality(item);
}
    
void GildedRose::updateAgedQuality(Item & item)
{
    item.quality = item.quality + 1;
    refineQuality(item);
}
    
void GildedRose::updateBackstageQuality(Item & item)
{
    if (item.sellIn <= 0)
    {
        item.quality = 0;
    } 
    else if (item.sellIn < 6)
    {
        item.quality = item.quality + 3;
    }
    else if (item.sellIn < 11)
    {
        item.quality = item.quality + 2;
    }
    else
    {
        item.quality = item.quality + 1;
    }
    refineQuality(item);
}
    
void GildedRose::updateConjuredQuality(Item & item)
{
    if (item.sellIn <= 0)
    {
        item.quality = item.quality - 4;
    }
    else
    {
        item.quality = item.quality - 2;
    }
    refineQuality(item);
}

void GildedRose::refineQuality(Item & item)
{
    if (item.quality < 0)
    {
        item.quality = 0;
    }
    else if (item.quality > 50)
    {
        item.quality = 50;
    }
}