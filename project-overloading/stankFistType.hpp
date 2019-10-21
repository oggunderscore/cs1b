#ifndef stankFistType_hpp_
#define stankFistType_hpp_

class StankFist{
    public:
        StankFist();
    private:
        int stinkyVar;
    friend void stinkysFriend(StankFist &sfo);
};

#endif