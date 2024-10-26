class MonoESC
{
public:
    int pin;
    int target;
    int deg;
    MonoESC();
    ~MonoESC();
    void attach(int pin);
};

MonoESC::MonoESC() {}

MonoESC::~MonoESC() {}

