#include <iostream>
#include <string>

// Receiver
class Receiver {
public:
    void action(const std::string& message) const {
        std::cout << "Receiver executes action: " << message << std::endl;
    }
};

// Command
class Command {
protected:
    Receiver* receiver;

public:
    Command(Receiver* receiver) : receiver(receiver) {}

    virtual void execute() const = 0;
};

// ConcreteCommand
class ConcreteCommand : public Command {
private:
    std::string commandState;

public:
    ConcreteCommand(Receiver* receiver, const std::string& commandState)
        : Command(receiver), commandState(commandState) {}

    void execute() const override {
        receiver->action("ConcreteCommand with state: " + commandState);
    }
};

// Invoker
class Invoker {
private:
    Command* command;

public:
    void setCommand(Command* command) {
        this->command = command;
    }

    void executeCommand() const {
        command->execute();
    }
};

int main() {
    Receiver receiver;
    ConcreteCommand concreteCommand(&receiver, "CommandState");

    Invoker invoker;
    invoker.setCommand(&concreteCommand);
    invoker.executeCommand();

    return 0;
}
