#pragma once

#include <string>

inline const std::string VERSION = "0.0.1";

namespace Books
{
	void welcome();
	bool handleOption();
	void save();
	void search();
	void list();
}

namespace Classes
{
	void welcome();
	bool handleOption();
}

namespace Students
{
	void welcome();
	bool handleOption();
}

namespace Loans
{
	void welcome();
	bool handleOption();
}

namespace Others
{
	void welcome();
	bool handleOption();
	void about();
}

namespace Home
{
	void welcome();
	bool handleOption();
}
