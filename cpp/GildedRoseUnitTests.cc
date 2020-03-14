#include <gtest/gtest.h>

#include "GildedRose.h"

TEST(GildedRoseTest, NormalItem) {
    vector<Item> items;
    items.push_back(Item("+5 Dexterity Vest", 0, 0));
    items.push_back(Item("+5 Dexterity Vest", 0, 1));
    items.push_back(Item("+5 Dexterity Vest", 0, 2));
    items.push_back(Item("+5 Dexterity Vest", 0, 3));
    items.push_back(Item("+5 Dexterity Vest", 1, 0));
    items.push_back(Item("+5 Dexterity Vest", 1, 1));
    items.push_back(Item("+5 Dexterity Vest", 1, 2));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(0, app.items[0].quality);
    EXPECT_EQ(0, app.items[1].quality);
    EXPECT_EQ(0, app.items[2].quality);
    EXPECT_EQ(1, app.items[3].quality);
    EXPECT_EQ(0, app.items[4].quality);
    EXPECT_EQ(0, app.items[5].quality);
    EXPECT_EQ(1, app.items[6].quality);
}

TEST(GildedRoseTest, AgedItem) {
    vector<Item> items;
    items.push_back(Item("Aged Brie", 0, 0));
    items.push_back(Item("Aged Brie", 0, 50));
    items.push_back(Item("Aged Brie", 1, 0));
    items.push_back(Item("Aged Brie", 1, 50));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(1, app.items[0].quality);
    EXPECT_EQ(50, app.items[1].quality);
    EXPECT_EQ(1, app.items[2].quality);
    EXPECT_EQ(50, app.items[3].quality);
}

TEST(GildedRoseTest, BackstageItem) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 0, 0));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 0, 50));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 5, 47));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 5, 48));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 5, 49));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 5, 50));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 10, 48));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 10, 49));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 10, 50));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 11, 49));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 11, 50));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(0, app.items[0].quality);
    EXPECT_EQ(0, app.items[1].quality);
    EXPECT_EQ(50, app.items[2].quality);
    EXPECT_EQ(50, app.items[3].quality);
    EXPECT_EQ(50, app.items[4].quality);
    EXPECT_EQ(50, app.items[5].quality);
    EXPECT_EQ(50, app.items[6].quality);
    EXPECT_EQ(50, app.items[7].quality);
    EXPECT_EQ(50, app.items[8].quality);
    EXPECT_EQ(50, app.items[9].quality);
    EXPECT_EQ(50, app.items[10].quality);
}

TEST(GildedRoseTest, ConjuredItem) {
    vector<Item> items;
    items.push_back(Item("Conjured Mana Cake", 0, 0));
    items.push_back(Item("Conjured Mana Cake", 0, 1));
    items.push_back(Item("Conjured Mana Cake", 0, 2));
    items.push_back(Item("Conjured Mana Cake", 0, 3));
    items.push_back(Item("Conjured Mana Cake", 0, 4));
    items.push_back(Item("Conjured Mana Cake", 0, 5));
    items.push_back(Item("Conjured Mana Cake", 1, 0));
    items.push_back(Item("Conjured Mana Cake", 1, 1));
    items.push_back(Item("Conjured Mana Cake", 1, 2));
    items.push_back(Item("Conjured Mana Cake", 1, 3));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(0, app.items[0].quality);
    EXPECT_EQ(0, app.items[1].quality);
    EXPECT_EQ(0, app.items[2].quality);
    EXPECT_EQ(0, app.items[3].quality);
    EXPECT_EQ(0, app.items[4].quality);
    EXPECT_EQ(1, app.items[5].quality);
    EXPECT_EQ(0, app.items[6].quality);
    EXPECT_EQ(0, app.items[7].quality);
    EXPECT_EQ(0, app.items[8].quality);
    EXPECT_EQ(1, app.items[9].quality);
}

TEST(GildedRoseTest, SulfurasItem) {
    vector<Item> items;
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 1, 80));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(80, app.items[0].quality);
    EXPECT_EQ(80, app.items[1].quality);
    EXPECT_EQ(0, app.items[0].sellIn);
    EXPECT_EQ(1, app.items[1].sellIn);
}

void example()
{
    vector<Item> items;
    items.push_back(Item("+5 Dexterity Vest", 10, 20));
    items.push_back(Item("Aged Brie", 2, 0));
    items.push_back(Item("Elixir of the Mongoose", 5, 7));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
    items.push_back(Item("Conjured Mana Cake", 3, 6));
    GildedRose app(items);
    app.updateQuality();
}
