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
        std::cout << vMax << '\n';
        return 0;
    }
    