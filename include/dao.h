#pragma once

#include <optional>
#include <vector>

#include "entities.h"

namespace BookDAO
{
	BookEntity& save(BookEntity& book);
	std::optional<BookEntity> getBookById(unsigned int id);
	std::vector<BookEntity> getAll();
};
