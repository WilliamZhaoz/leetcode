// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    peeked = false;
        peekval = 0;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!peeked) {
            peekval = Iterator::next();
	        peeked = true;
        }
        return peekval;
    }

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if (peeked) {
            peeked = false;
            return peekval;
        }
        return Iterator::next();
	}

	bool hasNext() const {
        if (peeked) {
            return true;
        }
        return Iterator::hasNext();
	    
	}
private:
    bool peeked;
    int peekval;
};
