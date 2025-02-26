# ABC 096 Editorial

## A - Day of Takahashi (84)

### 解法
$`a \leq b`$ なら $`a`$ , そうでないなら $`a-1`$.

## B - Maximum Sum (88)

### 解法
最も大きい整数のみに対して操作を行えばよい.

## C - Grid Repainting (407)

### 解法
黒いマスで, かつ隣のマスが全て白いという条件を満たすマスが存在すれば No. そうでないなら Yes.

## D - Five, Five Everywhere (1226)

### 解法
$`p\equiv 1 \;\textrm{mod}\;5`$ を満たす素数を $`N`$ 個出力すればよい. エラトステネスの篩によって素数リストを生成する.
### 計算量
$`M=55,555`$ 以下の素数を列挙するのに $`O(N\;\textrm{log\;log}\;N)`$ かかる.