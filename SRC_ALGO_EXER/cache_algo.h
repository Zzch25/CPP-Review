#ifndef CACHE
#define CACHE

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class Cache
{
    private:
        int maxElems,
            total,
            hasGet;
       
		//hash maps should be combined, done for readability!
        unordered_map<int, int> cache;
	    unordered_map<int, int> getCount;
        unordered_map<int, list<int>::iterator> order;
        list<int> inOrder;
        
    public:
        Cache(int capacity) : maxElems(capacity), total(0), hasGet(0)
        {
            cout << "CAP " << maxElems << endl;
        }
        
        void mark(int key, int value)
        {
            bool inc;
            int temp;

            inc = true;
            
            cout << "\nSET(" << key << '&' << value << ") ";
            
            if(maxElems > 0)
            {
                if(cache.find(key) != cache.end())
                {
                    inOrder.erase(order[key]);
    			    order.erase(key);
    			    getCount.erase(key);
    			    cache.erase(key);
    			    
    			    inc = false;
                }
                else if(total == maxElems)
                {
                    temp = inOrder.back();
    
                    inOrder.pop_back();
                    order.erase(temp);
                    cache.erase(temp);
                }
    
                cache.insert({key, value});
                inOrder.emplace_front(key);
    			order.insert({key, inOrder.begin()});
    			getCount.insert({key, 0});
            
                total += (int)(total != maxElems && inc);
                
                auto itrOrder = inOrder.begin();
			    auto itrNext = itrOrder;
			    
				//Should be forward linked for immediate access to skip index
			    for(++itrNext;
			        itrNext != inOrder.end() && getCount[*itrOrder] < getCount[*itrNext];
			                itrOrder = itrNext++)
			                {
			                    order.erase(*itrOrder);
			                    order.erase(*itrNext);
			                    
			                    swap(*itrOrder, *itrNext);
			                    
			                    order.insert({*itrOrder, itrOrder});
			                    order.insert({*itrNext, itrNext});
			                }
			                
                for(auto elemPrint : inOrder)
                    cout << elemPrint << '(' << cache[elemPrint] << ")@" << getCount[elemPrint] << ' ';
            }
        }
		
		int find(int key)
        {
            int temp;
            
            cout << "\nGET(" << key << ") ";
            
            if(maxElems > 0)
            {
    			auto itrCache = cache.find(key);
    			if(itrCache != cache.end())
    			{
    			    inOrder.erase(order[key]);
    		        temp = getCount[key] + 1;

    			    order.erase(key);
    			    getCount.erase(key);
    
    			    inOrder.emplace_front(key);
    			    order.insert({key, inOrder.begin()});
    			    getCount.insert({key, temp});

                    auto itrOrder = inOrder.begin();
    			    auto itrNext = itrOrder;
    			    
					//Should be forward linked for immediate access to skip index
    			    for(++itrNext;
    			        itrNext != inOrder.end() && getCount[*itrOrder] < getCount[*itrNext];
    			                itrOrder = itrNext++)
    			                    {
    			                        order.erase(*itrOrder);
        			                    order.erase(*itrNext);
        			                    
        			                    swap(*itrOrder, *itrNext);
        			                    
        			                    order.insert({*itrOrder, itrOrder});
        			                    order.insert({*itrNext, itrNext});
    			                    }
    			                    
    			    
                    for(auto&& elemPrint : inOrder)
                        cout << elemPrint << '(' << cache[elemPrint] << ")@" << getCount[elemPrint] << ' ';
                    cout << "== " << itrCache->second; 
    
    				return itrCache->second;
    			}
            }

            cout << "== " << -1; 
            return -1;
        }
};

#endif
