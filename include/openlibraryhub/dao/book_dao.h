#ifndef BOOK_DAO_H
#define BOOK_DAO_H

#include "dao/dao.h"
#include "entities/book_entity.h"

namespace olh
{
	class book_dao : public dao<book_entity>
	{
	public:
		book_dao() = default;
		~book_dao() = default;

		void save(book_entity& entity) override;
	};
}

#endif // BOOK_DAO_H
