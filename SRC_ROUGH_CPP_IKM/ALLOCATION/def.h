/*
 *
 */

#ifndef DEFS
#define DEFS

using namespace std;

#define DEFS_ARR123_SZ 3
#define DEFS_TESTTWOSTRINGS_SZ 2

/*There exists overhead for primitives*/

template <typename T> inline T* allocFill(size_t size)
{
	T* retPtr;

	allocator<T> instance;
	retPtr = instance.allocate(size);
	for(int i = 0; i < size; ++i)
	{
		T atIndex;
		instance.construct(retPtr + i, atIndex);
	}

	return retPtr;
};

template <typename T> inline T* allocFill()
{
	return allocFill<T>(1);	
};

template <typename T> inline void allocFree(T *toFree, size_t size)
{
	allocator<T> instance;
	for(int i = 0; i < size; ++i)
		instance.destroy(toFree + i);
	instance.deallocate(toFree, size);
};

template <typename T> inline void allocFree(T *toFree)
{
	allocFree(toFree, 1);
};

#endif
