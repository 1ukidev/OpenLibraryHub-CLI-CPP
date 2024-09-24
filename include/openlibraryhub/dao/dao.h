#ifndef DAO_H
#define DAO_H

namespace olh
{
	template<typename T>
	class dao
	{
	public:
		virtual void save(T& entity) = 0;
	};
}

#endif // DAO_H
