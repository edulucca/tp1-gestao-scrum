#include "Invoker.hpp"

void Invoker::addCommand(const std::shared_ptr<ICommand>& cmd) {
    queue.push_back(cmd);
}

void Invoker::runAll() {
    for (auto& c : queue) {
        c->execute();
    }
    queue.clear();
}
