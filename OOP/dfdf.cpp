class Example {
public:
    int GetValue() const {
        ++mutable_variable;
        return value_;
    }

private:
    int value_;
    mutable int mutable_variable;
};