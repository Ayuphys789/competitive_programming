# 競プロ典型90 Editorial

## 015 - Don't be too close
### 解法
整数の差が $`k`$ 以上という条件の元で $`a`$ 個のボールを選ぶ方法は $`{}_{N-(k-1)(a-1)}\textrm{C}_{a}`$ 通り. これを全て計算して加算すればよい. 
### 計算量
`Enumeration` 構造体 (`library/combinatorics/enumeration.hpp`) によって階乗とその逆元を前計算（$`O(N)`$）しておくことで, $`O(1)`$ で計算できる. 
計算量は調和級数より $`O(N\textrm{log}N)`$.