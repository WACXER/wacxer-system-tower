export class ICarfactory 
{
    public: 
        virtual ~ ICarfactory() = default;
        virtual std::uniqueptr<ICar> makeSedan = 0;
        virtual std::uniqueptr<ICar> makeSuv = 0;
};