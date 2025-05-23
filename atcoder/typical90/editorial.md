# 競プロ典型90 Editorial

## 015 - Don't be too close ($`\bigstar`$ 6)
### 解法
整数の差が $`k`$ 以上という条件の元で $`a`$ 個のボールを選ぶ方法は $`{}_{N-(k-1)(a-1)}\textrm{C}_{a}`$ 通り. これを全て計算して加算すればよい. 
### 計算量
`Enumeration` 構造体 (`library/combinatorics/enumeration.hpp`) によって階乗とその逆元を $`O(N)`$ で前計算しておくことで, 二項係数の各値は $`O(1)`$ で計算できる. 
計算量は調和級数より $`O(N\textrm{log}N)`$.

## 019 - Pick Two ($`\bigstar`$ 6)
### 解法
区間DPを行う.

#### 定義
$$dp[l][r]=l番目からr番目までを取り除くのに必要な最小コスト$$

#### 遷移
$$dp[l][r] = min(dp[l+1][r-1]+|A[l]-A[r]|,\;dp[l][j]+dp[j+1][r])$$

### 計算量
$`|l-r|`$ を固定して小さい方から見ていき, $`l,j`$ の順に動かしてDPテーブルを更新していくから, 計算量は $`O(N^3)`$

## 031 - VS Atcoder ($`\bigstar`$ 6)
### 解法
各山について Grundy 数を計算して全ての XOR をとったものがゲームの Grundy 数である.
### 計算量
mex を愚直に求めても Grundy 数のテーブルを $`O(P^5)`$ で作成できる. 後は $`O(N)`$ でゲーム全体の Grundy 数を求められる.


## 045 - Simple Grouping ($`\bigstar`$ 6)
### 解法
bitDP を用いる.
$$dp[i][bit] = bitに含まれる点をiグループに分けたときのスコアの最小値$$
#### 遷移
$$dp[i][bit] = \underset{b\in bit}{min}\{max(dp[b][i-1], dist[bit-b])\}$$
### 計算量
$`(bit, b)`$ の組み合わせが $`3^N`$ 通りだから, 計算量は
$`O(N\times 3^N)`$.

## 049 - Flip Digits 2 ($`\bigstar`$ 6)
### 解法
「$`L_i`$ 枚目から $`R_i`$ 枚目をひっくり返す」を「$`L_i-1`$ と $`R_i`$ を連結させる」と言い換える.
このとき, $`0,1,\dots,N`$ が連結であることが, 題意を満たすための必要十分条件である. 最小コストを求めるにはクラスカル法を用いればよい.
### 計算量
クラスカル法により, $`O(M\;\textrm{log}\;N)`$.

## 054 - Takahashi Number ($`\bigstar`$ 6)
### 解法
研究者をノード, 共著関係をエッジとしたグラフにおいて, 高橋氏からの距離が答えである.
これはDFSで求められるが, そのまま実装するとエッジ数が $`\sum_i K_i^2`$ になってしまい, 計算量が大きすぎるため, 以下のように工夫してグラフを書き換える.

$`R`$ 個のノードからなる完全グラフは, 新たなノードを１つ追加して, ΔY変換の要領で新たなグラフ(エッジの重みが $`0.5`$)に書き換えても, 元のノード同士の最短距離は変わらない. このとき, エッジ数を減らすことができるので、この問題はBFSで解ける.
### 計算量
グラフのノード数が $`O(N+M)`$, エッジ数が $`O(\sum_i K_i)`$ だから, $`O(N+M+\sum_i K_i)`$