/**
 * Author: Ayuphys
 * Problem Number: abc214-a
 * Title: New Generation ABC
 * Link to the Problem: https://atcoder.jp/contests/abc214/tasks/abc214_a
 * Link to the Submission: https://atcoder.jp/contests/abc214/submissions/65583677
 * Difficulty: 4
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        
        if(N <= 125) 
        {
            OUT(4);
        }
        else if(N <= 211)
        {
            OUT(6);
        }
        else
        {
            OUT(8);
        }
        
        
        return;
    }
};
  
int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
 
    int testcase_number = 1;
    // cin >> testcase_number;

    rep(testcase, testcase_number)
    {
        Ayuphys_solve Ayuphys;
        Ayuphys.Run();
    }

    return 0;
}