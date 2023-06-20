/**
 * Observer Design Pattern
 *
 * Intent: Lets you define a subscription mechanism to notify multiple objects
 * about any events that happen to the object they're observing.
 *
 * Note that there's a lot of different terms with similar meaning associated
 * with this pattern. Just remember that the Subject is also called the
 * Publisher and the Observer is often called the Subscriber and vice versa.
 * Also the verbs "observe", "listen" or "track" usually mean the same thing.
 */
 // 观察者 Observer

#include <iostream>
#include <list>
#include <string>

// 订阅者基类
class IObserver {
public:
    virtual ~IObserver() {};

    virtual void Update(const std::string &message_from_subject) = 0;
};

// 发布者基类
class ISubject {
public:
    virtual ~ISubject() {};

    virtual void Attach(IObserver *observer) = 0;

    virtual void Detach(IObserver *observer) = 0;

    virtual void Notify() = 0;
};

/**
 * The Subject owns some important state and notifies observers when the state
 * changes.
 */


// 发布者
class Subject : public ISubject {
public:
    virtual ~Subject() {
        std::cout << "Goodbye, I was the Subject.\n";
    }

    /**
     * The subscription management methods.
     */
    // 在监听的 observer 列表添加元素
    void Attach(IObserver *observer) override {
        list_observer_.push_back(observer);
    }

    // 在监听的 observer 列表移除元素
    void Detach(IObserver *observer) override {
        list_observer_.remove(observer);
    }

    // 向 observer 列表中的每一个元素发送通知
    void Notify() override {
        for (IObserver *observer: list_observer_) {
            observer->Update(message_);
        }

    }

    // 订阅者创建通知向发布者发布消息
    void CreateMessage(std::string message = "Empty") {
        this->message_ = message;
        Notify();
    }

    void HowManyObserver() {
        std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
    }

    /**
     * Usually, the subscription logic is only a fraction of what a Subject can
     * really do. Subjects commonly hold some important business logic, that
     * triggers a notification method whenever something important is about to
     * happen (or after it).
     */
    void SomeBusinessLogic() {
        this->message_ = "change message message";
        Notify();
        std::cout << "I'm about to do some thing important\n";
    }

private:
    std::list<IObserver *> list_observer_;
    std::string message_;
};


// 订阅者
class Observer : public IObserver {
public:
    // Observer 构造函数传入发布者对象
    // this->subject_.Attach(this); 开启订阅
    Observer(Subject &subject) : subject_(subject) {
        this->subject_.Attach(this);
        std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
        this->number_ = Observer::static_number_;
    }

    virtual ~Observer() {
        std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    }

    void Update(const std::string &message_from_subject) override {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }

    //  subject_.Detach(this); 关闭订阅
    void RemoveMeFromTheList() {
        subject_.Detach(this);
        std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
    }

    void PrintInfo() {
        std::cout << "Observer \"" << this->number_ << "\": a new message is available --> "
                  << this->message_from_subject_ << "\n";
    }

private:
    std::string message_from_subject_; // 收到发布者发来的消息
    Subject &subject_; // 传入的发布者对象
    static int static_number_; // 全部的订阅者数量
    int number_;  // 订阅者唯一的编号
};
int Observer::static_number_ = 0; // 全局订阅者数量


int main() {
    Subject *subject = new Subject;
    Observer *observer1 = new Observer(*subject);
    Observer *observer2 = new Observer(*subject);
    Observer *observer3 = new Observer(*subject);
    Observer *observer4;
    Observer *observer5;

    subject->CreateMessage("Hello World! :D");

    observer3->RemoveMeFromTheList();

    subject->CreateMessage("The weather is hot today! :p");
    observer4 = new Observer(*subject);

    observer2->RemoveMeFromTheList();
    observer5 = new Observer(*subject);

    subject->CreateMessage("My new car is great! ;)");
    observer5->RemoveMeFromTheList();

    observer4->RemoveMeFromTheList();
    observer1->RemoveMeFromTheList();

    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;
    return 0;
}
