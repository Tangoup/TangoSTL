/**
 * allocator_traits 为所有allocator类提供一个统一的接口，虽然作为allocator类，
 * 它不能是非类类型（因此它们可以自行提供接口），但是allocator_traits仍然提供
 * 所需的所有接口
 */
#ifndef _ALLOCATOR_TRAITS_H
#define _ALLOCATOR_TRAITS_H

namespace tstd
{
	template <class Alloc>
	struct allocator_traits
	{
		typedef Alloc allocator_type;
		typedef typename Alloc::value_type value_type;

		/* 对于以下成员类型，文档ISO/IEC14882:2011中注明Alloc中必须有相应类型，
		 * 才能进行如下定义，在本STL实现中，默认Alloc中已经定义有相应类型
		 */
		typedef typename Alloc::pointer				pointer;
		typedef typename Alloc::const_pointer		const_pointer;
		typedef typename Alloc::void_pointer		void_pointer;
		typedef typename Alloc::const_void_pointer	const_void_pointer;
		typedef typename Alloc::difference_type		differrence_type;
		typedef typename Alloc::size_type			size_type;
		template <class T> using rebind_alloc = Alloc::rebind<T>::other;
		template <class T> using rebind_traits = allocator_traits<rebind_alloc<T> >;
		static pointer allocate(Alloc& a, size_type n);
		static pointer allocate(Alloc& a, size_type n, const_void_pointer hint);
		static void deallocate(Alloc& a, pointer p, size_type n);
		template <class T, class... Args>
			static void construct(Alloc& a, T* p, Args&&... args);
		template <class T>
			static void destroy(Alloc& a, T* p);
	};
}

#endif
