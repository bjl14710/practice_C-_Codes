#include<iostream>
#include<vector>

std::vector<int> findNum(std::vector<int> inpt, unsigned int target)
{
    std::vector<int> results;
    unsigned int i;
    unsigned int j;
    int hld;
    for(i=0; i<inpt.size(); i++)
    {
        hld = inpt[i];
        for(j = i; j < inpt.size(); j++)
        {
            if(hld + inpt[j] == target - 30)
            {
                results.push_back(i);
                results.push_back(j);
                std::cout << i << " " << j << std::endl;
            }
        }
        //std::cout << i << std::endl;
    }
    return results;
}
int main()
{
    std::vector<int> nums; //{1,10,25,35,60};
    nums.push_back(1);
    nums.push_back(10);
    nums.push_back(25);
    nums.push_back(35);
    nums.push_back(60);
    unsigned int i = 0;
    unsigned int n = 5;
    /*for(i = 0; i < n; i++)
    {
        nums.push_back =
    }*/
    std::vector<int> res;
    findNum(nums, 90);


    //std::cout << findNum(nums,90) << std::endl;

}
