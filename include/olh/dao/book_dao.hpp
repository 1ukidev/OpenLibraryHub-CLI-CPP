#ifndef BOOK_DAO_H
#define BOOK_DAO_H

#include "dao/dao.hpp"
#include "entities/book_entity.hpp"

namespace olh {

class book_dao : public dao<book_entity>
{
public:
    book_dao() = default;
    ~book_dao() = default;

    void save(book_entity& entity) override;
};

}  // namespace olh

#endif  // BOOK_DAO_H
