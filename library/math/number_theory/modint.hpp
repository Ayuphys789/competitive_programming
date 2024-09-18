#pragma once

template <int MOD>
struct Fp
{
    // inner value
    long long val;

    // constructor
    constexpr Fp() : val(0) {}
    constexpr Fp(long long v) : val(v % MOD)
    {
        if (val < 0)
            val += MOD;
    }

    // getter
    constexpr long long get() const
    {
        return val;
    }
    constexpr int get_mod() const
    {
        return MOD;
    }

    // comparison operators
    constexpr bool operator==(const Fp &r) const
    {
        return this->val == r.val;
    }
    constexpr bool operator!=(const Fp &r) const
    {
        return this->val != r.val;
    }

    // arithmetic operators
    constexpr Fp &operator+=(const Fp &r)
    {
        val += r.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    constexpr Fp &operator-=(const Fp &r)
    {
        val -= r.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr Fp &operator*=(const Fp &r)
    {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp &operator/=(const Fp &r)
    {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b)
        {
            long long t = a / b;
            a -= t * b, swap(a, b);
            u -= t * v, swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr Fp operator+() const { return Fp(*this); }
    constexpr Fp operator-() const { return Fp(0) - Fp(*this); }
    constexpr Fp operator+(const Fp &r) const { return Fp(*this) += r; }
    constexpr Fp operator-(const Fp &r) const { return Fp(*this) -= r; }
    constexpr Fp operator*(const Fp &r) const { return Fp(*this) *= r; }
    constexpr Fp operator/(const Fp &r) const { return Fp(*this) /= r; }

    // other operators
    constexpr Fp &operator++()
    {
        ++val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    constexpr Fp &operator--()
    {
        if (val == 0)
            val += MOD;
        --val;
        return *this;
    }
    constexpr Fp operator++(int)
    {
        Fp res = *this;
        ++*this;
        return res;
    }
    constexpr Fp operator--(int)
    {
        Fp res = *this;
        --*this;
        return res;
    }
    friend constexpr istream &operator>>(istream &is, Fp<MOD> &x)
    {
        is >> x.val;
        x.val %= MOD;
        if (x.val < 0)
            x.val += MOD;
        return is;
    }
    friend constexpr ostream &operator<<(ostream &os, const Fp<MOD> &x)
    {
        return os << x.val;
    }

    // other functions
    constexpr Fp pow(long long n) const
    {
        Fp res(1), mul(*this);
        while (n > 0)
        {
            if (n & 1)
                res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }
    constexpr Fp inv() const
    {
        Fp res(1), div(*this);
        return res / div;
    }
    friend constexpr Fp<MOD> pow(const Fp<MOD> &r, long long n)
    {
        return r.pow(n);
    }
    friend constexpr Fp<MOD> inv(const Fp<MOD> &r)
    {
        return r.inv();
    }
};