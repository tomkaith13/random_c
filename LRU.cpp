#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#define CACHE_MAX 5
using namespace std;
/* 
	LRU Cache is implemented using a doubly-linked list
	of CACHE_MAX page-numbers. Whenever, the user accesses a
	page_num, the cache removes that page_number from the list
	and appends it to the front.
*/

class LRU_Cache{
	size_t cache_size;
	list<size_t> cache;
	
	list<size_t>::iterator find_pagenum(size_t);
	void add_pagenum(size_t);
	void del_pagenum(size_t);
public:
	LRU_Cache();
	LRU_Cache(size_t size);
	void access_cache(size_t page_no);
	void display_cache();
};

LRU_Cache::LRU_Cache() : cache_size(CACHE_MAX) {};
LRU_Cache::LRU_Cache(size_t c_size) : cache_size(c_size) {};

list<size_t>::iterator
LRU_Cache::find_pagenum(size_t pnum) {
	list<size_t>::iterator cache_it;
	for (cache_it = cache.begin(); cache_it != cache.end(); cache_it++) {
		if (*cache_it == pnum)
			return (cache_it);
	}
	return (cache.end());
}

void
LRU_Cache::del_pagenum(size_t pnum) {
	//auto cache_it;

	auto cache_it = find_pagenum(pnum);
	if (cache_it != cache.end())
		cache.erase(cache_it);
}

void
LRU_Cache::add_pagenum(size_t pnum) {
		if (cache.size() < cache_size)	
			cache.push_front(pnum);	
		else {
			// remove last element from cache and add new in front of cache
			cache.pop_back();
			cache.push_front(pnum);
		}
}

void
LRU_Cache::access_cache(size_t pnum) {
	auto cache_it = find_pagenum(pnum);
	if (cache_it == cache.end())
		add_pagenum(pnum);
	else {
		del_pagenum(pnum);	
		add_pagenum(pnum);
	}
}

void
LRU_Cache::display_cache() {
	for(auto it : cache) {
		cout<<"cache data:"<<it<<endl;
	}
}



int
main() {

	LRU_Cache lc;
	lc.access_cache(1);
	lc.access_cache(2);
	lc.access_cache(3);
	lc.access_cache(5);
	lc.access_cache(4);
	//lc.display_cache();
	lc.access_cache(1);
	lc.access_cache(7);
	lc.display_cache();

	return(0);
}

