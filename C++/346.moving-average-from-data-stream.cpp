class MovingAverage {
public:
    /** Initialize your data structure here. */
    int qsize = 0;
    queue<int> q;
    double ave = 0;
    double sum = 0;
    MovingAverage(int size) {
        qsize = size;
    }
    
    double next(int val) {
        if (q.size() == qsize) {
            sum -= q.front();
            sum += val;
            ave = sum / qsize;
            q.push(val);
            q.pop();
        } else {
            sum += val;
            q.push(val);
            ave = sum / q.size();
        }
        return ave;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */