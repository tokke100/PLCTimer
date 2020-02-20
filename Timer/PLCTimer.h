#ifndef TIMER_H
#define TIMER_H

class TON{
    private:
        unsigned long currentMillis;
        unsigned long previousMillis;
    public:
        int pre;
        bool ret;
        int acc;
        bool tt;
        bool dn;
        bool en;
        TON(int p, bool r);
        void loop();
};

class TOF{
    private:
        unsigned long currentMillis;
        unsigned long previousMillis;
    public:
        int pre;
        int acc;
        bool tt;
        bool dn;
        bool en;
        TOF(int p);
        void loop();
};

#endif