#include <iostream>
#include <string>

class Time {
protected:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    ~Time() {
        std::cout << "Объект класса 'Время' уничтожен\n";
    }

    int getTotalSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    void addFiveSeconds() {
        seconds += 5;
        if (seconds >= 60) {
            seconds -= 60;
            minutes++;
            if (minutes >= 60) {
                minutes -= 60;
                hours++;
            }
        }
    }

    std::string getInfo() const {
        return "Время: " + std::to_string(hours) + " часов, " +
               std::to_string(minutes) + " минут, " +
               std::to_string(seconds) + " секунд.";
    }
};

int main() {
    Time time1(10, 30, 25);

    std::cout << time1.getInfo() << std::endl;
    std::cout << "Количество секунд: " << time1.getTotalSeconds() << std::endl;

    time1.addFiveSeconds();
    std::cout << "После добавления 5 секунд: " << std::endl;
    std::cout << time1.getInfo() << std::endl;

    int h, m, s;
    std::cout << "Введите часы, минуты и секунды: ";
    std::cin >> h >> m >> s;
    Time time2(h, m, s);

    std::cout << time2.getInfo() << std::endl;
    std::cout << "Количество секунд: " << time2.getTotalSeconds() << std::endl;

    time2.addFiveSeconds();
    std::cout << "После добавления 5 секунд: " << std::endl;
    std::cout << time2.getInfo() << std::endl;

    return 0;
}