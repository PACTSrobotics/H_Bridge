class H_Bridge{
    public:
        H_Bridge(int IN1, int IN2);
        H_Bridge(int IN1, int IN2, int EN);
        void stop();
        void start(int derection);
        void start(int derection, int speed);
        static const int FORWARD;
        static const int BACK;
        static const int STOP;
    private:
        int IN1;
        int IN2;
        int EN;
};
