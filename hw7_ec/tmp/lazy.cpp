#include <stdlib.h>
#include <memory>
#include <vector>
#include <string.h>

// Models a linear function
class linear_function {
private:
    const double m;
    const double b;

public:
    // Construct the function from slop intercept representation
    linear_function(double m, double b) : m(m), b(b)
    { }

    // Evaluate the linear function for a specific value.
    double operator()(double x) const { return m * x + b; }

    bool operator==(const linear_function& other) const {
        return m == other.m && b == other.b;
    }
};

// Iterates over a given domain for a linear function.
template<typename Iter>
class linear_function_iterator { // You'd want to extend or mimic std::iterator in a library-esque implementation
private:
    const linear_function fn_;
    Iter iter_;
    const Iter end_;

public:
    // Whether you want to take a single iterator or a pair is going to depend on typical usecase. Taking
    // a pair makes use a bit safer though since you can do checking to ensure proper use.
    linear_function_iterator(linear_function fn, Iter iter, Iter end)
      : fn_(std::move(fn)), iter_(iter), end_(end)
    { }

    double operator*() const {
        assert(iter_ != end_); // Example of using two iterators instead of one to provide additional error checking.
        return fn_(*iter_);
    }

    linear_function_iterator& operator++() {
        assert(iter_ != end_);
        ++iter_;
        return *this;
    }

    bool operator==(const linear_function_iterator& other) const {
        return fn_ == other.fn_ && iter_ == other.iter_;
    }

    bool operator!=(const linear_function_iterator& other) const {
        return !operator==(other);
    }
};

// Convenience class for a linear function over a given domain.
// Provides both an upfront approach or generator-like.
template<class Iter>
class fixed_linear_function { // This seems like a terrible name, but I'm blanking on anything better.
private:
    linear_function fn_;
    const Iter begin_;
    const Iter end_;
public:

    using iterator = linear_function_iterator<Iter>;

    fixed_linear_function(linear_function fn, Iter domain_begin, Iter domain_end)
      : fn_(std::move(fn)), begin_(domain_begin), end_(domain_end) 
    {}

    std::vector<double> evaluate() const {
        std::vector<double> results;
        std::copy(begin(), end(), std::back_inserter(results));
        return results;
    }

    iterator begin() {
        return iterator(fn_, begin_, end_);
    }

    iterator end() {
        return iterator(fn_, end_, end_);
    }

};

int main() {

}
