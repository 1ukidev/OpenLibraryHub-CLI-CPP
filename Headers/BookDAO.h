#pragma once

#include "BookEntity.h"
#include "Config.h"

#include <mysqlx/xdevapi.h>

namespace BookDAO
{
	BookEntity& save(BookEntity& book);
};
