#include <iostream>
#include <memory>

// 추상화 클래스 A
class AbstractProductA {
public:
    virtual ~AbstractProductA() {} // 소멸자
    virtual void use() const = 0; // 사용시 0 으로
};

// 구체화 클래스 A1
class ConcreteProductA1 : public AbstractProductA { // class ConcreateProductA1은 AbstractProductA를 상속받는다. 자식클래스
public:
    void use() const override {
        std::cout << "Using ConcreteProductA1" << std::endl;
    }
};

// 구체화 클래스 A2
class ConcreteProductA2 : public AbstractProductA { // class ConcreateProductA1은 AbstractProductA를 상속받는다. 자식클래스
public:
    void use() const override { // 상속받은 use 를 대채한다.
        std::cout << "Using ConcreteProductA2" << std::endl;
    }
};

// 추상 클래스 B
class AbstractProductB {
public:
    virtual ~AbstractProductB() {}
    virtual void consume() const = 0;
};

// 구체화 클래스 B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void consume() const override {
        std::cout << "Consuming ConcreteProductB1" << std::endl;
    }
};

// 구체화 클래스 B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void consume() const override {
        std::cout << "Consuming ConcreteProductB2" << std::endl;
    }
};

// 추상 팩토리
class AbstractFactory {
public:
    virtual ~AbstractFactory() {}
    virtual std::unique_ptr<AbstractProductA> createProductA() const = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB() const = 0;
};

// 구체화 팩토리 1
class ConcreteFactory1 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA1>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB1>();
    }
};

// 구체화 팩토리 2
class ConcreteFactory2 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA2>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB2>();
    }
};

// 클라이언트
class Client {
public:
    Client(std::unique_ptr<AbstractFactory> factory)
        : productA(factory->createProductA()), productB(factory->createProductB())
    {}

    void run() const {
        productA->use();
        productB->consume();
    }

private:
    std::unique_ptr<AbstractProductA> productA;
    std::unique_ptr<AbstractProductB> productB;
};

// 사용 예시
int main() {
    std::unique_ptr<AbstractFactory> factory1 = std::make_unique<ConcreteFactory1>();
    std::unique_ptr<AbstractFactory> factory2 = std::make_unique<ConcreteFactory2>();

    Client client1(std::move(factory1));
    Client client2(std::move(factory2));

    client1.run();
    client2.run();


    return 0;
}