#ifndef GETIT_DLIST_H
#define GETIT_DLIST_H

#include <memory>
#include <array>
#include <mutex>
#include <atomic>

namespace getit
{
    template <typename T>
    class rlist_node: public std::enable_shared_from_this<rlist_node<T> >
    {
	    T data_;
	    std::shared_ptr< rlist_node<T> > next_;
	    std::weak_ptr< rlist_node<T> > prev_;
	public:

    };

    template <typename T, long size_par>
    class rlist
    {
	    std::array<T, size_par> array_;
	    mutable std::recursive_mutex mutex_;
	    std::atomic_long index_;
	public:
	    rlist();
	    void push ( T const& );
	    T pop ( );
	
	friend std::ostream&  operator << (std::ostream& s, rlist const& r)
	{
	    std::lock_guard<std::recursive_mutex> lg ( r.mutex_ );
	    for ( int i = 0; i <= r.index_; ++i )// auto a : r.array_ )
		s << r.array_[i] <<" ";
	    return s;
	}
    };

}
template <typename T, long size_par>
getit::rlist<T, size_par>::rlist():
    array_(),
    mutex_(),
    index_(-1)
{
}
template <typename T, long size_par>
void getit::rlist<T, size_par>::push( T const& _d )
{
    std::lock_guard<std::recursive_mutex> lg (mutex_);
    array_[++index_] = _d;
    if ( size_par == index_ ) index_ = -1;
}


template <typename T, long size_par>
T getit::rlist<T, size_par>::pop( )
{
    std::lock_guard<std::recursive_mutex> lg (mutex_);
    if ( -1 == index_ ) throw std::logic_error("Round list is empty, nothing to pop");
    return array_[index_--];
}










#endif // GETIT_DLIST_H
