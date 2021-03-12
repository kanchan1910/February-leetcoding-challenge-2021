
class PeekingIterator : public Iterator {
public:
    int peekn;
    bool peeked;
	PeekingIterator(const vector<int>& nums) : Iterator(nums)
    {
	   peeked = false;   
	}
	
	int peek() 
    {
       if(peeked == false)
       {
           peekn = Iterator::next(); 
           peeked = true;
       }
        return peekn;
	}
	
	
	int next()
    {
	     if(peeked == false)
         {
             return Iterator::next(); 
         }
        else
        {
            peeked = false;
            return peekn;
        }
	}
	
	bool hasNext() const {
	    if(peeked == true)
        {
            return true;
        }
        else
        {
            return Iterator::hasNext(); 
        }
	}
};
