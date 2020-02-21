#ifndef PLCTIMER_H
#define PLCTIMER_H

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
        bool res;
        TON(int p);
        TON(int p, bool r);
        void update();
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
        void update();
};

#endif
