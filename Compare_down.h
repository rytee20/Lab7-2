#pragma once
#include "Storage.h"

class Compare_down : public Storage
{
	friend class Storage;
public:
	bool operator()(Storage& p1, Storage& p2)
	{
		if (p1.GetAmount() > p2.GetAmount()) return 1;
		else return 0;
	}
};
