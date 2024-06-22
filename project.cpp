#include <iostream>
#include <memory>
#include <string>

// Abstract Base Class for Sports
class ISports {
public:
    virtual void play() = 0;
    virtual ~ISports() {}
};

// Concrete Sports Classes for Factory Method Pattern
class CricketSport : public ISports {
public:
    void play() override {
        std::cout << "Playing Cricket" << std::endl;
    }
    void printFamousLeague() {
        std::cout << "IPL - Indian Premier League" << std::endl;
    }
};

class BasketBallSport : public ISports {
public:
    void play() override {
        std::cout << "Playing Basketball" << std::endl;
    }
    void printFamousLeague() {
        std::cout << "NBA - National Basketball Association" << std::endl;
    }
};

class FootballSport : public ISports {
public:
    void play() override {
        std::cout << "Playing Football" << std::endl;
    }
    void printFamousLeague() {
        std::cout << "FIFA World Cup" << std::endl;
    }
};

class IndividualSports : public ISports {
public:
    void play() override {
        std::cout << "Playing Individual Sport" << std::endl;
    }
    void printFamousLeague() {
        std::cout << "Tennis Grand Slams" << std::endl;
    }
};

// Factory Class
class SportsFactory {
public:
    static std::unique_ptr<ISports> getSportsFactory(const std::string& sportsName) {
        if (sportsName == "Cricket")
            return std::make_unique<CricketSport>();
        else if (sportsName == "Basketball")
            return std::make_unique<BasketBallSport>();
        else if (sportsName == "Football")
            return std::make_unique<FootballSport>();
        else
            return std::make_unique<IndividualSports>();
    }
};

// Facade Class
class SportsFacade {
private:
    CricketSport cricketSport;
    BasketBallSport basketballSport;
    FootballSport footballSport;
    IndividualSports individualSports;

public:
    void printFamousLeague() {
        cricketSport.printFamousLeague();
        basketballSport.printFamousLeague();
        footballSport.printFamousLeague();
        individualSports.printFamousLeague();
    }
};

// Forward declaration of ContextState for State Pattern
class ContextState;

// Abstract Base Class for TransactionState (State Pattern)
class TransactionState {
public:
    virtual void doAction(ContextState& context) = 0;
    virtual ~TransactionState() {}
};

// Context Class
class ContextState {
private:
    std::unique_ptr<TransactionState> currentState;

public:
    ContextState() : currentState(nullptr) {}

    void setState(std::unique_ptr<TransactionState> state) {
        currentState = std::move(state);
    }

    void performAction() {
        if (currentState)
            currentState->doAction(*this);
    }
};

// Concrete State Classes
class CardInsertion : public TransactionState {
public:
    void doAction(ContextState& context) override {
        std::cout << "Card Inserted. Please enter your PIN." << std::endl;
        // Transition to next state...
        // context.setState(std::make_unique<NextState>());
    }
};

// Other states like EnterPin, WithdrawAmount, etc. can be similarly defined

int main() {
    // Demonstration of Factory Method Pattern
    auto sport = SportsFactory::getSportsFactory("Cricket");
    sport->play();

    // Demonstration of Facade Pattern
    SportsFacade sportsFacade;
    sportsFacade.printFamousLeague();

    // Demonstration of State Pattern
    ContextState atmMachine;
    atmMachine.setState(std::make_unique<CardInsertion>());
    atmMachine.performAction();

    return 0;
}
