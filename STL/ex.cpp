#include <iostream>
#include <memory>

// �߻�ȭ Ŭ���� A
class AbstractProductA {
public:
    virtual ~AbstractProductA() {} // �Ҹ���
    virtual void use() const = 0; // ���� 0 ����
};

// ��üȭ Ŭ���� A1
class ConcreteProductA1 : public AbstractProductA { // class ConcreateProductA1�� AbstractProductA�� ��ӹ޴´�. �ڽ�Ŭ����
public:
    void use() const override {
        std::cout << "Using ConcreteProductA1" << std::endl;
    }
};

// ��üȭ Ŭ���� A2
class ConcreteProductA2 : public AbstractProductA { // class ConcreateProductA1�� AbstractProductA�� ��ӹ޴´�. �ڽ�Ŭ����
public:
    void use() const override { // ��ӹ��� use �� ��ä�Ѵ�.
        std::cout << "Using ConcreteProductA2" << std::endl;
    }
};

// �߻� Ŭ���� B
class AbstractProductB {
public:
    virtual ~AbstractProductB() {}
    virtual void consume() const = 0;
};

// ��üȭ Ŭ���� B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void consume() const override {
        std::cout << "Consuming ConcreteProductB1" << std::endl;
    }
};

// ��üȭ Ŭ���� B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void consume() const override {
        std::cout << "Consuming ConcreteProductB2" << std::endl;
    }
};

// �߻� ���丮
class AbstractFactory {
public:
    virtual ~AbstractFactory() {}
    virtual std::unique_ptr<AbstractProductA> createProductA() const = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB() const = 0;
};

// ��üȭ ���丮 1
class ConcreteFactory1 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA1>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB1>();
    }
};

// ��üȭ ���丮 2
class ConcreteFactory2 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA2>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB2>();
    }
};

// Ŭ���̾�Ʈ
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

// ��� ����
int main() {
    std::unique_ptr<AbstractFactory> factory1 = std::make_unique<ConcreteFactory1>();
    std::unique_ptr<AbstractFactory> factory2 = std::make_unique<ConcreteFactory2>();

    Client client1(std::move(factory1));
    Client client2(std::move(factory2));

    client1.run();
    client2.run();


    return 0;
}