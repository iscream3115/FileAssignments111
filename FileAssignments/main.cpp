#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// ���� 1 ������ ����ϼ���.
// ���� 2 ������ ����� ������� Stage.csv, Monster.csv�� ����� Stage�� �����ϴ� ���͸� ����غ�����.
// �ڵ嵵 �����غ�����.

// ������ Ÿ��, ����/��
enum ITEMTYPE
{
	WEAPON ,
	ARMOR
};

// ������(�Ϻξ������� �������� ���ȼ��� ����.)
struct Item
{
	int itemType;
	int itemId;
	string name;
	int value;
};

// �������� �Ǹ��ϴ� ������
struct ShopItem
{
	int itemId;
	int itemType;
	int cost;
};

// ���� Ŭ����
class Shop
{
private:
	// �������� �����ϱ����� vector�� ����մϴ�.
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

	// �������� �����ݴϴ�.
	void ShowItem()
	{
		for (int i = 0; i < shopItems.size(); i++)
		{
			Item item = Find(shopItems[i].itemType, shopItems[i].itemId);

			cout << "-------------------------------------------" << endl;
			if (item.itemType == ARMOR)
			{
				cout << "������ : " << item.name << endl;
				cout << "�� : " << item.value << endl;
				cout << "��� : " << shopItems[i].cost << endl;
			}
			else
			{
				cout << "������ : " << item.name << endl;
				cout << "���ݷ� : " << item.value << endl;
				cout << "��� : " << shopItems[i].cost << endl;
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

	// item.csv, ShopItem.csv�� �о� Shop Ŭ������ �����͸� �ְ� ����غ�����.
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

			//��Ʈ����Ʈ������ �����ϰ� ����
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

			//��Ʈ����Ʈ������ �����ϰ� ����
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
#pragma region ���� �Է�
	// ���� �Է��Դϴ�.
	/*Item item1;
	item1.itemType = WEAPON;
	item1.itemId = 1;
	item1.name = "������";
	item1.value = 100;
	shop.AddItem(item1);

	Item item2;
	item2.itemType = WEAPON;
	item2.itemId = 1;
	item2.name = "������";
	item2.value = 100;
	shop.AddItem(item2);

	Item item3;
	item3.itemType = WEAPON;
	item3.itemId = 1;
	item3.name = "������";
	item3.value = 100;
	shop.AddItem(item3);

	Item item4;
	item4.itemType = WEAPON;
	item4.itemId = 1;
	item4.name = "������";
	item4.value = 100;
	shop.AddItem(item4);

	Item item5;
	item5.itemType = WEAPON;
	item5.itemId = 1;
	item5.name = "������";
	item5.value = 100;
	shop.AddItem(item5);

	ShopItem shopItem;
	shopItem.itemType = WEAPON;
	shopItem.itemId = 1;
	shopItem.cost = 1000;
	shop.AddShopItem(shopItem);*/
	// ���� �Է��Դϴ�.
#pragma endregion

	shop.ShowItem();

	return 0;
}