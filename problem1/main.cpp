    #include <vector>
    #include <iostream>
    int main()
    {
        std::vector<int> v{4, 7, 5, 3, 10};
        int vMax{};
        for(int i{0}; i<v.size(); ++i)
        {
            if(v[i]>vMax)
            vMax=v[i];
        }
        std::vector<int>w(++vMax, 0);
for(int i=0; i<w.size(); ++i)
w[v[i]] = w[v[i]] + 1;
        return 0;
    }
    