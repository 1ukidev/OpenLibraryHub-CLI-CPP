#ifndef DAO_H
#define DAO_H

namespace olh {

template <typename T>
class dao
{
public:
    virtual ~dao() = default;
    virtual void save(T& entity) = 0;
};

}  // namespace olh

#endif  // DAO_H
