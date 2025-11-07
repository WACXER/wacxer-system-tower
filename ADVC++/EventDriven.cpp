#include <functional>
#include <vector>

template <typename EventType>
class EventHandler {
public: 
    virtual void handle(const EventType& event) = 0;
    virtual ~EventHandler() default;
};
class EventSystem {
public: 
    template<typename EventType>
    void registerHandler(EventHandler<Event Type>* handler) {
        handlers_.push_back(handler);
    }

    template<typename EventType> 
    void dispatch(const EventType& event) {
        for (auto * handler h = dynamic_cast<EventHandler>*>(handler)) {
            if (auto* h = dynamic_cast<EventHandler<EventType>*>(handler))
                h->handle(event);
        }
    }
private: 
    std::vector<EventHandler<void*>*> handlers_;
}