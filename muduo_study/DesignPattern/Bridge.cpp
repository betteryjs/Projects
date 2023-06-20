/**
 * The Implementation defines the interface for all implementation classes. It
 * doesn't have to match the Abstraction's interface. In fact, the two
 * interfaces can be entirely different. Typically the Implementation interface
 * provides only primitive operations, while the Abstraction defines higher-
 * level operations based on those primitives.
 */


// 桥接 Bridge
#include <iostream>
#include <string>

using namespace std;

/**
 * 实现部分 （Implementation） 为所有具体实现声明通用接口。
 * 抽象部分仅能通过在这里声明的方法与实现对象交互。
 * 抽象部分可以列出和实现部分一样的方法， 但是抽象部分通常声明一些复杂行为，
 * 这些行为依赖于多种由实现部分声明的原语操作。
 * */
class Implementation {
public:
    virtual ~Implementation() {}

    virtual std::string OperationImplementation() const = 0;
};

/**
 * Each Concrete Implementation corresponds to a specific platform and
 * implements the Implementation interface using that platform's API.
 */
class ConcreteImplementationA : public Implementation {
public:
    std::string OperationImplementation() const override {
        return "ConcreteImplementationA: Here's the result on the platform A.\n";
    }
};

class ConcreteImplementationB : public Implementation {
public:
    std::string OperationImplementation() const override {
        return "ConcreteImplementationB: Here's the result on the platform B.\n";
    }
};

/**
 * The Abstraction defines the interface for the "control" part of the two class
 * hierarchies. It maintains a reference to an object of the Implementation
 * hierarchy and delegates all of the real work to this object.
 */


// 抽象部分 （Abstraction） 提供高层控制逻辑， 依赖于完成底层实际工作的实现对象。
class Abstraction {
    /**
     * @var Implementation
     */
protected:
    Implementation *implementation_;

public:
    Abstraction(Implementation *implementation) : implementation_(implementation) {
    }

    virtual ~Abstraction() {};

    virtual std::string Operation() const {
        return "Abstraction: Base operation with:\n" +
               this->implementation_->OperationImplementation();
    }
};

/**
 * You can extend the Abstraction without changing the Implementation classes.
 * 改变抽像数据类型 不改变具体数据类型
 */
class ExtendedAbstraction : public Abstraction {
public:
    ExtendedAbstraction(Implementation *implementation) : Abstraction(implementation) {
    }

    std::string Operation() const override {
        return "ExtendedAbstraction: Extended operation with:\n" +
               this->implementation_->OperationImplementation();
    }
};

/**
 * Except for the initialization phase, where an Abstraction object gets linked
 * with a specific Implementation object, the client code should only depend on
 * the Abstraction class. This way the client code can support any abstraction-
 * implementation combination.
 */
void ClientCode(const Abstraction &abstraction) {
    // ...
    std::cout << abstraction.Operation();
    // ...
}

/**
 * The client code should be able to work with any pre-configured abstraction-
 * implementation combination.
 */

int main() {
    Implementation *implementation = new ConcreteImplementationA;
    Abstraction *abstraction = new Abstraction(implementation);
    ClientCode(*abstraction);
    std::cout << std::endl;

    implementation = new ConcreteImplementationB;
    abstraction = new Abstraction(implementation);
    ClientCode(*abstraction);
    std::cout << std::endl;


    delete implementation;
    delete abstraction;

    implementation = new ConcreteImplementationB;
    // ExtendedAbstraction 只改变抽象的数据类型 不改变实现部分
    abstraction = new ExtendedAbstraction(implementation);
    ClientCode(*abstraction);

    delete implementation;
    delete abstraction;

    return 0;
}
