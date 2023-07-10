#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// 과제 1 상점을 출력하세요.
// 과제 2 상점과 비슷한 방법으로 Stage.csv, Monster.csv를 만들고 Stage에 등장하는 몬스터를 출력해보세요.
// 코드도 분할해보세요.

// 아이템 타입, 무기/방어구
enum ITEMTYPE
{
	WEAPON ,
	ARMOR
};

// 아이템(일부아이템은 상점에서 안팔수도 있음.)
struct Item
{
	int itemType;
	int itemId;
	string name;
	int value;
};

// 상점에서 판매하는 아이템
struct ShopItem
{
	int itemId;
	int itemType;
	int cost;
};

// 상점 클래스
class Shop
{
private:
	// 아이템을 저장하기위해 vector를 사용합니다.
	vector<Item>	items;
	vector<ShopItem> shopItems;

public:
	void AddItem(Item item)
	{
		items.push_back(item);
	}

	void AddShopItem(ShopItem shopItem)
	{
		shopItems.push_back(shopItem);
	}

	Item Find(int itemType, int itemId)
	{
		for (int i = 0; i < items.size(); i++)
		{
			if (items[i].itemType == itemType && items[i].itemId == itemId)
			{
				return items[i];
			}
		}

		return Item();
	}

	// 아이템을 보여줍니다.
	void ShowItem()
	{
		for (int i = 0; i < shopItems.size(); i++)
		{
			Item item = Find(shopItems[i].itemType, shopItems[i].itemId);

			cout << "-------------------------------------------" << endl;
			if (item.itemType == ARMOR)
			{
				cout << "아이템 : " << item.name << endl;
				cout << "방어도 : " << item.value << endl;
				cout << "비용 : " << shopItems[i].cost << endl;
			}
			else
			{
				cout << "아이템 : " << item.name << endl;
				cout << "공격력 : " << item.value << endl;
				cout << "비용 : " << shopItems[i].cost << endl;
			}
			cout << "-------------------------------------------" << endl;
		}
	}
};


int main()
{
	Shop shop;

	Item iTem;
	ShopItem sItem;

	// item.csv, ShopItem.csv를 읽어 Shop 클래스에 데이터를 넣고 출력해보세요.
	{
		std::ifstream fs;
		fs.open("Item.csv");

		string str;
		int Index = 0;

		while (!fs.eof())
		{
			getline(fs, str);

			for (int i = 0; i < str.size(); i++)
			{
				if (str[i] == ',') str[i] = ' ';
			}

			//스트링스트림으로 구분하고 저장
			//ss >> itemType[Index] >> itemId[Index] >> itemName[Index] >> itemValue[Index];
			int itemType, itemID, itemValue;
			string name;
			stringstream ss(str);
			ss >> itemType >> itemID >> name >> itemValue;

			iTem.itemType = itemType;
			iTem.itemId = itemID;
			iTem.name = name;
			iTem.value = itemValue;

			shop.AddItem(iTem);
		}

		fs.close();
	}

	{
		std::ifstream fs2;
		fs2.open("ShopItem.csv");

		stringstream ss2;
		string str2;

		ss2.str(str2);
		int Index2 = 0;

		while (!fs2.eof())
		{
			getline(fs2, str2);

			for (int i = 0; i < str2.size(); i++)
			{
				if (str2[i] == ',') str2[i] = ' ';
			}

			//스트링스트림으로 구분하고 저장
			//ss >> itemType[Index] >> itemId[Index] >> itemName[Index] >> itemValue[Index];

			stringstream ss2(str2);

			int itemType, itemID, itemCost;
			ss2 >> itemType >> itemID >> itemCost;

			sItem.itemType = itemType;
			sItem.itemId = itemID;
			sItem.cost = itemCost;

			shop.AddShopItem(sItem);
		}
		fs2.close();
	}
#pragma region 예제 입력
	// 예제 입력입니다.
	/*Item item1;
	item1.itemType = WEAPON;
	item1.itemId = 1;
	item1.name = "아이템";
	item1.value = 100;
	shop.AddItem(item1);

	Item item2;
	item2.itemType = WEAPON;
	item2.itemId = 1;
	item2.name = "아이템";
	item2.value = 100;
	shop.AddItem(item2);

	Item item3;
	item3.itemType = WEAPON;
	item3.itemId = 1;
	item3.name = "아이템";
	item3.value = 100;
	shop.AddItem(item3);

	Item item4;
	item4.itemType = WEAPON;
	item4.itemId = 1;
	item4.name = "아이템";
	item4.value = 100;
	shop.AddItem(item4);

	Item item5;
	item5.itemType = WEAPON;
	item5.itemId = 1;
	item5.name = "아이템";
	item5.value = 100;
	shop.AddItem(item5);

	ShopItem shopItem;
	shopItem.itemType = WEAPON;
	shopItem.itemId = 1;
	shopItem.cost = 1000;
	shop.AddShopItem(shopItem);*/
	// 예제 입력입니다.
#pragma endregion

	shop.ShowItem();

	return 0;
}