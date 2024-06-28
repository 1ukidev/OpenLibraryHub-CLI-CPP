#pragma once

#include <mysqlx/xdevapi.h>

#include "book_entity.h"
#include "config.h"

namespace BookDAO
{
	void save(BookEntity& bookEntity);
};
