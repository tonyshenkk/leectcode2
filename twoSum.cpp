struct node
{
    int val;
    int index;
    node(int a, int b):val(a), index(b){}
};
bool compare(const node &a, const node &b)
{
    return a.val < b.val;  
}
    
class Solution {
public:

    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = numbers.size() - 1;
        
        vector<int> res;
        if(len < 1)
            return res;
            
        vector<node> nodes;
        int low = 0, high = len, t;
        
        for(int i = 0; i <= len; i++)
        {
            node temp(numbers[i], i);
            nodes.push_back(temp);
        }
        
        sort(nodes.begin(), nodes.end(), compare);
        
        while(low < high)
        {
            t = nodes[low].val + nodes[high].val;
            if(t > target)
                high--;
            else if(t < target)
                low++;
            else
            {
                if(nodes[low].index > nodes[high].index)
                    swap(nodes[low].index, nodes[high].index);
                res.push_back(nodes[low].index + 1);
                res.push_back(nodes[high].index + 1);
                return res;
            }
        }
        return res;  
    }
};
