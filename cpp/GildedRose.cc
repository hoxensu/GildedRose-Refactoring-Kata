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
            items[i].quality = items[i].quality + 1;
        } 
        else if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
        {
            if (items[i].sellIn <= 0)
            {
                items[i].quality = 0;
            } 
            else if (items[i].sellIn < 6)
            {
                items[i].quality = items[i].quality + 3;
            }
            else if (items[i].sellIn < 11)
            {
                items[i].quality = items[i].quality + 2;
            }
            else
            {
                items[i].quality = items[i].quality + 1;
            }
        }
        else if (items[i].name == "Conjured Mana Cake")
        {
            if (items[i].quality <= 0)
            {
                items[i].quality = items[i].quality - 4;
            }
            else
            {
                items[i].quality = items[i].quality - 2;
            }
        }
        else
        {
            if (items[i].quality <= 0)
            {
                items[i].quality = items[i].quality - 2;
            }
            else
            {
                items[i].quality = items[i].quality - 1;
            }
        }
        
        if (items[i].quality < 0)
        {
            items[i].quality = 0;
        }
        else if (items[i].quality > 50)
        {
            items[i].quality = 50;
        }
        
        items[i].sellIn = items[i].sellIn - 1;
    }
}
