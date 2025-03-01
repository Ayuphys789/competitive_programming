#pragma once

struct ModInt_2_61m1
{
private:
    using mint61 = ModInt_2_61m1;
    using u64 = long long;
    using u128 = __uint128_t;

    u64 x;

public:
    ModInt_2_61m1() : x{} {}

    explicit ModInt_2_61m1(u64 a) : x{a} {}

    mint61 &operator+=(const mint61 &p)
    {
        if ((x += p.x) >= mod())
            x -= mod();
        return *this;
    }

    mint61 &operator-=(const mint61 &p)
    {
        if ((x += mod() - p.x) >= mod())
            x -= mod();
        return *this;
    }

    mint61 &operator*=(const mint61 &p)
    {
        u128 c = (u128)x * p.x;
        x = u64(c >> 61) + u64(c & mod());
        if (x >= mod())
            x -= mod();
        return *this;
    }

    mint61 &operator/=(const mint61 &p)
    {
        *this *= p.inv();
        return *this;
    }

    mint61 operator-() const { return mint61() - *this; }

    mint61 operator+(const mint61 &p) const { return mint61(*this) += p; }

    mint61 operator-(const mint61 &p) const { return mint61(*this) -= p; }

    mint61 operator*(const mint61 &p) const { return mint61(*this) *= p; }

    mint61 operator/(const mint61 &p) const { return mint61(*this) /= p; }

    bool operator==(const mint61 &p) const { return x == p.x; }

    bool operator!=(const mint61 &p) const { return x != p.x; }

    u64 val() const { return x; }

    mint61 pow(u64 n) const
    {
        mint61 ret(1), mul(*this);
        while (n > 0)
        {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    mint61 inv() const { return pow(mod() - 2); }

    friend ostream &operator<<(ostream &os, const mint61 &p)
    {
        return os << p.val();
    }

    friend istream &operator>>(istream &is, mint61 &a)
    {
        u64 t;
        is >> t;
        a = mint61(t);
        return is;
    }

    static constexpr u64 mod() { return (1ull << 61) - 1; }
};